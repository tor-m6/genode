/*
 * \brief  Basic test for manually managing a sub RM session
 *         based on Genode jdk os_genode.cpp code
 * \author Alexander Tormasov
 * \date   2020-09-10
 */

#include <base/heap.h>
#include <base/registry.h>
#include <libc/component.h>
#include <base/attached_rom_dataspace.h>
#include <region_map/client.h>
#include <rm_session/connection.h>
#include <util/retry.h>
#include <base/debug.h>
#include <base/log.h>
#include <libc/args.h>

#include <exception>
#include <typeinfo>
#include <stdexcept>

extern "C"
{
/* libc includes */
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/cdefs.h>
#include <assert.h>
}

#include <spec/x86_64/os/backtrace.h>

extern "C" void backtrace()
{
    Genode::backtrace();
}

/************************** 
 ** VM region management **
 **************************/

namespace Genode
{
    class Vm_area;
    class Vm_area_registry;
    class Vm_region_map;
}; // namespace Genode

/* 
 * intended for mmap with ANON memory
 * limitations: only full region map/unmap (no partial)
 */
class Genode::Vm_region_map
{
public:
    typedef Region_map_client::Local_addr Local_addr;

protected:
    Env &_env;
    Allocator_avl _range;
    addr_t _base;
    size_t _size;
    Rm_connection _rm_connection;
    Region_map_client _rm;

public:
    Vm_region_map(Env &env, Allocator &md_alloc, size_t bytes = 0, addr_t requested_addr = 0)
        : _env(env), _range(&md_alloc),
          _base(requested_addr), _size(bytes),
          _rm_connection(_env), _rm(_rm_connection.create(_size))
    {
        /* attach full chunk of dataspace as requested local virtual address */
        if (_base)
        {
            void *la = 0;
            la = _env.rm().attach_at(_rm.dataspace(), _base);
            if ((addr_t)la != _base)
            {
                Genode::error(
                    "Vm_region_map::Vm_region_map: cannot attach_at ",
                    Hex_range<addr_t>(_base, _size), 
                    " received ", Hex((addr_t)la));
                throw Region_map::Region_conflict();
            }
        }
        else
            _base = _env.rm().attach(_rm.dataspace());
    }

    addr_t base() const { return _base; }
    size_t size() const { return _size; }

    int add_range(addr_t base, size_t size) { return _range.add_range(base, size); }

    int remove_range(addr_t base, size_t size) { return _range.remove_range(base, size); }

    addr_t alloc(size_t size, int align)
    {
        addr_t addr = 0;
        Range_allocator::Alloc_return r = _range.alloc_aligned(size, (void **)&addr,
                                                               align > 12 ? align : 12);
        if ( r.error() )
        {
            Genode::error(
                "Vm_region_map::alloc error: ",
                int(r.value), " ", Hex_range<addr_t>(addr, size));
            throw -1;
        }
        return addr;
    }

    addr_t alloc_at(size_t size, addr_t addr)
    {
        Range_allocator::Alloc_return r = _range.alloc_addr(size, addr);
        if (r.error())
        {
            Genode::error(
                "Vm_region_map::alloc_at error: ",
                int(r.value), " ", Hex_range<addr_t>(addr, size));
            throw -1;
        }
        return addr;
    }

    void free(addr_t vaddr) { _range.free((void *)vaddr); }

    size_t size_at(void const *addr) const { return _range.size_at(addr); }

    Local_addr attach_at(Dataspace_capability ds, addr_t local_addr, size_t size)
    {
        return retry<Genode::Out_of_ram>(
            [&] () { return _rm.attach_at(ds, local_addr - _base, size); },
            [&] () { _env.upgrade(Parent::Env::pd(), "ram_quota=8K"); });
    }

    Local_addr attach_executable(Dataspace_capability ds, addr_t local_addr, size_t size)
    {
        return retry<Genode::Out_of_ram>(
            [&] () { return _rm.attach_executable(ds, local_addr - _base, size); },
            [&] () { _env.upgrade(Parent::Env::pd(), "ram_quota=8K"); });
    }

