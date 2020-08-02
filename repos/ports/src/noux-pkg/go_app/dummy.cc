// dummy func to link go apps
//

extern "C" {

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
int     sendfile(int fd, int s, off_t offset, size_t nbytes,
	 struct sf_hdtr *hdtr, off_t *sbytes, int flags)
{
	return 0;
}

#include <unistd.h>
pid_t getpgid(pid_t pid)
{
	return 0;
}

int lchown(const char *path, uid_t owner, gid_t group)
{
	return 0;
}
#include <sys/mount.h>
int mount(const char *source, const char *target, int f, void *data)
{
	return 0;
}

#include <sys/time.h>
int settimeofday(const struct timeval *tv , const struct timezone *tz)
{
	return 0;
}

#include <sys/mman.h>

int mlock(const void *addr, size_t len)
{
	return 0;
}
int munlock(const void *addr, size_t len)
{
	return 0;
}
int mlockall(int flags)
{
	return 0;
}
int munlockall(void)
{
	return 0;
}

#include <signal.h>
int sigaltstack(const stack_t *ss, stack_t *oss)
{
	return 0;
}

// end extern "C"
void stacktraceandabort( void );
void __outgo_genode_log();
}
//extern "C" bool _verbose;

// to produce call stack and halt
#include <spec/x86_64/os/backtrace.h>
extern "C" int raise(int sig)
{
	Genode::log("raise ", sig);
	Genode::backtrace();
	return 0;
}

#if 1
#include <stdlib.h>
#include <base/log.h>
void stacktraceandabort( void )
{
	Genode::log("--- stacktraceandabort ---");
	//Genode::backtrace();
	//abort();
	//exit(0);
}
#endif
//#include <base/heap.h>
// #include <platform.h>
// #include <core_env.h>
#include <base/component.h>

extern int main (int argc, const char* argv[]);

#if 0
void Component::construct(Genode::Env &env)
{
//	Genode::Heap heap(env.ram(), env.rm());
//	_verbose = false;
	// static Core_env _env;
	env.exec_static_constructors();

	Genode::log("Goalng  Component::construct");

	// Libc::with_libc([&r] () { r = main(c, &myname); });
}
#endif
#include <libc/component.h>
void Libc::Component::construct(Libc::Env &env)
{
	static int c = 1;
	static char const *myname = "GolangApp";
	int r = 0;
	Libc::with_libc([&r]() { r = main(c, &myname); });
	r = main(c, &myname);
	env.parent().exit(r);
}


extern "C"
void Log(const char * b)
{
	Genode::log("Log: ",b);
}

// print to log from go using go string
extern "C"
ssize_t __go_genode_write(int fd, const void *Buf, size_t count)
{
	static unsigned char b[1024];
	static unsigned int ptr=0; // point to free byte
// not safe in concurrent access
	// rest of buffer
	const unsigned int size = sizeof(b)-1; // available for data
	unsigned int rest_buf;
	unsigned char *buf = (unsigned char *)Buf;
again:	rest_buf = size - ptr;
	if (rest_buf)
	{
		while (count>0)
		{
			size_t to_copy = count > rest_buf ? rest_buf : count;
			Genode::memcpy(b+ptr,buf,to_copy);
			// increment pointers
			ptr += to_copy;
			count -= to_copy;
			buf += to_copy;
			rest_buf -= to_copy;
			// print only if we have "\n" or no buf space
			b[ptr] = 0; // terminate string - safe because of size above
			char *c;
			while ((c=(char*)__builtin_memchr(b,'\n',ptr)))	// found, print
			{
				*c = 0; // terminate string for ::log - replace \n
				Genode::log("fd(", fd, "): ", (const char*)b);
				// squeeze buffer
				ptr -= c+1 - (char *)(&b[0]);
				rest_buf += c+1 - (char *)(&b[0]);
				Genode::memmove((void *)(&b[0]), c+1, ptr);
				b[ptr] = 0;
			}
		}
	} else 
	{
		Genode::log("fd(", fd, "): ", (const char*)b);
		ptr = 0;
		goto again;
	}
	return count;
}

#include <base/thread.h>

/* base-internal includes */
#include <base/internal/stack_allocator.h>
#include <base/internal/globals.h>

using namespace Genode;
addr_t addr_to_base(void *addr)
{
	return ((addr_t)addr) & ~(stack_virtual_size() - 1);
}

extern "C"
void * alloc_secondary_stack( size_t stack_size )
{
	Genode::Thread * myself = Genode::Thread::myself();
	//if (stack_size> 1024*1024-4096*3) stack_size = 1024*1024-4096*3;
	if (!myself)
		return NULL;
	void  * ret =  myself->alloc_secondary_stack("goroutine", stack_size);
	addr_t base = addr_to_base(ret);

	char * c = reinterpret_cast<char *>(ret);
	//log("alloc_secondary_stack ", Hex(stack_size), " m ", myself, " r ", ret, " b ", Hex(base));
	for( size_t i= 0; i >= -stack_size; i-- )
		c[i] = 0x0;
	//memset(ret, 0, stack_size);
	//log(" firstb  ", Hex((addr_t)c-stack_size)," last  ", Hex((addr_t)c));

	return (void *)base;
}

void  *base_to_stack(addr_t base)
{
	addr_t result = base + stack_virtual_size()
	                - sizeof(Stack);
	return reinterpret_cast<void *>(result);
}

extern "C"
void free_secondary_stack( void * stack )
{
	Genode::Thread * myself = Genode::Thread::myself();
	//log("free_secondary_stack ", stack, " m ", myself, " bs ", base_to_stack((addr_t)stack));
	if (!myself)
		return ;
	myself->free_secondary_stack(base_to_stack((addr_t)stack));
}