    void detach(Local_addr local_addr) { _rm.detach((addr_t)local_addr - _base); }
};

class Genode::Vm_area
{
private:
    struct Vm_area_ds
    {
        addr_t base;
        size_t size;
        Ram_dataspace_capability ds;

        Vm_area_ds(addr_t base, size_t size, Ram_dataspace_capability ds)
            : base(base), size(size), ds(ds) {}

        virtual ~Vm_area_ds(){ };
    };

        typedef Registered<Vm_area_ds> Vm_handle;

        Env &_env;
        Heap &_kheap;
        Vm_region_map _rm;
        Registry<Vm_handle> _ds;

    public:
        Vm_area(Env &env, Heap &heap, addr_t base, size_t size)
            : _env(env), _kheap(heap), _rm(env, heap, size, base)
        {
        }

        addr_t base() const { return _rm.base(); }
        size_t size() const { return _rm.size(); }

        bool inside(addr_t base, size_t size)
        {
            return base >= _rm.base() && (base + size) <= (_rm.base() + _rm.size());
        }

        int add_range(addr_t base, size_t size) { return _rm.add_range(base, size); }

        int remove_range(addr_t base, size_t size) { return _rm.remove_range(base, size); }

        addr_t alloc(size_t size, int align) { return _rm.alloc(size, align); }

        addr_t alloc_at(size_t size, addr_t local_addr) { return _rm.alloc_at(size, local_addr); }

        void free(addr_t vaddr) { _rm.free(vaddr); }
        
        bool commit(addr_t base, size_t size, bool executable)
        {
            if (!inside(base, size))
                return false;

            Ram_dataspace_capability ds = _env.ram().alloc(size);

            try
            {
                if (executable)
                    _rm.attach_executable(ds, base, size);
                else
                    _rm.attach_at(ds, base, size);
            }
            catch (Region_map::Region_conflict)
            {
                Genode::error("Region_conflict in _rm.attach ",
                    Hex_range<addr_t>(base, size));
                _env.ram().free(ds);
                return false;
            }
            catch (...)
            {
                Genode::error(
                    "Vm_area::commit: catch _env.ram().free(ds)");
                _env.ram().free(ds);
                return false;
            }

            new (_kheap) Vm_handle(_ds, base, size, ds);

            return true;
        }

        virtual ~Vm_area()
        {
            _ds.for_each([&](Vm_handle &vm) {
                /* remove from local allocator */
                _rm.free(vm.base);
                /* detach from local virtual memory */
                _rm.detach(vm.base);
                /* free backend memory/dataspace (physical) */
                _env.ram().free(vm.ds);
                /* remove structure/metadata from local heap allocator */
                destroy(_kheap, &vm);
            });
        }
    };

class Genode::Vm_area_registry
{
private:
    typedef Registered<Vm_area> Vm_area_handle;

    Env &_env;
    Heap &_kheap;
    Registry<Vm_area_handle> _registry;
    /* dedicated area to store memory allocated without desired address */
    Vm_area *_pvma;

public :
    Vm_area_registry(Env &env, Heap &heap, size_t size, addr_t requested_address = 0)
        : _env(env), _kheap(heap)
    {
        /* register dedicated Vm_area for first allocator range, used without requested_addr */
        _pvma = new (&_kheap) Vm_area_handle(_registry, _env, _kheap, requested_address, size);

        /* add mapped range to local allocator to allow its use in local allocation */
        _pvma->add_range(_pvma->base(), size);
    }

    ~Vm_area_registry()
    {
        _registry.for_each([&](Vm_area_handle &vma) {
            destroy(_kheap, &vma);
        });
    };

    addr_t reserve(size_t size, addr_t base, int align)
    {
        if (!base)
        {
            /* from pre-allocated _pvma area; give new base address */
            base = _pvma->alloc(size, align);
        } else
        {
            /* store registered structure for this mapping */
            Vm_area *vm = new (&_kheap) Vm_area_handle(_registry, _env, _kheap, base, size);

            /* add range for requested addresses */
            if (vm->add_range(base, size))
            {
                error(__func__, " can't add_range; align ", Hex(align), " ", Hex_range<addr_t>(base, size));
                throw -5;
            }
            vm->alloc_at(size, base);
        }

        return base;
    }

    bool commit(addr_t base, size_t size, bool executable)
    {
        bool success = false;

        _registry.for_each([&](Vm_area_handle &vm) {
            if (success)
                return;
            success = vm.commit(base, size, executable);
        });

        return success;
    }

    bool release(addr_t base, size_t size)
    {
        bool success = false;

        _registry.for_each([&](Vm_area_handle &vm) {
            if (success || !vm.inside(base, size))
                return;

            if (base != vm.base() || size != vm.size())
            {
                error("sub region release attempt", " addr: ", Hex(base), " vm addr: ", Hex(vm.base()),
                      " size: ", Hex(size), " vm size: ", Hex(vm.size()));
                throw -6;
            }

            vm.free(vm.base());
            /* do not destroy main area for requested_address==0 allocation */
            if (_pvma != &vm)
                destroy(_kheap, &vm);
            success = true;
        });

        if (!success)
            error(__func__, " failed at ", Hex_range<addr_t>(base, size));

        return success;
    }
};


static Genode::Constructible<Genode::Vm_area_registry> vm_reg;

namespace Genode
{
    /*
     *_ZN6Genode17pd_release_memoryEPvm T
     _ZN6Genode18pd_uncommit_memoryEPvm T
     _ZN6Genode24pd_commit_memory_or_exitEPvmbbPKc T
     _ZN6Genode28pd_attempt_reserve_memory_atEmPv T
     */
    char *pd_reserve_memory(size_t bytes, void *requested_addr,
                            size_t alignment_hint);
    bool pd_unmap_memory(void *addr, size_t bytes);
    bool pd_commit_memory(void *addr, size_t size, bool exec, bool with_requested_addr);
}; // namespace Genode

char *Genode::pd_reserve_memory(size_t bytes, void *requested_addr,
                                size_t alignment_hint)
{
    try
    {
        Genode::addr_t addr;
        addr = vm_reg->reserve(bytes, (Genode::addr_t)requested_addr,
                     alignment_hint ? Genode::log2(alignment_hint) : 12);

        return (char *)addr;
    }
    catch (...)
    {
        Genode::error(__PRETTY_FUNCTION__, " exception!");
        backtrace();
    }
    return nullptr;
}

bool Genode::pd_unmap_memory(void *addr, size_t bytes)
{
    return vm_reg->release((Genode::addr_t)addr, bytes);
}

bool Genode::pd_commit_memory(void *addr, size_t size, bool exec, bool with_requested_addr)
{

    if (!addr)
    {
        Genode::error(__PRETTY_FUNCTION__, "  addr == 0");
        throw -7;
    }

    return vm_reg->commit((Genode::addr_t)addr, size, exec);
}

/******************
 ** Startup code **
 ******************/

    extern char **genode_argv;
    extern int genode_argc;
    extern char **genode_envp;

    /* initial environment for the FreeBSD libc implementation */
    extern char **environ;

    /* provided by the application */
    extern "C" int main(int argc, char **argv, char **envp);

    static void construct_component(Libc::Env &env)
    {

        populate_args_and_env(env, genode_argc, genode_argv, genode_envp);

        environ = genode_envp;

        exit(main(genode_argc, genode_argv, genode_envp));
}

extern Genode::Allocator *kernel_allocator();

void Libc::Component::construct(Libc::Env &env)
{
    Genode::Attached_rom_dataspace config(env, "config");

    /* 15 Mb for allocator without predefined address */
    size_t const local_heap_default_size =
        config.xml().attribute_value("local_heap_default_size", (size_t)(15ul * 1024 * 1024));

    /* get Kernel::_heap from Libc */
    /* and use it as metadata data storage with pre-allocaion */
    vm_reg.construct(env, reinterpret_cast<Genode::Heap &>(*kernel_allocator()), 
        local_heap_default_size);

    Libc::with_libc([&]() { construct_component(env); });
}