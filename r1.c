
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;

void __builtin_unreachable(void);
void halt(void) __attribute__((__noreturn__));
void memzero(void *s, unsigned long n);
void *memset(void *s, unsigned long c, unsigned long n) __attribute__((externally_visible));
void *memcpy(void* ptr_dst, const void* ptr_src, unsigned long n) __attribute__((externally_visible));
int __attribute__((__pure__)) strncmp(const char *s1, const char *s2, int n);
long __attribute__((__const__)) char_to_long(char c);
long __attribute__((__pure__)) str_to_long(const char* str);


int __builtin_clzl (unsigned long x);
int __builtin_ctzl (unsigned long x);
static inline long
__attribute__((__const__)) clzl(unsigned long x)
{
    return __builtin_clzl(x);
}
static inline long
__attribute__((__const__)) ctzl(unsigned long x)
{
    return __builtin_ctzl(x);
}



int __builtin_popcountl (unsigned long x);


static inline long
__attribute__((__const__)) popcountl(unsigned long mask)
{

    unsigned int count;
    for (count = 0; mask; count++) {
        mask &= mask - 1;
    }

    return count;



}



void _fail(
    const char* str,
    const char* file,
    unsigned int line,
    const char* function
) __attribute__((__noreturn__));



void _assert_fail(
    const char* assertion,
    const char* file,
    unsigned int line,
    const char* function
) __attribute__((__noreturn__));




typedef int __assert_failed_long_is_64bits[(sizeof(unsigned long) == 8) ? 1 : -1];


typedef unsigned long word_t;
typedef signed long sword_t;
typedef word_t vptr_t;
typedef word_t paddr_t;
typedef word_t pptr_t;
typedef word_t cptr_t;
typedef word_t dev_id_t;
typedef word_t cpu_id_t;
typedef uint32_t logical_id_t;
typedef word_t node_id_t;
typedef word_t dom_t;


typedef word_t seL4_Word;
typedef cptr_t seL4_CPtr;
typedef uint16_t seL4_Uint16;
typedef uint32_t seL4_Uint32;
typedef uint8_t seL4_Uint8;
typedef node_id_t seL4_NodeId;
typedef paddr_t seL4_PAddr;
typedef dom_t seL4_Domain;

typedef uint64_t timestamp_t;

enum _bool {
    false = 0,
    true = 1
};
typedef word_t bool_t;

typedef struct region {
    pptr_t start;
    pptr_t end;
} region_t;

typedef struct p_region {
    paddr_t start;
    paddr_t end;
} p_region_t;

typedef struct v_region {
    vptr_t start;
    vptr_t end;
} v_region_t;



struct seL4_MessageInfo {
    uint64_t words[1];
};
typedef struct seL4_MessageInfo seL4_MessageInfo_t;

static inline seL4_MessageInfo_t __attribute__((__const__))
seL4_MessageInfo_new(uint64_t label, uint64_t capsUnwrapped, uint64_t extraCaps, uint64_t length) {
    seL4_MessageInfo_t seL4_MessageInfo;


    if(!((label & ~0xfffffffffffffull) == ((0 && (label & (1ull << 63))) ? 0x0 : 0))) _assert_fail("(label & ~0xfffffffffffffull) == ((0 && (label & (1ull << 63))) ? 0x0 : 0)", "64/mode/api/shared_types_gen.h", 18, __FUNCTION__);
    if(!((capsUnwrapped & ~0x7ull) == ((0 && (capsUnwrapped & (1ull << 63))) ? 0x0 : 0))) _assert_fail("(capsUnwrapped & ~0x7ull) == ((0 && (capsUnwrapped & (1ull << 63))) ? 0x0 : 0)", "64/mode/api/shared_types_gen.h", 19, __FUNCTION__);
    if(!((extraCaps & ~0x3ull) == ((0 && (extraCaps & (1ull << 63))) ? 0x0 : 0))) _assert_fail("(extraCaps & ~0x3ull) == ((0 && (extraCaps & (1ull << 63))) ? 0x0 : 0)", "64/mode/api/shared_types_gen.h", 20, __FUNCTION__);
    if(!((length & ~0x7full) == ((0 && (length & (1ull << 63))) ? 0x0 : 0))) _assert_fail("(length & ~0x7full) == ((0 && (length & (1ull << 63))) ? 0x0 : 0)", "64/mode/api/shared_types_gen.h", 21, __FUNCTION__);

    seL4_MessageInfo.words[0] = 0
        | (label & 0xfffffffffffffull) << 12
        | (capsUnwrapped & 0x7ull) << 9
        | (extraCaps & 0x3ull) << 7
        | (length & 0x7full) << 0;

    return seL4_MessageInfo;
}

static inline uint64_t __attribute__((__const__))
seL4_MessageInfo_get_label(seL4_MessageInfo_t seL4_MessageInfo) {
    uint64_t ret;
    ret = (seL4_MessageInfo.words[0] & 0xfffffffffffff000ull) >> 12;

    if (0 && (ret & (1ull << (63)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
seL4_MessageInfo_get_capsUnwrapped(seL4_MessageInfo_t seL4_MessageInfo) {
    uint64_t ret;
    ret = (seL4_MessageInfo.words[0] & 0xe00ull) >> 9;

    if (0 && (ret & (1ull << (63)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_MessageInfo_t __attribute__((__const__))
seL4_MessageInfo_set_capsUnwrapped(seL4_MessageInfo_t seL4_MessageInfo, uint64_t v64) {

    if(!((((~0xe00 >> 9 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) _assert_fail("(((~0xe00 >> 9 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0)", "64/mode/api/shared_types_gen.h", 57, __FUNCTION__);
    seL4_MessageInfo.words[0] &= ~0xe00ull;
    seL4_MessageInfo.words[0] |= (v64 << 9) & 0xe00ull;
    return seL4_MessageInfo;
}

static inline uint64_t __attribute__((__const__))
seL4_MessageInfo_get_extraCaps(seL4_MessageInfo_t seL4_MessageInfo) {
    uint64_t ret;
    ret = (seL4_MessageInfo.words[0] & 0x180ull) >> 7;

    if (0 && (ret & (1ull << (63)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_MessageInfo_t __attribute__((__const__))
seL4_MessageInfo_set_extraCaps(seL4_MessageInfo_t seL4_MessageInfo, uint64_t v64) {

    if(!((((~0x180 >> 7 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) _assert_fail("(((~0x180 >> 7 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0)", "64/mode/api/shared_types_gen.h", 77, __FUNCTION__);
    seL4_MessageInfo.words[0] &= ~0x180ull;
    seL4_MessageInfo.words[0] |= (v64 << 7) & 0x180ull;
    return seL4_MessageInfo;
}

static inline uint64_t __attribute__((__const__))
seL4_MessageInfo_get_length(seL4_MessageInfo_t seL4_MessageInfo) {
    uint64_t ret;
    ret = (seL4_MessageInfo.words[0] & 0x7full) >> 0;

    if (0 && (ret & (1ull << (63)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_MessageInfo_t __attribute__((__const__))
seL4_MessageInfo_set_length(seL4_MessageInfo_t seL4_MessageInfo, uint64_t v64) {

    if(!((((~0x7f >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0))) _assert_fail("(((~0x7f >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0)", "64/mode/api/shared_types_gen.h", 97, __FUNCTION__);
    seL4_MessageInfo.words[0] &= ~0x7full;
    seL4_MessageInfo.words[0] |= (v64 << 0) & 0x7full;
    return seL4_MessageInfo;
}

struct seL4_CNode_CapData {
    uint64_t words[1];
};
typedef struct seL4_CNode_CapData seL4_CNode_CapData_t;

static inline uint64_t __attribute__((__const__))
seL4_CNode_CapData_get_guard(seL4_CNode_CapData_t seL4_CNode_CapData) {
    uint64_t ret;
    ret = (seL4_CNode_CapData.words[0] & 0xffffffffffffffc0ull) >> 6;

    if (0 && (ret & (1ull << (63)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
seL4_CNode_CapData_get_guardSize(seL4_CNode_CapData_t seL4_CNode_CapData) {
    uint64_t ret;
    ret = (seL4_CNode_CapData.words[0] & 0x3full) >> 0;

    if (0 && (ret & (1ull << (63)))) {
        ret |= 0x0;
    }
    return ret;
}

struct seL4_CapRights {
    uint64_t words[1];
};
typedef struct seL4_CapRights seL4_CapRights_t;

static inline seL4_CapRights_t __attribute__((__const__))
seL4_CapRights_new(uint64_t capAllowGrant, uint64_t capAllowRead, uint64_t capAllowWrite) {
    seL4_CapRights_t seL4_CapRights;


    if(!((capAllowGrant & ~0x1ull) == ((0 && (capAllowGrant & (1ull << 63))) ? 0x0 : 0))) _assert_fail("(capAllowGrant & ~0x1ull) == ((0 && (capAllowGrant & (1ull << 63))) ? 0x0 : 0)", "64/mode/api/shared_types_gen.h", 140, __FUNCTION__);
    if(!((capAllowRead & ~0x1ull) == ((0 && (capAllowRead & (1ull << 63))) ? 0x0 : 0))) _assert_fail("(capAllowRead & ~0x1ull) == ((0 && (capAllowRead & (1ull << 63))) ? 0x0 : 0)", "64/mode/api/shared_types_gen.h", 141, __FUNCTION__);
    if(!((capAllowWrite & ~0x1ull) == ((0 && (capAllowWrite & (1ull << 63))) ? 0x0 : 0))) _assert_fail("(capAllowWrite & ~0x1ull) == ((0 && (capAllowWrite & (1ull << 63))) ? 0x0 : 0)", "64/mode/api/shared_types_gen.h", 142, __FUNCTION__);

    seL4_CapRights.words[0] = 0
        | (capAllowGrant & 0x1ull) << 2
        | (capAllowRead & 0x1ull) << 1
        | (capAllowWrite & 0x1ull) << 0;

    return seL4_CapRights;
}

static inline uint64_t __attribute__((__const__))
seL4_CapRights_get_capAllowGrant(seL4_CapRights_t seL4_CapRights) {
    uint64_t ret;
    ret = (seL4_CapRights.words[0] & 0x4ull) >> 2;

    if (0 && (ret & (1ull << (63)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
seL4_CapRights_get_capAllowRead(seL4_CapRights_t seL4_CapRights) {
    uint64_t ret;
    ret = (seL4_CapRights.words[0] & 0x2ull) >> 1;

    if (0 && (ret & (1ull << (63)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
seL4_CapRights_get_capAllowWrite(seL4_CapRights_t seL4_CapRights) {
    uint64_t ret;
    ret = (seL4_CapRights.words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (63)))) {
        ret |= 0x0;
    }
    return ret;
}
typedef enum api_object {
    seL4_UntypedObject,
    seL4_TCBObject,
    seL4_EndpointObject,
    seL4_NotificationObject,
    seL4_CapTableObject,
    seL4_NonArchObjectTypeCount,
} seL4_ObjectType;

__attribute__((deprecated("use seL4_NotificationObject"))) static const seL4_ObjectType seL4_AsyncEndpointObject = seL4_NotificationObject;

typedef seL4_Word api_object_t;


typedef enum _mode_object {
    seL4_X86_PDPTObject = seL4_NonArchObjectTypeCount,
    seL4_X64_PML4Object,



    seL4_ModeObjectTypeCount
} seL4_seL4ArchObjectType;


typedef enum _object {
    seL4_X86_4K = seL4_ModeObjectTypeCount,
    seL4_X86_LargePageObject,
    seL4_X86_PageTableObject,
    seL4_X86_PageDirectoryObject,




    seL4_X86_VCPUObject,
    seL4_X86_EPTPML4Object,
    seL4_X86_EPTPDPTObject,
    seL4_X86_EPTPDObject,
    seL4_X86_EPTPTObject,

    seL4_ObjectTypeCount
} seL4_ArchObjectType;
typedef seL4_Word object_t;



enum asidConstants {
    asidInvalid = 0
};



typedef word_t asid_t;
enum priorityConstants {
    seL4_InvalidPrio = -1,
    seL4_MinPrio = 0,
    seL4_MaxPrio = 256 - 1
};



enum seL4_MsgLimits {
    seL4_MsgLengthBits = 7,
    seL4_MsgExtraCapBits = 2
};

enum {
    seL4_MsgMaxLength = 120,
};


typedef enum {
    seL4_NoFailure = 0,
    seL4_InvalidRoot,
    seL4_MissingCapability,
    seL4_DepthMismatch,
    seL4_GuardMismatch,
    _enum_pad_seL4_LookupFailureType = (1ULL << ((sizeof(long)*8) - 1)) - 1,
} seL4_LookupFailureType;
typedef struct seL4_IPCBuffer_ {
    seL4_MessageInfo_t tag;
    seL4_Word msg[seL4_MsgMaxLength];
    seL4_Word userData;
    seL4_Word caps_or_badges[((1ul<<(seL4_MsgExtraCapBits))-1)];
    seL4_CPtr receiveCNode;
    seL4_CPtr receiveIndex;
    seL4_Word receiveDepth;
} seL4_IPCBuffer __attribute__ ((__aligned__ (sizeof(struct seL4_IPCBuffer_))));

enum {
    seL4_CapFault_IP,
    seL4_CapFault_Addr,
    seL4_CapFault_InRecvPhase,
    seL4_CapFault_LookupFailureType,
    seL4_CapFault_BitsLeft,
    seL4_CapFault_DepthMismatch_BitsFound,
    seL4_CapFault_GuardMismatch_GuardFound = seL4_CapFault_DepthMismatch_BitsFound,
    seL4_CapFault_GuardMismatch_BitsFound,
    _enum_pad_seL4_CapFault_Msg = (1ULL << ((sizeof(long)*8) - 1)) - 1,
};







void putDebugChar(unsigned char c);




unsigned char getDebugChar(void);




void putConsoleChar(unsigned char c);
void putchar(char c);

word_t kprintf(const char *format, ...) __attribute__((externally_visible)) __attribute__((format(printf, 1, 2)));
word_t puts(const char *s) __attribute__((externally_visible));
word_t print_unsigned_long(unsigned long x, word_t ui_base) __attribute__((externally_visible));



typedef word_t prio_t;

enum domainConstants {
    minDom = 0,
    maxDom = 1 - 1
};

struct cap_transfer {
    cptr_t ctReceiveRoot;
    cptr_t ctReceiveIndex;
    word_t ctReceiveDepth;
};
typedef struct cap_transfer cap_transfer_t;

enum ctLimits {
    capTransferDataSize = 3
};

static inline seL4_CapRights_t __attribute__((__const__))
rightsFromWord(word_t w)
{
    seL4_CapRights_t seL4_CapRights;

    seL4_CapRights.words[0] = w;
    return seL4_CapRights;
}

static inline word_t __attribute__((__const__))
wordFromRights(seL4_CapRights_t seL4_CapRights)
{
    return seL4_CapRights.words[0] & ((1ul << (3))-1ul);
}

static inline cap_transfer_t __attribute__((__pure__))
capTransferFromWords(word_t *wptr)
{
    cap_transfer_t transfer;

    transfer.ctReceiveRoot = (cptr_t)wptr[0];
    transfer.ctReceiveIndex = (cptr_t)wptr[1];
    transfer.ctReceiveDepth = wptr[2];
    return transfer;
}

static inline seL4_MessageInfo_t __attribute__((__const__))
messageInfoFromWord_raw(word_t w)
{
    seL4_MessageInfo_t mi;

    mi.words[0] = w;
    return mi;
}

static inline seL4_MessageInfo_t __attribute__((__const__))
messageInfoFromWord(word_t w)
{
    seL4_MessageInfo_t mi;
    word_t len;

    mi.words[0] = w;

    len = seL4_MessageInfo_get_length(mi);
    if (len > seL4_MsgMaxLength) {
        mi = seL4_MessageInfo_set_length(mi, seL4_MsgMaxLength);
    }

    return mi;
}

static inline word_t __attribute__((__const__))
wordFromMessageInfo(seL4_MessageInfo_t mi)
{
    return mi.words[0];
}



struct io_port_capdata {
    uint64_t words[1];
};
typedef struct io_port_capdata io_port_capdata_t;

static inline uint64_t __attribute__((__const__))
io_port_capdata_get_firstPort(io_port_capdata_t io_port_capdata) {
    uint64_t ret;
    ret = (io_port_capdata.words[0] & 0xffff0000ull) >> 16;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
io_port_capdata_get_lastPort(io_port_capdata_t io_port_capdata) {
    uint64_t ret;
    ret = (io_port_capdata.words[0] & 0xffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

struct cpuid_007h_ebx {
    uint32_t words[1];
};
typedef struct cpuid_007h_ebx cpuid_007h_ebx_t;

static inline uint32_t __attribute__((__const__))
cpuid_007h_ebx_get_smap(cpuid_007h_ebx_t cpuid_007h_ebx) {
    uint32_t ret;
    ret = (cpuid_007h_ebx.words[0] & 0x100000u) >> 20;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
cpuid_007h_ebx_get_smep(cpuid_007h_ebx_t cpuid_007h_ebx) {
    uint32_t ret;
    ret = (cpuid_007h_ebx.words[0] & 0x80u) >> 7;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

struct ept_pte {
    uint64_t words[1];
};
typedef struct ept_pte ept_pte_t;

static inline ept_pte_t __attribute__((__const__))
ept_pte_new(uint64_t page_base_address, uint64_t avl_cte_depth, uint64_t ignore_pat, uint64_t type, uint64_t execute, uint64_t write, uint64_t read) {
    ept_pte_t ept_pte;


    if(!((page_base_address & ~0x7fffffffff000ull) == ((0 && (page_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(page_base_address & ~0x7fffffffff000ull) == ((0 && (page_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 72, __FUNCTION__);
    if(!((avl_cte_depth & ~0x3ull) == ((0 && (avl_cte_depth & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(avl_cte_depth & ~0x3ull) == ((0 && (avl_cte_depth & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 73, __FUNCTION__);
    if(!((ignore_pat & ~0x1ull) == ((0 && (ignore_pat & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(ignore_pat & ~0x1ull) == ((0 && (ignore_pat & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 74, __FUNCTION__);
    if(!((type & ~0x7ull) == ((0 && (type & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(type & ~0x7ull) == ((0 && (type & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 75, __FUNCTION__);
    if(!((execute & ~0x1ull) == ((0 && (execute & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(execute & ~0x1ull) == ((0 && (execute & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 76, __FUNCTION__);
    if(!((write & ~0x1ull) == ((0 && (write & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(write & ~0x1ull) == ((0 && (write & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 77, __FUNCTION__);
    if(!((read & ~0x1ull) == ((0 && (read & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(read & ~0x1ull) == ((0 && (read & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 78, __FUNCTION__);

    ept_pte.words[0] = 0
        | (page_base_address & 0x7fffffffff000ull) >> 0
        | (avl_cte_depth & 0x3ull) << 10
        | (ignore_pat & 0x1ull) << 6
        | (type & 0x7ull) << 3
        | (execute & 0x1ull) << 2
        | (write & 0x1ull) << 1
        | (read & 0x1ull) << 0;

    return ept_pte;
}

static inline uint64_t __attribute__((__pure__))
ept_pte_ptr_get_page_base_address(ept_pte_t *ept_pte_ptr) {
    uint64_t ret;
    ret = (ept_pte_ptr->words[0] & 0x7fffffffff000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
ept_pte_ptr_get_read(ept_pte_t *ept_pte_ptr) {
    uint64_t ret;
    ret = (ept_pte_ptr->words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

struct x2apic_icr2 {
    uint32_t words[1];
};
typedef struct x2apic_icr2 x2apic_icr2_t;

static inline x2apic_icr2_t __attribute__((__const__))
x2apic_icr2_new(uint32_t dest) {
    x2apic_icr2_t x2apic_icr2;



    x2apic_icr2.words[0] = 0
        | dest << 0;;

    return x2apic_icr2;
}

struct cpuid_007h_edx {
    uint32_t words[1];
};
typedef struct cpuid_007h_edx cpuid_007h_edx_t;

static inline uint32_t __attribute__((__const__))
cpuid_007h_edx_get_ia32_arch_cap_msr(cpuid_007h_edx_t cpuid_007h_edx) {
    uint32_t ret;
    ret = (cpuid_007h_edx.words[0] & 0x20000000u) >> 29;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
cpuid_007h_edx_get_ibrs_ibpb(cpuid_007h_edx_t cpuid_007h_edx) {
    uint32_t ret;
    ret = (cpuid_007h_edx.words[0] & 0x4000000u) >> 26;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

struct pte {
    uint64_t words[1];
};
typedef struct pte pte_t;

static inline pte_t __attribute__((__const__))
pte_new(uint64_t xd, uint64_t page_base_address, uint64_t global, uint64_t pat, uint64_t dirty, uint64_t accessed, uint64_t cache_disabled, uint64_t write_through, uint64_t super_user, uint64_t read_write, uint64_t present) {
    pte_t pte;


    if(!((xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 168, __FUNCTION__);
    if(!((page_base_address & ~0x7fffffffff000ull) == ((0 && (page_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(page_base_address & ~0x7fffffffff000ull) == ((0 && (page_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 169, __FUNCTION__);
    if(!((global & ~0x1ull) == ((0 && (global & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(global & ~0x1ull) == ((0 && (global & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 170, __FUNCTION__);
    if(!((pat & ~0x1ull) == ((0 && (pat & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(pat & ~0x1ull) == ((0 && (pat & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 171, __FUNCTION__);
    if(!((dirty & ~0x1ull) == ((0 && (dirty & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(dirty & ~0x1ull) == ((0 && (dirty & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 172, __FUNCTION__);
    if(!((accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 173, __FUNCTION__);
    if(!((cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 174, __FUNCTION__);
    if(!((write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 175, __FUNCTION__);
    if(!((super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 176, __FUNCTION__);
    if(!((read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 177, __FUNCTION__);
    if(!((present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 178, __FUNCTION__);

    pte.words[0] = 0
        | (xd & 0x1ull) << 63
        | (page_base_address & 0x7fffffffff000ull) >> 0
        | (global & 0x1ull) << 8
        | (pat & 0x1ull) << 7
        | (dirty & 0x1ull) << 6
        | (accessed & 0x1ull) << 5
        | (cache_disabled & 0x1ull) << 4
        | (write_through & 0x1ull) << 3
        | (super_user & 0x1ull) << 2
        | (read_write & 0x1ull) << 1
        | (present & 0x1ull) << 0;

    return pte;
}

static inline uint64_t __attribute__((__const__))
pte_get_page_base_address(pte_t pte) {
    uint64_t ret;
    ret = (pte.words[0] & 0x7fffffffff000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
pte_ptr_get_page_base_address(pte_t *pte_ptr) {
    uint64_t ret;
    ret = (pte_ptr->words[0] & 0x7fffffffff000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
pte_get_super_user(pte_t pte) {
    uint64_t ret;
    ret = (pte.words[0] & 0x4ull) >> 2;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
pte_get_present(pte_t pte) {
    uint64_t ret;
    ret = (pte.words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
pte_ptr_get_present(pte_t *pte_ptr) {
    uint64_t ret;
    ret = (pte_ptr->words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

struct ept_pml4e {
    uint64_t words[1];
};
typedef struct ept_pml4e ept_pml4e_t;

static inline ept_pml4e_t __attribute__((__const__))
ept_pml4e_new(uint64_t pdpt_base_address, uint64_t execute, uint64_t write, uint64_t read) {
    ept_pml4e_t ept_pml4e;


    if(!((pdpt_base_address & ~0x7fffffffff000ull) == ((0 && (pdpt_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(pdpt_base_address & ~0x7fffffffff000ull) == ((0 && (pdpt_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 261, __FUNCTION__);
    if(!((execute & ~0x1ull) == ((0 && (execute & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(execute & ~0x1ull) == ((0 && (execute & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 262, __FUNCTION__);
    if(!((write & ~0x1ull) == ((0 && (write & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(write & ~0x1ull) == ((0 && (write & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 263, __FUNCTION__);
    if(!((read & ~0x1ull) == ((0 && (read & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(read & ~0x1ull) == ((0 && (read & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 264, __FUNCTION__);

    ept_pml4e.words[0] = 0
        | (pdpt_base_address & 0x7fffffffff000ull) >> 0
        | (execute & 0x1ull) << 2
        | (write & 0x1ull) << 1
        | (read & 0x1ull) << 0;

    return ept_pml4e;
}

static inline uint64_t __attribute__((__pure__))
ept_pml4e_ptr_get_pdpt_base_address(ept_pml4e_t *ept_pml4e_ptr) {
    uint64_t ret;
    ret = (ept_pml4e_ptr->words[0] & 0x7fffffffff000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
ept_pml4e_ptr_get_read(ept_pml4e_t *ept_pml4e_ptr) {
    uint64_t ret;
    ret = (ept_pml4e_ptr->words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

struct ept_pdpte {
    uint64_t words[1];
};
typedef struct ept_pdpte ept_pdpte_t;

static inline ept_pdpte_t __attribute__((__const__))
ept_pdpte_new(uint64_t pd_base_address, uint64_t avl_cte_depth, uint64_t execute, uint64_t write, uint64_t read) {
    ept_pdpte_t ept_pdpte;


    if(!((pd_base_address & ~0x7fffffffff000ull) == ((0 && (pd_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(pd_base_address & ~0x7fffffffff000ull) == ((0 && (pd_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 307, __FUNCTION__);
    if(!((avl_cte_depth & ~0x7ull) == ((0 && (avl_cte_depth & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(avl_cte_depth & ~0x7ull) == ((0 && (avl_cte_depth & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 308, __FUNCTION__);
    if(!((execute & ~0x1ull) == ((0 && (execute & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(execute & ~0x1ull) == ((0 && (execute & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 309, __FUNCTION__);
    if(!((write & ~0x1ull) == ((0 && (write & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(write & ~0x1ull) == ((0 && (write & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 310, __FUNCTION__);
    if(!((read & ~0x1ull) == ((0 && (read & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(read & ~0x1ull) == ((0 && (read & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 311, __FUNCTION__);

    ept_pdpte.words[0] = 0
        | (pd_base_address & 0x7fffffffff000ull) >> 0
        | (avl_cte_depth & 0x7ull) << 9
        | (execute & 0x1ull) << 2
        | (write & 0x1ull) << 1
        | (read & 0x1ull) << 0;

    return ept_pdpte;
}

static inline uint64_t __attribute__((__pure__))
ept_pdpte_ptr_get_pd_base_address(ept_pdpte_t *ept_pdpte_ptr) {
    uint64_t ret;
    ret = (ept_pdpte_ptr->words[0] & 0x7fffffffff000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
ept_pdpte_ptr_get_read(ept_pdpte_t *ept_pdpte_ptr) {
    uint64_t ret;
    ret = (ept_pdpte_ptr->words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

struct apic_icr1 {
    uint32_t words[1];
};
typedef struct apic_icr1 apic_icr1_t;

static inline apic_icr1_t __attribute__((__const__))
apic_icr1_new(uint32_t dest_shorthand, uint32_t trigger_mode, uint32_t level, uint32_t delivery_status, uint32_t dest_mode, uint32_t delivery_mode, uint32_t vector) {
    apic_icr1_t apic_icr1;


    if(!((dest_shorthand & ~0x3u) == ((0 && (dest_shorthand & (1u << 31))) ? 0x0 : 0))) _assert_fail("(dest_shorthand & ~0x3u) == ((0 && (dest_shorthand & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 355, __FUNCTION__);
    if(!((trigger_mode & ~0x1u) == ((0 && (trigger_mode & (1u << 31))) ? 0x0 : 0))) _assert_fail("(trigger_mode & ~0x1u) == ((0 && (trigger_mode & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 356, __FUNCTION__);
    if(!((level & ~0x1u) == ((0 && (level & (1u << 31))) ? 0x0 : 0))) _assert_fail("(level & ~0x1u) == ((0 && (level & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 357, __FUNCTION__);
    if(!((delivery_status & ~0x1u) == ((0 && (delivery_status & (1u << 31))) ? 0x0 : 0))) _assert_fail("(delivery_status & ~0x1u) == ((0 && (delivery_status & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 358, __FUNCTION__);
    if(!((dest_mode & ~0x1u) == ((0 && (dest_mode & (1u << 31))) ? 0x0 : 0))) _assert_fail("(dest_mode & ~0x1u) == ((0 && (dest_mode & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 359, __FUNCTION__);
    if(!((delivery_mode & ~0x7u) == ((0 && (delivery_mode & (1u << 31))) ? 0x0 : 0))) _assert_fail("(delivery_mode & ~0x7u) == ((0 && (delivery_mode & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 360, __FUNCTION__);
    if(!((vector & ~0xffu) == ((0 && (vector & (1u << 31))) ? 0x0 : 0))) _assert_fail("(vector & ~0xffu) == ((0 && (vector & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 361, __FUNCTION__);

    apic_icr1.words[0] = 0
        | (dest_shorthand & 0x3u) << 18
        | (trigger_mode & 0x1u) << 15
        | (level & 0x1u) << 14
        | (delivery_status & 0x1u) << 12
        | (dest_mode & 0x1u) << 11
        | (delivery_mode & 0x7u) << 8
        | (vector & 0xffu) << 0;

    return apic_icr1;
}

static inline uint32_t __attribute__((__const__))
apic_icr1_get_delivery_status(apic_icr1_t apic_icr1) {
    uint32_t ret;
    ret = (apic_icr1.words[0] & 0x1000u) >> 12;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

struct apic_icr2 {
    uint32_t words[1];
};
typedef struct apic_icr2 apic_icr2_t;

static inline apic_icr2_t __attribute__((__const__))
apic_icr2_new(uint32_t dest) {
    apic_icr2_t apic_icr2;


    if(!((dest & ~0xffu) == ((0 && (dest & (1u << 31))) ? 0x0 : 0))) _assert_fail("(dest & ~0xffu) == ((0 && (dest & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 396, __FUNCTION__);

    apic_icr2.words[0] = 0
        | (dest & 0xffu) << 24;

    return apic_icr2;
}

struct x86_pat_msr {
    uint32_t words[2];
};
typedef struct x86_pat_msr x86_pat_msr_t;

static inline x86_pat_msr_t __attribute__((__const__))
x86_pat_msr_set_pa4(x86_pat_msr_t x86_pat_msr, uint32_t v32) {

    if(!((((~0x7 >> 0 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0))) _assert_fail("(((~0x7 >> 0 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 412, __FUNCTION__);
    x86_pat_msr.words[1] &= ~0x7u;
    x86_pat_msr.words[1] |= (v32 << 0) & 0x7u;
    return x86_pat_msr;
}

static inline x86_pat_msr_t __attribute__((__const__))
x86_pat_msr_set_pa3(x86_pat_msr_t x86_pat_msr, uint32_t v32) {

    if(!((((~0x7000000 >> 24 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0))) _assert_fail("(((~0x7000000 >> 24 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 421, __FUNCTION__);
    x86_pat_msr.words[0] &= ~0x7000000u;
    x86_pat_msr.words[0] |= (v32 << 24) & 0x7000000u;
    return x86_pat_msr;
}

static inline x86_pat_msr_t __attribute__((__const__))
x86_pat_msr_set_pa2(x86_pat_msr_t x86_pat_msr, uint32_t v32) {

    if(!((((~0x70000 >> 16 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0))) _assert_fail("(((~0x70000 >> 16 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 430, __FUNCTION__);
    x86_pat_msr.words[0] &= ~0x70000u;
    x86_pat_msr.words[0] |= (v32 << 16) & 0x70000u;
    return x86_pat_msr;
}

static inline x86_pat_msr_t __attribute__((__const__))
x86_pat_msr_set_pa1(x86_pat_msr_t x86_pat_msr, uint32_t v32) {

    if(!((((~0x700 >> 8 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0))) _assert_fail("(((~0x700 >> 8 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 439, __FUNCTION__);
    x86_pat_msr.words[0] &= ~0x700u;
    x86_pat_msr.words[0] |= (v32 << 8) & 0x700u;
    return x86_pat_msr;
}

static inline x86_pat_msr_t __attribute__((__const__))
x86_pat_msr_set_pa0(x86_pat_msr_t x86_pat_msr, uint32_t v32) {

    if(!((((~0x7 >> 0 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0))) _assert_fail("(((~0x7 >> 0 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 448, __FUNCTION__);
    x86_pat_msr.words[0] &= ~0x7u;
    x86_pat_msr.words[0] |= (v32 << 0) & 0x7u;
    return x86_pat_msr;
}

struct cpuid_001h_eax {
    uint32_t words[1];
};
typedef struct cpuid_001h_eax cpuid_001h_eax_t;

static inline uint32_t __attribute__((__const__))
cpuid_001h_eax_get_extended_family(cpuid_001h_eax_t cpuid_001h_eax) {
    uint32_t ret;
    ret = (cpuid_001h_eax.words[0] & 0xff00000u) >> 20;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
cpuid_001h_eax_get_extended_model(cpuid_001h_eax_t cpuid_001h_eax) {
    uint32_t ret;
    ret = (cpuid_001h_eax.words[0] & 0xf0000u) >> 16;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
cpuid_001h_eax_get_family(cpuid_001h_eax_t cpuid_001h_eax) {
    uint32_t ret;
    ret = (cpuid_001h_eax.words[0] & 0xf00u) >> 8;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
cpuid_001h_eax_get_model(cpuid_001h_eax_t cpuid_001h_eax) {
    uint32_t ret;
    ret = (cpuid_001h_eax.words[0] & 0xf0u) >> 4;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
cpuid_001h_eax_get_stepping(cpuid_001h_eax_t cpuid_001h_eax) {
    uint32_t ret;
    ret = (cpuid_001h_eax.words[0] & 0xfu) >> 0;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

struct cr3 {
    uint64_t words[1];
};
typedef struct cr3 cr3_t;

static inline cr3_t __attribute__((__const__))
cr3_new(uint64_t pml4_base_address, uint64_t pcid) {
    cr3_t cr3;


    if(!((pml4_base_address & ~0x7fffffffff000ull) == ((0 && (pml4_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(pml4_base_address & ~0x7fffffffff000ull) == ((0 && (pml4_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 524, __FUNCTION__);
    if(!((pcid & ~0xfffull) == ((0 && (pcid & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(pcid & ~0xfffull) == ((0 && (pcid & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 525, __FUNCTION__);

    cr3.words[0] = 0
        | (pml4_base_address & 0x7fffffffff000ull) >> 0
        | (pcid & 0xfffull) << 0;

    return cr3;
}

static inline uint64_t __attribute__((__const__))
cr3_get_pml4_base_address(cr3_t cr3) {
    uint64_t ret;
    ret = (cr3.words[0] & 0x7fffffffff000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cr3_get_pcid(cr3_t cr3) {
    uint64_t ret;
    ret = (cr3.words[0] & 0xfffull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

struct vmx_eptp {
    uint64_t words[1];
};
typedef struct vmx_eptp vmx_eptp_t;

static inline vmx_eptp_t __attribute__((__const__))
vmx_eptp_new(uint64_t paddr, uint64_t flags, uint64_t depth_minus_1, uint64_t memory_type) {
    vmx_eptp_t vmx_eptp;


    if(!((paddr & ~0x7fffffffff000ull) == ((0 && (paddr & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(paddr & ~0x7fffffffff000ull) == ((0 && (paddr & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 566, __FUNCTION__);
    if(!((flags & ~0x1ull) == ((0 && (flags & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(flags & ~0x1ull) == ((0 && (flags & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 567, __FUNCTION__);
    if(!((depth_minus_1 & ~0x7ull) == ((0 && (depth_minus_1 & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(depth_minus_1 & ~0x7ull) == ((0 && (depth_minus_1 & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 568, __FUNCTION__);
    if(!((memory_type & ~0x7ull) == ((0 && (memory_type & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(memory_type & ~0x7ull) == ((0 && (memory_type & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 569, __FUNCTION__);

    vmx_eptp.words[0] = 0
        | (paddr & 0x7fffffffff000ull) >> 0
        | (flags & 0x1ull) << 6
        | (depth_minus_1 & 0x7ull) << 3
        | (memory_type & 0x7ull) << 0;

    return vmx_eptp;
}

struct ia32_arch_capabilities_msr {
    uint32_t words[1];
};
typedef struct ia32_arch_capabilities_msr ia32_arch_capabilities_msr_t;

static inline uint32_t __attribute__((__const__))
ia32_arch_capabilities_msr_get_ibrs_all(ia32_arch_capabilities_msr_t ia32_arch_capabilities_msr) {
    uint32_t ret;
    ret = (ia32_arch_capabilities_msr.words[0] & 0x2u) >> 1;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
ia32_arch_capabilities_msr_get_rdcl_no(ia32_arch_capabilities_msr_t ia32_arch_capabilities_msr) {
    uint32_t ret;
    ret = (ia32_arch_capabilities_msr.words[0] & 0x1u) >> 0;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

struct thread_state {
    uint64_t words[3];
};
typedef struct thread_state thread_state_t;

static inline uint64_t __attribute__((__pure__))
thread_state_ptr_get_blockingIPCBadge(thread_state_t *thread_state_ptr) {
    uint64_t ret;
    ret = (thread_state_ptr->words[2] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
thread_state_ptr_set_blockingIPCBadge(thread_state_t *thread_state_ptr, uint64_t v64) {

    if(!((((~0xffffffffffffffff >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffffffffffffff >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 626, __FUNCTION__);
    thread_state_ptr->words[2] &= ~0xffffffffffffffffull;
    thread_state_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffff;
}

static inline uint64_t __attribute__((__pure__))
thread_state_ptr_get_blockingIPCCanGrant(thread_state_t *thread_state_ptr) {
    uint64_t ret;
    ret = (thread_state_ptr->words[1] & 0x8ull) >> 3;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
thread_state_ptr_set_blockingIPCCanGrant(thread_state_t *thread_state_ptr, uint64_t v64) {

    if(!((((~0x8 >> 3) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x8 >> 3) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 645, __FUNCTION__);
    thread_state_ptr->words[1] &= ~0x8ull;
    thread_state_ptr->words[1] |= (v64 << 3) & 0x8;
}

static inline uint64_t __attribute__((__pure__))
thread_state_ptr_get_blockingIPCIsCall(thread_state_t *thread_state_ptr) {
    uint64_t ret;
    ret = (thread_state_ptr->words[1] & 0x4ull) >> 2;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
thread_state_ptr_set_blockingIPCIsCall(thread_state_t *thread_state_ptr, uint64_t v64) {

    if(!((((~0x4 >> 2) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x4 >> 2) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 664, __FUNCTION__);
    thread_state_ptr->words[1] &= ~0x4ull;
    thread_state_ptr->words[1] |= (v64 << 2) & 0x4;
}

static inline uint64_t __attribute__((__const__))
thread_state_get_tcbQueued(thread_state_t thread_state) {
    uint64_t ret;
    ret = (thread_state.words[1] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
thread_state_ptr_set_tcbQueued(thread_state_t *thread_state_ptr, uint64_t v64) {

    if(!((((~0x1 >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x1 >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 683, __FUNCTION__);
    thread_state_ptr->words[1] &= ~0x1ull;
    thread_state_ptr->words[1] |= (v64 << 0) & 0x1;
}

static inline uint64_t __attribute__((__pure__))
thread_state_ptr_get_blockingObject(thread_state_t *thread_state_ptr) {
    uint64_t ret;
    ret = (thread_state_ptr->words[0] & 0xfffffffffff0ull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline void
thread_state_ptr_set_blockingObject(thread_state_t *thread_state_ptr, uint64_t v64) {

    if(!((((~0xfffffffffff0 << 0) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0xfffffffffff0 << 0) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 702, __FUNCTION__);
    thread_state_ptr->words[0] &= ~0xfffffffffff0ull;
    thread_state_ptr->words[0] |= (v64 >> 0) & 0xfffffffffff0;
}

static inline uint64_t __attribute__((__const__))
thread_state_get_tsType(thread_state_t thread_state) {
    uint64_t ret;
    ret = (thread_state.words[0] & 0xfull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
thread_state_ptr_get_tsType(thread_state_t *thread_state_ptr) {
    uint64_t ret;
    ret = (thread_state_ptr->words[0] & 0xfull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
thread_state_ptr_set_tsType(thread_state_t *thread_state_ptr, uint64_t v64) {

    if(!((((~0xf >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xf >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 732, __FUNCTION__);
    thread_state_ptr->words[0] &= ~0xfull;
    thread_state_ptr->words[0] |= (v64 << 0) & 0xf;
}

struct notification {
    uint64_t words[4];
};
typedef struct notification notification_t;

static inline uint64_t __attribute__((__pure__))
notification_ptr_get_ntfnBoundTCB(notification_t *notification_ptr) {
    uint64_t ret;
    ret = (notification_ptr->words[3] & 0xffffffffffffull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline void
notification_ptr_set_ntfnBoundTCB(notification_t *notification_ptr, uint64_t v64) {

    if(!((((~0xffffffffffff << 0) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0xffffffffffff << 0) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 756, __FUNCTION__);
    notification_ptr->words[3] &= ~0xffffffffffffull;
    notification_ptr->words[3] |= (v64 >> 0) & 0xffffffffffff;
}

static inline uint64_t __attribute__((__pure__))
notification_ptr_get_ntfnMsgIdentifier(notification_t *notification_ptr) {
    uint64_t ret;
    ret = (notification_ptr->words[2] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
notification_ptr_set_ntfnMsgIdentifier(notification_t *notification_ptr, uint64_t v64) {

    if(!((((~0xffffffffffffffff >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffffffffffffff >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 775, __FUNCTION__);
    notification_ptr->words[2] &= ~0xffffffffffffffffull;
    notification_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffff;
}

static inline uint64_t __attribute__((__pure__))
notification_ptr_get_ntfnQueue_head(notification_t *notification_ptr) {
    uint64_t ret;
    ret = (notification_ptr->words[1] & 0xffffffffffffull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline void
notification_ptr_set_ntfnQueue_head(notification_t *notification_ptr, uint64_t v64) {

    if(!((((~0xffffffffffff << 0) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0xffffffffffff << 0) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 794, __FUNCTION__);
    notification_ptr->words[1] &= ~0xffffffffffffull;
    notification_ptr->words[1] |= (v64 >> 0) & 0xffffffffffff;
}

static inline uint64_t __attribute__((__pure__))
notification_ptr_get_ntfnQueue_tail(notification_t *notification_ptr) {
    uint64_t ret;
    ret = (notification_ptr->words[0] & 0xffffffffffff0000ull) >> 16;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline void
notification_ptr_set_ntfnQueue_tail(notification_t *notification_ptr, uint64_t v64) {

    if(!((((~0xffffffffffff0000 >> 16) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0xffffffffffff0000 >> 16) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 813, __FUNCTION__);
    notification_ptr->words[0] &= ~0xffffffffffff0000ull;
    notification_ptr->words[0] |= (v64 << 16) & 0xffffffffffff0000;
}

static inline uint64_t __attribute__((__pure__))
notification_ptr_get_state(notification_t *notification_ptr) {
    uint64_t ret;
    ret = (notification_ptr->words[0] & 0x3ull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
notification_ptr_set_state(notification_t *notification_ptr, uint64_t v64) {

    if(!((((~0x3 >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x3 >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 832, __FUNCTION__);
    notification_ptr->words[0] &= ~0x3ull;
    notification_ptr->words[0] |= (v64 << 0) & 0x3;
}

struct task_gate {
    uint64_t words[2];
};
typedef struct task_gate task_gate_t;

struct apic_base_msr {
    uint32_t words[1];
};
typedef struct apic_base_msr apic_base_msr_t;

static inline uint32_t __attribute__((__const__))
apic_base_msr_get_base_addr(apic_base_msr_t apic_base_msr) {
    uint32_t ret;
    ret = (apic_base_msr.words[0] & 0xfffff000u) << 0;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
apic_base_msr_get_enabled(apic_base_msr_t apic_base_msr) {
    uint32_t ret;
    ret = (apic_base_msr.words[0] & 0x800u) >> 11;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
apic_base_msr_get_x2apic(apic_base_msr_t apic_base_msr) {
    uint32_t ret;
    ret = (apic_base_msr.words[0] & 0x400u) >> 10;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline apic_base_msr_t __attribute__((__const__))
apic_base_msr_set_x2apic(apic_base_msr_t apic_base_msr, uint32_t v32) {

    if(!((((~0x400 >> 10 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0))) _assert_fail("(((~0x400 >> 10 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 883, __FUNCTION__);
    apic_base_msr.words[0] &= ~0x400u;
    apic_base_msr.words[0] |= (v32 << 10) & 0x400u;
    return apic_base_msr;
}

struct tss {
    uint64_t words[13];
};
typedef struct tss tss_t;

static inline tss_t __attribute__((__const__))
tss_new(uint64_t io_map_base, uint64_t ist7_u, uint64_t ist7_l, uint64_t ist6_u, uint64_t ist6_l, uint64_t ist5_u, uint64_t ist5_l, uint64_t ist4_u, uint64_t ist4_l, uint64_t ist3_u, uint64_t ist3_l, uint64_t ist2_u, uint64_t ist2_l, uint64_t ist1_u, uint64_t ist1_l, uint64_t rsp2_u, uint64_t rsp2_l, uint64_t rsp1_u, uint64_t rsp1_l, uint64_t rsp0_u, uint64_t rsp0_l) {
    tss_t tss;


    if(!((io_map_base & ~0xffffull) == ((1 && (io_map_base & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(io_map_base & ~0xffffull) == ((1 && (io_map_base & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 899, __FUNCTION__);
    if(!((ist7_u & ~0xffffffffull) == ((1 && (ist7_u & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist7_u & ~0xffffffffull) == ((1 && (ist7_u & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 900, __FUNCTION__);
    if(!((ist7_l & ~0xffffffffull) == ((1 && (ist7_l & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist7_l & ~0xffffffffull) == ((1 && (ist7_l & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 901, __FUNCTION__);
    if(!((ist6_u & ~0xffffffffull) == ((1 && (ist6_u & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist6_u & ~0xffffffffull) == ((1 && (ist6_u & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 902, __FUNCTION__);
    if(!((ist6_l & ~0xffffffffull) == ((1 && (ist6_l & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist6_l & ~0xffffffffull) == ((1 && (ist6_l & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 903, __FUNCTION__);
    if(!((ist5_u & ~0xffffffffull) == ((1 && (ist5_u & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist5_u & ~0xffffffffull) == ((1 && (ist5_u & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 904, __FUNCTION__);
    if(!((ist5_l & ~0xffffffffull) == ((1 && (ist5_l & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist5_l & ~0xffffffffull) == ((1 && (ist5_l & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 905, __FUNCTION__);
    if(!((ist4_u & ~0xffffffffull) == ((1 && (ist4_u & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist4_u & ~0xffffffffull) == ((1 && (ist4_u & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 906, __FUNCTION__);
    if(!((ist4_l & ~0xffffffffull) == ((1 && (ist4_l & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist4_l & ~0xffffffffull) == ((1 && (ist4_l & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 907, __FUNCTION__);
    if(!((ist3_u & ~0xffffffffull) == ((1 && (ist3_u & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist3_u & ~0xffffffffull) == ((1 && (ist3_u & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 908, __FUNCTION__);
    if(!((ist3_l & ~0xffffffffull) == ((1 && (ist3_l & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist3_l & ~0xffffffffull) == ((1 && (ist3_l & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 909, __FUNCTION__);
    if(!((ist2_u & ~0xffffffffull) == ((1 && (ist2_u & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist2_u & ~0xffffffffull) == ((1 && (ist2_u & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 910, __FUNCTION__);
    if(!((ist2_l & ~0xffffffffull) == ((1 && (ist2_l & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist2_l & ~0xffffffffull) == ((1 && (ist2_l & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 911, __FUNCTION__);
    if(!((ist1_u & ~0xffffffffull) == ((1 && (ist1_u & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist1_u & ~0xffffffffull) == ((1 && (ist1_u & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 912, __FUNCTION__);
    if(!((ist1_l & ~0xffffffffull) == ((1 && (ist1_l & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist1_l & ~0xffffffffull) == ((1 && (ist1_l & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 913, __FUNCTION__);
    if(!((rsp2_u & ~0xffffffffull) == ((1 && (rsp2_u & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(rsp2_u & ~0xffffffffull) == ((1 && (rsp2_u & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 914, __FUNCTION__);
    if(!((rsp2_l & ~0xffffffffull) == ((1 && (rsp2_l & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(rsp2_l & ~0xffffffffull) == ((1 && (rsp2_l & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 915, __FUNCTION__);
    if(!((rsp1_u & ~0xffffffffull) == ((1 && (rsp1_u & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(rsp1_u & ~0xffffffffull) == ((1 && (rsp1_u & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 916, __FUNCTION__);
    if(!((rsp1_l & ~0xffffffffull) == ((1 && (rsp1_l & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(rsp1_l & ~0xffffffffull) == ((1 && (rsp1_l & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 917, __FUNCTION__);
    if(!((rsp0_u & ~0xffffffffull) == ((1 && (rsp0_u & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(rsp0_u & ~0xffffffffull) == ((1 && (rsp0_u & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 918, __FUNCTION__);
    if(!((rsp0_l & ~0xffffffffull) == ((1 && (rsp0_l & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(rsp0_l & ~0xffffffffull) == ((1 && (rsp0_l & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 919, __FUNCTION__);

    tss.words[0] = 0
        | (rsp0_l & 0xffffffffull) << 32;
    tss.words[1] = 0
        | (rsp1_l & 0xffffffffull) << 32
        | (rsp0_u & 0xffffffffull) << 0;
    tss.words[2] = 0
        | (rsp2_l & 0xffffffffull) << 32
        | (rsp1_u & 0xffffffffull) << 0;
    tss.words[3] = 0
        | (rsp2_u & 0xffffffffull) << 0;
    tss.words[4] = 0
        | (ist1_l & 0xffffffffull) << 32;
    tss.words[5] = 0
        | (ist2_l & 0xffffffffull) << 32
        | (ist1_u & 0xffffffffull) << 0;
    tss.words[6] = 0
        | (ist3_l & 0xffffffffull) << 32
        | (ist2_u & 0xffffffffull) << 0;
    tss.words[7] = 0
        | (ist4_l & 0xffffffffull) << 32
        | (ist3_u & 0xffffffffull) << 0;
    tss.words[8] = 0
        | (ist5_l & 0xffffffffull) << 32
        | (ist4_u & 0xffffffffull) << 0;
    tss.words[9] = 0
        | (ist6_l & 0xffffffffull) << 32
        | (ist5_u & 0xffffffffull) << 0;
    tss.words[10] = 0
        | (ist7_l & 0xffffffffull) << 32
        | (ist6_u & 0xffffffffull) << 0;
    tss.words[11] = 0
        | (ist7_u & 0xffffffffull) << 0;
    tss.words[12] = 0
        | (io_map_base & 0xffffull) << 48;

    return tss;
}

struct cpuid_001h_ebx {
    uint32_t words[1];
};
typedef struct cpuid_001h_ebx cpuid_001h_ebx_t;

static inline uint32_t __attribute__((__const__))
cpuid_001h_ebx_get_brand(cpuid_001h_ebx_t cpuid_001h_ebx) {
    uint32_t ret;
    ret = (cpuid_001h_ebx.words[0] & 0xffu) >> 0;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

struct apic_version {
    uint32_t words[1];
};
typedef struct apic_version apic_version_t;

static inline uint32_t __attribute__((__const__))
apic_version_get_max_lvt_entry(apic_version_t apic_version) {
    uint32_t ret;
    ret = (apic_version.words[0] & 0xff0000u) >> 16;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
apic_version_get_version(apic_version_t apic_version) {
    uint32_t ret;
    ret = (apic_version.words[0] & 0xffu) >> 0;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

struct mdb_node {
    uint64_t words[2];
};
typedef struct mdb_node mdb_node_t;

static inline mdb_node_t __attribute__((__const__))
mdb_node_new(uint64_t mdbNext, uint64_t mdbRevocable, uint64_t mdbFirstBadged, uint64_t mdbPrev) {
    mdb_node_t mdb_node;


    if(!((mdbNext & ~0xfffffffffffcull) == ((1 && (mdbNext & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(mdbNext & ~0xfffffffffffcull) == ((1 && (mdbNext & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 1012, __FUNCTION__);
    if(!((mdbRevocable & ~0x1ull) == ((1 && (mdbRevocable & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(mdbRevocable & ~0x1ull) == ((1 && (mdbRevocable & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1013, __FUNCTION__);
    if(!((mdbFirstBadged & ~0x1ull) == ((1 && (mdbFirstBadged & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(mdbFirstBadged & ~0x1ull) == ((1 && (mdbFirstBadged & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1014, __FUNCTION__);

    mdb_node.words[0] = 0
        | mdbPrev << 0;;
    mdb_node.words[1] = 0
        | (mdbNext & 0xfffffffffffcull) >> 0
        | (mdbRevocable & 0x1ull) << 1
        | (mdbFirstBadged & 0x1ull) << 0;

    return mdb_node;
}

static inline uint64_t __attribute__((__const__))
mdb_node_get_mdbNext(mdb_node_t mdb_node) {
    uint64_t ret;
    ret = (mdb_node.words[1] & 0xfffffffffffcull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline void
mdb_node_ptr_set_mdbNext(mdb_node_t *mdb_node_ptr, uint64_t v64) {

    if(!((((~0xfffffffffffc << 0) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0xfffffffffffc << 0) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 1040, __FUNCTION__);
    mdb_node_ptr->words[1] &= ~0xfffffffffffcull;
    mdb_node_ptr->words[1] |= (v64 >> 0) & 0xfffffffffffc;
}

static inline uint64_t __attribute__((__const__))
mdb_node_get_mdbRevocable(mdb_node_t mdb_node) {
    uint64_t ret;
    ret = (mdb_node.words[1] & 0x2ull) >> 1;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline mdb_node_t __attribute__((__const__))
mdb_node_set_mdbRevocable(mdb_node_t mdb_node, uint64_t v64) {

    if(!((((~0x2 >> 1 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x2 >> 1 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1059, __FUNCTION__);
    mdb_node.words[1] &= ~0x2ull;
    mdb_node.words[1] |= (v64 << 1) & 0x2ull;
    return mdb_node;
}

static inline void
mdb_node_ptr_set_mdbRevocable(mdb_node_t *mdb_node_ptr, uint64_t v64) {

    if(!((((~0x2 >> 1) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x2 >> 1) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1068, __FUNCTION__);
    mdb_node_ptr->words[1] &= ~0x2ull;
    mdb_node_ptr->words[1] |= (v64 << 1) & 0x2;
}

static inline uint64_t __attribute__((__const__))
mdb_node_get_mdbFirstBadged(mdb_node_t mdb_node) {
    uint64_t ret;
    ret = (mdb_node.words[1] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline mdb_node_t __attribute__((__const__))
mdb_node_set_mdbFirstBadged(mdb_node_t mdb_node, uint64_t v64) {

    if(!((((~0x1 >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x1 >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1087, __FUNCTION__);
    mdb_node.words[1] &= ~0x1ull;
    mdb_node.words[1] |= (v64 << 0) & 0x1ull;
    return mdb_node;
}

static inline void
mdb_node_ptr_set_mdbFirstBadged(mdb_node_t *mdb_node_ptr, uint64_t v64) {

    if(!((((~0x1 >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x1 >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1096, __FUNCTION__);
    mdb_node_ptr->words[1] &= ~0x1ull;
    mdb_node_ptr->words[1] |= (v64 << 0) & 0x1;
}

static inline uint64_t __attribute__((__const__))
mdb_node_get_mdbPrev(mdb_node_t mdb_node) {
    uint64_t ret;
    ret = (mdb_node.words[0] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline mdb_node_t __attribute__((__const__))
mdb_node_set_mdbPrev(mdb_node_t mdb_node, uint64_t v64) {

    if(!((((~0xffffffffffffffff >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffffffffffffff >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1115, __FUNCTION__);
    mdb_node.words[0] &= ~0xffffffffffffffffull;
    mdb_node.words[0] |= (v64 << 0) & 0xffffffffffffffffull;
    return mdb_node;
}

static inline void
mdb_node_ptr_set_mdbPrev(mdb_node_t *mdb_node_ptr, uint64_t v64) {

    if(!((((~0xffffffffffffffff >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffffffffffffff >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1124, __FUNCTION__);
    mdb_node_ptr->words[0] &= ~0xffffffffffffffffull;
    mdb_node_ptr->words[0] |= (v64 << 0) & 0xffffffffffffffff;
}

struct pml4e {
    uint64_t words[1];
};
typedef struct pml4e pml4e_t;

static inline pml4e_t __attribute__((__const__))
pml4e_new(uint64_t xd, uint64_t pdpt_base_address, uint64_t accessed, uint64_t cache_disabled, uint64_t write_through, uint64_t super_user, uint64_t read_write, uint64_t present) {
    pml4e_t pml4e;


    if(!((xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1139, __FUNCTION__);
    if(!((pdpt_base_address & ~0x7fffffffff000ull) == ((0 && (pdpt_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(pdpt_base_address & ~0x7fffffffff000ull) == ((0 && (pdpt_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1140, __FUNCTION__);
    if(!((accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1141, __FUNCTION__);
    if(!((cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1142, __FUNCTION__);
    if(!((write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1143, __FUNCTION__);
    if(!((super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1144, __FUNCTION__);
    if(!((read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1145, __FUNCTION__);
    if(!((present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1146, __FUNCTION__);

    pml4e.words[0] = 0
        | (xd & 0x1ull) << 63
        | (pdpt_base_address & 0x7fffffffff000ull) >> 0
        | (accessed & 0x1ull) << 5
        | (cache_disabled & 0x1ull) << 4
        | (write_through & 0x1ull) << 3
        | (super_user & 0x1ull) << 2
        | (read_write & 0x1ull) << 1
        | (present & 0x1ull) << 0;

    return pml4e;
}

static inline uint64_t __attribute__((__pure__))
pml4e_ptr_get_pdpt_base_address(pml4e_t *pml4e_ptr) {
    uint64_t ret;
    ret = (pml4e_ptr->words[0] & 0x7fffffffff000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
pml4e_ptr_get_present(pml4e_t *pml4e_ptr) {
    uint64_t ret;
    ret = (pml4e_ptr->words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

struct apic_lvt {
    uint32_t words[1];
};
typedef struct apic_lvt apic_lvt_t;

static inline apic_lvt_t __attribute__((__const__))
apic_lvt_new(uint32_t timer_mode, uint32_t masked, uint32_t trigger_mode, uint32_t remote_irr, uint32_t pin_polarity, uint32_t delivery_status, uint32_t delivery_mode, uint32_t vector) {
    apic_lvt_t apic_lvt;


    if(!((timer_mode & ~0x3u) == ((0 && (timer_mode & (1u << 31))) ? 0x0 : 0))) _assert_fail("(timer_mode & ~0x3u) == ((0 && (timer_mode & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1193, __FUNCTION__);
    if(!((masked & ~0x1u) == ((0 && (masked & (1u << 31))) ? 0x0 : 0))) _assert_fail("(masked & ~0x1u) == ((0 && (masked & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1194, __FUNCTION__);
    if(!((trigger_mode & ~0x1u) == ((0 && (trigger_mode & (1u << 31))) ? 0x0 : 0))) _assert_fail("(trigger_mode & ~0x1u) == ((0 && (trigger_mode & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1195, __FUNCTION__);
    if(!((remote_irr & ~0x1u) == ((0 && (remote_irr & (1u << 31))) ? 0x0 : 0))) _assert_fail("(remote_irr & ~0x1u) == ((0 && (remote_irr & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1196, __FUNCTION__);
    if(!((pin_polarity & ~0x1u) == ((0 && (pin_polarity & (1u << 31))) ? 0x0 : 0))) _assert_fail("(pin_polarity & ~0x1u) == ((0 && (pin_polarity & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1197, __FUNCTION__);
    if(!((delivery_status & ~0x1u) == ((0 && (delivery_status & (1u << 31))) ? 0x0 : 0))) _assert_fail("(delivery_status & ~0x1u) == ((0 && (delivery_status & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1198, __FUNCTION__);
    if(!((delivery_mode & ~0x7u) == ((0 && (delivery_mode & (1u << 31))) ? 0x0 : 0))) _assert_fail("(delivery_mode & ~0x7u) == ((0 && (delivery_mode & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1199, __FUNCTION__);
    if(!((vector & ~0xffu) == ((0 && (vector & (1u << 31))) ? 0x0 : 0))) _assert_fail("(vector & ~0xffu) == ((0 && (vector & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1200, __FUNCTION__);

    apic_lvt.words[0] = 0
        | (timer_mode & 0x3u) << 17
        | (masked & 0x1u) << 16
        | (trigger_mode & 0x1u) << 15
        | (remote_irr & 0x1u) << 14
        | (pin_polarity & 0x1u) << 13
        | (delivery_status & 0x1u) << 12
        | (delivery_mode & 0x7u) << 8
        | (vector & 0xffu) << 0;

    return apic_lvt;
}

struct gdt_tss {
    uint64_t words[2];
};
typedef struct gdt_tss gdt_tss_t;

static inline gdt_tss_t __attribute__((__const__))
gdt_tss_new(uint64_t base_63_32, uint64_t base_31_24, uint64_t granularity, uint64_t avl, uint64_t limit_high, uint64_t present, uint64_t dpl, uint64_t desc_type, uint64_t base_23_16, uint64_t base_15_0, uint64_t limit_low) {
    gdt_tss_t gdt_tss;


    if(!((base_63_32 & ~0xffffffffull) == ((1 && (base_63_32 & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(base_63_32 & ~0xffffffffull) == ((1 && (base_63_32 & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1225, __FUNCTION__);
    if(!((base_31_24 & ~0xffull) == ((1 && (base_31_24 & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(base_31_24 & ~0xffull) == ((1 && (base_31_24 & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1226, __FUNCTION__);
    if(!((granularity & ~0x1ull) == ((1 && (granularity & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(granularity & ~0x1ull) == ((1 && (granularity & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1227, __FUNCTION__);
    if(!((avl & ~0x1ull) == ((1 && (avl & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(avl & ~0x1ull) == ((1 && (avl & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1228, __FUNCTION__);
    if(!((limit_high & ~0xfull) == ((1 && (limit_high & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(limit_high & ~0xfull) == ((1 && (limit_high & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1229, __FUNCTION__);
    if(!((present & ~0x1ull) == ((1 && (present & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(present & ~0x1ull) == ((1 && (present & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1230, __FUNCTION__);
    if(!((dpl & ~0x3ull) == ((1 && (dpl & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(dpl & ~0x3ull) == ((1 && (dpl & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1231, __FUNCTION__);
    if(!((desc_type & ~0xfull) == ((1 && (desc_type & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(desc_type & ~0xfull) == ((1 && (desc_type & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1232, __FUNCTION__);
    if(!((base_23_16 & ~0xffull) == ((1 && (base_23_16 & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(base_23_16 & ~0xffull) == ((1 && (base_23_16 & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1233, __FUNCTION__);
    if(!((base_15_0 & ~0xffffull) == ((1 && (base_15_0 & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(base_15_0 & ~0xffffull) == ((1 && (base_15_0 & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1234, __FUNCTION__);
    if(!((limit_low & ~0xffffull) == ((1 && (limit_low & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(limit_low & ~0xffffull) == ((1 && (limit_low & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1235, __FUNCTION__);

    gdt_tss.words[0] = 0
        | (base_31_24 & 0xffull) << 56
        | (granularity & 0x1ull) << 55
        | (avl & 0x1ull) << 52
        | (limit_high & 0xfull) << 48
        | (present & 0x1ull) << 47
        | (dpl & 0x3ull) << 45
        | (desc_type & 0xfull) << 40
        | (base_23_16 & 0xffull) << 32
        | (base_15_0 & 0xffffull) << 16
        | (limit_low & 0xffffull) << 0;
    gdt_tss.words[1] = 0
        | (base_63_32 & 0xffffffffull) << 0;

    return gdt_tss;
}

struct vm_attributes {
    uint64_t words[1];
};
typedef struct vm_attributes vm_attributes_t;

static inline uint64_t __attribute__((__const__))
vm_attributes_get_x86PATBit(vm_attributes_t vm_attributes) {
    uint64_t ret;
    ret = (vm_attributes.words[0] & 0x4ull) >> 2;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
vm_attributes_get_x86PCDBit(vm_attributes_t vm_attributes) {
    uint64_t ret;
    ret = (vm_attributes.words[0] & 0x2ull) >> 1;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
vm_attributes_get_x86PWTBit(vm_attributes_t vm_attributes) {
    uint64_t ret;
    ret = (vm_attributes.words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

struct vmx_data_exit_qualification_control_regster {
    uint32_t words[1];
};
typedef struct vmx_data_exit_qualification_control_regster vmx_data_exit_qualification_control_regster_t;

static inline uint32_t __attribute__((__const__))
vmx_data_exit_qualification_control_regster_get_data(vmx_data_exit_qualification_control_regster_t vmx_data_exit_qualification_control_regster) {
    uint32_t ret;
    ret = (vmx_data_exit_qualification_control_regster.words[0] & 0xffff0000u) >> 16;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
vmx_data_exit_qualification_control_regster_get_reg(vmx_data_exit_qualification_control_regster_t vmx_data_exit_qualification_control_regster) {
    uint32_t ret;
    ret = (vmx_data_exit_qualification_control_regster.words[0] & 0xf00u) >> 8;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
vmx_data_exit_qualification_control_regster_get_access_type(vmx_data_exit_qualification_control_regster_t vmx_data_exit_qualification_control_regster) {
    uint32_t ret;
    ret = (vmx_data_exit_qualification_control_regster.words[0] & 0x30u) >> 4;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
vmx_data_exit_qualification_control_regster_get_cr(vmx_data_exit_qualification_control_regster_t vmx_data_exit_qualification_control_regster) {
    uint32_t ret;
    ret = (vmx_data_exit_qualification_control_regster.words[0] & 0xfu) >> 0;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

struct endpoint {
    uint64_t words[2];
};
typedef struct endpoint endpoint_t;

static inline uint64_t __attribute__((__pure__))
endpoint_ptr_get_epQueue_head(endpoint_t *endpoint_ptr) {
    uint64_t ret;
    ret = (endpoint_ptr->words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
endpoint_ptr_set_epQueue_head(endpoint_t *endpoint_ptr, uint64_t v64) {

    if(!((((~0xffffffffffffffff >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffffffffffffff >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1360, __FUNCTION__);
    endpoint_ptr->words[1] &= ~0xffffffffffffffffull;
    endpoint_ptr->words[1] |= (v64 << 0) & 0xffffffffffffffff;
}

static inline uint64_t __attribute__((__pure__))
endpoint_ptr_get_epQueue_tail(endpoint_t *endpoint_ptr) {
    uint64_t ret;
    ret = (endpoint_ptr->words[0] & 0xfffffffffffcull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline void
endpoint_ptr_set_epQueue_tail(endpoint_t *endpoint_ptr, uint64_t v64) {

    if(!((((~0xfffffffffffc << 0) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0xfffffffffffc << 0) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 1379, __FUNCTION__);
    endpoint_ptr->words[0] &= ~0xfffffffffffcull;
    endpoint_ptr->words[0] |= (v64 >> 0) & 0xfffffffffffc;
}

static inline uint64_t __attribute__((__pure__))
endpoint_ptr_get_state(endpoint_t *endpoint_ptr) {
    uint64_t ret;
    ret = (endpoint_ptr->words[0] & 0x3ull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
endpoint_ptr_set_state(endpoint_t *endpoint_ptr, uint64_t v64) {

    if(!((((~0x3 >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x3 >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1398, __FUNCTION__);
    endpoint_ptr->words[0] &= ~0x3ull;
    endpoint_ptr->words[0] |= (v64 << 0) & 0x3;
}

struct x2apic_icr1 {
    uint32_t words[1];
};
typedef struct x2apic_icr1 x2apic_icr1_t;

static inline x2apic_icr1_t __attribute__((__const__))
x2apic_icr1_new(uint32_t dest_shorthand, uint32_t trigger_mode, uint32_t level, uint32_t dest_mode, uint32_t delivery_mode, uint32_t vector) {
    x2apic_icr1_t x2apic_icr1;


    if(!((dest_shorthand & ~0x3u) == ((0 && (dest_shorthand & (1u << 31))) ? 0x0 : 0))) _assert_fail("(dest_shorthand & ~0x3u) == ((0 && (dest_shorthand & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1413, __FUNCTION__);
    if(!((trigger_mode & ~0x1u) == ((0 && (trigger_mode & (1u << 31))) ? 0x0 : 0))) _assert_fail("(trigger_mode & ~0x1u) == ((0 && (trigger_mode & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1414, __FUNCTION__);
    if(!((level & ~0x1u) == ((0 && (level & (1u << 31))) ? 0x0 : 0))) _assert_fail("(level & ~0x1u) == ((0 && (level & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1415, __FUNCTION__);
    if(!((dest_mode & ~0x1u) == ((0 && (dest_mode & (1u << 31))) ? 0x0 : 0))) _assert_fail("(dest_mode & ~0x1u) == ((0 && (dest_mode & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1416, __FUNCTION__);
    if(!((delivery_mode & ~0x7u) == ((0 && (delivery_mode & (1u << 31))) ? 0x0 : 0))) _assert_fail("(delivery_mode & ~0x7u) == ((0 && (delivery_mode & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1417, __FUNCTION__);
    if(!((vector & ~0xffu) == ((0 && (vector & (1u << 31))) ? 0x0 : 0))) _assert_fail("(vector & ~0xffu) == ((0 && (vector & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1418, __FUNCTION__);

    x2apic_icr1.words[0] = 0
        | (dest_shorthand & 0x3u) << 18
        | (trigger_mode & 0x1u) << 15
        | (level & 0x1u) << 14
        | (dest_mode & 0x1u) << 11
        | (delivery_mode & 0x7u) << 8
        | (vector & 0xffu) << 0;

    return x2apic_icr1;
}

struct apic_svr {
    uint32_t words[1];
};
typedef struct apic_svr apic_svr_t;

static inline apic_svr_t __attribute__((__const__))
apic_svr_new(uint32_t focus_processor_chk, uint32_t enabled, uint32_t spurious_vector) {
    apic_svr_t apic_svr;


    if(!((focus_processor_chk & ~0x1u) == ((0 && (focus_processor_chk & (1u << 31))) ? 0x0 : 0))) _assert_fail("(focus_processor_chk & ~0x1u) == ((0 && (focus_processor_chk & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1441, __FUNCTION__);
    if(!((enabled & ~0x1u) == ((0 && (enabled & (1u << 31))) ? 0x0 : 0))) _assert_fail("(enabled & ~0x1u) == ((0 && (enabled & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1442, __FUNCTION__);
    if(!((spurious_vector & ~0xffu) == ((0 && (spurious_vector & (1u << 31))) ? 0x0 : 0))) _assert_fail("(spurious_vector & ~0xffu) == ((0 && (spurious_vector & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1443, __FUNCTION__);

    apic_svr.words[0] = 0
        | (focus_processor_chk & 0x1u) << 9
        | (enabled & 0x1u) << 8
        | (spurious_vector & 0xffu) << 0;

    return apic_svr;
}

struct vmx_basic_msr {
    uint32_t words[2];
};
typedef struct vmx_basic_msr vmx_basic_msr_t;

static inline uint32_t __attribute__((__const__))
vmx_basic_msr_get_true_msrs(vmx_basic_msr_t vmx_basic_msr) {
    uint32_t ret;
    ret = (vmx_basic_msr.words[1] & 0x800000u) >> 23;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
vmx_basic_msr_get_vmcs_revision(vmx_basic_msr_t vmx_basic_msr) {
    uint32_t ret;
    ret = (vmx_basic_msr.words[0] & 0x7fffffffu) >> 0;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

struct vmx_ept_vpid_cap_msr {
    uint32_t words[2];
};
typedef struct vmx_ept_vpid_cap_msr vmx_ept_vpid_cap_msr_t;

static inline uint32_t __attribute__((__const__))
vmx_ept_vpid_cap_msr_get_invept_all_context(vmx_ept_vpid_cap_msr_t vmx_ept_vpid_cap_msr) {
    uint32_t ret;
    ret = (vmx_ept_vpid_cap_msr.words[0] & 0x4000000u) >> 26;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
vmx_ept_vpid_cap_msr_get_invept_single_context(vmx_ept_vpid_cap_msr_t vmx_ept_vpid_cap_msr) {
    uint32_t ret;
    ret = (vmx_ept_vpid_cap_msr.words[0] & 0x2000000u) >> 25;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
vmx_ept_vpid_cap_msr_get_invept(vmx_ept_vpid_cap_msr_t vmx_ept_vpid_cap_msr) {
    uint32_t ret;
    ret = (vmx_ept_vpid_cap_msr.words[0] & 0x100000u) >> 20;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
vmx_ept_vpid_cap_msr_get_ept_2m(vmx_ept_vpid_cap_msr_t vmx_ept_vpid_cap_msr) {
    uint32_t ret;
    ret = (vmx_ept_vpid_cap_msr.words[0] & 0x10000u) >> 16;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
vmx_ept_vpid_cap_msr_get_ept_wb(vmx_ept_vpid_cap_msr_t vmx_ept_vpid_cap_msr) {
    uint32_t ret;
    ret = (vmx_ept_vpid_cap_msr.words[0] & 0x4000u) >> 14;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

struct feature_control_msr {
    uint32_t words[1];
};
typedef struct feature_control_msr feature_control_msr_t;

static inline uint32_t __attribute__((__const__))
feature_control_msr_get_vmx_outside_smx(feature_control_msr_t feature_control_msr) {
    uint32_t ret;
    ret = (feature_control_msr.words[0] & 0x4u) >> 2;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline feature_control_msr_t __attribute__((__const__))
feature_control_msr_set_vmx_outside_smx(feature_control_msr_t feature_control_msr, uint32_t v32) {

    if(!((((~0x4 >> 2 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0))) _assert_fail("(((~0x4 >> 2 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1559, __FUNCTION__);
    feature_control_msr.words[0] &= ~0x4u;
    feature_control_msr.words[0] |= (v32 << 2) & 0x4u;
    return feature_control_msr;
}

static inline uint32_t __attribute__((__const__))
feature_control_msr_get_lock(feature_control_msr_t feature_control_msr) {
    uint32_t ret;
    ret = (feature_control_msr.words[0] & 0x1u) >> 0;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline feature_control_msr_t __attribute__((__const__))
feature_control_msr_set_lock(feature_control_msr_t feature_control_msr, uint32_t v32) {

    if(!((((~0x1 >> 0 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0))) _assert_fail("(((~0x1 >> 0 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1579, __FUNCTION__);
    feature_control_msr.words[0] &= ~0x1u;
    feature_control_msr.words[0] |= (v32 << 0) & 0x1u;
    return feature_control_msr;
}

struct gdt_entry {
    uint64_t words[1];
};
typedef struct gdt_entry gdt_entry_t;

enum gdt_entry_tag {
    gdt_entry_gdt_null = 0,
    gdt_entry_gdt_data = 7,
    gdt_entry_gdt_code = 11
};
typedef enum gdt_entry_tag gdt_entry_tag_t;

static inline gdt_entry_t __attribute__((__const__))
gdt_entry_gdt_null_new(void) {
    gdt_entry_t gdt_entry;


    if(!(((uint64_t)gdt_entry_gdt_null & ~0xfull) == ((1 && ((uint64_t)gdt_entry_gdt_null & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)gdt_entry_gdt_null & ~0xfull) == ((1 && ((uint64_t)gdt_entry_gdt_null & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1602, __FUNCTION__);

    gdt_entry.words[0] = 0
        | ((uint64_t)gdt_entry_gdt_null & 0xfull) << 40;

    return gdt_entry;
}

static inline gdt_entry_t __attribute__((__const__))
gdt_entry_gdt_data_new(uint64_t base_high, uint64_t granularity, uint64_t operation_size, uint64_t avl, uint64_t seg_limit_high, uint64_t present, uint64_t dpl, uint64_t always_1, uint64_t base_mid, uint64_t base_low, uint64_t seg_limit_low) {
    gdt_entry_t gdt_entry;


    if(!((base_high & ~0xffull) == ((1 && (base_high & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(base_high & ~0xffull) == ((1 && (base_high & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1615, __FUNCTION__);
    if(!((granularity & ~0x1ull) == ((1 && (granularity & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(granularity & ~0x1ull) == ((1 && (granularity & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1616, __FUNCTION__);
    if(!((operation_size & ~0x1ull) == ((1 && (operation_size & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(operation_size & ~0x1ull) == ((1 && (operation_size & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1617, __FUNCTION__);
    if(!((avl & ~0x1ull) == ((1 && (avl & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(avl & ~0x1ull) == ((1 && (avl & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1618, __FUNCTION__);
    if(!((seg_limit_high & ~0xfull) == ((1 && (seg_limit_high & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(seg_limit_high & ~0xfull) == ((1 && (seg_limit_high & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1619, __FUNCTION__);
    if(!((present & ~0x1ull) == ((1 && (present & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(present & ~0x1ull) == ((1 && (present & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1620, __FUNCTION__);
    if(!((dpl & ~0x3ull) == ((1 && (dpl & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(dpl & ~0x3ull) == ((1 && (dpl & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1621, __FUNCTION__);
    if(!((always_1 & ~0x1ull) == ((1 && (always_1 & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(always_1 & ~0x1ull) == ((1 && (always_1 & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1622, __FUNCTION__);
    if(!(((uint64_t)gdt_entry_gdt_data & ~0xfull) == ((1 && ((uint64_t)gdt_entry_gdt_data & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)gdt_entry_gdt_data & ~0xfull) == ((1 && ((uint64_t)gdt_entry_gdt_data & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1623, __FUNCTION__);
    if(!((base_mid & ~0xffull) == ((1 && (base_mid & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(base_mid & ~0xffull) == ((1 && (base_mid & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1624, __FUNCTION__);
    if(!((base_low & ~0xffffull) == ((1 && (base_low & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(base_low & ~0xffffull) == ((1 && (base_low & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1625, __FUNCTION__);
    if(!((seg_limit_low & ~0xffffull) == ((1 && (seg_limit_low & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(seg_limit_low & ~0xffffull) == ((1 && (seg_limit_low & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1626, __FUNCTION__);

    gdt_entry.words[0] = 0
        | (base_high & 0xffull) << 56
        | (granularity & 0x1ull) << 55
        | (operation_size & 0x1ull) << 54
        | (avl & 0x1ull) << 52
        | (seg_limit_high & 0xfull) << 48
        | (present & 0x1ull) << 47
        | (dpl & 0x3ull) << 45
        | (always_1 & 0x1ull) << 44
        | ((uint64_t)gdt_entry_gdt_data & 0xfull) << 40
        | (base_mid & 0xffull) << 32
        | (base_low & 0xffffull) << 16
        | (seg_limit_low & 0xffffull) << 0;

    return gdt_entry;
}

static inline void
gdt_entry_gdt_data_ptr_set_base_high(gdt_entry_t *gdt_entry_ptr,
                                      uint64_t v64) {
    if(!(((gdt_entry_ptr->words[0] >> 40) & 0xf) == gdt_entry_gdt_data)) _assert_fail("((gdt_entry_ptr->words[0] >> 40) & 0xf) == gdt_entry_gdt_data",
                             "./arch/object/structures_gen.h"
    ,
                             1649
    , __FUNCTION__)
                              ;


    if(!((((~0xff00000000000000ull >> 56) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xff00000000000000ull >> 56) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1652, __FUNCTION__);

    gdt_entry_ptr->words[0] &= ~0xff00000000000000ull;
    gdt_entry_ptr->words[0] |= (v64 << 56) & 0xff00000000000000ull;
}

static inline void
gdt_entry_gdt_data_ptr_set_base_mid(gdt_entry_t *gdt_entry_ptr,
                                      uint64_t v64) {
    if(!(((gdt_entry_ptr->words[0] >> 40) & 0xf) == gdt_entry_gdt_data)) _assert_fail("((gdt_entry_ptr->words[0] >> 40) & 0xf) == gdt_entry_gdt_data",
                             "./arch/object/structures_gen.h"
    ,
                             1662
    , __FUNCTION__)
                              ;


    if(!((((~0xff00000000ull >> 32) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xff00000000ull >> 32) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1665, __FUNCTION__);

    gdt_entry_ptr->words[0] &= ~0xff00000000ull;
    gdt_entry_ptr->words[0] |= (v64 << 32) & 0xff00000000ull;
}

static inline void
gdt_entry_gdt_data_ptr_set_base_low(gdt_entry_t *gdt_entry_ptr,
                                      uint64_t v64) {
    if(!(((gdt_entry_ptr->words[0] >> 40) & 0xf) == gdt_entry_gdt_data)) _assert_fail("((gdt_entry_ptr->words[0] >> 40) & 0xf) == gdt_entry_gdt_data",
                             "./arch/object/structures_gen.h"
    ,
                             1675
    , __FUNCTION__)
                              ;


    if(!((((~0xffff0000ull >> 16) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffff0000ull >> 16) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1678, __FUNCTION__);

    gdt_entry_ptr->words[0] &= ~0xffff0000ull;
    gdt_entry_ptr->words[0] |= (v64 << 16) & 0xffff0000ull;
}

static inline gdt_entry_t __attribute__((__const__))
gdt_entry_gdt_code_new(uint64_t base_high, uint64_t granularity, uint64_t operation_size, uint64_t long_mode, uint64_t avl, uint64_t seg_limit_high, uint64_t present, uint64_t dpl, uint64_t always_1, uint64_t base_mid, uint64_t base_low, uint64_t seg_limit_low) {
    gdt_entry_t gdt_entry;


    if(!((base_high & ~0xffull) == ((1 && (base_high & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(base_high & ~0xffull) == ((1 && (base_high & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1689, __FUNCTION__);
    if(!((granularity & ~0x1ull) == ((1 && (granularity & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(granularity & ~0x1ull) == ((1 && (granularity & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1690, __FUNCTION__);
    if(!((operation_size & ~0x1ull) == ((1 && (operation_size & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(operation_size & ~0x1ull) == ((1 && (operation_size & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1691, __FUNCTION__);
    if(!((long_mode & ~0x1ull) == ((1 && (long_mode & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(long_mode & ~0x1ull) == ((1 && (long_mode & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1692, __FUNCTION__);
    if(!((avl & ~0x1ull) == ((1 && (avl & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(avl & ~0x1ull) == ((1 && (avl & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1693, __FUNCTION__);
    if(!((seg_limit_high & ~0xfull) == ((1 && (seg_limit_high & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(seg_limit_high & ~0xfull) == ((1 && (seg_limit_high & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1694, __FUNCTION__);
    if(!((present & ~0x1ull) == ((1 && (present & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(present & ~0x1ull) == ((1 && (present & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1695, __FUNCTION__);
    if(!((dpl & ~0x3ull) == ((1 && (dpl & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(dpl & ~0x3ull) == ((1 && (dpl & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1696, __FUNCTION__);
    if(!((always_1 & ~0x1ull) == ((1 && (always_1 & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(always_1 & ~0x1ull) == ((1 && (always_1 & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1697, __FUNCTION__);
    if(!(((uint64_t)gdt_entry_gdt_code & ~0xfull) == ((1 && ((uint64_t)gdt_entry_gdt_code & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)gdt_entry_gdt_code & ~0xfull) == ((1 && ((uint64_t)gdt_entry_gdt_code & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1698, __FUNCTION__);
    if(!((base_mid & ~0xffull) == ((1 && (base_mid & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(base_mid & ~0xffull) == ((1 && (base_mid & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1699, __FUNCTION__);
    if(!((base_low & ~0xffffull) == ((1 && (base_low & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(base_low & ~0xffffull) == ((1 && (base_low & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1700, __FUNCTION__);
    if(!((seg_limit_low & ~0xffffull) == ((1 && (seg_limit_low & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(seg_limit_low & ~0xffffull) == ((1 && (seg_limit_low & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1701, __FUNCTION__);

    gdt_entry.words[0] = 0
        | (base_high & 0xffull) << 56
        | (granularity & 0x1ull) << 55
        | (operation_size & 0x1ull) << 54
        | (long_mode & 0x1ull) << 53
        | (avl & 0x1ull) << 52
        | (seg_limit_high & 0xfull) << 48
        | (present & 0x1ull) << 47
        | (dpl & 0x3ull) << 45
        | (always_1 & 0x1ull) << 44
        | ((uint64_t)gdt_entry_gdt_code & 0xfull) << 40
        | (base_mid & 0xffull) << 32
        | (base_low & 0xffffull) << 16
        | (seg_limit_low & 0xffffull) << 0;

    return gdt_entry;
}

struct lookup_fault {
    uint64_t words[2];
};
typedef struct lookup_fault lookup_fault_t;

enum lookup_fault_tag {
    lookup_fault_invalid_root = 0,
    lookup_fault_missing_capability = 1,
    lookup_fault_depth_mismatch = 2,
    lookup_fault_guard_mismatch = 3
};
typedef enum lookup_fault_tag lookup_fault_tag_t;

static inline uint64_t __attribute__((__const__))
lookup_fault_get_lufType(lookup_fault_t lookup_fault) {
    return (lookup_fault.words[0] >> 0) & 0x3ull;
}

static inline lookup_fault_t __attribute__((__const__))
lookup_fault_invalid_root_new(void) {
    lookup_fault_t lookup_fault;


    if(!(((uint64_t)lookup_fault_invalid_root & ~0x3ull) == ((1 && ((uint64_t)lookup_fault_invalid_root & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)lookup_fault_invalid_root & ~0x3ull) == ((1 && ((uint64_t)lookup_fault_invalid_root & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1744, __FUNCTION__);

    lookup_fault.words[0] = 0
        | ((uint64_t)lookup_fault_invalid_root & 0x3ull) << 0;
    lookup_fault.words[1] = 0;

    return lookup_fault;
}

static inline lookup_fault_t __attribute__((__const__))
lookup_fault_missing_capability_new(uint64_t bitsLeft) {
    lookup_fault_t lookup_fault;


    if(!((bitsLeft & ~0x7full) == ((1 && (bitsLeft & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(bitsLeft & ~0x7full) == ((1 && (bitsLeft & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1758, __FUNCTION__);
    if(!(((uint64_t)lookup_fault_missing_capability & ~0x3ull) == ((1 && ((uint64_t)lookup_fault_missing_capability & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)lookup_fault_missing_capability & ~0x3ull) == ((1 && ((uint64_t)lookup_fault_missing_capability & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1759, __FUNCTION__);

    lookup_fault.words[0] = 0
        | (bitsLeft & 0x7full) << 2
        | ((uint64_t)lookup_fault_missing_capability & 0x3ull) << 0;
    lookup_fault.words[1] = 0;

    return lookup_fault;
}

static inline uint64_t __attribute__((__const__))
lookup_fault_missing_capability_get_bitsLeft(lookup_fault_t lookup_fault) {
    uint64_t ret;
    if(!(((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_missing_capability)) _assert_fail("((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_missing_capability",
                                          "./arch/object/structures_gen.h"
    ,
                                          1773
    , __FUNCTION__)
                                           ;

    ret = (lookup_fault.words[0] & 0x1fcull) >> 2;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline lookup_fault_t __attribute__((__const__))
lookup_fault_depth_mismatch_new(uint64_t bitsFound, uint64_t bitsLeft) {
    lookup_fault_t lookup_fault;


    if(!((bitsFound & ~0x7full) == ((1 && (bitsFound & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(bitsFound & ~0x7full) == ((1 && (bitsFound & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1788, __FUNCTION__);
    if(!((bitsLeft & ~0x7full) == ((1 && (bitsLeft & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(bitsLeft & ~0x7full) == ((1 && (bitsLeft & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1789, __FUNCTION__);
    if(!(((uint64_t)lookup_fault_depth_mismatch & ~0x3ull) == ((1 && ((uint64_t)lookup_fault_depth_mismatch & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)lookup_fault_depth_mismatch & ~0x3ull) == ((1 && ((uint64_t)lookup_fault_depth_mismatch & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1790, __FUNCTION__);

    lookup_fault.words[0] = 0
        | (bitsFound & 0x7full) << 9
        | (bitsLeft & 0x7full) << 2
        | ((uint64_t)lookup_fault_depth_mismatch & 0x3ull) << 0;
    lookup_fault.words[1] = 0;

    return lookup_fault;
}

static inline uint64_t __attribute__((__const__))
lookup_fault_depth_mismatch_get_bitsFound(lookup_fault_t lookup_fault) {
    uint64_t ret;
    if(!(((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_depth_mismatch)) _assert_fail("((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_depth_mismatch",
                                      "./arch/object/structures_gen.h"
    ,
                                      1805
    , __FUNCTION__)
                                       ;

    ret = (lookup_fault.words[0] & 0xfe00ull) >> 9;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
lookup_fault_depth_mismatch_get_bitsLeft(lookup_fault_t lookup_fault) {
    uint64_t ret;
    if(!(((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_depth_mismatch)) _assert_fail("((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_depth_mismatch",
                                      "./arch/object/structures_gen.h"
    ,
                                      1819
    , __FUNCTION__)
                                       ;

    ret = (lookup_fault.words[0] & 0x1fcull) >> 2;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline lookup_fault_t __attribute__((__const__))
lookup_fault_guard_mismatch_new(uint64_t guardFound, uint64_t bitsLeft, uint64_t bitsFound) {
    lookup_fault_t lookup_fault;


    if(!((bitsLeft & ~0x7full) == ((1 && (bitsLeft & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(bitsLeft & ~0x7full) == ((1 && (bitsLeft & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1834, __FUNCTION__);
    if(!((bitsFound & ~0x7full) == ((1 && (bitsFound & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(bitsFound & ~0x7full) == ((1 && (bitsFound & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1835, __FUNCTION__);
    if(!(((uint64_t)lookup_fault_guard_mismatch & ~0x3ull) == ((1 && ((uint64_t)lookup_fault_guard_mismatch & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)lookup_fault_guard_mismatch & ~0x3ull) == ((1 && ((uint64_t)lookup_fault_guard_mismatch & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1836, __FUNCTION__);

    lookup_fault.words[0] = 0
        | (bitsLeft & 0x7full) << 9
        | (bitsFound & 0x7full) << 2
        | ((uint64_t)lookup_fault_guard_mismatch & 0x3ull) << 0;
    lookup_fault.words[1] = 0
        | guardFound << 0;

    return lookup_fault;
}

static inline uint64_t __attribute__((__const__))
lookup_fault_guard_mismatch_get_guardFound(lookup_fault_t lookup_fault) {
    uint64_t ret;
    if(!(((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_guard_mismatch)) _assert_fail("((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_guard_mismatch",
                                      "./arch/object/structures_gen.h"
    ,
                                      1852
    , __FUNCTION__)
                                       ;

    ret = (lookup_fault.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
lookup_fault_guard_mismatch_get_bitsLeft(lookup_fault_t lookup_fault) {
    uint64_t ret;
    if(!(((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_guard_mismatch)) _assert_fail("((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_guard_mismatch",
                                      "./arch/object/structures_gen.h"
    ,
                                      1866
    , __FUNCTION__)
                                       ;

    ret = (lookup_fault.words[0] & 0xfe00ull) >> 9;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
lookup_fault_guard_mismatch_get_bitsFound(lookup_fault_t lookup_fault) {
    uint64_t ret;
    if(!(((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_guard_mismatch)) _assert_fail("((lookup_fault.words[0] >> 0) & 0x3) == lookup_fault_guard_mismatch",
                                      "./arch/object/structures_gen.h"
    ,
                                      1880
    , __FUNCTION__)
                                       ;

    ret = (lookup_fault.words[0] & 0x1fcull) >> 2;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

struct asid_map {
    uint64_t words[1];
};
typedef struct asid_map asid_map_t;

enum asid_map_tag {
    asid_map_asid_map_none = 0,
    asid_map_asid_map_vspace = 1,
    asid_map_asid_map_ept = 2
};
typedef enum asid_map_tag asid_map_tag_t;

static inline uint64_t __attribute__((__const__))
asid_map_get_type(asid_map_t asid_map) {
    return (asid_map.words[0] >> 0) & 0x3ull;
}

static inline asid_map_t __attribute__((__const__))
asid_map_asid_map_none_new(void) {
    asid_map_t asid_map;


    if(!(((uint64_t)asid_map_asid_map_none & ~0x3ull) == ((1 && ((uint64_t)asid_map_asid_map_none & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)asid_map_asid_map_none & ~0x3ull) == ((1 && ((uint64_t)asid_map_asid_map_none & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1912, __FUNCTION__);

    asid_map.words[0] = 0
        | ((uint64_t)asid_map_asid_map_none & 0x3ull) << 0;

    return asid_map;
}

static inline asid_map_t __attribute__((__const__))
asid_map_asid_map_vspace_new(uint64_t vspace_root) {
    asid_map_t asid_map;


    if(!((vspace_root & ~0xffffffffffffull) == ((1 && (vspace_root & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(vspace_root & ~0xffffffffffffull) == ((1 && (vspace_root & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 1925, __FUNCTION__);
    if(!(((uint64_t)asid_map_asid_map_vspace & ~0x3ull) == ((1 && ((uint64_t)asid_map_asid_map_vspace & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)asid_map_asid_map_vspace & ~0x3ull) == ((1 && ((uint64_t)asid_map_asid_map_vspace & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1926, __FUNCTION__);

    asid_map.words[0] = 0
        | (vspace_root & 0xffffffffffffull) << 16
        | ((uint64_t)asid_map_asid_map_vspace & 0x3ull) << 0;

    return asid_map;
}

static inline uint64_t __attribute__((__const__))
asid_map_asid_map_vspace_get_vspace_root(asid_map_t asid_map) {
    uint64_t ret;
    if(!(((asid_map.words[0] >> 0) & 0x3) == asid_map_asid_map_vspace)) _assert_fail("((asid_map.words[0] >> 0) & 0x3) == asid_map_asid_map_vspace",
                                   "./arch/object/structures_gen.h"
    ,
                                   1939
    , __FUNCTION__)
                                    ;

    ret = (asid_map.words[0] & 0xffffffffffff0000ull) >> 16;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline asid_map_t __attribute__((__const__))
asid_map_asid_map_ept_new(uint64_t ept_root) {
    asid_map_t asid_map;


    if(!((ept_root & ~0xffffffffffffull) == ((1 && (ept_root & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(ept_root & ~0xffffffffffffull) == ((1 && (ept_root & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 1954, __FUNCTION__);
    if(!(((uint64_t)asid_map_asid_map_ept & ~0x3ull) == ((1 && ((uint64_t)asid_map_asid_map_ept & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)asid_map_asid_map_ept & ~0x3ull) == ((1 && ((uint64_t)asid_map_asid_map_ept & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1955, __FUNCTION__);

    asid_map.words[0] = 0
        | (ept_root & 0xffffffffffffull) << 16
        | ((uint64_t)asid_map_asid_map_ept & 0x3ull) << 0;

    return asid_map;
}

static inline uint64_t __attribute__((__const__))
asid_map_asid_map_ept_get_ept_root(asid_map_t asid_map) {
    uint64_t ret;
    if(!(((asid_map.words[0] >> 0) & 0x3) == asid_map_asid_map_ept)) _assert_fail("((asid_map.words[0] >> 0) & 0x3) == asid_map_asid_map_ept",
                                "./arch/object/structures_gen.h"
    ,
                                1968
    , __FUNCTION__)
                                 ;

    ret = (asid_map.words[0] & 0xffffffffffff0000ull) >> 16;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

struct idt_entry {
    uint64_t words[2];
};
typedef struct idt_entry idt_entry_t;

enum idt_entry_tag {
    idt_entry_interrupt_gate = 14,
    idt_entry_trap_gate = 15
};
typedef enum idt_entry_tag idt_entry_tag_t;

static inline idt_entry_t __attribute__((__const__))
idt_entry_interrupt_gate_new(uint64_t offset_63_32, uint64_t offset_31_16, uint64_t present, uint64_t dpl, uint64_t ist, uint64_t seg_selector, uint64_t offset_15_0) {
    idt_entry_t idt_entry;


    if(!((offset_63_32 & ~0xffffffffull) == ((1 && (offset_63_32 & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(offset_63_32 & ~0xffffffffull) == ((1 && (offset_63_32 & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1994, __FUNCTION__);
    if(!((offset_31_16 & ~0xffffull) == ((1 && (offset_31_16 & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(offset_31_16 & ~0xffffull) == ((1 && (offset_31_16 & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1995, __FUNCTION__);
    if(!((present & ~0x1ull) == ((1 && (present & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(present & ~0x1ull) == ((1 && (present & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1996, __FUNCTION__);
    if(!((dpl & ~0x3ull) == ((1 && (dpl & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(dpl & ~0x3ull) == ((1 && (dpl & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1997, __FUNCTION__);
    if(!(((uint64_t)idt_entry_interrupt_gate & ~0xfull) == ((1 && ((uint64_t)idt_entry_interrupt_gate & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)idt_entry_interrupt_gate & ~0xfull) == ((1 && ((uint64_t)idt_entry_interrupt_gate & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1998, __FUNCTION__);
    if(!((ist & ~0x7ull) == ((1 && (ist & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(ist & ~0x7ull) == ((1 && (ist & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 1999, __FUNCTION__);
    if(!((seg_selector & ~0xffffull) == ((1 && (seg_selector & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(seg_selector & ~0xffffull) == ((1 && (seg_selector & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2000, __FUNCTION__);
    if(!((offset_15_0 & ~0xffffull) == ((1 && (offset_15_0 & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(offset_15_0 & ~0xffffull) == ((1 && (offset_15_0 & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2001, __FUNCTION__);

    idt_entry.words[0] = 0
        | (offset_31_16 & 0xffffull) << 48
        | (present & 0x1ull) << 47
        | (dpl & 0x3ull) << 45
        | ((uint64_t)idt_entry_interrupt_gate & 0xfull) << 40
        | (ist & 0x7ull) << 32
        | (seg_selector & 0xffffull) << 16
        | (offset_15_0 & 0xffffull) << 0;
    idt_entry.words[1] = 0
        | (offset_63_32 & 0xffffffffull) << 0;

    return idt_entry;
}

struct cap {
    uint64_t words[2];
};
typedef struct cap cap_t;

enum cap_tag {
    cap_null_cap = 0,
    cap_untyped_cap = 2,
    cap_endpoint_cap = 4,
    cap_notification_cap = 6,
    cap_reply_cap = 8,
    cap_cnode_cap = 10,
    cap_thread_cap = 12,
    cap_irq_control_cap = 14,
    cap_irq_handler_cap = 16,
    cap_zombie_cap = 18,
    cap_domain_cap = 20,
    cap_frame_cap = 1,
    cap_page_table_cap = 3,
    cap_page_directory_cap = 5,
    cap_pdpt_cap = 7,
    cap_pml4_cap = 9,
    cap_asid_control_cap = 11,
    cap_asid_pool_cap = 13,
    cap_io_port_cap = 19,
    cap_vcpu_cap = 21,
    cap_ept_pt_cap = 23,
    cap_ept_pd_cap = 25,
    cap_ept_pdpt_cap = 27,
    cap_ept_pml4_cap = 29
};
typedef enum cap_tag cap_tag_t;

static inline uint64_t __attribute__((__const__))
cap_get_capType(cap_t cap) {
    return (cap.words[0] >> 59) & 0x1full;
}

static inline int __attribute__((__const__))
cap_capType_equals(cap_t cap, uint64_t cap_type_tag) {
    return ((cap.words[0] >> 59) & 0x1full) == cap_type_tag;
}

static inline cap_t __attribute__((__const__))
cap_null_cap_new(void) {
    cap_t cap;


    if(!(((uint64_t)cap_null_cap & ~0x1full) == ((1 && ((uint64_t)cap_null_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_null_cap & ~0x1full) == ((1 && ((uint64_t)cap_null_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2065, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_null_cap & 0x1full) << 59;
    cap.words[1] = 0;

    return cap;
}

static inline cap_t __attribute__((__const__))
cap_untyped_cap_new(uint64_t capFreeIndex, uint64_t capIsDevice, uint64_t capBlockSize, uint64_t capPtr) {
    cap_t cap;


    if(!((capFreeIndex & ~0xffffffffffffull) == ((1 && (capFreeIndex & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capFreeIndex & ~0xffffffffffffull) == ((1 && (capFreeIndex & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2079, __FUNCTION__);
    if(!((capIsDevice & ~0x1ull) == ((1 && (capIsDevice & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capIsDevice & ~0x1ull) == ((1 && (capIsDevice & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2080, __FUNCTION__);
    if(!((capBlockSize & ~0x3full) == ((1 && (capBlockSize & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capBlockSize & ~0x3full) == ((1 && (capBlockSize & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2081, __FUNCTION__);
    if(!(((uint64_t)cap_untyped_cap & ~0x1full) == ((1 && ((uint64_t)cap_untyped_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_untyped_cap & ~0x1full) == ((1 && ((uint64_t)cap_untyped_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2082, __FUNCTION__);
    if(!((capPtr & ~0xffffffffffffull) == ((1 && (capPtr & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capPtr & ~0xffffffffffffull) == ((1 && (capPtr & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 2083, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_untyped_cap & 0x1full) << 59
        | (capPtr & 0xffffffffffffull) >> 0;
    cap.words[1] = 0
        | (capFreeIndex & 0xffffffffffffull) << 16
        | (capIsDevice & 0x1ull) << 6
        | (capBlockSize & 0x3full) << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_untyped_cap_get_capFreeIndex(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_untyped_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_untyped_cap",
                          "./arch/object/structures_gen.h"
    ,
                          2100
    , __FUNCTION__)
                           ;

    ret = (cap.words[1] & 0xffffffffffff0000ull) >> 16;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_untyped_cap_set_capFreeIndex(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_untyped_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_untyped_cap",
                          "./arch/object/structures_gen.h"
    ,
                          2113
    , __FUNCTION__)
                           ;

    if(!((((~0xffffffffffff0000ull >> 16 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffffffffff0000ull >> 16 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2115, __FUNCTION__);

    cap.words[1] &= ~0xffffffffffff0000ull;
    cap.words[1] |= (v64 << 16) & 0xffffffffffff0000ull;
    return cap;
}

static inline void
cap_untyped_cap_ptr_set_capFreeIndex(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_untyped_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_untyped_cap",
                          "./arch/object/structures_gen.h"
    ,
                          2126
    , __FUNCTION__)
                           ;


    if(!((((~0xffffffffffff0000ull >> 16) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffffffffff0000ull >> 16) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2129, __FUNCTION__);

    cap_ptr->words[1] &= ~0xffffffffffff0000ull;
    cap_ptr->words[1] |= (v64 << 16) & 0xffffffffffff0000ull;
}

static inline uint64_t __attribute__((__const__))
cap_untyped_cap_get_capIsDevice(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_untyped_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_untyped_cap",
                          "./arch/object/structures_gen.h"
    ,
                          2139
    , __FUNCTION__)
                           ;

    ret = (cap.words[1] & 0x40ull) >> 6;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_untyped_cap_get_capBlockSize(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_untyped_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_untyped_cap",
                          "./arch/object/structures_gen.h"
    ,
                          2153
    , __FUNCTION__)
                           ;

    ret = (cap.words[1] & 0x3full) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_untyped_cap_get_capPtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_untyped_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_untyped_cap",
                          "./arch/object/structures_gen.h"
    ,
                          2167
    , __FUNCTION__)
                           ;

    ret = (cap.words[0] & 0xffffffffffffull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_endpoint_cap_new(uint64_t capEPBadge, uint64_t capCanGrant, uint64_t capCanSend, uint64_t capCanReceive, uint64_t capEPPtr) {
    cap_t cap;


    if(!(((uint64_t)cap_endpoint_cap & ~0x1full) == ((1 && ((uint64_t)cap_endpoint_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_endpoint_cap & ~0x1full) == ((1 && ((uint64_t)cap_endpoint_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2182, __FUNCTION__);
    if(!((capCanGrant & ~0x1ull) == ((1 && (capCanGrant & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capCanGrant & ~0x1ull) == ((1 && (capCanGrant & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2183, __FUNCTION__);
    if(!((capCanSend & ~0x1ull) == ((1 && (capCanSend & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capCanSend & ~0x1ull) == ((1 && (capCanSend & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2184, __FUNCTION__);
    if(!((capCanReceive & ~0x1ull) == ((1 && (capCanReceive & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capCanReceive & ~0x1ull) == ((1 && (capCanReceive & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2185, __FUNCTION__);
    if(!((capEPPtr & ~0xffffffffffffull) == ((1 && (capEPPtr & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capEPPtr & ~0xffffffffffffull) == ((1 && (capEPPtr & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 2186, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_endpoint_cap & 0x1full) << 59
        | (capCanGrant & 0x1ull) << 58
        | (capCanSend & 0x1ull) << 56
        | (capCanReceive & 0x1ull) << 57
        | (capEPPtr & 0xffffffffffffull) >> 0;
    cap.words[1] = 0
        | capEPBadge << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_endpoint_cap_get_capEPBadge(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap",
                           "./arch/object/structures_gen.h"
    ,
                           2204
    , __FUNCTION__)
                            ;

    ret = (cap.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_endpoint_cap_set_capEPBadge(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap",
                           "./arch/object/structures_gen.h"
    ,
                           2217
    , __FUNCTION__)
                            ;

    if(!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2219, __FUNCTION__);

    cap.words[1] &= ~0xffffffffffffffffull;
    cap.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_endpoint_cap_get_capCanGrant(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap",
                           "./arch/object/structures_gen.h"
    ,
                           2230
    , __FUNCTION__)
                            ;

    ret = (cap.words[0] & 0x400000000000000ull) >> 58;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_endpoint_cap_set_capCanGrant(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap",
                           "./arch/object/structures_gen.h"
    ,
                           2243
    , __FUNCTION__)
                            ;

    if(!((((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2245, __FUNCTION__);

    cap.words[0] &= ~0x400000000000000ull;
    cap.words[0] |= (v64 << 58) & 0x400000000000000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_endpoint_cap_get_capCanReceive(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap",
                           "./arch/object/structures_gen.h"
    ,
                           2256
    , __FUNCTION__)
                            ;

    ret = (cap.words[0] & 0x200000000000000ull) >> 57;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_endpoint_cap_set_capCanReceive(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap",
                           "./arch/object/structures_gen.h"
    ,
                           2269
    , __FUNCTION__)
                            ;

    if(!((((~0x200000000000000ull >> 57 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x200000000000000ull >> 57 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2271, __FUNCTION__);

    cap.words[0] &= ~0x200000000000000ull;
    cap.words[0] |= (v64 << 57) & 0x200000000000000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_endpoint_cap_get_capCanSend(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap",
                           "./arch/object/structures_gen.h"
    ,
                           2282
    , __FUNCTION__)
                            ;

    ret = (cap.words[0] & 0x100000000000000ull) >> 56;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_endpoint_cap_set_capCanSend(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap",
                           "./arch/object/structures_gen.h"
    ,
                           2295
    , __FUNCTION__)
                            ;

    if(!((((~0x100000000000000ull >> 56 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x100000000000000ull >> 56 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2297, __FUNCTION__);

    cap.words[0] &= ~0x100000000000000ull;
    cap.words[0] |= (v64 << 56) & 0x100000000000000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_endpoint_cap_get_capEPPtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_endpoint_cap",
                           "./arch/object/structures_gen.h"
    ,
                           2308
    , __FUNCTION__)
                            ;

    ret = (cap.words[0] & 0xffffffffffffull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_notification_cap_new(uint64_t capNtfnBadge, uint64_t capNtfnCanReceive, uint64_t capNtfnCanSend, uint64_t capNtfnPtr) {
    cap_t cap;


    if(!(((uint64_t)cap_notification_cap & ~0x1full) == ((1 && ((uint64_t)cap_notification_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_notification_cap & ~0x1full) == ((1 && ((uint64_t)cap_notification_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2323, __FUNCTION__);
    if(!((capNtfnCanReceive & ~0x1ull) == ((1 && (capNtfnCanReceive & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capNtfnCanReceive & ~0x1ull) == ((1 && (capNtfnCanReceive & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2324, __FUNCTION__);
    if(!((capNtfnCanSend & ~0x1ull) == ((1 && (capNtfnCanSend & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capNtfnCanSend & ~0x1ull) == ((1 && (capNtfnCanSend & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2325, __FUNCTION__);
    if(!((capNtfnPtr & ~0xffffffffffffull) == ((1 && (capNtfnPtr & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capNtfnPtr & ~0xffffffffffffull) == ((1 && (capNtfnPtr & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 2326, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_notification_cap & 0x1full) << 59
        | (capNtfnCanReceive & 0x1ull) << 58
        | (capNtfnCanSend & 0x1ull) << 57
        | (capNtfnPtr & 0xffffffffffffull) >> 0;
    cap.words[1] = 0
        | capNtfnBadge << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_notification_cap_get_capNtfnBadge(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_notification_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_notification_cap",
                               "./arch/object/structures_gen.h"
    ,
                               2343
    , __FUNCTION__)
                                ;

    ret = (cap.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_notification_cap_set_capNtfnBadge(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_notification_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_notification_cap",
                               "./arch/object/structures_gen.h"
    ,
                               2356
    , __FUNCTION__)
                                ;

    if(!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2358, __FUNCTION__);

    cap.words[1] &= ~0xffffffffffffffffull;
    cap.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_notification_cap_get_capNtfnCanReceive(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_notification_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_notification_cap",
                               "./arch/object/structures_gen.h"
    ,
                               2369
    , __FUNCTION__)
                                ;

    ret = (cap.words[0] & 0x400000000000000ull) >> 58;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_notification_cap_set_capNtfnCanReceive(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_notification_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_notification_cap",
                               "./arch/object/structures_gen.h"
    ,
                               2382
    , __FUNCTION__)
                                ;

    if(!((((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2384, __FUNCTION__);

    cap.words[0] &= ~0x400000000000000ull;
    cap.words[0] |= (v64 << 58) & 0x400000000000000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_notification_cap_get_capNtfnCanSend(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_notification_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_notification_cap",
                               "./arch/object/structures_gen.h"
    ,
                               2395
    , __FUNCTION__)
                                ;

    ret = (cap.words[0] & 0x200000000000000ull) >> 57;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_notification_cap_set_capNtfnCanSend(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_notification_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_notification_cap",
                               "./arch/object/structures_gen.h"
    ,
                               2408
    , __FUNCTION__)
                                ;

    if(!((((~0x200000000000000ull >> 57 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x200000000000000ull >> 57 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2410, __FUNCTION__);

    cap.words[0] &= ~0x200000000000000ull;
    cap.words[0] |= (v64 << 57) & 0x200000000000000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_notification_cap_get_capNtfnPtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_notification_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_notification_cap",
                               "./arch/object/structures_gen.h"
    ,
                               2421
    , __FUNCTION__)
                                ;

    ret = (cap.words[0] & 0xffffffffffffull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_reply_cap_new(uint64_t capReplyMaster, uint64_t capTCBPtr) {
    cap_t cap;


    if(!((capReplyMaster & ~0x1ull) == ((1 && (capReplyMaster & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capReplyMaster & ~0x1ull) == ((1 && (capReplyMaster & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2436, __FUNCTION__);
    if(!(((uint64_t)cap_reply_cap & ~0x1full) == ((1 && ((uint64_t)cap_reply_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_reply_cap & ~0x1full) == ((1 && ((uint64_t)cap_reply_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2437, __FUNCTION__);

    cap.words[0] = 0
        | (capReplyMaster & 0x1ull) << 0
        | ((uint64_t)cap_reply_cap & 0x1full) << 59;
    cap.words[1] = 0
        | capTCBPtr << 0;

    return cap;
}

static inline void
cap_reply_cap_ptr_new(cap_t *cap_ptr, uint64_t capReplyMaster, uint64_t capTCBPtr) {

    if(!((capReplyMaster & ~0x1ull) == ((1 && (capReplyMaster & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capReplyMaster & ~0x1ull) == ((1 && (capReplyMaster & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2451, __FUNCTION__);
    if(!(((uint64_t)cap_reply_cap & ~0x1full) == ((1 && ((uint64_t)cap_reply_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_reply_cap & ~0x1full) == ((1 && ((uint64_t)cap_reply_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2452, __FUNCTION__);

    cap_ptr->words[0] = 0
        | (capReplyMaster & 0x1ull) << 0
        | ((uint64_t)cap_reply_cap & 0x1full) << 59;
    cap_ptr->words[1] = 0
        | capTCBPtr << 0;
}

static inline uint64_t __attribute__((__const__))
cap_reply_cap_get_capTCBPtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_reply_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_reply_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2465
    , __FUNCTION__)
                         ;

    ret = (cap.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_reply_cap_get_capReplyMaster(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_reply_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_reply_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2479
    , __FUNCTION__)
                         ;

    ret = (cap.words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_cnode_cap_new(uint64_t capCNodeRadix, uint64_t capCNodeGuardSize, uint64_t capCNodeGuard, uint64_t capCNodePtr) {
    cap_t cap;


    if(!((capCNodeRadix & ~0x3full) == ((1 && (capCNodeRadix & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capCNodeRadix & ~0x3full) == ((1 && (capCNodeRadix & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2494, __FUNCTION__);
    if(!((capCNodeGuardSize & ~0x3full) == ((1 && (capCNodeGuardSize & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capCNodeGuardSize & ~0x3full) == ((1 && (capCNodeGuardSize & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2495, __FUNCTION__);
    if(!(((uint64_t)cap_cnode_cap & ~0x1full) == ((1 && ((uint64_t)cap_cnode_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_cnode_cap & ~0x1full) == ((1 && ((uint64_t)cap_cnode_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2496, __FUNCTION__);
    if(!((capCNodePtr & ~0xfffffffffffeull) == ((1 && (capCNodePtr & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capCNodePtr & ~0xfffffffffffeull) == ((1 && (capCNodePtr & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 2497, __FUNCTION__);

    cap.words[0] = 0
        | (capCNodeRadix & 0x3full) << 47
        | (capCNodeGuardSize & 0x3full) << 53
        | ((uint64_t)cap_cnode_cap & 0x1full) << 59
        | (capCNodePtr & 0xfffffffffffeull) >> 1;
    cap.words[1] = 0
        | capCNodeGuard << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_cnode_cap_get_capCNodeGuard(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2514
    , __FUNCTION__)
                         ;

    ret = (cap.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_cnode_cap_set_capCNodeGuard(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2527
    , __FUNCTION__)
                         ;

    if(!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2529, __FUNCTION__);

    cap.words[1] &= ~0xffffffffffffffffull;
    cap.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_cnode_cap_get_capCNodeGuardSize(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2540
    , __FUNCTION__)
                         ;

    ret = (cap.words[0] & 0x7e0000000000000ull) >> 53;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_cnode_cap_set_capCNodeGuardSize(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2553
    , __FUNCTION__)
                         ;

    if(!((((~0x7e0000000000000ull >> 53 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x7e0000000000000ull >> 53 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2555, __FUNCTION__);

    cap.words[0] &= ~0x7e0000000000000ull;
    cap.words[0] |= (v64 << 53) & 0x7e0000000000000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_cnode_cap_get_capCNodeRadix(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2566
    , __FUNCTION__)
                         ;

    ret = (cap.words[0] & 0x1f800000000000ull) >> 47;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_cnode_cap_get_capCNodePtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_cnode_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2580
    , __FUNCTION__)
                         ;

    ret = (cap.words[0] & 0x7fffffffffffull) << 1;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_thread_cap_new(uint64_t capTCBPtr) {
    cap_t cap;


    if(!(((uint64_t)cap_thread_cap & ~0x1full) == ((1 && ((uint64_t)cap_thread_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_thread_cap & ~0x1full) == ((1 && ((uint64_t)cap_thread_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2595, __FUNCTION__);
    if(!((capTCBPtr & ~0xffffffffffffull) == ((1 && (capTCBPtr & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capTCBPtr & ~0xffffffffffffull) == ((1 && (capTCBPtr & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 2596, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_thread_cap & 0x1full) << 59
        | (capTCBPtr & 0xffffffffffffull) >> 0;
    cap.words[1] = 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_thread_cap_get_capTCBPtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_thread_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_thread_cap",
                         "./arch/object/structures_gen.h"
    ,
                         2610
    , __FUNCTION__)
                          ;

    ret = (cap.words[0] & 0xffffffffffffull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_irq_control_cap_new(void) {
    cap_t cap;


    if(!(((uint64_t)cap_irq_control_cap & ~0x1full) == ((1 && ((uint64_t)cap_irq_control_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_irq_control_cap & ~0x1full) == ((1 && ((uint64_t)cap_irq_control_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2625, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_irq_control_cap & 0x1full) << 59;
    cap.words[1] = 0;

    return cap;
}

static inline cap_t __attribute__((__const__))
cap_irq_handler_cap_new(uint64_t capIRQ) {
    cap_t cap;


    if(!((capIRQ & ~0xffull) == ((1 && (capIRQ & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capIRQ & ~0xffull) == ((1 && (capIRQ & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2639, __FUNCTION__);
    if(!(((uint64_t)cap_irq_handler_cap & ~0x1full) == ((1 && ((uint64_t)cap_irq_handler_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_irq_handler_cap & ~0x1full) == ((1 && ((uint64_t)cap_irq_handler_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2640, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_irq_handler_cap & 0x1full) << 59;
    cap.words[1] = 0
        | (capIRQ & 0xffull) << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_irq_handler_cap_get_capIRQ(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_irq_handler_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_irq_handler_cap",
                              "./arch/object/structures_gen.h"
    ,
                              2654
    , __FUNCTION__)
                               ;

    ret = (cap.words[1] & 0xffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_zombie_cap_new(uint64_t capZombieID, uint64_t capZombieType) {
    cap_t cap;


    if(!(((uint64_t)cap_zombie_cap & ~0x1full) == ((1 && ((uint64_t)cap_zombie_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_zombie_cap & ~0x1full) == ((1 && ((uint64_t)cap_zombie_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2669, __FUNCTION__);
    if(!((capZombieType & ~0x7full) == ((1 && (capZombieType & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capZombieType & ~0x7full) == ((1 && (capZombieType & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2670, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_zombie_cap & 0x1full) << 59
        | (capZombieType & 0x7full) << 0;
    cap.words[1] = 0
        | capZombieID << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_zombie_cap_get_capZombieID(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_zombie_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_zombie_cap",
                         "./arch/object/structures_gen.h"
    ,
                         2685
    , __FUNCTION__)
                          ;

    ret = (cap.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_zombie_cap_set_capZombieID(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_zombie_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_zombie_cap",
                         "./arch/object/structures_gen.h"
    ,
                         2698
    , __FUNCTION__)
                          ;

    if(!((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2700, __FUNCTION__);

    cap.words[1] &= ~0xffffffffffffffffull;
    cap.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_zombie_cap_get_capZombieType(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_zombie_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_zombie_cap",
                         "./arch/object/structures_gen.h"
    ,
                         2711
    , __FUNCTION__)
                          ;

    ret = (cap.words[0] & 0x7full) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_domain_cap_new(void) {
    cap_t cap;


    if(!(((uint64_t)cap_domain_cap & ~0x1full) == ((1 && ((uint64_t)cap_domain_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_domain_cap & ~0x1full) == ((1 && ((uint64_t)cap_domain_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2726, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_domain_cap & 0x1full) << 59;
    cap.words[1] = 0;

    return cap;
}

static inline cap_t __attribute__((__const__))
cap_frame_cap_new(uint64_t capFMappedASID, uint64_t capFBasePtr, uint64_t capFSize, uint64_t capFMapType, uint64_t capFMappedAddress, uint64_t capFVMRights, uint64_t capFIsDevice) {
    cap_t cap;


    if(!((capFMappedASID & ~0xffffull) == ((1 && (capFMappedASID & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capFMappedASID & ~0xffffull) == ((1 && (capFMappedASID & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2740, __FUNCTION__);
    if(!((capFBasePtr & ~0xffffffffffffull) == ((1 && (capFBasePtr & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capFBasePtr & ~0xffffffffffffull) == ((1 && (capFBasePtr & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 2741, __FUNCTION__);
    if(!(((uint64_t)cap_frame_cap & ~0x1full) == ((1 && ((uint64_t)cap_frame_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_frame_cap & ~0x1full) == ((1 && ((uint64_t)cap_frame_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2742, __FUNCTION__);
    if(!((capFSize & ~0x3ull) == ((1 && (capFSize & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capFSize & ~0x3ull) == ((1 && (capFSize & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2743, __FUNCTION__);
    if(!((capFMapType & ~0x3ull) == ((1 && (capFMapType & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capFMapType & ~0x3ull) == ((1 && (capFMapType & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2744, __FUNCTION__);
    if(!((capFMappedAddress & ~0xffffffffffffull) == ((1 && (capFMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capFMappedAddress & ~0xffffffffffffull) == ((1 && (capFMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 2745, __FUNCTION__);
    if(!((capFVMRights & ~0x3ull) == ((1 && (capFVMRights & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capFVMRights & ~0x3ull) == ((1 && (capFVMRights & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2746, __FUNCTION__);
    if(!((capFIsDevice & ~0x1ull) == ((1 && (capFIsDevice & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capFIsDevice & ~0x1ull) == ((1 && (capFIsDevice & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2747, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_frame_cap & 0x1full) << 59
        | (capFSize & 0x3ull) << 57
        | (capFMapType & 0x3ull) << 55
        | (capFMappedAddress & 0xffffffffffffull) << 7
        | (capFVMRights & 0x3ull) << 5
        | (capFIsDevice & 0x1ull) << 4;
    cap.words[1] = 0
        | (capFMappedASID & 0xffffull) << 48
        | (capFBasePtr & 0xffffffffffffull) >> 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_frame_cap_get_capFMappedASID(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2767
    , __FUNCTION__)
                         ;

    ret = (cap.words[1] & 0xffff000000000000ull) >> 48;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_frame_cap_set_capFMappedASID(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2780
    , __FUNCTION__)
                         ;

    if(!((((~0xffff000000000000ull >> 48 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffff000000000000ull >> 48 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2782, __FUNCTION__);

    cap.words[1] &= ~0xffff000000000000ull;
    cap.words[1] |= (v64 << 48) & 0xffff000000000000ull;
    return cap;
}

static inline uint64_t __attribute__((__pure__))
cap_frame_cap_ptr_get_capFMappedASID(cap_t *cap_ptr) {
    uint64_t ret;
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2793
    , __FUNCTION__)
                         ;

    ret = (cap_ptr->words[1] & 0xffff000000000000ull) >> 48;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
cap_frame_cap_ptr_set_capFMappedASID(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2807
    , __FUNCTION__)
                         ;


    if(!((((~0xffff000000000000ull >> 48) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffff000000000000ull >> 48) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2810, __FUNCTION__);

    cap_ptr->words[1] &= ~0xffff000000000000ull;
    cap_ptr->words[1] |= (v64 << 48) & 0xffff000000000000ull;
}

static inline uint64_t __attribute__((__const__))
cap_frame_cap_get_capFBasePtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2820
    , __FUNCTION__)
                         ;

    ret = (cap.words[1] & 0xffffffffffffull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_frame_cap_get_capFSize(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2834
    , __FUNCTION__)
                         ;

    ret = (cap.words[0] & 0x600000000000000ull) >> 57;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_frame_cap_get_capFMapType(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2848
    , __FUNCTION__)
                         ;

    ret = (cap.words[0] & 0x180000000000000ull) >> 55;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_frame_cap_set_capFMapType(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2861
    , __FUNCTION__)
                         ;

    if(!((((~0x180000000000000ull >> 55 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x180000000000000ull >> 55 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2863, __FUNCTION__);

    cap.words[0] &= ~0x180000000000000ull;
    cap.words[0] |= (v64 << 55) & 0x180000000000000ull;
    return cap;
}

static inline void
cap_frame_cap_ptr_set_capFMapType(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2874
    , __FUNCTION__)
                         ;


    if(!((((~0x180000000000000ull >> 55) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x180000000000000ull >> 55) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2877, __FUNCTION__);

    cap_ptr->words[0] &= ~0x180000000000000ull;
    cap_ptr->words[0] |= (v64 << 55) & 0x180000000000000ull;
}

static inline uint64_t __attribute__((__const__))
cap_frame_cap_get_capFMappedAddress(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2887
    , __FUNCTION__)
                         ;

    ret = (cap.words[0] & 0x7fffffffffff80ull) >> 7;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_frame_cap_set_capFMappedAddress(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2900
    , __FUNCTION__)
                         ;

    if(!((((~0x7fffffffffff80ull >> 7 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0x7fffffffffff80ull >> 7 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 2902, __FUNCTION__);

    cap.words[0] &= ~0x7fffffffffff80ull;
    cap.words[0] |= (v64 << 7) & 0x7fffffffffff80ull;
    return cap;
}

static inline void
cap_frame_cap_ptr_set_capFMappedAddress(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2913
    , __FUNCTION__)
                         ;


    if(!((((~0x7fffffffffff80ull >> 7) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0x7fffffffffff80ull >> 7) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 2916, __FUNCTION__);

    cap_ptr->words[0] &= ~0x7fffffffffff80ull;
    cap_ptr->words[0] |= (v64 << 7) & 0x7fffffffffff80ull;
}

static inline uint64_t __attribute__((__const__))
cap_frame_cap_get_capFVMRights(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2926
    , __FUNCTION__)
                         ;

    ret = (cap.words[0] & 0x60ull) >> 5;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_frame_cap_set_capFVMRights(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2939
    , __FUNCTION__)
                         ;

    if(!((((~0x60ull >> 5 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x60ull >> 5 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2941, __FUNCTION__);

    cap.words[0] &= ~0x60ull;
    cap.words[0] |= (v64 << 5) & 0x60ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_frame_cap_get_capFIsDevice(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_frame_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_frame_cap",
                        "./arch/object/structures_gen.h"
    ,
                        2952
    , __FUNCTION__)
                         ;

    ret = (cap.words[0] & 0x10ull) >> 4;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_page_table_cap_new(uint64_t capPTMappedASID, uint64_t capPTBasePtr, uint64_t capPTIsMapped, uint64_t capPTMappedAddress) {
    cap_t cap;


    if(!((capPTMappedASID & ~0xfffull) == ((1 && (capPTMappedASID & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPTMappedASID & ~0xfffull) == ((1 && (capPTMappedASID & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2967, __FUNCTION__);
    if(!((capPTBasePtr & ~0xffffffffffffull) == ((1 && (capPTBasePtr & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capPTBasePtr & ~0xffffffffffffull) == ((1 && (capPTBasePtr & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 2968, __FUNCTION__);
    if(!(((uint64_t)cap_page_table_cap & ~0x1full) == ((1 && ((uint64_t)cap_page_table_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_page_table_cap & ~0x1full) == ((1 && ((uint64_t)cap_page_table_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2969, __FUNCTION__);
    if(!((capPTIsMapped & ~0x1ull) == ((1 && (capPTIsMapped & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPTIsMapped & ~0x1ull) == ((1 && (capPTIsMapped & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 2970, __FUNCTION__);
    if(!((capPTMappedAddress & ~0xfffffff00000ull) == ((1 && (capPTMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capPTMappedAddress & ~0xfffffff00000ull) == ((1 && (capPTMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 2971, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_page_table_cap & 0x1full) << 59
        | (capPTIsMapped & 0x1ull) << 49
        | (capPTMappedAddress & 0xfffffff00000ull) << 1;
    cap.words[1] = 0
        | (capPTMappedASID & 0xfffull) << 48
        | (capPTBasePtr & 0xffffffffffffull) >> 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_page_table_cap_get_capPTMappedASID(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap",
                             "./arch/object/structures_gen.h"
    ,
                             2988
    , __FUNCTION__)
                              ;

    ret = (cap.words[1] & 0xfff000000000000ull) >> 48;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_page_table_cap_set_capPTMappedASID(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap",
                             "./arch/object/structures_gen.h"
    ,
                             3001
    , __FUNCTION__)
                              ;

    if(!((((~0xfff000000000000ull >> 48 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xfff000000000000ull >> 48 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3003, __FUNCTION__);

    cap.words[1] &= ~0xfff000000000000ull;
    cap.words[1] |= (v64 << 48) & 0xfff000000000000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_page_table_cap_get_capPTBasePtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap",
                             "./arch/object/structures_gen.h"
    ,
                             3014
    , __FUNCTION__)
                              ;

    ret = (cap.words[1] & 0xffffffffffffull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_page_table_cap_get_capPTIsMapped(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap",
                             "./arch/object/structures_gen.h"
    ,
                             3028
    , __FUNCTION__)
                              ;

    ret = (cap.words[0] & 0x2000000000000ull) >> 49;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_page_table_cap_set_capPTIsMapped(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap",
                             "./arch/object/structures_gen.h"
    ,
                             3041
    , __FUNCTION__)
                              ;

    if(!((((~0x2000000000000ull >> 49 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x2000000000000ull >> 49 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3043, __FUNCTION__);

    cap.words[0] &= ~0x2000000000000ull;
    cap.words[0] |= (v64 << 49) & 0x2000000000000ull;
    return cap;
}

static inline void
cap_page_table_cap_ptr_set_capPTIsMapped(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_page_table_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_page_table_cap",
                             "./arch/object/structures_gen.h"
    ,
                             3054
    , __FUNCTION__)
                              ;


    if(!((((~0x2000000000000ull >> 49) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x2000000000000ull >> 49) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3057, __FUNCTION__);

    cap_ptr->words[0] &= ~0x2000000000000ull;
    cap_ptr->words[0] |= (v64 << 49) & 0x2000000000000ull;
}

static inline uint64_t __attribute__((__const__))
cap_page_table_cap_get_capPTMappedAddress(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap",
                             "./arch/object/structures_gen.h"
    ,
                             3067
    , __FUNCTION__)
                              ;

    ret = (cap.words[0] & 0x1ffffffe00000ull) >> 1;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_page_table_cap_set_capPTMappedAddress(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_table_cap",
                             "./arch/object/structures_gen.h"
    ,
                             3080
    , __FUNCTION__)
                              ;

    if(!((((~0x1ffffffe00000ull >> 1 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0x1ffffffe00000ull >> 1 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3082, __FUNCTION__);

    cap.words[0] &= ~0x1ffffffe00000ull;
    cap.words[0] |= (v64 << 1) & 0x1ffffffe00000ull;
    return cap;
}

static inline cap_t __attribute__((__const__))
cap_page_directory_cap_new(uint64_t capPDMappedASID, uint64_t capPDBasePtr, uint64_t capPDIsMapped, uint64_t capPDMappedAddress) {
    cap_t cap;


    if(!((capPDMappedASID & ~0xfffull) == ((1 && (capPDMappedASID & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPDMappedASID & ~0xfffull) == ((1 && (capPDMappedASID & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3094, __FUNCTION__);
    if(!((capPDBasePtr & ~0xffffffffffffull) == ((1 && (capPDBasePtr & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capPDBasePtr & ~0xffffffffffffull) == ((1 && (capPDBasePtr & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3095, __FUNCTION__);
    if(!(((uint64_t)cap_page_directory_cap & ~0x1full) == ((1 && ((uint64_t)cap_page_directory_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_page_directory_cap & ~0x1full) == ((1 && ((uint64_t)cap_page_directory_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3096, __FUNCTION__);
    if(!((capPDIsMapped & ~0x1ull) == ((1 && (capPDIsMapped & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPDIsMapped & ~0x1ull) == ((1 && (capPDIsMapped & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3097, __FUNCTION__);
    if(!((capPDMappedAddress & ~0xffffe0000000ull) == ((1 && (capPDMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capPDMappedAddress & ~0xffffe0000000ull) == ((1 && (capPDMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3098, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_page_directory_cap & 0x1full) << 59
        | (capPDIsMapped & 0x1ull) << 49
        | (capPDMappedAddress & 0xffffe0000000ull) << 1;
    cap.words[1] = 0
        | (capPDMappedASID & 0xfffull) << 48
        | (capPDBasePtr & 0xffffffffffffull) >> 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_page_directory_cap_get_capPDMappedASID(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap",
                                 "./arch/object/structures_gen.h"
    ,
                                 3115
    , __FUNCTION__)
                                  ;

    ret = (cap.words[1] & 0xfff000000000000ull) >> 48;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_page_directory_cap_set_capPDMappedASID(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap",
                                 "./arch/object/structures_gen.h"
    ,
                                 3128
    , __FUNCTION__)
                                  ;

    if(!((((~0xfff000000000000ull >> 48 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xfff000000000000ull >> 48 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3130, __FUNCTION__);

    cap.words[1] &= ~0xfff000000000000ull;
    cap.words[1] |= (v64 << 48) & 0xfff000000000000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_page_directory_cap_get_capPDBasePtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap",
                                 "./arch/object/structures_gen.h"
    ,
                                 3141
    , __FUNCTION__)
                                  ;

    ret = (cap.words[1] & 0xffffffffffffull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_page_directory_cap_get_capPDIsMapped(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap",
                                 "./arch/object/structures_gen.h"
    ,
                                 3155
    , __FUNCTION__)
                                  ;

    ret = (cap.words[0] & 0x2000000000000ull) >> 49;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_page_directory_cap_set_capPDIsMapped(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap",
                                 "./arch/object/structures_gen.h"
    ,
                                 3168
    , __FUNCTION__)
                                  ;

    if(!((((~0x2000000000000ull >> 49 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x2000000000000ull >> 49 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3170, __FUNCTION__);

    cap.words[0] &= ~0x2000000000000ull;
    cap.words[0] |= (v64 << 49) & 0x2000000000000ull;
    return cap;
}

static inline void
cap_page_directory_cap_ptr_set_capPDIsMapped(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_page_directory_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_page_directory_cap",
                                 "./arch/object/structures_gen.h"
    ,
                                 3181
    , __FUNCTION__)
                                  ;


    if(!((((~0x2000000000000ull >> 49) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x2000000000000ull >> 49) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3184, __FUNCTION__);

    cap_ptr->words[0] &= ~0x2000000000000ull;
    cap_ptr->words[0] |= (v64 << 49) & 0x2000000000000ull;
}

static inline uint64_t __attribute__((__const__))
cap_page_directory_cap_get_capPDMappedAddress(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap",
                                 "./arch/object/structures_gen.h"
    ,
                                 3194
    , __FUNCTION__)
                                  ;

    ret = (cap.words[0] & 0x1ffffc0000000ull) >> 1;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_page_directory_cap_set_capPDMappedAddress(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_page_directory_cap",
                                 "./arch/object/structures_gen.h"
    ,
                                 3207
    , __FUNCTION__)
                                  ;

    if(!((((~0x1ffffc0000000ull >> 1 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0x1ffffc0000000ull >> 1 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3209, __FUNCTION__);

    cap.words[0] &= ~0x1ffffc0000000ull;
    cap.words[0] |= (v64 << 1) & 0x1ffffc0000000ull;
    return cap;
}

static inline cap_t __attribute__((__const__))
cap_pdpt_cap_new(uint64_t capPDPTMappedASID, uint64_t capPDPTBasePtr, uint64_t capPDPTIsMapped, uint64_t capPDPTMappedAddress) {
    cap_t cap;


    if(!((capPDPTMappedASID & ~0xfffull) == ((1 && (capPDPTMappedASID & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPDPTMappedASID & ~0xfffull) == ((1 && (capPDPTMappedASID & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3221, __FUNCTION__);
    if(!((capPDPTBasePtr & ~0xffffffffffffull) == ((1 && (capPDPTBasePtr & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capPDPTBasePtr & ~0xffffffffffffull) == ((1 && (capPDPTBasePtr & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3222, __FUNCTION__);
    if(!(((uint64_t)cap_pdpt_cap & ~0x1full) == ((1 && ((uint64_t)cap_pdpt_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_pdpt_cap & ~0x1full) == ((1 && ((uint64_t)cap_pdpt_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3223, __FUNCTION__);
    if(!((capPDPTIsMapped & ~0x1ull) == ((1 && (capPDPTIsMapped & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPDPTIsMapped & ~0x1ull) == ((1 && (capPDPTIsMapped & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3224, __FUNCTION__);
    if(!((capPDPTMappedAddress & ~0xffc000000000ull) == ((1 && (capPDPTMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capPDPTMappedAddress & ~0xffc000000000ull) == ((1 && (capPDPTMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3225, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_pdpt_cap & 0x1full) << 59
        | (capPDPTIsMapped & 0x1ull) << 58
        | (capPDPTMappedAddress & 0xffc000000000ull) << 10;
    cap.words[1] = 0
        | (capPDPTMappedASID & 0xfffull) << 48
        | (capPDPTBasePtr & 0xffffffffffffull) >> 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_pdpt_cap_get_capPDPTMappedASID(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3242
    , __FUNCTION__)
                        ;

    ret = (cap.words[1] & 0xfff000000000000ull) >> 48;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_pdpt_cap_set_capPDPTMappedASID(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3255
    , __FUNCTION__)
                        ;

    if(!((((~0xfff000000000000ull >> 48 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xfff000000000000ull >> 48 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3257, __FUNCTION__);

    cap.words[1] &= ~0xfff000000000000ull;
    cap.words[1] |= (v64 << 48) & 0xfff000000000000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_pdpt_cap_get_capPDPTBasePtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3268
    , __FUNCTION__)
                        ;

    ret = (cap.words[1] & 0xffffffffffffull) << 0;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_pdpt_cap_get_capPDPTIsMapped(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3282
    , __FUNCTION__)
                        ;

    ret = (cap.words[0] & 0x400000000000000ull) >> 58;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_pdpt_cap_set_capPDPTIsMapped(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3295
    , __FUNCTION__)
                        ;

    if(!((((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3297, __FUNCTION__);

    cap.words[0] &= ~0x400000000000000ull;
    cap.words[0] |= (v64 << 58) & 0x400000000000000ull;
    return cap;
}

static inline void
cap_pdpt_cap_ptr_set_capPDPTIsMapped(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_pdpt_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_pdpt_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3308
    , __FUNCTION__)
                        ;


    if(!((((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3311, __FUNCTION__);

    cap_ptr->words[0] &= ~0x400000000000000ull;
    cap_ptr->words[0] |= (v64 << 58) & 0x400000000000000ull;
}

static inline uint64_t __attribute__((__const__))
cap_pdpt_cap_get_capPDPTMappedAddress(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3321
    , __FUNCTION__)
                        ;

    ret = (cap.words[0] & 0x3ff000000000000ull) >> 10;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_pdpt_cap_set_capPDPTMappedAddress(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_pdpt_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3334
    , __FUNCTION__)
                        ;

    if(!((((~0x3ff000000000000ull >> 10 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0x3ff000000000000ull >> 10 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3336, __FUNCTION__);

    cap.words[0] &= ~0x3ff000000000000ull;
    cap.words[0] |= (v64 << 10) & 0x3ff000000000000ull;
    return cap;
}

static inline cap_t __attribute__((__const__))
cap_pml4_cap_new(uint64_t capPML4MappedASID, uint64_t capPML4BasePtr, uint64_t capPML4IsMapped) {
    cap_t cap;


    if(!((capPML4MappedASID & ~0xfffull) == ((1 && (capPML4MappedASID & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPML4MappedASID & ~0xfffull) == ((1 && (capPML4MappedASID & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3348, __FUNCTION__);
    if(!(((uint64_t)cap_pml4_cap & ~0x1full) == ((1 && ((uint64_t)cap_pml4_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_pml4_cap & ~0x1full) == ((1 && ((uint64_t)cap_pml4_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3349, __FUNCTION__);
    if(!((capPML4IsMapped & ~0x1ull) == ((1 && (capPML4IsMapped & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPML4IsMapped & ~0x1ull) == ((1 && (capPML4IsMapped & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3350, __FUNCTION__);

    cap.words[0] = 0
        | (capPML4MappedASID & 0xfffull) << 0
        | ((uint64_t)cap_pml4_cap & 0x1full) << 59
        | (capPML4IsMapped & 0x1ull) << 58;
    cap.words[1] = 0
        | capPML4BasePtr << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_pml4_cap_get_capPML4BasePtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_pml4_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_pml4_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3366
    , __FUNCTION__)
                        ;

    ret = (cap.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_pml4_cap_get_capPML4IsMapped(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_pml4_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_pml4_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3380
    , __FUNCTION__)
                        ;

    ret = (cap.words[0] & 0x400000000000000ull) >> 58;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
cap_pml4_cap_ptr_set_capPML4IsMapped(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_pml4_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_pml4_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3394
    , __FUNCTION__)
                        ;


    if(!((((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3397, __FUNCTION__);

    cap_ptr->words[0] &= ~0x400000000000000ull;
    cap_ptr->words[0] |= (v64 << 58) & 0x400000000000000ull;
}

static inline uint64_t __attribute__((__const__))
cap_pml4_cap_get_capPML4MappedASID(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_pml4_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_pml4_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3407
    , __FUNCTION__)
                        ;

    ret = (cap.words[0] & 0xfffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
cap_pml4_cap_ptr_set_capPML4MappedASID(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_pml4_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_pml4_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3421
    , __FUNCTION__)
                        ;


    if(!((((~0xfffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xfffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3424, __FUNCTION__);

    cap_ptr->words[0] &= ~0xfffull;
    cap_ptr->words[0] |= (v64 << 0) & 0xfffull;
}

static inline cap_t __attribute__((__const__))
cap_asid_control_cap_new(void) {
    cap_t cap;


    if(!(((uint64_t)cap_asid_control_cap & ~0x1full) == ((1 && ((uint64_t)cap_asid_control_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_asid_control_cap & ~0x1full) == ((1 && ((uint64_t)cap_asid_control_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3435, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_asid_control_cap & 0x1full) << 59;
    cap.words[1] = 0;

    return cap;
}

static inline cap_t __attribute__((__const__))
cap_asid_pool_cap_new(uint64_t capASIDBase, uint64_t capASIDPool) {
    cap_t cap;


    if(!(((uint64_t)cap_asid_pool_cap & ~0x1full) == ((1 && ((uint64_t)cap_asid_pool_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_asid_pool_cap & ~0x1full) == ((1 && ((uint64_t)cap_asid_pool_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3449, __FUNCTION__);
    if(!((capASIDBase & ~0xfffull) == ((1 && (capASIDBase & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capASIDBase & ~0xfffull) == ((1 && (capASIDBase & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3450, __FUNCTION__);
    if(!((capASIDPool & ~0xfffffffff800ull) == ((1 && (capASIDPool & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capASIDPool & ~0xfffffffff800ull) == ((1 && (capASIDPool & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3451, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_asid_pool_cap & 0x1full) << 59
        | (capASIDBase & 0xfffull) << 47
        | (capASIDPool & 0xfffffffff800ull) >> 11;
    cap.words[1] = 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_asid_pool_cap_get_capASIDBase(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_asid_pool_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_asid_pool_cap",
                            "./arch/object/structures_gen.h"
    ,
                            3466
    , __FUNCTION__)
                             ;

    ret = (cap.words[0] & 0x7ff800000000000ull) >> 47;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_asid_pool_cap_get_capASIDPool(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_asid_pool_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_asid_pool_cap",
                            "./arch/object/structures_gen.h"
    ,
                            3480
    , __FUNCTION__)
                             ;

    ret = (cap.words[0] & 0x1fffffffffull) << 11;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_io_port_cap_new(uint64_t capIOPortFirstPort, uint64_t capIOPortLastPort, uint64_t capIOPortVPID) {
    cap_t cap;


    if(!(((uint64_t)cap_io_port_cap & ~0x1full) == ((1 && ((uint64_t)cap_io_port_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_io_port_cap & ~0x1full) == ((1 && ((uint64_t)cap_io_port_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3495, __FUNCTION__);
    if(!((capIOPortFirstPort & ~0xffffull) == ((1 && (capIOPortFirstPort & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capIOPortFirstPort & ~0xffffull) == ((1 && (capIOPortFirstPort & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3496, __FUNCTION__);
    if(!((capIOPortLastPort & ~0xffffull) == ((1 && (capIOPortLastPort & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capIOPortLastPort & ~0xffffull) == ((1 && (capIOPortLastPort & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3497, __FUNCTION__);
    if(!((capIOPortVPID & ~0xffffull) == ((1 && (capIOPortVPID & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capIOPortVPID & ~0xffffull) == ((1 && (capIOPortVPID & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3498, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_io_port_cap & 0x1full) << 59
        | (capIOPortFirstPort & 0xffffull) << 40
        | (capIOPortLastPort & 0xffffull) << 24
        | (capIOPortVPID & 0xffffull) << 0;
    cap.words[1] = 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_io_port_cap_get_capIOPortFirstPort(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_io_port_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_io_port_cap",
                          "./arch/object/structures_gen.h"
    ,
                          3514
    , __FUNCTION__)
                           ;

    ret = (cap.words[0] & 0xffff0000000000ull) >> 40;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_io_port_cap_get_capIOPortLastPort(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_io_port_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_io_port_cap",
                          "./arch/object/structures_gen.h"
    ,
                          3528
    , __FUNCTION__)
                           ;

    ret = (cap.words[0] & 0xffff000000ull) >> 24;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_io_port_cap_get_capIOPortVPID(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_io_port_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_io_port_cap",
                          "./arch/object/structures_gen.h"
    ,
                          3542
    , __FUNCTION__)
                           ;

    ret = (cap.words[0] & 0xffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_io_port_cap_set_capIOPortVPID(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_io_port_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_io_port_cap",
                          "./arch/object/structures_gen.h"
    ,
                          3555
    , __FUNCTION__)
                           ;

    if(!((((~0xffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3557, __FUNCTION__);

    cap.words[0] &= ~0xffffull;
    cap.words[0] |= (v64 << 0) & 0xffffull;
    return cap;
}

static inline cap_t __attribute__((__const__))
cap_vcpu_cap_new(uint64_t capVCPUPtr) {
    cap_t cap;


    if(!(((uint64_t)cap_vcpu_cap & ~0x1full) == ((1 && ((uint64_t)cap_vcpu_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_vcpu_cap & ~0x1full) == ((1 && ((uint64_t)cap_vcpu_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3569, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_vcpu_cap & 0x1full) << 59;
    cap.words[1] = 0
        | capVCPUPtr << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_vcpu_cap_get_capVCPUPtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_vcpu_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_vcpu_cap",
                       "./arch/object/structures_gen.h"
    ,
                       3583
    , __FUNCTION__)
                        ;

    ret = (cap.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_ept_pt_cap_new(uint64_t capPTMappedAddress, uint64_t capPTIsMapped, uint64_t capPTMappedASID, uint64_t capPTBasePtr) {
    cap_t cap;


    if(!(((uint64_t)cap_ept_pt_cap & ~0x1full) == ((1 && ((uint64_t)cap_ept_pt_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_ept_pt_cap & ~0x1full) == ((1 && ((uint64_t)cap_ept_pt_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3598, __FUNCTION__);
    if(!((capPTMappedAddress & ~0xfffffff00000ull) == ((1 && (capPTMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capPTMappedAddress & ~0xfffffff00000ull) == ((1 && (capPTMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3599, __FUNCTION__);
    if(!((capPTIsMapped & ~0x1ull) == ((1 && (capPTIsMapped & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPTIsMapped & ~0x1ull) == ((1 && (capPTIsMapped & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3600, __FUNCTION__);
    if(!((capPTMappedASID & ~0xffffull) == ((1 && (capPTMappedASID & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPTMappedASID & ~0xffffull) == ((1 && (capPTMappedASID & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3601, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_ept_pt_cap & 0x1full) << 59
        | (capPTMappedAddress & 0xfffffff00000ull) << 1
        | (capPTIsMapped & 0x1ull) << 58
        | (capPTMappedASID & 0xffffull) << 5;
    cap.words[1] = 0
        | capPTBasePtr << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pt_cap_get_capPTBasePtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3618
    , __FUNCTION__)
                          ;

    ret = (cap.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pt_cap_get_capPTIsMapped(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3632
    , __FUNCTION__)
                          ;

    ret = (cap.words[0] & 0x400000000000000ull) >> 58;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_ept_pt_cap_set_capPTIsMapped(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3645
    , __FUNCTION__)
                          ;

    if(!((((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3647, __FUNCTION__);

    cap.words[0] &= ~0x400000000000000ull;
    cap.words[0] |= (v64 << 58) & 0x400000000000000ull;
    return cap;
}

static inline void
cap_ept_pt_cap_ptr_set_capPTIsMapped(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_ept_pt_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_ept_pt_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3658
    , __FUNCTION__)
                          ;


    if(!((((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3661, __FUNCTION__);

    cap_ptr->words[0] &= ~0x400000000000000ull;
    cap_ptr->words[0] |= (v64 << 58) & 0x400000000000000ull;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pt_cap_get_capPTMappedAddress(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3671
    , __FUNCTION__)
                          ;

    ret = (cap.words[0] & 0x1ffffffe00000ull) >> 1;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_ept_pt_cap_set_capPTMappedAddress(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3684
    , __FUNCTION__)
                          ;

    if(!((((~0x1ffffffe00000ull >> 1 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0x1ffffffe00000ull >> 1 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3686, __FUNCTION__);

    cap.words[0] &= ~0x1ffffffe00000ull;
    cap.words[0] |= (v64 << 1) & 0x1ffffffe00000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pt_cap_get_capPTMappedASID(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3697
    , __FUNCTION__)
                          ;

    ret = (cap.words[0] & 0x1fffe0ull) >> 5;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_ept_pt_cap_set_capPTMappedASID(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pt_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3710
    , __FUNCTION__)
                          ;

    if(!((((~0x1fffe0ull >> 5 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x1fffe0ull >> 5 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3712, __FUNCTION__);

    cap.words[0] &= ~0x1fffe0ull;
    cap.words[0] |= (v64 << 5) & 0x1fffe0ull;
    return cap;
}

static inline cap_t __attribute__((__const__))
cap_ept_pd_cap_new(uint64_t capPDMappedAddress, uint64_t capPDIsMapped, uint64_t capPDMappedASID, uint64_t capPDBasePtr) {
    cap_t cap;


    if(!(((uint64_t)cap_ept_pd_cap & ~0x1full) == ((1 && ((uint64_t)cap_ept_pd_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_ept_pd_cap & ~0x1full) == ((1 && ((uint64_t)cap_ept_pd_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3724, __FUNCTION__);
    if(!((capPDMappedAddress & ~0xfffff0000000ull) == ((1 && (capPDMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capPDMappedAddress & ~0xfffff0000000ull) == ((1 && (capPDMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3725, __FUNCTION__);
    if(!((capPDIsMapped & ~0x1ull) == ((1 && (capPDIsMapped & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPDIsMapped & ~0x1ull) == ((1 && (capPDIsMapped & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3726, __FUNCTION__);
    if(!((capPDMappedASID & ~0xffffull) == ((1 && (capPDMappedASID & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPDMappedASID & ~0xffffull) == ((1 && (capPDMappedASID & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3727, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_ept_pd_cap & 0x1full) << 59
        | (capPDMappedAddress & 0xfffff0000000ull) << 1
        | (capPDIsMapped & 0x1ull) << 58
        | (capPDMappedASID & 0xffffull) << 13;
    cap.words[1] = 0
        | capPDBasePtr << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pd_cap_get_capPDBasePtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3744
    , __FUNCTION__)
                          ;

    ret = (cap.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pd_cap_get_capPDIsMapped(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3758
    , __FUNCTION__)
                          ;

    ret = (cap.words[0] & 0x400000000000000ull) >> 58;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_ept_pd_cap_set_capPDIsMapped(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3771
    , __FUNCTION__)
                          ;

    if(!((((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3773, __FUNCTION__);

    cap.words[0] &= ~0x400000000000000ull;
    cap.words[0] |= (v64 << 58) & 0x400000000000000ull;
    return cap;
}

static inline void
cap_ept_pd_cap_ptr_set_capPDIsMapped(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_ept_pd_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_ept_pd_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3784
    , __FUNCTION__)
                          ;


    if(!((((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3787, __FUNCTION__);

    cap_ptr->words[0] &= ~0x400000000000000ull;
    cap_ptr->words[0] |= (v64 << 58) & 0x400000000000000ull;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pd_cap_get_capPDMappedAddress(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3797
    , __FUNCTION__)
                          ;

    ret = (cap.words[0] & 0x1ffffe0000000ull) >> 1;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_ept_pd_cap_set_capPDMappedAddress(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3810
    , __FUNCTION__)
                          ;

    if(!((((~0x1ffffe0000000ull >> 1 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0x1ffffe0000000ull >> 1 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3812, __FUNCTION__);

    cap.words[0] &= ~0x1ffffe0000000ull;
    cap.words[0] |= (v64 << 1) & 0x1ffffe0000000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pd_cap_get_capPDMappedASID(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3823
    , __FUNCTION__)
                          ;

    ret = (cap.words[0] & 0x1fffe000ull) >> 13;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_ept_pd_cap_set_capPDMappedASID(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pd_cap",
                         "./arch/object/structures_gen.h"
    ,
                         3836
    , __FUNCTION__)
                          ;

    if(!((((~0x1fffe000ull >> 13 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x1fffe000ull >> 13 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3838, __FUNCTION__);

    cap.words[0] &= ~0x1fffe000ull;
    cap.words[0] |= (v64 << 13) & 0x1fffe000ull;
    return cap;
}

static inline cap_t __attribute__((__const__))
cap_ept_pdpt_cap_new(uint64_t capPDPTMappedAddress, uint64_t capPDPTIsMapped, uint64_t capPDPTMappedASID, uint64_t capPDPTBasePtr) {
    cap_t cap;


    if(!(((uint64_t)cap_ept_pdpt_cap & ~0x1full) == ((1 && ((uint64_t)cap_ept_pdpt_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_ept_pdpt_cap & ~0x1full) == ((1 && ((uint64_t)cap_ept_pdpt_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3850, __FUNCTION__);
    if(!((capPDPTMappedAddress & ~0xffffc0000000ull) == ((1 && (capPDPTMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0))) _assert_fail("(capPDPTMappedAddress & ~0xffffc0000000ull) == ((1 && (capPDPTMappedAddress & (1ull << 47))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3851, __FUNCTION__);
    if(!((capPDPTIsMapped & ~0x1ull) == ((1 && (capPDPTIsMapped & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPDPTIsMapped & ~0x1ull) == ((1 && (capPDPTIsMapped & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3852, __FUNCTION__);
    if(!((capPDPTMappedASID & ~0xffffull) == ((1 && (capPDPTMappedASID & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPDPTMappedASID & ~0xffffull) == ((1 && (capPDPTMappedASID & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3853, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_ept_pdpt_cap & 0x1full) << 59
        | (capPDPTMappedAddress & 0xffffc0000000ull) << 1
        | (capPDPTIsMapped & 0x1ull) << 58
        | (capPDPTMappedASID & 0xffffull) << 15;
    cap.words[1] = 0
        | capPDPTBasePtr << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pdpt_cap_get_capPDPTBasePtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap",
                           "./arch/object/structures_gen.h"
    ,
                           3870
    , __FUNCTION__)
                            ;

    ret = (cap.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pdpt_cap_get_capPDPTIsMapped(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap",
                           "./arch/object/structures_gen.h"
    ,
                           3884
    , __FUNCTION__)
                            ;

    ret = (cap.words[0] & 0x400000000000000ull) >> 58;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_ept_pdpt_cap_set_capPDPTIsMapped(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap",
                           "./arch/object/structures_gen.h"
    ,
                           3897
    , __FUNCTION__)
                            ;

    if(!((((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3899, __FUNCTION__);

    cap.words[0] &= ~0x400000000000000ull;
    cap.words[0] |= (v64 << 58) & 0x400000000000000ull;
    return cap;
}

static inline void
cap_ept_pdpt_cap_ptr_set_capPDPTIsMapped(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap",
                           "./arch/object/structures_gen.h"
    ,
                           3910
    , __FUNCTION__)
                            ;


    if(!((((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3913, __FUNCTION__);

    cap_ptr->words[0] &= ~0x400000000000000ull;
    cap_ptr->words[0] |= (v64 << 58) & 0x400000000000000ull;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pdpt_cap_get_capPDPTMappedAddress(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap",
                           "./arch/object/structures_gen.h"
    ,
                           3923
    , __FUNCTION__)
                            ;

    ret = (cap.words[0] & 0x1ffff80000000ull) >> 1;

    if (1 && (ret & (1ull << (47)))) {
        ret |= 0xffff000000000000;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_ept_pdpt_cap_set_capPDPTMappedAddress(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap",
                           "./arch/object/structures_gen.h"
    ,
                           3936
    , __FUNCTION__)
                            ;

    if(!((((~0x1ffff80000000ull >> 1 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0))) _assert_fail("(((~0x1ffff80000000ull >> 1 ) | 0xffff000000000000) & v64) == ((1 && (v64 & (1ull << (47)))) ? 0xffff000000000000 : 0)", "./arch/object/structures_gen.h", 3938, __FUNCTION__);

    cap.words[0] &= ~0x1ffff80000000ull;
    cap.words[0] |= (v64 << 1) & 0x1ffff80000000ull;
    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pdpt_cap_get_capPDPTMappedASID(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap",
                           "./arch/object/structures_gen.h"
    ,
                           3949
    , __FUNCTION__)
                            ;

    ret = (cap.words[0] & 0x7fff8000ull) >> 15;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline cap_t __attribute__((__const__))
cap_ept_pdpt_cap_set_capPDPTMappedASID(cap_t cap, uint64_t v64) {
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pdpt_cap",
                           "./arch/object/structures_gen.h"
    ,
                           3962
    , __FUNCTION__)
                            ;

    if(!((((~0x7fff8000ull >> 15 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x7fff8000ull >> 15 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3964, __FUNCTION__);

    cap.words[0] &= ~0x7fff8000ull;
    cap.words[0] |= (v64 << 15) & 0x7fff8000ull;
    return cap;
}

static inline cap_t __attribute__((__const__))
cap_ept_pml4_cap_new(uint64_t capPML4IsMapped, uint64_t capPML4MappedASID, uint64_t capPML4BasePtr) {
    cap_t cap;


    if(!(((uint64_t)cap_ept_pml4_cap & ~0x1full) == ((1 && ((uint64_t)cap_ept_pml4_cap & (1ull << 47))) ? 0x0 : 0))) _assert_fail("((uint64_t)cap_ept_pml4_cap & ~0x1full) == ((1 && ((uint64_t)cap_ept_pml4_cap & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3976, __FUNCTION__);
    if(!((capPML4IsMapped & ~0x1ull) == ((1 && (capPML4IsMapped & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPML4IsMapped & ~0x1ull) == ((1 && (capPML4IsMapped & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3977, __FUNCTION__);
    if(!((capPML4MappedASID & ~0xffffull) == ((1 && (capPML4MappedASID & (1ull << 47))) ? 0x0 : 0))) _assert_fail("(capPML4MappedASID & ~0xffffull) == ((1 && (capPML4MappedASID & (1ull << 47))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 3978, __FUNCTION__);

    cap.words[0] = 0
        | ((uint64_t)cap_ept_pml4_cap & 0x1full) << 59
        | (capPML4IsMapped & 0x1ull) << 58
        | (capPML4MappedASID & 0xffffull) << 0;
    cap.words[1] = 0
        | capPML4BasePtr << 0;

    return cap;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pml4_cap_get_capPML4BasePtr(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pml4_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pml4_cap",
                           "./arch/object/structures_gen.h"
    ,
                           3994
    , __FUNCTION__)
                            ;

    ret = (cap.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pml4_cap_get_capPML4IsMapped(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pml4_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pml4_cap",
                           "./arch/object/structures_gen.h"
    ,
                           4008
    , __FUNCTION__)
                            ;

    ret = (cap.words[0] & 0x400000000000000ull) >> 58;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
cap_ept_pml4_cap_ptr_set_capPML4IsMapped(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_ept_pml4_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_ept_pml4_cap",
                           "./arch/object/structures_gen.h"
    ,
                           4022
    , __FUNCTION__)
                            ;


    if(!((((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0x400000000000000ull >> 58) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4025, __FUNCTION__);

    cap_ptr->words[0] &= ~0x400000000000000ull;
    cap_ptr->words[0] |= (v64 << 58) & 0x400000000000000ull;
}

static inline uint64_t __attribute__((__const__))
cap_ept_pml4_cap_get_capPML4MappedASID(cap_t cap) {
    uint64_t ret;
    if(!(((cap.words[0] >> 59) & 0x1f) == cap_ept_pml4_cap)) _assert_fail("((cap.words[0] >> 59) & 0x1f) == cap_ept_pml4_cap",
                           "./arch/object/structures_gen.h"
    ,
                           4035
    , __FUNCTION__)
                            ;

    ret = (cap.words[0] & 0xffffull) >> 0;

    if (0 && (ret & (1ull << (47)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline void
cap_ept_pml4_cap_ptr_set_capPML4MappedASID(cap_t *cap_ptr,
                                      uint64_t v64) {
    if(!(((cap_ptr->words[0] >> 59) & 0x1f) == cap_ept_pml4_cap)) _assert_fail("((cap_ptr->words[0] >> 59) & 0x1f) == cap_ept_pml4_cap",
                           "./arch/object/structures_gen.h"
    ,
                           4049
    , __FUNCTION__)
                            ;


    if(!((((~0xffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0))) _assert_fail("(((~0xffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (47)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4052, __FUNCTION__);

    cap_ptr->words[0] &= ~0xffffull;
    cap_ptr->words[0] |= (v64 << 0) & 0xffffull;
}

struct pdpte {
    uint64_t words[1];
};
typedef struct pdpte pdpte_t;

enum pdpte_tag {
    pdpte_pdpte_1g = 1,
    pdpte_pdpte_pd = 0
};
typedef enum pdpte_tag pdpte_tag_t;

static inline uint64_t __attribute__((__pure__))
pdpte_ptr_get_page_size(pdpte_t *pdpte_ptr) {
    return (pdpte_ptr->words[0] >> 7) & 0x1ull;
}

static inline pdpte_t __attribute__((__const__))
pdpte_pdpte_1g_new(uint64_t xd, uint64_t page_base_address, uint64_t pat, uint64_t global, uint64_t dirty, uint64_t accessed, uint64_t cache_disabled, uint64_t write_through, uint64_t super_user, uint64_t read_write, uint64_t present) {
    pdpte_t pdpte;


    if(!((xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4079, __FUNCTION__);
    if(!((page_base_address & ~0x7ffffc0000000ull) == ((0 && (page_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(page_base_address & ~0x7ffffc0000000ull) == ((0 && (page_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4080, __FUNCTION__);
    if(!((pat & ~0x1ull) == ((0 && (pat & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(pat & ~0x1ull) == ((0 && (pat & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4081, __FUNCTION__);
    if(!((global & ~0x1ull) == ((0 && (global & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(global & ~0x1ull) == ((0 && (global & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4082, __FUNCTION__);
    if(!(((uint64_t)pdpte_pdpte_1g & ~0x1ull) == ((0 && ((uint64_t)pdpte_pdpte_1g & (1ull << 50))) ? 0x0 : 0))) _assert_fail("((uint64_t)pdpte_pdpte_1g & ~0x1ull) == ((0 && ((uint64_t)pdpte_pdpte_1g & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4083, __FUNCTION__);
    if(!((dirty & ~0x1ull) == ((0 && (dirty & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(dirty & ~0x1ull) == ((0 && (dirty & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4084, __FUNCTION__);
    if(!((accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4085, __FUNCTION__);
    if(!((cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4086, __FUNCTION__);
    if(!((write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4087, __FUNCTION__);
    if(!((super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4088, __FUNCTION__);
    if(!((read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4089, __FUNCTION__);
    if(!((present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4090, __FUNCTION__);

    pdpte.words[0] = 0
        | (xd & 0x1ull) << 63
        | (page_base_address & 0x7ffffc0000000ull) >> 0
        | (pat & 0x1ull) << 12
        | (global & 0x1ull) << 8
        | ((uint64_t)pdpte_pdpte_1g & 0x1ull) << 7
        | (dirty & 0x1ull) << 6
        | (accessed & 0x1ull) << 5
        | (cache_disabled & 0x1ull) << 4
        | (write_through & 0x1ull) << 3
        | (super_user & 0x1ull) << 2
        | (read_write & 0x1ull) << 1
        | (present & 0x1ull) << 0;

    return pdpte;
}

static inline uint64_t __attribute__((__pure__))
pdpte_pdpte_1g_ptr_get_page_base_address(pdpte_t *pdpte_ptr) {
    uint64_t ret;
    if(!(((pdpte_ptr->words[0] >> 7) & 0x1) == pdpte_pdpte_1g)) _assert_fail("((pdpte_ptr->words[0] >> 7) & 0x1) == pdpte_pdpte_1g",
                         "./arch/object/structures_gen.h"
    ,
                         4113
    , __FUNCTION__)
                          ;

    ret = (pdpte_ptr->words[0] & 0x7ffffc0000000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
pdpte_pdpte_1g_ptr_get_present(pdpte_t *pdpte_ptr) {
    uint64_t ret;
    if(!(((pdpte_ptr->words[0] >> 7) & 0x1) == pdpte_pdpte_1g)) _assert_fail("((pdpte_ptr->words[0] >> 7) & 0x1) == pdpte_pdpte_1g",
                         "./arch/object/structures_gen.h"
    ,
                         4127
    , __FUNCTION__)
                          ;

    ret = (pdpte_ptr->words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline pdpte_t __attribute__((__const__))
pdpte_pdpte_pd_new(uint64_t xd, uint64_t pd_base_address, uint64_t accessed, uint64_t cache_disabled, uint64_t write_through, uint64_t super_user, uint64_t read_write, uint64_t present) {
    pdpte_t pdpte;


    if(!((xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4142, __FUNCTION__);
    if(!((pd_base_address & ~0x7fffffffff000ull) == ((0 && (pd_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(pd_base_address & ~0x7fffffffff000ull) == ((0 && (pd_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4143, __FUNCTION__);
    if(!(((uint64_t)pdpte_pdpte_pd & ~0x1ull) == ((0 && ((uint64_t)pdpte_pdpte_pd & (1ull << 50))) ? 0x0 : 0))) _assert_fail("((uint64_t)pdpte_pdpte_pd & ~0x1ull) == ((0 && ((uint64_t)pdpte_pdpte_pd & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4144, __FUNCTION__);
    if(!((accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4145, __FUNCTION__);
    if(!((cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4146, __FUNCTION__);
    if(!((write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4147, __FUNCTION__);
    if(!((super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4148, __FUNCTION__);
    if(!((read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4149, __FUNCTION__);
    if(!((present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4150, __FUNCTION__);

    pdpte.words[0] = 0
        | (xd & 0x1ull) << 63
        | (pd_base_address & 0x7fffffffff000ull) >> 0
        | ((uint64_t)pdpte_pdpte_pd & 0x1ull) << 7
        | (accessed & 0x1ull) << 5
        | (cache_disabled & 0x1ull) << 4
        | (write_through & 0x1ull) << 3
        | (super_user & 0x1ull) << 2
        | (read_write & 0x1ull) << 1
        | (present & 0x1ull) << 0;

    return pdpte;
}

static inline uint64_t __attribute__((__pure__))
pdpte_pdpte_pd_ptr_get_pd_base_address(pdpte_t *pdpte_ptr) {
    uint64_t ret;
    if(!(((pdpte_ptr->words[0] >> 7) & 0x1) == pdpte_pdpte_pd)) _assert_fail("((pdpte_ptr->words[0] >> 7) & 0x1) == pdpte_pdpte_pd",
                         "./arch/object/structures_gen.h"
    ,
                         4170
    , __FUNCTION__)
                          ;

    ret = (pdpte_ptr->words[0] & 0x7fffffffff000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
pdpte_pdpte_pd_ptr_get_present(pdpte_t *pdpte_ptr) {
    uint64_t ret;
    if(!(((pdpte_ptr->words[0] >> 7) & 0x1) == pdpte_pdpte_pd)) _assert_fail("((pdpte_ptr->words[0] >> 7) & 0x1) == pdpte_pdpte_pd",
                         "./arch/object/structures_gen.h"
    ,
                         4184
    , __FUNCTION__)
                          ;

    ret = (pdpte_ptr->words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

struct ept_pde {
    uint64_t words[1];
};
typedef struct ept_pde ept_pde_t;

enum ept_pde_tag {
    ept_pde_ept_pde_pt = 0,
    ept_pde_ept_pde_2m = 1
};
typedef enum ept_pde_tag ept_pde_tag_t;

static inline uint64_t __attribute__((__pure__))
ept_pde_ptr_get_page_size(ept_pde_t *ept_pde_ptr) {
    return (ept_pde_ptr->words[0] >> 7) & 0x1ull;
}

static inline ept_pde_t __attribute__((__const__))
ept_pde_ept_pde_pt_new(uint64_t pt_base_address, uint64_t avl_cte_depth, uint64_t execute, uint64_t write, uint64_t read) {
    ept_pde_t ept_pde;


    if(!((pt_base_address & ~0x7fffffffff000ull) == ((0 && (pt_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(pt_base_address & ~0x7fffffffff000ull) == ((0 && (pt_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4215, __FUNCTION__);
    if(!((avl_cte_depth & ~0x7ull) == ((0 && (avl_cte_depth & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(avl_cte_depth & ~0x7ull) == ((0 && (avl_cte_depth & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4216, __FUNCTION__);
    if(!(((uint64_t)ept_pde_ept_pde_pt & ~0x1ull) == ((0 && ((uint64_t)ept_pde_ept_pde_pt & (1ull << 50))) ? 0x0 : 0))) _assert_fail("((uint64_t)ept_pde_ept_pde_pt & ~0x1ull) == ((0 && ((uint64_t)ept_pde_ept_pde_pt & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4217, __FUNCTION__);
    if(!((execute & ~0x1ull) == ((0 && (execute & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(execute & ~0x1ull) == ((0 && (execute & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4218, __FUNCTION__);
    if(!((write & ~0x1ull) == ((0 && (write & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(write & ~0x1ull) == ((0 && (write & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4219, __FUNCTION__);
    if(!((read & ~0x1ull) == ((0 && (read & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(read & ~0x1ull) == ((0 && (read & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4220, __FUNCTION__);

    ept_pde.words[0] = 0
        | (pt_base_address & 0x7fffffffff000ull) >> 0
        | (avl_cte_depth & 0x7ull) << 9
        | ((uint64_t)ept_pde_ept_pde_pt & 0x1ull) << 7
        | (execute & 0x1ull) << 2
        | (write & 0x1ull) << 1
        | (read & 0x1ull) << 0;

    return ept_pde;
}

static inline uint64_t __attribute__((__pure__))
ept_pde_ept_pde_pt_ptr_get_pt_base_address(ept_pde_t *ept_pde_ptr) {
    uint64_t ret;
    if(!(((ept_pde_ptr->words[0] >> 7) & 0x1) == ept_pde_ept_pde_pt)) _assert_fail("((ept_pde_ptr->words[0] >> 7) & 0x1) == ept_pde_ept_pde_pt",
                             "./arch/object/structures_gen.h"
    ,
                             4237
    , __FUNCTION__)
                              ;

    ret = (ept_pde_ptr->words[0] & 0x7fffffffff000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
ept_pde_ept_pde_pt_ptr_get_read(ept_pde_t *ept_pde_ptr) {
    uint64_t ret;
    if(!(((ept_pde_ptr->words[0] >> 7) & 0x1) == ept_pde_ept_pde_pt)) _assert_fail("((ept_pde_ptr->words[0] >> 7) & 0x1) == ept_pde_ept_pde_pt",
                             "./arch/object/structures_gen.h"
    ,
                             4251
    , __FUNCTION__)
                              ;

    ret = (ept_pde_ptr->words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline ept_pde_t __attribute__((__const__))
ept_pde_ept_pde_2m_new(uint64_t page_base_address, uint64_t avl_cte_depth, uint64_t ignore_pat, uint64_t type, uint64_t execute, uint64_t write, uint64_t read) {
    ept_pde_t ept_pde;


    if(!((page_base_address & ~0x7fffffff00000ull) == ((0 && (page_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(page_base_address & ~0x7fffffff00000ull) == ((0 && (page_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4266, __FUNCTION__);
    if(!((avl_cte_depth & ~0x3ull) == ((0 && (avl_cte_depth & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(avl_cte_depth & ~0x3ull) == ((0 && (avl_cte_depth & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4267, __FUNCTION__);
    if(!(((uint64_t)ept_pde_ept_pde_2m & ~0x1ull) == ((0 && ((uint64_t)ept_pde_ept_pde_2m & (1ull << 50))) ? 0x0 : 0))) _assert_fail("((uint64_t)ept_pde_ept_pde_2m & ~0x1ull) == ((0 && ((uint64_t)ept_pde_ept_pde_2m & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4268, __FUNCTION__);
    if(!((ignore_pat & ~0x1ull) == ((0 && (ignore_pat & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(ignore_pat & ~0x1ull) == ((0 && (ignore_pat & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4269, __FUNCTION__);
    if(!((type & ~0x7ull) == ((0 && (type & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(type & ~0x7ull) == ((0 && (type & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4270, __FUNCTION__);
    if(!((execute & ~0x1ull) == ((0 && (execute & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(execute & ~0x1ull) == ((0 && (execute & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4271, __FUNCTION__);
    if(!((write & ~0x1ull) == ((0 && (write & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(write & ~0x1ull) == ((0 && (write & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4272, __FUNCTION__);
    if(!((read & ~0x1ull) == ((0 && (read & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(read & ~0x1ull) == ((0 && (read & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4273, __FUNCTION__);

    ept_pde.words[0] = 0
        | (page_base_address & 0x7fffffff00000ull) >> 0
        | (avl_cte_depth & 0x3ull) << 10
        | ((uint64_t)ept_pde_ept_pde_2m & 0x1ull) << 7
        | (ignore_pat & 0x1ull) << 6
        | (type & 0x7ull) << 3
        | (execute & 0x1ull) << 2
        | (write & 0x1ull) << 1
        | (read & 0x1ull) << 0;

    return ept_pde;
}

static inline uint64_t __attribute__((__pure__))
ept_pde_ept_pde_2m_ptr_get_page_base_address(ept_pde_t *ept_pde_ptr) {
    uint64_t ret;
    if(!(((ept_pde_ptr->words[0] >> 7) & 0x1) == ept_pde_ept_pde_2m)) _assert_fail("((ept_pde_ptr->words[0] >> 7) & 0x1) == ept_pde_ept_pde_2m",
                             "./arch/object/structures_gen.h"
    ,
                             4292
    , __FUNCTION__)
                              ;

    ret = (ept_pde_ptr->words[0] & 0x7fffffff00000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
ept_pde_ept_pde_2m_ptr_get_read(ept_pde_t *ept_pde_ptr) {
    uint64_t ret;
    if(!(((ept_pde_ptr->words[0] >> 7) & 0x1) == ept_pde_ept_pde_2m)) _assert_fail("((ept_pde_ptr->words[0] >> 7) & 0x1) == ept_pde_ept_pde_2m",
                             "./arch/object/structures_gen.h"
    ,
                             4306
    , __FUNCTION__)
                              ;

    ret = (ept_pde_ptr->words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

struct x86_irq_state {
    uint32_t words[2];
};
typedef struct x86_irq_state x86_irq_state_t;

enum x86_irq_state_tag {
    x86_irq_state_irq_free = 0,
    x86_irq_state_irq_ioapic = 1,
    x86_irq_state_irq_msi = 2,
    x86_irq_state_irq_reserved = 3
};
typedef enum x86_irq_state_tag x86_irq_state_tag_t;

static inline uint32_t __attribute__((__const__))
x86_irq_state_get_irqType(x86_irq_state_t x86_irq_state) {
    return (x86_irq_state.words[1] >> 28) & 0xfu;
}

static inline x86_irq_state_t __attribute__((__const__))
x86_irq_state_irq_free_new(void) {
    x86_irq_state_t x86_irq_state;


    if(!(((uint32_t)x86_irq_state_irq_free & ~0xfu) == ((0 && ((uint32_t)x86_irq_state_irq_free & (1u << 31))) ? 0x0 : 0))) _assert_fail("((uint32_t)x86_irq_state_irq_free & ~0xfu) == ((0 && ((uint32_t)x86_irq_state_irq_free & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4339, __FUNCTION__);

    x86_irq_state.words[0] = 0;
    x86_irq_state.words[1] = 0
        | ((uint32_t)x86_irq_state_irq_free & 0xfu) << 28;

    return x86_irq_state;
}

static inline x86_irq_state_t __attribute__((__const__))
x86_irq_state_irq_ioapic_new(uint32_t id, uint32_t pin, uint32_t level, uint32_t polarity_low, uint32_t masked) {
    x86_irq_state_t x86_irq_state;


    if(!(((uint32_t)x86_irq_state_irq_ioapic & ~0xfu) == ((0 && ((uint32_t)x86_irq_state_irq_ioapic & (1u << 31))) ? 0x0 : 0))) _assert_fail("((uint32_t)x86_irq_state_irq_ioapic & ~0xfu) == ((0 && ((uint32_t)x86_irq_state_irq_ioapic & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4353, __FUNCTION__);
    if(!((id & ~0x1fu) == ((0 && (id & (1u << 31))) ? 0x0 : 0))) _assert_fail("(id & ~0x1fu) == ((0 && (id & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4354, __FUNCTION__);
    if(!((pin & ~0x1fu) == ((0 && (pin & (1u << 31))) ? 0x0 : 0))) _assert_fail("(pin & ~0x1fu) == ((0 && (pin & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4355, __FUNCTION__);
    if(!((level & ~0x1u) == ((0 && (level & (1u << 31))) ? 0x0 : 0))) _assert_fail("(level & ~0x1u) == ((0 && (level & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4356, __FUNCTION__);
    if(!((polarity_low & ~0x1u) == ((0 && (polarity_low & (1u << 31))) ? 0x0 : 0))) _assert_fail("(polarity_low & ~0x1u) == ((0 && (polarity_low & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4357, __FUNCTION__);
    if(!((masked & ~0x1u) == ((0 && (masked & (1u << 31))) ? 0x0 : 0))) _assert_fail("(masked & ~0x1u) == ((0 && (masked & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4358, __FUNCTION__);

    x86_irq_state.words[0] = 0;
    x86_irq_state.words[1] = 0
        | ((uint32_t)x86_irq_state_irq_ioapic & 0xfu) << 28
        | (id & 0x1fu) << 23
        | (pin & 0x1fu) << 18
        | (level & 0x1u) << 17
        | (polarity_low & 0x1u) << 16
        | (masked & 0x1u) << 15;

    return x86_irq_state;
}

static inline uint32_t __attribute__((__const__))
x86_irq_state_irq_ioapic_get_id(x86_irq_state_t x86_irq_state) {
    uint32_t ret;
    if(!(((x86_irq_state.words[1] >> 28) & 0xf) == x86_irq_state_irq_ioapic)) _assert_fail("((x86_irq_state.words[1] >> 28) & 0xf) == x86_irq_state_irq_ioapic",
                                   "./arch/object/structures_gen.h"
    ,
                                   4376
    , __FUNCTION__)
                                    ;

    ret = (x86_irq_state.words[1] & 0xf800000u) >> 23;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint32_t __attribute__((__const__))
x86_irq_state_irq_ioapic_get_pin(x86_irq_state_t x86_irq_state) {
    uint32_t ret;
    if(!(((x86_irq_state.words[1] >> 28) & 0xf) == x86_irq_state_irq_ioapic)) _assert_fail("((x86_irq_state.words[1] >> 28) & 0xf) == x86_irq_state_irq_ioapic",
                                   "./arch/object/structures_gen.h"
    ,
                                   4390
    , __FUNCTION__)
                                    ;

    ret = (x86_irq_state.words[1] & 0x7c0000u) >> 18;

    if (0 && (ret & (1u << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline x86_irq_state_t __attribute__((__const__))
x86_irq_state_irq_ioapic_set_masked(x86_irq_state_t x86_irq_state, uint32_t v32) {
    if(!(((x86_irq_state.words[1] >> 28) & 0xf) == x86_irq_state_irq_ioapic)) _assert_fail("((x86_irq_state.words[1] >> 28) & 0xf) == x86_irq_state_irq_ioapic",
                                   "./arch/object/structures_gen.h"
    ,
                                   4403
    , __FUNCTION__)
                                    ;

    if(!((((~0x8000u >> 15 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0))) _assert_fail("(((~0x8000u >> 15 ) | 0x0) & v32) == ((0 && (v32 & (1u << (31)))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4405, __FUNCTION__);

    x86_irq_state.words[1] &= ~0x8000u;
    x86_irq_state.words[1] |= (v32 << 15) & 0x8000u;
    return x86_irq_state;
}

static inline x86_irq_state_t __attribute__((__const__))
x86_irq_state_irq_msi_new(uint32_t bus, uint32_t dev, uint32_t func, uint32_t handle) {
    x86_irq_state_t x86_irq_state;


    if(!(((uint32_t)x86_irq_state_irq_msi & ~0xfu) == ((0 && ((uint32_t)x86_irq_state_irq_msi & (1u << 31))) ? 0x0 : 0))) _assert_fail("((uint32_t)x86_irq_state_irq_msi & ~0xfu) == ((0 && ((uint32_t)x86_irq_state_irq_msi & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4417, __FUNCTION__);
    if(!((bus & ~0xffu) == ((0 && (bus & (1u << 31))) ? 0x0 : 0))) _assert_fail("(bus & ~0xffu) == ((0 && (bus & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4418, __FUNCTION__);
    if(!((dev & ~0x1fu) == ((0 && (dev & (1u << 31))) ? 0x0 : 0))) _assert_fail("(dev & ~0x1fu) == ((0 && (dev & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4419, __FUNCTION__);
    if(!((func & ~0x7u) == ((0 && (func & (1u << 31))) ? 0x0 : 0))) _assert_fail("(func & ~0x7u) == ((0 && (func & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4420, __FUNCTION__);

    x86_irq_state.words[0] = 0
        | handle << 0;
    x86_irq_state.words[1] = 0
        | ((uint32_t)x86_irq_state_irq_msi & 0xfu) << 28
        | (bus & 0xffu) << 20
        | (dev & 0x1fu) << 15
        | (func & 0x7u) << 12;

    return x86_irq_state;
}

static inline x86_irq_state_t __attribute__((__const__))
x86_irq_state_irq_reserved_new(void) {
    x86_irq_state_t x86_irq_state;


    if(!(((uint32_t)x86_irq_state_irq_reserved & ~0xfu) == ((0 && ((uint32_t)x86_irq_state_irq_reserved & (1u << 31))) ? 0x0 : 0))) _assert_fail("((uint32_t)x86_irq_state_irq_reserved & ~0xfu) == ((0 && ((uint32_t)x86_irq_state_irq_reserved & (1u << 31))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4438, __FUNCTION__);

    x86_irq_state.words[0] = 0;
    x86_irq_state.words[1] = 0
        | ((uint32_t)x86_irq_state_irq_reserved & 0xfu) << 28;

    return x86_irq_state;
}

struct pde {
    uint64_t words[1];
};
typedef struct pde pde_t;

enum pde_tag {
    pde_pde_pt = 0,
    pde_pde_large = 1
};
typedef enum pde_tag pde_tag_t;

static inline uint64_t __attribute__((__const__))
pde_get_page_size(pde_t pde) {
    return (pde.words[0] >> 7) & 0x1ull;
}

static inline uint64_t __attribute__((__pure__))
pde_ptr_get_page_size(pde_t *pde_ptr) {
    return (pde_ptr->words[0] >> 7) & 0x1ull;
}

static inline pde_t __attribute__((__const__))
pde_pde_pt_new(uint64_t xd, uint64_t pt_base_address, uint64_t accessed, uint64_t cache_disabled, uint64_t write_through, uint64_t super_user, uint64_t read_write, uint64_t present) {
    pde_t pde;


    if(!((xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4473, __FUNCTION__);
    if(!((pt_base_address & ~0x7fffffffff000ull) == ((0 && (pt_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(pt_base_address & ~0x7fffffffff000ull) == ((0 && (pt_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4474, __FUNCTION__);
    if(!(((uint64_t)pde_pde_pt & ~0x1ull) == ((0 && ((uint64_t)pde_pde_pt & (1ull << 50))) ? 0x0 : 0))) _assert_fail("((uint64_t)pde_pde_pt & ~0x1ull) == ((0 && ((uint64_t)pde_pde_pt & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4475, __FUNCTION__);
    if(!((accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4476, __FUNCTION__);
    if(!((cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4477, __FUNCTION__);
    if(!((write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4478, __FUNCTION__);
    if(!((super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4479, __FUNCTION__);
    if(!((read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4480, __FUNCTION__);
    if(!((present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4481, __FUNCTION__);

    pde.words[0] = 0
        | (xd & 0x1ull) << 63
        | (pt_base_address & 0x7fffffffff000ull) >> 0
        | ((uint64_t)pde_pde_pt & 0x1ull) << 7
        | (accessed & 0x1ull) << 5
        | (cache_disabled & 0x1ull) << 4
        | (write_through & 0x1ull) << 3
        | (super_user & 0x1ull) << 2
        | (read_write & 0x1ull) << 1
        | (present & 0x1ull) << 0;

    return pde;
}

static inline uint64_t __attribute__((__const__))
pde_pde_pt_get_pt_base_address(pde_t pde) {
    uint64_t ret;
    if(!(((pde.words[0] >> 7) & 0x1) == pde_pde_pt)) _assert_fail("((pde.words[0] >> 7) & 0x1) == pde_pde_pt",
                     "./arch/object/structures_gen.h"
    ,
                     4501
    , __FUNCTION__)
                      ;

    ret = (pde.words[0] & 0x7fffffffff000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
pde_pde_pt_ptr_get_pt_base_address(pde_t *pde_ptr) {
    uint64_t ret;
    if(!(((pde_ptr->words[0] >> 7) & 0x1) == pde_pde_pt)) _assert_fail("((pde_ptr->words[0] >> 7) & 0x1) == pde_pde_pt",
                     "./arch/object/structures_gen.h"
    ,
                     4515
    , __FUNCTION__)
                      ;

    ret = (pde_ptr->words[0] & 0x7fffffffff000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
pde_pde_pt_get_super_user(pde_t pde) {
    uint64_t ret;
    if(!(((pde.words[0] >> 7) & 0x1) == pde_pde_pt)) _assert_fail("((pde.words[0] >> 7) & 0x1) == pde_pde_pt",
                     "./arch/object/structures_gen.h"
    ,
                     4529
    , __FUNCTION__)
                      ;

    ret = (pde.words[0] & 0x4ull) >> 2;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
pde_pde_pt_get_present(pde_t pde) {
    uint64_t ret;
    if(!(((pde.words[0] >> 7) & 0x1) == pde_pde_pt)) _assert_fail("((pde.words[0] >> 7) & 0x1) == pde_pde_pt",
                     "./arch/object/structures_gen.h"
    ,
                     4543
    , __FUNCTION__)
                      ;

    ret = (pde.words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
pde_pde_pt_ptr_get_present(pde_t *pde_ptr) {
    uint64_t ret;
    if(!(((pde_ptr->words[0] >> 7) & 0x1) == pde_pde_pt)) _assert_fail("((pde_ptr->words[0] >> 7) & 0x1) == pde_pde_pt",
                     "./arch/object/structures_gen.h"
    ,
                     4557
    , __FUNCTION__)
                      ;

    ret = (pde_ptr->words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline pde_t __attribute__((__const__))
pde_pde_large_new(uint64_t xd, uint64_t page_base_address, uint64_t pat, uint64_t global, uint64_t dirty, uint64_t accessed, uint64_t cache_disabled, uint64_t write_through, uint64_t super_user, uint64_t read_write, uint64_t present) {
    pde_t pde;


    if(!((xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(xd & ~0x1ull) == ((0 && (xd & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4572, __FUNCTION__);
    if(!((page_base_address & ~0x7ffffffe00000ull) == ((0 && (page_base_address & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(page_base_address & ~0x7ffffffe00000ull) == ((0 && (page_base_address & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4573, __FUNCTION__);
    if(!((pat & ~0x1ull) == ((0 && (pat & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(pat & ~0x1ull) == ((0 && (pat & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4574, __FUNCTION__);
    if(!((global & ~0x1ull) == ((0 && (global & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(global & ~0x1ull) == ((0 && (global & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4575, __FUNCTION__);
    if(!(((uint64_t)pde_pde_large & ~0x1ull) == ((0 && ((uint64_t)pde_pde_large & (1ull << 50))) ? 0x0 : 0))) _assert_fail("((uint64_t)pde_pde_large & ~0x1ull) == ((0 && ((uint64_t)pde_pde_large & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4576, __FUNCTION__);
    if(!((dirty & ~0x1ull) == ((0 && (dirty & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(dirty & ~0x1ull) == ((0 && (dirty & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4577, __FUNCTION__);
    if(!((accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(accessed & ~0x1ull) == ((0 && (accessed & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4578, __FUNCTION__);
    if(!((cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(cache_disabled & ~0x1ull) == ((0 && (cache_disabled & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4579, __FUNCTION__);
    if(!((write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(write_through & ~0x1ull) == ((0 && (write_through & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4580, __FUNCTION__);
    if(!((super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(super_user & ~0x1ull) == ((0 && (super_user & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4581, __FUNCTION__);
    if(!((read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(read_write & ~0x1ull) == ((0 && (read_write & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4582, __FUNCTION__);
    if(!((present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(present & ~0x1ull) == ((0 && (present & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4583, __FUNCTION__);

    pde.words[0] = 0
        | (xd & 0x1ull) << 63
        | (page_base_address & 0x7ffffffe00000ull) >> 0
        | (pat & 0x1ull) << 12
        | (global & 0x1ull) << 8
        | ((uint64_t)pde_pde_large & 0x1ull) << 7
        | (dirty & 0x1ull) << 6
        | (accessed & 0x1ull) << 5
        | (cache_disabled & 0x1ull) << 4
        | (write_through & 0x1ull) << 3
        | (super_user & 0x1ull) << 2
        | (read_write & 0x1ull) << 1
        | (present & 0x1ull) << 0;

    return pde;
}

static inline uint64_t __attribute__((__const__))
pde_pde_large_get_page_base_address(pde_t pde) {
    uint64_t ret;
    if(!(((pde.words[0] >> 7) & 0x1) == pde_pde_large)) _assert_fail("((pde.words[0] >> 7) & 0x1) == pde_pde_large",
                        "./arch/object/structures_gen.h"
    ,
                        4606
    , __FUNCTION__)
                         ;

    ret = (pde.words[0] & 0x7ffffffe00000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
pde_pde_large_ptr_get_page_base_address(pde_t *pde_ptr) {
    uint64_t ret;
    if(!(((pde_ptr->words[0] >> 7) & 0x1) == pde_pde_large)) _assert_fail("((pde_ptr->words[0] >> 7) & 0x1) == pde_pde_large",
                        "./arch/object/structures_gen.h"
    ,
                        4620
    , __FUNCTION__)
                         ;

    ret = (pde_ptr->words[0] & 0x7ffffffe00000ull) << 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
pde_pde_large_get_super_user(pde_t pde) {
    uint64_t ret;
    if(!(((pde.words[0] >> 7) & 0x1) == pde_pde_large)) _assert_fail("((pde.words[0] >> 7) & 0x1) == pde_pde_large",
                        "./arch/object/structures_gen.h"
    ,
                        4634
    , __FUNCTION__)
                         ;

    ret = (pde.words[0] & 0x4ull) >> 2;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
pde_pde_large_get_present(pde_t pde) {
    uint64_t ret;
    if(!(((pde.words[0] >> 7) & 0x1) == pde_pde_large)) _assert_fail("((pde.words[0] >> 7) & 0x1) == pde_pde_large",
                        "./arch/object/structures_gen.h"
    ,
                        4648
    , __FUNCTION__)
                         ;

    ret = (pde.words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__pure__))
pde_pde_large_ptr_get_present(pde_t *pde_ptr) {
    uint64_t ret;
    if(!(((pde_ptr->words[0] >> 7) & 0x1) == pde_pde_large)) _assert_fail("((pde_ptr->words[0] >> 7) & 0x1) == pde_pde_large",
                        "./arch/object/structures_gen.h"
    ,
                        4662
    , __FUNCTION__)
                         ;

    ret = (pde_ptr->words[0] & 0x1ull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

struct seL4_Fault {
    uint64_t words[2];
};
typedef struct seL4_Fault seL4_Fault_t;

enum seL4_Fault_tag {
    seL4_Fault_NullFault = 0,
    seL4_Fault_CapFault = 1,
    seL4_Fault_UnknownSyscall = 2,
    seL4_Fault_UserException = 3,
    seL4_Fault_VMFault = 5
};
typedef enum seL4_Fault_tag seL4_Fault_tag_t;

static inline uint64_t __attribute__((__const__))
seL4_Fault_get_seL4_FaultType(seL4_Fault_t seL4_Fault) {
    return (seL4_Fault.words[0] >> 0) & 0x7ull;
}

static inline uint64_t __attribute__((__pure__))
seL4_Fault_ptr_get_seL4_FaultType(seL4_Fault_t *seL4_Fault_ptr) {
    return (seL4_Fault_ptr->words[0] >> 0) & 0x7ull;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_NullFault_new(void) {
    seL4_Fault_t seL4_Fault;


    if(!(((uint64_t)seL4_Fault_NullFault & ~0x7ull) == ((0 && ((uint64_t)seL4_Fault_NullFault & (1ull << 50))) ? 0x0 : 0))) _assert_fail("((uint64_t)seL4_Fault_NullFault & ~0x7ull) == ((0 && ((uint64_t)seL4_Fault_NullFault & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4701, __FUNCTION__);

    seL4_Fault.words[0] = 0
        | ((uint64_t)seL4_Fault_NullFault & 0x7ull) << 0;
    seL4_Fault.words[1] = 0;

    return seL4_Fault;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_CapFault_new(uint64_t address, uint64_t inReceivePhase) {
    seL4_Fault_t seL4_Fault;


    if(!((inReceivePhase & ~0x1ull) == ((0 && (inReceivePhase & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(inReceivePhase & ~0x1ull) == ((0 && (inReceivePhase & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4715, __FUNCTION__);
    if(!(((uint64_t)seL4_Fault_CapFault & ~0x7ull) == ((0 && ((uint64_t)seL4_Fault_CapFault & (1ull << 50))) ? 0x0 : 0))) _assert_fail("((uint64_t)seL4_Fault_CapFault & ~0x7ull) == ((0 && ((uint64_t)seL4_Fault_CapFault & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4716, __FUNCTION__);

    seL4_Fault.words[0] = 0
        | (inReceivePhase & 0x1ull) << 63
        | ((uint64_t)seL4_Fault_CapFault & 0x7ull) << 0;
    seL4_Fault.words[1] = 0
        | address << 0;

    return seL4_Fault;
}

static inline uint64_t __attribute__((__const__))
seL4_Fault_CapFault_get_address(seL4_Fault_t seL4_Fault) {
    uint64_t ret;
    if(!(((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_CapFault)) _assert_fail("((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_CapFault",
                              "./arch/object/structures_gen.h"
    ,
                              4731
    , __FUNCTION__)
                               ;

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
seL4_Fault_CapFault_get_inReceivePhase(seL4_Fault_t seL4_Fault) {
    uint64_t ret;
    if(!(((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_CapFault)) _assert_fail("((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_CapFault",
                              "./arch/object/structures_gen.h"
    ,
                              4745
    , __FUNCTION__)
                               ;

    ret = (seL4_Fault.words[0] & 0x8000000000000000ull) >> 63;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_new(uint64_t syscallNumber) {
    seL4_Fault_t seL4_Fault;


    if(!(((uint64_t)seL4_Fault_UnknownSyscall & ~0x7ull) == ((0 && ((uint64_t)seL4_Fault_UnknownSyscall & (1ull << 50))) ? 0x0 : 0))) _assert_fail("((uint64_t)seL4_Fault_UnknownSyscall & ~0x7ull) == ((0 && ((uint64_t)seL4_Fault_UnknownSyscall & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4760, __FUNCTION__);

    seL4_Fault.words[0] = 0
        | ((uint64_t)seL4_Fault_UnknownSyscall & 0x7ull) << 0;
    seL4_Fault.words[1] = 0
        | syscallNumber << 0;

    return seL4_Fault;
}

static inline uint64_t __attribute__((__const__))
seL4_Fault_UnknownSyscall_get_syscallNumber(seL4_Fault_t seL4_Fault) {
    uint64_t ret;
    if(!(((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_UnknownSyscall)) _assert_fail("((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_UnknownSyscall",
                                    "./arch/object/structures_gen.h"
    ,
                                    4774
    , __FUNCTION__)
                                     ;

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_UserException_new(uint64_t number, uint64_t code) {
    seL4_Fault_t seL4_Fault;


    if(!((number & ~0xffffffffull) == ((0 && (number & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(number & ~0xffffffffull) == ((0 && (number & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4789, __FUNCTION__);
    if(!((code & ~0x1fffffffull) == ((0 && (code & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(code & ~0x1fffffffull) == ((0 && (code & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4790, __FUNCTION__);
    if(!(((uint64_t)seL4_Fault_UserException & ~0x7ull) == ((0 && ((uint64_t)seL4_Fault_UserException & (1ull << 50))) ? 0x0 : 0))) _assert_fail("((uint64_t)seL4_Fault_UserException & ~0x7ull) == ((0 && ((uint64_t)seL4_Fault_UserException & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4791, __FUNCTION__);

    seL4_Fault.words[0] = 0
        | (number & 0xffffffffull) << 32
        | (code & 0x1fffffffull) << 3
        | ((uint64_t)seL4_Fault_UserException & 0x7ull) << 0;
    seL4_Fault.words[1] = 0;

    return seL4_Fault;
}

static inline uint64_t __attribute__((__const__))
seL4_Fault_UserException_get_number(seL4_Fault_t seL4_Fault) {
    uint64_t ret;
    if(!(((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_UserException)) _assert_fail("((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_UserException",
                                   "./arch/object/structures_gen.h"
    ,
                                   4806
    , __FUNCTION__)
                                    ;

    ret = (seL4_Fault.words[0] & 0xffffffff00000000ull) >> 32;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
seL4_Fault_UserException_get_code(seL4_Fault_t seL4_Fault) {
    uint64_t ret;
    if(!(((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_UserException)) _assert_fail("((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_UserException",
                                   "./arch/object/structures_gen.h"
    ,
                                   4820
    , __FUNCTION__)
                                    ;

    ret = (seL4_Fault.words[0] & 0xfffffff8ull) >> 3;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline seL4_Fault_t __attribute__((__const__))
seL4_Fault_VMFault_new(uint64_t address, uint64_t FSR, uint64_t instructionFault) {
    seL4_Fault_t seL4_Fault;


    if(!((FSR & ~0x1full) == ((0 && (FSR & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(FSR & ~0x1full) == ((0 && (FSR & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4835, __FUNCTION__);
    if(!((instructionFault & ~0x1ull) == ((0 && (instructionFault & (1ull << 50))) ? 0x0 : 0))) _assert_fail("(instructionFault & ~0x1ull) == ((0 && (instructionFault & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4836, __FUNCTION__);
    if(!(((uint64_t)seL4_Fault_VMFault & ~0x7ull) == ((0 && ((uint64_t)seL4_Fault_VMFault & (1ull << 50))) ? 0x0 : 0))) _assert_fail("((uint64_t)seL4_Fault_VMFault & ~0x7ull) == ((0 && ((uint64_t)seL4_Fault_VMFault & (1ull << 50))) ? 0x0 : 0)", "./arch/object/structures_gen.h", 4837, __FUNCTION__);

    seL4_Fault.words[0] = 0
        | (FSR & 0x1full) << 27
        | (instructionFault & 0x1ull) << 19
        | ((uint64_t)seL4_Fault_VMFault & 0x7ull) << 0;
    seL4_Fault.words[1] = 0
        | address << 0;

    return seL4_Fault;
}

static inline uint64_t __attribute__((__const__))
seL4_Fault_VMFault_get_address(seL4_Fault_t seL4_Fault) {
    uint64_t ret;
    if(!(((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_VMFault)) _assert_fail("((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_VMFault",
                             "./arch/object/structures_gen.h"
    ,
                             4853
    , __FUNCTION__)
                              ;

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
seL4_Fault_VMFault_get_FSR(seL4_Fault_t seL4_Fault) {
    uint64_t ret;
    if(!(((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_VMFault)) _assert_fail("((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_VMFault",
                             "./arch/object/structures_gen.h"
    ,
                             4867
    , __FUNCTION__)
                              ;

    ret = (seL4_Fault.words[0] & 0xf8000000ull) >> 27;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}

static inline uint64_t __attribute__((__const__))
seL4_Fault_VMFault_get_instructionFault(seL4_Fault_t seL4_Fault) {
    uint64_t ret;
    if(!(((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_VMFault)) _assert_fail("((seL4_Fault.words[0] >> 0) & 0x7) == seL4_Fault_VMFault",
                             "./arch/object/structures_gen.h"
    ,
                             4881
    , __FUNCTION__)
                              ;

    ret = (seL4_Fault.words[0] & 0x80000ull) >> 19;

    if (0 && (ret & (1ull << (50)))) {
        ret |= 0x0;
    }
    return ret;
}


typedef struct {
    timestamp_t schedule_start_time;
    uint64_t utilisation;
} benchmark_util_t;

enum irq_state {
    IRQInactive = 0,
    IRQSignal = 1,
    IRQTimer = 2,

    IRQIPI = 3,

    IRQReserved
};
typedef word_t irq_state_t;

typedef struct dschedule {
    dom_t domain;
    word_t length;
} dschedule_t;


enum endpoint_state {
    EPState_Idle = 0,
    EPState_Send = 1,
    EPState_Recv = 2
};
typedef word_t endpoint_state_t;

enum notification_state {
    NtfnState_Idle = 0,
    NtfnState_Waiting = 1,
    NtfnState_Active = 2
};
typedef word_t notification_state_t;
static inline cap_t __attribute__((__const__))
Zombie_new(word_t number, word_t type, word_t ptr)
{
    word_t mask;

    if (type == (1ul << (6))) {
        mask = ((1ul << (4 + 1))-1ul);
    } else {
        mask = ((1ul << (type + 1))-1ul);
    }

    return cap_zombie_cap_new((ptr & ~mask) | (number & mask), type);
}

static inline word_t __attribute__((__const__))
cap_zombie_cap_get_capZombieBits(cap_t cap)
{
    word_t type = cap_zombie_cap_get_capZombieType(cap);
    if (type == (1ul << (6))) {
        return 4;
    }
    return ((type) & ((1ul << (6))-1ul));
}

static inline word_t __attribute__((__const__))
cap_zombie_cap_get_capZombieNumber(cap_t cap)
{
    word_t radix = cap_zombie_cap_get_capZombieBits(cap);
    return cap_zombie_cap_get_capZombieID(cap) & ((1ul << (radix + 1))-1ul);
}

static inline word_t __attribute__((__const__))
cap_zombie_cap_get_capZombiePtr(cap_t cap)
{
    word_t radix = cap_zombie_cap_get_capZombieBits(cap);
    return cap_zombie_cap_get_capZombieID(cap) & ~((1ul << (radix + 1))-1ul);
}

static inline cap_t __attribute__((__const__))
cap_zombie_cap_set_capZombieNumber(cap_t cap, word_t n)
{
    word_t radix = cap_zombie_cap_get_capZombieBits(cap);
    word_t ptr = cap_zombie_cap_get_capZombieID(cap) & ~((1ul << (radix + 1))-1ul);
    return cap_zombie_cap_set_capZombieID(cap, ptr | (n & ((1ul << (radix + 1))-1ul)));
}


struct cte {
    cap_t cap;
    mdb_node_t cteMDBNode;
};
typedef struct cte cte_t;




enum _thread_state {
    ThreadState_Inactive = 0,
    ThreadState_Running,
    ThreadState_Restart,
    ThreadState_BlockedOnReceive,
    ThreadState_BlockedOnSend,
    ThreadState_BlockedOnReply,
    ThreadState_BlockedOnNotification,

    ThreadState_RunningVM,

    ThreadState_IdleThreadState
};
typedef word_t _thread_state_t;



enum tcb_cnode_index {

    tcbCTable = 0,


    tcbVTable = 1,


    tcbReply = 2,


    tcbCaller = 3,


    tcbBuffer = 4,

    tcbCNodeEntries
};
typedef word_t tcb_cnode_index_t;








typedef int __assert_failed_seL4_PageTableEntryBitsseL4_PageTableIndexBitsseL4_PageTableBits[(3 + 9 == 12) ? 1 : -1];;
typedef int __assert_failed_seL4_PageDirEntryBitsseL4_PageDirIndexBitsseL4_PageDirBits[(3 + 9 == 12) ? 1 : -1];;
typedef int __assert_failed_seL4_PDPTEntryBitsseL4_PDPTIndexBitsseL4_PDPTBits[(3 + 9 == 12) ? 1 : -1];;
typedef int __assert_failed_seL4_PML4EntryBitsseL4_PML4IndexBitsseL4_PML4Bits[(3 + 9 == 12) ? 1 : -1];;
typedef int __assert_failed_seL4_WordSizeBitsseL4_ASIDPoolIndexBitsseL4_ASIDPoolBits[(3 + 9 == 12) ? 1 : -1];;

enum {
    seL4_VMFault_IP,
    seL4_VMFault_Addr,
    seL4_VMFault_PrefetchFault,
    seL4_VMFault_FSR,
    seL4_VMFault_Length,
    _enum_pad_seL4_VMFault_Msg = (1ULL << ((sizeof(long)*8) - 1)) - 1,
};

enum {
    seL4_UnknownSyscall_RAX,
    seL4_UnknownSyscall_RBX,
    seL4_UnknownSyscall_RCX,
    seL4_UnknownSyscall_RDX,
    seL4_UnknownSyscall_RSI,
    seL4_UnknownSyscall_RDI,
    seL4_UnknownSyscall_RBP,
    seL4_UnknownSyscall_R8,
    seL4_UnknownSyscall_R9,
    seL4_UnknownSyscall_R10,
    seL4_UnknownSyscall_R11,
    seL4_UnknownSyscall_R12,
    seL4_UnknownSyscall_R13,
    seL4_UnknownSyscall_R14,
    seL4_UnknownSyscall_R15,
    seL4_UnknownSyscall_FaultIP,
    seL4_UnknownSyscall_SP,
    seL4_UnknownSyscall_FLAGS,
    seL4_UnknownSyscall_Syscall,
    seL4_UnknownSyscall_Length,
    _enum_pad_seL4_UnknownSyscall_Msg = (1ULL << ((sizeof(long)*8) - 1)) - 1
};

enum {
    seL4_UserException_FaultIP,
    seL4_UserException_SP,
    seL4_UserException_FLAGS,
    seL4_UserException_Number,
    seL4_UserException_Code,
    seL4_UserException_Length,
    _enum_pad_seL4_UserException_Msg = (1ULL << ((sizeof(long)*8) - 1)) - 1
};






enum vm_fault_type {
    X86DataFault = 0,
    X86InstructionFault = 1
};

typedef word_t vm_fault_type_t;

enum vm_page_size {
    X86_SmallPage,
    X86_LargePage,
    X64_HugePage
};
typedef word_t vm_page_size_t;

enum frameSizeConstants {
    X64SmallPageBits = 12,
    X64LargePageBits = 21,
    X64HugePageBits = 30
};

enum vm_page_map_type {
    X86_MappingNone = 0,
    X86_MappingVSpace,




    X86_MappingEPT

};
typedef word_t vm_page_map_type_t;



static inline word_t __attribute__((__const__))
pageBitsForSize(vm_page_size_t pagesize)
{
    switch (pagesize) {
    case X86_SmallPage:
        return 12;

    case X86_LargePage:
        return 21;

    case X64_HugePage:
        return 30;

    default:
        _fail("Invalid page size", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/arch/x86/arch/machine/hardware.h", 73, __func__);
    }
}





__attribute__((__section__(".phys.text")))
static inline word_t __attribute__((__const__))
pageBitsForSize_phys(vm_page_size_t pagesize)
{
    switch (pagesize) {
    case X86_SmallPage:
        return 12;

    case X86_LargePage:
        return 21;

    case X64_HugePage:
        return 30;

    default:
        _fail("Invalid page size", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/arch/x86/arch/machine/hardware.h", 96, __func__);
    }
}


uint32_t __attribute__((__const__)) getCacheLineSize(void);
uint32_t __attribute__((__const__)) getCacheLineSizeBits(void);


static inline void flushCacheLine(volatile void* vaddr)
{
    __asm__ volatile ("clflush %[vaddr]" : [vaddr] "+m"(*((volatile char *)vaddr)));
}

void flushCacheRange(void* vaddr, uint32_t size_bits);


bool_t disablePrefetchers(void);


__attribute__((__section__(".boot.text"))) void enablePMCUser(void);


static inline void x86_wbinvd(void)
{
    __asm__ volatile("wbinvd" ::: "memory");
}

static inline void
arch_clean_invalidate_caches(void)
{
    x86_wbinvd();
}


bool_t init_ibrs(void);

enum _register {




    RDI = 0,
    capRegister = 0,
    badgeRegister = 0,
    RSI = 1,
    msgInfoRegister = 1,
    RAX = 2,
    RBX = 3,
    RBP = 4,
    R12 = 5,
    R13 = 6,
    R14 = 7,
    RDX = 8,

    R10 = 9,
    R8 = 10,
    R9 = 11,
    R15 = 12,
    FLAGS = 13,


    NextIP = 14,

    Error = 15,
    RSP = 16,

    TLS_BASE = 17,
    FaultIP = 18,

    R11 = 19,
    RCX = 20,
    CS = 21,
    SS = 22,

    n_contextRegisters = 23
};

typedef uint32_t register_t;

enum messageSizes {
    n_msgRegisters = 4,
    n_frameRegisters = 18,
    n_gpRegisters = 1,
    n_exceptionMessage = 3,
    n_syscallMessage = 18
};
extern const register_t msgRegisters[];
extern const register_t frameRegisters[];
extern const register_t gpRegisters[];

struct user_fpu_state {
    uint8_t state[512];
};
typedef struct user_fpu_state user_fpu_state_t;


struct user_context {
    user_fpu_state_t fpuState;
    word_t registers[n_contextRegisters];







};
typedef struct user_context user_context_t;

void Mode_initContext(user_context_t* context);
void Arch_initContext(user_context_t* context);
word_t Mode_sanitiseRegister(register_t reg, word_t v);

enum tcb_arch_cnode_index {

    tcbArchEPTRoot = tcbCNodeEntries,
    tcbArchCNodeEntries
};

typedef struct arch_tcb {
    user_context_t tcbContext;



    struct vcpu *tcbVCPU;

} arch_tcb_t;

struct user_data {
    word_t words[(1ul << (12)) / sizeof(word_t)];
};

typedef struct user_data user_data_t;

struct user_data_device {
    word_t words[(1ul << (12)) / sizeof(word_t)];
};

typedef struct user_data_device user_data_device_t;
typedef int __assert_failed_vtd_pt_size_sane[(9 + 3 == 12) ? 1 : -1];
struct rdmsr_safe_result {
    uint64_t value;
    bool_t success;
};

typedef struct rdmsr_safe_result rdmsr_safe_result_t;


typedef struct gdt_idt_ptr {
    uint16_t limit;
    word_t base;
} __attribute__((packed)) gdt_idt_ptr_t;

enum vm_rights {
    VMKernelOnly = 1,
    VMReadOnly = 2,
    VMReadWrite = 3
};
typedef word_t vm_rights_t;

typedef int __assert_failed_gdt_idt_ptr_packed[(sizeof(gdt_idt_ptr_t) == sizeof(uint16_t) * 5) ? 1 : -1];


typedef int __assert_failed_unsigned_long_size_64[(sizeof(unsigned long) == 8) ? 1 : -1];


typedef int __assert_failed_unsinged_int_size_32[(sizeof(unsigned int) == 4) ? 1 : -1];


typedef int __assert_failed_uint64_t_size_64[(sizeof(uint64_t) == 8) ? 1 : -1];
typedef pml4e_t vspace_root_t;





enum asidSizeConstants {
    asidHighBits = 3,
    asidLowBits = 9
};

struct asid_pool {
    asid_map_t array[(1ul << (asidLowBits))];
};

typedef struct asid_pool asid_pool_t;
static inline asid_t __attribute__((__pure__))
cap_get_capMappedASID(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {

    case cap_pml4_cap:
        return cap_pml4_cap_get_capPML4MappedASID(cap);

    case cap_pdpt_cap:
        return cap_pdpt_cap_get_capPDPTMappedASID(cap);

    case cap_page_directory_cap:
        return cap_page_directory_cap_get_capPDMappedASID(cap);


    case cap_ept_pml4_cap:
        return cap_ept_pml4_cap_get_capPML4MappedASID(cap);


    default:
        _fail("Invalid arch cap type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/arch/x86/arch/64/mode/object/structures.h", 150, __func__);
    }
}

static inline word_t __attribute__((__const__))
cap_get_modeCapSizeBits(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_pml4_cap:
        return 12;

    case cap_pdpt_cap:
        return 12;

    default:
        return 0;
    }
}

static inline bool_t __attribute__((__const__))
cap_get_modeCapIsPhysical(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {

    case cap_pml4_cap:
        return true;

    case cap_pdpt_cap:
        return true;

    default:
        return false;
    }
}

static inline void * __attribute__((__const__))
cap_get_modeCapPtr(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_pml4_cap:
        return ((pml4e_t *)(cap_pml4_cap_get_capPML4BasePtr(cap)));

    case cap_pdpt_cap:
        return ((pdpte_t *)(cap_pdpt_cap_get_capPDPTBasePtr(cap)));

    default:
        return ((void *)0);
    }
}

static inline word_t __attribute__((__const__))
cap_get_archCapSizeBits(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_frame_cap:
        return pageBitsForSize(cap_frame_cap_get_capFSize(cap));

    case cap_page_table_cap:
        return 12;

    case cap_page_directory_cap:
        return 12;

    case cap_io_port_cap:
        return 0;
    case cap_asid_control_cap:
        return 0;

    case cap_asid_pool_cap:
        return 12;


    case cap_vcpu_cap:
        return 14;

    case cap_ept_pml4_cap:
        return (3 + 9);
    case cap_ept_pdpt_cap:
        return (3 + 9);
    case cap_ept_pd_cap:
        return (3 + 9);
    case cap_ept_pt_cap:
        return (3 + 9);


    default:
        return cap_get_modeCapSizeBits(cap);
    }
}

static inline bool_t __attribute__((__const__))
cap_get_archCapIsPhysical(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {

    case cap_frame_cap:
        return true;

    case cap_page_table_cap:
        return true;

    case cap_page_directory_cap:
        return true;

    case cap_io_port_cap:
        return false;
    case cap_asid_control_cap:
        return false;

    case cap_asid_pool_cap:
        return true;


    case cap_ept_pt_cap:
        return true;

    case cap_ept_pd_cap:
        return true;

    case cap_ept_pdpt_cap:
        return true;

    case cap_ept_pml4_cap:
        return true;


    default:
        return cap_get_modeCapIsPhysical(cap);
    }
}

static inline void * __attribute__((__const__))
cap_get_archCapPtr(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {

    case cap_frame_cap:
        return (void *)(cap_frame_cap_get_capFBasePtr(cap));

    case cap_page_table_cap:
        return ((pde_t *)(cap_page_table_cap_get_capPTBasePtr(cap)));

    case cap_page_directory_cap:
        return ((pte_t *)(cap_page_directory_cap_get_capPDBasePtr(cap)));

    case cap_io_port_cap:
        return ((void *)0);
    case cap_asid_control_cap:
        return ((void *)0);

    case cap_asid_pool_cap:
        return ((asid_pool_t*)cap_asid_pool_cap_get_capASIDPool(cap));


    case cap_ept_pt_cap:
        return ((ept_pte_t *)(cap_ept_pt_cap_get_capPTBasePtr(cap)));

    case cap_ept_pd_cap:
        return ((ept_pde_t *)(cap_ept_pd_cap_get_capPDBasePtr(cap)));

    case cap_ept_pdpt_cap:
        return ((ept_pdpte_t *)(cap_ept_pdpt_cap_get_capPDPTBasePtr(cap)));

    case cap_ept_pml4_cap:
        return ((ept_pml4e_t *)(cap_ept_pml4_cap_get_capPML4BasePtr(cap)));


    default:
        return cap_get_modeCapPtr(cap);
    }
}

static inline word_t __attribute__((__const__))
wordFromVMRights(vm_rights_t vm_rights)
{
    return (word_t)vm_rights;
}

static inline vm_rights_t __attribute__((__const__))
vmRightsFromWord(word_t w)
{
    return (vm_rights_t)w;
}

static inline vm_attributes_t __attribute__((__const__))
vmAttributesFromWord(word_t w)
{
    vm_attributes_t attr;

    attr.words[0] = w;
    return attr;
}


struct tcb {

    arch_tcb_t tcbArch;


    thread_state_t tcbState;




    notification_t *tcbBoundNotification;


    seL4_Fault_t tcbFault;


    lookup_fault_t tcbLookupFailure;


    dom_t tcbDomain;


    prio_t tcbMCP;


    prio_t tcbPriority;


    word_t tcbTimeSlice;


    cptr_t tcbFaultHandler;


    word_t tcbIPCBuffer;



    word_t tcbAffinity;



    struct tcb* tcbSchedNext;
    struct tcb* tcbSchedPrev;

    struct tcb* tcbEPNext;
    struct tcb* tcbEPPrev;


    benchmark_util_t benchmark;





    struct tcb *tcbDebugNext;
    struct tcb *tcbDebugPrev;

    char tcbName[];

};
typedef struct tcb tcb_t;


typedef int __assert_failed_cte_size_sane[(sizeof(cte_t) <= (1ul << (5))) ? 1 : -1];
typedef int __assert_failed_tcb_cte_size_sane[((4 + 5) <= (11 - 1)) ? 1 : -1];
typedef int __assert_failed_tcb_size_sane[((1ul << ((11 - 1))) >= sizeof(tcb_t)) ? 1 : -1];

typedef int __assert_failed_tcb_size_not_excessive[((1ul << ((11 - 1) - 1)) < sizeof(tcb_t)) ? 1 : -1];

typedef int __assert_failed_ep_size_sane[(sizeof(endpoint_t) <= (1ul << (4))) ? 1 : -1];
typedef int __assert_failed_notification_size_sane[(sizeof(notification_t) <= (1ul << (5))) ? 1 : -1];


typedef int __assert_failed_ipc_buf_size_sane[(sizeof(seL4_IPCBuffer) == (1ul << (10))) ? 1 : -1];



static inline word_t __attribute__((__const__))
isArchCap(cap_t cap)
{
    return (cap_get_capType(cap) % 2);
}

static inline word_t __attribute__((__const__))
cap_get_capSizeBits(cap_t cap)
{

    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_untyped_cap:
        return cap_untyped_cap_get_capBlockSize(cap);

    case cap_endpoint_cap:
        return 4;

    case cap_notification_cap:
        return 5;

    case cap_cnode_cap:
        return cap_cnode_cap_get_capCNodeRadix(cap) + 5;

    case cap_thread_cap:
        return 11;

    case cap_zombie_cap: {
        word_t type = cap_zombie_cap_get_capZombieType(cap);
        if (type == (1ul << (6))) {
            return 11;
        }
        return ((type) & ((1ul << (6))-1ul)) + 5;
    }

    case cap_null_cap:
        return 0;

    case cap_domain_cap:
        return 0;

    case cap_reply_cap:
        return 0;

    case cap_irq_control_cap:
        return 0;

    case cap_irq_handler_cap:
        return 0;

    default:
        return cap_get_archCapSizeBits(cap);
    }

}




static inline bool_t __attribute__((__const__))
cap_get_capIsPhysical(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_untyped_cap:
        return true;

    case cap_endpoint_cap:
        return true;

    case cap_notification_cap:
        return true;

    case cap_cnode_cap:
        return true;

    case cap_thread_cap:
        return true;

    case cap_zombie_cap:
        return true;

    case cap_domain_cap:
        return false;

    case cap_reply_cap:
        return false;

    case cap_irq_control_cap:
        return false;

    case cap_irq_handler_cap:
        return false;

    default:
        return cap_get_archCapIsPhysical(cap);
    }
}

static inline void * __attribute__((__const__))
cap_get_capPtr(cap_t cap)
{
    cap_tag_t ctag;

    ctag = cap_get_capType(cap);

    switch (ctag) {
    case cap_untyped_cap:
        return ((word_t *)(cap_untyped_cap_get_capPtr(cap)));

    case cap_endpoint_cap:
        return ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(cap)));

    case cap_notification_cap:
        return ((notification_t *)(cap_notification_cap_get_capNtfnPtr(cap)));

    case cap_cnode_cap:
        return ((cte_t *)(cap_cnode_cap_get_capCNodePtr(cap)));

    case cap_thread_cap:
        return (((cte_t *)((word_t)(cap_thread_cap_get_capTCBPtr(cap))&~((1ul << (11))-1ul)))+(0));

    case cap_zombie_cap:
        return ((cte_t *)(cap_zombie_cap_get_capZombiePtr(cap)));

    case cap_domain_cap:
        return ((void *)0);

    case cap_reply_cap:
        return ((void *)0);

    case cap_irq_control_cap:
        return ((void *)0);

    case cap_irq_handler_cap:
        return ((void *)0);
    default:
        return cap_get_archCapPtr(cap);

    }
}

struct pde_range {
    pde_t *base;
    word_t length;
};
typedef struct pde_range pde_range_t;

struct pte_range {
    pte_t *base;
    word_t length;
};
typedef struct pte_range pte_range_t;

typedef cte_t *cte_ptr_t;

struct extra_caps {
    cte_ptr_t excaprefs[((1ul<<(seL4_MsgExtraCapBits))-1)];
};
typedef struct extra_caps extra_caps_t;

word_t setMRs_fault(tcb_t *sender, tcb_t* receiver, word_t *receiveIPCBuffer);
word_t Arch_setMRs_fault(tcb_t *sender, tcb_t* receiver, word_t *receiveIPCBuffer, word_t faultType);

bool_t handleFaultReply(tcb_t *receiver, tcb_t *sender);
bool_t Arch_handleFaultReply(tcb_t *receiver, tcb_t *sender, word_t faultType);
typedef enum _interrupt_t {
    int_invalid = -1,
    int_debug = 1,
    int_software_break_request = 3,
    int_unimpl_dev = 7,
    int_gp_fault = 13,
    int_page_fault = 14,
    int_irq_min = 0x20,
    int_irq_isa_min = 0x20,
    int_irq_isa_max = 0x20 + 16 - 1,
    int_irq_user_min = 0x20 + 16,
    int_irq_user_max = 155,



    int_timer = 157,

    int_remote_call_ipi = 158,
    int_reschedule_ipi = 159,
    int_irq_max = 159,



    int_trap_min,
    int_trap_max = 254,
    int_spurious = 255,
    int_max = 255
} interrupt_t;

typedef enum _platform_irq_t {
    irq_isa_min = int_irq_isa_min - 0x20,
    irq_isa_max = int_irq_isa_max - 0x20,
    irq_user_min = int_irq_user_min - 0x20,
    irq_user_max = int_irq_user_max - 0x20,



    irq_timer = int_timer - 0x20,

    irq_remote_call_ipi = int_remote_call_ipi - 0x20,
    irq_reschedule_ipi = int_reschedule_ipi - 0x20,

    maxIRQ = int_irq_max - 0x20,



    irqInvalid = 255,
} platform_irq_t;

typedef uint8_t irq_t;

typedef enum {
    MessageID_Syscall,
    MessageID_Exception
} MessageID_t;


extern const register_t fault_messages[][(((n_syscallMessage)>(n_exceptionMessage))?(n_syscallMessage):(n_exceptionMessage))] __attribute__((externally_visible));

static inline void
setRegister(tcb_t *thread, register_t reg, word_t w)
{
    thread->tcbArch.tcbContext.registers[reg] = w;
}

static inline word_t __attribute__((__pure__))
getRegister(tcb_t *thread, register_t reg)
{
    return thread->tcbArch.tcbContext.registers[reg];
}

typedef enum {
    seL4_NoError = 0,
    seL4_InvalidArgument,
    seL4_InvalidCapability,
    seL4_IllegalOperation,
    seL4_RangeError,
    seL4_AlignmentError,
    seL4_FailedLookup,
    seL4_TruncatedMessage,
    seL4_DeleteFirst,
    seL4_RevokeFirst,
    seL4_NotEnoughMemory,





    seL4_NumErrors
} seL4_Error;




enum exception {
    EXCEPTION_NONE,
    EXCEPTION_FAULT,
    EXCEPTION_LOOKUP_FAULT,
    EXCEPTION_SYSCALL_ERROR,
    EXCEPTION_PREEMPTED
};
typedef word_t exception_t;

typedef word_t syscall_error_type_t;

struct syscall_error {
    word_t invalidArgumentNumber;
    word_t invalidCapNumber;
    word_t rangeErrorMin;
    word_t rangeErrorMax;
    word_t memoryLeft;
    bool_t failedLookupWasSource;

    syscall_error_type_t type;
};
typedef struct syscall_error syscall_error_t;

extern lookup_fault_t current_lookup_fault;
extern seL4_Fault_t current_fault;
extern syscall_error_t current_syscall_error;

enum exit_reasons {
    EXCEPTION_OR_NMI = 0x00,
    EXTERNAL_INTERRUPT = 0x01,
    TRIPLE_FAULT = 0x02,
    INIT_SIGNAL = 0x03,
    SIPI = 0x04,


    INTERRUPT_WINDOW = 0x07,
    NMI_WINDOW = 0x08,
    TASK_SWITCH = 0x09,
    CPUID = 0x0A,
    GETSEC = 0x0B,
    HLT = 0x0C,
    INVD = 0x0D,
    INVLPG = 0x0E,
    RDPMC = 0x0F,
    RDTSC = 0x10,
    RSM = 0x11,
    VMCALL = 0x12,
    VMCLEAR = 0x13,
    VMLAUNCH = 0x14,
    VMPTRLD = 0x15,
    VMPTRST = 0x16,
    VMREAD = 0x17,
    VMRESUME = 0x18,
    VMWRITE = 0x19,
    VMXOFF = 0x1A,
    VMXON = 0x1B,
    CONTROL_REGISTER = 0x1C,
    MOV_DR = 0x1D,
    IO = 0x1E,
    RDMSR = 0x1F,
    WRMSR = 0x20,
    INVALID_GUEST_STATE = 0x21,
    MSR_LOAD_FAIL = 0x22,

    MWAIT = 0x24,
    MONITOR_TRAP_FLAG = 0x25,

    MONITOR = 0x27,
    PAUSE = 0x28,
    MACHINE_CHECK = 0x29,

    TPR_BELOW_THRESHOLD = 0x2B,
    APIC_ACCESS = 0x2C,
    GDTR_OR_IDTR = 0x2E,
    LDTR_OR_TR = 0x2F,
    EPT_VIOLATION = 0x30,
    EPT_MISCONFIGURATION = 0x31,
    INVEPT = 0x32,
    RDTSCP = 0x33,
    VMX_PREEMPTION_TIMER = 0x34,
    INVVPID = 0x35,
    WBINVD = 0x36,
    XSETBV = 0x37
};





typedef uint16_t vpid_t;




enum vcpu_gp_register {
    VCPU_EAX = 0,
    VCPU_EBX,
    VCPU_ECX,
    VCPU_EDX,
    VCPU_ESI,
    VCPU_EDI,
    VCPU_EBP,
    n_vcpu_gp_register,


    VCPU_ESP,
};

typedef enum vcpu_gp_register vcpu_gp_register_t;;

const vcpu_gp_register_t crExitRegs[];

struct vcpu {


    char vmcs[4096];
    word_t io[8192 / sizeof(word_t)];


    user_fpu_state_t fpuState;



    word_t gp_registers[n_vcpu_gp_register];





    struct tcb *vcpuTCB;
    bool_t launched;


    vpid_t vpid;






    word_t cr0;




    word_t cr0_shadow;
    word_t cr0_mask;
    word_t exception_bitmap;



    word_t cached_exception_bitmap;
    word_t cached_cr0_shadow;
    word_t cached_cr0_mask;
    word_t cached_cr0;


    word_t last_ept_root;



    word_t last_host_cr3;




    word_t last_cpu;

};
typedef struct vcpu vcpu_t;

typedef int __assert_failed_vcpu_size_sane[(sizeof(vcpu_t) <= (1ul << (14))) ? 1 : -1];





bool_t vcpu_init(vcpu_t *vcpu);


void vcpu_finalise(vcpu_t *vcpu);

exception_t decodeX86VCPUInvocation(
    word_t invLabel,
    word_t length,
    cptr_t cptr,
    cte_t* slot,
    cap_t cap,
    extra_caps_t excaps,
    word_t* buffer
);



void vcpu_update_state_sysvmenter(vcpu_t *vcpu);

void vcpu_sysvmenter_reply_to_user(tcb_t *tcb);

bool_t vtx_init(void);
exception_t handleVmexit(void);
exception_t handleVmEntryFail(void);
void restoreVMCS(void);
void clearCurrentVCPU(void);


void VMCheckBoundNotification(tcb_t *tcb);


void invept(ept_pml4e_t *ept_pml4);


void clearVPIDIOPortMappings(vpid_t vpid, uint16_t first, uint16_t last);

static inline word_t
vmread(word_t field)
{
    word_t value;
    __asm__ volatile (
        "vmread %1, %0"
        : "=r"(value)
        : "r"(field)
        : "cc"
    );
    return value;
}


static inline void
vmwrite(word_t field, word_t value)
{
    __asm__ volatile (
        "vmwrite %0, %1"
        :
        : "r"(value), "r"(field)
        : "cc"
    );
}



struct slot_range {
    cte_t *cnode;
    word_t offset;
    word_t length;
};
typedef struct slot_range slot_range_t;

exception_t decodeCNodeInvocation(word_t invLabel, word_t length,
                                  cap_t cap, extra_caps_t excaps,
                                  word_t *buffer);
exception_t invokeCNodeRevoke(cte_t *destSlot);
exception_t invokeCNodeDelete(cte_t *destSlot);
exception_t invokeCNodeCancelBadgedSends(cap_t cap);
exception_t invokeCNodeInsert(cap_t cap, cte_t *srcSlot, cte_t *destSlot);
exception_t invokeCNodeMove(cap_t cap, cte_t *srcSlot, cte_t *destSlot);
exception_t invokeCNodeRotate(cap_t cap1, cap_t cap2, cte_t *slot1,
                              cte_t *slot2, cte_t *slot3);
exception_t invokeCNodeSaveCaller(cte_t *destSlot);
void cteInsert(cap_t newCap, cte_t *srcSlot, cte_t *destSlot);
void cteMove(cap_t newCap, cte_t *srcSlot, cte_t *destSlot);
void capSwapForDelete(cte_t *slot1, cte_t *slot2);
void cteSwap(cap_t cap1, cte_t *slot1, cap_t cap2, cte_t *slot2);
exception_t cteRevoke(cte_t *slot);
exception_t cteDelete(cte_t *slot, bool_t exposed);
void cteDeleteOne(cte_t* slot);
void insertNewCap(cte_t *parent, cte_t *slot, cap_t cap);
void setupReplyMaster(tcb_t *thread);
bool_t __attribute__((__pure__)) isMDBParentOf(cte_t *cte_a, cte_t *cte_b);
exception_t ensureNoChildren(cte_t *slot);
exception_t ensureEmptySlot(cte_t *slot);
bool_t __attribute__((__pure__)) isFinalCapability(cte_t *cte);
bool_t __attribute__((__pure__)) slotCapLongRunningDelete(cte_t *slot);
cte_t *getReceiveSlots(tcb_t *thread, word_t *buffer);
cap_transfer_t __attribute__((__pure__)) loadCapTransfer(word_t *buffer);




typedef int __assert_failed_tcb_name_fits[(((1ul << (11)) - (1ul << ((11 - 1))) - sizeof(tcb_t)) > 0) ? 1 : -1];


struct tcb_queue {
    tcb_t *head;
    tcb_t *end;
};
typedef struct tcb_queue tcb_queue_t;

static inline unsigned int
setMR(tcb_t *receiver, word_t* receiveIPCBuffer,
      unsigned int offset, word_t reg)
{
    if (offset >= n_msgRegisters) {
        if (receiveIPCBuffer) {
            receiveIPCBuffer[offset + 1] = reg;
            return offset + 1;
        } else {
            return n_msgRegisters;
        }
    } else {
        setRegister(receiver, msgRegisters[offset], reg);
        return offset + 1;
    }
}

void tcbSchedEnqueue(tcb_t *tcb);
void tcbSchedAppend(tcb_t *tcb);
void tcbSchedDequeue(tcb_t *tcb);


void tcbDebugAppend(tcb_t *tcb);
void tcbDebugRemove(tcb_t *tcb);



void remoteQueueUpdate(tcb_t *tcb);
void remoteTCBStall(tcb_t *tcb);
tcb_queue_t tcbEPAppend(tcb_t *tcb, tcb_queue_t queue);
tcb_queue_t tcbEPDequeue(tcb_t *tcb, tcb_queue_t queue);

void setupCallerCap(tcb_t *sender, tcb_t *receiver);
void deleteCallerCap(tcb_t *receiver);

word_t copyMRs(tcb_t *sender, word_t *sendBuf, tcb_t *receiver,
               word_t *recvBuf, word_t n);
exception_t decodeTCBInvocation(word_t invLabel, word_t length, cap_t cap,
                                cte_t* slot, extra_caps_t excaps, bool_t call,
                                word_t *buffer);
exception_t decodeCopyRegisters(cap_t cap, word_t length,
                                extra_caps_t excaps, word_t *buffer);
exception_t decodeReadRegisters(cap_t cap, word_t length, bool_t call,
                                word_t *buffer);
exception_t decodeWriteRegisters(cap_t cap, word_t length, word_t *buffer);
exception_t decodeTCBConfigure(cap_t cap, word_t length,
                               cte_t* slot, extra_caps_t rootCaps, word_t *buffer);
exception_t decodeSetPriority(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer);
exception_t decodeSetMCPriority(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer);
exception_t decodeSetSchedParams(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer);
exception_t decodeSetIPCBuffer(cap_t cap, word_t length,
                               cte_t* slot, extra_caps_t excaps, word_t *buffer);
exception_t decodeSetSpace(cap_t cap, word_t length,
                           cte_t* slot, extra_caps_t excaps, word_t *buffer);
exception_t decodeDomainInvocation(word_t invLabel, word_t length,
                                   extra_caps_t excaps, word_t *buffer);
exception_t decodeBindNotification(cap_t cap, extra_caps_t excaps);
exception_t decodeUnbindNotification(cap_t cap);

enum thread_control_flag {
    thread_control_update_priority = 0x1,
    thread_control_update_ipc_buffer = 0x2,
    thread_control_update_space = 0x4,
    thread_control_update_mcp = 0x8,
};

typedef word_t thread_control_flag_t;

exception_t invokeTCB_Suspend(tcb_t *thread);
exception_t invokeTCB_Resume(tcb_t *thread);
exception_t invokeTCB_ThreadControl(tcb_t *target, cte_t* slot, cptr_t faultep,
                                    prio_t mcp, prio_t priority, cap_t cRoot_newCap,
                                    cte_t *cRoot_srcSlot, cap_t vRoot_newCap,
                                    cte_t *vRoot_srcSlot, word_t bufferAddr,
                                    cap_t bufferCap, cte_t *bufferSrcSlot,
                                    thread_control_flag_t updateFlags);
exception_t invokeTCB_CopyRegisters(tcb_t *dest, tcb_t *src,
                                    bool_t suspendSource, bool_t resumeTarget,
                                    bool_t transferFrame, bool_t transferInteger,
                                    word_t transferArch);
exception_t invokeTCB_ReadRegisters(tcb_t *src, bool_t suspendSource,
                                    word_t n, word_t arch, bool_t call);
exception_t invokeTCB_WriteRegisters(tcb_t *dest, bool_t resumeTarget,
                                     word_t n, word_t arch, word_t *buffer);
exception_t invokeTCB_NotificationControl(tcb_t *tcb, notification_t *ntfnPtr);

cptr_t __attribute__((__pure__)) getExtraCPtr(word_t *bufferPtr, word_t i);
void setExtraBadge(word_t *bufferPtr, word_t badge, word_t i);

exception_t lookupExtraCaps(tcb_t* thread, word_t *bufferPtr, seL4_MessageInfo_t info);
word_t setMRs_syscall_error(tcb_t *thread, word_t *receiveIPCBuffer);
word_t __attribute__((__const__)) Arch_decodeTransfer(word_t flags);
exception_t __attribute__((__const__)) Arch_performTransfer(word_t arch, tcb_t *tcb_src,
                                       tcb_t *tcb_dest);


void Arch_migrateTCB(tcb_t *thread);



void setThreadName(tcb_t *thread, const char *name);


void Arch_setTCBIPCBuffer(tcb_t *thread, word_t bufferAddr);
typedef struct nodeState {
tcb_queue_t ksReadyQueues[(1 * 256)];
word_t ksReadyQueuesL1Bitmap[1];
word_t ksReadyQueuesL2Bitmap[1][((256 + (1 << 6) - 1) / (1 << 6))];
tcb_t *ksCurThread;
tcb_t *ksIdleThread;
tcb_t *ksSchedulerAction;



user_fpu_state_t * ksActiveFPUState;

word_t ksFPURestoresSinceSwitch;


tcb_t * ksDebugTCBs;


} nodeState_t;

extern word_t ksNumCPUs;

extern word_t ksWorkUnitsCompleted;
extern irq_state_t intStateIRQTable[];
extern cte_t *intStateIRQNode;
extern const dschedule_t ksDomSchedule[];
extern const word_t ksDomScheduleLength;
extern word_t ksDomScheduleIdx;
extern dom_t ksCurDomain;
extern word_t ksDomainTime;
extern word_t tlbLockCount __attribute__((externally_visible));

extern pml4e_t x64KSKernelPML4[(1ul << (9))] __attribute__((externally_visible));
extern pdpte_t x64KSKernelPDPT[(1ul << (9))];



extern pde_t x64KSKernelPDs[(1ul << (9))][(1ul << (9))];

extern pte_t x64KSKernelPT[(1ul << (9))];
typedef struct modeNodeState {






cr3_t x64KSCurrentCR3;

} modeNodeState_t;
extern word_t x64KSIRQStack[16][6 + 2] __attribute__((__aligned__(64))) __attribute__((externally_visible)) __attribute__((__section__(".skim.bss")));




typedef struct {
    tss_t tss;
    word_t io_map[(65536 / 8 / sizeof(word_t) + 1)];
} __attribute__((packed)) tss_io_t;

typedef struct archNodeState {

interrupt_t x86KScurInterrupt;


interrupt_t x86KSPendingInterrupt;

word_t ipiReschedulePending;


vcpu_t * x86KSCurrentVCPU;


word_t x86KSCurrentFSBase;
word_t x86KSCurrentGSBase;




word_t x86KSGPExceptReturnTo;

modeNodeState_t mode;
} archNodeState_t;



typedef struct x86_arch_global_state {

    tss_io_t x86KStss;

    gdt_entry_t x86KSgdt[9];

    idt_entry_t x86KSidt[256];
    char padding[64 - ((sizeof(tss_io_t) + 9 * sizeof(gdt_entry_t) + 256 * sizeof(idt_entry_t)) % 64)];
} x86_arch_global_state_t;
typedef int __assert_failed_x86_arch_global_state_padded[((sizeof(x86_arch_global_state_t) % 64) == 0) ? 1 : -1];

extern x86_arch_global_state_t x86KSGlobalState[16] __attribute__((__aligned__(64))) __attribute__((__section__(".skim.bss")));

extern asid_pool_t* x86KSASIDTable[];
extern uint32_t x86KScacheLineSizeBits;
extern user_fpu_state_t x86KSnullFpuState __attribute__((__aligned__(64)));
extern uint16_t x86KSconsolePort;


extern uint16_t x86KSdebugPort;


extern x86_irq_state_t x86KSIRQState[];



static unsigned long control_reg_order;

static inline unsigned long read_cr3(void)
{
    word_t cr3;
    __asm__ volatile ("movq %%cr3, %0" : "=r"(cr3), "=m"(control_reg_order));
    return cr3;
}

static inline void write_cr3(unsigned long val)
{
    __asm__ volatile("movq %0, %%cr3" :: "r"(val), "m"(control_reg_order));
}

static inline unsigned long read_cr0(void)
{
    unsigned long val;
    __asm__ volatile("movq %%cr0, %0" : "=r"(val), "=m"(control_reg_order));
    return val;
}

static inline void write_cr0(unsigned long val)
{
    __asm__ volatile("movq %0, %%cr0" :: "r"(val), "m"(control_reg_order));
}

static inline unsigned long read_cr2(void)
{
    unsigned long val;
    __asm__ volatile("movq %%cr2, %0" : "=r"(val), "=m"(control_reg_order));
    return val;
}

static inline unsigned long read_cr4(void)
{
    unsigned long val;
    __asm__ volatile("movq %%cr4, %0" : "=r"(val), "=m"(control_reg_order));
    return val;
}

static inline void write_cr4(unsigned long val)
{
    __asm__ volatile("movq %0, %%cr4" :: "r"(val), "m"(control_reg_order));
}

static inline void xsetbv(uint32_t reg, uint64_t value)
{
    __asm__ volatile("xsetbv" :: "d"((uint32_t)(value >> 32)), "a"((uint32_t)(value & 0xffffffff)), "c"(reg), "m"(control_reg_order));
}

static inline void write_xcr0(uint64_t value)
{
    xsetbv(0, value);
}



typedef struct smpStatedata {
    archNodeState_t cpu;
    nodeState_t system;
    char padding[64 - ((sizeof(archNodeState_t) + sizeof(nodeState_t)) % 64)];
} smpStatedata_t;

extern smpStatedata_t ksSMP[16];

void migrateTCB(tcb_t *tcb, word_t new_core);



typedef struct nodeInfo {
    void *stackTop;
    void *irqStack;
    word_t currentThreadUserContext;
    cpu_id_t index;
    char padding[64 - ((sizeof(void*) + sizeof(void*) + sizeof(word_t) + sizeof(cpu_id_t)) % 64)];
} nodeInfo_t;
typedef int __assert_failed_nodeInfoIsCacheSized[((sizeof(nodeInfo_t) % 64) == 0) ? 1 : -1];

extern nodeInfo_t node_info[16] __attribute__((__aligned__(64)));
static inline __attribute__((__const__)) cpu_id_t getCurrentCPUIndex(void)
{
    cpu_id_t index;
    __asm__ ("movq %%gs:%c[offset], %[result]"
         : [result] "=r" (index)
         : [offset] "i" (__builtin_offsetof(nodeInfo_t, index)));
    return index;
}

__attribute__((__section__(".boot.text"))) void
mode_init_tls(cpu_id_t cpu_index);



typedef struct cpu_id_mapping {
    cpu_id_t index_to_cpu_id[16];





} cpu_id_mapping_t;

extern cpu_id_mapping_t cpu_mapping;

static inline cpu_id_t cpuIndexToID(word_t index)
{
    return cpu_mapping.index_to_cpu_id[index];
}

static inline __attribute__((__pure__)) word_t getCurrentCPUID(void)
{
    return cpu_mapping.index_to_cpu_id[getCurrentCPUIndex()];
}

static inline bool_t
try_arch_atomic_exchange(void *ptr, void *new_val, void **prev, int success_memorder, int failure_memorder)
{
    *prev = __atomic_exchange_n((void **) ptr, new_val, success_memorder);
    return true;
}






typedef int __assert_failed_user_top_tlbbitmap_no_overlap[(( ((0x7FFFFFFFFFFF) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)) != ( (((0xffffff8000000000ul - ((((16 - 1) / ((1 << 6) - 1)) + 1) * (1ul << (((((12) + 9) + 9) + 9)))))) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul))) ? 1 : -1];







static inline void* __attribute__((__const__))
paddr_to_kpptr(paddr_t paddr)
{
    if(!(paddr < (0xffffffffc0000000ul - 0xffffffff80000000ul))) _assert_fail("paddr < PADDR_HIGH_TOP", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/plat/pc99/plat/64/plat_mode/machine/hardware.h", 91, __FUNCTION__);
    return (void*)(paddr + (0xffffffff80000000ul - 0x00000000ul));
}

static inline paddr_t __attribute__((__const__))
kpptr_to_paddr(void *pptr)
{
    if(!((word_t)pptr >= 0xffffffff80000000ul)) _assert_fail("(word_t)pptr >= KERNEL_BASE", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/plat/pc99/plat/64/plat_mode/machine/hardware.h", 98, __FUNCTION__);
    return (paddr_t)pptr - (0xffffffff80000000ul - 0x00000000ul);
}

static inline cr3_t makeCR3(paddr_t addr, word_t pcid)
{
    return cr3_new(addr, 0 ? pcid : 0);
}


static inline cr3_t getCurrentCR3(void)
{





    return ksSMP[(getCurrentCPUIndex())].cpu.mode.x64KSCurrentCR3;

}

static inline cr3_t getCurrentUserCR3(void)
{
    return getCurrentCR3();

}

static inline paddr_t getCurrentUserVSpaceRoot(void)
{
    return cr3_get_pml4_base_address(getCurrentUserCR3());
}

static inline void setCurrentCR3(cr3_t cr3, word_t preserve_translation)
{






    ksSMP[(getCurrentCPUIndex())].cpu.mode.x64KSCurrentCR3 = cr3;

    word_t cr3_word = cr3.words[0];
    if (0) {
        if (preserve_translation) {
            cr3_word |= (1ul << (63));
        }
    } else {
        if(!(cr3_get_pcid(cr3) == 0)) _assert_fail("cr3_get_pcid(cr3) == 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/arch/x86/arch/64/mode/machine.h", 77, __FUNCTION__);
    }
    write_cr3(cr3_word);
}




static inline void setCurrentUserCR3(cr3_t cr3)
{
    setCurrentCR3(cr3, 1);

}

static inline void setCurrentVSpaceRoot(paddr_t addr, word_t pcid)
{
    setCurrentCR3(makeCR3(addr, pcid), 1);
}

static inline void setCurrentUserVSpaceRoot(paddr_t addr, word_t pcid)
{



    setCurrentVSpaceRoot(addr, pcid);

}


void x64_install_gdt(gdt_idt_ptr_t* gdt_idt_ptr);


void x64_install_idt(gdt_idt_ptr_t* gdt_idt_ptr);


void x64_install_ldt(uint32_t ldt_sel);


void x64_install_tss(uint32_t tss_sel);

void handle_fastsyscall(void);

void init_syscall_msrs(void);


static inline void* get_current_esp(void)
{
    word_t stack;
    void *result;
    __asm__ volatile("movq %[stack_address], %[result]" : [result] "=r"(result) : [stack_address] "r"(&stack));
    return result;
}

typedef struct invpcid_desc {
    uint64_t asid;
    uint64_t addr;
} invpcid_desc_t;






static inline void invalidateLocalPCID(word_t type, void *vaddr, asid_t asid)
{
    if (0) {
        invpcid_desc_t desc;
        desc.asid = asid & 0xfff;
        desc.addr = (uint64_t)vaddr;
        __asm__ volatile ("invpcid %1, %0" :: "r"(type), "m"(desc));
    } else {
        switch (type) {
        case 0:
            __asm__ volatile("invlpg (%[vptr])" :: [vptr] "r"(vaddr));
            break;
        case 1:
        case 3:

            setCurrentCR3(getCurrentCR3(), 0);
            break;
        case 2 : {

            unsigned long cr4 = read_cr4();
            write_cr4(cr4 & ~(1ul << (7)));
            write_cr4(cr4);
        }
        break;
        }
    }
}

static inline void invalidateLocalTranslationSingle(vptr_t vptr)
{



    invalidateLocalPCID(2 , (void*)0, 0);
}

static inline void invalidateLocalTranslationSingleASID(vptr_t vptr, asid_t asid)
{
    invalidateLocalPCID(0, (void*)vptr, asid);
}

static inline void invalidateLocalTranslationAll(void)
{
    invalidateLocalPCID(2 , (void*)0, 0);
}

static inline void invalidateLocalPageStructureCacheASID(paddr_t root, asid_t asid)
{
    if (0) {

        cr3_t cr3 = getCurrentCR3();





        __asm__ volatile(
            "mov %[new_cr3], %%cr3\n"
            "mov %[old_cr3], %%cr3\n"
            ::
            [new_cr3] "r" (makeCR3(root, asid).words[0]),
            [old_cr3] "r" (cr3.words[0] | (1ul << (63)))
        );
    } else {


        __asm__ volatile("invlpg (%[vptr])" :: [vptr] "r"(0));
    }
}

static inline void swapgs(void)
{
    __asm__ volatile("swapgs");
}

static inline rdmsr_safe_result_t x86_rdmsr_safe(const uint32_t reg)
{
    uint32_t low;
    uint32_t high;
    word_t returnto;
    word_t temp;
    rdmsr_safe_result_t result;
    __asm__ volatile(
        "movabs $1f, %[temp] \n"
        "movq %[temp], (%[returnto_addr]) \n         rdmsr \n         1: \n         movq (%[returnto_addr]), %[returnto] \n         movq $0, (%[returnto_addr])"




        : [returnto] "=&r" (returnto),
        [temp] "=&r" (temp),
        [high] "=&d" (high),
        [low] "=&a" (low)
        : [returnto_addr] "r" (&ksSMP[(getCurrentCPUIndex())].cpu.x86KSGPExceptReturnTo),
        [reg] "c" (reg)
        : "memory"
    );
    result.success = returnto != 0;
    result.value = ((uint64_t)high << 32) | (uint64_t)low;
    return result;
}



typedef enum _apic_reg_t {
    APIC_ID = 0x020,
    APIC_VERSION = 0x030,
    APIC_TASK_PRIO = 0x080,
    APIC_ARBITR_PRIO = 0x090,
    APIC_PROC_PRIO = 0x0A0,
    APIC_EOI = 0x0B0,
    APIC_LOGICAL_DEST = 0x0D0,
    APIC_DEST_FORMAT = 0x0E0,
    APIC_SVR = 0x0F0,
    APIC_ISR_BASE = 0x100,
    APIC_TMR_BASE = 0x180,
    APIC_IRR_BASE = 0x200,
    APIC_ERR_STATUS = 0x280,
    APIC_ICR1 = 0x300,
    APIC_ICR2 = 0x310,
    APIC_LVT_TIMER = 0x320,
    APIC_LVT_THERMAL = 0x330,
    APIC_LVT_PERF_CNTR = 0x340,
    APIC_LVT_LINT0 = 0x350,
    APIC_LVT_LINT1 = 0x360,
    APIC_LVT_ERROR = 0x370,
    APIC_TIMER_COUNT = 0x380,
    APIC_TIMER_CURRENT = 0x390,
    APIC_TIMER_DIVIDE = 0x3E0
} apic_reg_t;




static inline uint32_t
apic_read_reg(apic_reg_t reg)
{
    return *(volatile uint32_t*)(0xffffffffc0000000ul + reg);
}

static inline void
apic_write_reg(apic_reg_t reg, uint32_t val)
{
    *(volatile uint32_t*)(0xffffffffc0000000ul + reg) = val;
}

static inline logical_id_t
apic_get_logical_id(void)
{
    return apic_read_reg(APIC_LOGICAL_DEST) >> 24;
}

static inline word_t
apic_get_cluster(logical_id_t logical_id)
{
    return 0;
}

static inline void
apic_write_icr(word_t high, word_t low)
{
    apic_write_reg(APIC_ICR2, high);
    apic_write_reg(APIC_ICR1, low);
}

exception_t Arch_decodeIRQControlInvocation(word_t invLabel, word_t length,
                                            cte_t *srcSlot, extra_caps_t excaps,
                                            word_t *buffer);
void Arch_irqStateInit(void);
exception_t Arch_checkIRQ(word_t irq_w);

exception_t decodeIRQControlInvocation(word_t invLabel, word_t length,
                                       cte_t *srcSlot, extra_caps_t excaps,
                                       word_t *buffer);
exception_t invokeIRQControl(irq_t irq, cte_t *handlerSlot, cte_t *controlSlot);
exception_t decodeIRQHandlerInvocation(word_t invLabel, irq_t irq,
                                       extra_caps_t excaps);
void invokeIRQHandler_AckIRQ(irq_t irq);
void invokeIRQHandler_SetIRQHandler(irq_t irq, cap_t cap, cte_t *slot);
void invokeIRQHandler_ClearIRQHandler(irq_t irq);
void deletingIRQHandler(irq_t irq);
void deletedIRQHandler(irq_t irq);
void handleInterrupt(irq_t irq);
bool_t isIRQActive(irq_t irq);
void setIRQState(irq_state_t irqState, irq_t irq);
word_t __attribute__((__pure__)) getRestartPC(tcb_t *thread);
void setNextPC(tcb_t *thread, word_t v);

static uint64_t x86_rdmsr(const uint32_t reg)
{
    uint32_t low, high;
    uint64_t value;
    __asm__ volatile("rdmsr" : "=a"(low), "=d"(high) : "c"(reg));
    value = ((uint64_t)high << 32) | (uint64_t)low;
    return value;
}


static inline uint32_t x86_rdmsr_low(const uint32_t reg)
{
    return (uint32_t)x86_rdmsr(reg);
}

static inline uint32_t x86_rdmsr_high(const uint32_t reg)
{
    return (uint32_t)(x86_rdmsr(reg) >> 32ull);
}


static inline void x86_wrmsr_parts(const uint32_t reg, const uint32_t high, const uint32_t low)
{
    __asm__ volatile("wrmsr" :: "a"(low), "d"(high), "c"(reg));
}

static inline void x86_wrmsr(const uint32_t reg, const uint64_t val)
{
    uint32_t low = (uint32_t)val;
    uint32_t high = (uint32_t)(val >> 32);
    x86_wrmsr_parts(reg, high, low);
}


static inline uint32_t x86_cpuid_edx(uint32_t eax, uint32_t ecx)
{
    uint32_t edx, ebx;
    __asm__ volatile("cpuid"
                 : "=a" (eax),
                 "=b" (ebx),
                 "=c" (ecx),
                 "=d" (edx)
                 : "a" (eax), "c" (ecx)
                 : "memory");
    return edx;
}

static inline uint32_t x86_cpuid_eax(uint32_t eax, uint32_t ecx)
{
    uint32_t edx, ebx;
    __asm__ volatile("cpuid"
                 : "=a" (eax),
                 "=b" (ebx),
                 "=c" (ecx),
                 "=d" (edx)
                 : "a" (eax), "c" (ecx)
                 : "memory");
    return eax;
}

static inline uint32_t x86_cpuid_ecx(uint32_t eax, uint32_t ecx)
{
    uint32_t edx, ebx;
    __asm__ volatile("cpuid"
                 : "=a" (eax),
                 "=b" (ebx),
                 "=c" (ecx),
                 "=d" (edx)
                 : "a" (eax), "c" (ecx)
                 : "memory");
    return ecx;
}

static inline uint32_t x86_cpuid_ebx(uint32_t eax, uint32_t ecx)
{
    uint32_t edx, ebx;
    __asm__ volatile("cpuid"
                 : "=a" (eax),
                 "=b" (ebx),
                 "=c" (ecx),
                 "=d" (edx)
                 : "a" (eax), "c" (ecx)
                 : "memory");
    return ebx;
}

static inline uint64_t x86_rdtsc(void)
{
    uint32_t hi, lo;
    __asm__ volatile("rdtsc"
                 : "=a" (lo),
                 "=d" (hi)
                );
    return ((uint64_t) hi) << 32llu | (uint64_t) lo;
}


static inline void arch_pause(void)
{
    __asm__ volatile("pause");
}


enum x86_vendor {
    X86_VENDOR_INTEL = 0,
    X86_VENDOR_AMD,
    X86_VENDOR_OTHER
};

typedef struct _x86_cpu_identity {
    uint8_t family, model, stepping, extended_family, extended_model;
    uint8_t brand;
} x86_cpu_identity_t;

typedef struct _cpu_identity {
    enum x86_vendor vendor;
    char vendor_string[(12) + 1];





    x86_cpu_identity_t display;
} cpu_identity_t;


__attribute__((__section__(".boot.text"))) bool_t x86_cpuid_initialize(void);




x86_cpu_identity_t *x86_cpuid_get_model_info(void);



cpu_identity_t *x86_cpuid_get_identity(void);



static inline void x86_write_fs_base_impl(word_t base)
{
    x86_wrmsr(0xC0000100, base);
}

static inline void x86_write_gs_base_impl(word_t base)
{
    x86_wrmsr(0xC0000101, base);
}

static inline word_t x86_read_fs_base_impl(void)
{
    return x86_rdmsr(0xC0000100);
}

static inline word_t x86_read_gs_base_impl(void)
{
    return x86_rdmsr(0xC0000101);
}






static inline void x86_write_fs_base(word_t base, cpu_id_t cpu)
{
    if (base != ksSMP[(cpu)].cpu.x86KSCurrentFSBase) {
        ksSMP[(cpu)].cpu.x86KSCurrentFSBase = base;
        x86_write_fs_base_impl(base);
    }
}

static inline void x86_write_gs_base(word_t base, cpu_id_t cpu)
{
    if (__builtin_expect(!!(base != ksSMP[(cpu)].cpu.x86KSCurrentGSBase), 1)) {
        ksSMP[(cpu)].cpu.x86KSCurrentGSBase = base;
        x86_write_gs_base_impl(base);
    }
}

static inline word_t x86_read_fs_base(cpu_id_t cpu)
{
    return ksSMP[(cpu)].cpu.x86KSCurrentFSBase;
}

static inline word_t x86_read_gs_base(cpu_id_t cpu)
{
    return ksSMP[(cpu)].cpu.x86KSCurrentGSBase;
}


static inline void clearMemory(void* ptr, unsigned int bits)
{
    memzero(ptr, (1ul << (bits)));

}


void init_sysenter_msrs(void);


static inline void x86_mfence(void)
{
    __asm__ volatile("mfence" ::: "memory");
}


static inline unsigned long getFaultAddr(void)
{
    return read_cr2();
}

static inline void Arch_finaliseInterrupt(void)
{
    ksSMP[(getCurrentCPUIndex())].cpu.x86KScurInterrupt = int_invalid;
}




static inline void x86_enable_ibrs(void)
{


    x86_wrmsr(0x48, (1ul << (0)) | (1ul << (1)) );
}

static inline void x86_disable_ibrs(void)
{


    x86_wrmsr(0x48, (1ul << (1)) );
}

static inline void x86_ibpb(void)
{
    x86_wrmsr(0x49, 1);
}

void x86_flush_rsb(void)
{

    word_t iter = 32;
    __asm__ (

        "pause\n"


        : [iter]"+r"(iter)
        : [stack]"i"(sizeof(word_t) * iter)
        : "cc"
    );
}


void handle_syscall(void);


void int_00(void);

void int_01(void);

void int_02(void);

void int_03(void);

void int_04(void);

void int_05(void);

void int_06(void);

void int_07(void);

void int_08(void);

void int_09(void);

void int_0a(void);

void int_0b(void);

void int_0c(void);

void int_0d(void);

void int_0e(void);

void int_0f(void);


void int_10(void);

void int_11(void);

void int_12(void);

void int_13(void);

void int_14(void);

void int_15(void);

void int_16(void);

void int_17(void);

void int_18(void);

void int_19(void);

void int_1a(void);

void int_1b(void);

void int_1c(void);

void int_1d(void);

void int_1e(void);

void int_1f(void);


void int_20(void);

void int_21(void);

void int_22(void);

void int_23(void);

void int_24(void);

void int_25(void);

void int_26(void);

void int_27(void);

void int_28(void);

void int_29(void);

void int_2a(void);

void int_2b(void);

void int_2c(void);

void int_2d(void);

void int_2e(void);

void int_2f(void);


void int_30(void);

void int_31(void);

void int_32(void);

void int_33(void);

void int_34(void);

void int_35(void);

void int_36(void);

void int_37(void);

void int_38(void);

void int_39(void);

void int_3a(void);

void int_3b(void);

void int_3c(void);

void int_3d(void);

void int_3e(void);

void int_3f(void);


void int_40(void);

void int_41(void);

void int_42(void);

void int_43(void);

void int_44(void);

void int_45(void);

void int_46(void);

void int_47(void);

void int_48(void);

void int_49(void);

void int_4a(void);

void int_4b(void);

void int_4c(void);

void int_4d(void);

void int_4e(void);

void int_4f(void);


void int_50(void);

void int_51(void);

void int_52(void);

void int_53(void);

void int_54(void);

void int_55(void);

void int_56(void);

void int_57(void);

void int_58(void);

void int_59(void);

void int_5a(void);

void int_5b(void);

void int_5c(void);

void int_5d(void);

void int_5e(void);

void int_5f(void);


void int_60(void);

void int_61(void);

void int_62(void);

void int_63(void);

void int_64(void);

void int_65(void);

void int_66(void);

void int_67(void);

void int_68(void);

void int_69(void);

void int_6a(void);

void int_6b(void);

void int_6c(void);

void int_6d(void);

void int_6e(void);

void int_6f(void);


void int_70(void);

void int_71(void);

void int_72(void);

void int_73(void);

void int_74(void);

void int_75(void);

void int_76(void);

void int_77(void);

void int_78(void);

void int_79(void);

void int_7a(void);

void int_7b(void);

void int_7c(void);

void int_7d(void);

void int_7e(void);

void int_7f(void);


void int_80(void);

void int_81(void);

void int_82(void);

void int_83(void);

void int_84(void);

void int_85(void);

void int_86(void);

void int_87(void);

void int_88(void);

void int_89(void);

void int_8a(void);

void int_8b(void);

void int_8c(void);

void int_8d(void);

void int_8e(void);

void int_8f(void);


void int_90(void);

void int_91(void);

void int_92(void);

void int_93(void);

void int_94(void);

void int_95(void);

void int_96(void);

void int_97(void);

void int_98(void);

void int_99(void);

void int_9a(void);

void int_9b(void);

void int_9c(void);

void int_9d(void);

void int_9e(void);

void int_9f(void);


void int_a0(void);

void int_a1(void);

void int_a2(void);

void int_a3(void);

void int_a4(void);

void int_a5(void);

void int_a6(void);

void int_a7(void);

void int_a8(void);

void int_a9(void);

void int_aa(void);

void int_ab(void);

void int_ac(void);

void int_ad(void);

void int_ae(void);

void int_af(void);


void int_b0(void);

void int_b1(void);

void int_b2(void);

void int_b3(void);

void int_b4(void);

void int_b5(void);

void int_b6(void);

void int_b7(void);

void int_b8(void);

void int_b9(void);

void int_ba(void);

void int_bb(void);

void int_bc(void);

void int_bd(void);

void int_be(void);

void int_bf(void);


void int_c0(void);

void int_c1(void);

void int_c2(void);

void int_c3(void);

void int_c4(void);

void int_c5(void);

void int_c6(void);

void int_c7(void);

void int_c8(void);

void int_c9(void);

void int_ca(void);

void int_cb(void);

void int_cc(void);

void int_cd(void);

void int_ce(void);

void int_cf(void);


void int_d0(void);

void int_d1(void);

void int_d2(void);

void int_d3(void);

void int_d4(void);

void int_d5(void);

void int_d6(void);

void int_d7(void);

void int_d8(void);

void int_d9(void);

void int_da(void);

void int_db(void);

void int_dc(void);

void int_dd(void);

void int_de(void);

void int_df(void);


void int_e0(void);

void int_e1(void);

void int_e2(void);

void int_e3(void);

void int_e4(void);

void int_e5(void);

void int_e6(void);

void int_e7(void);

void int_e8(void);

void int_e9(void);

void int_ea(void);

void int_eb(void);

void int_ec(void);

void int_ed(void);

void int_ee(void);

void int_ef(void);


void int_f0(void);

void int_f1(void);

void int_f2(void);

void int_f3(void);

void int_f4(void);

void int_f5(void);

void int_f6(void);

void int_f7(void);

void int_f8(void);

void int_f9(void);

void int_fa(void);

void int_fb(void);

void int_fc(void);

void int_fd(void);

void int_fe(void);

void int_ff(void);


void handle_vmexit(void);

__attribute__((__section__(".boot.text"))) bool_t x2apic_is_enabled(void);

__attribute__((__section__(".boot.text"))) bool_t apic_enable(void);
__attribute__((__section__(".boot.text"))) void apic_send_init_ipi(cpu_id_t cpu_id);
__attribute__((__section__(".boot.text"))) void apic_send_startup_ipi(cpu_id_t cpu_id, paddr_t startup_addr);
__attribute__((__section__(".boot.text"))) paddr_t apic_get_base_paddr(void);
__attribute__((__section__(".boot.text"))) bool_t apic_init(bool_t mask_legacy_irqs);

uint32_t apic_read_reg(apic_reg_t reg);
void apic_write_reg(apic_reg_t reg, uint32_t val);
void apic_write_icr(word_t high, word_t low);

logical_id_t apic_get_logical_id(void);
word_t apic_get_cluster(logical_id_t logical_id);
void apic_ack_active_interrupt(void);
bool_t apic_is_interrupt_pending(void);

void apic_send_ipi_core(irq_t vector, cpu_id_t cpu_id);
void apic_send_ipi_cluster(irq_t vector, word_t mda);

enum acpi_size {
    ACPI_V1_SIZE = 20,
    ACPI_V2_SIZE = 36
};


typedef struct acpi_header {
    char signature[4];
    uint32_t length;
    uint8_t revision;
    uint8_t checksum;
    char oem_id[6];
    char oem_table_id[8];
    uint32_t oem_revision;
    char creater_id[4];
    uint32_t creater_revision;
} __attribute__((packed)) acpi_header_t;


typedef struct acpi_rsdp {
    char signature[8];
    uint8_t checksum;
    char oem_id[6];
    uint8_t revision;
    uint32_t rsdt_address;
    uint32_t length;
    uint64_t xsdt_address;
    uint8_t extended_checksum;
    char reserved[3];
} __attribute__((packed)) acpi_rsdp_t;
typedef int __assert_failed_acpi_rsdp_packed[(sizeof(acpi_rsdp_t) == ACPI_V2_SIZE) ? 1 : -1];


typedef struct acpi_rsdt {
    acpi_header_t header;
    uint32_t entry[1];
} __attribute__((packed)) acpi_rsdt_t;



bool_t acpi_init(acpi_rsdp_t *rsdp_data);


__attribute__((__section__(".boot.text"))) bool_t acpi_validate_rsdp(acpi_rsdp_t *acpi_rsdp);

uint32_t acpi_madt_scan(
    acpi_rsdp_t* acpi_rsdp,
    cpu_id_t* cpu_list,
    uint32_t* num_ioapic,
    paddr_t* ioapic_addrs
);

typedef struct acpi_rmrr_entry {
    dev_id_t device;
    uint32_t base;
    uint32_t limit;
} acpi_rmrr_entry_t;

typedef struct acpi_rmrr_list {
    acpi_rmrr_entry_t entries[32];
    int num;
} acpi_rmrr_list_t;

void acpi_dmar_scan(
    acpi_rsdp_t* acpi_rsdp,
    paddr_t* drhu_list,
    uint32_t* num_drhu,
    uint32_t max_dhru_list_len,
    acpi_rmrr_list_t *rmrr_list
);

bool_t acpi_fadt_scan(
    acpi_rsdp_t* acpi_rsdp
);

void ioapic_init(uint32_t num_nodes, cpu_id_t *cpu_list, uint32_t num_ioapic);
void ioapic_mask(bool_t mask, uint32_t ioapic, uint32_t pin);



exception_t ioapic_decode_map_pin_to_vector(word_t ioapic, word_t pin, word_t level, word_t polarity, word_t vector);


void ioapic_map_pin_to_vector(word_t ioapic, word_t pin, word_t level, word_t polarity, word_t vector);



void pic_remap_irqs(interrupt_t vector);
void pic_disable(void);

void pic_mask_irq(bool_t mask, irq_t irq);
bool_t pic_is_irq_pending(void);
void pic_ack_active_irq(void);


static inline void
handleReservedIRQ(irq_t irq)
{






}

static inline void
receivePendingIRQ(void)
{
    if(!(ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt == int_invalid)) _assert_fail("ARCH_NODE_STATE(x86KSPendingInterrupt) == int_invalid", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/plat/pc99/plat/machine/interrupt.h", 41, __FUNCTION__);
    __asm__ volatile("sti\n"
                 "nop\n"
                 "cli\n"
                 : "=m"(ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt));
}

static inline interrupt_t
servicePendingIRQ(void)
{
    if(!(ksSMP[(getCurrentCPUIndex())].cpu.x86KScurInterrupt == int_invalid)) _assert_fail("ARCH_NODE_STATE(x86KScurInterrupt) == int_invalid", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/plat/pc99/plat/machine/interrupt.h", 51, __FUNCTION__);
    if(!(ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt != int_invalid)) _assert_fail("ARCH_NODE_STATE(x86KSPendingInterrupt) != int_invalid", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/plat/pc99/plat/machine/interrupt.h", 52, __FUNCTION__);
    interrupt_t ret = ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt;
    ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt = int_invalid;
    return ret;
}


static inline irq_t
getActiveIRQ(void)
{
    if (ksSMP[(getCurrentCPUIndex())].cpu.x86KScurInterrupt == int_invalid) {







        if (ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt == int_invalid) {
            receivePendingIRQ();

            if (ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt == int_invalid) {
                return irqInvalid;
            }
        }

        ksSMP[(getCurrentCPUIndex())].cpu.x86KScurInterrupt = servicePendingIRQ();
    }
    return ksSMP[(getCurrentCPUIndex())].cpu.x86KScurInterrupt - 0x20;
}


static inline bool_t
isIRQPending(void)
{
    if (apic_is_interrupt_pending()) {
        return true;
    }

    if (0 && pic_is_irq_pending()) {
        return true;
    }

    return false;
}

static inline void
ackInterrupt(irq_t irq)
{
    if (0 && irq <= irq_isa_max) {
        pic_ack_active_irq();
    } else {
        apic_ack_active_interrupt();
    }
}

static inline void
handleSpuriousIRQ(void)
{

}

static void inline
updateIRQState(irq_t irq, x86_irq_state_t state)
{
    if(!(irq <= maxIRQ)) _assert_fail("irq <= maxIRQ", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/plat/pc99/plat/machine/interrupt.h", 117, __FUNCTION__);
    x86KSIRQState[irq] = state;
}

static inline void
maskInterrupt(bool_t disable, irq_t irq)
{
    if (irq >= irq_isa_min && irq <= irq_isa_max) {
        if (0) {
            pic_mask_irq(disable, irq);
        } else {


        }
    } else if (irq >= irq_user_min && irq <= irq_user_max) {
        x86_irq_state_t state = x86KSIRQState[irq];
        switch (x86_irq_state_get_irqType(state)) {
        case x86_irq_state_irq_ioapic: {
            uint32_t ioapic = x86_irq_state_irq_ioapic_get_id(state);
            uint32_t pin = x86_irq_state_irq_ioapic_get_pin(state);
            ioapic_mask(disable, ioapic, pin);
            state = x86_irq_state_irq_ioapic_set_masked(state, disable);
            updateIRQState(irq, state);
        }
        break;
        case x86_irq_state_irq_msi:

            break;
        case x86_irq_state_irq_free:



            break;
        }
    } else {


    }
}


bool_t platAddDevices(void);

static inline void* __attribute__((__const__))
ptrFromPAddr(paddr_t paddr)
{
    return (void*)(paddr + 0xffffff8000000000ul);
}

static inline paddr_t __attribute__((__const__))
addrFromPPtr(void* pptr)
{
    return (paddr_t)pptr - 0xffffff8000000000ul;
}

static inline region_t __attribute__((__const__))
paddr_to_pptr_reg(p_region_t p_reg)
{
    return (region_t) {
        p_reg.start + 0xffffff8000000000ul, p_reg.end + 0xffffff8000000000ul
    };
}

static inline p_region_t __attribute__((__const__))
pptr_to_paddr_reg(region_t reg)
{
    return (p_region_t) {
        reg.start - 0xffffff8000000000ul, reg.end - 0xffffff8000000000ul
    };
}




struct lookupPTSlot_ret {
    exception_t status;
    pte_t* ptSlot;
};
typedef struct lookupPTSlot_ret lookupPTSlot_ret_t;

struct lookupPDSlot_ret {
    exception_t status;
    pde_t* pdSlot;
};
typedef struct lookupPDSlot_ret lookupPDSlot_ret_t;

struct findVSpaceForASID_ret {
    exception_t status;
    vspace_root_t *vspace_root;
};
typedef struct findVSpaceForASID_ret findVSpaceForASID_ret_t;

void init_boot_pd(void);
void enable_paging(void);
bool_t map_kernel_window(
    uint32_t num_ioapic,
    paddr_t* ioapic_paddrs,
    uint32_t num_drhu,
    paddr_t* drhu_list
);
bool_t map_skim_window(vptr_t skim_start, vptr_t skim_end);
bool_t map_kernel_window_devices(
    pte_t *pt,
    uint32_t num_ioapic,
    paddr_t* ioapic_paddrs,
    uint32_t num_drhu,
    paddr_t* drhu_list
);

void init_tss(tss_t *tss);
void init_gdt(gdt_entry_t *gdt, tss_t *tss);
void init_idt_entry(idt_entry_t* idt, interrupt_t interrupt, void(*handler)(void));
vspace_root_t *getValidNativeRoot(cap_t vspace_cap);
pde_t *get_boot_pd(void);
void* map_temp_boot_page(void* entry, uint32_t large_pages);
bool_t init_vm_state(void);
void init_dtrs(void);
void map_it_pt_cap(cap_t vspace_cap, cap_t pt_cap);
void map_it_pd_cap(cap_t vspace_cap, cap_t pd_cap);
void map_it_frame_cap(cap_t vspace_cap, cap_t frame_cap);
void write_it_asid_pool(cap_t it_ap_cap, cap_t it_vspace_cap);
bool_t init_pat_msr(void);
cap_t create_it_address_space(cap_t root_cnode_cap, v_region_t it_v_reg);



void idle_thread(void);


bool_t isVTableRoot(cap_t cap);

asid_map_t findMapForASID(asid_t asid);

lookupPTSlot_ret_t lookupPTSlot(vspace_root_t *vspace, vptr_t vptr);
lookupPDSlot_ret_t lookupPDSlot(vspace_root_t *vspace, vptr_t vptr);
void copyGlobalMappings(vspace_root_t *new_vspace);
word_t* __attribute__((__pure__)) lookupIPCBuffer(bool_t isReceiver, tcb_t *thread);
exception_t handleVMFault(tcb_t *thread, vm_fault_type_t vm_faultType);
void unmapPageDirectory(asid_t asid, vptr_t vaddr, pde_t *pd);
void unmapPageTable(asid_t, vptr_t vaddr, pte_t* pt);

exception_t performASIDPoolInvocation(asid_t asid, asid_pool_t* poolPtr, cte_t* vspaceCapSlot);
exception_t performASIDControlInvocation(void *frame, cte_t *slot, cte_t *parent, asid_t asid_base);
void hwASIDInvalidate(asid_t asid, vspace_root_t *vspace);
void deleteASIDPool(asid_t asid_base, asid_pool_t* pool);
void deleteASID(asid_t asid, vspace_root_t *vspace);
findVSpaceForASID_ret_t findVSpaceForASID(asid_t asid);

void unmapPage(vm_page_size_t page_size, asid_t asid, vptr_t vptr, void *pptr);

bool_t modeUnmapPage(vm_page_size_t page_size, vspace_root_t *vroot, vptr_t vptr, void *pptr);
exception_t decodeX86ModeMapRemapPage(word_t invLabel, vm_page_size_t page_size, cte_t *cte, cap_t cap, vspace_root_t *vroot, vptr_t vptr, paddr_t paddr, vm_rights_t vm_rights, vm_attributes_t vm_attr);
void setVMRoot(tcb_t *tcb);
bool_t __attribute__((__const__)) isValidVTableRoot(cap_t cap);
bool_t __attribute__((__const__)) isValidNativeRoot(cap_t cap);
exception_t checkValidIPCBuffer(vptr_t vptr, cap_t cap);
vm_rights_t __attribute__((__const__)) maskVMRights(vm_rights_t vm_rights, seL4_CapRights_t cap_rights_mask);
void flushTable(vspace_root_t *vspace, word_t vptr, pte_t *pt, asid_t asid);

exception_t decodeX86MMUInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t *cte,
                                   cap_t cap, extra_caps_t excaps, word_t *buffer);

exception_t decodeX86ModeMMUInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t *cte,
                                       cap_t cap, extra_caps_t excaps, word_t *buffer);

exception_t decodeIA32PageDirectoryInvocation(word_t invLabel, word_t length, cte_t* cte, cap_t cap, extra_caps_t excaps, word_t* buffer);


exception_t decodeX86FrameInvocation(word_t invLabel, word_t length, cte_t *cte, cap_t cap, extra_caps_t excaps, word_t *buffer);

uint32_t __attribute__((__const__)) WritableFromVMRights(vm_rights_t vm_rights);
uint32_t __attribute__((__const__)) SuperUserFromVMRights(vm_rights_t vm_rights);





pte_t __attribute__((__const__)) makeUserPTE(paddr_t paddr, vm_attributes_t vm_attr, vm_rights_t vm_rights);
pte_t __attribute__((__const__)) makeUserPTEInvalid(void);
pde_t __attribute__((__const__)) makeUserPDELargePage(paddr_t paddr, vm_attributes_t vm_attr, vm_rights_t vm_rights);
pde_t __attribute__((__const__)) makeUserPDEPageTable(paddr_t paddr, vm_attributes_t vm_attr);
pde_t __attribute__((__const__)) makeUserPDEInvalid(void);



void Arch_userStackTrace(tcb_t *tptr);


static inline bool_t
checkVPAlignment(vm_page_size_t sz, word_t w)
{
    return (!((w) & ((1ul << (pageBitsForSize(sz)))-1ul)));
}
enum syscall {
    SysCall = -1,
    SysReplyRecv = -2,
    SysSend = -3,
    SysNBSend = -4,
    SysRecv = -5,
    SysReply = -6,
    SysYield = -7,
    SysNBRecv = -8,

    SysDebugPutChar = -9,
    SysDebugDumpScheduler = -10,


    SysDebugHalt = -11,
    SysDebugCapIdentify = -12,
    SysDebugSnapshot = -13,
    SysDebugNameThread = -14,





    SysBenchmarkFlushCaches = -16,
    SysBenchmarkResetLog = -17,
    SysBenchmarkFinalizeLog = -18,
    SysBenchmarkSetLogBuffer = -19,
    SysBenchmarkNullSyscall = -20,


    SysBenchmarkGetThreadUtilisation = -21,
    SysBenchmarkResetThreadUtilisation = -22,






    SysVMEnter = -25,

};
typedef word_t syscall_t;



static char *syscall_names[] __attribute__((unused)) = {
         [1] = "Call",
         [2] = "ReplyRecv",
         [3] = "Send",
         [4] = "NBSend",
         [5] = "Recv",
         [6] = "Reply",
         [7] = "Yield",
         [8] = "NBRecv",
};







static inline uint64_t
timestamp(void)
{
    uint32_t low, high;

    __asm__ volatile (
        "movl $0, %%eax \n"
        "movl $0, %%ecx \n"
        "cpuid          \n"
        "rdtsc          \n"
        "movl %%edx, %0 \n"
        "movl %%eax, %1 \n"
        "movl $0, %%eax \n"
        "movl $0, %%ecx \n"
        "cpuid          \n"
        : "=r" (high), "=r" (low)
        :
        : "eax", "ebx", "ecx", "edx"
    );

    return ((uint64_t) high) << 32llu | (uint64_t) low;
}

static inline void benchmark_arch_utilisation_reset(void)
{
}






typedef enum {
    Entry_Interrupt,
    Entry_UnknownSyscall,
    Entry_UserLevelFault,
    Entry_DebugFault,
    Entry_VMFault,
    Entry_Syscall,
    Entry_UnimplementedDevice,




    Entry_VMExit,

} entry_type_t;






typedef struct __attribute__((packed)) kernel_entry {
    seL4_Word path: 3;
    union {
        struct {
            seL4_Word word: 29;
        };

        struct {
            seL4_Word syscall_no: 4;
            seL4_Word cap_type: 5;
            seL4_Word is_fastpath: 1;
            seL4_Word invocation_tag: 19;
        };
    };
} kernel_entry_t;

struct lookupCap_ret {
    exception_t status;
    cap_t cap;
};
typedef struct lookupCap_ret lookupCap_ret_t;

struct lookupCapAndSlot_ret {
    exception_t status;
    cap_t cap;
    cte_t *slot;
};
typedef struct lookupCapAndSlot_ret lookupCapAndSlot_ret_t;

struct lookupSlot_raw_ret {
    exception_t status;
    cte_t *slot;
};
typedef struct lookupSlot_raw_ret lookupSlot_raw_ret_t;

struct lookupSlot_ret {
    exception_t status;
    cte_t *slot;
};
typedef struct lookupSlot_ret lookupSlot_ret_t;

struct resolveAddressBits_ret {
    exception_t status;
    cte_t *slot;
    word_t bitsRemaining;
};
typedef struct resolveAddressBits_ret resolveAddressBits_ret_t;

lookupCap_ret_t lookupCap(tcb_t *thread, cptr_t cPtr);
lookupCapAndSlot_ret_t lookupCapAndSlot(tcb_t *thread, cptr_t cPtr);
lookupSlot_raw_ret_t lookupSlot(tcb_t *thread, cptr_t capptr);
lookupSlot_ret_t lookupSlotForCNodeOp(bool_t isSource,
                                      cap_t root, cptr_t capptr,
                                      word_t depth);
lookupSlot_ret_t lookupSourceSlot(cap_t root, cptr_t capptr,
                                  word_t depth);
lookupSlot_ret_t lookupTargetSlot(cap_t root, cptr_t capptr,
                                  word_t depth);
lookupSlot_ret_t lookupPivotSlot(cap_t root, cptr_t capptr,
                                 word_t depth);
resolveAddressBits_ret_t resolveAddressBits(cap_t nodeCap,
                                            cptr_t capptr,
                                            word_t n_bits);



extern kernel_entry_t ksKernelEntry;
static inline void
benchmark_debug_syscall_start(word_t cptr, word_t msgInfo, word_t syscall)
{
    seL4_MessageInfo_t info = messageInfoFromWord_raw(msgInfo);
    lookupCapAndSlot_ret_t lu_ret = lookupCapAndSlot(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, cptr);
    ksKernelEntry.path = Entry_Syscall;
    ksKernelEntry.syscall_no = -syscall;
    ksKernelEntry.cap_type = cap_get_capType(lu_ret.cap);
    ksKernelEntry.invocation_tag = seL4_MessageInfo_get_label(info);
}

static inline __attribute__((__const__)) word_t
ready_queues_index(word_t dom, word_t prio)
{
    if (1 > 1) {
        return dom * 256 + prio;
    } else {
        if(!(dom == 0)) _assert_fail("dom == 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/kernel/thread.h", 25, __FUNCTION__);
        return prio;
    }
}

static inline __attribute__((__const__)) word_t
prio_to_l1index(word_t prio)
{
    return (prio >> 6);
}

static inline __attribute__((__const__)) word_t
l1index_to_prio(word_t l1index)
{
    return (l1index << 6);
}

static inline bool_t __attribute__((__pure__))
isRunnable(const tcb_t *thread)
{
    switch (thread_state_get_tsType(thread->tcbState)) {
    case ThreadState_Running:
    case ThreadState_Restart:

    case ThreadState_RunningVM:

        return true;

    default:
        return false;
    }
}

static inline __attribute__((__const__)) word_t
invert_l1index(word_t l1index)
{
    word_t inverted = (((256 + (1 << 6) - 1) / (1 << 6)) - 1 - l1index);
    if(!(inverted < ((256 + (1 << 6) - 1) / (1 << 6)))) _assert_fail("inverted < L2_BITMAP_SIZE", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/kernel/thread.h", 62, __FUNCTION__);
    return inverted;
}

static inline prio_t
getHighestPrio(word_t dom)
{
    word_t l1index;
    word_t l2index;
    word_t l1index_inverted;


    if(!(ksSMP[(getCurrentCPUIndex())].system.ksReadyQueuesL1Bitmap[dom] != 0)) _assert_fail("NODE_STATE(ksReadyQueuesL1Bitmap)[dom] != 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/kernel/thread.h", 74, __FUNCTION__);

    l1index = (1 << 6) - 1 - clzl(ksSMP[(getCurrentCPUIndex())].system.ksReadyQueuesL1Bitmap[dom]);
    l1index_inverted = invert_l1index(l1index);
    if(!(ksSMP[(getCurrentCPUIndex())].system.ksReadyQueuesL2Bitmap[dom][l1index_inverted] != 0)) _assert_fail("NODE_STATE(ksReadyQueuesL2Bitmap)[dom][l1index_inverted] != 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/kernel/thread.h", 78, __FUNCTION__);
    l2index = (1 << 6) - 1 - clzl(ksSMP[(getCurrentCPUIndex())].system.ksReadyQueuesL2Bitmap[dom][l1index_inverted]);
    return (l1index_to_prio(l1index) | l2index);
}

static inline bool_t
isHighestPrio(word_t dom, prio_t prio)
{
    return ksSMP[(getCurrentCPUIndex())].system.ksReadyQueuesL1Bitmap[dom] == 0 ||
           prio >= getHighestPrio(dom);
}

void configureIdleThread(tcb_t *tcb);
void activateThread(void);
void suspend(tcb_t *target);
void restart(tcb_t *target);
void doIPCTransfer(tcb_t *sender, endpoint_t *endpoint,
                   word_t badge, bool_t grant, tcb_t *receiver);
void doReplyTransfer(tcb_t *sender, tcb_t *receiver, cte_t *slot);
void doNormalTransfer(tcb_t *sender, word_t *sendBuffer, endpoint_t *endpoint,
                      word_t badge, bool_t canGrant, tcb_t *receiver,
                      word_t *receiveBuffer);
void doFaultTransfer(word_t badge, tcb_t *sender, tcb_t *receiver,
                     word_t *receiverIPCBuffer);
void doNBRecvFailedTransfer(tcb_t *thread);
void schedule(void);
void chooseThread(void);
void switchToThread(tcb_t *thread);
void switchToIdleThread(void);
void setDomain(tcb_t *tptr, dom_t dom);
void setPriority(tcb_t *tptr, prio_t prio);
void setMCPriority(tcb_t *tptr, prio_t mcp);
void scheduleTCB(tcb_t *tptr);
void possibleSwitchTo(tcb_t *tptr);
void setThreadState(tcb_t *tptr, _thread_state_t ts);
void timerTick(void);
void rescheduleRequired(void);




void Arch_postModifyRegisters(tcb_t *tptr);



static inline void
debug_printKernelEntryReason(void)
{
    kprintf("\nKernel entry via ");
    switch (ksKernelEntry.path) {
    case Entry_Interrupt:
        kprintf("Interrupt, irq %lu\n", (unsigned long) ksKernelEntry.word);
        break;
    case Entry_UnknownSyscall:
        kprintf("Unknown syscall, word: %lu", (unsigned long) ksKernelEntry.word);
        break;
    case Entry_VMFault:
        kprintf("VM Fault, fault type: %lu\n", (unsigned long) ksKernelEntry.word);
        break;
    case Entry_UserLevelFault:
        kprintf("User level fault, number: %lu", (unsigned long) ksKernelEntry.word);
        break;





    case Entry_Syscall:
        kprintf("Syscall, number: %ld, %s\n", (long) ksKernelEntry.syscall_no, syscall_names[ksKernelEntry.syscall_no]);
        if (ksKernelEntry.syscall_no == -SysSend ||
                ksKernelEntry.syscall_no == -SysNBSend ||
                ksKernelEntry.syscall_no == -SysCall) {

            kprintf("Cap type: %lu, Invocation tag: %lu\n", (unsigned long) ksKernelEntry.cap_type, (unsigned long) ksKernelEntry.invocation_tag)
                                                                ;
        }
        break;
    default:
        kprintf("Unknown\n");
        break;

    }
}


static inline void
debug_printUserState(void)
{
    tcb_t *tptr = ksSMP[(getCurrentCPUIndex())].system.ksCurThread;
    kprintf("Current thread: %s\n", tptr->tcbName);
    kprintf("Next instruction adress: %lx\n", getRestartPC(tptr));
    kprintf("Stack:\n");
    Arch_userStackTrace(tptr);
}

static inline void
debug_printTCB(tcb_t *tcb)
{
    kprintf("%40s\t", tcb->tcbName);
    char* state;
    switch (thread_state_get_tsType(tcb->tcbState)) {
    case ThreadState_Inactive:
        state = "inactive";
        break;
    case ThreadState_Running:
        state = "running";
        break;
    case ThreadState_Restart:
        state = "restart";
        break;
    case ThreadState_BlockedOnReceive:
        state = "blocked on recv";
        break;
    case ThreadState_BlockedOnSend:
        state = "blocked on send";
        break;
    case ThreadState_BlockedOnReply:
        state = "blocked on reply";
        break;
    case ThreadState_BlockedOnNotification:
        state = "blocked on ntfn";
        break;

    case ThreadState_RunningVM:
        state = "running VM";
        break;

    case ThreadState_IdleThreadState:
        state = "idle";
        break;
    default:
        _fail("Unknown thread state", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/api/debug.h", 121, __func__);
    }

    word_t core = tcb->tcbAffinity;
    kprintf("%15s\t%p\t%20lu\t%lu\n", state, (void *) getRestartPC(tcb), tcb->tcbPriority, core);
}

static inline void
debug_dumpScheduler(void)
{
    kprintf("Dumping all tcbs!\n");
    kprintf("Name                                    \tState          \tIP                  \t Prio \t Core\n");
    kprintf("--------------------------------------------------------------------------------------\n");
    for (tcb_t *curr = ksSMP[(getCurrentCPUIndex())].system.ksDebugTCBs; curr != ((void *)0); curr = curr->tcbDebugNext) {
        debug_printTCB(curr);
    }
}

exception_t handleSyscall(syscall_t syscall);
exception_t handleInterruptEntry(void);
exception_t handleUnknownSyscall(word_t w);
exception_t handleUserLevelFault(word_t w_a, word_t w_b);
exception_t handleVMFaultEvent(vm_fault_type_t vm_faultType);

static inline word_t __attribute__((__pure__))
getSyscallArg(word_t i, word_t* ipc_buffer)
{
    if (i < n_msgRegisters) {
        return getRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, msgRegisters[i]);
    }

    if(!(ipc_buffer != ((void *)0))) _assert_fail("ipc_buffer != NULL", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/api/syscall.h", 35, __FUNCTION__);
    return ipc_buffer[i + 1];
}

extern extra_caps_t current_extra_caps;
struct deriveCap_ret {
    exception_t status;
    cap_t cap;
};
typedef struct deriveCap_ret deriveCap_ret_t;

struct finaliseCap_ret {
    cap_t remainder;


    cap_t cleanupInfo;
};
typedef struct finaliseCap_ret finaliseCap_ret_t;

deriveCap_ret_t Arch_deriveCap(cte_t *slot, cap_t cap);
cap_t __attribute__((__const__)) Arch_updateCapData(bool_t preserve, word_t data, cap_t cap);
cap_t __attribute__((__const__)) Arch_maskCapRights(seL4_CapRights_t cap_rights_mask, cap_t cap);
finaliseCap_ret_t Arch_finaliseCap(cap_t cap, bool_t final);
bool_t __attribute__((__const__)) Arch_hasRecycleRights(cap_t cap);
bool_t __attribute__((__const__)) Arch_sameRegionAs(cap_t cap_a, cap_t cap_b);
bool_t __attribute__((__const__)) Arch_sameObjectAs(cap_t cap_a, cap_t cap_b);
bool_t __attribute__((__const__)) Arch_isFrameType(word_t type);
cap_t Arch_createObject(object_t t, void *regionBase, word_t userSize, bool_t deviceMemory);
exception_t Arch_decodeInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t *slot, cap_t cap, extra_caps_t excaps, bool_t call, word_t* buffer);
void Arch_prepareThreadDelete(tcb_t *thread);
word_t Arch_getObjectSize(word_t t);



deriveCap_ret_t Mode_deriveCap(cte_t *slot, cap_t cap);
finaliseCap_ret_t Mode_finaliseCap(cap_t cap, bool_t final);
bool_t __attribute__((__const__)) Mode_sameRegionAs(cap_t cap_a, cap_t cap_b);
cap_t Mode_createObject(object_t t, void *regionBase, word_t userSize, bool_t deviceMemory);
exception_t Mode_decodeInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t *slot, cap_t cap, extra_caps_t excaps, word_t* buffer);
word_t Mode_getObjectSize(word_t t);

static inline void
Arch_postCapDeletion(cap_t cap)
{
}

deriveCap_ret_t deriveCap(cte_t *slot, cap_t cap);
finaliseCap_ret_t finaliseCap(cap_t cap, bool_t final, bool_t exposed);
bool_t __attribute__((__const__)) hasCancelSendRights(cap_t cap);
bool_t __attribute__((__const__)) sameRegionAs(cap_t cap_a, cap_t cap_b);
bool_t __attribute__((__const__)) sameObjectAs(cap_t cap_a, cap_t cap_b);
cap_t __attribute__((__const__)) updateCapData(bool_t preserve, word_t newData, cap_t cap);
cap_t __attribute__((__const__)) maskCapRights(seL4_CapRights_t seL4_CapRights, cap_t cap);
cap_t createObject(object_t t, void *regionBase, word_t, bool_t deviceMemory);
void createNewObjects(object_t t, cte_t *parent, slot_range_t slots,
                      void *regionBase, word_t userSize, bool_t deviceMemory);
exception_t decodeInvocation(word_t invLabel, word_t length,
                             cptr_t capIndex, cte_t *slot, cap_t cap,
                             extra_caps_t excaps, bool_t block, bool_t call,
                             word_t *buffer);
exception_t performInvocation_Endpoint(endpoint_t *ep, word_t badge,
                                       bool_t canGrant, bool_t block,
                                       bool_t call);
exception_t performInvocation_Notification(notification_t *ntfn,
                                           word_t badge);
exception_t performInvocation_Reply(tcb_t *thread, cte_t *slot);
word_t getObjectSize(word_t t, word_t userObjSize);

static inline void
postCapDeletion(cap_t cap)
{
    if (cap_get_capType(cap) == cap_irq_handler_cap) {
        irq_t irq = cap_irq_handler_cap_get_capIRQ(cap);
        deletedIRQHandler(irq);
    } else if (isArchCap(cap)) {
        Arch_postCapDeletion(cap);
    }
}

void sendSignal(notification_t *ntfnPtr, word_t badge);
void receiveSignal(tcb_t *thread, cap_t cap, bool_t isBlocking);
void cancelAllSignals(notification_t *ntfnPtr);
void cancelSignal(tcb_t *threadPtr, notification_t *ntfnPtr);
void completeSignal(notification_t *ntfnPtr, tcb_t *tcb);
void unbindMaybeNotification(notification_t *ntfnPtr);
void unbindNotification(tcb_t *tcb);
void bindNotification(tcb_t *tcb, notification_t *ntfnPtr);

void sendIPC(bool_t blocking, bool_t do_call, word_t badge,
             bool_t canGrant, tcb_t *thread, endpoint_t *epptr);
void receiveIPC(tcb_t *thread, cap_t cap, bool_t isBlocking);
void cancelIPC(tcb_t *tptr);
void cancelAllIPC(endpoint_t *epptr);
void cancelBadgedSends(endpoint_t *epptr, word_t badge);
void replyFromKernel_error(tcb_t *thread);
void replyFromKernel_success_empty(tcb_t *thread);
exception_t decodeUntypedInvocation(word_t invLabel, word_t length,
                                    cte_t *slot, cap_t cap,
                                    extra_caps_t excaps, bool_t call,
                                    word_t *buffer);
exception_t invokeUntyped_Retype(cte_t *srcSlot, bool_t reset,
                                 void* retypeBase, object_t newType,
                                 word_t userSize, slot_range_t destSlots,
                                 bool_t deviceMemory);

void Arch_switchToThread(tcb_t *tcb);
void Arch_switchToIdleThread(void);
void Arch_configureIdleThread(tcb_t *tcb);
void Arch_activateIdleThread(tcb_t *tcb);
word_t sanitiseRegister(register_t reg, word_t v, bool_t archInfo);

static inline bool_t __attribute__((__const__))
Arch_getSanitiseRegisterInfo(tcb_t *thread)
{
    return 0;
}

void Mode_postModifyRegisters(tcb_t *tptr);


typedef int __assert_failed_InvalidRoot[(lookup_fault_invalid_root + 1 == seL4_InvalidRoot) ? 1 : -1];
typedef int __assert_failed_MissingCapability[(lookup_fault_missing_capability + 1 == seL4_MissingCapability) ? 1 : -1];
typedef int __assert_failed_DepthMismatch[(lookup_fault_depth_mismatch + 1 == seL4_DepthMismatch) ? 1 : -1];
typedef int __assert_failed_GuardMismatch[(lookup_fault_guard_mismatch + 1 == seL4_GuardMismatch) ? 1 : -1];
typedef int __assert_failed_seL4_UnknownSyscall_Syscall[((word_t) n_syscallMessage == seL4_UnknownSyscall_Syscall) ? 1 : -1];
typedef int __assert_failed_seL4_UserException_Number[((word_t) n_exceptionMessage == seL4_UserException_Number) ? 1 : -1];
typedef int __assert_failed_seL4_UserException_Code[((word_t) n_exceptionMessage + 1 == seL4_UserException_Code) ? 1 : -1];

static inline unsigned int
setMRs_lookup_failure(tcb_t *receiver, word_t* receiveIPCBuffer,
                      lookup_fault_t luf, unsigned int offset)
{
    word_t lufType = lookup_fault_get_lufType(luf);
    word_t i;

    i = setMR(receiver, receiveIPCBuffer, offset, lufType + 1);


    if (offset == seL4_CapFault_LookupFailureType) {
        if(!(offset + 1 == seL4_CapFault_BitsLeft)) _assert_fail("offset + 1 == seL4_CapFault_BitsLeft", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/api/faults.c", 41, __FUNCTION__);
        if(!(offset + 2 == seL4_CapFault_DepthMismatch_BitsFound)) _assert_fail("offset + 2 == seL4_CapFault_DepthMismatch_BitsFound", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/api/faults.c", 42, __FUNCTION__);
        if(!(offset + 2 == seL4_CapFault_GuardMismatch_GuardFound)) _assert_fail("offset + 2 == seL4_CapFault_GuardMismatch_GuardFound", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/api/faults.c", 43, __FUNCTION__);
        if(!(offset + 3 == seL4_CapFault_GuardMismatch_BitsFound)) _assert_fail("offset + 3 == seL4_CapFault_GuardMismatch_BitsFound", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/api/faults.c", 44, __FUNCTION__);
    } else {
        if(!(offset == 1)) _assert_fail("offset == 1", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/api/faults.c", 46, __FUNCTION__);
    }

    switch (lufType) {
    case lookup_fault_invalid_root:
        return i;

    case lookup_fault_missing_capability:
        return setMR(receiver, receiveIPCBuffer, offset + 1,
                     lookup_fault_missing_capability_get_bitsLeft(luf));

    case lookup_fault_depth_mismatch:
        setMR(receiver, receiveIPCBuffer, offset + 1,
              lookup_fault_depth_mismatch_get_bitsLeft(luf));
        return setMR(receiver, receiveIPCBuffer, offset + 2,
                     lookup_fault_depth_mismatch_get_bitsFound(luf));

    case lookup_fault_guard_mismatch:
        setMR(receiver, receiveIPCBuffer, offset + 1,
              lookup_fault_guard_mismatch_get_bitsLeft(luf));
        setMR(receiver, receiveIPCBuffer, offset + 2,
              lookup_fault_guard_mismatch_get_guardFound(luf));
        return setMR(receiver, receiveIPCBuffer, offset + 3,
                     lookup_fault_guard_mismatch_get_bitsFound(luf));

    default:
        _fail("Invalid lookup failure", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/api/faults.c", 72, __func__);
    }
}

static inline void
copyMRsFaultReply(tcb_t *sender, tcb_t *receiver, MessageID_t id, word_t length)
{
    word_t i;
    bool_t archInfo;

    archInfo = Arch_getSanitiseRegisterInfo(receiver);

    for (i = 0; i < (((length)<(n_msgRegisters))?(length):(n_msgRegisters)); i++) {
        register_t r = fault_messages[id][i];
        word_t v = getRegister(sender, msgRegisters[i]);
        setRegister(receiver, r, sanitiseRegister(r, v, archInfo));
    }

    if (i < length) {
        word_t *sendBuf = lookupIPCBuffer(false, sender);
        if (sendBuf) {
            for (; i < length; i++) {
                register_t r = fault_messages[id][i];
                word_t v = sendBuf[i + 1];
                setRegister(receiver, r, sanitiseRegister(r, v, archInfo));
            }
        }
    }
}

static inline void
copyMRsFault(tcb_t *sender, tcb_t *receiver, MessageID_t id,
             word_t length, word_t *receiveIPCBuffer)
{
    word_t i;
    for (i = 0; i < (((length)<(n_msgRegisters))?(length):(n_msgRegisters)); i++) {
        setRegister(receiver, msgRegisters[i], getRegister(sender, fault_messages[id][i]));
    }

    if (receiveIPCBuffer) {
        for (; i < length; i++) {
            receiveIPCBuffer[i + 1] = getRegister(sender, fault_messages[id][i]);
        }
    }
}

bool_t
handleFaultReply(tcb_t *receiver, tcb_t *sender)
{

    seL4_MessageInfo_t tag = messageInfoFromWord(getRegister(sender, msgInfoRegister));
    word_t label = seL4_MessageInfo_get_label(tag);
    word_t length = seL4_MessageInfo_get_length(tag);
    seL4_Fault_t fault = receiver->tcbFault;

    switch (seL4_Fault_get_seL4_FaultType(fault)) {
    case seL4_Fault_CapFault:
        return true;

    case seL4_Fault_UnknownSyscall:
        copyMRsFaultReply(sender, receiver, MessageID_Syscall, (((length)<(n_syscallMessage))?(length):(n_syscallMessage)));
        return (label == 0);

    case seL4_Fault_UserException:
        copyMRsFaultReply(sender, receiver, MessageID_Exception, (((length)<(n_exceptionMessage))?(length):(n_exceptionMessage)));
        return (label == 0);
    default:
        return Arch_handleFaultReply(receiver, sender, seL4_Fault_get_seL4_FaultType(fault));
    }
}

word_t
setMRs_fault(tcb_t *sender, tcb_t* receiver, word_t *receiveIPCBuffer)
{
    switch (seL4_Fault_get_seL4_FaultType(sender->tcbFault)) {
    case seL4_Fault_CapFault:
        setMR(receiver, receiveIPCBuffer, seL4_CapFault_IP, getRestartPC(sender));
        setMR(receiver, receiveIPCBuffer, seL4_CapFault_Addr,
              seL4_Fault_CapFault_get_address(sender->tcbFault));
        setMR(receiver, receiveIPCBuffer, seL4_CapFault_InRecvPhase,
              seL4_Fault_CapFault_get_inReceivePhase(sender->tcbFault));
        return setMRs_lookup_failure(receiver, receiveIPCBuffer,
                                     sender->tcbLookupFailure, seL4_CapFault_LookupFailureType);

    case seL4_Fault_UnknownSyscall: {
        copyMRsFault(sender, receiver, MessageID_Syscall, n_syscallMessage,
                     receiveIPCBuffer);

        return setMR(receiver, receiveIPCBuffer, n_syscallMessage,
                     seL4_Fault_UnknownSyscall_get_syscallNumber(sender->tcbFault));
    }

    case seL4_Fault_UserException: {
        copyMRsFault(sender, receiver, MessageID_Exception,
                     n_exceptionMessage, receiveIPCBuffer);
        setMR(receiver, receiveIPCBuffer, n_exceptionMessage,
              seL4_Fault_UserException_get_number(sender->tcbFault));
        return setMR(receiver, receiveIPCBuffer, n_exceptionMessage + 1u,
                     seL4_Fault_UserException_get_code(sender->tcbFault));
    }
    default:
        return Arch_setMRs_fault(sender, receiver, receiveIPCBuffer,
                                 seL4_Fault_get_seL4_FaultType(sender->tcbFault));
    }
}



enum benchmark_track_util_ipc_index {
    BENCHMARK_TCB_UTILISATION,
    BENCHMARK_IDLE_LOCALCPU_UTILISATION,
    BENCHMARK_IDLE_TCBCPU_UTILISATION,
    BENCHMARK_TOTAL_UTILISATION
};






extern bool_t benchmark_log_utilisation_enabled;
extern timestamp_t ksEnter;
extern timestamp_t benchmark_start_time;
extern timestamp_t benchmark_end_time;

void benchmark_track_utilisation_dump(void);

void benchmark_track_reset_utilisation(void);



static inline void benchmark_utilisation_switch(tcb_t *heir, tcb_t *next)
{

    if (__builtin_expect(!!(benchmark_log_utilisation_enabled), 1)) {


        if (__builtin_expect(!!(ksEnter > heir->benchmark.schedule_start_time), 1)) {

            heir->benchmark.utilisation += (ksEnter - heir->benchmark.schedule_start_time);

        } else {




        }


        next->benchmark.schedule_start_time = ksEnter;

    }
}

static inline void benchmark_utilisation_kentry_stamp(void)
{
    ksEnter = timestamp();
}




static inline void benchmark_utilisation_finalise(void)
{

    benchmark_utilisation_switch(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksIdleThread);

    benchmark_end_time = ksEnter;
    benchmark_log_utilisation_enabled = false;
}

void handleFault(tcb_t *tptr);
exception_t sendFaultIPC(tcb_t *tptr);
void handleDoubleFault(tcb_t *tptr, seL4_Fault_t ex1);

word_t strnlen(const char *s, word_t maxlen);
word_t strlcpy(char *dest, const char *src, word_t size);
word_t strlcat(char *dest, const char *src, word_t size);

static inline void arch_c_entry_hook(void)
{
}

static inline void arch_c_exit_hook(void)
{
}

void c_handle_syscall(word_t cptr, word_t msgInfo, syscall_t syscall)
__attribute__((externally_visible)) __attribute__((__noreturn__));

void restore_user_context(void)
__attribute__((externally_visible)) __attribute__((__noreturn__));

void c_nested_interrupt(int irq)
__attribute__((externally_visible));

void c_handle_interrupt(int irq, int syscall)
__attribute__((externally_visible)) __attribute__((__noreturn__));

void c_handle_vmexit(void)
__attribute__((externally_visible)) __attribute__((__noreturn__));


typedef enum {
    IpiRemoteCall_Stall,

    IpiRemoteCall_ClearCurrentVCPU,
    IpiRemoteCall_VMCheckBoundNotification,

    IpiRemoteCall_InvalidatePageStructureCacheASID,
    IpiRemoteCall_InvalidateTranslationSingle,
    IpiRemoteCall_InvalidateTranslationSingleASID,
    IpiRemoteCall_InvalidateTranslationAll,
    IpiRemoteCall_switchFpuOwner,
    IpiNumArchRemoteCall
} IpiRemoteCall_t;




static volatile struct {
    word_t count;
    word_t globalsense;

    char padding[64 - ((sizeof(word_t) + sizeof(word_t)) % 64)];
} ipiSyncBarrier = {0};

static volatile word_t totalCoreBarrier;
static word_t ipi_args[3 ];

static inline word_t get_ipi_arg(word_t n)
{
    if(!(n < 3 )) _assert_fail("n < MAX_IPI_ARGS", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/smp/ipi.h", 36, __FUNCTION__);
    return ipi_args[n];
}

static inline void ipi_wait(word_t cores)
{
    word_t localsense = ipiSyncBarrier.globalsense;

    if (__atomic_fetch_add(&ipiSyncBarrier.count, 1, 4) == cores) {
        ipiSyncBarrier.count = 0;
        ipiSyncBarrier.globalsense =
            ~ipiSyncBarrier.globalsense;
    }

    while (localsense == ipiSyncBarrier.globalsense) {
        arch_pause();
    }
}


void generic_ipi_send_mask(irq_t ipi, word_t mask, bool_t isBlocking);





void ipi_send_mask(irq_t ipi, word_t mask, bool_t isBlocking);


void apic_send_ipi_core(irq_t irq, word_t cpuTargetList);
void ipiStallCoreCallback(bool_t irqPath);






void handleIPI(irq_t irq, bool_t irqPath);
void doRemoteMaskOp(IpiRemoteCall_t func, word_t data1, word_t data2, word_t data3, word_t mask);
static void inline doRemoteOp(IpiRemoteCall_t func, word_t data1, word_t data2, word_t data3, word_t cpu)
{
    doRemoteMaskOp(func, data1, data2, data3, (1ul << (cpu)));
}
static void inline doRemoteMaskOp0Arg(IpiRemoteCall_t func, word_t mask)
{
    doRemoteMaskOp(func, 0, 0, 0, mask);
}

static void inline
doRemoteMaskOp1Arg(IpiRemoteCall_t func, word_t data1, word_t mask)
{
    doRemoteMaskOp(func, data1, 0, 0, mask);
}

static void inline
doRemoteMaskOp2Arg(IpiRemoteCall_t func, word_t data1, word_t data2, word_t mask)
{
    doRemoteMaskOp(func, data1, data2, 0, mask);
}

static void inline
doRemoteMaskOp3Arg(IpiRemoteCall_t func, word_t data1, word_t data2, word_t data3, word_t mask)
{
    doRemoteMaskOp(func, data1, data2, data3, mask);
}

static void inline doRemoteOp0Arg(IpiRemoteCall_t func, word_t cpu)
{
    doRemoteOp(func, 0, 0, 0, cpu);
}

static void inline
doRemoteOp1Arg(IpiRemoteCall_t func, word_t data1, word_t cpu)
{
    doRemoteOp(func, data1, 0, 0, cpu);
}

static void inline
doRemoteOp2Arg(IpiRemoteCall_t func, word_t data1, word_t data2, word_t cpu)
{
    doRemoteOp(func, data1, data2, 0, cpu);
}






void doMaskReschedule(word_t mask);






static void inline doReschedule(word_t cpu)
{
    if (cpu != getCurrentCPUIndex()) {
        if(!(cpu < 16)) _assert_fail("cpu < CONFIG_MAX_NUM_NODES", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/smp/ipi.h", 173, __FUNCTION__);
        doMaskReschedule((1ul << (cpu)));
    }
}






typedef enum {
    CLHState_Granted = 0,
    CLHState_Pending
} clh_qnode_state_t;

typedef struct clh_qnode {
    clh_qnode_state_t value;

    char padding[64 - ((sizeof(clh_qnode_state_t)) % 64)];
} clh_qnode_t;

typedef struct clh_qnode_p {
    clh_qnode_t *node;
    clh_qnode_t *next;

    word_t ipi;

    char padding[64 - ((sizeof(clh_qnode_t *) + sizeof(clh_qnode_t *) + sizeof(word_t)) % 64)]

                                        ;
} clh_qnode_p_t;

typedef struct clh_lock {
    clh_qnode_t nodes[16 + 1];
    clh_qnode_p_t node_owners[16];

    clh_qnode_t *head;
    char padding[64 - ((sizeof(clh_qnode_t *)) % 64)];
} clh_lock_t;

extern clh_lock_t big_kernel_lock;
__attribute__((__section__(".boot.text"))) void clh_lock_init(void);

static inline bool_t __attribute__((always_inline))
clh_is_ipi_pending(word_t cpu)
{
    return big_kernel_lock.node_owners[cpu].ipi == 1;
}

static inline void *
sel4_atomic_exchange(void* ptr, bool_t
                     irqPath, word_t cpu, int memorder)
{
    clh_qnode_t *prev;

    while (!try_arch_atomic_exchange(&big_kernel_lock.head,
                                     (void *) big_kernel_lock.node_owners[cpu].node, (void **) &prev,
                                     memorder, 2)) {
        if (clh_is_ipi_pending(cpu)) {



            handleIPI(irq_remote_call_ipi, irqPath);
        }

        arch_pause();
    }

    return prev;
}

static inline void __attribute__((always_inline))
clh_lock_acquire(word_t cpu, bool_t irqPath)
{
    clh_qnode_t *prev;
    big_kernel_lock.node_owners[cpu].node->value = CLHState_Pending;

    prev = sel4_atomic_exchange(&big_kernel_lock.head, irqPath, cpu, 2);

    big_kernel_lock.node_owners[cpu].next = prev;



    while (big_kernel_lock.node_owners[cpu].next->value != CLHState_Granted) {


        __atomic_thread_fence(2);
        if (clh_is_ipi_pending(cpu)) {



            handleIPI(irq_remote_call_ipi, irqPath);


        }
        arch_pause();
    }


    __atomic_thread_fence(2);
}

static inline void __attribute__((always_inline))
clh_lock_release(word_t cpu)
{

    __atomic_thread_fence(3);

    big_kernel_lock.node_owners[cpu].node->value = CLHState_Granted;
    big_kernel_lock.node_owners[cpu].node =
        big_kernel_lock.node_owners[cpu].next;
}

static inline bool_t __attribute__((always_inline))
clh_is_self_in_queue(void)
{
    return big_kernel_lock.node_owners[getCurrentCPUIndex()].node->value == CLHState_Pending;
}




static inline void c_entry_hook(void)
{
    arch_c_entry_hook();

    ksEnter = timestamp();

}





static inline void c_exit_hook(void)
{



    arch_c_exit_hook();
}


void capDL(void);





exception_t
handleInterruptEntry(void)
{
    irq_t irq;

    irq = getActiveIRQ();

    if (irq != irqInvalid) {
        handleInterrupt(irq);
        Arch_finaliseInterrupt();
    } else {



        handleSpuriousIRQ();
    }

    schedule();
    activateThread();

    return EXCEPTION_NONE;
}

exception_t
handleUnknownSyscall(word_t w)
{

    if (w == SysDebugPutChar) {
        putchar(getRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, capRegister));
        return EXCEPTION_NONE;
    }
    if (w == SysDebugDumpScheduler) {

        debug_dumpScheduler();

        return EXCEPTION_NONE;
    }


    if (w == SysDebugHalt) {
        tcb_t *tptr = ksSMP[(getCurrentCPUIndex())].system.ksCurThread;
        kprintf("Debug halt syscall from user thread %p \"%s\"\n", tptr, tptr->tcbName);
        halt();
    }
    if (w == SysDebugSnapshot) {
        tcb_t *tptr = ksSMP[(getCurrentCPUIndex())].system.ksCurThread;
        kprintf("Debug snapshot syscall from user thread %p \"%s\"\n", tptr, tptr->tcbName);
        capDL();
        return EXCEPTION_NONE;
    }
    if (w == SysDebugCapIdentify) {
        word_t cptr = getRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, capRegister);
        lookupCapAndSlot_ret_t lu_ret = lookupCapAndSlot(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, cptr);
        word_t cap_type = cap_get_capType(lu_ret.cap);
        setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, capRegister, cap_type);
        return EXCEPTION_NONE;
    }

    if (w == SysDebugNameThread) {


        const char *name;
        word_t len;
        word_t cptr = getRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, capRegister);
        lookupCapAndSlot_ret_t lu_ret = lookupCapAndSlot(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, cptr);

        word_t cap_type = cap_get_capType(lu_ret.cap);
        if (cap_type != cap_thread_cap) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 106, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("SysDebugNameThread: cap is not a TCB, halting"); kprintf(">>" "" "\n"); } while (0);
            halt();
        }

        name = (const char*)(lookupIPCBuffer(true, ksSMP[(getCurrentCPUIndex())].system.ksCurThread) + 1);
        if (!name) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 112, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("SysDebugNameThread: Failed to lookup IPC buffer, halting"); kprintf(">>" "" "\n"); } while (0);
            halt();
        }

        len = strnlen(name, seL4_MsgMaxLength * sizeof(word_t));
        if (len == seL4_MsgMaxLength * sizeof(word_t)) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 118, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("SysDebugNameThread: Name too long, halting"); kprintf(">>" "" "\n"); } while (0);
            halt();
        }
        setThreadName(((tcb_t *)(cap_thread_cap_get_capTCBPtr(lu_ret.cap))), name);
        return EXCEPTION_NONE;
    }
    if (w == SysBenchmarkFlushCaches) {
        arch_clean_invalidate_caches();
        return EXCEPTION_NONE;
    } else if (w == SysBenchmarkResetLog) {
        benchmark_log_utilisation_enabled = true;
        ksSMP[(getCurrentCPUIndex())].system.ksIdleThread->benchmark.utilisation = 0;
        ksSMP[(getCurrentCPUIndex())].system.ksCurThread->benchmark.schedule_start_time = ksEnter;
        benchmark_start_time = ksEnter;
        benchmark_arch_utilisation_reset();

        setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, capRegister, seL4_NoError);
        return EXCEPTION_NONE;
    } else if (w == SysBenchmarkFinalizeLog) {





        benchmark_utilisation_finalise();

        return EXCEPTION_NONE;
    } else if (w == SysBenchmarkSetLogBuffer) {
    }


    else if (w == SysBenchmarkGetThreadUtilisation) {
        benchmark_track_utilisation_dump();
        return EXCEPTION_NONE;
    } else if (w == SysBenchmarkResetThreadUtilisation) {
        benchmark_track_reset_utilisation();
        return EXCEPTION_NONE;
    }


    else if (w == SysBenchmarkNullSyscall) {
        return EXCEPTION_NONE;
    }


    current_fault = seL4_Fault_UnknownSyscall_new(w);
    handleFault(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);

    schedule();
    activateThread();

    return EXCEPTION_NONE;
}

exception_t
handleUserLevelFault(word_t w_a, word_t w_b)
{
    current_fault = seL4_Fault_UserException_new(w_a, w_b);
    handleFault(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);

    schedule();
    activateThread();

    return EXCEPTION_NONE;
}

exception_t
handleVMFaultEvent(vm_fault_type_t vm_faultType)
{
    exception_t status;

    status = handleVMFault(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, vm_faultType);
    if (status != EXCEPTION_NONE) {
        handleFault(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
    }

    schedule();
    activateThread();

    return EXCEPTION_NONE;
}


static exception_t
handleInvocation(bool_t isCall, bool_t isBlocking)
{
    seL4_MessageInfo_t info;
    cptr_t cptr;
    lookupCapAndSlot_ret_t lu_ret;
    word_t *buffer;
    exception_t status;
    word_t length;
    tcb_t *thread;

    thread = ksSMP[(getCurrentCPUIndex())].system.ksCurThread;

    info = messageInfoFromWord(getRegister(thread, msgInfoRegister));
    cptr = getRegister(thread, capRegister);


    lu_ret = lookupCapAndSlot(thread, cptr);

    if (__builtin_expect(!!(lu_ret.status != EXCEPTION_NONE), 0)) {
        current_fault = seL4_Fault_CapFault_new(cptr, false);

        if (isBlocking) {
            handleFault(thread);
        }

        return EXCEPTION_NONE;
    }

    buffer = lookupIPCBuffer(false, thread);

    status = lookupExtraCaps(thread, buffer, info);

    if (__builtin_expect(!!(status != EXCEPTION_NONE), 0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 296, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Lookup of extra caps failed."); kprintf(">>" "" "\n"); } while (0);
        if (isBlocking) {
            handleFault(thread);
        }
        return EXCEPTION_NONE;
    }


    length = seL4_MessageInfo_get_length(info);
    if (__builtin_expect(!!(length > n_msgRegisters && !buffer), 0)) {
        length = n_msgRegisters;
    }
    status = decodeInvocation(seL4_MessageInfo_get_label(info), length,
                              cptr, lu_ret.slot, lu_ret.cap,
                              current_extra_caps, isBlocking, isCall,
                              buffer);

    if (__builtin_expect(!!(status == EXCEPTION_PREEMPTED), 0)) {
        return status;
    }

    if (__builtin_expect(!!(status == EXCEPTION_SYSCALL_ERROR), 0)) {
        if (isCall) {
            replyFromKernel_error(thread);
        }
        return EXCEPTION_NONE;
    }

    if (__builtin_expect(!!(thread_state_get_tsType(thread->tcbState) == ThreadState_Restart), 0)
                                                                                 ) {
        if (isCall) {
            replyFromKernel_success_empty(thread);
        }
        setThreadState(thread, ThreadState_Running);
    }

    return EXCEPTION_NONE;
}

static void
handleReply(void)
{
    cte_t *callerSlot;
    cap_t callerCap;

    callerSlot = (((cte_t *)((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)&~((1ul << (11))-1ul)))+(tcbCaller));
    callerCap = callerSlot->cap;

    switch (cap_get_capType(callerCap)) {
    case cap_reply_cap: {
        tcb_t *caller;

        if (cap_reply_cap_get_capReplyMaster(callerCap)) {
            break;
        }
        caller = ((tcb_t *)(cap_reply_cap_get_capTCBPtr(callerCap)));


        if(!(caller != ksSMP[(getCurrentCPUIndex())].system.ksCurThread)) _assert_fail("caller != NODE_STATE(ksCurThread)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/api/syscall.c", 354, __FUNCTION__);
        doReplyTransfer(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, caller, callerSlot);
        return;
    }

    case cap_null_cap:

        return;

    default:
        break;
    }

    _fail("handleReply: invalid caller cap", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/api/syscall.c", 367, __func__);
}

static void
handleRecv(bool_t isBlocking)
{
    word_t epCPtr;
    lookupCap_ret_t lu_ret;

    epCPtr = getRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, capRegister);

    lu_ret = lookupCap(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, epCPtr);

    if (__builtin_expect(!!(lu_ret.status != EXCEPTION_NONE), 0)) {

        current_fault = seL4_Fault_CapFault_new(epCPtr, true);
        handleFault(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
        return;
    }

    switch (cap_get_capType(lu_ret.cap)) {
    case cap_endpoint_cap:
        if (__builtin_expect(!!(!cap_endpoint_cap_get_capCanReceive(lu_ret.cap)), 0)) {
            current_lookup_fault = lookup_fault_missing_capability_new(0);
            current_fault = seL4_Fault_CapFault_new(epCPtr, true);
            handleFault(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
            break;
        }

        deleteCallerCap(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
        receiveIPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, lu_ret.cap, isBlocking);
        break;

    case cap_notification_cap: {
        notification_t *ntfnPtr;
        tcb_t *boundTCB;
        ntfnPtr = ((notification_t *)(cap_notification_cap_get_capNtfnPtr(lu_ret.cap)));
        boundTCB = (tcb_t*)notification_ptr_get_ntfnBoundTCB(ntfnPtr);
        if (__builtin_expect(!!(!cap_notification_cap_get_capNtfnCanReceive(lu_ret.cap) || (boundTCB && boundTCB != ksSMP[(getCurrentCPUIndex())].system.ksCurThread)), 0)
                                                                          ) {
            current_lookup_fault = lookup_fault_missing_capability_new(0);
            current_fault = seL4_Fault_CapFault_new(epCPtr, true);
            handleFault(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
            break;
        }

        receiveSignal(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, lu_ret.cap, isBlocking);
        break;
    }
    default:
        current_lookup_fault = lookup_fault_missing_capability_new(0);
        current_fault = seL4_Fault_CapFault_new(epCPtr, true);
        handleFault(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
        break;
    }
}

static void
handleYield(void)
{
    tcbSchedDequeue(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
    tcbSchedAppend(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
    rescheduleRequired();
}

exception_t
handleSyscall(syscall_t syscall)
{
    exception_t ret;
    irq_t irq;

    switch (syscall) {
    case SysSend:
        ret = handleInvocation(false, true);
        if (__builtin_expect(!!(ret != EXCEPTION_NONE), 0)) {
            irq = getActiveIRQ();
            if (irq != irqInvalid) {
                handleInterrupt(irq);
                Arch_finaliseInterrupt();
            }
        }
        break;

    case SysNBSend:
        ret = handleInvocation(false, false);
        if (__builtin_expect(!!(ret != EXCEPTION_NONE), 0)) {
            irq = getActiveIRQ();
            if (irq != irqInvalid) {
                handleInterrupt(irq);
                Arch_finaliseInterrupt();
            }
        }
        break;

    case SysCall:
        ret = handleInvocation(true, true);
        if (__builtin_expect(!!(ret != EXCEPTION_NONE), 0)) {
            irq = getActiveIRQ();
            if (irq != irqInvalid) {
                handleInterrupt(irq);
                Arch_finaliseInterrupt();
            }
        }
        break;

    case SysRecv:
        handleRecv(true);
        break;

    case SysReply:
        handleReply();
        break;

    case SysReplyRecv:
        handleReply();
        handleRecv(true);
        break;

    case SysNBRecv:
        handleRecv(false);
        break;

    case SysYield:
        handleYield();
        break;

    default:
        _fail("Invalid syscall", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/api/syscall.c", 494, __func__);
    }

    schedule();
    activateThread();

    return EXCEPTION_NONE;
}





typedef struct i387_state {
    uint16_t cwd;
    uint16_t swd;
    uint16_t twd;
    uint16_t fop;
    uint32_t reserved[4];
    uint32_t mxcsr;
    uint32_t mxcsr_mask;
    uint32_t st_space[32];
    uint32_t xmm_space[64];
    uint32_t padding[13];
} __attribute__((packed)) i387_state_t;


typedef struct xsave_state {
    i387_state_t i387;
    struct {
        uint64_t xfeatures;
        uint64_t xcomp_bv;
        uint64_t reserved[6];
    } header;
} __attribute__((packed)) xsave_state_t;


bool_t Arch_initFpu(void);


void Arch_initFpuContext(user_context_t *context);

static inline uint32_t xsave_features_high(void)
{
    uint64_t features = 1;
    return (uint32_t)(features >> 32);
}

static inline uint32_t xsave_features_low(void)
{
    uint64_t features = 1;
    return (uint32_t)(features & 0xffffffff);
}


static inline void saveFpuState(user_fpu_state_t *dest)
{
    if (1) {
        __asm__ volatile("fxsave %[dest]" : [dest] "=m"(*dest));
    } else if (0) {
        __asm__ volatile("xsaveopt %[dest]" : [dest] "=m"(*dest) : "d"(xsave_features_high()), "a"(xsave_features_low()));
    } else if (0) {
        __asm__ volatile("xsave %[dest]" : [dest] "=m"(*dest) : "d"(xsave_features_high()), "a"(xsave_features_low()));
    } else if (0) {
        __asm__ volatile("xsavec %[dest]" : [dest] "=m"(*dest) : "d"(xsave_features_high()), "a"(xsave_features_low()));
    } else if (0) {
        __asm__ volatile("xsaves %[dest]" : [dest] "=m"(*dest) : "d"(xsave_features_high()), "a"(xsave_features_low()));
    }
}


static inline void loadFpuState(user_fpu_state_t *src)
{
    if (1) {
        __asm__ volatile("fxrstor %[src]" :: [src] "m"(*src));
    } else if (0) {
        if (0) {
            __asm__ volatile("xrstors %[src]" :: [src] "m"(*src), "d"(xsave_features_high()), "a"(xsave_features_low()));
        } else {
            __asm__ volatile("xrstor %[src]" :: [src] "m"(*src), "d"(xsave_features_high()), "a"(xsave_features_low()));
        }
    }
}


static inline void finit(void)
{
    __asm__ volatile("finit" :: "m"(control_reg_order));
}





static inline void enableFpu(void)
{
    __asm__ volatile("clts" :: "m" (control_reg_order));
}




static inline void disableFpu(void)
{
    write_cr0(read_cr0() | (1ul << (3)) );
}


static inline bool_t vcpuThreadUsingFPU(tcb_t *thread)
{
    return thread->tcbArch.tcbVCPU && &thread->tcbArch.tcbVCPU->fpuState == ksSMP[(getCurrentCPUIndex())].system.ksActiveFPUState;
}




void fpuThreadDelete(tcb_t *thread);


exception_t handleFPUFault(void);

void switchLocalFpuOwner(user_fpu_state_t *new_owner);


void switchFpuOwner(user_fpu_state_t *new_owner, word_t cpu);


static inline bool_t nativeThreadUsingFPU(tcb_t *thread)
{
    return &thread->tcbArch.tcbContext.fpuState ==
           ksSMP[(thread->tcbAffinity)].system.ksActiveFPUState;
}

static inline void __attribute__((always_inline)) lazyFPURestore(tcb_t *thread)
{
    if (__builtin_expect(!!(ksSMP[(getCurrentCPUIndex())].system.ksActiveFPUState), 0)) {



        if (__builtin_expect(!!(ksSMP[(getCurrentCPUIndex())].system.ksFPURestoresSinceSwitch > 64), 0)) {
            switchLocalFpuOwner(((void *)0));
            ksSMP[(getCurrentCPUIndex())].system.ksFPURestoresSinceSwitch = 0;
        } else {
            if (__builtin_expect(!!(nativeThreadUsingFPU(thread)), 1)) {

                enableFpu();
            } else {

                disableFpu();
            }
            ksSMP[(getCurrentCPUIndex())].system.ksFPURestoresSinceSwitch++;
        }
    } else {


    }
}






extern char kernel_stack_alloc[16][(1ul << (12))];



static void __attribute__((__noreturn__)) vmlaunch_failed(word_t failInvalid, word_t failValid)
{
    do { clh_lock_acquire(getCurrentCPUIndex(), false); } while(0);

    c_entry_hook();

    if (failInvalid) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 30, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("current VMCS pointer is not valid"); kprintf(">>" "" "\n"); } while (0);
    }
    if (failValid) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 33, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("vmlaunch/vmresume error %d", (int)vmread(0x00004400)); kprintf(">>" "" "\n"); } while (0);
    }

    handleVmEntryFail();
    restore_user_context();
}

static void __attribute__((__noreturn__)) restore_vmx(void)
{
    restoreVMCS();
    tcb_t *cur_thread = ksSMP[(getCurrentCPUIndex())].system.ksCurThread;




    if (cur_thread->tcbArch.tcbVCPU->launched) {

        __asm__ volatile(

            "movq %[reg], %%rsp\n"
            "popq %%rax\n"
            "popq %%rbx\n"
            "popq %%rcx\n"
            "popq %%rdx\n"
            "popq %%rsi\n"
            "popq %%rdi\n"
            "popq %%rbp\n"

            "swapgs\n"


            "vmresume\n"
            "setb %%al\n"
            "sete %%bl\n"
            "movzx %%al, %%rdi\n"
            "movzx %%bl, %%rsi\n"


            "swapgs\n"
            "movq %%gs:%c[stack_offset], %%rsp\n"



            "leaq %[failed], %%rax\n"
            "jmp *%%rax\n"
            :
            : [reg]"r"(&cur_thread->tcbArch.tcbVCPU->gp_registers[VCPU_EAX]),
            [failed]"m"(vmlaunch_failed),
            [stack_size]"i"((1ul << (12)))

            , [stack_offset]"i"(__builtin_offsetof(nodeInfo_t, stackTop))



            : "memory"
        );
    } else {

        __asm__ volatile(

            "movq %[reg], %%rsp\n"
            "popq %%rax\n"
            "popq %%rbx\n"
            "popq %%rcx\n"
            "popq %%rdx\n"
            "popq %%rsi\n"
            "popq %%rdi\n"
            "popq %%rbp\n"

            "swapgs\n"


            "vmlaunch\n"

            "setb %%al\n"
            "sete %%bl\n"
            "movzx %%al, %%rdi\n"
            "movzx %%bl, %%rsi\n"

            "swapgs\n"
            "movq %%gs:%c[stack_offset], %%rsp\n"



            "leaq %[failed], %%rax\n"
            "jmp *%%rax\n"
            :
            : [reg]"r"(&cur_thread->tcbArch.tcbVCPU->gp_registers[VCPU_EAX]),
            [failed]"m"(vmlaunch_failed),
            [stack_size]"i"((1ul << (12)))

            , [stack_offset]"i"(__builtin_offsetof(nodeInfo_t, stackTop))



            : "memory"
        );
    }
    __builtin_unreachable();
}


void __attribute__((externally_visible)) __attribute__((__noreturn__)) restore_user_context(void)
{
    do { if(clh_is_self_in_queue()) { do { clh_lock_release(getCurrentCPUIndex()); } while(0); } } while(0);
    c_exit_hook();



    if (ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt != int_invalid) {
        interrupt_t irq = servicePendingIRQ();

        __asm__ volatile(
            "movq %[stack_top], %%rsp\n"
            "movq %[syscall], %%rsi\n"
            "movq %[irq], %%rdi\n"
            "call c_handle_interrupt"
            :
            : [stack_top] "r"(&(kernel_stack_alloc[getCurrentCPUIndex()][(1ul << (12))])),
            [syscall] "i"(0),
            [irq] "r"((seL4_Word)irq)
            : "memory");
        __builtin_unreachable();
    }

    tcb_t *cur_thread = ksSMP[(getCurrentCPUIndex())].system.ksCurThread;
    word_t *irqstack = x64KSIRQStack[getCurrentCPUIndex()];

    if (thread_state_ptr_get_tsType(&cur_thread->tcbState) == ThreadState_RunningVM) {
        restore_vmx();
    }

    lazyFPURestore(cur_thread);






    cpu_id_t cpu = getCurrentCPUIndex();



    swapgs();






    word_t base = getRegister(cur_thread, TLS_BASE);
    x86_write_fs_base(base, cpu);

    base = cur_thread->tcbIPCBuffer;
    x86_write_gs_base(base, cpu);

    if (0) {
        x86_disable_ibrs();
    }




    if (__builtin_expect(!!(cur_thread->tcbArch.tcbContext.registers[Error] == -1), 1) &&
            (!0 || !0 || ((cur_thread->tcbArch.tcbContext.registers[FLAGS] & (1ul << (8)) ) == 0))) {
        if (0) {
            irqstack[0] = 0;
            irqstack[1] = 0;
            irqstack[2] = 0;
            irqstack[3] = 0;
            irqstack[4] = 0;
            irqstack[5] = 0;
        }
        if (0) {
            cur_thread->tcbArch.tcbContext.registers[FLAGS] &= ~(1ul << (9)) ;



            __asm__ volatile(

                "movq %0, %%rsp\n"
                "popq %%rdi\n"
                "popq %%rsi\n"
                "popq %%rax\n"
                "popq %%rbx\n"
                "popq %%rbp\n"
                "popq %%r12\n"
                "popq %%r13\n"
                "popq %%r14\n"

                "addq $8, %%rsp\n"
                "popq %%r10\n"
                "popq %%r8\n"
                "popq %%r9\n"
                "popq %%r15\n"

                "popfq\n"

                "orq %[IF], -8(%%rsp)\n"

                "popq %%rdx\n"

                "addq $8, %%rsp\n"

                "popq %%rcx\n"

                "addq $16, %%rsp\n"





                "popq %%r11\n"







                "sti\n"




                "rex.w sysexit\n"
                :
                : "r"(&cur_thread->tcbArch.tcbContext.registers[RDI]),



                [IF] "i" ((1ul << (9)) )


                : "memory"
            );
        } else {
            __asm__ volatile(

                "movq %0, %%rsp\n"
                "popq %%rdi\n"
                "popq %%rsi\n"
                "popq %%rax\n"
                "popq %%rbx\n"
                "popq %%rbp\n"
                "popq %%r12\n"
                "popq %%r13\n"
                "popq %%r14\n"
                "popq %%rdx\n"
                "popq %%r10\n"
                "popq %%r8\n"
                "popq %%r9\n"
                "popq %%r15\n"

                "popq %%r11\n"






                "popq %%rcx\n"






                "xor %%rsp, %%rsp\n"


                "rex.w sysret\n"
                :
                : "r"(&cur_thread->tcbArch.tcbContext.registers[RDI])





                : "memory"
            );
        }
    } else {





        irqstack[1] = getRegister(cur_thread, NextIP);
        irqstack[2] = getRegister(cur_thread, CS);
        irqstack[3] = getRegister(cur_thread, FLAGS);
        irqstack[4] = getRegister(cur_thread, RSP);
        irqstack[5] = getRegister(cur_thread, SS);
        __asm__ volatile(

            "movq %0, %%rsp\n"
            "popq %%rdi\n"
            "popq %%rsi\n"
            "popq %%rax\n"
            "popq %%rbx\n"
            "popq %%rbp\n"
            "popq %%r12\n"
            "popq %%r13\n"
            "popq %%r14\n"
            "popq %%rdx\n"
            "popq %%r10\n"
            "popq %%r8\n"
            "popq %%r9\n"
            "popq %%r15\n"

            "addq $48, %%rsp\n"
            "popq %%r11\n"






            "popq %%rcx\n"





            "swapgs\n"





            "movq %%gs:8, %%rsp\n"






            "addq $8, %%rsp\n"

            "swapgs\n"







            "iretq\n"
            :
            : "r"(&cur_thread->tcbArch.tcbContext.registers[RDI])






            : "memory"
        );
    }
    __builtin_unreachable();
}

void __attribute__((externally_visible)) __attribute__((__noreturn__)) c_x64_handle_interrupt(int irq, int syscall);
void __attribute__((externally_visible)) __attribute__((__noreturn__)) c_x64_handle_interrupt(int irq, int syscall)
{
    if (0) {
        x86_enable_ibrs();
    }
    word_t *irq_stack = x64KSIRQStack[getCurrentCPUIndex()];
    setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, Error, irq_stack[0]);




    setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, NextIP, irq_stack[1]);
    setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, FaultIP, irq_stack[1]);
    setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, FLAGS, irq_stack[3]);
    setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, RSP, irq_stack[4]);
    c_handle_interrupt(irq, syscall);
    __builtin_unreachable();
}


typedef struct Elf64_Header {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Header_t, Elf_Header_t;

typedef struct Elf64_Phdr {
    uint32_t p_type;
    uint32_t p_flags;
    uint64_t p_offset;
    uint64_t p_vaddr;
    uint64_t p_paddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint64_t p_align;
} Elf64_Phdr_t, Elf_Phdr_t;


bool_t elf_checkFile(Elf_Header_t* elfFile);
v_region_t elf_getMemoryBounds(Elf_Header_t* elfFile);
void elf_load(Elf_Header_t* elfFile, seL4_Word offset);

__attribute__((__section__(".boot.text"))) bool_t
elf_checkFile(Elf64_Header_t *elf)
{
    return (
               elf->e_ident[0] == '\177' &&
               elf->e_ident[1] == 'E' &&
               elf->e_ident[2] == 'L' &&
               elf->e_ident[3] == 'F' &&
               elf->e_ident[4] == 2
           );
}


__attribute__((__section__(".boot.text"))) v_region_t
elf_getMemoryBounds(Elf64_Header_t *elf)
{
    v_region_t elf_reg;
    vptr_t sect_start;
    vptr_t sect_end;
    uint32_t i;
    Elf64_Phdr_t *phdr = (Elf64_Phdr_t *)((paddr_t)elf + elf->e_phoff);

    elf_reg.start = 0x7fffffffffffffffUL;
    elf_reg.end = 0;

    for (i = 0; i < elf->e_phnum; i++) {
        if (phdr[i].p_memsz > 0) {
            sect_start = phdr[i].p_vaddr;
            sect_end = sect_start + phdr[i].p_memsz;
            if (sect_start < elf_reg.start) {
                elf_reg.start = sect_start;
            }
            if (sect_end > elf_reg.end) {
                elf_reg.end = sect_end;
            }
        }
    }

    return elf_reg;
}

__attribute__((__section__(".boot.text"))) void
elf_load(Elf64_Header_t *elf, seL4_Word offset)
{
    paddr_t src;
    paddr_t dst;
    uint64_t len;
    uint32_t i;
    Elf64_Phdr_t *phdr = (Elf64_Phdr_t *)((paddr_t)elf + elf->e_phoff);

    for (i = 0; i < elf->e_phnum; i++) {
        src = (paddr_t)elf + phdr[i].p_offset;
        dst = phdr[i].p_vaddr + offset;
        len = phdr[i].p_filesz;
        memcpy((void *)dst, (char *)src, len);
        dst += len;
        memset((void *)dst, 0, phdr[i].p_memsz - len);
    }
}

void
Arch_switchToThread(tcb_t* tcb)
{

    setVMRoot(tcb);

    __asm__ volatile("movq %[value], %%gs:%c[offset]"
                 :
                 : [value] "r" (&tcb->tcbArch.tcbContext.registers[Error + 1]),
                 [offset] "i" (__builtin_offsetof(nodeInfo_t, currentThreadUserContext)));

    if (0) {
        x86_ibpb();
    }

    if (0) {
        x86_flush_rsb();
    }
}

__attribute__((__section__(".boot.text"))) void
Arch_configureIdleThread(tcb_t* tcb)
{
    setRegister(tcb, FLAGS, (1ul << (9)) | (1ul << (1)) );
    setRegister(tcb, NextIP, (uint64_t)(&idle_thread));
    setRegister(tcb, CS, (1 << 3));
    setRegister(tcb, SS, (2 << 3));





    setRegister(tcb, RSP, 0);
}

void
Arch_switchToIdleThread(void)
{
    tcb_t *tcb = ksSMP[(getCurrentCPUIndex())].system.ksIdleThread;

    setVMRoot(tcb);

    __asm__ volatile("movq %[value], %%gs:%c[offset]"
                 :
                 : [value] "r"(&tcb->tcbArch.tcbContext.registers[Error + 1]),
                 [offset] "i" (__builtin_offsetof(nodeInfo_t, currentThreadUserContext)));

}

void
Arch_activateIdleThread(tcb_t* tcb)
{

}

void
Mode_postModifyRegisters(tcb_t *tptr)
{



    if (tptr != ksSMP[(getCurrentCPUIndex())].system.ksCurThread) {
        setRegister(tptr, Error, 0);
    }
}
enum {
    seL4_CapNull = 0,
    seL4_CapInitThreadTCB = 1,
    seL4_CapInitThreadCNode = 2,
    seL4_CapInitThreadVSpace = 3,
    seL4_CapIRQControl = 4,
    seL4_CapASIDControl = 5,
    seL4_CapInitThreadASIDPool = 6,
    seL4_CapIOPort = 7,
    seL4_CapIOSpace = 8,
    seL4_CapBootInfoFrame = 9,
    seL4_CapInitThreadIPCBuffer = 10,
    seL4_CapDomain = 11,
    seL4_NumInitialCaps = 12
};






typedef seL4_Word seL4_SlotPos;

typedef struct {
    seL4_SlotPos start;
    seL4_SlotPos end;
} __attribute__((packed)) seL4_SlotRegion;

typedef struct {
    seL4_Word paddr;
    seL4_Uint8 padding1;
    seL4_Uint8 padding2;
    seL4_Uint8 sizeBits;
    seL4_Uint8 isDevice;
} __attribute__((packed)) seL4_UntypedDesc;

typedef struct {
    seL4_Word extraLen;
    seL4_NodeId nodeID;
    seL4_Word numNodes;
    seL4_Word numIOPTLevels;
    seL4_IPCBuffer* ipcBuffer;
    seL4_SlotRegion empty;
    seL4_SlotRegion sharedFrames;
    seL4_SlotRegion userImageFrames;
    seL4_SlotRegion userImagePaging;
    seL4_SlotRegion ioSpaceCaps;
    seL4_SlotRegion extraBIPages;
    seL4_Uint8 initThreadCNodeSizeBits;
    seL4_Domain initThreadDomain;
    seL4_SlotRegion untyped;
    seL4_UntypedDesc untypedList[230];


} __attribute__((packed)) seL4_BootInfo;




typedef struct {

    seL4_Word id;

    seL4_Word len;
} __attribute__((packed)) seL4_BootInfoHeader;







typedef int __assert_failed_bi_size[(sizeof(seL4_BootInfo) <= (1ul << (12))) ? 1 : -1];
typedef cte_t slot_t;
typedef cte_t* slot_ptr_t;





typedef struct ndks_boot {
    region_t freemem[16];
    seL4_BootInfo* bi_frame;
    seL4_SlotPos slot_pos_cur;
    seL4_SlotPos slot_pos_max;
} ndks_boot_t;

extern ndks_boot_t ndks_boot;



static inline bool_t
is_reg_empty(region_t reg)
{
    return reg.start == reg.end;
}

pptr_t alloc_region(word_t size_bits);
bool_t insert_region(region_t reg);
void write_slot(slot_ptr_t slot_ptr, cap_t cap);
cap_t create_root_cnode(void);
bool_t provide_cap(cap_t root_cnode_cap, cap_t cap);
cap_t create_it_asid_pool(cap_t root_cnode_cap);
void write_it_pd_pts(cap_t root_cnode_cap, cap_t it_pd_cap);
bool_t create_idle_thread(void);
bool_t create_untypeds_for_region(cap_t root_cnode_cap, bool_t device_memory, region_t reg, seL4_SlotPos first_untyped_slot);
bool_t create_kernel_untypeds(cap_t root_cnode_cap, region_t boot_mem_reuse_reg, seL4_SlotPos first_untyped_slot);
void bi_finalise(void);
bool_t create_irq_cnode(void);
void create_domain_cap(cap_t root_cnode_cap);

cap_t create_ipcbuf_frame(cap_t root_cnode_cap, cap_t pd_cap, vptr_t vptr);

region_t allocate_extra_bi_region(word_t extra_size);
pptr_t allocate_bi_frame(node_id_t node_id, word_t num_nodes, vptr_t ipcbuf_vptr);

void create_bi_frame_cap(cap_t root_cnode_cap, cap_t pd_cap, pptr_t pptr, vptr_t vptr);

typedef struct create_frames_of_region_ret {
    seL4_SlotRegion region;
    bool_t success;
} create_frames_of_region_ret_t;

create_frames_of_region_ret_t
create_frames_of_region(
    cap_t root_cnode_cap,
    cap_t pd_cap,
    region_t reg,
    bool_t do_map,
    sword_t pv_offset
);

cap_t
create_it_pd_pts(
    cap_t root_cnode_cap,
    v_region_t ui_v_reg,
    vptr_t ipcbuf_vptr,
    vptr_t bi_frame_vptr
);

tcb_t *
create_initial_thread(
    cap_t root_cnode_cap,
    cap_t it_pd_cap,
    vptr_t ui_v_entry,
    vptr_t bi_frame_vptr,
    vptr_t ipcbuf_vptr,
    cap_t ipcbuf_cap
);

void init_core_state(tcb_t *scheduler_action);
typedef struct seL4_VBEInfoBlock {
    char signature[4];
    seL4_Uint16 version;
    seL4_Uint32 oemStringPtr;
    seL4_Uint32 capabilities;
    seL4_Uint32 modeListPtr;
    seL4_Uint16 totalMemory;
    seL4_Uint16 oemSoftwareRev;
    seL4_Uint32 oemVendorNamePtr;
    seL4_Uint32 oemProductNamePtr;
    seL4_Uint32 oemProductRevPtr;
    seL4_Uint8 reserved[222];
    seL4_Uint8 oemData[256];
} __attribute__((packed)) seL4_VBEInfoBlock_t;


typedef struct seL4_VBEModeInfoCommon {
    seL4_Uint16 modeAttr;
    seL4_Uint8 winAAttr;
    seL4_Uint8 winBAttr;
    seL4_Uint16 winGranularity;
    seL4_Uint16 winSize;
    seL4_Uint16 winASeg;
    seL4_Uint16 winBSeg;
    seL4_Uint32 winFuncPtr;
    seL4_Uint16 bytesPerScanLine;
} __attribute__((packed)) seL4_VBEModeInfoCommon_t;

typedef struct seL4_VBEInfo12Part1 {
    seL4_Uint16 xRes;
    seL4_Uint16 yRes;
    seL4_Uint8 xCharSize;
    seL4_Uint8 yCharSize;
    seL4_Uint8 planes;
    seL4_Uint8 bitsPerPixel;
    seL4_Uint8 banks;
    seL4_Uint8 memoryModel;
    seL4_Uint8 bankSize;
    seL4_Uint8 imagePages;
    seL4_Uint8 reserved1;
} __attribute__((packed)) seL4_VBEInfo12Part1_t;

typedef struct seL4_VBEInfo12Part2 {
    seL4_Uint8 redLen;
    seL4_Uint8 redOff;
    seL4_Uint8 greenLen;
    seL4_Uint8 greenOff;
    seL4_Uint8 blueLen;
    seL4_Uint8 blueOff;
    seL4_Uint8 rsvdLen;
    seL4_Uint8 rsvdOff;
    seL4_Uint8 directColorInfo;
} __attribute__((packed)) seL4_VBEInfo12Part2_t;

typedef struct seL4_VBEInfo20 {
    seL4_Uint32 physBasePtr;
    seL4_Uint8 reserved2[6];
} __attribute__((packed)) seL4_VBEInfo20_t;

typedef struct seL4_VBEInfo30 {
    seL4_Uint16 linBytesPerScanLine;
    seL4_Uint8 bnkImagePages;
    seL4_Uint8 linImagePages;
    seL4_Uint8 linRedLen;
    seL4_Uint8 linRedOff;
    seL4_Uint8 linGreenLen;
    seL4_Uint8 linGreenOff;
    seL4_Uint8 linBlueLen;
    seL4_Uint8 linBlueOff;
    seL4_Uint8 linRsvdLen;
    seL4_Uint8 linRsvdOff;
    seL4_Uint32 maxPixelClock;
    seL4_Uint16 modeId;
    seL4_Uint8 depth;
} __attribute__((packed)) seL4_VBEInfo30_t;

typedef struct seL4_VBEModeInfoBlock {

    seL4_VBEModeInfoCommon_t vbe_common;

    seL4_VBEInfo12Part1_t vbe12_part1;
    seL4_VBEInfo12Part2_t vbe12_part2;


    seL4_VBEInfo20_t vbe20;


    seL4_VBEInfo30_t vbe30;

    seL4_Uint8 reserved3[187];
} __attribute__((packed)) seL4_VBEModeInfoBlock_t;

typedef struct _seL4_X86_BootInfo_VBE {
    seL4_BootInfoHeader header;
    seL4_VBEInfoBlock_t vbeInfoBlock;
    seL4_VBEModeInfoBlock_t vbeModeInfoBlock;
    seL4_Uint32 vbeMode;
    seL4_Uint32 vbeInterfaceSeg;
    seL4_Uint32 vbeInterfaceOff;
    seL4_Uint32 vbeInterfaceLen;
} __attribute__((packed)) seL4_X86_BootInfo_VBE;





typedef struct seL4_X86_mb_mmap {
    uint32_t size;
    uint64_t base_addr;
    uint64_t length;
    uint32_t type;
} __attribute__((packed)) seL4_X86_mb_mmap_t;

typedef struct seL4_X86_BootInfo_mmap {
    seL4_BootInfoHeader header;
    seL4_Uint32 mmap_length;
    seL4_X86_mb_mmap_t mmap[50];
} __attribute__((packed)) seL4_X86_BootInfo_mmap_t;

typedef struct multiboot2_fb seL4_X86_BootInfo_fb_t;

typedef struct mem_p_regs {
    word_t count;
    p_region_t list[16];
} mem_p_regs_t;

typedef struct ui_info {
    p_region_t p_reg;
    sword_t pv_offset;
    vptr_t v_entry;
} ui_info_t;

cap_t create_unmapped_it_frame_cap(pptr_t pptr, bool_t use_large);
cap_t create_mapped_it_frame_cap(cap_t pd_cap, pptr_t pptr, vptr_t vptr, asid_t asid, bool_t use_large, bool_t executable);

bool_t init_sys_state(
    cpu_id_t cpu_id,
    mem_p_regs_t mem_p_regs,
    ui_info_t ui_info,
    p_region_t boot_mem_reuse_p_reg,

    uint32_t num_drhu,
    paddr_t* drhu_list,
    acpi_rmrr_list_t *rmrr_list,
    acpi_rsdp_t *acpi_rsdp,
    seL4_X86_BootInfo_VBE *vbe,
    seL4_X86_BootInfo_mmap_t *mb_mmap,
    seL4_X86_BootInfo_fb_t *fb_info
);

bool_t init_cpu(
    bool_t mask_legacy_irqs
);

bool_t add_allocated_p_region(p_region_t reg);
void init_allocated_p_regions(void);
enum invocation_label {
    InvalidInvocation,
    UntypedRetype,
    TCBReadRegisters,
    TCBWriteRegisters,
    TCBCopyRegisters,
    TCBConfigure,
    TCBSetPriority,
    TCBSetMCPriority,
    TCBSetSchedParams,
    TCBSetIPCBuffer,
    TCBSetSpace,
    TCBSuspend,
    TCBResume,
    TCBBindNotification,
    TCBUnbindNotification,

    TCBSetAffinity,
    CNodeRevoke,
    CNodeDelete,
    CNodeCancelBadgedSends,
    CNodeCopy,
    CNodeMint,
    CNodeMove,
    CNodeMutate,
    CNodeRotate,
    CNodeSaveCaller,
    IRQIssueIRQHandler,
    IRQAckIRQ,
    IRQSetIRQHandler,
    IRQClearIRQHandler,
    DomainSetSet,
    nInvocationLabels
};
enum sel4_arch_invocation_label {
    X86PDPTMap = nInvocationLabels,
    X86PDPTUnmap,
    nSeL4ArchInvocationLabels
};
enum arch_invocation_label {
    X86PageDirectoryMap = nSeL4ArchInvocationLabels,
    X86PageDirectoryUnmap,



    X86PageTableMap,
    X86PageTableUnmap,






    X86PageMap,
    X86PageRemap,
    X86PageUnmap,



    X86PageGetAddress,

    X86PageMapEPT,

    X86ASIDControlMakePool,
    X86ASIDPoolAssign,
    X86IOPortIn8,
    X86IOPortIn16,
    X86IOPortIn32,
    X86IOPortOut8,
    X86IOPortOut16,
    X86IOPortOut32,
    X86IRQIssueIRQHandlerIOAPIC,
    X86IRQIssueIRQHandlerMSI,

    TCBSetEPTRoot,


    X86VCPUSetTCB,


    X86VCPUReadVMCS,


    X86VCPUWriteVMCS,


    X86VCPUEnableIOPort,


    X86VCPUDisableIOPort,


    X86VCPUWriteRegisters,


    X86EPTPDPTMap,


    X86EPTPDPTUnmap,


    X86EPTPDMap,


    X86EPTPDUnmap,


    X86EPTPTMap,


    X86EPTPTUnmap,

    nArchInvocationLabels
};


static inline void doRemoteStall(word_t cpu)
{
    doRemoteOp0Arg(IpiRemoteCall_Stall, cpu);
}

static inline void doRemoteswitchFpuOwner(user_fpu_state_t *new_owner, word_t cpu)
{
    doRemoteOp1Arg(IpiRemoteCall_switchFpuOwner, (word_t)new_owner, cpu);
}

static inline void doRemoteInvalidatePageStructureCacheASID(paddr_t root, asid_t asid, word_t mask)
{
    doRemoteMaskOp2Arg(IpiRemoteCall_InvalidatePageStructureCacheASID, root, asid, mask);
}

static inline void doRemoteInvalidateTranslationSingle(vptr_t vptr, word_t mask)
{
    doRemoteMaskOp1Arg(IpiRemoteCall_InvalidateTranslationSingle, vptr, mask);
}

static inline void doRemoteInvalidateTranslationSingleASID(vptr_t vptr, asid_t asid, word_t mask)
{
    doRemoteMaskOp2Arg(IpiRemoteCall_InvalidateTranslationSingleASID, vptr, asid, mask);
}

static inline void doRemoteInvalidateTranslationAll(word_t mask)
{
    doRemoteMaskOp0Arg(IpiRemoteCall_InvalidateTranslationAll, mask);
}


static inline void
doRemoteClearCurrentVCPU(word_t cpu)
{
    doRemoteOp0Arg(IpiRemoteCall_ClearCurrentVCPU, cpu);
}

static inline void
doRemoteVMCheckBoundNotification(word_t cpu, tcb_t *tcb)
{
    doRemoteOp1Arg(IpiRemoteCall_VMCheckBoundNotification, cpu, (word_t)tcb);
}

static inline void invalidatePageStructureCacheASID(paddr_t root, asid_t asid, word_t mask)
{
    invalidateLocalPageStructureCacheASID(root, asid);
    doRemoteInvalidatePageStructureCacheASID(root, asid, mask);
}

static inline void invalidateTranslationSingle(vptr_t vptr, word_t mask)
{
    invalidateLocalTranslationSingle(vptr);
    doRemoteInvalidateTranslationSingle(vptr, mask);
}

static inline void invalidateTranslationSingleASID(vptr_t vptr, asid_t asid, word_t mask)
{
    invalidateLocalTranslationSingleASID(vptr, asid);
    doRemoteInvalidateTranslationSingleASID(vptr, asid, mask);
}

static inline void invalidateTranslationAll(word_t mask)
{
    invalidateLocalTranslationAll();
    doRemoteInvalidateTranslationAll(mask);
}



typedef enum {
    IpiRemoteCall_InvalidatePCID = IpiNumArchRemoteCall,
    IpiRemoteCall_InvalidateASID,
    IpiNumModeRemoteCall
} IpiModeRemoteCall_t;

void Mode_handleRemoteCall(IpiModeRemoteCall_t call, word_t arg0, word_t arg1, word_t arg2);

static inline void doRemoteInvalidatePCID(word_t type, void *vaddr, asid_t asid, word_t mask)
{
    doRemoteMaskOp3Arg(IpiRemoteCall_InvalidatePCID, type, (word_t)vaddr, asid, mask);
}

static inline void doRemoteInvalidateASID(vspace_root_t *vspace, asid_t asid, word_t mask)
{
    doRemoteMaskOp2Arg(IpiRemoteCall_InvalidateASID, (word_t)vspace, asid, mask);
}

struct lookupPDPTSlot_ret {
    exception_t status;
    pdpte_t *pdptSlot;
};
typedef struct lookupPDPTSlot_ret lookupPDPTSlot_ret_t;

static inline pte_t
x86_make_device_pte(paddr_t phys)
{
    return pte_new(
               0,
               phys,
               1,
               0,
               0,
               0,
               1,
               1,
               0,
               1,
               1
           );
}

static inline pte_t
x86_make_empty_pte(void)
{
    return pte_new(
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0
           );
}

static inline __attribute__((__const__)) pml4e_t
x86_make_empty_root_mapping(void)
{
    return pml4e_new(
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0
           );
}



static inline void
tlb_bitmap_init(vspace_root_t *root)
{
    for (int i = 0; i < (((16 - 1) / ((1 << 6) - 1)) + 1); i++) {
        root[( (((0xffffff8000000000ul - ((((16 - 1) / ((1 << 6) - 1)) + 1) * (1ul << (((((12) + 9) + 9) + 9)))))) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)) + i] = x86_make_empty_root_mapping();
    }
}

static inline void
tlb_bitmap_set(vspace_root_t *root, word_t cpu)
{
    if(!(cpu < (((1 << 6) - 1) * (((16 - 1) / ((1 << 6) - 1)) + 1)) && cpu <= (1 << 6))) _assert_fail("cpu < TLBBITMAP_ROOT_BITS && cpu <= wordBits", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/arch/x86/arch/kernel/tlb_bitmap.h", 36, __FUNCTION__);
    root[(( (((0xffffff8000000000ul - ((((16 - 1) / ((1 << 6) - 1)) + 1) * (1ul << (((((12) + 9) + 9) + 9)))))) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)) + ((cpu) / ((1 << 6) - 1)))].words[0] |= (1ul << (((cpu) % ((1 << 6) - 1)) + 1));
}

static inline void
tlb_bitmap_unset(vspace_root_t *root, word_t cpu)
{
    if(!(cpu < (((1 << 6) - 1) * (((16 - 1) / ((1 << 6) - 1)) + 1)) && cpu <= (1 << 6))) _assert_fail("cpu < TLBBITMAP_ROOT_BITS && cpu <= wordBits", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/include/arch/x86/arch/kernel/tlb_bitmap.h", 43, __FUNCTION__);
    root[(( (((0xffffff8000000000ul - ((((16 - 1) / ((1 << 6) - 1)) + 1) * (1ul << (((((12) + 9) + 9) + 9)))))) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)) + ((cpu) / ((1 << 6) - 1)))].words[0] &= ~(1ul << (((cpu) % ((1 << 6) - 1)) + 1));
}

static inline word_t
tlb_bitmap_get(vspace_root_t *root)
{
    word_t bitmap = 0;

    for (int i = 0; i < (((16 - 1) / ((1 << 6) - 1)) + 1); i++) {
        word_t entry = root[( (((0xffffff8000000000ul - ((((16 - 1) / ((1 << 6) - 1)) + 1) * (1ul << (((((12) + 9) + 9) + 9)))))) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)) + i].words[0];

        entry >>= 1;

        int shift = i * ((1 << 6) - 1);
        bitmap |= entry << shift;
    }
    return bitmap;
}






static inline void invalidateLocalASID(vspace_root_t *vspace, asid_t asid)
{
    invalidateLocalPCID(1, (void*)0, asid);

    if (addrFromPPtr(vspace) != getCurrentUserVSpaceRoot()) {
        tlb_bitmap_unset(vspace, getCurrentCPUIndex());
    }

}

static inline void invalidatePCID(word_t type, void *vaddr, asid_t asid, word_t mask)
{
    invalidateLocalPCID(type, vaddr, asid);
    doRemoteInvalidatePCID(type, vaddr, asid, mask);
}

static inline void invalidateASID(vspace_root_t *vspace, asid_t asid, word_t mask)
{
    invalidateLocalASID(vspace, asid);
    doRemoteInvalidateASID(vspace, asid, mask);
}
pml4e_t boot_pml4[(1ul << (9))] __attribute__((__aligned__((1ul << (12))))) __attribute__((externally_visible)) __attribute__((__section__(".phys.bss")));
pdpte_t boot_pdpt[(1ul << (9))] __attribute__((__aligned__((1ul << (12))))) __attribute__((externally_visible)) __attribute__((__section__(".phys.bss")));




gdt_idt_ptr_t gdt_idt_ptr;

__attribute__((__section__(".boot.text"))) bool_t
map_kernel_window(
    uint32_t num_ioapic,
    paddr_t* ioapic_paddrs,
    uint32_t num_drhu,
    paddr_t* drhu_list
)
{

    uint64_t paddr;
    uint64_t vaddr;
    int pd_index = 0;


    if(!(( ((0xffffff8000000000ul) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)) == (1ul << (9)) - 1)) _assert_fail("GET_PML4_INDEX(PPTR_BASE) == BIT(PML4_INDEX_BITS) - 1", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 145, __FUNCTION__);


    if(!(( ((0xffffffff80000000ul) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)) == (1ul << (9)) - 1)) _assert_fail("GET_PML4_INDEX(KERNEL_BASE) == BIT(PML4_INDEX_BITS) - 1", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 148, __FUNCTION__);
    if(!(( ((0xffffffff80000000ul) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)) == (1ul << (9)) - 2)) _assert_fail("GET_PDPT_INDEX(KERNEL_BASE) == BIT(PML4_INDEX_BITS) - 2", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 149, __FUNCTION__);
    if(!(( ((0xffffffffc0000000ul) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)) == (1ul << (9)) - 1)) _assert_fail("GET_PDPT_INDEX(PPTR_KDEV) == BIT(PML4_INDEX_BITS) - 1", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 150, __FUNCTION__);
    if(!((!((0xffffffff80000000ul) & ((1ul << (30))-1ul))))) _assert_fail("IS_ALIGNED(KERNEL_BASE, seL4_HugePageBits)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 151, __FUNCTION__);
    if(!((!((0xffffffffc0000000ul) & ((1ul << (30))-1ul))))) _assert_fail("IS_ALIGNED(PPTR_KDEV, seL4_HugePageBits)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 152, __FUNCTION__);


    x64KSKernelPML4[( ((0xffffff8000000000ul) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul))] = pml4e_new(
                                                     0,
                                                     kpptr_to_paddr(x64KSKernelPDPT),
                                                     0,
                                                     0,
                                                     0,
                                                     0,
                                                     1,
                                                     1
                                                 );

    for (pd_index = 0; pd_index < (0xffffffff80000000ul - 0xffffff8000000000ul) >> 30; pd_index++) {

        x64KSKernelPDPT[( ((0xffffff8000000000ul) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)) + pd_index] = pdpte_pdpte_pd_new(
                                                                    0,
                                                                    kpptr_to_paddr(&x64KSKernelPDs[pd_index][0]),
                                                                    0,
                                                                    0,
                                                                    0,
                                                                    0,
                                                                    1,
                                                                    1
                                                                );
    }

    x64KSKernelPDPT[( ((0xffffffff80000000ul) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul))] = pdpte_pdpte_pd_new(
                                                       0,
                                                       kpptr_to_paddr(&x64KSKernelPDs[0][0]),
                                                       0,
                                                       0,
                                                       1,
                                                       0,
                                                       1,
                                                       1
                                                   );

    paddr = 0;
    vaddr = 0xffffff8000000000ul;

    for (paddr = 0; paddr < (0xffffffff80000000ul - 0xffffff8000000000ul);
            paddr += 0x200000) {

        int pd_index = ( ((vaddr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul)) - ( ((0xffffff8000000000ul) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));
        int pde_index = ( ((vaddr) >> (((12) + 9))) & ((1ul << (9))-1ul));

        x64KSKernelPDs[pd_index][pde_index] = pde_pde_large_new(
                                                  0,
                                                  paddr,
                                                  0,
                                                  (0 ? 0 : 1),
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  0,
                                                  1,
                                                  1
                                              );
        vaddr += 0x200000;
    }


    x64KSKernelPDPT[( ((0xffffffffc0000000ul) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul))] = pdpte_pdpte_pd_new(
                                                     0,
                                                     kpptr_to_paddr(&x64KSKernelPDs[(1ul << (9)) - 1][0]),
                                                     0,
                                                     0,
                                                     0,
                                                     0,
                                                     1,
                                                     1
                                                 );


    x64KSKernelPDs[(1ul << (9)) - 1][0] = pde_pde_pt_new(
                                                      0,
                                                      kpptr_to_paddr(x64KSKernelPT),
                                                      0,
                                                      0,
                                                      0,
                                                      0,
                                                      1,
                                                      1
                                                  );

    if (!map_kernel_window_devices(x64KSKernelPT, num_ioapic, ioapic_paddrs, num_drhu, drhu_list)) {
        return false;
    }



    tlb_bitmap_init(x64KSKernelPML4);



    invalidateLocalTranslationAll();
    kprintf("Mapping kernel window is done\n");
    return true;
}
__attribute__((__section__(".boot.text"))) void
init_tss(tss_t *tss)
{
    word_t base = (word_t)&x64KSIRQStack[getCurrentCPUIndex()][6];
    *tss = tss_new(
               sizeof(*tss),
               0, 0,
               0, 0,
               0, 0,
               0, 0,
               0, 0,
               0, 0,

               base >> 32, base & 0xffffffff,
               0, 0,
               0, 0,
               0, 0
           );

    memset(&x86KSGlobalState[getCurrentCPUIndex()].x86KStss.io_map[0], 0xff, sizeof(x86KSGlobalState[getCurrentCPUIndex()].x86KStss.io_map));
}

__attribute__((__section__(".boot.text"))) void
init_syscall_msrs(void)
{
    x86_wrmsr(0xC0000082, (uint64_t)&handle_fastsyscall);



    x86_wrmsr(0xC0000084, (1ul << (8)) | (1ul << (9)) );
    x86_wrmsr(0xC0000081, ((uint64_t)(1 << 3) << 32) | ((uint64_t)((5 << 3) | 3) << 48));
}

__attribute__((__section__(".boot.text"))) void
init_gdt(gdt_entry_t *gdt, tss_t *tss)
{

    uint64_t tss_base = (uint64_t)tss;
    gdt_tss_t gdt_tss;

    gdt[0] = gdt_entry_gdt_null_new();

    gdt[1] = gdt_entry_gdt_code_new(
                        0,
                        1,
                        0,
                        1,
                        0,
                        0xf,
                        1,
                        0,
                        1,
                        0,
                        0,
                        0xffff
                    );

    gdt[2] = gdt_entry_gdt_data_new(
                        0,
                        1,
                        1,
                        0,
                        0xf,
                        1,
                        0,
                        1,
                        0,
                        0,
                        0xffff
                    );

    gdt[5] = gdt_entry_gdt_code_new(
                        0,
                        1,
                        0,
                        1,
                        0,
                        0xf,
                        1,
                        3,
                        1,
                        0,
                        0,
                        0xffff
                    );

    gdt[6] = gdt_entry_gdt_data_new(
                        0,
                        1,
                        1,
                        0,
                        0xf,
                        1,
                        3,
                        1,
                        0,
                        0,
                        0xffff
                    );

    gdt[7] = gdt_entry_gdt_data_new(
                       0,
                       1,
                       1,
                       0,
                       0xf,
                       1,
                       3,
                       1,
                       0,
                       0,
                       0xffff
                   );

    gdt[8] = gdt_entry_gdt_data_new(
                          0,
                          1,
                          1,
                          0,
                          0xf,
                          1,
                          3,
                          1,
                          0,
                          0,
                          0xffff
                      );

    gdt_tss = gdt_tss_new(
                  tss_base >> 32,
                  (tss_base & 0xff000000UL) >> 24,
                  1,
                  0,
                  0,
                  1,
                  0,
                  9,
                  (tss_base & 0xff0000UL) >> 16,
                  (tss_base & 0xffffUL),
                  sizeof(tss_io_t) - 1
              );

    gdt[3 ].words[0] = gdt_tss.words[0];
    gdt[3 + 1].words[0] = gdt_tss.words[1];
}

__attribute__((__section__(".boot.text"))) void
init_idt_entry(idt_entry_t *idt, interrupt_t interrupt, void(*handler)(void))
{
    uint64_t handler_addr = (uint64_t)handler;
    uint64_t dpl = 3;

    if (interrupt < int_trap_min && interrupt != int_software_break_request) {
        dpl = 0;
    }

    idt[interrupt] = idt_entry_interrupt_gate_new(
                         handler_addr >> 32,
                         ((handler_addr >> 16) & 0xffff),
                         1,
                         dpl,
                         1,
                         (1 << 3),
                         (handler_addr & 0xffff)
                     );
}

void setVMRoot(tcb_t *tcb)
{
    cap_t threadRoot;
    asid_t asid;
    pml4e_t *pml4;
    findVSpaceForASID_ret_t find_ret;
    cr3_t cr3;

    threadRoot = (((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbVTable))->cap;

    if (cap_get_capType(threadRoot) != cap_pml4_cap ||
            !cap_pml4_cap_get_capPML4IsMapped(threadRoot)) {
        setCurrentUserVSpaceRoot(kpptr_to_paddr(x64KSKernelPML4), 0);
        return;
    }

    pml4 = ((pml4e_t *)(cap_pml4_cap_get_capPML4BasePtr(threadRoot)));
    asid = cap_pml4_cap_get_capPML4MappedASID(threadRoot);
    find_ret = findVSpaceForASID(asid);
    if (__builtin_expect(!!(find_ret.status != EXCEPTION_NONE || find_ret.vspace_root != pml4), 0)) {
        setCurrentUserVSpaceRoot(kpptr_to_paddr(x64KSKernelPML4), 0);
        return;
    }
    cr3 = makeCR3(addrFromPPtr(pml4), asid);
    if (getCurrentUserCR3().words[0] != cr3.words[0]) {
        tlb_bitmap_set(pml4, getCurrentCPUIndex());
        setCurrentUserCR3(cr3);
    }
}


__attribute__((__section__(".boot.text"))) void
init_dtrs(void)
{
    gdt_idt_ptr.limit = (sizeof(gdt_entry_t) * 9) - 1;
    gdt_idt_ptr.base = (uint64_t)x86KSGlobalState[getCurrentCPUIndex()].x86KSgdt;





    swapgs();
    x64_install_gdt(&gdt_idt_ptr);
    swapgs();

    gdt_idt_ptr.limit = (sizeof(idt_entry_t) * (int_max + 1 )) - 1;
    gdt_idt_ptr.base = (uint64_t)x86KSGlobalState[getCurrentCPUIndex()].x86KSidt;
    x64_install_idt(&gdt_idt_ptr);

    x64_install_ldt(0);

    x64_install_tss((3 << 3));
}

__attribute__((__section__(".boot.text"))) void
map_it_frame_cap(cap_t pd_cap, cap_t frame_cap)
{
    pml4e_t *pml4 = ((pml4e_t *)((pptr_t)cap_get_capPtr(pd_cap)));
    pdpte_t *pdpt;
    pde_t *pd;
    pte_t *pt;
    vptr_t vptr = cap_frame_cap_get_capFMappedAddress(frame_cap);
    void *pptr = (void*)cap_frame_cap_get_capFBasePtr(frame_cap);

    if(!(cap_frame_cap_get_capFMapType(frame_cap) == X86_MappingVSpace)) _assert_fail("cap_frame_cap_get_capFMapType(frame_cap) == X86_MappingVSpace", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 545, __FUNCTION__);
    if(!(cap_frame_cap_get_capFMappedASID(frame_cap) != asidInvalid)) _assert_fail("cap_frame_cap_get_capFMappedASID(frame_cap) != asidInvalid", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 546, __FUNCTION__);
    pml4 += ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul));
    if(!(pml4e_ptr_get_present(pml4))) _assert_fail("pml4e_ptr_get_present(pml4)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 548, __FUNCTION__);
    pdpt = ptrFromPAddr(pml4e_ptr_get_pdpt_base_address(pml4));
    pdpt += ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));
    if(!(pdpte_pdpte_pd_ptr_get_present(pdpt))) _assert_fail("pdpte_pdpte_pd_ptr_get_present(pdpt)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 551, __FUNCTION__);
    pd = ptrFromPAddr(pdpte_pdpte_pd_ptr_get_pd_base_address(pdpt));
    pd += ( ((vptr) >> (((12) + 9))) & ((1ul << (9))-1ul));
    if(!(pde_pde_pt_ptr_get_present(pd))) _assert_fail("pde_pde_pt_ptr_get_present(pd)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 554, __FUNCTION__);
    pt = ptrFromPAddr(pde_pde_pt_ptr_get_pt_base_address(pd));
    *(pt + ( ((vptr) >> ((12))) & ((1ul << (9))-1ul))) = pte_new(
                                     0,
                                     addrFromPPtr(pptr),
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     0,
                                     1,
                                     1,
                                     1
                                 );
}

static __attribute__((__section__(".boot.text"))) void
map_it_pdpt_cap(cap_t vspace_cap, cap_t pdpt_cap)
{
    pml4e_t *pml4 = ((pml4e_t *)((pptr_t)cap_get_capPtr(vspace_cap)));
    pdpte_t *pdpt = ((pdpte_t *)(cap_pdpt_cap_get_capPDPTBasePtr(pdpt_cap)));
    vptr_t vptr = cap_pdpt_cap_get_capPDPTMappedAddress(pdpt_cap);

    if(!(cap_pdpt_cap_get_capPDPTIsMapped(pdpt_cap))) _assert_fail("cap_pdpt_cap_get_capPDPTIsMapped(pdpt_cap)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 578, __FUNCTION__);
    *(pml4 + ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul))) = pml4e_new(
                                         0,
                                         addrFromPPtr(pdpt),
                                         0,
                                         0,
                                         0,
                                         1,
                                         1,
                                         1
                                     );
}

__attribute__((__section__(".boot.text"))) void
map_it_pd_cap(cap_t vspace_cap, cap_t pd_cap)
{
    pml4e_t *pml4 = ((pml4e_t *)((pptr_t)cap_get_capPtr(vspace_cap)));
    pdpte_t *pdpt;
    pde_t *pd = ((pde_t *)(cap_page_directory_cap_get_capPDBasePtr(pd_cap)));
    vptr_t vptr = cap_page_directory_cap_get_capPDMappedAddress(pd_cap);

    if(!(cap_page_directory_cap_get_capPDIsMapped(pd_cap))) _assert_fail("cap_page_directory_cap_get_capPDIsMapped(pd_cap)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 599, __FUNCTION__);
    pml4 += ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul));
    if(!(pml4e_ptr_get_present(pml4))) _assert_fail("pml4e_ptr_get_present(pml4)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 601, __FUNCTION__);
    pdpt = ptrFromPAddr(pml4e_ptr_get_pdpt_base_address(pml4));
    *(pdpt + ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul))) = pdpte_pdpte_pd_new(
                                         0,
                                         addrFromPPtr(pd),
                                         0,
                                         0,
                                         0,
                                         1,
                                         1,
                                         1
                                     );
}

__attribute__((__section__(".boot.text"))) void
map_it_pt_cap(cap_t vspace_cap, cap_t pt_cap)
{
    pml4e_t *pml4 = ((pml4e_t *)((pptr_t)cap_get_capPtr(vspace_cap)));
    pdpte_t *pdpt;
    pde_t *pd;
    pte_t *pt = ((pte_t *)(cap_page_table_cap_get_capPTBasePtr(pt_cap)));
    vptr_t vptr = cap_page_table_cap_get_capPTMappedAddress(pt_cap);

    if(!(cap_page_table_cap_get_capPTIsMapped(pt_cap))) _assert_fail("cap_page_table_cap_get_capPTIsMapped(pt_cap)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 624, __FUNCTION__);
    pml4 += ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul));
    if(!(pml4e_ptr_get_present(pml4))) _assert_fail("pml4e_ptr_get_present(pml4)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 626, __FUNCTION__);
    pdpt = ptrFromPAddr(pml4e_ptr_get_pdpt_base_address(pml4));
    pdpt += ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));
    if(!(pdpte_pdpte_pd_ptr_get_present(pdpt))) _assert_fail("pdpte_pdpte_pd_ptr_get_present(pdpt)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 629, __FUNCTION__);
    pd = ptrFromPAddr(pdpte_pdpte_pd_ptr_get_pd_base_address(pdpt));
    *(pd + ( ((vptr) >> (((12) + 9))) & ((1ul << (9))-1ul))) = pde_pde_pt_new(
                                     0,
                                     addrFromPPtr(pt),
                                     0,
                                     0,
                                     0,
                                     1,
                                     1,
                                     1
                                 );
}

__attribute__((__section__(".boot.text"))) void*
map_temp_boot_page(void* entry, uint32_t large_pages)
{




    if(!((word_t)entry < (1ul << (32)))) _assert_fail("(word_t)entry < BIT(32)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 650, __FUNCTION__);
    return entry;
}

static __attribute__((__section__(".boot.text"))) cap_t
create_it_pdpt_cap(cap_t vspace_cap, pptr_t pptr, vptr_t vptr, asid_t asid)
{
    cap_t cap;
    cap = cap_pdpt_cap_new(
              asid,
              pptr,
              1,
              vptr
          );
    map_it_pdpt_cap(vspace_cap, cap);
    return cap;
}

static __attribute__((__section__(".boot.text"))) cap_t
create_it_pd_cap(cap_t vspace_cap, pptr_t pptr, vptr_t vptr, asid_t asid)
{
    cap_t cap;
    cap = cap_page_directory_cap_new(
              asid,
              pptr,
              1,
              vptr
          );
    map_it_pd_cap(vspace_cap, cap);
    return cap;
}

static __attribute__((__section__(".boot.text"))) cap_t
create_it_pt_cap(cap_t vspace_cap, pptr_t pptr, vptr_t vptr, asid_t asid)
{
    cap_t cap;
    cap = cap_page_table_cap_new(
              asid,
              pptr,
              1,
              vptr
          );
    map_it_pt_cap(vspace_cap, cap);
    return cap;
}

__attribute__((__section__(".boot.text"))) cap_t
create_it_address_space(cap_t root_cnode_cap, v_region_t it_v_reg)
{
    cap_t vspace_cap;
    vptr_t vptr;
    pptr_t pptr;
    seL4_SlotPos slot_pos_before;
    seL4_SlotPos slot_pos_after;

    slot_pos_before = ndks_boot.slot_pos_cur;

    pptr = alloc_region(12);
    if (!pptr) {
        return cap_null_cap_new();
    }
    memzero(((pml4e_t *)(pptr)), (1ul << (12)));
    copyGlobalMappings(((pml4e_t *)(pptr)));
    vspace_cap = cap_pml4_cap_new(
                     1 ,
                     pptr,
                     1
                 );


    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadVSpace)), vspace_cap);


    for (vptr = (((it_v_reg.start) >> (((((12) + 9) + 9) + 9))) << (((((12) + 9) + 9) + 9)));
            vptr < it_v_reg.end;
            vptr += (1ul << (((((12) + 9) + 9) + 9)))) {
        pptr = alloc_region(12);
        if (!pptr) {
            return cap_null_cap_new();
        }
        memzero(((pdpte_t *)(pptr)), (1ul << (12)));
        if (!provide_cap(root_cnode_cap,
                         create_it_pdpt_cap(vspace_cap, pptr, vptr, 1 ))
           ) {
            return cap_null_cap_new();
        }
    }


    for (vptr = (((it_v_reg.start) >> ((((12) + 9) + 9))) << ((((12) + 9) + 9)));
            vptr < it_v_reg.end;
            vptr += (1ul << ((((12) + 9) + 9)))) {
        pptr = alloc_region(12);
        if (!pptr) {
            return cap_null_cap_new();
        }
        memzero(((pde_t *)(pptr)), (1ul << (12)));
        if (!provide_cap(root_cnode_cap,
                         create_it_pd_cap(vspace_cap, pptr, vptr, 1 ))
           ) {
            return cap_null_cap_new();
        }
    }


    for (vptr = (((it_v_reg.start) >> (((12) + 9))) << (((12) + 9)));
            vptr < it_v_reg.end;
            vptr += (1ul << (((12) + 9)))) {
        pptr = alloc_region(12);
        if (!pptr) {
            return cap_null_cap_new();
        }
        memzero(((pte_t *)(pptr)), (1ul << (12)));
        if (!provide_cap(root_cnode_cap,
                         create_it_pt_cap(vspace_cap, pptr, vptr, 1 ))
           ) {
            return cap_null_cap_new();
        }
    }

    slot_pos_after = ndks_boot.slot_pos_cur;
    ndks_boot.bi_frame->userImagePaging = (seL4_SlotRegion) {
        slot_pos_before, slot_pos_after
    };
    return vspace_cap;
}

void copyGlobalMappings(vspace_root_t *new_vspace)
{
    unsigned long i;
    pml4e_t *vspace = (pml4e_t *)new_vspace;





    for (i = ( (((0xffffff8000000000ul - ((((16 - 1) / ((1 << 6) - 1)) + 1) * (1ul << (((((12) + 9) + 9) + 9)))))) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul)); i < (1ul << (9)); i++) {
        vspace[i] = x64KSKernelPML4[i];
    }
}

static __attribute__((__section__(".boot.text"))) cap_t
create_it_frame_cap(pptr_t pptr, vptr_t vptr, asid_t asid, bool_t use_large, seL4_Word map_type)
{
    vm_page_size_t frame_size;

    if (use_large) {
        frame_size = X86_LargePage;
    } else {
        frame_size = X86_SmallPage;
    }

    return
        cap_frame_cap_new(
            asid,
            pptr,
            frame_size,
            map_type,
            vptr,
            wordFromVMRights(VMReadWrite),
            0
        );
}

__attribute__((__section__(".boot.text"))) cap_t
create_unmapped_it_frame_cap(pptr_t pptr, bool_t use_large)
{
    return create_it_frame_cap(pptr, 0, asidInvalid, use_large, X86_MappingNone);
}

__attribute__((__section__(".boot.text"))) cap_t
create_mapped_it_frame_cap(cap_t vspace_cap, pptr_t pptr, vptr_t vptr, asid_t asid, bool_t use_large, bool_t executable __attribute__((unused)))
{
    cap_t cap = create_it_frame_cap(pptr, vptr, asid, use_large, X86_MappingVSpace);
    map_it_frame_cap(vspace_cap, cap);
    return cap;
}





exception_t
performASIDPoolInvocation(asid_t asid, asid_pool_t *poolPtr, cte_t *vspaceCapSlot)
{
    asid_map_t asid_map;

    if (cap_get_capType(vspaceCapSlot->cap) == cap_ept_pml4_cap) {
        cap_ept_pml4_cap_ptr_set_capPML4MappedASID(&vspaceCapSlot->cap, asid);
        cap_ept_pml4_cap_ptr_set_capPML4IsMapped(&vspaceCapSlot->cap, 1);
        asid_map = asid_map_asid_map_ept_new(cap_ept_pml4_cap_get_capPML4BasePtr(vspaceCapSlot->cap));
    } else

    {
        if(!(cap_get_capType(vspaceCapSlot->cap) == cap_pml4_cap)) _assert_fail("cap_get_capType(vspaceCapSlot->cap) == cap_pml4_cap", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 844, __FUNCTION__);
        cap_pml4_cap_ptr_set_capPML4MappedASID(&vspaceCapSlot->cap, asid);
        cap_pml4_cap_ptr_set_capPML4IsMapped(&vspaceCapSlot->cap, 1);
        asid_map = asid_map_asid_map_vspace_new(cap_pml4_cap_get_capPML4BasePtr(vspaceCapSlot->cap));
    }
    poolPtr->array[asid & ((1ul << (asidLowBits))-1ul)] = asid_map;
    return EXCEPTION_NONE;
}

bool_t __attribute__((__const__))
isVTableRoot(cap_t cap)
{
    return cap_get_capType(cap) == cap_pml4_cap;
}

bool_t __attribute__((__const__))
isValidNativeRoot(cap_t cap)
{
    return isVTableRoot(cap) &&
           cap_pml4_cap_get_capPML4IsMapped(cap);
}

static pml4e_t __attribute__((__const__))
makeUserPML4E(paddr_t paddr, vm_attributes_t vm_attr)
{
    return pml4e_new(
               0,
               paddr,
               0,
               vm_attributes_get_x86PCDBit(vm_attr),
               vm_attributes_get_x86PWTBit(vm_attr),
               1,
               1,
               1
           );
}

static pml4e_t __attribute__((__const__))
makeUserPML4EInvalid(void)
{
    return pml4e_new(
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0
           );
}

static pdpte_t __attribute__((__const__))
makeUserPDPTEHugePage(paddr_t paddr, vm_attributes_t vm_attr, vm_rights_t vm_rights)
{
    return pdpte_pdpte_1g_new(
               0,
               paddr,
               0,
               0,
               0,
               0,
               vm_attributes_get_x86PCDBit(vm_attr),
               vm_attributes_get_x86PWTBit(vm_attr),
               SuperUserFromVMRights(vm_rights),
               WritableFromVMRights(vm_rights),
               1
           );
}

static pdpte_t __attribute__((__const__))
makeUserPDPTEPageDirectory(paddr_t paddr, vm_attributes_t vm_attr)
{
    return pdpte_pdpte_pd_new(
               0,
               paddr,
               0,
               vm_attributes_get_x86PCDBit(vm_attr),
               vm_attributes_get_x86PWTBit(vm_attr),
               1,
               1,
               1
           );
}

static pdpte_t __attribute__((__const__))
makeUserPDPTEInvalid(void)
{
    return pdpte_pdpte_pd_new(
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0
           );
}

pde_t __attribute__((__const__))
makeUserPDELargePage(paddr_t paddr, vm_attributes_t vm_attr, vm_rights_t vm_rights)
{
    return pde_pde_large_new(
               0,
               paddr,
               vm_attributes_get_x86PATBit(vm_attr),
               0,
               0,
               0,
               vm_attributes_get_x86PCDBit(vm_attr),
               vm_attributes_get_x86PWTBit(vm_attr),
               SuperUserFromVMRights(vm_rights),
               WritableFromVMRights(vm_rights),
               1
           );
}

pde_t __attribute__((__const__))
makeUserPDEPageTable(paddr_t paddr, vm_attributes_t vm_attr)
{

    return pde_pde_pt_new(
                0,
                paddr,
                0,
                vm_attributes_get_x86PCDBit(vm_attr),
                vm_attributes_get_x86PWTBit(vm_attr),
                1,
                1,
                1
            );
}

pde_t __attribute__((__const__))
makeUserPDEInvalid(void)
{



    return pde_pde_pt_new(
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0
           );
}

pte_t __attribute__((__const__))
makeUserPTE(paddr_t paddr, vm_attributes_t vm_attr, vm_rights_t vm_rights)
{
    return pte_new(
               0,
               paddr,
               0,
               vm_attributes_get_x86PATBit(vm_attr),
               0,
               0,
               vm_attributes_get_x86PCDBit(vm_attr),
               vm_attributes_get_x86PWTBit(vm_attr),
               SuperUserFromVMRights(vm_rights),
               WritableFromVMRights(vm_rights),
               1
           );
}

pte_t __attribute__((__const__))
makeUserPTEInvalid(void)
{
    return pte_new(
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0
           );
}


static pml4e_t*
lookupPML4Slot(vspace_root_t*pml4, vptr_t vptr)
{
    pml4e_t *pml4e = ((pml4e_t *)(pml4));
    word_t pml4Index = ( ((vptr) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul));
    return pml4e + pml4Index;
}

static lookupPDPTSlot_ret_t
lookupPDPTSlot(vspace_root_t *pml4, vptr_t vptr)
{
    pml4e_t *pml4Slot = lookupPML4Slot(pml4, vptr);
    lookupPDPTSlot_ret_t ret;

    if (!pml4e_ptr_get_present(pml4Slot)) {
        current_lookup_fault = lookup_fault_missing_capability_new(((((12) + 9) + 9) + 9));

        ret.pdptSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    } else {
        pdpte_t *pdpt;
        pdpte_t *pdptSlot;
        word_t pdptIndex = ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));
        pdpt = ptrFromPAddr(pml4e_ptr_get_pdpt_base_address(pml4Slot));
        pdptSlot = pdpt + pdptIndex;

        ret.status = EXCEPTION_NONE;
        ret.pdptSlot = pdptSlot;
        return ret;
    }
}

lookupPDSlot_ret_t
lookupPDSlot(vspace_root_t *pml4, vptr_t vptr)
{
    lookupPDPTSlot_ret_t pdptSlot;
    lookupPDSlot_ret_t ret;

    pdptSlot = lookupPDPTSlot(pml4, vptr);

    if (pdptSlot.status != EXCEPTION_NONE) {
        ret.pdSlot = ((void *)0);
        ret.status = pdptSlot.status;
        return ret;
    }
    if ((pdpte_ptr_get_page_size(pdptSlot.pdptSlot) != pdpte_pdpte_pd) ||
            !pdpte_pdpte_pd_ptr_get_present(pdptSlot.pdptSlot)) {
        current_lookup_fault = lookup_fault_missing_capability_new((((12) + 9) + 9));

        ret.pdSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    } else {
        pde_t *pd;
        pde_t *pdSlot;
        word_t pdIndex = ( ((vptr) >> (((12) + 9))) & ((1ul << (9))-1ul));
        pd = ptrFromPAddr(pdpte_pdpte_pd_ptr_get_pd_base_address(pdptSlot.pdptSlot));
        pdSlot = pd + pdIndex;

        ret.status = EXCEPTION_NONE;
        ret.pdSlot = pdSlot;
        return ret;
    }
}

static void
flushPD(vspace_root_t *vspace, word_t vptr, pde_t *pd, asid_t asid)
{




    invalidateASID(vspace, asid, tlb_bitmap_get(vspace));

}

static void
flushPDPT(vspace_root_t *vspace, word_t vptr, pdpte_t *pdpt, asid_t asid)
{

    invalidateASID(vspace, asid, tlb_bitmap_get(vspace));
    return;
}

void
hwASIDInvalidate(asid_t asid, vspace_root_t *vspace)
{
    invalidateASID(vspace, asid, tlb_bitmap_get(vspace));
}

void
unmapPageDirectory(asid_t asid, vptr_t vaddr, pde_t *pd)
{
    findVSpaceForASID_ret_t find_ret;
    lookupPDPTSlot_ret_t lu_ret;

    find_ret = findVSpaceForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        return;
    }

    lu_ret = lookupPDPTSlot(find_ret.vspace_root, vaddr);
    if (lu_ret.status != EXCEPTION_NONE) {
        return;
    }


    if (! (pdpte_ptr_get_page_size(lu_ret.pdptSlot) == pdpte_pdpte_pd &&
            pdpte_pdpte_pd_ptr_get_present(lu_ret.pdptSlot) &&
            (pdpte_pdpte_pd_ptr_get_pd_base_address(lu_ret.pdptSlot) == addrFromPPtr(pd)))) {
        return;
    }

    flushPD(find_ret.vspace_root, vaddr, pd, asid);

    *lu_ret.pdptSlot = makeUserPDPTEInvalid();

    invalidatePageStructureCacheASID(addrFromPPtr(find_ret.vspace_root), asid,
                                     tlb_bitmap_get(find_ret.vspace_root));
}


static exception_t
performX64PageDirectoryInvocationUnmap(cap_t cap, cte_t *ctSlot)
{

    if (cap_page_directory_cap_get_capPDIsMapped(cap)) {
        pde_t *pd = ((pde_t *)(cap_page_directory_cap_get_capPDBasePtr(cap)));
        unmapPageDirectory(
            cap_page_directory_cap_get_capPDMappedASID(cap),
            cap_page_directory_cap_get_capPDMappedAddress(cap),
            pd
        );
        clearMemory((void *)pd, cap_get_capSizeBits(cap));
    }

    cap_page_directory_cap_ptr_set_capPDIsMapped(&(ctSlot->cap), 0);

    return EXCEPTION_NONE;
}

static exception_t
performX64PageDirectoryInvocationMap(cap_t cap, cte_t *ctSlot, pdpte_t pdpte, pdpte_t *pdptSlot, vspace_root_t *vspace)
{
    ctSlot->cap = cap;
    *pdptSlot = pdpte;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), cap_page_directory_cap_get_capPDMappedASID(cap),
                                     tlb_bitmap_get(vspace));
    return EXCEPTION_NONE;
}


static exception_t
decodeX64PageDirectoryInvocation(
    word_t label,
    word_t length,
    cte_t* cte,
    cap_t cap,
    extra_caps_t extraCaps,
    word_t* buffer
)
{
    word_t vaddr;
    vm_attributes_t vm_attr;
    cap_t vspaceCap;
    vspace_root_t *vspace;
    pdpte_t pdpte;
    paddr_t paddr;
    asid_t asid;
    lookupPDPTSlot_ret_t pdptSlot;

    if (label == X86PageDirectoryUnmap) {
        if (!isFinalCapability(cte)) {
            current_syscall_error.type = seL4_RevokeFirst;
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1208, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86PageDirectory: Cannot unmap if more than one cap exist."); kprintf(">>" "" "\n"); } while (0);
            return EXCEPTION_SYSCALL_ERROR;
        }
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);

        return performX64PageDirectoryInvocationUnmap(cap, cte);
    }

    if (label != X86PageDirectoryMap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1217, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X64Directory: Illegal operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 2 || extraCaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1223, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X64PageDirectory: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cap_page_directory_cap_get_capPDIsMapped(cap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1229, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X64PageDirectory: PD is already mapped to a PML4."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vaddr = getSyscallArg(0, buffer) & (~((1ul << ((((12) + 9) + 9)))-1ul));
    vm_attr = vmAttributesFromWord(getSyscallArg(1, buffer));
    vspaceCap = extraCaps.excaprefs[0]->cap;

    if (!isValidNativeRoot(vspaceCap)) {
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vspace = (vspace_root_t *)(pptr_t)cap_get_capPtr(vspaceCap);
    asid = cap_get_capMappedASID(vspaceCap);

    if (vaddr >= 0x7FFFFFFFFFFF) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1251, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X64PageDirectory: Mapping address too high."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    pdptSlot = lookupPDPTSlot(vspace, vaddr);
    if (pdptSlot.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if ((pdpte_ptr_get_page_size(pdptSlot.pdptSlot) == pdpte_pdpte_pd &&
            pdpte_pdpte_pd_ptr_get_present(pdptSlot.pdptSlot)) ||
            (pdpte_ptr_get_page_size(pdptSlot.pdptSlot) == pdpte_pdpte_1g
             && pdpte_pdpte_1g_ptr_get_present(pdptSlot.pdptSlot))) {
        current_syscall_error.type = seL4_DeleteFirst;

        return EXCEPTION_SYSCALL_ERROR;
    }

    paddr = addrFromPPtr(((pde_t *)(cap_page_directory_cap_get_capPDBasePtr(cap))));
    pdpte = makeUserPDPTEPageDirectory(paddr, vm_attr);

    cap = cap_page_directory_cap_set_capPDIsMapped(cap, 1);
    cap = cap_page_directory_cap_set_capPDMappedASID(cap, asid);
    cap = cap_page_directory_cap_set_capPDMappedAddress(cap, vaddr);

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return performX64PageDirectoryInvocationMap(cap, cte, pdpte, pdptSlot.pdptSlot, vspace);
}

static void unmapPDPT(asid_t asid, vptr_t vaddr, pdpte_t *pdpt)
{
    findVSpaceForASID_ret_t find_ret;
    pml4e_t *pml4Slot;

    find_ret = findVSpaceForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        return;
    }

    pml4Slot = lookupPML4Slot(find_ret.vspace_root, vaddr);


    if (! (pml4e_ptr_get_present(pml4Slot) &&
            pml4e_ptr_get_pdpt_base_address(pml4Slot) == addrFromPPtr(pdpt))) {
        return;
    }

    flushPDPT(find_ret.vspace_root, vaddr, pdpt, asid);

    *pml4Slot = makeUserPML4EInvalid();
}

static exception_t
performX64PDPTInvocationUnmap(cap_t cap, cte_t *ctSlot)
{
    if (cap_pdpt_cap_get_capPDPTIsMapped(cap)) {
        pdpte_t *pdpt = ((pdpte_t *)(cap_pdpt_cap_get_capPDPTBasePtr(cap)));
        unmapPDPT(cap_pdpt_cap_get_capPDPTMappedASID(cap),
                  cap_pdpt_cap_get_capPDPTMappedAddress(cap),
                  pdpt);
        clearMemory((void *)pdpt, cap_get_capSizeBits(cap));
    }

    cap_pdpt_cap_ptr_set_capPDPTIsMapped(&(ctSlot->cap), 0);

    return EXCEPTION_NONE;
}

static exception_t
performX64PDPTInvocationMap(cap_t cap, cte_t *ctSlot, pml4e_t pml4e, pml4e_t *pml4Slot, vspace_root_t *vspace)
{
    ctSlot->cap = cap;
    *pml4Slot = pml4e;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), cap_pdpt_cap_get_capPDPTMappedASID(cap),
                                     tlb_bitmap_get(vspace));

    return EXCEPTION_NONE;
}

static exception_t
decodeX64PDPTInvocation(
    word_t label,
    word_t length,
    cte_t *cte,
    cap_t cap,
    extra_caps_t extraCaps,
    word_t *buffer)
{
    word_t vaddr;
    vm_attributes_t attr;
    pml4e_t *pml4Slot;
    cap_t vspaceCap;
    vspace_root_t *vspace;
    pml4e_t pml4e;
    paddr_t paddr;
    asid_t asid;

    if (label == X86PDPTUnmap) {
        if (!isFinalCapability(cte)) {
            current_syscall_error.type = seL4_RevokeFirst;
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1357, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86PDPT: Cannot unmap if more than one cap exist."); kprintf(">>" "" "\n"); } while (0);
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);

        return performX64PDPTInvocationUnmap(cap, cte);
    }

    if (label != X86PDPTMap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1367, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86PDPT: Illegal operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 2 || extraCaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1373, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X64PDPT: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cap_pdpt_cap_get_capPDPTIsMapped(cap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1379, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X64PDPT: PDPT is already mapped to a PML4."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vaddr = getSyscallArg(0, buffer) & (~((1ul << (((((12) + 9) + 9) + 9)))-1ul));
    attr = vmAttributesFromWord(getSyscallArg(1, buffer));
    vspaceCap = extraCaps.excaprefs[0]->cap;

    if (!isValidNativeRoot(vspaceCap)) {
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vspace = (vspace_root_t *)(pptr_t)cap_get_capPtr(vspaceCap);
    asid = cap_get_capMappedASID(vspaceCap);

    if (vaddr >= 0x7FFFFFFFFFFF) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1401, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X64PDPT: Mapping address too high."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    pml4Slot = lookupPML4Slot(vspace, vaddr);

    if (pml4e_ptr_get_present(pml4Slot)) {
        current_syscall_error.type = seL4_DeleteFirst;

        return EXCEPTION_SYSCALL_ERROR;
    }

    paddr = addrFromPPtr(((pdpte_t *)((cap_pdpt_cap_get_capPDPTBasePtr(cap)))));
    pml4e = makeUserPML4E(paddr, attr);

    cap = cap_pdpt_cap_set_capPDPTIsMapped(cap, 1);
    cap = cap_pdpt_cap_set_capPDPTMappedASID(cap, asid);
    cap = cap_pdpt_cap_set_capPDPTMappedAddress(cap, vaddr);

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return performX64PDPTInvocationMap(cap, cte, pml4e, pml4Slot, vspace);
}

exception_t
decodeX86ModeMMUInvocation(
    word_t label,
    word_t length,
    cptr_t cptr,
    cte_t* cte,
    cap_t cap,
    extra_caps_t extraCaps,
    word_t* buffer
)
{
    switch (cap_get_capType(cap)) {

    case cap_pml4_cap:
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;

    case cap_pdpt_cap:
        return decodeX64PDPTInvocation(label, length, cte, cap, extraCaps, buffer);

    case cap_page_directory_cap:
        return decodeX64PageDirectoryInvocation(label, length, cte, cap, extraCaps, buffer);

    default:
        _fail("Invalid arch cap type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 1451, __func__);
    }
}

bool_t modeUnmapPage(vm_page_size_t page_size, vspace_root_t *vroot, vptr_t vaddr, void *pptr)
{
    if (0 && page_size == X64_HugePage) {
        pdpte_t *pdpte;
        lookupPDPTSlot_ret_t pdpt_ret = lookupPDPTSlot(vroot, vaddr);
        if (pdpt_ret.status != EXCEPTION_NONE) {
            return false;
        }
        pdpte = pdpt_ret.pdptSlot;


        if (! (pdpte_ptr_get_page_size(pdpte) == pdpte_pdpte_1g
                && pdpte_pdpte_1g_ptr_get_present(pdpte)
                && (pdpte_pdpte_1g_ptr_get_page_base_address(pdpte)
                     == addrFromPPtr(pptr)))) {
            return false;
        }

        *pdpte = makeUserPDPTEInvalid();
        return true;
    }
    _fail("Invalid page type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 1476, __func__);
    return false;
}

static exception_t
performX64ModeMapRemapPage(cap_t cap, cte_t *ctSlot, pdpte_t pdpte, pdpte_t *pdptSlot, vspace_root_t *vspace)
{
    ctSlot->cap = cap;
    *pdptSlot = pdpte;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), cap_frame_cap_get_capFMappedASID(cap),
                                     tlb_bitmap_get(vspace));
    return EXCEPTION_NONE;
}


exception_t
decodeX86ModeMapRemapPage(word_t label, vm_page_size_t page_size, cte_t *cte, cap_t cap, vspace_root_t *vroot, vptr_t vaddr, paddr_t paddr, vm_rights_t vm_rights, vm_attributes_t vm_attr)
{
    if (0 && page_size == X64_HugePage) {
        pdpte_t pdpte;
        pdpte_t *pdptSlot;
        lookupPDPTSlot_ret_t lu_ret;
        lu_ret = lookupPDPTSlot(vroot, vaddr);

        if (lu_ret.status != EXCEPTION_NONE) {
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = false;
            return EXCEPTION_SYSCALL_ERROR;
        }

        pdptSlot = lu_ret.pdptSlot;
        switch (label) {

        case X86PageMap: {

            if ((pdpte_ptr_get_page_size(pdptSlot) == pdpte_pdpte_pd) &&
                    (pdpte_pdpte_pd_ptr_get_present(pdptSlot))) {
                current_syscall_error.type = seL4_DeleteFirst;
                return EXCEPTION_SYSCALL_ERROR;
            }

            if ((pdpte_ptr_get_page_size(pdptSlot) == pdpte_pdpte_1g) &&
                    (pdpte_pdpte_1g_ptr_get_present(pdptSlot))) {
                current_syscall_error.type = seL4_DeleteFirst;
                return EXCEPTION_SYSCALL_ERROR;
            }

            pdpte = makeUserPDPTEHugePage(paddr, vm_attr, vm_rights);
            setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
            return performX64ModeMapRemapPage(cap, cte, pdpte, pdptSlot, vroot);
        }

        case X86PageRemap: {

            if ((pdpte_ptr_get_page_size(pdptSlot) == pdpte_pdpte_pd) &&
                    (pdpte_pdpte_pd_ptr_get_present(pdptSlot))) {
                current_syscall_error.type = seL4_DeleteFirst;
                return EXCEPTION_SYSCALL_ERROR;
            }

            pdpte = makeUserPDPTEHugePage(paddr, vm_attr, vm_rights);
            setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
            return performX64ModeMapRemapPage(cap, cte, pdpte, pdptSlot, vroot);
        }

        default: {
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }
        }
    }
    _fail("Invalid Page type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/kernel/vspace.c", 1547, __func__);
}


typedef struct readWordFromVSpace_ret {
    exception_t status;
    word_t value;
} readWordFromVSpace_ret_t;

static readWordFromVSpace_ret_t
readWordFromVSpace(vspace_root_t *vspace, word_t vaddr)
{
    readWordFromVSpace_ret_t ret;
    lookupPTSlot_ret_t ptSlot;
    lookupPDSlot_ret_t pdSlot;
    lookupPDPTSlot_ret_t pdptSlot;
    paddr_t paddr;
    word_t offset;
    pptr_t kernel_vaddr;
    word_t *value;

    pdptSlot = lookupPDPTSlot(vspace, vaddr);
    if (pdptSlot.status == EXCEPTION_NONE &&
            pdpte_ptr_get_page_size(pdptSlot.pdptSlot) == pdpte_pdpte_1g &&
            pdpte_pdpte_1g_ptr_get_present(pdptSlot.pdptSlot)) {

        paddr = pdpte_pdpte_1g_ptr_get_page_base_address(pdptSlot.pdptSlot);
        offset = vaddr & ((1ul << (30))-1ul);
    } else {
        pdSlot = lookupPDSlot(vspace, vaddr);
        if (pdSlot.status == EXCEPTION_NONE &&
                ((pde_ptr_get_page_size(pdSlot.pdSlot) == pde_pde_large) &&
                 pde_pde_large_ptr_get_present(pdSlot.pdSlot))) {

            paddr = pde_pde_large_ptr_get_page_base_address(pdSlot.pdSlot);
            offset = vaddr & ((1ul << (21))-1ul);
        } else {
            ptSlot = lookupPTSlot(vspace, vaddr);
            if (ptSlot.status == EXCEPTION_NONE && pte_ptr_get_present(ptSlot.ptSlot)) {
                paddr = pte_ptr_get_page_base_address(ptSlot.ptSlot);
                offset = vaddr & ((1ul << (12))-1ul);
            } else {
                ret.status = EXCEPTION_LOOKUP_FAULT;
                return ret;
            }
        }
    }


    kernel_vaddr = (word_t)ptrFromPAddr(paddr);
    value = (word_t*)(kernel_vaddr + offset);
    ret.status = EXCEPTION_NONE;
    ret.value = *value;
    return ret;
}

void
Arch_userStackTrace(tcb_t *tptr)
{
    cap_t threadRoot;
    vspace_root_t *vspace_root;
    word_t sp;
    int i;

    threadRoot = (((cte_t *)((word_t)(tptr)&~((1ul << (11))-1ul)))+(tcbVTable))->cap;


    if (cap_get_capType(threadRoot) != cap_pml4_cap) {
        kprintf("Invalid vspace\n");
        return;
    }

    vspace_root = (vspace_root_t*)(pptr_t)cap_get_capPtr(threadRoot);

    sp = getRegister(tptr, RSP);


    if (!(!((sp) & ((1ul << (3))-1ul)))) {
        kprintf("RSP not aligned\n");
        return;
    }

    for (i = 0; i < 1; i++) {
        word_t address = sp + (i * sizeof(word_t));
        readWordFromVSpace_ret_t result;
        result = readWordFromVSpace(vspace_root, address);
        if (result.status == EXCEPTION_NONE) {
            kprintf("0x%lx: 0x%lx\n", (long)address, (long)result.value);
        } else {
            kprintf("0x%lx: INVALID\n", (long)address);
        }
    }
}

const register_t msgRegisters[] = {
    R10, R8, R9, R15
};

const register_t frameRegisters[] = {
    FaultIP, RSP, FLAGS, RAX, RBX, RCX, RDX, RSI, RDI, RBP,
    R8, R9, R10, R11, R12, R13, R14, R15
};

const register_t gpRegisters[] = {
    TLS_BASE
};

const register_t syscallMessage[] = {
    [seL4_UnknownSyscall_RAX] = RAX,
    [seL4_UnknownSyscall_RBX] = RBX,
    [seL4_UnknownSyscall_RCX] = RCX,
    [seL4_UnknownSyscall_RDX] = RDX,
    [seL4_UnknownSyscall_RSI] = RSI,
    [seL4_UnknownSyscall_RDI] = RDI,
    [seL4_UnknownSyscall_RBP] = RBP,
    [seL4_UnknownSyscall_R8] = R8,
    [seL4_UnknownSyscall_R9] = R9,
    [seL4_UnknownSyscall_R10] = R10,
    [seL4_UnknownSyscall_R11] = R11,
    [seL4_UnknownSyscall_R12] = R12,
    [seL4_UnknownSyscall_R13] = R13,
    [seL4_UnknownSyscall_R14] = R14,
    [seL4_UnknownSyscall_R15] = R15,
    [seL4_UnknownSyscall_FaultIP] = FaultIP,
    [seL4_UnknownSyscall_SP] = RSP,
    [seL4_UnknownSyscall_FLAGS] = FLAGS
};

void Mode_initContext(user_context_t* context)
{
    context->registers[RAX] = 0;
    context->registers[RBX] = 0;
    context->registers[RCX] = 0;
    context->registers[RDX] = 0;
    context->registers[RSI] = 0;
    context->registers[RDI] = 0;
    context->registers[RBP] = 0;
    context->registers[R8] = 0;
    context->registers[R9] = 0;
    context->registers[R10] = 0;
    context->registers[R11] = 0;
    context->registers[R12] = 0;
    context->registers[R13] = 0;
    context->registers[R14] = 0;
    context->registers[R15] = 0;
    context->registers[RSP] = 0;
}

word_t Mode_sanitiseRegister(register_t reg, word_t v)
{
    if (reg == FaultIP || reg == NextIP) {

        if (v > 0x00007fffffffffff && v < 0xffff800000000000) {

            v = 0;
        }
    }
    return v;
}



nodeInfo_t node_info[16] __attribute__((__aligned__(64))) __attribute__((externally_visible));
char nodeSkimScratch[16][sizeof(nodeInfo_t)] __attribute__((__aligned__(64)));
extern char kernel_stack_alloc[16][(1ul << (12))];

__attribute__((__section__(".boot.text"))) void
mode_init_tls(cpu_id_t cpu_index)
{
    node_info[cpu_index].stackTop = kernel_stack_alloc[cpu_index + 1];
    node_info[cpu_index].irqStack = &x64KSIRQStack[cpu_index][0];
    node_info[cpu_index].index = cpu_index;
    x86_wrmsr(0xC0000102, (word_t)&node_info[cpu_index]);
    swapgs();
}


pml4e_t x64KSKernelPML4[(1ul << (9))] __attribute__((__aligned__((1ul << (12))))) __attribute__((externally_visible));
pdpte_t x64KSKernelPDPT[(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));



pde_t x64KSKernelPDs[(1ul << (9))][(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));

pte_t x64KSKernelPT[(1ul << (9))] __attribute__((__aligned__((1ul << (12)))));
;


word_t x64KSIRQStack[16][6 + 2] __attribute__((__aligned__(64))) __attribute__((externally_visible)) __attribute__((__section__(".skim.bss")));



exception_t decodeX86PortInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t *slot, cap_t cap, extra_caps_t excaps, word_t* buffer);



struct EPTPDPTMapped_ret {
    ept_pml4e_t *pml4;
    ept_pml4e_t *pml4Slot;
    exception_t status;
};
typedef struct EPTPDPTMapped_ret EPTPDPTMapped_ret_t;

struct EPTPageDirectoryMapped_ret {
    ept_pml4e_t *pml4;
    ept_pdpte_t *pdptSlot;
    exception_t status;
};
typedef struct EPTPageDirectoryMapped_ret EPTPageDirectoryMapped_ret_t;

struct EPTPageTableMapped_ret {
    ept_pml4e_t *pml4;
    ept_pde_t *pdSlot;
    exception_t status;
};
typedef struct EPTPageTableMapped_ret EPTPageTableMapped_ret_t;

struct findEPTForASID_ret {
    exception_t status;
    ept_pml4e_t *ept;
};
typedef struct findEPTForASID_ret findEPTForASID_ret_t;

EPTPDPTMapped_ret_t EPTPDPTMapped(asid_t asid, vptr_t vptr, ept_pdpte_t *pdpt);
EPTPageDirectoryMapped_ret_t EPTPageDirectoryMapped(asid_t asid, vptr_t vaddr, ept_pde_t *pd);
EPTPageTableMapped_ret_t EPTPageTableMapped(asid_t asid, vptr_t vaddr, ept_pte_t *pt);
findEPTForASID_ret_t findEPTForASID(asid_t asid);

void deleteEPTASID(asid_t asid, ept_pml4e_t *ept);
exception_t decodeX86EPTInvocation(word_t invLabel, word_t length, cptr_t cptr, cte_t* cte, cap_t cap, extra_caps_t excaps, word_t* buffer);
exception_t decodeX86EPTPDInvocation(word_t invLabel, word_t length, cte_t* cte, cap_t cap, extra_caps_t excaps, word_t* buffer);
exception_t decodeX86EPTPTInvocation(word_t invLabel, word_t length, cte_t* cte, cap_t cap, extra_caps_t excaps, word_t* buffer);
exception_t decodeX86EPTPageMap(word_t invLabel, word_t length, cte_t* cte, cap_t cap, extra_caps_t excaps, word_t* buffer);
exception_t performX86EPTPageInvocationUnmap(cap_t cap, cte_t *ctSlot);
void unmapEPTPDPT(asid_t asid, vptr_t vaddr, ept_pdpte_t *pdpt);
void unmapEPTPageDirectory(asid_t asid, vptr_t vaddr, ept_pde_t *pd);
void unmapEPTPageTable(asid_t asid, vptr_t vaddr, ept_pte_t *pt);
void unmapEPTPage(vm_page_size_t page_size, asid_t asid, vptr_t vptr, void *pptr);



bool_t
Arch_isFrameType(word_t type)
{
    switch (type) {
    case seL4_X86_4K:
        return true;
    case seL4_X86_LargePageObject:
        return true;
    case 0xfffffffe:
        return true;
    default:
        return false;
    }
}

deriveCap_ret_t
Mode_deriveCap(cte_t* slot, cap_t cap)
{
    deriveCap_ret_t ret;

    switch (cap_get_capType(cap)) {
    case cap_pml4_cap:
        if (cap_pml4_cap_get_capPML4IsMapped(cap)) {
            ret.cap = cap;
            ret.status = EXCEPTION_NONE;
        } else {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 55, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Deriving a PML4 cap without an assigned ASID"); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            ret.cap = cap_null_cap_new();
            ret.status = EXCEPTION_SYSCALL_ERROR;
        }
        return ret;

    case cap_frame_cap:
        cap = cap_frame_cap_set_capFMapType(cap, X86_MappingNone);
        ret.cap = cap_frame_cap_set_capFMappedASID(cap, asidInvalid);
        ret.status = EXCEPTION_NONE;
        return ret;

    default:
        _fail("Invalid arch cap type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/object/objecttype.c", 69, __func__);
    }
}

finaliseCap_ret_t Mode_finaliseCap(cap_t cap, bool_t final)
{
    finaliseCap_ret_t fc_ret;

    switch (cap_get_capType(cap)) {

    case cap_pml4_cap:
        if (final && cap_pml4_cap_get_capPML4IsMapped(cap)) {
            deleteASID(
                cap_pml4_cap_get_capPML4MappedASID(cap),
                ((pml4e_t *)(cap_pml4_cap_get_capPML4BasePtr(cap)))
            );
        }
        break;

    case cap_pdpt_cap:
        if (final && cap_pdpt_cap_get_capPDPTIsMapped(cap)) {
            unmapPDPT(
                cap_pdpt_cap_get_capPDPTMappedASID(cap),
                cap_pdpt_cap_get_capPDPTMappedAddress(cap),
                ((pdpte_t *)(cap_pdpt_cap_get_capPDPTBasePtr(cap)))
            );
        }
        break;

    case cap_frame_cap:
        if (cap_frame_cap_get_capFMappedASID(cap)) {
            switch (cap_frame_cap_get_capFMapType(cap)) {

            case X86_MappingEPT:
                unmapEPTPage(
                    cap_frame_cap_get_capFSize(cap),
                    cap_frame_cap_get_capFMappedASID(cap),
                    cap_frame_cap_get_capFMappedAddress(cap),
                    (void *)cap_frame_cap_get_capFBasePtr(cap)
                );
                break;






            case X86_MappingVSpace:
                unmapPage(
                    cap_frame_cap_get_capFSize(cap),
                    cap_frame_cap_get_capFMappedASID(cap),
                    cap_frame_cap_get_capFMappedAddress(cap),
                    (void *)cap_frame_cap_get_capFBasePtr(cap)
                );
                break;
            default:
                _fail("Invalid map type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/object/objecttype.c", 125, __func__);
            }
        }
        break;

    default:
        _fail("Invalid arch cap type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/object/objecttype.c", 131, __func__);
    }

    fc_ret.remainder = cap_null_cap_new();
    fc_ret.cleanupInfo = cap_null_cap_new();
    return fc_ret;
}

bool_t __attribute__((__const__)) Mode_sameRegionAs(cap_t cap_a, cap_t cap_b)
{
    switch (cap_get_capType(cap_a)) {

    case cap_pdpt_cap:
        if (cap_get_capType(cap_b) == cap_pdpt_cap) {
            return cap_pdpt_cap_get_capPDPTBasePtr(cap_a) ==
                   cap_pdpt_cap_get_capPDPTBasePtr(cap_b);
        }
        return false;

    case cap_pml4_cap:
        if (cap_get_capType(cap_b) == cap_pml4_cap) {
            return cap_pml4_cap_get_capPML4BasePtr(cap_a) ==
                   cap_pml4_cap_get_capPML4BasePtr(cap_b);
        }
        return false;
    default:
        return false;
    }
}

word_t
Mode_getObjectSize(word_t t)
{
    switch (t) {
    case seL4_X64_PML4Object:
        return 12;

    case 0xfffffffe:
        return pageBitsForSize(X64_HugePage);

    default:
        _fail("Invalid object type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/object/objecttype.c", 172, __func__);
        return 0;
    }
}

cap_t
Mode_createObject(object_t t, void *regionBase, word_t userSize, bool_t deviceMemory)
{
    switch (t) {

    case seL4_X86_4K:
        if (deviceMemory) {





        } else {





        }
        return cap_frame_cap_new(
                   asidInvalid,
                   (word_t)regionBase,
                   X86_SmallPage,
                   X86_MappingNone,
                   0,
                   VMReadWrite,
                   deviceMemory
               );

    case seL4_X86_LargePageObject:
        if (deviceMemory) {





        } else {





        }
        return cap_frame_cap_new(
                   asidInvalid,
                   (word_t)regionBase,
                   X86_LargePage,
                   X86_MappingNone,
                   0,
                   VMReadWrite,
                   deviceMemory
               );

    case 0xfffffffe:
        if (deviceMemory) {





        } else {





        }
        return cap_frame_cap_new(
                   asidInvalid,
                   (word_t)regionBase,
                   X64_HugePage,
                   X86_MappingNone,
                   0,
                   VMReadWrite,
                   deviceMemory
               );

    case seL4_X86_PageTableObject:


        return cap_page_table_cap_new(
                   asidInvalid,
                   (word_t)regionBase,
                   0,
                   0
               );

    case seL4_X86_PageDirectoryObject:


        return cap_page_directory_cap_new(
                   asidInvalid,
                   (word_t)regionBase,
                   0,
                   0
               );

    case seL4_X86_PDPTObject:


        return cap_pdpt_cap_new(
                   asidInvalid,
                   (word_t)regionBase,
                   0,
                   0
               );

    case seL4_X64_PML4Object:


        copyGlobalMappings(((pml4e_t *)(regionBase)));
        return cap_pml4_cap_new(
                   asidInvalid,
                   (word_t)regionBase,
                   0
               );
    default:





        _fail("Arch_createObject got an API type or invalid object type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/object/objecttype.c", 311, __func__);
    }
}

exception_t
Mode_decodeInvocation(
    word_t label,
    word_t length,
    cptr_t cptr,
    cte_t* slot,
    cap_t cap,
    extra_caps_t extraCaps,
    word_t* buffer
)
{
    switch (cap_get_capType(cap)) {
    case cap_pml4_cap:
    case cap_pdpt_cap:
    case cap_page_directory_cap:
    case cap_page_table_cap:
    case cap_frame_cap:
        return decodeX86MMUInvocation(label, length, cptr, slot, cap, extraCaps, buffer);

    default:
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;
        return EXCEPTION_SYSCALL_ERROR;
    }
}



void Mode_handleRemoteCall(IpiModeRemoteCall_t call, word_t arg0, word_t arg1, word_t arg2)
{
    switch (call) {
    case IpiRemoteCall_InvalidatePCID:
        invalidateLocalPCID(arg0, (void*)arg1, arg2);
        break;

    case IpiRemoteCall_InvalidateASID:
        invalidateLocalASID((vspace_root_t*)arg0, arg1);
        break;

    default:
        _fail("Invalid remote call", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/64/smp/ipi.c", 31, __func__);
    }
}

bool_t Arch_handleFaultReply(tcb_t *receiver, tcb_t *sender, word_t faultType)
{
    switch (faultType) {
    case seL4_Fault_VMFault:
        return true;

    default:
        _fail("Invalid fault", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/api/faults.c", 26, __func__);
    }
}

word_t
Arch_setMRs_fault(tcb_t *sender, tcb_t* receiver, word_t *receiveIPCBuffer, word_t faultType)
{
    switch (faultType) {
    case seL4_Fault_VMFault: {
        setMR(receiver, receiveIPCBuffer, seL4_VMFault_IP, getRestartPC(sender));
        setMR(receiver, receiveIPCBuffer, seL4_VMFault_Addr,
              seL4_Fault_VMFault_get_address(sender->tcbFault));
        setMR(receiver, receiveIPCBuffer, seL4_VMFault_PrefetchFault,
              seL4_Fault_VMFault_get_instructionFault(sender->tcbFault));
        return setMR(receiver, receiveIPCBuffer, seL4_VMFault_FSR,
                     seL4_Fault_VMFault_get_FSR(sender->tcbFault));
    }
    default:
        _fail("Invalid fault", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/api/faults.c", 44, __func__);
    }
}

word_t handleKernelException(
    word_t vector,
    word_t errcode,
    word_t ip,
    word_t sp,
    word_t flags,
    word_t cr0,
    word_t cr2,
    word_t cr3,
    word_t cr4
);

__attribute__((externally_visible))
word_t handleKernelException(
    word_t vector,
    word_t errcode,
    word_t ip,
    word_t sp,
    word_t flags,
    word_t cr0,
    word_t cr2,
    word_t cr3,
    word_t cr4
)
{
    word_t i;


    if (vector == int_gp_fault && ksSMP[(getCurrentCPUIndex())].cpu.x86KSGPExceptReturnTo != 0) {
        word_t ret = ksSMP[(getCurrentCPUIndex())].cpu.x86KSGPExceptReturnTo;
        ksSMP[(getCurrentCPUIndex())].cpu.x86KSGPExceptReturnTo = 0;
        return ret;
    }
    kprintf("\n========== KERNEL EXCEPTION ==========\n");
    kprintf("Vector:  0x%lx\n", vector);
    kprintf("ErrCode: 0x%lx\n", errcode);
    kprintf("IP:      0x%lx\n", ip);
    kprintf("SP:      0x%lx\n", sp);
    kprintf("FLAGS:   0x%lx\n", flags);
    kprintf("CR0:     0x%lx\n", cr0);
    kprintf("CR2:     0x%lx (page-fault address)\n", cr2);
    kprintf("CR3:     0x%lx (page-directory physical address)\n", cr3);
    kprintf("CR4:     0x%lx\n", cr4);
    kprintf("\nStack Dump:\n");
    for (i = 0; i < 20; i++) {
        word_t __attribute__((unused)) stack = sp + i * sizeof(word_t);
        kprintf("*0x%lx == 0x%lx\n", stack, *(word_t*)stack);
    }
    kprintf("\nHalting...\n");
    halt();
    __builtin_unreachable();
}







static inline tcb_t *
endpoint_ptr_get_epQueue_tail_fp(endpoint_t *ep_ptr)
{
    uint64_t ret = ep_ptr->words[0] & 0xfffffffffffcull;
    return __builtin_expect(!!(ret), 0) ? ((tcb_t *)(ret | 0xffffff8000000000ul)) : ((void *)0);
}

static inline vspace_root_t *
cap_vtable_cap_get_vspace_root_fp(cap_t vtable_cap)
{
    return ((pml4e_t *)(vtable_cap.words[1]));
}

static inline word_t
cap_pml4_cap_get_capPML4MappedASID_fp(cap_t vtable_cap)
{
    return (uint32_t)vtable_cap.words[0];
}

static inline void __attribute__((always_inline))
switchToThread_fp(tcb_t *thread, vspace_root_t *vroot, pde_t stored_hw_asid)
{
    word_t new_vroot = addrFromPPtr(vroot);

    asid_t asid = (asid_t)(stored_hw_asid.words[0] & 0xfff);
    cr3_t next_cr3 = makeCR3(new_vroot, asid);
    if (__builtin_expect(!!(getCurrentUserCR3().words[0] != next_cr3.words[0]), 1)) {
        tlb_bitmap_set(vroot, getCurrentCPUIndex());
        setCurrentUserCR3(next_cr3);
    }


    __asm__ volatile("movq %[value], %%gs:%c[offset]"
                 :
                 : [value] "r" (&thread->tcbArch.tcbContext.registers[Error + 1]),
                 [offset] "i" (__builtin_offsetof(nodeInfo_t, currentThreadUserContext)));


    if (0) {
        x86_ibpb();
    }

    if (0) {
        x86_flush_rsb();
    }


    benchmark_utilisation_switch(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, thread);


    ksSMP[(getCurrentCPUIndex())].system.ksCurThread = thread;
}

static inline void
thread_state_ptr_set_blockingIPCDiminish_np(thread_state_t *ts_ptr, word_t dim)
{
    ts_ptr->words[1] = (ts_ptr->words[1] & 1) | dim;
}

static inline void
mdb_node_ptr_mset_mdbNext_mdbRevocable_mdbFirstBadged(
    mdb_node_t *node_ptr, word_t mdbNext,
    word_t mdbRevocable, word_t mdbFirstBadged)
{
    node_ptr->words[1] = mdbNext | (mdbRevocable << 1) | mdbFirstBadged;
}

static inline void
mdb_node_ptr_set_mdbPrev_np(mdb_node_t *node_ptr, word_t mdbPrev)
{
    node_ptr->words[0] = mdbPrev;
}

static inline bool_t
isValidVTableRoot_fp(cap_t vspace_root_cap)
{


    return (vspace_root_cap.words[0] >> (64 - 6)) == ((cap_pml4_cap << 1) | 0x1);
}

static inline void
fastpath_copy_mrs(word_t length, tcb_t *src, tcb_t *dest)
{
    word_t i;
    register_t reg;


    for (i = 0; i < length; i ++) {

        reg = msgRegisters[0] + i;
        setRegister(dest, reg, getRegister(src, reg));
    }
}






typedef int __assert_failed_n_msgRegisters_eq_4[(n_msgRegisters == 4) ? 1 : -1];
static inline int
fastpath_mi_check(word_t msgInfo)
{
    return ((msgInfo & ((1ul << (seL4_MsgLengthBits + seL4_MsgExtraCapBits))-1ul))
            + 3) & ~((1ul << (3))-1ul);
}

static inline void __attribute__((__noreturn__)) __attribute__((always_inline))
fastpath_restore(word_t badge, word_t msgInfo, tcb_t *cur_thread)
{
    if (0 && 0 && ((getRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, FLAGS) & (1ul << (8)) ) != 0)) {




        restore_user_context();
    }
    do { clh_lock_release(getCurrentCPUIndex()); } while(0);
    c_exit_hook();
    lazyFPURestore(cur_thread);

    if (0) {

        word_t *irqstack = x64KSIRQStack[getCurrentCPUIndex()];
        irqstack[0] = 0;
        irqstack[1] = 0;
        irqstack[2] = 0;
        irqstack[3] = 0;
        irqstack[4] = 0;
        irqstack[5] = 0;
    }






    cpu_id_t cpu = getCurrentCPUIndex();



    swapgs();





    word_t base = getRegister(cur_thread, TLS_BASE);
    x86_write_fs_base(base, cpu);

    base = cur_thread->tcbIPCBuffer;
    x86_write_gs_base(base, cpu);

    if (0) {
        x86_disable_ibrs();
    }

    if (0) {
        cur_thread->tcbArch.tcbContext.registers[FLAGS] &= ~(1ul << (9)) ;




        __asm__ volatile (
            "movq %%rcx, %%rsp\n"
            "popq %%rax\n"
            "popq %%rbx\n"
            "popq %%rbp\n"
            "popq %%r12\n"
            "popq %%r13\n"
            "popq %%r14\n"

            "addq $8, %%rsp\n"
            "popq %%r10\n"
            "popq %%r8\n"
            "popq %%r9\n"
            "popq %%r15\n"

            "popfq\n"

            "orq %[IF], -8(%%rsp)\n"

            "popq %%rdx\n"

            "addq $8, %%rsp\n"

            "popq %%rcx\n"

            "addq $16, %%rsp\n"





            "popq %%r11\n"





            "sti\n"
            "rex.w sysexit\n"
            :
            : "c" (&cur_thread->tcbArch.tcbContext.registers[RAX]),
            "D" (badge),
            "S" (msgInfo),



            [IF] "i" ((1ul << (9)) )
            : "memory"
        );
    } else {
        __asm__ volatile(

            "movq %0, %%rsp\n"
            "popq %%rax\n"
            "popq %%rbx\n"
            "popq %%rbp\n"
            "popq %%r12\n"
            "popq %%r13\n"
            "popq %%r14\n"
            "popq %%rdx\n"
            "popq %%r10\n"
            "popq %%r8\n"
            "popq %%r9\n"
            "popq %%r15\n"

            "popq %%r11\n"






            "popq %%rcx\n"






            "xor %%rsp, %%rsp\n"


            "rex.w sysret\n"
            :
            : "r"(&cur_thread->tcbArch.tcbContext.registers[RAX]),
            "D" (badge),
            "S" (msgInfo)



            : "memory"
        );
    }
    __builtin_unreachable();
}

static inline int
fastpath_reply_cap_check(cap_t cap)
{
    return cap_capType_equals(cap, cap_reply_cap);
}

void slowpath(syscall_t syscall)
__attribute__((__noreturn__));

void fastpath_call(word_t cptr, word_t r_msgInfo)
__attribute__((__noreturn__));

void fastpath_reply_recv(word_t cptr, word_t r_msgInfo)
__attribute__((__noreturn__));


void __attribute__((externally_visible))
c_nested_interrupt(int irq)
{



    if(!(ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt == int_invalid)) _assert_fail("ARCH_NODE_STATE(x86KSPendingInterrupt) == int_invalid", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/c_traps.c", 30, __FUNCTION__);
    ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt = irq;
}

void __attribute__((externally_visible)) __attribute__((__noreturn__))
c_handle_interrupt(int irq, int syscall)
{



    if (0 && 0) {
        x86_enable_ibrs();
    }



    do { if((irq != int_remote_call_ipi)) { do { clh_lock_acquire(getCurrentCPUIndex(), irq >= int_irq_min && irq <= int_irq_max); } while(0); } } while(0)
                                                          ;

    c_entry_hook();

    if (irq == int_unimpl_dev) {
        handleFPUFault();

        ksKernelEntry.path = Entry_UnimplementedDevice;
        ksKernelEntry.word = irq;

    } else if (irq == int_page_fault) {

        vm_fault_type_t type = (ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbContext.registers[Error] >> 4u) & 1u;

        ksKernelEntry.path = Entry_VMFault;
        ksKernelEntry.word = type;

        handleVMFaultEvent(type);
    } else if (irq < int_irq_min) {

        ksKernelEntry.path = Entry_UserLevelFault;
        ksKernelEntry.word = irq;

        handleUserLevelFault(irq, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbContext.registers[Error]);
    } else if (__builtin_expect(!!(irq < int_trap_min), 1)) {
        ksSMP[(getCurrentCPUIndex())].cpu.x86KScurInterrupt = irq;

        ksKernelEntry.path = Entry_Interrupt;
        ksKernelEntry.word = irq;

        handleInterruptEntry();

        receivePendingIRQ();
    } else if (irq == int_spurious) {

    } else {



        int sys_num;
        ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbContext.registers[FaultIP] -= 2;

        sys_num = (irq << 24) | (syscall & 0x00ffffff);

        ksKernelEntry.path = Entry_UnknownSyscall;
        ksKernelEntry.word = sys_num;

        handleUnknownSyscall(sys_num);
    }
    restore_user_context();
    __builtin_unreachable();
}

void __attribute__((__noreturn__))
slowpath(syscall_t syscall)
{


    if (syscall == SysVMEnter && ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU) {
        vcpu_update_state_sysvmenter(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU);
        if (ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbBoundNotification && notification_ptr_get_state(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbBoundNotification) == NtfnState_Active) {
            completeSignal(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbBoundNotification, ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
            setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, msgInfoRegister, 0);



            restore_user_context();
        } else {
            setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_RunningVM);
            restore_user_context();
        }
    }


    if (__builtin_expect(!!(syscall < (-8) || syscall > (-1)), 0)) {

        ksKernelEntry.path = Entry_UnknownSyscall;


        handleUnknownSyscall(syscall);
    } else {

        ksKernelEntry.is_fastpath = 0;

        handleSyscall(syscall);
    }

    restore_user_context();
    __builtin_unreachable();
}

void __attribute__((externally_visible)) __attribute__((__noreturn__))
c_handle_syscall(word_t cptr, word_t msgInfo, syscall_t syscall)
{


    if (0) {
        x86_enable_ibrs();
    }

    do { clh_lock_acquire(getCurrentCPUIndex(), false); } while(0);

    c_entry_hook();


    benchmark_debug_syscall_start(cptr, msgInfo, syscall);
    ksKernelEntry.is_fastpath = 1;


    if (0) {

        ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbContext.registers[NextIP] += 2;
    } else {

        setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, FaultIP, getRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, NextIP) - 2);
    }


    if (syscall == (syscall_t)SysCall) {
        fastpath_call(cptr, msgInfo);
        __builtin_unreachable();
    } else if (syscall == (syscall_t)SysReplyRecv) {
        fastpath_reply_recv(cptr, msgInfo);
        __builtin_unreachable();
    }

    slowpath(syscall);
    __builtin_unreachable();
}


void __attribute__((externally_visible)) __attribute__((__noreturn__)) c_handle_vmexit(void)
{

    ksKernelEntry.path = Entry_VMExit;



    x86_flush_rsb();

    c_entry_hook();

    handleVmexit();
    tcb_t *cur_thread = ksSMP[(getCurrentCPUIndex())].system.ksCurThread;
    if (thread_state_ptr_get_tsType(&cur_thread->tcbState) != ThreadState_RunningVM) {
        ksSMP[(getCurrentCPUIndex())].cpu.x86KSCurrentGSBase = -(word_t)1;
        ksSMP[(getCurrentCPUIndex())].cpu.x86KSCurrentFSBase = -(word_t)1;
    }
    restore_user_context();
    __builtin_unreachable();
}

void idle_thread(void)
{
    while (1) {
        __asm__ volatile("hlt");
    }
}


void __attribute__((externally_visible)) halt(void)
{

    __asm__ volatile("cli");


    kprintf("halting...");

    debug_printKernelEntryReason();


    idle_thread();
    __builtin_unreachable();
}
void pit_init(void);
void pit_wait_wraparound(void);

static __attribute__((__section__(".boot.text"))) uint32_t
apic_measure_freq(void)
{
    pit_init();

    pit_wait_wraparound();


    apic_write_reg(APIC_TIMER_DIVIDE, 0xb);
    apic_write_reg(APIC_TIMER_COUNT, 0xffffffff);


    pit_wait_wraparound();


    return (0xffffffff - apic_read_reg(APIC_TIMER_CURRENT)) / 50;
}

__attribute__((__section__(".boot.text"))) paddr_t
apic_get_base_paddr(void)
{
    apic_base_msr_t apic_base_msr;

    apic_base_msr.words[0] = x86_rdmsr_low(0x01B);
    return apic_base_msr_get_base_addr(apic_base_msr);
}

__attribute__((__section__(".boot.text"))) bool_t
apic_init(bool_t mask_legacy_irqs)
{
    apic_version_t apic_version;
    uint32_t num_lvt_entries;
    uint32_t apic_khz;

    if (!apic_enable()) {
        return false;
    }

    apic_khz = apic_measure_freq();

    apic_version.words[0] = apic_read_reg(APIC_VERSION);


    if (apic_version_get_version(apic_version) >> 4 != 1) {
        kprintf("APIC: apic_version must be 0x1X\n");
        return false;
    }


    num_lvt_entries = apic_version_get_max_lvt_entry(apic_version) + 1;
    if (num_lvt_entries < 3) {
        kprintf("APIC: number of LVT entries: %d\n", num_lvt_entries);
        kprintf("APIC: number of LVT entries must be >= 3\n");
        return false;
    }


    apic_write_reg(APIC_TIMER_DIVIDE, 0xb);
    apic_write_reg(APIC_TIMER_COUNT, apic_khz * 2);


    apic_write_reg(
        APIC_SVR,
        apic_svr_new(
            0,
            1,
            int_spurious
        ).words[0]
    );


    apic_write_reg(
        APIC_LVT_LINT0,
        apic_lvt_new(
            0,
            mask_legacy_irqs,
            0,
            0,
            0,
            0,
            7,
            0
        ).words[0]
    );


    apic_write_reg(
        APIC_LVT_LINT1,
        apic_lvt_new(
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        ).words[0]
    );


    apic_write_reg(
        APIC_LVT_TIMER,
        apic_lvt_new(
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            int_timer
        ).words[0]
    );
    return true;
}

void apic_ack_active_interrupt(void)
{
    apic_write_reg(APIC_EOI, 0);
}

typedef struct multiboot_module {
    uint32_t start;
    uint32_t end;
    uint32_t name;
    uint32_t reserved;
} __attribute__((packed)) multiboot_module_t;

typedef struct multiboot_mmap {
    uint32_t size;
    uint64_t base_addr;
    uint64_t length;
    uint32_t type;
} __attribute__((packed)) multiboot_mmap_t;

typedef struct multiboot_info {

    struct multiboot_part1 {
        uint32_t flags;
        uint32_t mem_lower;
        uint32_t mem_upper;
        uint32_t boot_device;
        uint32_t cmdline;
        uint32_t mod_count;
        uint32_t mod_list;
    } part1;



    struct multiboot_part2 {
        uint32_t syms[4];
        uint32_t mmap_length;
        uint32_t mmap_addr;
        uint32_t drives_length;
        uint32_t drives_addr;
        uint32_t config_table;
        uint32_t boot_loader_name;
        uint32_t apm_table;
        uint32_t vbe_control_info;
        uint32_t vbe_mode_info;
        uint16_t vbe_mode;
        uint16_t vbe_interface_seg;
        uint16_t vbe_interface_off;
        uint16_t vbe_interface_len;
    } part2;
} __attribute__((packed)) multiboot_info_t;

typedef struct multiboot2_header {
    uint32_t total_size;
    uint32_t unknown;
} __attribute__((packed)) multiboot2_header_t;

typedef struct multiboot2_tag {
    uint32_t type;
    uint32_t size;
} __attribute__((packed)) multiboot2_tag_t;

typedef struct multiboot2_memory {
    uint64_t addr;
    uint64_t size;
    uint32_t type;
    uint32_t reserved;
} __attribute__((packed)) multiboot2_memory_t;

typedef struct multiboot2_module {
    uint32_t start;
    uint32_t end;
    char string [1];
} __attribute__((packed)) multiboot2_module_t;

typedef struct multiboot2_fb {
    uint64_t addr;
    uint32_t pitch;
    uint32_t width;
    uint32_t height;
    uint8_t bpp;
    uint8_t type;
} __attribute__((packed)) multiboot2_fb_t;

enum multiboot2_tags {
    MULTIBOOT2_TAG_END = 0,
    MULTIBOOT2_TAG_CMDLINE = 1,
    MULTIBOOT2_TAG_MODULE = 3,
    MULTIBOOT2_TAG_MEMORY = 6,
    MULTIBOOT2_TAG_FB = 8,
    MULTIBOOT2_TAG_ACPI_1 = 14,
    MULTIBOOT2_TAG_ACPI_2 = 15,
};

void boot_sys(
    unsigned long multiboot_magic,
    void * multiboot
);

__attribute__((__section__(".boot.text"))) uint32_t tsc_init(void);




__attribute__((__section__(".boot.text"))) static void
init_irqs(cap_t root_cnode_cap)
{
    irq_t i;

    for (i = 0; i <= maxIRQ; i++) {
        if (i == irq_timer) {
            setIRQState(IRQTimer, i);

        } else if (i == irq_remote_call_ipi || i == irq_reschedule_ipi) {
            setIRQState(IRQIPI, i);





        } else if (i == 2 && 0) {

            setIRQState(IRQReserved, i);
        } else if (i >= irq_isa_min && i <= irq_isa_max) {
            if (0) {
                setIRQState(IRQInactive, i);
            } else {
                setIRQState(IRQReserved, i);
            }
        } else if (i >= irq_user_min && i <= irq_user_max) {
            if (1) {
                setIRQState(IRQInactive, i);
            } else {
                setIRQState(IRQReserved, i);
            }
        } else {
            setIRQState(IRQReserved, i);
        }
    }
    Arch_irqStateInit();

    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapIRQControl)), cap_irq_control_cap_new());
}





typedef struct allocated_p_region {
    p_region_t regs[(16 + 1 + ((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12) + 2)];
    word_t cur_pos;
} allocated_p_region_t;

__attribute__((__section__(".boot.bss"))) static allocated_p_region_t allocated_p_regions;

__attribute__((__section__(".boot.text"))) static void
merge_regions(void)
{
    unsigned int i, j;

    for (i = 1; i < allocated_p_regions.cur_pos;) {
        if (allocated_p_regions.regs[i - 1].end == allocated_p_regions.regs[i].start) {

            allocated_p_regions.regs[i - 1].end = allocated_p_regions.regs[i].end;

            for (j = i; j < allocated_p_regions.cur_pos - 1; j++) {
                allocated_p_regions.regs[j] = allocated_p_regions.regs[j + 1];
            }
            allocated_p_regions.cur_pos--;


        } else {
            i++;
        }
    }
}

static __attribute__((unused)) __attribute__((__section__(".boot.text"))) bool_t p_region_overlaps(p_region_t reg)
{
    unsigned int i;
    for (i = 0; i < allocated_p_regions.cur_pos; i++) {
        if (allocated_p_regions.regs[i].start < reg.end &&
                allocated_p_regions.regs[i].end > reg.start) {
            return true;
        }
    }
    return false;
}

__attribute__((__section__(".boot.text"))) bool_t
add_allocated_p_region(p_region_t reg)
{
    unsigned int i, j;

    if(!(reg.start <= reg.end)) _assert_fail("reg.start <= reg.end", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/boot.c", 122, __FUNCTION__);
    if(!(!p_region_overlaps(reg))) _assert_fail("!p_region_overlaps(reg)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/boot.c", 123, __FUNCTION__);



    for (i = 0; i < allocated_p_regions.cur_pos; i++) {

        if (allocated_p_regions.regs[i].end == reg.start) {
            allocated_p_regions.regs[i].end = reg.end;
            merge_regions();
            return true;
        }
        if (allocated_p_regions.regs[i].start == reg.end) {
            allocated_p_regions.regs[i].start = reg.start;
            merge_regions();
            return true;
        }

        if (reg.end < allocated_p_regions.regs[i].start) {

            if (allocated_p_regions.cur_pos + 1 == (16 + 1 + ((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12) + 2)) {
                kprintf("Ran out of reserved physical regions\n");
                return false;
            }

            for (j = allocated_p_regions.cur_pos; j != i; j--) {
                allocated_p_regions.regs[j] = allocated_p_regions.regs[j - 1];
            }

            allocated_p_regions.regs[i] = reg;
            allocated_p_regions.cur_pos++;
            return true;
        }
    }


    if (i + 1 == (16 + 1 + ((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12) + 2)) {
        kprintf("Ran out of reserved physical regions\n");
        return false;
    }
    allocated_p_regions.regs[i] = reg;
    allocated_p_regions.cur_pos = i + 1;
    return true;
}

__attribute__((__section__(".boot.text"))) void
init_allocated_p_regions()
{
    allocated_p_regions.cur_pos = 0;
}

__attribute__((__section__(".boot.text"))) static bool_t
create_untypeds(
    cap_t root_cnode_cap,
    region_t boot_mem_reuse_reg)
{
    seL4_SlotPos slot_pos_before;
    seL4_SlotPos slot_pos_after;
    word_t i;

    paddr_t start = 0;

    slot_pos_before = ndks_boot.slot_pos_cur;
    create_kernel_untypeds(root_cnode_cap, boot_mem_reuse_reg, slot_pos_before);

    for (i = 0; i < allocated_p_regions.cur_pos; i++) {
        if (start != allocated_p_regions.regs[i].start) {
            if (!create_untypeds_for_region(root_cnode_cap, true,
            paddr_to_pptr_reg((p_region_t) {
            start, allocated_p_regions.regs[i].start
            }),
            slot_pos_before)) {
                return false;
            }
        }
        start = allocated_p_regions.regs[i].end;
    }

    if (start != (1ul << (47))) {
        if (!create_untypeds_for_region(root_cnode_cap, true,
        paddr_to_pptr_reg((p_region_t) {
        start, (1ul << (47))
    }),
    slot_pos_before)) {
            return false;
        }
    }

    slot_pos_after = ndks_boot.slot_pos_cur;
    ndks_boot.bi_frame->untyped = (seL4_SlotRegion) {
        slot_pos_before, slot_pos_after
    };
    return true;
}

__attribute__((__section__(".boot.text"))) static void
init_freemem(p_region_t ui_p_reg, mem_p_regs_t mem_p_regs)
{
    word_t i;


    pptr_t floor = ui_p_reg.end;
    for (i = 0; i < 16; i++) {
        ndks_boot.freemem[i] = (region_t){ .start = 0, .end = 0 };
    }
    for (i = 0; i < mem_p_regs.count; i++) {
        pptr_t start = mem_p_regs.list[i].start;
        pptr_t end = mem_p_regs.list[i].end;
        if (start < floor) {
            start = floor;
        }
        if (end < floor) {
            end = floor;
        }
        insert_region(paddr_to_pptr_reg((p_region_t) {
            start, end
        }));
    }
}



__attribute__((__section__(".boot.text"))) bool_t
init_sys_state(
    cpu_id_t cpu_id,
    mem_p_regs_t mem_p_regs,
    ui_info_t ui_info,
    p_region_t boot_mem_reuse_p_reg,

    uint32_t num_drhu,
    paddr_t* drhu_list,
    acpi_rmrr_list_t *rmrr_list,
    acpi_rsdp_t *acpi_rsdp,
    seL4_X86_BootInfo_VBE *vbe,
    seL4_X86_BootInfo_mmap_t *mb_mmap,
    seL4_X86_BootInfo_fb_t *fb_info
)
{
    cap_t root_cnode_cap;
    vptr_t extra_bi_frame_vptr;
    vptr_t bi_frame_vptr;
    vptr_t ipcbuf_vptr;
    cap_t it_vspace_cap;
    cap_t it_ap_cap;
    cap_t ipcbuf_cap;
    pptr_t bi_frame_pptr;
    word_t extra_bi_size = sizeof(seL4_BootInfoHeader);
    region_t extra_bi_region;
    pptr_t extra_bi_offset = 0;
    uint32_t tsc_freq;
    create_frames_of_region_ret_t create_frames_ret;
    create_frames_of_region_ret_t extra_bi_ret;


    region_t ui_reg = paddr_to_pptr_reg(ui_info.p_reg);
    region_t boot_mem_reuse_reg = paddr_to_pptr_reg(boot_mem_reuse_p_reg);


    v_region_t ui_v_reg;
    v_region_t it_v_reg;
    ui_v_reg.start = ui_info.p_reg.start - ui_info.pv_offset;
    ui_v_reg.end = ui_info.p_reg.end - ui_info.pv_offset;

    ipcbuf_vptr = ui_v_reg.end;
    bi_frame_vptr = ipcbuf_vptr + (1ul << (12));
    extra_bi_frame_vptr = bi_frame_vptr + (1ul << (12));

    if (vbe->vbeMode != -1) {
        extra_bi_size += sizeof(seL4_X86_BootInfo_VBE);
    }
    if (acpi_rsdp) {
        extra_bi_size += sizeof(seL4_BootInfoHeader) + sizeof(*acpi_rsdp);
    }
    if (fb_info && fb_info->addr) {
        extra_bi_size += sizeof(seL4_BootInfoHeader) + sizeof(*fb_info);
    }

    word_t mb_mmap_size = sizeof(seL4_X86_BootInfo_mmap_t);
    extra_bi_size += mb_mmap_size;


    extra_bi_size += sizeof(seL4_BootInfoHeader) + 4;


    it_v_reg.start = ui_v_reg.start;
    it_v_reg.end = (((((extra_bi_frame_vptr + extra_bi_size) - 1ul) >> (12)) + 1ul) << (12));

    init_freemem(ui_info.p_reg, mem_p_regs);


    root_cnode_cap = create_root_cnode();


    write_slot(
        (((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapIOPort)),
        cap_io_port_cap_new(
            0,
            (1ul << (16)) - 1

            , 0

        )
    );


    create_domain_cap(root_cnode_cap);


    if (!create_irq_cnode()) {
        return false;
    }


    init_irqs(root_cnode_cap);

    tsc_freq = tsc_init();


    bi_frame_pptr = allocate_bi_frame(0, ksNumCPUs, ipcbuf_vptr);
    if (!bi_frame_pptr) {
        return false;
    }

    extra_bi_region = allocate_extra_bi_region(extra_bi_size);
    if (extra_bi_region.start == 0) {
        return false;
    }


    if (vbe->vbeMode != -1) {
        vbe->header.id = 1;
        vbe->header.len = sizeof(seL4_X86_BootInfo_VBE);
        memcpy((void*)(extra_bi_region.start + extra_bi_offset), vbe, sizeof(seL4_X86_BootInfo_VBE));
        extra_bi_offset += sizeof(seL4_X86_BootInfo_VBE);
    }


    if (acpi_rsdp) {
        seL4_BootInfoHeader header;
        header.id = 3;
        header.len = sizeof(header) + sizeof(*acpi_rsdp);
        *(seL4_BootInfoHeader*)(extra_bi_region.start + extra_bi_offset) = header;
        extra_bi_offset += sizeof(header);
        memcpy((void*)(extra_bi_region.start + extra_bi_offset), acpi_rsdp, sizeof(*acpi_rsdp));
        extra_bi_offset += sizeof(*acpi_rsdp);
    }


    if (fb_info && fb_info->addr) {
        seL4_BootInfoHeader header;
        header.id = 4;
        header.len = sizeof(header) + sizeof(*fb_info);
        *(seL4_BootInfoHeader*)(extra_bi_region.start + extra_bi_offset) = header;
        extra_bi_offset += sizeof(header);
        memcpy((void*)(extra_bi_region.start + extra_bi_offset), fb_info, sizeof(*fb_info));
        extra_bi_offset += sizeof(*fb_info);
    }


    mb_mmap->header.id = 2;
    mb_mmap->header.len = mb_mmap_size;
    memcpy((void*)(extra_bi_region.start + extra_bi_offset), mb_mmap, mb_mmap_size);
    extra_bi_offset += mb_mmap_size;


    {
        seL4_BootInfoHeader header;
        header.id = 5 ;
        header.len = sizeof(header) + 4;
        *(seL4_BootInfoHeader*)(extra_bi_region.start + extra_bi_offset) = header;
        extra_bi_offset += sizeof(header);
        *(uint32_t*)(extra_bi_region.start + extra_bi_offset) = tsc_freq;
        extra_bi_offset += 4;
    }


    seL4_BootInfoHeader padding_header;
    padding_header.id = 0;
    padding_header.len = (extra_bi_region.end - extra_bi_region.start) - extra_bi_offset;
    *(seL4_BootInfoHeader*)(extra_bi_region.start + extra_bi_offset) = padding_header;



    it_vspace_cap = create_it_address_space(root_cnode_cap, it_v_reg);
    if (cap_get_capType(it_vspace_cap) == cap_null_cap) {
        return false;
    }


    create_bi_frame_cap(
        root_cnode_cap,
        it_vspace_cap,
        bi_frame_pptr,
        bi_frame_vptr
    );


    extra_bi_ret =
        create_frames_of_region(
            root_cnode_cap,
            it_vspace_cap,
            extra_bi_region,
            true,
            addrFromPPtr((void*)(extra_bi_region.start - extra_bi_frame_vptr))
        );
    if (!extra_bi_ret.success) {
        return false;
    }
    ndks_boot.bi_frame->extraBIPages = extra_bi_ret.region;


    ipcbuf_cap = create_ipcbuf_frame(root_cnode_cap, it_vspace_cap, ipcbuf_vptr);
    if (cap_get_capType(ipcbuf_cap) == cap_null_cap) {
        return false;
    }


    create_frames_ret =
        create_frames_of_region(
            root_cnode_cap,
            it_vspace_cap,
            ui_reg,
            true,
            ui_info.pv_offset
        );
    if (!create_frames_ret.success) {
        return false;
    }
    ndks_boot.bi_frame->userImageFrames = create_frames_ret.region;


    it_ap_cap = create_it_asid_pool(root_cnode_cap);
    if (cap_get_capType(it_ap_cap) == cap_null_cap) {
        return false;
    }
    write_it_asid_pool(it_ap_cap, it_vspace_cap);


    if (!create_idle_thread()) {
        return false;
    }


    tcb_t *initial = create_initial_thread(root_cnode_cap,
                                           it_vspace_cap,
                                           ui_info.v_entry,
                                           bi_frame_vptr,
                                           ipcbuf_vptr,
                                           ipcbuf_cap);
    if (initial == ((void *)0)) {
        return false;
    }
    init_core_state(initial);
    ndks_boot.bi_frame->numIOPTLevels = -1;



    if (!create_untypeds(root_cnode_cap, boot_mem_reuse_reg)) {
        return false;
    }



    bi_finalise();

    return true;
}



__attribute__((__section__(".boot.text"))) bool_t
init_cpu(
    bool_t mask_legacy_irqs
)
{

    if (!init_vm_state()) {
        return false;
    }


    init_dtrs();

    if (0) {

        init_sysenter_msrs();
    } else if (1) {
        init_syscall_msrs();
    } else {
        return false;
    }


    if (!init_pat_msr()) {
        return false;
    }



    write_cr0(read_cr0() | (1ul << (16)) );


    cpuid_007h_ebx_t ebx_007;
    ebx_007.words[0] = x86_cpuid_ebx(0x7, 0);
    if (cpuid_007h_ebx_get_smap(ebx_007)) {


        if (!1 && !0) {
            write_cr4(read_cr4() | (1ul << (21)) );
        }
    }
    if (cpuid_007h_ebx_get_smep(ebx_007)) {


        if (!0) {
            write_cr4(read_cr4() | (1ul << (20)) );
        }
    }

    if (!init_ibrs()) {
        return false;
    }







    if (!Arch_initFpu()) {
        return false;
    }


    if (!apic_init(mask_legacy_irqs)) {
        return false;
    }







    if (0) {
        enablePMCUser();
    }



    vtx_init();


    return true;
}

typedef struct cmdline_opt {

    uint16_t console_port;


    uint16_t debug_port;

    bool_t disable_iommu;
} cmdline_opt_t;

void cmdline_parse(const char *cmdline, cmdline_opt_t* cmdline_opt);
void boot_node(void);
__attribute__((__section__(".boot.text"))) void start_boot_aps(void);
__attribute__((__section__(".boot.text"))) bool_t copy_boot_code_aps(uint32_t mem_lower);





extern char boot_cpu_start[1];
extern char boot_cpu_end[1];


extern char boot_stack_bottom[1];
extern char boot_stack_top[1];


extern char ki_boot_end[1];
extern char ki_end[1];
extern char ki_skim_start[1];
extern char ki_skim_end[1];



extern char _start[1];
typedef struct boot_state {
    p_region_t avail_p_reg;
    p_region_t ki_p_reg;
    ui_info_t ui_info;
    uint32_t num_ioapic;
    paddr_t ioapic_paddr[1];
    uint32_t num_drhu;
    paddr_t drhu_list[((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12)];
    acpi_rmrr_list_t rmrr_list;
    acpi_rsdp_t acpi_rsdp;
    paddr_t mods_end_paddr;
    paddr_t boot_module_start;
    uint32_t num_cpus;
    uint32_t mem_lower;
    cpu_id_t cpus[16];
    mem_p_regs_t mem_p_regs;
    seL4_X86_BootInfo_VBE vbe_info;
    seL4_X86_BootInfo_mmap_t mb_mmap_info;
    seL4_X86_BootInfo_fb_t fb_info;
} boot_state_t;

__attribute__((__section__(".boot.bss")))
boot_state_t boot_state;



__attribute__((__section__(".boot.bss")))
cmdline_opt_t cmdline_opt;


__attribute__((__section__(".boot.text"))) static bool_t
module_paddr_region_valid(paddr_t pa_start, paddr_t pa_end)
{
    int i = 0;
    for (i = 0; i < boot_state.mem_p_regs.count; i++) {
        paddr_t start = boot_state.mem_p_regs.list[i].start;
        paddr_t end = boot_state.mem_p_regs.list[i].end;
        if (pa_start >= start && pa_end < end) {
            return true;
        }
    }
    return false;
}



__attribute__((__section__(".boot.text"))) static paddr_t
find_load_paddr(paddr_t min_paddr, word_t image_size)
{
    int i;

    for (i = 0; i < boot_state.mem_p_regs.count; i++) {
        paddr_t start = (((min_paddr)>(boot_state.mem_p_regs.list[i].start))?(min_paddr):(boot_state.mem_p_regs.list[i].start));
        paddr_t end = boot_state.mem_p_regs.list[i].end;
        word_t region_size = end - start;

        if (region_size >= image_size) {
            return start;
        }
    }

    return 0;
}

__attribute__((__section__(".boot.text"))) static paddr_t
load_boot_module(word_t boot_module_start, paddr_t load_paddr)
{
    v_region_t v_reg;
    word_t entry;
    Elf_Header_t* elf_file = (Elf_Header_t*)boot_module_start;

    if (!elf_checkFile(elf_file)) {
        kprintf("Boot module does not contain a valid ELF image\n");
        return 0;
    }

    v_reg = elf_getMemoryBounds(elf_file);
    entry = elf_file->e_entry;

    if (v_reg.end == 0) {
        kprintf("ELF image in boot module does not contain any segments\n");
        return 0;
    }
    v_reg.end = (((((v_reg.end) - 1ul) >> (12)) + 1ul) << (12));

    kprintf("size=0x%lx v_entry=%p v_start=%p v_end=%p ", v_reg.end - v_reg.start, (void*)entry, (void*)v_reg.start, (void*)v_reg.end)




           ;

    if (!(!((v_reg.start) & ((1ul << (12))-1ul)))) {
        kprintf("Userland image virtual start address must be 4KB-aligned\n");
        return 0;
    }
    if (v_reg.end + 2 * (1ul << (12)) > 0x7FFFFFFFFFFF) {

        kprintf("Userland image virtual end address too high\n");
        return 0;
    }
    if ((entry < v_reg.start) || (entry >= v_reg.end)) {
        kprintf("Userland image entry point does not lie within userland image\n");
        return 0;
    }

    load_paddr = find_load_paddr(load_paddr, v_reg.end - v_reg.start);
    if(!(load_paddr)) _assert_fail("load_paddr", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/boot_sys.c", 165, __FUNCTION__);


    boot_state.ui_info.pv_offset = load_paddr - v_reg.start;
    boot_state.ui_info.p_reg.start = load_paddr;
    load_paddr += v_reg.end - v_reg.start;
    boot_state.ui_info.p_reg.end = load_paddr;
    boot_state.ui_info.v_entry = entry;

    kprintf("p_start=0x%lx p_end=0x%lx\n", boot_state.ui_info.p_reg.start, boot_state.ui_info.p_reg.end)


           ;

    if (!module_paddr_region_valid(
                boot_state.ui_info.p_reg.start,
                boot_state.ui_info.p_reg.end)) {
        kprintf("End of loaded userland image lies outside of usable physical memory\n");
        return 0;
    }


    memzero(
        (void*)boot_state.ui_info.p_reg.start,
        boot_state.ui_info.p_reg.end - boot_state.ui_info.p_reg.start
    );
    elf_load(elf_file, boot_state.ui_info.pv_offset);

    return load_paddr;
}

static __attribute__((__section__(".boot.text"))) bool_t
try_boot_sys_node(cpu_id_t cpu_id)
{
    p_region_t boot_mem_reuse_p_reg;

    if (!map_kernel_window(
                boot_state.num_ioapic,
                boot_state.ioapic_paddr,
                boot_state.num_drhu,
                boot_state.drhu_list
            )) {
        return false;
    }
    setCurrentVSpaceRoot(kpptr_to_paddr(x64KSKernelPML4), 0);


    __asm__ volatile("" ::: "memory");
    boot_mem_reuse_p_reg.start = 0x00200000ul;
    boot_mem_reuse_p_reg.end = (paddr_t)ki_boot_end - (0xffffffff80000000ul - 0x00000000ul);


    if (!init_cpu(1 ? 1 : 0)) {
        return false;
    }


    if (!init_sys_state(
                cpu_id,
                boot_state.mem_p_regs,
                boot_state.ui_info,
                boot_mem_reuse_p_reg,

                boot_state.num_drhu,
                boot_state.drhu_list,
                &boot_state.rmrr_list,
                &boot_state.acpi_rsdp,
                &boot_state.vbe_info,
                &boot_state.mb_mmap_info,
                &boot_state.fb_info
            )) {
        return false;
    }

    return true;
}

static __attribute__((__section__(".boot.text"))) bool_t
add_mem_p_regs(p_region_t reg)
{
    if (reg.end > (0xffffffff80000000ul - 0xffffff8000000000ul)) {
        reg.end = (0xffffffff80000000ul - 0xffffff8000000000ul);
    }
    if (reg.start > (0xffffffff80000000ul - 0xffffff8000000000ul)) {
        reg.start = (0xffffffff80000000ul - 0xffffff8000000000ul);
    }
    if (reg.start == reg.end) {


        return true;
    }
    if (boot_state.mem_p_regs.count == 16) {
        kprintf("Dropping memory region 0x%lx-0x%lx, try increasing MAX_NUM_FREEMEM_REG\n", reg.start, reg.end);
        return false;
    }
    kprintf("Adding physical memory region 0x%lx-0x%lx\n", reg.start, reg.end);
    boot_state.mem_p_regs.list[boot_state.mem_p_regs.count] = reg;
    boot_state.mem_p_regs.count++;
    return add_allocated_p_region(reg);
}





static __attribute__((__section__(".boot.text"))) bool_t
parse_mem_map(uint32_t mmap_length, uint32_t mmap_addr)
{
    multiboot_mmap_t *mmap = (multiboot_mmap_t *)((word_t)mmap_addr);
    kprintf("Parsing GRUB physical memory map\n");

    while ((word_t)mmap < (word_t)(mmap_addr + mmap_length)) {
        uint64_t mem_start = mmap->base_addr;
        uint64_t mem_length = mmap->length;
        uint32_t type = mmap->type;
        if (mem_start != (uint64_t)(word_t)mem_start) {
            kprintf("\tPhysical memory region not addressable\n");
        } else {
            kprintf("\tPhysical Memory Region from %lx size %lx type %d\n", (long)mem_start, (long)mem_length, type);
            if (type == 1 && mem_start >= 0x100000) {
                if (!add_mem_p_regs((p_region_t) {
                mem_start, mem_start + mem_length
            })) {
                    return false;
                }
            }
        }
        mmap++;
    }
    return true;
}

static __attribute__((__section__(".boot.text"))) bool_t
is_compiled_for_microarchitecture(void)
{
    word_t microarch_generation = 0;
    x86_cpu_identity_t *model_info = x86_cpuid_get_model_info();

    if (0 ) {
        microarch_generation = 7;
    } else if (0 ) {
        microarch_generation = 6;
    } else if (0 ) {
        microarch_generation = 5;
    } else if (0 ) {
        microarch_generation = 4;
    } else if (0 ) {
        microarch_generation = 3;
    } else if (0 ) {
        microarch_generation = 2;
    } else if (0 ) {
        microarch_generation = 1;
    }

    switch (model_info->model) {
    case 0x4E:
    case 0x5E:
        if (microarch_generation > 7) {
            return false;
        }
        break;

    case 0x4D:
    case 0x56:
    case 0x4F:
    case 0x47:
    case 0x3D:
        if (microarch_generation > 6) {
            return false;
        }
        break;

    case 0x3C:
    case 0x3F:
    case 0x45:
    case 0x46:
        if (microarch_generation > 5) {
            return false;
        }
        break;

    case 0x9A:
    case 0x3E:
    case 0x3A:
        if (microarch_generation > 4) {
            return false;
        }
        break;

    case 0x2A :
    case 0x2D :
        if (microarch_generation > 3) {
            return false;
        }
        break;

    case 0x25 :
    case 0x2C :
    case 0x2F :
        if (microarch_generation > 2) {
            return false;
        }
        break;

    case 0x1E :
    case 0x1A :
    case 0x2E :
        if (microarch_generation > 1) {
            return false;
        }
        break;

    default:
        if (!1) {
            return false;
        }
    }

    return true;
}

static __attribute__((__section__(".boot.text"))) bool_t
try_boot_sys(void)
{
    paddr_t mods_end_paddr = boot_state.mods_end_paddr;
    p_region_t ui_p_regs;
    paddr_t load_paddr;

    boot_state.ki_p_reg.start = 0x00200000ul;
    boot_state.ki_p_reg.end = kpptr_to_paddr(ki_end);

    if (!x86_cpuid_initialize()) {
        kprintf("Warning: Your x86 CPU has an unsupported vendor, '%s'.\n" "\tYour setup may not be able to competently run seL4 as " "intended.\n" "\tCurrently supported x86 vendors are AMD and Intel.\n", x86_cpuid_get_identity()->vendor_string)



                                                       ;
    }

    if (!is_compiled_for_microarchitecture()) {
        kprintf("Warning: Your kernel was not compiled for the current microarchitecture.\n");
    }

    cpuid_007h_edx_t edx;
    edx.words[0] = x86_cpuid_edx(0x7, 0);


    if (cpuid_007h_edx_get_ia32_arch_cap_msr(edx)) {
        ia32_arch_capabilities_msr_t cap_msr;
        cap_msr.words[0] = x86_rdmsr(0x10A);
        if (ia32_arch_capabilities_msr_get_rdcl_no(cap_msr) && 0) {
            kprintf("CPU reports not vulnerable to Rogue Data Cache Load (aka Meltdown https://meltdownattack.com) " "yet SKIM window is enabled. Performance is needlessly being impacted, consider disabling.\n")
                                                                                                                 ;
        } else if (!ia32_arch_capabilities_msr_get_rdcl_no(cap_msr) && !0) {
            kprintf("CPU reports vulernable to Rogue Data Cache Load (aka Meltdown https://meltdownattack.com) " "yet SKIM window is *not* enabled. Please re-build with SKIM window enabled.")
                                                                                                 ;
            return false;
        }
    } else {

        if (0 && x86_cpuid_get_identity()->vendor == X86_VENDOR_AMD) {
            kprintf("SKIM window for mitigating Meltdown (https://www.meltdownattack.com) " "not necessary for AMD and performance is being needlessly affected, " "consider disabling\n")

                                          ;
        }
        if (!0 && x86_cpuid_get_identity()->vendor == X86_VENDOR_INTEL) {
            kprintf("***WARNING*** SKIM window not enabled, this machine is probably vulernable " "to Meltdown (https://www.meltdownattack.com), consider enabling\n")
                                                                                       ;
        }
    }



    if (!copy_boot_code_aps(boot_state.mem_lower)) {
        return false;
    }

    mode_init_tls(0);


    kprintf("Kernel loaded to: start=0x%lx end=0x%lx size=0x%lx entry=0x%lx\n", boot_state.ki_p_reg.start, boot_state.ki_p_reg.end, boot_state.ki_p_reg.end - boot_state.ki_p_reg.start, (paddr_t)_start)




           ;


    pic_remap_irqs(0x20);
    if (1) {


        pic_disable();
    }


    if (!acpi_validate_rsdp(&boot_state.acpi_rsdp)) {
        return false;
    }


    if (!acpi_fadt_scan(&boot_state.acpi_rsdp)) {
        return false;
    }

    if (!0 || cmdline_opt.disable_iommu) {
        boot_state.num_drhu = 0;
    } else {

        acpi_dmar_scan(
            &boot_state.acpi_rsdp,
            boot_state.drhu_list,
            &boot_state.num_drhu,
            ((-((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1)) >> 12),
            &boot_state.rmrr_list
        );
    }


    boot_state.num_cpus = acpi_madt_scan(&boot_state.acpi_rsdp, boot_state.cpus, &boot_state.num_ioapic, boot_state.ioapic_paddr);
    if (boot_state.num_cpus == 0) {
        kprintf("No CPUs detected\n");
        return false;
    }

    if (1) {
        if (boot_state.num_ioapic == 0) {
            kprintf("No IOAPICs detected\n");
            return false;
        }
    } else {
        if (boot_state.num_ioapic > 0) {
            kprintf("Detected %d IOAPICs, but configured to use PIC instead\n", boot_state.num_ioapic);
        }
    }

    mods_end_paddr = (((((mods_end_paddr) - 1ul) >> (12)) + 1ul) << (12));
    if(!(mods_end_paddr > boot_state.ki_p_reg.end)) _assert_fail("mods_end_paddr > boot_state.ki_p_reg.end", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/boot_sys.c", 510, __FUNCTION__);

    kprintf("ELF-loading userland images from boot modules:\n");
    load_paddr = mods_end_paddr;

    load_paddr = load_boot_module(boot_state.boot_module_start, load_paddr);
    if (!load_paddr) {
        return false;
    }


    ui_p_regs.start = boot_state.ki_p_reg.end;
    ui_p_regs.end = ui_p_regs.start + load_paddr - mods_end_paddr;

    kprintf("Moving loaded userland images to final location: from=0x%lx to=0x%lx size=0x%lx\n", mods_end_paddr, ui_p_regs.start, ui_p_regs.end - ui_p_regs.start)




     ;
    memcpy((void*)ui_p_regs.start, (void*)mods_end_paddr, ui_p_regs.end - ui_p_regs.start);


    boot_state.ui_info.p_reg.start -= mods_end_paddr - ui_p_regs.start;
    boot_state.ui_info.p_reg.end -= mods_end_paddr - ui_p_regs.start;
    boot_state.ui_info.pv_offset -= mods_end_paddr - ui_p_regs.start;



    if (!platAddDevices()) {
        return false;
    }


    ksNumCPUs = boot_state.num_cpus;

    if (!try_boot_sys_node(boot_state.cpus[0])) {
        return false;
    }

    if (1) {
        ioapic_init(1, boot_state.cpus, boot_state.num_ioapic);
    }


    clh_lock_init();
    start_boot_aps();


    do { clh_lock_acquire(getCurrentCPUIndex(), false); } while(0);

    kprintf("Booting all finished, dropped to user space\n");

    return true;
}

static __attribute__((__section__(".boot.text"))) bool_t
try_boot_sys_mbi1(
    multiboot_info_t* mbi
)
{
    word_t i;
    multiboot_module_t *modules = (multiboot_module_t*)(word_t)mbi->part1.mod_list;

    cmdline_parse((const char *)(word_t)mbi->part1.cmdline, &cmdline_opt);

    if ((mbi->part1.flags & (1ul << (0))) == 0) {
        kprintf("Boot loader did not provide information about physical memory size\n");
        return false;
    }

    if (!(mbi->part1.flags & (1ul << (3)))) {
        kprintf("Boot loader did not provide information about boot modules\n");
        return false;
    }

    kprintf("Detected %d boot module(s):\n", mbi->part1.mod_count);

    if (mbi->part1.mod_count < 1) {
        kprintf("Expect at least one boot module (containing a userland image)\n");
        return false;
    }

    for (i = 0; i < mbi->part1.mod_count; i++) {






         ;
        if ((sword_t)(modules[i].end - modules[i].start) <= 0) {
            kprintf("Invalid boot module size! Possible cause: boot module file not found by QEMU\n");
            return false;
        }
        if (boot_state.mods_end_paddr < modules[i].end) {
            boot_state.mods_end_paddr = modules[i].end;
        }
    }






    boot_state.mem_p_regs.count = 0;
    init_allocated_p_regions();
    if (mbi->part1.flags & (1ul << (6))) {
        if (!parse_mem_map(mbi->part2.mmap_length, mbi->part2.mmap_addr)) {
            return false;
        }
        uint32_t multiboot_mmap_length = mbi->part2.mmap_length;
        if (multiboot_mmap_length > (50 * sizeof(seL4_X86_mb_mmap_t))) {
            multiboot_mmap_length = 50 * sizeof(seL4_X86_mb_mmap_t);
            kprintf("Warning: Multiboot has reported more memory map entries, %zd, " "than the max amount that will be passed in the bootinfo, %d. " "These extra regions will still be turned into untyped caps.", multiboot_mmap_length / sizeof(seL4_X86_mb_mmap_t), 50)


                                                                                                       ;
        }
        memcpy(&boot_state.mb_mmap_info.mmap, (void*)(word_t)mbi->part2.mmap_addr, multiboot_mmap_length);
        boot_state.mb_mmap_info.mmap_length = multiboot_mmap_length;
    } else {

        p_region_t avail;
        avail.start = 0x100000;
        avail.end = (((avail.start + (mbi->part1.mem_upper << 10)) >> (12)) << (12));
        if (!add_mem_p_regs(avail)) {
            return false;
        }
    }


    if ((mbi->part1.flags & (1ul << (11))) == 0) {
        boot_state.vbe_info.vbeMode = -1;
        kprintf("Multiboot gave us no video information\n");
    } else {
        boot_state.vbe_info.vbeInfoBlock = *(seL4_VBEInfoBlock_t*)(seL4_Word)mbi->part2.vbe_control_info;
        boot_state.vbe_info.vbeModeInfoBlock = *(seL4_VBEModeInfoBlock_t*)(seL4_Word)mbi->part2.vbe_mode_info;
        boot_state.vbe_info.vbeMode = mbi->part2.vbe_mode;
        kprintf("Got VBE info in multiboot. Current video mode is %d\n", mbi->part2.vbe_mode);
        boot_state.vbe_info.vbeInterfaceSeg = mbi->part2.vbe_interface_seg;
        boot_state.vbe_info.vbeInterfaceOff = mbi->part2.vbe_interface_off;
        boot_state.vbe_info.vbeInterfaceLen = mbi->part2.vbe_interface_len;
    }

    boot_state.mem_lower = mbi->part1.mem_lower;
    boot_state.boot_module_start = modules->start;


    if (!acpi_init(&boot_state.acpi_rsdp)) {
        return false;
    }

    return true;
}

static __attribute__((__section__(".boot.text"))) bool_t
try_boot_sys_mbi2(
    multiboot2_header_t* mbi2
)
{
    int mod_count = 0;
    multiboot2_tag_t const * tag = (multiboot2_tag_t *)(mbi2 + 1);
    multiboot2_tag_t const * tag_e = (multiboot2_tag_t *)((word_t)mbi2 + mbi2->total_size);






    boot_state.mem_p_regs.count = 0;
    init_allocated_p_regions();
    boot_state.mb_mmap_info.mmap_length = 0;
    boot_state.vbe_info.vbeMode = -1;

    while (tag < tag_e && tag->type != MULTIBOOT2_TAG_END) {
        word_t const behind_tag = (word_t)tag + sizeof(*tag);

        if (tag->type == MULTIBOOT2_TAG_CMDLINE) {
            char const * const cmdline = (char const * const)(behind_tag);
            cmdline_parse(cmdline, &cmdline_opt);
        } else if (tag->type == MULTIBOOT2_TAG_ACPI_1) {
            if (ACPI_V1_SIZE == tag->size - sizeof(*tag)) {
                memcpy(&boot_state.acpi_rsdp, (void *)behind_tag, tag->size - sizeof(*tag));
            }
        } else if (tag->type == MULTIBOOT2_TAG_ACPI_2) {
            if (sizeof(boot_state.acpi_rsdp) == tag->size - sizeof(*tag)) {
                memcpy(&boot_state.acpi_rsdp, (void *)behind_tag, sizeof(boot_state.acpi_rsdp));
            }
        } else if (tag->type == MULTIBOOT2_TAG_MODULE) {
            multiboot2_module_t const * module = (multiboot2_module_t const *)behind_tag;






             ;

            if (mod_count == 0) {
                boot_state.boot_module_start = module->start;
            }

            mod_count ++;
            if ((sword_t)(module->end - module->start) <= 0) {
                kprintf("Invalid boot module size! Possible cause: boot module file not found\n");
                return false;
            }
            if (boot_state.mods_end_paddr < module->end) {
                boot_state.mods_end_paddr = module->end;
            }
        } else if (tag->type == MULTIBOOT2_TAG_MEMORY) {
            multiboot2_memory_t const * s = (multiboot2_memory_t *)(behind_tag + 8);
            multiboot2_memory_t const * e = (multiboot2_memory_t *)((word_t)tag + tag->size);

            for (multiboot2_memory_t const * m = s; m < e; m++) {
                if (!m->addr) {
                    boot_state.mem_lower = m->size;
                }

                kprintf("\tPhysical Memory Region from %llx size %llx type %u\n", m->addr, m->size, m->type);
                if (m->addr != (uint64_t)(word_t)m->addr) {
                    kprintf("\t\tPhysical memory region not addressable\n");
                }

                if (m->type == 1 && m->addr >= 0x100000) {
                    if (!add_mem_p_regs((p_region_t) {
                    m->addr, m->addr + m->size
                }))
                    return false;
                }
            }
        } else if (tag->type == MULTIBOOT2_TAG_FB) {
            multiboot2_fb_t const * fb = (multiboot2_fb_t const *)behind_tag;
            kprintf("Got framebuffer info in multiboot2. Current video mode is at physical address=%llx pitch=%u resolution=%ux%u@%u type=%u\n", fb->addr, fb->pitch, fb->width, fb->height, fb->bpp, fb->type)
                                                                                 ;
            boot_state.fb_info = *fb;
        }

        tag = (multiboot2_tag_t const *)((word_t)tag + (((((tag->size) - 1ul) >> (3)) + 1ul) << (3)));
    }

    kprintf("Detected %d boot module(s):\n", mod_count);

    if (mod_count < 1) {
        kprintf("Expect at least one boot module (containing a userland image)\n");
        return false;
    }

    return true;
}

__attribute__((__section__(".boot.text"))) __attribute__((externally_visible)) void
boot_sys(
    unsigned long multiboot_magic,
    void* mbi)
{
    bool_t result = false;

    if (multiboot_magic == 0x2BADB002) {
        result = try_boot_sys_mbi1(mbi);
    } else if (multiboot_magic == 0x36d76289) {
        result = try_boot_sys_mbi2(mbi);
    } else {
        kprintf("Boot loader is not multiboot 1 or 2 compliant %lx\n", multiboot_magic);
    }

    if (result) {
        result = try_boot_sys();
    }

    if (!result) {
        _fail("boot_sys failed for some reason :(\n", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/boot_sys.c", 785, __func__);
    }

    ksSMP[(getCurrentCPUIndex())].cpu.x86KScurInterrupt = int_invalid;
    ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt = int_invalid;

    schedule();
    activateThread();
}


void out8(uint16_t port, uint8_t value);

void out16(uint16_t port, uint16_t value);

void out32(uint16_t port, uint32_t value);

uint8_t in8(uint16_t port);

uint16_t in16(uint16_t port);

uint32_t in32(uint16_t port);


void serial_init(uint16_t port);





__attribute__((__section__(".boot.bss")))
char cmdline_val[1000];


const char cmdline_str_max_num_nodes[] = {'m', 'a', 'x', '_', 'n', 'u', 'm', '_', 'n', 'o', 'd', 'e', 's', 0};
const char cmdline_str_num_sh_frames[] = {'n', 'u', 'm', '_', 's', 'h', '_', 'f', 'r', 'a', 'm', 'e', 's', 0};
const char cmdline_str_disable_iommu[] = {'d', 'i', 's', 'a', 'b', 'l', 'e', '_', 'i', 'o', 'm', 'm', 'u', 0};

static int is_space(char c)
{
    return c <= ' ';
}

static int __attribute__((unused)) parse_opt(const char *cmdline, const char *opt, char *value, int bufsize)
{
    int len = -1;
    const char *optptr = ((void *)0);

    while (true) {
        for (; is_space(*cmdline) && (*cmdline != 0); cmdline++);
        if (*cmdline == 0) {
            break;
        }

        for (optptr = opt; *optptr && *cmdline && (*cmdline != '=') && !is_space(*cmdline) && (*optptr == *cmdline); optptr++, cmdline++);

        if (*optptr == '\0' && *cmdline == '=') {
            cmdline++;

            for (len = 0; !is_space(*cmdline) && (len < bufsize - 1); cmdline++, len++) {
                value[len] = *cmdline;
            }
            if (bufsize) {
                value[len] = '\0';
            }
        }
        for (; !is_space(*cmdline); cmdline++);
    }

    return len;
}

static int parse_bool(const char *cmdline, const char *opt)
{
    const char *optptr = ((void *)0);

    while (1) {
        for (; is_space(*cmdline) && (*cmdline != 0); cmdline++);
        if (*cmdline == 0) {
            return 0;
        }

        for (optptr = opt; *optptr && *cmdline && !is_space(*cmdline) && (*optptr == *cmdline); optptr++, cmdline++);

        if (*optptr == '\0' && is_space(*cmdline)) {
            return 1;
        } else {
            for (; !is_space(*cmdline); cmdline++);
        }
    }
}

static void __attribute__((unused)) parse_uint16_array(char* str, uint16_t* array, int array_size)
{
    char* last;
    int i = 0;
    int v;

    while (str && i < array_size) {
        for (last = str; *str && *str != ','; str++);
        if (*str == 0) {
            str = 0;
        } else {
            *str = 0;
            str++;
        }
        v = str_to_long(last);
        if (v == -1) {
            array[i] = 0;
        } else {
            array[i] = v;
        }
        i++;
    }
}

void cmdline_parse(const char *cmdline, cmdline_opt_t* cmdline_opt)
{




    const unsigned short * bda_port = (unsigned short *)0x400;
    const unsigned short * bda_equi = (unsigned short *)0x410;
    int const bda_ports_count = (*bda_equi >> 9) & 0x7;




    cmdline_opt->console_port = bda_ports_count && *bda_port ? *bda_port : 0x3f8;

    if (parse_opt(cmdline, "console_port", cmdline_val, 1000) != -1) {
        parse_uint16_array(cmdline_val, &cmdline_opt->console_port, 1);
    }


    if (cmdline_opt->console_port) {
        serial_init(cmdline_opt->console_port);
        x86KSconsolePort = cmdline_opt->console_port;
    }


    kprintf("\nBoot config: parsing cmdline '%s'\n", cmdline);

    if (cmdline_opt->console_port) {
        kprintf("Boot config: console_port = 0x%x\n", cmdline_opt->console_port);
    }




    cmdline_opt->debug_port = bda_ports_count && *bda_port ? *bda_port : 0x3f8;
    if (parse_opt(cmdline, "debug_port", cmdline_val, 1000) != -1) {
        parse_uint16_array(cmdline_val, &cmdline_opt->debug_port, 1);
    }


    if (cmdline_opt->debug_port) {
        serial_init(cmdline_opt->debug_port);
        x86KSdebugPort = cmdline_opt->debug_port;
        kprintf("Boot config: debug_port = 0x%x\n", cmdline_opt->debug_port);
    }


    cmdline_opt->disable_iommu = parse_bool(cmdline, cmdline_str_disable_iommu);
    kprintf("Boot config: disable_iommu = %s\n", cmdline_opt->disable_iommu ? "true" : "false");
}




struct lookupEPTPDPTSlot_ret {
    exception_t status;
    ept_pdpte_t* pdptSlot;
};
typedef struct lookupEPTPDPTSlot_ret lookupEPTPDPTSlot_ret_t;

struct lookupEPTPDSlot_ret {
    exception_t status;
    ept_pde_t* pdSlot;
};
typedef struct lookupEPTPDSlot_ret lookupEPTPDSlot_ret_t;

struct lookupEPTPTSlot_ret {
    exception_t status;
    ept_pte_t* ptSlot;
};
typedef struct lookupEPTPTSlot_ret lookupEPTPTSlot_ret_t;

enum ept_cache_options {
    EPTUncacheable = 0,
    EPTWriteCombining = 1,
    EPTWriteThrough = 4,
    EPTWriteProtected = 5,
    EPTWriteBack = 6
};
typedef enum ept_cache_options ept_cache_options_t;

void
deleteEPTASID(asid_t asid, ept_pml4e_t *ept)
{
    asid_pool_t* poolPtr;

    poolPtr = x86KSASIDTable[asid >> asidLowBits];
    if (poolPtr != ((void *)0)) {
        asid_map_t asid_map = poolPtr->array[asid & ((1ul << (asidLowBits))-1ul)];
        if (asid_map_get_type(asid_map) == asid_map_asid_map_ept &&
                (ept_pml4e_t*)asid_map_asid_map_ept_get_ept_root(asid_map) == ept) {
            poolPtr->array[asid & ((1ul << (asidLowBits))-1ul)] = asid_map_asid_map_none_new();
        }
    }
}

exception_t
performX86EPTPageInvocationUnmap(cap_t cap, cte_t *ctSlot)
{
    unmapEPTPage(
        cap_frame_cap_get_capFSize(cap),
        cap_frame_cap_get_capFMappedASID(cap),
        cap_frame_cap_get_capFMappedAddress(cap),
        (void *)cap_frame_cap_get_capFBasePtr(cap)
    );

    cap_frame_cap_ptr_set_capFMappedAddress(&ctSlot->cap, 0);
    cap_frame_cap_ptr_set_capFMappedASID(&ctSlot->cap, asidInvalid);
    cap_frame_cap_ptr_set_capFMapType(&ctSlot->cap, X86_MappingNone);

    return EXCEPTION_NONE;
}

findEPTForASID_ret_t
findEPTForASID(asid_t asid)
{
    findEPTForASID_ret_t ret;
    asid_map_t asid_map;

    asid_map = findMapForASID(asid);
    if (asid_map_get_type(asid_map) != asid_map_asid_map_ept) {
        current_lookup_fault = lookup_fault_invalid_root_new();

        ret.ept = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }

    ret.ept = (ept_pml4e_t*)asid_map_asid_map_ept_get_ept_root(asid_map);
    ret.status = EXCEPTION_NONE;
    return ret;
}

static ept_pml4e_t* __attribute__((__const__))
lookupEPTPML4Slot(ept_pml4e_t *pml4, vptr_t vptr)
{
    return pml4 + ( (((uint64_t)(vptr)) >> (((((12) + 9) + 9) + 9))) & ((1ul << (9))-1ul));
}

static lookupEPTPDPTSlot_ret_t __attribute__((__const__))
lookupEPTPDPTSlot(ept_pml4e_t *pml4, vptr_t vptr)
{
    lookupEPTPDPTSlot_ret_t ret;
    ept_pml4e_t *pml4Slot;

    pml4Slot = lookupEPTPML4Slot(pml4, vptr);

    if (!ept_pml4e_ptr_get_read(pml4Slot)) {
        current_lookup_fault = lookup_fault_missing_capability_new(22);

        ret.pdptSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }

    ept_pdpte_t *pdpt = ptrFromPAddr(ept_pml4e_ptr_get_pdpt_base_address(pml4Slot));
    uint32_t index = ( ((vptr) >> ((((12) + 9) + 9))) & ((1ul << (9))-1ul));
    ret.pdptSlot = pdpt + index;
    ret.status = EXCEPTION_NONE;
    return ret;
}

static lookupEPTPDSlot_ret_t
lookupEPTPDSlot(ept_pml4e_t* pml4, vptr_t vptr)
{
    lookupEPTPDSlot_ret_t ret;
    lookupEPTPDPTSlot_ret_t lu_ret;

    lu_ret = lookupEPTPDPTSlot(pml4, vptr);
    if (lu_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        ret.pdSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }

    if (!ept_pdpte_ptr_get_read(lu_ret.pdptSlot)) {
        current_lookup_fault = lookup_fault_missing_capability_new(22);

        ret.pdSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }

    ept_pde_t *pd = ptrFromPAddr(ept_pdpte_ptr_get_pd_base_address(lu_ret.pdptSlot));
    uint32_t index = ( ((vptr) >> (((12) + 9))) & ((1ul << (9))-1ul));
    ret.pdSlot = pd + index;
    ret.status = EXCEPTION_NONE;
    return ret;
}

static lookupEPTPTSlot_ret_t
lookupEPTPTSlot(ept_pml4e_t* pml4, vptr_t vptr)
{
    lookupEPTPTSlot_ret_t ret;
    lookupEPTPDSlot_ret_t lu_ret;

    lu_ret = lookupEPTPDSlot(pml4, vptr);
    if (lu_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        ret.ptSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }

    if ((ept_pde_ptr_get_page_size(lu_ret.pdSlot) != ept_pde_ept_pde_pt) ||
            !ept_pde_ept_pde_pt_ptr_get_read(lu_ret.pdSlot)) {
        current_lookup_fault = lookup_fault_missing_capability_new(22);

        ret.ptSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }

    ept_pte_t *pt = ptrFromPAddr(ept_pde_ept_pde_pt_ptr_get_pt_base_address(lu_ret.pdSlot));
    uint32_t index = ( ((vptr) >> ((12))) & ((1ul << (9))-1ul));

    ret.ptSlot = pt + index;
    ret.status = EXCEPTION_NONE;
    return ret;
}

static ept_cache_options_t
eptCacheFromVmAttr(vm_attributes_t vmAttr)
{


    ept_cache_options_t option = vmAttr.words[0];
    if (option != EPTUncacheable ||
            option != EPTWriteCombining ||
            option != EPTWriteThrough ||
            option != EPTWriteBack) {

        option = EPTWriteBack;
    }
    return option;
}

EPTPDPTMapped_ret_t
EPTPDPTMapped(asid_t asid, vptr_t vptr, ept_pdpte_t *pdpt)
{
    EPTPDPTMapped_ret_t ret;
    findEPTForASID_ret_t asid_ret;
    ept_pml4e_t *pml4Slot;

    asid_ret = findEPTForASID(asid);
    if (asid_ret.status != EXCEPTION_NONE) {
        ret.pml4 = ((void *)0);
        ret.pml4Slot = ((void *)0);
        ret.status = asid_ret.status;
        return ret;
    }

    pml4Slot = lookupEPTPML4Slot(asid_ret.ept, vptr);

    if (ept_pml4e_ptr_get_read(pml4Slot)
            && ptrFromPAddr(ept_pml4e_ptr_get_pdpt_base_address(pml4Slot)) == pdpt) {
        ret.pml4 = asid_ret.ept;
        ret.pml4Slot = pml4Slot;
        ret.status = EXCEPTION_NONE;
        return ret;
    } else {
        ret.pml4 = ((void *)0);
        ret.pml4Slot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }
}

void
unmapEPTPDPT(asid_t asid, vptr_t vaddr, ept_pdpte_t *pdpt)
{
    EPTPDPTMapped_ret_t lu_ret;

    lu_ret = EPTPDPTMapped(asid, vaddr, pdpt);

    if (lu_ret.status == EXCEPTION_NONE) {
        *lu_ret.pml4Slot = ept_pml4e_new(0, 0, 0, 0);
        invept(lu_ret.pml4);
    }
}

static exception_t
performEPTPDPTInvocationUnmap(cap_t cap, cte_t *cte)
{
    if (cap_ept_pdpt_cap_get_capPDPTIsMapped(cap)) {
        ept_pdpte_t *pdpt = (ept_pdpte_t*)cap_ept_pdpt_cap_get_capPDPTBasePtr(cap);
        unmapEPTPDPT(
            cap_ept_pdpt_cap_get_capPDPTMappedASID(cap),
            cap_ept_pdpt_cap_get_capPDPTMappedAddress(cap),
            pdpt);
        clearMemory((void *)pdpt, cap_get_capSizeBits(cap));
    }
    cap_ept_pdpt_cap_ptr_set_capPDPTIsMapped(&(cte->cap), 0);

    return EXCEPTION_NONE;
}

static exception_t
performEPTPDPTInvocationMap(cap_t cap, cte_t *cte, ept_pml4e_t pml4e, ept_pml4e_t *pml4Slot, ept_pml4e_t *pml4)
{
    cte->cap = cap;
    *pml4Slot = pml4e;
    invept(pml4);

    return EXCEPTION_NONE;
}

static exception_t
decodeX86EPTPDPTInvocation(
    word_t invLabel,
    word_t length,
    cte_t *cte,
    cap_t cap,
    extra_caps_t excaps,
    word_t *buffer
)
{
    word_t vaddr;
    cap_t pml4Cap;
    ept_pml4e_t* pml4;
    ept_pml4e_t pml4e;
    paddr_t paddr;
    asid_t asid;
    findEPTForASID_ret_t find_ret;
    ept_pml4e_t* pml4Slot;

    if (invLabel == X86EPTPDPTUnmap) {
        if (!isFinalCapability(cte)) {
            current_syscall_error.type = seL4_RevokeFirst;
            return EXCEPTION_SYSCALL_ERROR;
        }
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performEPTPDPTInvocationUnmap(cap, cte);
    }

    if (invLabel != X86EPTPDPTMap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 308, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPDPT Illegal operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 2 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 314, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPDPTMap: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cap_ept_pdpt_cap_get_capPDPTIsMapped(cap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 320, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPDPTMap: EPT PDPT is already mapped to a PML4."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vaddr = getSyscallArg(0, buffer);



    vaddr = vaddr & ~(((uint64_t)1 << ((((12) + 9) + 9) + 9)) - 1);
    pml4Cap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(pml4Cap) != cap_ept_pml4_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 335, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPDPTMap: Not a valid EPT PML4."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    pml4 = (ept_pml4e_t*)cap_ept_pml4_cap_get_capPML4BasePtr(pml4Cap);
    asid = cap_ept_pml4_cap_get_capPML4MappedASID(pml4Cap);

    find_ret = findEPTForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if (find_ret.ept != pml4) {
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    pml4Slot = lookupEPTPML4Slot(pml4, vaddr);

    if (ept_pml4e_ptr_get_read(pml4Slot)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 363, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPDPTMap: PDPT already mapped here."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_DeleteFirst;
        return EXCEPTION_SYSCALL_ERROR;
    }

    paddr = addrFromPPtr((void*)cap_ept_pdpt_cap_get_capPDPTBasePtr(cap));
    pml4e = ept_pml4e_new(
                paddr,
                1,
                1,
                1
            );

    cap = cap_ept_pdpt_cap_set_capPDPTIsMapped(cap, 1);
    cap = cap_ept_pdpt_cap_set_capPDPTMappedASID(cap, asid);
    cap = cap_ept_pdpt_cap_set_capPDPTMappedAddress(cap, vaddr);

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return performEPTPDPTInvocationMap(cap, cte, pml4e, pml4Slot, pml4);
}

exception_t
decodeX86EPTInvocation(
    word_t invLabel,
    word_t length,
    cptr_t cptr,
    cte_t* cte,
    cap_t cap,
    extra_caps_t excaps,
    word_t* buffer
)
{
    switch (cap_get_capType(cap)) {
    case cap_ept_pdpt_cap:
        return decodeX86EPTPDPTInvocation(invLabel, length, cte, cap, excaps, buffer);
    case cap_ept_pd_cap:
        return decodeX86EPTPDInvocation(invLabel, length, cte, cap, excaps, buffer);
    case cap_ept_pt_cap:
        return decodeX86EPTPTInvocation(invLabel, length, cte, cap, excaps, buffer);
    default:
        _fail("Invalid cap type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/ept.c", 403, __func__);
    }
}

EPTPageDirectoryMapped_ret_t
EPTPageDirectoryMapped(asid_t asid, vptr_t vaddr, ept_pde_t *pd)
{
    EPTPageDirectoryMapped_ret_t ret;
    lookupEPTPDPTSlot_ret_t find_ret;
    findEPTForASID_ret_t asid_ret;

    asid_ret = findEPTForASID(asid);
    if (asid_ret.status != EXCEPTION_NONE) {
        ret.pml4 = ((void *)0);
        ret.pdptSlot = ((void *)0);
        ret.status = asid_ret.status;
        return ret;
    }

    find_ret = lookupEPTPDPTSlot(asid_ret.ept, vaddr);
    if (find_ret.status != EXCEPTION_NONE) {
        ret.pml4 = ((void *)0);
        ret.pdptSlot = ((void *)0);
        ret.status = find_ret.status;
        return ret;
    }

    if (ept_pdpte_ptr_get_read(find_ret.pdptSlot)
            && ptrFromPAddr(ept_pdpte_ptr_get_pd_base_address(find_ret.pdptSlot)) == pd) {
        ret.pml4 = asid_ret.ept;
        ret.pdptSlot = find_ret.pdptSlot;
        ret.status = EXCEPTION_NONE;
        return ret;
    } else {
        ret.pml4 = ((void *)0);
        ret.pdptSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }
}

void
unmapEPTPageDirectory(asid_t asid, vptr_t vaddr, ept_pde_t *pd)
{
    EPTPageDirectoryMapped_ret_t lu_ret;

    lu_ret = EPTPageDirectoryMapped(asid, vaddr, pd);

    if (lu_ret.status == EXCEPTION_NONE) {
        *lu_ret.pdptSlot = ept_pdpte_new(
                               0,
                               0,
                               0,
                               0,
                               0
                           );
        invept(lu_ret.pml4);
    }
}

static exception_t
performEPTPDInvocationUnmap(cap_t cap, cte_t *cte)
{
    if (cap_ept_pd_cap_get_capPDIsMapped(cap)) {
        ept_pde_t *pd = (ept_pde_t*)cap_ept_pd_cap_get_capPDBasePtr(cap);
        unmapEPTPageDirectory(
            cap_ept_pd_cap_get_capPDMappedASID(cap),
            cap_ept_pd_cap_get_capPDMappedAddress(cap),
            pd);
        clearMemory((void*)pd, cap_get_capSizeBits(cap));
    }
    cap_ept_pd_cap_ptr_set_capPDIsMapped(&(cte->cap), 0);

    return EXCEPTION_NONE;
}

static exception_t
performEPTPDInvocationMap(cap_t cap, cte_t *cte, ept_pdpte_t pdpte, ept_pdpte_t *pdptSlot, ept_pml4e_t *pml4)
{
    cte->cap = cap;
    *pdptSlot = pdpte;
    invept(pml4);

    return EXCEPTION_NONE;
}

exception_t
decodeX86EPTPDInvocation(
    word_t invLabel,
    word_t length,
    cte_t* cte,
    cap_t cap,
    extra_caps_t excaps,
    word_t* buffer
)
{
    word_t vaddr;
    cap_t pml4Cap;
    ept_pml4e_t* pml4;
    ept_pdpte_t pdpte;
    paddr_t paddr;
    asid_t asid;
    findEPTForASID_ret_t find_ret;
    lookupEPTPDPTSlot_ret_t lu_ret;

    if (invLabel == X86EPTPDUnmap) {
        if (!isFinalCapability(cte)) {
            current_syscall_error.type = seL4_RevokeFirst;
            return EXCEPTION_SYSCALL_ERROR;
        }
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performEPTPDInvocationUnmap(cap, cte);
    }

    if (invLabel != X86EPTPDMap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 518, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPD Illegal operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 2 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 524, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPDMap: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cap_ept_pd_cap_get_capPDIsMapped(cap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 530, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPDMap: EPT Page directory is already mapped to a PDPT."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type =
            seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vaddr = getSyscallArg(0, buffer);
    vaddr = vaddr & ~((1ul << ((((12) + 9) + 9)))-1ul);
    pml4Cap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(pml4Cap) != cap_ept_pml4_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 543, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPDMap: Not a valid EPT pml4."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    pml4 = (ept_pml4e_t*)cap_ept_pml4_cap_get_capPML4BasePtr(pml4Cap);
    asid = cap_ept_pml4_cap_get_capPML4MappedASID(pml4Cap);

    find_ret = findEPTForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 555, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPDMap: EPT PML4 is not mapped."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if (find_ret.ept != pml4) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 563, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPDMap: EPT PML4 asid is invalid."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    lu_ret = lookupEPTPDPTSlot(pml4, vaddr);
    if (lu_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (ept_pdpte_ptr_get_read(lu_ret.pdptSlot)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 578, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPDMap: Page directory already mapped here."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_DeleteFirst;
        return EXCEPTION_SYSCALL_ERROR;
    }

    paddr = addrFromPPtr((void*)(cap_ept_pd_cap_get_capPDBasePtr(cap)));
    pdpte = ept_pdpte_new(
                paddr,
                0,
                1,
                1,
                1
            );

    cap = cap_ept_pd_cap_set_capPDIsMapped(cap, 1);
    cap = cap_ept_pd_cap_set_capPDMappedASID(cap, asid);
    cap = cap_ept_pd_cap_set_capPDMappedAddress(cap, vaddr);

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return performEPTPDInvocationMap(cap, cte, pdpte, lu_ret.pdptSlot, pml4);
}

EPTPageTableMapped_ret_t
EPTPageTableMapped(asid_t asid, vptr_t vaddr, ept_pte_t *pt)
{
    EPTPageTableMapped_ret_t ret;
    lookupEPTPDSlot_ret_t find_ret;
    findEPTForASID_ret_t asid_ret;

    asid_ret = findEPTForASID(asid);
    if (asid_ret.status != EXCEPTION_NONE) {
        ret.pml4 = ((void *)0);
        ret.pdSlot = ((void *)0);
        ret.status = asid_ret.status;
        return ret;
    }

    find_ret = lookupEPTPDSlot(asid_ret.ept, vaddr);
    if (find_ret.status != EXCEPTION_NONE) {
        ret.pml4 = ((void *)0);
        ret.pdSlot = ((void *)0);
        ret.status = find_ret.status;
        return ret;
    }

    if (ept_pde_ptr_get_page_size(find_ret.pdSlot) == ept_pde_ept_pde_pt
            && ptrFromPAddr(ept_pde_ept_pde_pt_ptr_get_pt_base_address(find_ret.pdSlot)) == pt) {
        ret.pml4 = asid_ret.ept;
        ret.pdSlot = find_ret.pdSlot;
        ret.status = EXCEPTION_NONE;
        return ret;
    } else {
        ret.pml4 = ((void *)0);
        ret.pdSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }
}

void
unmapEPTPageTable(asid_t asid, vptr_t vaddr, ept_pte_t *pt)
{
    EPTPageTableMapped_ret_t lu_ret;

    lu_ret = EPTPageTableMapped(asid, vaddr, pt);

    if (lu_ret.status == EXCEPTION_NONE) {
        *lu_ret.pdSlot = ept_pde_ept_pde_pt_new(
                             0,
                             0,
                             0,
                             0,
                             0
                         );
        invept(lu_ret.pml4);
    }
}

static exception_t
performEPTPTInvocationUnmap(cap_t cap, cte_t *cte)
{
    if (cap_ept_pt_cap_get_capPTIsMapped(cap)) {
        ept_pte_t *pt = (ept_pte_t*)cap_ept_pt_cap_get_capPTBasePtr(cap);
        unmapEPTPageTable(
            cap_ept_pt_cap_get_capPTMappedASID(cap),
            cap_ept_pt_cap_get_capPTMappedAddress(cap),
            pt);
        clearMemory((void *)pt, cap_get_capSizeBits(cap));
    }
    cap_ept_pt_cap_ptr_set_capPTIsMapped(&(cte->cap), 0);

    return EXCEPTION_NONE;
}

static exception_t
performEPTPTInvocationMap(cap_t cap, cte_t *cte, ept_pde_t pde, ept_pde_t *pdSlot, ept_pml4e_t *pml4)
{
    cte->cap = cap;
    *pdSlot = pde;
    invept(pml4);

    return EXCEPTION_NONE;
}

exception_t
decodeX86EPTPTInvocation(
    word_t invLabel,
    word_t length,
    cte_t* cte,
    cap_t cap,
    extra_caps_t excaps,
    word_t* buffer
)
{
    word_t vaddr;
    cap_t pml4Cap;
    ept_pml4e_t* pml4;
    ept_pde_t pde;
    paddr_t paddr;
    asid_t asid;
    findEPTForASID_ret_t find_ret;
    lookupEPTPDSlot_ret_t lu_ret;

    if (invLabel == X86EPTPTUnmap) {
        if (!isFinalCapability(cte)) {
            current_syscall_error.type = seL4_RevokeFirst;
            return EXCEPTION_SYSCALL_ERROR;
        }
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performEPTPTInvocationUnmap(cap, cte);
    }

    if (invLabel != X86EPTPTMap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 711, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPT Illegal operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 2 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 717, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPT: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cap_ept_pt_cap_get_capPTIsMapped(cap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 723, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPT EPT Page table is already mapped to an EPT page directory."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type =
            seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vaddr = getSyscallArg(0, buffer);
    vaddr = vaddr & ~((1ul << (((12) + 9)))-1ul);
    pml4Cap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(pml4Cap) != cap_ept_pml4_cap ||
            !cap_ept_pml4_cap_get_capPML4IsMapped(pml4Cap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 737, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPTMap: Not a valid EPT pml4."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    pml4 = (ept_pml4e_t*)(cap_ept_pml4_cap_get_capPML4BasePtr(pml4Cap));
    asid = cap_ept_pml4_cap_get_capPML4MappedASID(pml4Cap);

    find_ret = findEPTForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if (find_ret.ept != pml4) {
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    lu_ret = lookupEPTPDSlot(pml4, vaddr);
    if (lu_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if (((ept_pde_ptr_get_page_size(lu_ret.pdSlot) == ept_pde_ept_pde_pt) &&
            ept_pde_ept_pde_pt_ptr_get_read(lu_ret.pdSlot)) ||
            ((ept_pde_ptr_get_page_size(lu_ret.pdSlot) == ept_pde_ept_pde_2m) &&
             ept_pde_ept_pde_2m_ptr_get_read(lu_ret.pdSlot))) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 774, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPTMap: Page table already mapped here"); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_DeleteFirst;
        return EXCEPTION_SYSCALL_ERROR;
    }

    paddr = addrFromPPtr((void*)(cap_ept_pt_cap_get_capPTBasePtr(cap)));
    pde = ept_pde_ept_pde_pt_new(
              paddr,
              0,
              1,
              1,
              1
          );

    cap = cap_ept_pt_cap_set_capPTIsMapped(cap, 1);
    cap = cap_ept_pt_cap_set_capPTMappedASID(cap, asid);
    cap = cap_ept_pt_cap_set_capPTMappedAddress(cap, vaddr);

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return performEPTPTInvocationMap(cap, cte, pde, lu_ret.pdSlot, pml4);
}

static exception_t
performEPTPageMapPTE(cap_t cap, cte_t *cte, ept_pte_t *ptSlot, ept_pte_t pte, ept_pml4e_t *pml4)
{
    *ptSlot = pte;
    cte->cap = cap;
    invept(pml4);

    return EXCEPTION_NONE;
}

static exception_t
performEPTPageMapPDE(cap_t cap, cte_t *cte, ept_pde_t *pdSlot, ept_pde_t pde1, ept_pde_t pde2, ept_pml4e_t *pml4)
{
    pdSlot[0] = pde1;
    if (21 == 22) {
        pdSlot[1] = pde2;
    }
    cte->cap = cap;
    invept(pml4);

    return EXCEPTION_NONE;
}

exception_t
decodeX86EPTPageMap(
    word_t invLabel,
    word_t length,
    cte_t* cte,
    cap_t cap,
    extra_caps_t excaps,
    word_t* buffer)
{
    word_t vaddr;
    word_t w_rightsMask;
    paddr_t paddr;
    cap_t pml4Cap;
    ept_pml4e_t* pml4;
    vm_rights_t capVMRights;
    vm_rights_t vmRights;
    vm_attributes_t vmAttr;
    vm_page_size_t frameSize;
    asid_t asid;

    frameSize = cap_frame_cap_get_capFSize(cap);
    vaddr = getSyscallArg(0, buffer);
    vaddr = vaddr & ~((1ul << ((12)))-1ul);
    w_rightsMask = getSyscallArg(1, buffer);
    vmAttr = vmAttributesFromWord(getSyscallArg(2, buffer));
    pml4Cap = excaps.excaprefs[0]->cap;

    capVMRights = cap_frame_cap_get_capFVMRights(cap);

    if (cap_frame_cap_get_capFMappedASID(cap) != asidInvalid) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 849, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPageMap: Frame already mapped."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if(!(cap_frame_cap_get_capFMapType(cap) == X86_MappingNone)) _assert_fail("cap_frame_cap_get_capFMapType(cap) == X86_MappingNone", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/ept.c", 856, __FUNCTION__);

    if (cap_get_capType(pml4Cap) != cap_ept_pml4_cap ||
            !cap_ept_pml4_cap_get_capPML4IsMapped(pml4Cap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 860, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPageMap: Attempting to map frame into invalid ept pml4."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    pml4 = (ept_pml4e_t*)(cap_ept_pml4_cap_get_capPML4BasePtr(pml4Cap));
    asid = cap_ept_pml4_cap_get_capPML4MappedASID(pml4Cap);

    findEPTForASID_ret_t find_ret = findEPTForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if (find_ret.ept != pml4) {
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }


    vmRights = maskVMRights(capVMRights, rightsFromWord(w_rightsMask));

    if (!checkVPAlignment(frameSize, vaddr)) {
        current_syscall_error.type = seL4_AlignmentError;

        return EXCEPTION_SYSCALL_ERROR;
    }

    paddr = addrFromPPtr((void*)cap_frame_cap_get_capFBasePtr(cap));

    cap = cap_frame_cap_set_capFMappedASID(cap, asid);
    cap = cap_frame_cap_set_capFMappedAddress(cap, vaddr);
    cap = cap_frame_cap_set_capFMapType(cap, X86_MappingEPT);

    switch (frameSize) {

    case X86_SmallPage: {
        lookupEPTPTSlot_ret_t lu_ret;
        ept_pte_t pte;

        lu_ret = lookupEPTPTSlot(pml4, vaddr);
        if (lu_ret.status != EXCEPTION_NONE) {
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = false;

            return EXCEPTION_SYSCALL_ERROR;
        }

        if (ept_pte_ptr_get_read(lu_ret.ptSlot)) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 915, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPageMap: Mapping already present."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_DeleteFirst;
            return EXCEPTION_SYSCALL_ERROR;
        }

        pte = ept_pte_new(
                  paddr,
                  0,
                  0,
                  eptCacheFromVmAttr(vmAttr),
                  1,
                  WritableFromVMRights(vmRights),
                  1);

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performEPTPageMapPTE(cap, cte, lu_ret.ptSlot, pte, pml4);
    }


    case X86_LargePage: {
        lookupEPTPDSlot_ret_t lu_ret;

        lu_ret = lookupEPTPDSlot(pml4, vaddr);
        if (lu_ret.status != EXCEPTION_NONE) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 939, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPageMap: Need a page directory first."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = false;

            return EXCEPTION_SYSCALL_ERROR;
        }


        if ((ept_pde_ptr_get_page_size(lu_ret.pdSlot) == ept_pde_ept_pde_pt) &&
                ept_pde_ept_pde_pt_ptr_get_read(lu_ret.pdSlot)) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 949, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPageMap: Page table already present."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_DeleteFirst;
            return EXCEPTION_SYSCALL_ERROR;
        }
        if (21 != ((12) + 9) &&
                (ept_pde_ptr_get_page_size(lu_ret.pdSlot + 1) == ept_pde_ept_pde_pt) &&
                ept_pde_ept_pde_pt_ptr_get_read(lu_ret.pdSlot + 1)) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 956, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPageMap: Page table already present."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_DeleteFirst;
            return EXCEPTION_SYSCALL_ERROR;
        }
        if ((ept_pde_ptr_get_page_size(lu_ret.pdSlot) == ept_pde_ept_pde_2m) &&
                ept_pde_ept_pde_2m_ptr_get_read(lu_ret.pdSlot)) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 962, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPageMap: Mapping already present."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_DeleteFirst;
            return EXCEPTION_SYSCALL_ERROR;
        }

        ept_pde_t pde1 = ept_pde_ept_pde_2m_new(
                             paddr,
                             0,
                             0,
                             eptCacheFromVmAttr(vmAttr),
                             1,
                             WritableFromVMRights(vmRights),
                             1);

        ept_pde_t pde2 = ept_pde_ept_pde_2m_new(
                             paddr + (1ul << (((12) + 9))),
                             0,
                             0,
                             eptCacheFromVmAttr(vmAttr),
                             1,
                             WritableFromVMRights(vmRights),
                             1);

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performEPTPageMapPDE(cap, cte, lu_ret.pdSlot, pde1, pde2, pml4);
    }

    default:


        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 992, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86EPTPageMap: Attempted to map unsupported page size."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;
        return EXCEPTION_SYSCALL_ERROR;
    }
}

void
unmapEPTPage(vm_page_size_t page_size, asid_t asid, vptr_t vptr, void *pptr)
{
    findEPTForASID_ret_t find_ret;
    paddr_t addr = addrFromPPtr(pptr);

    find_ret = findEPTForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        return;
    }

    switch (page_size) {
    case X86_SmallPage: {
        lookupEPTPTSlot_ret_t lu_ret;

        lu_ret = lookupEPTPTSlot(find_ret.ept, vptr);
        if (lu_ret.status != EXCEPTION_NONE) {
            return;
        }
        if (!ept_pte_ptr_get_read(lu_ret.ptSlot)) {
            return;
        }
        if (ept_pte_ptr_get_page_base_address(lu_ret.ptSlot) != addr) {
            return;
        }

        *lu_ret.ptSlot = ept_pte_new(0, 0, 0, 0, 0, 0, 0);
        break;
    }
    case X86_LargePage: {
        lookupEPTPDSlot_ret_t lu_ret;

        lu_ret = lookupEPTPDSlot(find_ret.ept, vptr);
        if (lu_ret.status != EXCEPTION_NONE) {
            return;
        }
        if (ept_pde_ptr_get_page_size(lu_ret.pdSlot) != ept_pde_ept_pde_2m) {
            return;
        }
        if (!ept_pde_ept_pde_2m_ptr_get_read(lu_ret.pdSlot)) {
            return;
        }
        if (ept_pde_ept_pde_2m_ptr_get_page_base_address(lu_ret.pdSlot) != addr) {
            return;
        }

        lu_ret.pdSlot[0] = ept_pde_ept_pde_2m_new(0, 0, 0, 0, 0, 0, 0);

        if (21 != ((12) + 9)) {
            if(!(ept_pde_ptr_get_page_size(lu_ret.pdSlot + 1) == ept_pde_ept_pde_2m)) _assert_fail("ept_pde_ptr_get_page_size(lu_ret.pdSlot + 1) == ept_pde_ept_pde_2m", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/ept.c", 1048, __FUNCTION__);
            if(!(ept_pde_ept_pde_2m_ptr_get_read(lu_ret.pdSlot + 1))) _assert_fail("ept_pde_ept_pde_2m_ptr_get_read(lu_ret.pdSlot + 1)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/ept.c", 1049, __FUNCTION__);
            if(!(ept_pde_ept_pde_2m_ptr_get_page_base_address(lu_ret.pdSlot + 1) == addr + (1ul << (21)))) _assert_fail("ept_pde_ept_pde_2m_ptr_get_page_base_address(lu_ret.pdSlot + 1) == addr + BIT(21)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/ept.c", 1050, __FUNCTION__);

            lu_ret.pdSlot[1] = ept_pde_ept_pde_2m_new(0, 0, 0, 0, 0, 0, 0);
        }
        break;
    }
    default:



        if(!(!"Invalid page size for unmap")) _assert_fail("!\"Invalid page size for unmap\"", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/ept.c", 1060, __FUNCTION__);
    }
}




__attribute__((__section__(".boot.data"))) __attribute__((externally_visible))
volatile word_t smp_aps_index = 1;
__attribute__((__section__(".boot.text"))) static void
start_cpu(cpu_id_t cpu_id, paddr_t boot_fun_paddr)
{

    x86_mfence();


    apic_send_init_ipi(cpu_id);
    apic_send_startup_ipi(cpu_id, boot_fun_paddr);
}

__attribute__((__section__(".boot.text"))) void
start_boot_aps(void)
{

    cpu_mapping.index_to_cpu_id[getCurrentCPUIndex()] = boot_state.cpus[0];





    while (smp_aps_index < boot_state.num_cpus) {
        word_t current_ap_index = smp_aps_index;

                                                                   ;




        cpu_mapping.index_to_cpu_id[current_ap_index] = boot_state.cpus[current_ap_index];
        start_cpu(boot_state.cpus[current_ap_index], 0x1000);


        while (smp_aps_index == current_ap_index);
    }
}

__attribute__((__section__(".boot.text"))) bool_t
copy_boot_code_aps(uint32_t mem_lower)
{
    if(!(boot_cpu_end - boot_cpu_start < 0x400)) _assert_fail("boot_cpu_end - boot_cpu_start < 0x400", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/smp_sys.c", 83, __FUNCTION__);




    word_t boot_size = (word_t)(boot_cpu_end - boot_cpu_start);
    word_t boot_node_top = 0x1000 + boot_size;
    word_t mem_lower_bytes = mem_lower << 10;
    if (boot_node_top > 0x7bff) {
        kprintf("AP boot code does not fit in chosen memory hole. Can be at most %lu, is %lu\n", (word_t)(0x7bff - 0x1000), boot_size)
                                                                          ;
        return false;
    }
    if (mem_lower_bytes < boot_node_top) {
        kprintf("Need lower physical memory up to %lu to be free. Multiboot reports only up to %lu\n", boot_node_top, mem_lower_bytes)
                                              ;
        return false;
    }


    memcpy((void*)0x1000, boot_cpu_start, boot_size);
    return true;
}

static __attribute__((__section__(".boot.text"))) bool_t
try_boot_node(void)
{
    setCurrentVSpaceRoot(kpptr_to_paddr(x64KSKernelPML4), 0);


    __asm__ volatile("" ::: "memory");


    if (!init_cpu(1)) {
        return false;
    }




    return true;
}




__attribute__((externally_visible)) void
boot_node(void)
{
    bool_t result;

    mode_init_tls(smp_aps_index);
    result = try_boot_node();

    if (!result) {
        _fail("boot_node failed for some reason :(\n", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/smp_sys.c", 138, __func__);
    }

    smp_aps_index++;


    do { clh_lock_acquire(getCurrentCPUIndex(), false); } while(0);

    init_core_state(((tcb_t*) 1));
    ksSMP[(getCurrentCPUIndex())].cpu.x86KScurInterrupt = int_invalid;
    ksSMP[(getCurrentCPUIndex())].cpu.x86KSPendingInterrupt = int_invalid;

    schedule();
    activateThread();
}

void
Arch_postModifyRegisters(tcb_t *tptr)
{
    Mode_postModifyRegisters(tptr);
}

static exception_t
performPageGetAddress(void *vbase_ptr)
{
    paddr_t capFBasePtr;


    capFBasePtr = addrFromPPtr(vbase_ptr);


    setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, msgRegisters[0], capFBasePtr);
    setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, msgInfoRegister,
                wordFromMessageInfo(seL4_MessageInfo_new(0, 0, 0, 1)));

    return EXCEPTION_NONE;
}


void deleteASIDPool(asid_t asid_base, asid_pool_t* pool)
{

    if(!((!((asid_base) & ((1ul << (asidLowBits))-1ul))))) _assert_fail("IS_ALIGNED(asid_base, asidLowBits)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 42, __FUNCTION__);

    if (x86KSASIDTable[asid_base >> asidLowBits] == pool) {
        for (unsigned int offset = 0; offset < (1ul << (asidLowBits)); offset++) {
            asid_map_t asid_map = pool->array[offset];
            if (asid_map_get_type(asid_map) == asid_map_asid_map_vspace) {
                vspace_root_t *vspace = (vspace_root_t*)asid_map_asid_map_vspace_get_vspace_root(asid_map);
                hwASIDInvalidate(asid_base + offset, vspace);
            }
        }
        x86KSASIDTable[asid_base >> asidLowBits] = ((void *)0);
        setVMRoot(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
    }
}

exception_t performASIDControlInvocation(void* frame, cte_t* slot, cte_t* parent, asid_t asid_base)
{


    cap_untyped_cap_ptr_set_capFreeIndex(&(parent->cap),
                                         ((1ul << ((cap_untyped_cap_get_capBlockSize(parent->cap)) - 4))));

    memzero(frame, (1ul << (pageBitsForSize(X86_SmallPage))));


    cteInsert(
        cap_asid_pool_cap_new(
            asid_base,
            ((word_t)(frame))
        ),
        parent,
        slot
    );

    if(!((asid_base & ((1ul << (asidLowBits))-1ul)) == 0)) _assert_fail("(asid_base & MASK(asidLowBits)) == 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 76, __FUNCTION__);
    x86KSASIDTable[asid_base >> asidLowBits] = (asid_pool_t*)frame;

    return EXCEPTION_NONE;
}

void deleteASID(asid_t asid, vspace_root_t *vspace)
{
    asid_pool_t* poolPtr;

    poolPtr = x86KSASIDTable[asid >> asidLowBits];
    hwASIDInvalidate(asid, vspace);
    if (poolPtr != ((void *)0)) {
        asid_map_t asid_map = poolPtr->array[asid & ((1ul << (asidLowBits))-1ul)];
        if (asid_map_get_type(asid_map) == asid_map_asid_map_vspace &&
                (vspace_root_t*)asid_map_asid_map_vspace_get_vspace_root(asid_map) == vspace) {
            poolPtr->array[asid & ((1ul << (asidLowBits))-1ul)] = asid_map_asid_map_none_new();
            setVMRoot(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
        }
    }
}

word_t* __attribute__((__pure__)) lookupIPCBuffer(bool_t isReceiver, tcb_t *thread)
{
    word_t w_bufferPtr;
    cap_t bufferCap;
    vm_rights_t vm_rights;

    w_bufferPtr = thread->tcbIPCBuffer;
    bufferCap = (((cte_t *)((word_t)(thread)&~((1ul << (11))-1ul)))+(tcbBuffer))->cap;

    if (cap_get_capType(bufferCap) != cap_frame_cap) {
        return ((void *)0);
    }
    if (__builtin_expect(!!(cap_frame_cap_get_capFIsDevice(bufferCap)), 0)) {
        return ((void *)0);
    }

    vm_rights = cap_frame_cap_get_capFVMRights(bufferCap);
    if (vm_rights == VMReadWrite || (!isReceiver && vm_rights == VMReadOnly)) {
        word_t basePtr, pageBits;

        basePtr = cap_frame_cap_get_capFBasePtr(bufferCap);
        pageBits = pageBitsForSize(cap_frame_cap_get_capFSize(bufferCap));
        return (word_t *)(basePtr + (w_bufferPtr & ((1ul << (pageBits))-1ul)));
    } else {
        return ((void *)0);
    }
}

bool_t __attribute__((__const__)) isValidVTableRoot(cap_t cap)
{
    return isValidNativeRoot(cap);
}


__attribute__((__section__(".boot.text"))) bool_t map_kernel_window_devices(pte_t *pt, uint32_t num_ioapic, paddr_t* ioapic_paddrs, uint32_t num_drhu, paddr_t* drhu_list)
{
    word_t idx = (0xffffffffc0000000ul & ((1ul << (21))-1ul)) >> 12;
    paddr_t phys;
    pte_t pte;
    unsigned int i;

    phys = apic_get_base_paddr();
    if (!phys) {
        return false;
    }
    if (!add_allocated_p_region((p_region_t) {
    phys, phys + 0x1000
})) {
        return false;
    }
    pte = x86_make_device_pte(phys);

    if(!(idx == (0xffffffffc0000000ul & ((1ul << (21))-1ul)) >> 12)) _assert_fail("idx == (PPTR_APIC & MASK(LARGE_PAGE_BITS)) >> PAGE_BITS", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 150, __FUNCTION__);
    pt[idx] = pte;
    idx++;
    for (i = 0; i < num_ioapic; i++) {
        phys = ioapic_paddrs[i];
        if (!add_allocated_p_region((p_region_t) {
        phys, phys + 0x1000
    })) {
            return false;
        }
        pte = x86_make_device_pte(phys);
        if(!(idx == ( ((0xffffffffc0000000ul + (1ul << (12))) + i * (1ul << (12))) & ((1ul << (21))-1ul)) >> 12)) _assert_fail("idx == ( (PPTR_IOAPIC_START + i * BIT(PAGE_BITS)) & MASK(LARGE_PAGE_BITS)) >> PAGE_BITS", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 161, __FUNCTION__);
        pt[idx] = pte;
        idx++;
        if (idx == (1ul << (9))) {
            return false;
        }
    }

    for (; i < 1; i++) {
        pte = x86_make_empty_pte();
        if(!(idx == ( ((0xffffffffc0000000ul + (1ul << (12))) + i * (1ul << (12))) & ((1ul << (21))-1ul)) >> 12)) _assert_fail("idx == ( (PPTR_IOAPIC_START + i * BIT(PAGE_BITS)) & MASK(LARGE_PAGE_BITS)) >> PAGE_BITS", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 171, __FUNCTION__);
        pt[idx] = pte;
        idx++;
    }


    for (i = 0; i < num_drhu; i++) {
        phys = (paddr_t)drhu_list[i];
        if (!add_allocated_p_region((p_region_t) {
        phys, phys + 0x1000
    })) {
            return false;
        }
        pte = x86_make_device_pte(phys);

        if(!(idx == ((((0xffffffffc0000000ul + (1ul << (12))) + (1ul << (12)) * 1) + i * (1ul << (12))) & ((1ul << (21))-1ul)) >> 12)) _assert_fail("idx == ((PPTR_DRHU_START + i * BIT(PAGE_BITS)) & MASK(LARGE_PAGE_BITS)) >> PAGE_BITS", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 186, __FUNCTION__);
        pt[idx] = pte;
        idx++;
        if (idx == (1ul << (9))) {
            return false;
        }
    }


    while (idx < (1ul << (9))) {
        pte = x86_make_empty_pte();
        pt[idx] = pte;
        idx++;
    }


    if(!(idx == (1ul << (9)))) _assert_fail("idx == BIT(PT_INDEX_BITS)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 202, __FUNCTION__);
    return true;
}

__attribute__((__section__(".boot.text"))) static void
init_idt(idt_entry_t* idt)
{
    init_idt_entry(idt, 0x00, int_00);
    init_idt_entry(idt, 0x01, int_01);
    init_idt_entry(idt, 0x02, int_02);
    init_idt_entry(idt, 0x03, int_03);
    init_idt_entry(idt, 0x04, int_04);
    init_idt_entry(idt, 0x05, int_05);
    init_idt_entry(idt, 0x06, int_06);
    init_idt_entry(idt, 0x07, int_07);
    init_idt_entry(idt, 0x08, int_08);
    init_idt_entry(idt, 0x09, int_09);
    init_idt_entry(idt, 0x0a, int_0a);
    init_idt_entry(idt, 0x0b, int_0b);
    init_idt_entry(idt, 0x0c, int_0c);
    init_idt_entry(idt, 0x0d, int_0d);
    init_idt_entry(idt, 0x0e, int_0e);
    init_idt_entry(idt, 0x0f, int_0f);

    init_idt_entry(idt, 0x10, int_10);
    init_idt_entry(idt, 0x11, int_11);
    init_idt_entry(idt, 0x12, int_12);
    init_idt_entry(idt, 0x13, int_13);
    init_idt_entry(idt, 0x14, int_14);
    init_idt_entry(idt, 0x15, int_15);
    init_idt_entry(idt, 0x16, int_16);
    init_idt_entry(idt, 0x17, int_17);
    init_idt_entry(idt, 0x18, int_18);
    init_idt_entry(idt, 0x19, int_19);
    init_idt_entry(idt, 0x1a, int_1a);
    init_idt_entry(idt, 0x1b, int_1b);
    init_idt_entry(idt, 0x1c, int_1c);
    init_idt_entry(idt, 0x1d, int_1d);
    init_idt_entry(idt, 0x1e, int_1e);
    init_idt_entry(idt, 0x1f, int_1f);

    init_idt_entry(idt, 0x20, int_20);
    init_idt_entry(idt, 0x21, int_21);
    init_idt_entry(idt, 0x22, int_22);
    init_idt_entry(idt, 0x23, int_23);
    init_idt_entry(idt, 0x24, int_24);
    init_idt_entry(idt, 0x25, int_25);
    init_idt_entry(idt, 0x26, int_26);
    init_idt_entry(idt, 0x27, int_27);
    init_idt_entry(idt, 0x28, int_28);
    init_idt_entry(idt, 0x29, int_29);
    init_idt_entry(idt, 0x2a, int_2a);
    init_idt_entry(idt, 0x2b, int_2b);
    init_idt_entry(idt, 0x2c, int_2c);
    init_idt_entry(idt, 0x2d, int_2d);
    init_idt_entry(idt, 0x2e, int_2e);
    init_idt_entry(idt, 0x2f, int_2f);

    init_idt_entry(idt, 0x30, int_30);
    init_idt_entry(idt, 0x31, int_31);
    init_idt_entry(idt, 0x32, int_32);
    init_idt_entry(idt, 0x33, int_33);
    init_idt_entry(idt, 0x34, int_34);
    init_idt_entry(idt, 0x35, int_35);
    init_idt_entry(idt, 0x36, int_36);
    init_idt_entry(idt, 0x37, int_37);
    init_idt_entry(idt, 0x38, int_38);
    init_idt_entry(idt, 0x39, int_39);
    init_idt_entry(idt, 0x3a, int_3a);
    init_idt_entry(idt, 0x3b, int_3b);
    init_idt_entry(idt, 0x3c, int_3c);
    init_idt_entry(idt, 0x3d, int_3d);
    init_idt_entry(idt, 0x3e, int_3e);
    init_idt_entry(idt, 0x3f, int_3f);

    init_idt_entry(idt, 0x40, int_40);
    init_idt_entry(idt, 0x41, int_41);
    init_idt_entry(idt, 0x42, int_42);
    init_idt_entry(idt, 0x43, int_43);
    init_idt_entry(idt, 0x44, int_44);
    init_idt_entry(idt, 0x45, int_45);
    init_idt_entry(idt, 0x46, int_46);
    init_idt_entry(idt, 0x47, int_47);
    init_idt_entry(idt, 0x48, int_48);
    init_idt_entry(idt, 0x49, int_49);
    init_idt_entry(idt, 0x4a, int_4a);
    init_idt_entry(idt, 0x4b, int_4b);
    init_idt_entry(idt, 0x4c, int_4c);
    init_idt_entry(idt, 0x4d, int_4d);
    init_idt_entry(idt, 0x4e, int_4e);
    init_idt_entry(idt, 0x4f, int_4f);

    init_idt_entry(idt, 0x50, int_50);
    init_idt_entry(idt, 0x51, int_51);
    init_idt_entry(idt, 0x52, int_52);
    init_idt_entry(idt, 0x53, int_53);
    init_idt_entry(idt, 0x54, int_54);
    init_idt_entry(idt, 0x55, int_55);
    init_idt_entry(idt, 0x56, int_56);
    init_idt_entry(idt, 0x57, int_57);
    init_idt_entry(idt, 0x58, int_58);
    init_idt_entry(idt, 0x59, int_59);
    init_idt_entry(idt, 0x5a, int_5a);
    init_idt_entry(idt, 0x5b, int_5b);
    init_idt_entry(idt, 0x5c, int_5c);
    init_idt_entry(idt, 0x5d, int_5d);
    init_idt_entry(idt, 0x5e, int_5e);
    init_idt_entry(idt, 0x5f, int_5f);

    init_idt_entry(idt, 0x60, int_60);
    init_idt_entry(idt, 0x61, int_61);
    init_idt_entry(idt, 0x62, int_62);
    init_idt_entry(idt, 0x63, int_63);
    init_idt_entry(idt, 0x64, int_64);
    init_idt_entry(idt, 0x65, int_65);
    init_idt_entry(idt, 0x66, int_66);
    init_idt_entry(idt, 0x67, int_67);
    init_idt_entry(idt, 0x68, int_68);
    init_idt_entry(idt, 0x69, int_69);
    init_idt_entry(idt, 0x6a, int_6a);
    init_idt_entry(idt, 0x6b, int_6b);
    init_idt_entry(idt, 0x6c, int_6c);
    init_idt_entry(idt, 0x6d, int_6d);
    init_idt_entry(idt, 0x6e, int_6e);
    init_idt_entry(idt, 0x6f, int_6f);

    init_idt_entry(idt, 0x70, int_70);
    init_idt_entry(idt, 0x71, int_71);
    init_idt_entry(idt, 0x72, int_72);
    init_idt_entry(idt, 0x73, int_73);
    init_idt_entry(idt, 0x74, int_74);
    init_idt_entry(idt, 0x75, int_75);
    init_idt_entry(idt, 0x76, int_76);
    init_idt_entry(idt, 0x77, int_77);
    init_idt_entry(idt, 0x78, int_78);
    init_idt_entry(idt, 0x79, int_79);
    init_idt_entry(idt, 0x7a, int_7a);
    init_idt_entry(idt, 0x7b, int_7b);
    init_idt_entry(idt, 0x7c, int_7c);
    init_idt_entry(idt, 0x7d, int_7d);
    init_idt_entry(idt, 0x7e, int_7e);
    init_idt_entry(idt, 0x7f, int_7f);

    init_idt_entry(idt, 0x80, int_80);
    init_idt_entry(idt, 0x81, int_81);
    init_idt_entry(idt, 0x82, int_82);
    init_idt_entry(idt, 0x83, int_83);
    init_idt_entry(idt, 0x84, int_84);
    init_idt_entry(idt, 0x85, int_85);
    init_idt_entry(idt, 0x86, int_86);
    init_idt_entry(idt, 0x87, int_87);
    init_idt_entry(idt, 0x88, int_88);
    init_idt_entry(idt, 0x89, int_89);
    init_idt_entry(idt, 0x8a, int_8a);
    init_idt_entry(idt, 0x8b, int_8b);
    init_idt_entry(idt, 0x8c, int_8c);
    init_idt_entry(idt, 0x8d, int_8d);
    init_idt_entry(idt, 0x8e, int_8e);
    init_idt_entry(idt, 0x8f, int_8f);

    init_idt_entry(idt, 0x90, int_90);
    init_idt_entry(idt, 0x91, int_91);
    init_idt_entry(idt, 0x92, int_92);
    init_idt_entry(idt, 0x93, int_93);
    init_idt_entry(idt, 0x94, int_94);
    init_idt_entry(idt, 0x95, int_95);
    init_idt_entry(idt, 0x96, int_96);
    init_idt_entry(idt, 0x97, int_97);
    init_idt_entry(idt, 0x98, int_98);
    init_idt_entry(idt, 0x99, int_99);
    init_idt_entry(idt, 0x9a, int_9a);
    init_idt_entry(idt, 0x9b, int_9b);
    init_idt_entry(idt, 0x9c, int_9c);
    init_idt_entry(idt, 0x9d, int_9d);
    init_idt_entry(idt, 0x9e, int_9e);
    init_idt_entry(idt, 0x9f, int_9f);

    init_idt_entry(idt, 0xa0, int_a0);
    init_idt_entry(idt, 0xa1, int_a1);
    init_idt_entry(idt, 0xa2, int_a2);
    init_idt_entry(idt, 0xa3, int_a3);
    init_idt_entry(idt, 0xa4, int_a4);
    init_idt_entry(idt, 0xa5, int_a5);
    init_idt_entry(idt, 0xa6, int_a6);
    init_idt_entry(idt, 0xa7, int_a7);
    init_idt_entry(idt, 0xa8, int_a8);
    init_idt_entry(idt, 0xa9, int_a9);
    init_idt_entry(idt, 0xaa, int_aa);
    init_idt_entry(idt, 0xab, int_ab);
    init_idt_entry(idt, 0xac, int_ac);
    init_idt_entry(idt, 0xad, int_ad);
    init_idt_entry(idt, 0xae, int_ae);
    init_idt_entry(idt, 0xaf, int_af);

    init_idt_entry(idt, 0xb0, int_b0);
    init_idt_entry(idt, 0xb1, int_b1);
    init_idt_entry(idt, 0xb2, int_b2);
    init_idt_entry(idt, 0xb3, int_b3);
    init_idt_entry(idt, 0xb4, int_b4);
    init_idt_entry(idt, 0xb5, int_b5);
    init_idt_entry(idt, 0xb6, int_b6);
    init_idt_entry(idt, 0xb7, int_b7);
    init_idt_entry(idt, 0xb8, int_b8);
    init_idt_entry(idt, 0xb9, int_b9);
    init_idt_entry(idt, 0xba, int_ba);
    init_idt_entry(idt, 0xbb, int_bb);
    init_idt_entry(idt, 0xbc, int_bc);
    init_idt_entry(idt, 0xbd, int_bd);
    init_idt_entry(idt, 0xbe, int_be);
    init_idt_entry(idt, 0xbf, int_bf);

    init_idt_entry(idt, 0xc0, int_c0);
    init_idt_entry(idt, 0xc1, int_c1);
    init_idt_entry(idt, 0xc2, int_c2);
    init_idt_entry(idt, 0xc3, int_c3);
    init_idt_entry(idt, 0xc4, int_c4);
    init_idt_entry(idt, 0xc5, int_c5);
    init_idt_entry(idt, 0xc6, int_c6);
    init_idt_entry(idt, 0xc7, int_c7);
    init_idt_entry(idt, 0xc8, int_c8);
    init_idt_entry(idt, 0xc9, int_c9);
    init_idt_entry(idt, 0xca, int_ca);
    init_idt_entry(idt, 0xcb, int_cb);
    init_idt_entry(idt, 0xcc, int_cc);
    init_idt_entry(idt, 0xcd, int_cd);
    init_idt_entry(idt, 0xce, int_ce);
    init_idt_entry(idt, 0xcf, int_cf);

    init_idt_entry(idt, 0xd0, int_d0);
    init_idt_entry(idt, 0xd1, int_d1);
    init_idt_entry(idt, 0xd2, int_d2);
    init_idt_entry(idt, 0xd3, int_d3);
    init_idt_entry(idt, 0xd4, int_d4);
    init_idt_entry(idt, 0xd5, int_d5);
    init_idt_entry(idt, 0xd6, int_d6);
    init_idt_entry(idt, 0xd7, int_d7);
    init_idt_entry(idt, 0xd8, int_d8);
    init_idt_entry(idt, 0xd9, int_d9);
    init_idt_entry(idt, 0xda, int_da);
    init_idt_entry(idt, 0xdb, int_db);
    init_idt_entry(idt, 0xdc, int_dc);
    init_idt_entry(idt, 0xdd, int_dd);
    init_idt_entry(idt, 0xde, int_de);
    init_idt_entry(idt, 0xdf, int_df);

    init_idt_entry(idt, 0xe0, int_e0);
    init_idt_entry(idt, 0xe1, int_e1);
    init_idt_entry(idt, 0xe2, int_e2);
    init_idt_entry(idt, 0xe3, int_e3);
    init_idt_entry(idt, 0xe4, int_e4);
    init_idt_entry(idt, 0xe5, int_e5);
    init_idt_entry(idt, 0xe6, int_e6);
    init_idt_entry(idt, 0xe7, int_e7);
    init_idt_entry(idt, 0xe8, int_e8);
    init_idt_entry(idt, 0xe9, int_e9);
    init_idt_entry(idt, 0xea, int_ea);
    init_idt_entry(idt, 0xeb, int_eb);
    init_idt_entry(idt, 0xec, int_ec);
    init_idt_entry(idt, 0xed, int_ed);
    init_idt_entry(idt, 0xee, int_ee);
    init_idt_entry(idt, 0xef, int_ef);

    init_idt_entry(idt, 0xf0, int_f0);
    init_idt_entry(idt, 0xf1, int_f1);
    init_idt_entry(idt, 0xf2, int_f2);
    init_idt_entry(idt, 0xf3, int_f3);
    init_idt_entry(idt, 0xf4, int_f4);
    init_idt_entry(idt, 0xf5, int_f5);
    init_idt_entry(idt, 0xf6, int_f6);
    init_idt_entry(idt, 0xf7, int_f7);
    init_idt_entry(idt, 0xf8, int_f8);
    init_idt_entry(idt, 0xf9, int_f9);
    init_idt_entry(idt, 0xfa, int_fa);
    init_idt_entry(idt, 0xfb, int_fb);
    init_idt_entry(idt, 0xfc, int_fc);
    init_idt_entry(idt, 0xfd, int_fd);
    init_idt_entry(idt, 0xfe, int_fe);
    init_idt_entry(idt, 0xff, int_ff);
}

__attribute__((__section__(".boot.text"))) bool_t
init_vm_state(void)
{
    word_t cacheLineSize;
    x86KScacheLineSizeBits = getCacheLineSizeBits();
    if (!x86KScacheLineSizeBits) {
        return false;
    }

    cacheLineSize = (1ul << (x86KScacheLineSizeBits));
    if (cacheLineSize != 64) {
        kprintf("Configured cache line size is %d but detected size is %lu\n", 64, cacheLineSize)
                                                 ;
        return false;
    }

    init_tss(&x86KSGlobalState[getCurrentCPUIndex()].x86KStss.tss);
    init_gdt(x86KSGlobalState[getCurrentCPUIndex()].x86KSgdt, &x86KSGlobalState[getCurrentCPUIndex()].x86KStss.tss);
    init_idt(x86KSGlobalState[getCurrentCPUIndex()].x86KSidt);
    return true;
}

__attribute__((__section__(".boot.text"))) bool_t
init_pat_msr(void)
{
    x86_pat_msr_t pat_msr;


    if ( (x86_cpuid_edx(0x1, 0x0) & (1ul << (16))) == 0) {
        kprintf("PAT support not found\n");
        return false;
    }
    pat_msr.words[0] = x86_rdmsr_low(0x277);
    pat_msr.words[1] = x86_rdmsr_high(0x277);


    pat_msr = x86_pat_msr_set_pa0(pat_msr, 0x06);
    pat_msr = x86_pat_msr_set_pa1(pat_msr, 0x04);
    pat_msr = x86_pat_msr_set_pa2(pat_msr, 0x07);
    pat_msr = x86_pat_msr_set_pa3(pat_msr, 0x00);

    pat_msr = x86_pat_msr_set_pa4(pat_msr, 0x01);
    x86_wrmsr(0x277, ((uint64_t)pat_msr.words[1]) << 32 | pat_msr.words[0]);
    return true;
}

__attribute__((__section__(".boot.text"))) void
write_it_asid_pool(cap_t it_ap_cap, cap_t it_vspace_cap)
{
    asid_pool_t* ap = ((asid_pool_t*)(pptr_t)cap_get_capPtr(it_ap_cap));
    ap->array[1 ] = asid_map_asid_map_vspace_new((pptr_t)cap_get_capPtr(it_vspace_cap));
    x86KSASIDTable[1 >> asidLowBits] = ap;
}

asid_map_t
findMapForASID(asid_t asid)
{
    asid_pool_t* poolPtr;

    poolPtr = x86KSASIDTable[asid >> asidLowBits];
    if (!poolPtr) {
        return asid_map_asid_map_none_new();
    }

    return poolPtr->array[asid & ((1ul << (asidLowBits))-1ul)];
}

findVSpaceForASID_ret_t findVSpaceForASID(asid_t asid)
{
    findVSpaceForASID_ret_t ret;
    asid_map_t asid_map;

    asid_map = findMapForASID(asid);
    if (asid_map_get_type(asid_map) != asid_map_asid_map_vspace) {
        current_lookup_fault = lookup_fault_invalid_root_new();

        ret.vspace_root = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }

    ret.vspace_root = (vspace_root_t*)asid_map_asid_map_vspace_get_vspace_root(asid_map);
    ret.status = EXCEPTION_NONE;
    return ret;
}

exception_t handleVMFault(tcb_t* thread, vm_fault_type_t vm_faultType)
{
    word_t addr;
    uint32_t fault;

    addr = getFaultAddr();
    fault = getRegister(thread, Error);

    switch (vm_faultType) {
    case X86DataFault:
        current_fault = seL4_Fault_VMFault_new(addr, fault, false);
        return EXCEPTION_FAULT;

    case X86InstructionFault:
        current_fault = seL4_Fault_VMFault_new(addr, fault, true);
        return EXCEPTION_FAULT;

    default:
        _fail("Invalid VM fault type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 586, __func__);
    }
}

uint32_t __attribute__((__const__)) WritableFromVMRights(vm_rights_t vm_rights)
{
    switch (vm_rights) {
    case VMReadOnly:
        return 0;

    case VMKernelOnly:
    case VMReadWrite:
        return 1;

    default:
        _fail("Invalid VM rights", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 601, __func__);
    }
}

uint32_t __attribute__((__const__)) SuperUserFromVMRights(vm_rights_t vm_rights)
{
    switch (vm_rights) {
    case VMKernelOnly:
        return 0;

    case VMReadOnly:
    case VMReadWrite:
        return 1;

    default:
        _fail("Invalid VM rights", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 616, __func__);
    }
}

lookupPTSlot_ret_t lookupPTSlot(vspace_root_t *vspace, vptr_t vptr)
{
    lookupPTSlot_ret_t ret;
    lookupPDSlot_ret_t pdSlot;

    pdSlot = lookupPDSlot(vspace, vptr);
    if (pdSlot.status != EXCEPTION_NONE) {
        ret.ptSlot = ((void *)0);
        ret.status = pdSlot.status;
        return ret;
    }
    if ((pde_ptr_get_page_size(pdSlot.pdSlot) != pde_pde_pt) ||
            !pde_pde_pt_ptr_get_present(pdSlot.pdSlot)) {
        current_lookup_fault = lookup_fault_missing_capability_new(12 + 9);
        ret.ptSlot = ((void *)0);
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    } else {
        pte_t* pt;
        pte_t* ptSlot;
        word_t ptIndex;

        pt = ptrFromPAddr(pde_pde_pt_ptr_get_pt_base_address(pdSlot.pdSlot));
        ptIndex = (vptr >> 12) & ((1ul << (9))-1ul);
        ptSlot = pt + ptIndex;

        ret.ptSlot = ptSlot;
        ret.status = EXCEPTION_NONE;
        return ret;
    }
}

exception_t checkValidIPCBuffer(vptr_t vptr, cap_t cap)
{
    if (cap_get_capType(cap) != cap_frame_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 655, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IPC Buffer is an invalid cap."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (__builtin_expect(!!(cap_frame_cap_get_capFIsDevice(cap)), 0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 660, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Specifying a device frame as an IPC buffer is not permitted."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (!(!((vptr) & ((1ul << (10))-1ul)))) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 666, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IPC Buffer vaddr 0x%x is not aligned.", (int)vptr); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_AlignmentError;
        return EXCEPTION_SYSCALL_ERROR;
    }

    return EXCEPTION_NONE;
}

vm_rights_t __attribute__((__const__)) maskVMRights(vm_rights_t vm_rights, seL4_CapRights_t cap_rights_mask)
{
    if (vm_rights == VMReadOnly && seL4_CapRights_get_capAllowRead(cap_rights_mask)) {
        return VMReadOnly;
    }
    if (vm_rights == VMReadWrite && seL4_CapRights_get_capAllowRead(cap_rights_mask)) {
        if (!seL4_CapRights_get_capAllowWrite(cap_rights_mask)) {
            return VMReadOnly;
        } else {
            return VMReadWrite;
        }
    }
    return VMKernelOnly;
}

void flushTable(vspace_root_t *vspace, word_t vptr, pte_t* pt, asid_t asid)
{
    word_t i;
    cap_t threadRoot;

    if(!((!((vptr) & ((1ul << (9 + 12))-1ul))))) _assert_fail("IS_ALIGNED(vptr, PT_INDEX_BITS + PAGE_BITS)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 694, __FUNCTION__);


    threadRoot = (((cte_t *)((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)&~((1ul << (11))-1ul)))+(tcbVTable))->cap;

    for (i = 0; i < (1ul << (9)); i++) {
        if (pte_get_present(pt[i])) {
            if (0 || (isValidNativeRoot(threadRoot) && (vspace_root_t*)(pptr_t)cap_get_capPtr(threadRoot) == vspace)) {
                invalidateTranslationSingleASID(vptr + (i << 12), asid,
                                                tlb_bitmap_get(vspace));
            }
        }
    }
}


void unmapPage(vm_page_size_t page_size, asid_t asid, vptr_t vptr, void *pptr)
{
    findVSpaceForASID_ret_t find_ret;
    lookupPTSlot_ret_t lu_ret;
    lookupPDSlot_ret_t pd_ret;
    pde_t *pde;

    find_ret = findVSpaceForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        return;
    }

    switch (page_size) {
    case X86_SmallPage:
        lu_ret = lookupPTSlot(find_ret.vspace_root, vptr);
        if (lu_ret.status != EXCEPTION_NONE) {
            return;
        }
        if (! (pte_ptr_get_present(lu_ret.ptSlot)
                && (pte_ptr_get_page_base_address(lu_ret.ptSlot)
                    == addrFromPPtr(pptr)))) {
            return;
        }
        *lu_ret.ptSlot = makeUserPTEInvalid();
        break;

    case X86_LargePage:
        pd_ret = lookupPDSlot(find_ret.vspace_root, vptr);
        if (pd_ret.status != EXCEPTION_NONE) {
            return;
        }
        pde = pd_ret.pdSlot;
        if (! (pde_ptr_get_page_size(pde) == pde_pde_large
                && pde_pde_large_ptr_get_present(pde)
                && (pde_pde_large_ptr_get_page_base_address(pde)
                    == addrFromPPtr(pptr)))) {
            return;
        }
        *pde = makeUserPDEInvalid();
        break;

    default:
        if (!modeUnmapPage(page_size, find_ret.vspace_root, vptr, pptr)) {
            return;
        }
        break;
    }

    invalidateTranslationSingleASID(vptr, asid,
                                    tlb_bitmap_get(find_ret.vspace_root));
}

void unmapPageTable(asid_t asid, vptr_t vaddr, pte_t* pt)
{
    findVSpaceForASID_ret_t find_ret;
    lookupPDSlot_ret_t lu_ret;

    find_ret = findVSpaceForASID(asid);
    if (find_ret.status != EXCEPTION_NONE) {
        return;
    }

    lu_ret = lookupPDSlot(find_ret.vspace_root, vaddr);
    if (lu_ret.status != EXCEPTION_NONE) {
        return;
    }


    if (! (pde_ptr_get_page_size(lu_ret.pdSlot) == pde_pde_pt &&
            pde_pde_pt_ptr_get_present(lu_ret.pdSlot) &&
            (pde_pde_pt_ptr_get_pt_base_address(lu_ret.pdSlot) == addrFromPPtr(pt)))) {
        return;
    }

    flushTable(find_ret.vspace_root, vaddr, pt, asid);

    *lu_ret.pdSlot = makeUserPDEInvalid();

    invalidatePageStructureCacheASID(addrFromPPtr(find_ret.vspace_root), asid,
                                     tlb_bitmap_get(find_ret.vspace_root));
}

static exception_t
performX86PageInvocationMapPTE(cap_t cap, cte_t *ctSlot, pte_t *ptSlot, pte_t pte, vspace_root_t *vspace)
{
    ctSlot->cap = cap;
    *ptSlot = pte;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), cap_frame_cap_get_capFMappedASID(cap),
                                     tlb_bitmap_get(vspace));
    return EXCEPTION_NONE;
}

static exception_t
performX86PageInvocationMapPDE(cap_t cap, cte_t *ctSlot, pde_t *pdSlot, pde_t pde, vspace_root_t *vspace)
{
    ctSlot->cap = cap;
    *pdSlot = pde;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), cap_frame_cap_get_capFMappedASID(cap),
                                     tlb_bitmap_get(vspace));
    return EXCEPTION_NONE;
}

static exception_t
performX86PageInvocationRemapPTE(pte_t *ptSlot, pte_t pte, asid_t asid, vspace_root_t *vspace)
{
    *ptSlot = pte;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), asid,
                                     tlb_bitmap_get(vspace));
    return EXCEPTION_NONE;
}

static exception_t
performX86PageInvocationRemapPDE(pde_t *pdSlot, pde_t pde, asid_t asid, vspace_root_t *vspace)
{
    *pdSlot = pde;
    invalidatePageStructureCacheASID(addrFromPPtr(vspace), asid,
                                     tlb_bitmap_get(vspace));
    return EXCEPTION_NONE;
}

static exception_t
performX86PageInvocationUnmap(cap_t cap, cte_t *ctSlot)
{
    if(!(cap_frame_cap_get_capFMappedASID(cap))) _assert_fail("cap_frame_cap_get_capFMappedASID(cap)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 833, __FUNCTION__);
    if(!(cap_frame_cap_get_capFMapType(cap) == X86_MappingVSpace)) _assert_fail("cap_frame_cap_get_capFMapType(cap) == X86_MappingVSpace", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 834, __FUNCTION__);



    if (cap_frame_cap_get_capFMappedASID(cap)) {
        unmapPage(
            cap_frame_cap_get_capFSize(cap),
            cap_frame_cap_get_capFMappedASID(cap),
            cap_frame_cap_get_capFMappedAddress(cap),
            (void *)cap_frame_cap_get_capFBasePtr(cap)
        );
    }

    cap_frame_cap_ptr_set_capFMappedAddress(&ctSlot->cap, 0);
    cap_frame_cap_ptr_set_capFMappedASID(&ctSlot->cap, asidInvalid);
    cap_frame_cap_ptr_set_capFMapType(&ctSlot->cap, X86_MappingNone);

    return EXCEPTION_NONE;
}

exception_t decodeX86FrameInvocation(
    word_t invLabel,
    word_t length,
    cte_t* cte,
    cap_t cap,
    extra_caps_t excaps,
    word_t* buffer
)
{
    switch (invLabel) {
    case X86PageMap: {
        word_t vaddr;
        word_t vtop;
        word_t w_rightsMask;
        paddr_t paddr;
        cap_t vspaceCap;
        vspace_root_t* vspace;
        vm_rights_t capVMRights;
        vm_rights_t vmRights;
        vm_attributes_t vmAttr;
        vm_page_size_t frameSize;
        asid_t asid;

        if (length < 3 || excaps.excaprefs[0] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;

            return EXCEPTION_SYSCALL_ERROR;
        }

        frameSize = cap_frame_cap_get_capFSize(cap);
        vaddr = getSyscallArg(0, buffer);
        w_rightsMask = getSyscallArg(1, buffer);
        vmAttr = vmAttributesFromWord(getSyscallArg(2, buffer));
        vspaceCap = excaps.excaprefs[0]->cap;

        capVMRights = cap_frame_cap_get_capFVMRights(cap);

        if (cap_frame_cap_get_capFMappedASID(cap) != asidInvalid) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 892, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86Frame: Frame already mapped."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;

            return EXCEPTION_SYSCALL_ERROR;
        }

        if(!(cap_frame_cap_get_capFMapType(cap) == X86_MappingNone)) _assert_fail("cap_frame_cap_get_capFMapType(cap) == X86_MappingNone", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 899, __FUNCTION__);

        if (!isValidNativeRoot(vspaceCap)) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 902, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86Frame: Attempting to map frame into invalid page directory cap."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 1;

            return EXCEPTION_SYSCALL_ERROR;
        }
        vspace = (vspace_root_t*)(pptr_t)cap_get_capPtr(vspaceCap);
        asid = cap_get_capMappedASID(vspaceCap);

        {
            findVSpaceForASID_ret_t find_ret;

            find_ret = findVSpaceForASID(asid);
            if (find_ret.status != EXCEPTION_NONE) {
                current_syscall_error.type = seL4_FailedLookup;
                current_syscall_error.failedLookupWasSource = false;

                return EXCEPTION_SYSCALL_ERROR;
            }

            if (find_ret.vspace_root != vspace) {
                current_syscall_error.type = seL4_InvalidCapability;
                current_syscall_error.invalidCapNumber = 1;

                return EXCEPTION_SYSCALL_ERROR;
            }
        }

        vtop = vaddr + (1ul << (pageBitsForSize(frameSize)));

        if (vtop > 0x7FFFFFFFFFFF) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 933, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86Frame: Mapping address too high."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_InvalidArgument;
            current_syscall_error.invalidArgumentNumber = 0;

            return EXCEPTION_SYSCALL_ERROR;
        }

        vmRights = maskVMRights(capVMRights, rightsFromWord(w_rightsMask));

        if (!checkVPAlignment(frameSize, vaddr)) {
            current_syscall_error.type = seL4_AlignmentError;

            return EXCEPTION_SYSCALL_ERROR;
        }

        paddr = addrFromPPtr((void*)cap_frame_cap_get_capFBasePtr(cap));

        cap = cap_frame_cap_set_capFMappedASID(cap, asid);
        cap = cap_frame_cap_set_capFMappedAddress(cap, vaddr);
        cap = cap_frame_cap_set_capFMapType(cap, X86_MappingVSpace);

        switch (frameSize) {

        case X86_SmallPage: {
            pte_t pte;
            lookupPTSlot_ret_t lu_ret;

            lu_ret = lookupPTSlot(vspace, vaddr);
            if (lu_ret.status != EXCEPTION_NONE) {
                current_syscall_error.type = seL4_FailedLookup;
                current_syscall_error.failedLookupWasSource = false;

                return EXCEPTION_SYSCALL_ERROR;
            }

            if (pte_ptr_get_present(lu_ret.ptSlot)) {
                current_syscall_error.type = seL4_DeleteFirst;
                return EXCEPTION_SYSCALL_ERROR;
            }

            pte = makeUserPTE(paddr, vmAttr, vmRights);
            setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
            return performX86PageInvocationMapPTE(cap, cte, lu_ret.ptSlot, pte, vspace);
        }


        case X86_LargePage: {
            pde_t* pdeSlot;
            pde_t pde;
            lookupPDSlot_ret_t lu_ret;

            lu_ret = lookupPDSlot(vspace, vaddr);
            if (lu_ret.status != EXCEPTION_NONE) {
                current_syscall_error.type = seL4_FailedLookup;
                current_syscall_error.failedLookupWasSource = false;

                return EXCEPTION_SYSCALL_ERROR;
            }
            pdeSlot = lu_ret.pdSlot;


            if ((pde_ptr_get_page_size(pdeSlot) == pde_pde_pt) &&
                    (pde_pde_pt_ptr_get_present(pdeSlot))) {
                current_syscall_error.type = seL4_DeleteFirst;

                return EXCEPTION_SYSCALL_ERROR;
            }


            if ((pde_ptr_get_page_size(pdeSlot) == pde_pde_large) &&
                    (pde_pde_large_ptr_get_present(pdeSlot))) {
                current_syscall_error.type = seL4_DeleteFirst;

                return EXCEPTION_SYSCALL_ERROR;
            }

            pde = makeUserPDELargePage(paddr, vmAttr, vmRights);
            setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
            return performX86PageInvocationMapPDE(cap, cte, lu_ret.pdSlot, pde, vspace);
        }

        default: {
            return decodeX86ModeMapRemapPage(invLabel, frameSize, cte, cap, vspace, vaddr, paddr, vmRights, vmAttr);
        }
        }

        return EXCEPTION_SYSCALL_ERROR;
    }

    case X86PageRemap: {
        word_t vaddr;
        word_t w_rightsMask;
        paddr_t paddr;
        cap_t vspaceCap;
        vspace_root_t* vspace;
        vm_rights_t capVMRights;
        vm_rights_t vmRights;
        vm_attributes_t vmAttr;
        vm_page_size_t frameSize;
        asid_t asid;

        if (cap_frame_cap_get_capFMapType(cap) != X86_MappingVSpace) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1035, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86FrameRemap: Attempting to remap frame with different mapping type"); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;

            return EXCEPTION_SYSCALL_ERROR;
        }

        if (length < 2 || excaps.excaprefs[0] == ((void *)0)) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1042, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86FrameRemap: Truncated message"); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_TruncatedMessage;

            return EXCEPTION_SYSCALL_ERROR;
        }

        w_rightsMask = getSyscallArg(0, buffer);
        vmAttr = vmAttributesFromWord(getSyscallArg(1, buffer));
        vspaceCap = excaps.excaprefs[0]->cap;

        if (!isValidNativeRoot(vspaceCap)) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1053, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86FrameRemap: Attempting to map frame into invalid page directory."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 1;

            return EXCEPTION_SYSCALL_ERROR;
        }
        vspace = (vspace_root_t*)(pptr_t)cap_get_capPtr(vspaceCap);
        asid = cap_get_capMappedASID(vspaceCap);

        if (cap_frame_cap_get_capFMappedASID(cap) != asid) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1063, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86PageRemap: Frame must already have been mapped into provided vspace."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;

            return EXCEPTION_SYSCALL_ERROR;
        }

        {
            findVSpaceForASID_ret_t find_ret;

            find_ret = findVSpaceForASID(asid);
            if (find_ret.status != EXCEPTION_NONE) {
                current_syscall_error.type = seL4_FailedLookup;
                current_syscall_error.failedLookupWasSource = false;

                return EXCEPTION_SYSCALL_ERROR;
            }

            if (find_ret.vspace_root != vspace) {
                current_syscall_error.type = seL4_InvalidCapability;
                current_syscall_error.invalidCapNumber = 1;

                return EXCEPTION_SYSCALL_ERROR;
            }
        }

        vaddr = cap_frame_cap_get_capFMappedAddress(cap);
        frameSize = cap_frame_cap_get_capFSize(cap);
        capVMRights = cap_frame_cap_get_capFVMRights(cap);
        paddr = addrFromPPtr((void*)cap_frame_cap_get_capFBasePtr(cap));

        vmRights = maskVMRights(capVMRights, rightsFromWord(w_rightsMask));

        switch (frameSize) {

        case X86_SmallPage: {
            pte_t pte;
            lookupPTSlot_ret_t lu_ret;

            lu_ret = lookupPTSlot(vspace, vaddr);
            if (lu_ret.status != EXCEPTION_NONE) {
                current_syscall_error.type = seL4_FailedLookup;
                current_syscall_error.failedLookupWasSource = false;

                return EXCEPTION_SYSCALL_ERROR;
            }

            pte = makeUserPTE(paddr, vmAttr, vmRights);

            setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
            return performX86PageInvocationRemapPTE(lu_ret.ptSlot, pte, asid, vspace);

        }


        case X86_LargePage: {
            pde_t* pdeSlot;
            pde_t pde;
            lookupPDSlot_ret_t lu_ret;

            lu_ret = lookupPDSlot(vspace, vaddr);
            if (lu_ret.status != EXCEPTION_NONE) {
                current_syscall_error.type = seL4_FailedLookup;
                current_syscall_error.failedLookupWasSource = false;

                return EXCEPTION_SYSCALL_ERROR;
            }
            pdeSlot = lu_ret.pdSlot;

            if ((pde_ptr_get_page_size(pdeSlot) == pde_pde_pt) &&
                    (pde_pde_pt_ptr_get_present(pdeSlot))) {
                current_syscall_error.type = seL4_DeleteFirst;

                return EXCEPTION_SYSCALL_ERROR;
            }

            pde = makeUserPDELargePage(paddr, vmAttr, vmRights);

            setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
            return performX86PageInvocationRemapPDE(pdeSlot, pde, asid, vspace);
        }

        default: {
            return decodeX86ModeMapRemapPage(invLabel, frameSize, cte, cap, vspace, vaddr, paddr, vmRights, vmAttr);
        }
        }

        return EXCEPTION_SYSCALL_ERROR;
    }

    case X86PageUnmap: {
        if (cap_frame_cap_get_capFMappedASID(cap) != asidInvalid) {
            switch (cap_frame_cap_get_capFMapType(cap)) {
            case X86_MappingVSpace:
                setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
                return performX86PageInvocationUnmap(cap, cte);






            case X86_MappingEPT:
                setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
                return performX86EPTPageInvocationUnmap(cap, cte);

            case X86_MappingNone:
                _fail("Mapped frame cap was not mapped", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 1170, __func__);
                break;
            }
        }

        return EXCEPTION_NONE;
    }
    case X86PageMapEPT:
        return decodeX86EPTPageMap(invLabel, length, cte, cap, excaps, buffer);


    case X86PageGetAddress: {

        if(!(n_msgRegisters >= 1)) _assert_fail("n_msgRegisters >= 1", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/vspace.c", 1191, __FUNCTION__);

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performPageGetAddress((void*)cap_frame_cap_get_capFBasePtr(cap));
    }

    default:
        current_syscall_error.type = seL4_IllegalOperation;

        return EXCEPTION_SYSCALL_ERROR;
    }
}

static exception_t
performX86PageTableInvocationUnmap(cap_t cap, cte_t *ctSlot)
{

    if (cap_page_table_cap_get_capPTIsMapped(cap)) {
        pte_t *pt = ((pte_t *)(cap_page_table_cap_get_capPTBasePtr(cap)));
        unmapPageTable(
            cap_page_table_cap_get_capPTMappedASID(cap),
            cap_page_table_cap_get_capPTMappedAddress(cap),
            pt
        );
        clearMemory((void *)pt, cap_get_capSizeBits(cap));
    }
    cap_page_table_cap_ptr_set_capPTIsMapped(&(ctSlot->cap), 0);

    return EXCEPTION_NONE;
}

static exception_t
performX86PageTableInvocationMap(cap_t cap, cte_t *ctSlot, pde_t pde, pde_t *pdSlot, vspace_root_t *root)
{
    ctSlot->cap = cap;
    *pdSlot = pde;
    invalidatePageStructureCacheASID(addrFromPPtr(root), cap_page_table_cap_get_capPTMappedASID(cap),
                                     tlb_bitmap_get(root));
    return EXCEPTION_NONE;
}

static exception_t
decodeX86PageTableInvocation(
    word_t invLabel,
    word_t length,
    cte_t* cte, cap_t cap,
    extra_caps_t excaps,
    word_t* buffer
)
{
    word_t vaddr;
    vm_attributes_t attr;
    lookupPDSlot_ret_t pdSlot;
    cap_t vspaceCap;
    vspace_root_t* vspace;
    pde_t pde;
    paddr_t paddr;
    asid_t asid;

    if (invLabel == X86PageTableUnmap) {
        if (! isFinalCapability(cte)) {
            current_syscall_error.type = seL4_RevokeFirst;
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1253, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86PageTable: Cannot unmap if more than one cap exists."); kprintf(">>" "" "\n"); } while (0);
            return EXCEPTION_SYSCALL_ERROR;
        }
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performX86PageTableInvocationUnmap(cap, cte);
    }

    if (invLabel != X86PageTableMap ) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1261, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86PageTable: Illegal operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 2 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1267, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86PageTable: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cap_page_table_cap_get_capPTIsMapped(cap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1273, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86PageTable: Page table is already mapped to a page directory."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type =
            seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vaddr = getSyscallArg(0, buffer) & (~((1ul << (9 + 12))-1ul));
    attr = vmAttributesFromWord(getSyscallArg(1, buffer));
    vspaceCap = excaps.excaprefs[0]->cap;

    if (!isValidNativeRoot(vspaceCap)) {
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;

        return EXCEPTION_SYSCALL_ERROR;
    }

    vspace = (vspace_root_t*)(pptr_t)cap_get_capPtr(vspaceCap);
    asid = cap_get_capMappedASID(vspaceCap);

    if (vaddr >= 0x7FFFFFFFFFFF) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1296, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86PageTable: Mapping address too high."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 0;

        return EXCEPTION_SYSCALL_ERROR;
    }

    {
        findVSpaceForASID_ret_t find_ret;

        find_ret = findVSpaceForASID(asid);
        if (find_ret.status != EXCEPTION_NONE) {
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = false;

            return EXCEPTION_SYSCALL_ERROR;
        }

        if (find_ret.vspace_root != vspace) {
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 1;

            return EXCEPTION_SYSCALL_ERROR;
        }
    }

    pdSlot = lookupPDSlot(vspace, vaddr);
    if (pdSlot.status != EXCEPTION_NONE) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = false;

        return EXCEPTION_SYSCALL_ERROR;
    }

    if (((pde_ptr_get_page_size(pdSlot.pdSlot) == pde_pde_pt) && pde_pde_pt_ptr_get_present(pdSlot.pdSlot)) ||
            ((pde_ptr_get_page_size(pdSlot.pdSlot) == pde_pde_large) && pde_pde_large_ptr_get_present(pdSlot.pdSlot))) {
        current_syscall_error.type = seL4_DeleteFirst;

        return EXCEPTION_SYSCALL_ERROR;
    }

    paddr = addrFromPPtr(((pte_t *)(cap_page_table_cap_get_capPTBasePtr(cap))));
    pde = makeUserPDEPageTable(paddr, attr);

    cap = cap_page_table_cap_set_capPTIsMapped(cap, 1);
    cap = cap_page_table_cap_set_capPTMappedASID(cap, asid);
    cap = cap_page_table_cap_set_capPTMappedAddress(cap, vaddr);

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return performX86PageTableInvocationMap(cap, cte, pde, pdSlot.pdSlot, vspace);
}

exception_t decodeX86MMUInvocation(
    word_t invLabel,
    word_t length,
    cptr_t cptr,
    cte_t* cte,
    cap_t cap,
    extra_caps_t excaps,
    word_t* buffer
)
{
    switch (cap_get_capType(cap)) {

    case cap_frame_cap:
        return decodeX86FrameInvocation(invLabel, length, cte, cap, excaps, buffer);

    case cap_page_table_cap:
        return decodeX86PageTableInvocation(invLabel, length, cte, cap, excaps, buffer);

    case cap_asid_control_cap: {
        word_t i;
        asid_t asid_base;
        word_t index;
        word_t depth;
        cap_t untyped;
        cap_t root;
        cte_t* parentSlot;
        cte_t* destSlot;
        lookupSlot_ret_t lu_ret;
        void* frame;
        exception_t status;

        if (invLabel != X86ASIDControlMakePool) {
            current_syscall_error.type = seL4_IllegalOperation;

            return EXCEPTION_SYSCALL_ERROR;
        }

        if (length < 2 || excaps.excaprefs[0] == ((void *)0)
                || excaps.excaprefs[1] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }

        index = getSyscallArg(0, buffer);
        depth = getSyscallArg(1, buffer);
        parentSlot = excaps.excaprefs[0];
        untyped = parentSlot->cap;
        root = excaps.excaprefs[1]->cap;


        for (i = 0; i < (1ul << (asidHighBits)) && x86KSASIDTable[i]; i++);

        if (i == (1ul << (asidHighBits))) {

            current_syscall_error.type = seL4_DeleteFirst;

            return EXCEPTION_SYSCALL_ERROR;
        }

        asid_base = i << asidLowBits;


        if (cap_get_capType(untyped) != cap_untyped_cap ||
                cap_untyped_cap_get_capBlockSize(untyped) != 12 ||
                cap_untyped_cap_get_capIsDevice(untyped)) {
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 1;

            return EXCEPTION_SYSCALL_ERROR;
        }

        status = ensureNoChildren(parentSlot);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        frame = ((word_t *)(cap_untyped_cap_get_capPtr(untyped)));

        lu_ret = lookupTargetSlot(root, index, depth);
        if (lu_ret.status != EXCEPTION_NONE) {
            return lu_ret.status;
        }
        destSlot = lu_ret.slot;

        status = ensureEmptySlot(destSlot);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performASIDControlInvocation(frame, destSlot, parentSlot, asid_base);
    }

    case cap_asid_pool_cap: {
        cap_t vspaceCap;
        cte_t* vspaceCapSlot;
        asid_pool_t* pool;
        word_t i;
        asid_t asid;

        if (invLabel != X86ASIDPoolAssign) {
            current_syscall_error.type = seL4_IllegalOperation;

            return EXCEPTION_SYSCALL_ERROR;
        }
        if (excaps.excaprefs[0] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;

            return EXCEPTION_SYSCALL_ERROR;
        }

        vspaceCapSlot = excaps.excaprefs[0];
        vspaceCap = vspaceCapSlot->cap;

        if (!(isVTableRoot(vspaceCap) || cap_get_capType(vspaceCap) == cap_ept_pml4_cap)
                || cap_get_capMappedASID(vspaceCap) != asidInvalid) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1464, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("X86ASIDPool: Invalid vspace root."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 1;

            return EXCEPTION_SYSCALL_ERROR;
        }

        pool = x86KSASIDTable[cap_asid_pool_cap_get_capASIDBase(cap) >> asidLowBits];
        if (!pool) {
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = false;
            current_lookup_fault = lookup_fault_invalid_root_new();
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (pool != ((asid_pool_t*)cap_asid_pool_cap_get_capASIDPool(cap))) {
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }


        asid = cap_asid_pool_cap_get_capASIDBase(cap);
        for (i = 0; i < (1ul << (asidLowBits)) && (asid + i == 0 || asid_map_get_type(pool->array[i]) != asid_map_asid_map_none); i++);

        if (i == (1ul << (asidLowBits))) {
            current_syscall_error.type = seL4_DeleteFirst;

            return EXCEPTION_SYSCALL_ERROR;
        }

        asid += i;

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performASIDPoolInvocation(asid, pool, vspaceCapSlot);
    }

    default:
        return decodeX86ModeMMUInvocation(invLabel, length, cptr, cte, cap, excaps, buffer);
    }
}

__attribute__((__section__(".boot.text"))) bool_t
x2apic_is_enabled(void)
{
    apic_base_msr_t apic_base_msr;
    apic_base_msr.words[0] = x86_rdmsr_low(0x01B);

    if ((x86_cpuid_ecx(1, 0) & (1ul << (21))) &&
            apic_base_msr_get_enabled(apic_base_msr) &&
            apic_base_msr_get_x2apic(apic_base_msr)) {
        return true;
    }
    return false;
}
__attribute__((__section__(".boot.text"))) bool_t
apic_enable(void)
{
    apic_base_msr_t apic_base_msr;
    apic_base_msr.words[0] = x86_rdmsr_low(0x01B);

    if (!apic_base_msr_get_enabled(apic_base_msr)) {
        kprintf("APIC: Enabled bit not set\n");
        return false;
    }

    if (x2apic_is_enabled()) {
        kprintf("x2APIC enabled in BIOS but kernel does not support that\n");
        return false;
    }





    return true;
}

bool_t apic_is_interrupt_pending(void)
{
    word_t i;


    if(!(int_irq_min % 32 == 0)) _assert_fail("int_irq_min % 32 == 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/xapic.c", 62, __FUNCTION__);
    for (i = int_irq_min; i <= int_irq_max; i += 32) {
        if (apic_read_reg(APIC_IRR_BASE + i / 2) != 0) {
            return true;
        }
    }
    return false;
}

__attribute__((__section__(".boot.text"))) void
apic_send_init_ipi(cpu_id_t cpu_id)
{
    apic_write_icr(
        apic_icr2_new(
            cpu_id
        ).words[0],
        apic_icr1_new(
            0,
            1,
            1,
            0,
            0,
            5,
            0
        ).words[0]
    );
    apic_write_icr(
        apic_icr2_new(
            cpu_id
        ).words[0],
        apic_icr1_new(
            0,
            1,
            0,
            0,
            0,
            5,
            0
        ).words[0]
    );
}

__attribute__((__section__(".boot.text"))) void
apic_send_startup_ipi(cpu_id_t cpu_id, paddr_t startup_addr)
{

    if(!((!((startup_addr) & ((1ul << (12))-1ul))))) _assert_fail("IS_ALIGNED(startup_addr, PAGE_BITS)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/xapic.c", 108, __FUNCTION__);

    if(!(startup_addr < 0xa0000)) _assert_fail("startup_addr < 0xa0000", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/kernel/xapic.c", 110, __FUNCTION__);
    startup_addr >>= 12;

    apic_write_icr(
        apic_icr2_new(
            cpu_id
        ).words[0],
        apic_icr1_new(
            0,
            0,
            0,
            0,
            0,
            6,
            startup_addr
        ).words[0]
    );
}

void apic_send_ipi_core(irq_t vector, cpu_id_t cpu_id)
{
    apic_icr1_t icr1;

    do {
        icr1.words[0] = apic_read_reg(APIC_ICR1);
    } while (apic_icr1_get_delivery_status(icr1));

    apic_write_icr(
        apic_icr2_new(
            cpu_id
        ).words[0],
        apic_icr1_new(
            0,
            0,
            0,
            0,
            0,
            0,
            vector
        ).words[0]
    );
}

void apic_send_ipi_cluster(irq_t vector, word_t mda)
{
    apic_icr1_t icr1;

    do {
        icr1.words[0] = apic_read_reg(APIC_ICR1);
    } while (apic_icr1_get_delivery_status(icr1));

    apic_write_icr(
        apic_icr2_new(
            mda
        ).words[0],
        apic_icr1_new(
            0,
            0,
            0,
            0,
            1,
            0,
            vector
        ).words[0]
    );
}
static int getDecodedChar(unsigned char *result)
{
    unsigned char c;
    c = getDebugChar();
    if (c == 0xff) {
        return 1;
    }
    if (c == 0xaa) {
        c = getDebugChar();
        if (c == 0xff) {
            return 1;
        }
        switch (c) {
        case 0xa1:
            *result = 0xaa;
            break;
        case 0xa0:
            *result = 0xff;
            break;
        case 0xa2:
            *result = 0xbb;
            break;
        default:
            if (c >= 20 && c < 40) {
                *result = c - 20;
            } else {
                return 1;
            }
        }
        return 0;
    } else {
        *result = c;
        return 0;
    }
}

static void putEncodedChar(unsigned char c)
{
    switch (c) {
    case 0xaa:
        putDebugChar(0xaa);
        putDebugChar(0xa1);
        break;
    case 0xff:
        putDebugChar(0xaa);
        putDebugChar(0xa0);
        break;
    case 0xbb:
        putDebugChar(0xaa);
        putDebugChar(0xa2);
        break;
    default:
        if (c < 20) {
            putDebugChar(0xaa);
            putDebugChar(c + 20);
        } else {
            putDebugChar(c);
        }
    }
}

static int getArg(unsigned long *res)
{
    unsigned long i;
    unsigned char byte;
    *res = 0;
    for (i = 0; i < sizeof(unsigned long); i++) {
        if (getDecodedChar(&byte)) {
            return 1;
        }
        (*res) = ((*res) << 8) | byte;
    }
    return 0;
}

static void sendWord(unsigned long word)
{
    unsigned long i;
    for (i = 0; i < sizeof(unsigned long); i++) {
        putEncodedChar( (word >> (i * 8)) & 0xff);
    }
}

static cte_t *getMDBParent(cte_t *slot)
{
    cte_t *oldSlot = ((cte_t *)(mdb_node_get_mdbPrev(slot->cteMDBNode)));

    while (oldSlot != 0 && !isMDBParentOf(oldSlot, slot)) {
        oldSlot = ((cte_t *)(mdb_node_get_mdbPrev(oldSlot->cteMDBNode)));
    }

    return oldSlot;
}

static void sendPD(unsigned long address)
{
    unsigned long i;
    unsigned int exists;
    pde_t *start = (pde_t *)address;
    for (i = 0; i < (1ul << (9)); i++) {
        pde_t pde = start[i];
        exists = 1;
        if (pde_get_page_size(pde) == pde_pde_pt && (pde_pde_pt_get_pt_base_address(pde) == 0 ||
                                                     !pde_pde_pt_get_present(pde) || !pde_pde_pt_get_super_user(pde))) {
            exists = 0;
        } else if (pde_get_page_size(pde) == pde_pde_large && (pde_pde_large_get_page_base_address(pde) == 0 ||
                                                               !pde_pde_large_get_present(pde) || !pde_pde_large_get_super_user(pde))) {
            exists = 0;
        }
        if (exists != 0 && i < 0xffffff8000000000ul >> pageBitsForSize(X86_LargePage)) {
            sendWord(i);
            sendWord(pde.words[0]);
        }
    }
}

static void sendPT(unsigned long address)
{
    unsigned long i;
    pte_t *start = (pte_t *)address;
    for (i = 0; i < (1ul << (9)); i++) {
        pte_t pte = start[i];
        if (pte_get_page_base_address(pte) != 0 && pte_get_present(pte) && pte_get_super_user(pte)) {
            sendWord(i);
            sendWord(pte.words[0]);
        }
    }
}

static void sendASIDPool(unsigned long address)
{
    unsigned long i;
    pde_t **start = (pde_t **)address;
    for (i = 0; i < (1ul << (9)); i++) {
        pde_t *pde = start[i];
        if (pde != 0) {
            sendWord(i);
            sendWord((unsigned long)pde);
        }
    }
}
static void sendRunqueues(void)
{
    word_t i;
    sendWord((unsigned long)ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
    for (i = 0; i < (1 * 256); i++) {
        tcb_t *current = ksSMP[(getCurrentCPUIndex())].system.ksReadyQueues[i].head;
        if (current != 0) {
            while (current != ksSMP[(getCurrentCPUIndex())].system.ksReadyQueues[i].end) {
                sendWord((unsigned long)current);
                current = current -> tcbSchedNext;
            }
            sendWord((unsigned long)current);
        }
    }
}

static void sendEPQueue(unsigned long epptr)
{
    tcb_t *current = (tcb_t *)endpoint_ptr_get_epQueue_head((endpoint_t *)epptr);
    tcb_t *tail = (tcb_t *)endpoint_ptr_get_epQueue_tail((endpoint_t *)epptr);
    if (current == 0) {
        return;
    }
    while (current != tail) {
        sendWord((unsigned long)current);
        current = current->tcbEPNext;
    }
    sendWord((unsigned long)current);
}

static void sendCNode(unsigned long address, unsigned int sizebits)
{
    unsigned long i;
    cte_t *start = (cte_t *)address;
    for (i = 0; i < (1 << sizebits); i++) {
        cap_t cap = start[i].cap;
        if (cap_get_capType(cap) != cap_null_cap) {
            cte_t *parent = getMDBParent(&start[i]);
            sendWord(i);
            sendWord(cap.words[0]);
            sendWord(cap.words[1]);
            sendWord((unsigned long)parent);
        }
    }
}

static void sendIRQNode(void)
{
    sendCNode((unsigned long)intStateIRQNode, 8);
}

static void sendVersion(void)
{
    sendWord(0xe1);
    sendWord(0);
}

void capDL(void)
{
    int result;
    int done = 0;
    while (done == 0) {
        unsigned char c;
        do {
            c = getDebugChar();
        } while (c != 0xff);
        do {
            result = getDecodedChar(&c);
            if (result) {
                continue;
            }
            switch (c) {
            case 0xf0: {

                unsigned long arg;
                result = getArg(&arg);
                if (result) {
                    continue;
                }
                sendPD(arg);
                putDebugChar(0xbb);
            }
            break;
            case 0xf5: {

                unsigned long arg;
                result = getArg(&arg);
                if (result) {
                    continue;
                }
                sendPT(arg);
                putDebugChar(0xbb);
            }
            break;
            case 0xf6: {

                unsigned long arg;
                result = getArg(&arg);
                if (result) {
                    continue;
                }
                sendASIDPool(arg);
                putDebugChar(0xbb);
            }
            break;
            break;
            case 0xf1: {

                sendRunqueues();
                putDebugChar(0xbb);
                result = 0;
            }
            break;
            case 0xf2: {

                unsigned long arg;
                result = getArg(&arg);
                if (result) {
                    continue;
                }
                sendEPQueue(arg);
                putDebugChar(0xbb);
            }
            break;
            case 0xf3: {

                unsigned long address, sizebits;
                result = getArg(&address);
                if (result) {
                    continue;
                }
                result = getArg(&sizebits);
                if (result) {
                    continue;
                }

                sendCNode(address, sizebits);
                putDebugChar(0xbb);
            }
            break;
            case 0xf4: {
                sendIRQNode();
                putDebugChar(0xbb);
                result = 0;
            }
            break;
            case 0xf9: {
                sendVersion();
                putDebugChar(0xbb);
            }
            break;
            case 0xfa: {
                done = 1;
                putDebugChar(0xbb);
            }
            default:
                result = 0;
                break;
            }
        } while (result);
    }
}







const char X86_CPUID_VENDOR_STRING_INTEL[] = {'G', 'e', 'n', 'u', 'i', 'n', 'e', 'I', 'n', 't', 'e', 'l', 0};
const char X86_CPUID_VENDOR_STRING_AMD_LEGACY[] = { 'A', 'M', 'D', 'i', 's', 'b', 'e', 't', 't', 'e', 'r', '!', 0};
const char X86_CPUID_VENDOR_STRING_AMD[] = {'A', 'u', 't', 'h', 'e', 'n', 't', 'i', 'c', 'A', 'M', 'D', 0};

__attribute__((__section__(".boot.bss"))) static cpu_identity_t cpu_identity;

__attribute__((__section__(".boot.text"))) cpu_identity_t *x86_cpuid_get_identity(void)
{
    return &cpu_identity;
}

__attribute__((__section__(".boot.text"))) x86_cpu_identity_t *x86_cpuid_get_model_info(void)
{
    return &cpu_identity.display;
}





__attribute__((__section__(".boot.text"))) static void
x86_cpuid_fill_vendor_string(cpu_identity_t *ci)
{
    __attribute__((may_alias)) uint32_t *vendor_string32 = (uint32_t *)ci->vendor_string;

    if (ci == ((void *)0)) {
        return;
    }

    vendor_string32[0] = x86_cpuid_ebx(0, 0);
    vendor_string32[1] = x86_cpuid_edx(0, 0);
    vendor_string32[2] = x86_cpuid_ecx(0, 0);

    ci->vendor_string[(12)] = '\0';
}

struct family_model {
    uint8_t family, model;
};

__attribute__((__section__(".boot.text"))) static void
x86_cpuid_intel_identity_initialize(cpu_identity_t *ci,
                                    struct family_model original)
{






    if (original.family != 0x0F) {
        ci->display.family = original.family;
    } else {
        ci->display.family = ci->display.extended_family + original.family;
    }
    if (ci->display.family == 0x06 || ci->display.family == 0x0F) {
        ci->display.model = (ci->display.extended_model << 4u) + original.model;
    } else {
        ci->display.model = original.model;
    }
}

__attribute__((__section__(".boot.text"))) static void
x86_cpuid_amd_identity_initialize(cpu_identity_t *ci,
                                  struct family_model original)
{







    if (original.family < 0xF) {
        ci->display.family = original.family;
        ci->display.model = original.model;
    } else {
        ci->display.family = original.family + ci->display.extended_family;
        ci->display.family = (ci->display.extended_model << 4u) + original.model;
    }
}

bool_t
x86_cpuid_initialize(void)
{
    cpu_identity_t *ci = x86_cpuid_get_identity();
    struct family_model original;
    cpuid_001h_eax_t eax;
    cpuid_001h_ebx_t ebx;

    memset(ci, 0, sizeof(*ci));


    x86_cpuid_fill_vendor_string(ci);


    eax.words[0] = x86_cpuid_eax(1, 0);
    ebx.words[0] = x86_cpuid_ebx(1, 0);




    original.family = cpuid_001h_eax_get_family(eax);
    original.model = cpuid_001h_eax_get_model(eax);
    ci->display.stepping = cpuid_001h_eax_get_stepping(eax);


    ci->display.extended_family = cpuid_001h_eax_get_extended_family(eax);
    ci->display.extended_model = cpuid_001h_eax_get_extended_model(eax);


    ci->display.brand = cpuid_001h_ebx_get_brand(ebx);

    if (strncmp(ci->vendor_string, X86_CPUID_VENDOR_STRING_INTEL,
                (12)) == 0) {
        ci->vendor = X86_VENDOR_INTEL;
        x86_cpuid_intel_identity_initialize(ci, original);
        return true;
    } else if (strncmp(ci->vendor_string, X86_CPUID_VENDOR_STRING_AMD_LEGACY,
                       (12)) == 0
               || strncmp(ci->vendor_string, X86_CPUID_VENDOR_STRING_AMD,
                          (12)) == 0) {
        ci->vendor = X86_VENDOR_AMD;
        x86_cpuid_amd_identity_initialize(ci, original);
        return true;
    } else {




        ci->vendor = X86_VENDOR_OTHER;
        return false;
    }
}




void
Arch_initFpuContext(user_context_t *context)
{
    context->fpuState = x86KSnullFpuState;
}




__attribute__((__section__(".boot.text"))) bool_t
Arch_initFpu(void)
{

    write_cr4(read_cr4() | (1ul << (9)) );


    write_cr0((read_cr0() & ~(1ul << (2)) ) | (1ul << (1)) | (1ul << (5)) );
    enableFpu();


    finit();

    if (0) {
        uint64_t xsave_features;
        uint32_t xsave_instruction;
        uint64_t desired_features = 1;
        xsave_state_t *nullFpuState = (xsave_state_t *) &x86KSnullFpuState;


        memzero(&x86KSnullFpuState, sizeof(x86KSnullFpuState));


        if (!(x86_cpuid_ecx(1, 0) & (1ul << (26)))) {
            kprintf("XSAVE not supported\n");
            return false;
        }

        write_cr4(read_cr4() | (1ul << (18)) );

        xsave_features = ((uint64_t)x86_cpuid_edx(0x0d, 0x0) << 32) | x86_cpuid_eax(0x0d, 0x0);
        if ((xsave_features & desired_features) != desired_features) {
            kprintf("Requested feature mask is 0x%llx, but only 0x%llx supported\n", desired_features, (long long)xsave_features);
            return false;
        }

        write_xcr0(desired_features);

        if (x86_cpuid_ebx(0x0d, 0x0) > 512) {
            kprintf("XSAVE buffer set set to %d, but needs to be at least %d\n", 512, x86_cpuid_ebx(0x0d, 0x0));
            return false;
        }
        if (x86_cpuid_ebx(0x0d, 0x0) < 512) {
            kprintf("XSAVE buffer set set to %d, but only needs to be %d.\n" "Warning: Memory may be wasted with larger than needed TCBs.\n", 512, x86_cpuid_ebx(0x0d, 0x0))

                                                               ;
        }

        xsave_instruction = x86_cpuid_eax(0x0d, 0x1);
        if (0) {
            if (!(xsave_instruction & (1ul << (0)))) {
                kprintf("XSAVEOPT requested, but not supported\n");
                return false;
            }
        } else if (0) {
            if (!(xsave_instruction & (1ul << (1)))) {
                kprintf("XSAVEC requested, but not supported\n");
                return false;
            }
        } else if (0) {
            if (!(xsave_instruction & (1ul << (3)))) {
                kprintf("XSAVES requested, but not supported\n");
                return false;
            }


            nullFpuState->header.xcomp_bv = (1ull << 63);


            x86_wrmsr(0xD0A, desired_features);
        }


        saveFpuState(&x86KSnullFpuState);
        nullFpuState->i387.mxcsr = 0x1f80;
    } else {

        saveFpuState(&x86KSnullFpuState);
    }

    disableFpu();
    return true;
}


__attribute__((__section__(".boot.text"))) void
init_sysenter_msrs(void)
{
    x86_wrmsr(0x174, (uint64_t)(word_t)(1 << 3));
    x86_wrmsr(0x176, (uint64_t)(word_t)&handle_syscall);
    if (0 && !0) {



        x86_wrmsr(0x175, (uint64_t)(word_t)((char *)&x86KSGlobalState[getCurrentCPUIndex()].x86KStss.tss.words[0] + 4));
    }
}

word_t __attribute__((__pure__)) getRestartPC(tcb_t *thread)
{
    return getRegister(thread, FaultIP);
}

void setNextPC(tcb_t *thread, word_t v)
{
    setRegister(thread, NextIP, v);
}


__attribute__((__section__(".boot.text"))) uint32_t __attribute__((__const__))
getCacheLineSizeBits(void)
{
    uint32_t line_size;
    uint32_t n;

    line_size = getCacheLineSize();
    if (line_size == 0) {
        kprintf("Cacheline size must be >0\n");
        return 0;
    }


    n = 0;
    while (!(line_size & 1)) {
        line_size >>= 1;
        n++;
    }

    if (line_size != 1) {
        kprintf("Cacheline size must be a power of two\n");
        return 0;
    }

    return n;
}



void flushCacheRange(void* vaddr, uint32_t size_bits)
{
    word_t v;

    if(!(size_bits < 64)) _assert_fail("size_bits < seL4_WordBits", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/machine/hardware.c", 78, __FUNCTION__);
    if(!((!(((word_t)vaddr) & ((1ul << (size_bits))-1ul))))) _assert_fail("IS_ALIGNED((word_t)vaddr, size_bits)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/machine/hardware.c", 79, __FUNCTION__);

    x86_mfence();

    for (v = ((((word_t)vaddr) >> (x86KScacheLineSizeBits)) << (x86KScacheLineSizeBits));
            v < (word_t)vaddr + (1ul << (size_bits));
            v += (1ul << (x86KScacheLineSizeBits))) {
        flushCacheLine((void*)v);
    }
    x86_mfence();
}


__attribute__((__section__(".boot.text"))) bool_t
disablePrefetchers()
{
    x86_cpu_identity_t *model_info;
    uint32_t low, high;
    word_t i;

    uint32_t valid_models[] = { 0x4D, 0x56,
                                0x4F, 0x47,
                                0x3D,
                                0x3C, 0x3F,
                                0x45, 0x46,
                                0x9A, 0x3E,
                                0x3A,
                                0x2A , 0x2D , 0x25 , 0x2C ,
                                0x2F , 0x1E , 0x1A , 0x2E ,
                                0x4E, 0x5E
                              };

    model_info = x86_cpuid_get_model_info();

    for (i = 0; i < (sizeof(valid_models) / sizeof(valid_models[0])); i++) {







        if (model_info->family == (0x06)
                && model_info->model == valid_models[i]) {
            low = x86_rdmsr_low(0x1A4);
            high = x86_rdmsr_high(0x1A4);

            low |= (1ul << (0));
            low |= (1ul << (1));
            low |= (1ul << (2));
            low |= (1ul << (3));

            x86_wrmsr(0x1A4, ((uint64_t)high) << 32 | low);

            return true;
        }
    }

    kprintf("Disabling prefetchers not implemented for CPU fam %x model %x\n", model_info->family, model_info->model)
                                                 ;
    return false;
}

__attribute__((__section__(".boot.text"))) void
enablePMCUser(void)
{
    write_cr4(read_cr4() | (1ul << (8)) );
}

__attribute__((__section__(".boot.text"))) bool_t
init_ibrs(void)
{
    cpuid_007h_edx_t edx;
    edx.words[0] = x86_cpuid_edx(0x7, 0);
    bool_t support_ibrs = cpuid_007h_edx_get_ibrs_ibpb(edx);
    if ((0 || 0) && !support_ibrs) {
        kprintf("IBRS not supported by CPU\n");
        return false;
    } else if (support_ibrs) {


        x86_disable_ibrs();
    }

    if (0 && !support_ibrs) {
        kprintf("IBPB not supported by CPU\n");
        return false;
    }

    bool_t enhanced_ibrs = false;
    if (cpuid_007h_edx_get_ia32_arch_cap_msr(edx)) {
        ia32_arch_capabilities_msr_t cap_msr;
        cap_msr.words[0] = x86_rdmsr(0x10A);
        if (ia32_arch_capabilities_msr_get_ibrs_all(cap_msr)) {
            enhanced_ibrs = true;
        }
    }
    if (0 && enhanced_ibrs) {
        kprintf("Kernel configured for basic IBRS, but CPU supports enhanced IBRS. " "Enable enhanced IBRS for improved performance\n")
                                                                 ;
    }
    if (0) {
        if (!enhanced_ibrs) {
            kprintf("Enhanced IBRS not supported by CPU\n");
            return false;
        }

        x86_enable_ibrs();
    }
    return true;
}

void Arch_initContext(user_context_t* context)
{
    Mode_initContext(context);
    context->registers[TLS_BASE] = 0;
    context->registers[Error] = 0;
    context->registers[FaultIP] = 0;
    context->registers[NextIP] = 0;
    context->registers[CS] = ((5 << 3) | 3);
    context->registers[FLAGS] = (1ul << (9)) | (1ul << (1)) ;
    context->registers[SS] = ((6 << 3) | 3);

    Arch_initFpuContext(context);



}

word_t sanitiseRegister(register_t reg, word_t v, bool_t archInfo)
{

    v = Mode_sanitiseRegister(reg, v);
    if (reg == FLAGS) {

        v |= (1ul << (1)) ;
        v &= ~((1ul << (3)) | (1ul << (5))) ;

        v |= (1ul << (9)) ;
        v &= ~(1ul << (8)) ;

        v &= ((1ul << (12))-1ul) ;
    }
    return v;
}




;

;



x86_arch_global_state_t x86KSGlobalState[16] __attribute__((__aligned__(64))) __attribute__((__section__(".skim.bss")));


asid_pool_t* x86KSASIDTable[(1ul << (asidHighBits))];


;
;

;




cpu_id_mapping_t cpu_mapping;


uint32_t x86KScacheLineSizeBits;


user_fpu_state_t x86KSnullFpuState __attribute__((__aligned__(64)));


uint32_t x86KSnumDrhu;
;



uint16_t x86KSconsolePort;


uint16_t x86KSdebugPort;




x86_irq_state_t x86KSIRQState[maxIRQ + 1];

void
Arch_irqStateInit(void)
{
    int i = 0;
    for (i = 0; i <= maxIRQ; i++) {
        if (i == irq_timer



           ) {
            x86KSIRQState[i] = x86_irq_state_irq_reserved_new();
        } else {
            x86KSIRQState[i] = x86_irq_state_irq_free_new();
        }
    }
}







exception_t
Arch_checkIRQ(word_t irq_w)
{
    if (0 && irq_w >= irq_isa_min && irq_w <= irq_isa_max) {
        return EXCEPTION_NONE;
    }
    if (1) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 49, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IRQControl: Illegal operation"); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
    } else {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 52, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IRQControl: IRQ %ld should be in range %ld - %ld", irq_w, (long)irq_isa_min, (long)irq_isa_max); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = irq_isa_min;
        current_syscall_error.rangeErrorMax = irq_isa_max;
    }
    return EXCEPTION_SYSCALL_ERROR;
}

static exception_t
Arch_invokeIRQControl(irq_t irq, cte_t *handlerSlot, cte_t *controlSlot, x86_irq_state_t irqState)
{
    updateIRQState(irq, irqState);
    return invokeIRQControl(irq, handlerSlot, controlSlot);
}

static exception_t
invokeIssueIRQHandlerIOAPIC(irq_t irq, word_t ioapic, word_t pin, word_t level, word_t polarity, word_t vector,
                            cte_t *handlerSlot, cte_t *controlSlot)
{
    x86_irq_state_t irqState = x86_irq_state_irq_ioapic_new(ioapic, pin, level, polarity, 1);
    ioapic_map_pin_to_vector(ioapic, pin, level, polarity, vector);
    return Arch_invokeIRQControl(irq, handlerSlot, controlSlot, irqState);
}

exception_t
Arch_decodeIRQControlInvocation(word_t invLabel, word_t length, cte_t *srcSlot, extra_caps_t excaps, word_t *buffer)
{
    word_t index, depth;
    cte_t *destSlot;
    cap_t cnodeCap;
    lookupSlot_ret_t lu_ret;
    exception_t status;
    irq_t irq;
    word_t vector;

    if (!1) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 88, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IRQControl: Illegal operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }



    if (length < 7 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 96, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IRQControl: Truncated message"); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }
    index = getSyscallArg(0, buffer);
    depth = getSyscallArg(1, buffer);
    cnodeCap = excaps.excaprefs[0]->cap;
    irq = getSyscallArg(6, buffer);
    if (irq > irq_user_max - irq_user_min) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 105, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IRQControl: Invalid irq %ld should be between 0-%ld", (long)irq, (long)(irq_user_max - irq_user_min - 1)); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = irq_user_max - irq_user_min;
        return EXCEPTION_SYSCALL_ERROR;
    }
    irq += irq_user_min;
    vector = (word_t)irq + 0x20;

    lu_ret = lookupTargetSlot(cnodeCap, index, depth);
    if (lu_ret.status != EXCEPTION_NONE) {
        return lu_ret.status;
    }

    destSlot = lu_ret.slot;

    status = ensureEmptySlot(destSlot);
    if (status != EXCEPTION_NONE) {
        return status;
    }

    switch (invLabel) {
    case X86IRQIssueIRQHandlerIOAPIC: {
        word_t ioapic = getSyscallArg(2, buffer);
        word_t pin = getSyscallArg(3, buffer);
        word_t level = getSyscallArg(4, buffer);
        word_t polarity = getSyscallArg(5, buffer);


        if (isIRQActive(irq)) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 135, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IOAPICGet: IRQ %d is already active.", (int)irq); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_RevokeFirst;
            return EXCEPTION_SYSCALL_ERROR;
        }

        status = ioapic_decode_map_pin_to_vector(ioapic, pin, level, polarity, vector);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return invokeIssueIRQHandlerIOAPIC(irq, ioapic, pin, level, polarity, vector, destSlot, srcSlot);
    }
    break;
    case X86IRQIssueIRQHandlerMSI: {
        word_t pci_bus = getSyscallArg(2, buffer);
        word_t pci_dev = getSyscallArg(3, buffer);
        word_t pci_func = getSyscallArg(4, buffer);
        word_t handle = getSyscallArg(5, buffer);
        x86_irq_state_t irqState;


        (void)vector;
        if (isIRQActive(irq)) {
            current_syscall_error.type = seL4_RevokeFirst;
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (pci_bus > 255) {
            current_syscall_error.type = seL4_RangeError;
            current_syscall_error.rangeErrorMin = 0;
            current_syscall_error.rangeErrorMax = 255;
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (pci_dev > 31) {
            current_syscall_error.type = seL4_RangeError;
            current_syscall_error.rangeErrorMin = 0;
            current_syscall_error.rangeErrorMax = 31;
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (pci_func > 7) {
            current_syscall_error.type = seL4_RangeError;
            current_syscall_error.rangeErrorMin = 0;
            current_syscall_error.rangeErrorMax = 7;
            return EXCEPTION_SYSCALL_ERROR;
        }

        irqState = x86_irq_state_irq_msi_new(pci_bus, pci_dev, pci_func, handle);

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return Arch_invokeIRQControl(irq, destSlot, srcSlot, irqState);
    }
    break;
    default:
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 191, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IRQControl: Illegal operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
}

static exception_t
ensurePortOperationAllowed(cap_t cap, uint32_t start_port, uint32_t size)
{
    uint32_t first_allowed = cap_io_port_cap_get_capIOPortFirstPort(cap);
    uint32_t last_allowed = cap_io_port_cap_get_capIOPortLastPort(cap);
    uint32_t end_port = start_port + size - 1;
    if(!(first_allowed <= last_allowed)) _assert_fail("first_allowed <= last_allowed", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/ioport.c", 25, __FUNCTION__);
    if(!(start_port <= end_port)) _assert_fail("start_port <= end_port", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/ioport.c", 26, __FUNCTION__);

    if ((start_port < first_allowed) || (end_port > last_allowed)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 31, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IOPort: Ports %d--%d fall outside permitted range %d--%d.", (int)start_port, (int)end_port, (int)first_allowed, (int)last_allowed); kprintf(">>" "" "\n"); } while (0)

                                                        ;
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    return EXCEPTION_NONE;
}

exception_t
decodeX86PortInvocation(
    word_t invLabel,
    word_t length,
    cptr_t cptr,
    cte_t* slot,
    cap_t cap,
    extra_caps_t excaps,
    word_t* buffer
)
{
    uint32_t res;
    uint32_t len;
    uint16_t port;
    exception_t ret;


    if (length < 1) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 57, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IOPort: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (invLabel == X86IOPortOut8 || invLabel == X86IOPortOut16 || invLabel == X86IOPortOut32) {

        if (length < 2) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 65, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IOPort Out32: Truncated message."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }
    }


    port = getSyscallArg(0, buffer) & 0xffff;

    switch (invLabel) {
    case X86IOPortIn8: {


        ret = ensurePortOperationAllowed(cap, port, 1);
        if (ret != EXCEPTION_NONE) {
            return ret;
        }


        res = in8(port);
        len = 1;
        break;
    }

    case X86IOPortIn16: {


        ret = ensurePortOperationAllowed(cap, port, 2);
        if (ret != EXCEPTION_NONE) {
            return ret;
        }


        res = in16(port);
        len = 1;
        break;
    }

    case X86IOPortIn32: {


        ret = ensurePortOperationAllowed(cap, port, 4);
        if (ret != EXCEPTION_NONE) {
            return ret;
        }


        res = in32(port);
        len = 1;
        break;
    }

    case X86IOPortOut8: {
        uint8_t data;


        ret = ensurePortOperationAllowed(cap, port, 1);
        if (ret != EXCEPTION_NONE) {
            return ret;
        }


        data = (getSyscallArg(1, buffer)) & 0xff;
        out8(port, data);
        len = 0;
        break;
    }

    case X86IOPortOut16: {
        uint16_t data;


        ret = ensurePortOperationAllowed(cap, port, 2);
        if (ret != EXCEPTION_NONE) {
            return ret;
        }


        data = (getSyscallArg(1, buffer)) & 0xffff;
        out16(port, data);
        len = 0;
        break;
    }

    case X86IOPortOut32: {
        uint32_t data;


        ret = ensurePortOperationAllowed(cap, port, 4);
        if (ret != EXCEPTION_NONE) {
            return ret;
        }


        data = getSyscallArg(1, buffer) & 0xffffffff;
        out32(port, data);
        len = 0;
        break;
    }

    default:
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 166, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IOPort: Unknown operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (len > 0) {

        setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, badgeRegister, 0);
        if (n_msgRegisters < 1) {
            word_t* ipcBuffer;
            ipcBuffer = lookupIPCBuffer(true, ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
            if (ipcBuffer != ((void *)0)) {
                ipcBuffer[1] = res;
                len = 1;
            } else {
                len = 0;
            }
        } else {
            setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, msgRegisters[0], res);
            len = 1;
        }
    }
    setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, msgInfoRegister,
                wordFromMessageInfo(seL4_MessageInfo_new(0, 0, 0, len)));

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return EXCEPTION_NONE;
}


deriveCap_ret_t Arch_deriveCap(cte_t* slot, cap_t cap)
{
    deriveCap_ret_t ret;

    switch (cap_get_capType(cap)) {
    case cap_page_table_cap:
        if (cap_page_table_cap_get_capPTIsMapped(cap)) {
            ret.cap = cap;
            ret.status = EXCEPTION_NONE;
        } else {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 37, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Deriving an unmapped PT cap"); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            ret.cap = cap_null_cap_new();
            ret.status = EXCEPTION_SYSCALL_ERROR;
        }
        return ret;

    case cap_page_directory_cap:
        if (cap_page_directory_cap_get_capPDIsMapped(cap)) {
            ret.cap = cap;
            ret.status = EXCEPTION_NONE;
        } else {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 49, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Deriving a PD cap without an assigned ASID"); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            ret.cap = cap_null_cap_new();
            ret.status = EXCEPTION_SYSCALL_ERROR;
        }
        return ret;

    case cap_asid_control_cap:
    case cap_asid_pool_cap:
        ret.cap = cap;
        ret.status = EXCEPTION_NONE;
        return ret;
    case cap_io_port_cap:
        ret.cap = cap;
        ret.status = EXCEPTION_NONE;
        return ret;
    case cap_vcpu_cap:
        ret.cap = cap;
        ret.status = EXCEPTION_NONE;
        return ret;
    case cap_ept_pml4_cap:
        if (cap_ept_pml4_cap_get_capPML4IsMapped(cap)) {
            ret.cap = cap;
            ret.status = EXCEPTION_NONE;
        } else {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 93, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Deriving a EPT PML4 cap without an assigned ASID."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            ret.cap = cap_null_cap_new();
            ret.status = EXCEPTION_SYSCALL_ERROR;
        }
        return ret;
    case cap_ept_pdpt_cap:
        if (cap_ept_pdpt_cap_get_capPDPTIsMapped(cap)) {
            ret.cap = cap;
            ret.status = EXCEPTION_NONE;
        } else {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 104, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Deriving an unmapped EPT PDPT cap."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            ret.cap = cap_null_cap_new();
            ret.status = EXCEPTION_SYSCALL_ERROR;
        }
        return ret;

    case cap_ept_pd_cap:
        if (cap_ept_pd_cap_get_capPDIsMapped(cap)) {
            ret.cap = cap;
            ret.status = EXCEPTION_NONE;
        } else {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 116, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Deriving an unmapped EPT PD cap."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            ret.cap = cap_null_cap_new();
            ret.status = EXCEPTION_SYSCALL_ERROR;
        }
        return ret;

    case cap_ept_pt_cap:
        if (cap_ept_pt_cap_get_capPTIsMapped(cap)) {
            ret.cap = cap;
            ret.status = EXCEPTION_NONE;
        } else {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 128, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Deriving an unmapped EPT PT cap."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            ret.cap = cap_null_cap_new();
            ret.status = EXCEPTION_SYSCALL_ERROR;
        }
        return ret;


    default:
        return Mode_deriveCap(slot, cap);
    }
}

cap_t __attribute__((__const__)) Arch_updateCapData(bool_t preserve, word_t data, cap_t cap)
{
    switch (cap_get_capType(cap)) {
    case cap_io_port_cap: {
        io_port_capdata_t w = { .words = { data } };
        uint16_t firstPort = io_port_capdata_get_firstPort(w);
        uint16_t lastPort = io_port_capdata_get_lastPort(w);
        uint16_t capFirstPort = cap_io_port_cap_get_capIOPortFirstPort(cap);
        uint16_t capLastPort = cap_io_port_cap_get_capIOPortLastPort(cap);
        if(!(capFirstPort <= capLastPort)) _assert_fail("capFirstPort <= capLastPort", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/objecttype.c", 165, __FUNCTION__);


        if (firstPort > lastPort) {
            return cap_null_cap_new();
        }



        if ((firstPort >= capFirstPort) && (lastPort <= capLastPort)) {
            return cap_io_port_cap_new(firstPort, lastPort

                                       , 0

                                      );
        } else {
            return cap_null_cap_new();
        }
    }

    default:
        return cap;
    }
}

cap_t __attribute__((__const__)) Arch_maskCapRights(seL4_CapRights_t cap_rights_mask, cap_t cap)
{
    if (cap_get_capType(cap) == cap_frame_cap) {
        vm_rights_t vm_rights;

        vm_rights = vmRightsFromWord(cap_frame_cap_get_capFVMRights(cap));
        vm_rights = maskVMRights(vm_rights, cap_rights_mask);
        return cap_frame_cap_set_capFVMRights(cap, wordFromVMRights(vm_rights));
    } else {
        return cap;
    }
}

finaliseCap_ret_t Arch_finaliseCap(cap_t cap, bool_t final)
{
    finaliseCap_ret_t fc_ret;

    switch (cap_get_capType(cap)) {
    case cap_page_directory_cap:
        if (final && cap_page_directory_cap_get_capPDIsMapped(cap)) {
            unmapPageDirectory(
                cap_page_directory_cap_get_capPDMappedASID(cap),
                cap_page_directory_cap_get_capPDMappedAddress(cap),
                ((pde_t *)(cap_page_directory_cap_get_capPDBasePtr(cap)))
            );
        }
        break;

    case cap_page_table_cap:
        if (final && cap_page_table_cap_get_capPTIsMapped(cap)) {
            unmapPageTable(
                cap_page_table_cap_get_capPTMappedASID(cap),
                cap_page_table_cap_get_capPTMappedAddress(cap),
                ((pte_t *)(cap_page_table_cap_get_capPTBasePtr(cap)))
            );
        }
        break;

    case cap_asid_pool_cap:
        if (final) {
            deleteASIDPool(
                cap_asid_pool_cap_get_capASIDBase(cap),
                ((asid_pool_t*)cap_asid_pool_cap_get_capASIDPool(cap))
            );
        }
        break;
    case cap_asid_control_cap:
        break;
    case cap_io_port_cap:

        clearVPIDIOPortMappings(cap_io_port_cap_get_capIOPortVPID(cap),
                                cap_io_port_cap_get_capIOPortFirstPort(cap),
                                cap_io_port_cap_get_capIOPortLastPort(cap));

        break;
    case cap_vcpu_cap:
        if (final) {
            vcpu_finalise(((vcpu_t *)(cap_vcpu_cap_get_capVCPUPtr(cap))));
        }
        break;
    case cap_ept_pml4_cap:
        if (final && cap_ept_pml4_cap_get_capPML4IsMapped(cap)) {
            deleteEPTASID(cap_ept_pml4_cap_get_capPML4MappedASID(cap),
                          (ept_pml4e_t*)cap_ept_pml4_cap_get_capPML4BasePtr(cap));
        }
        break;

    case cap_ept_pdpt_cap:
        if (final && cap_ept_pdpt_cap_get_capPDPTIsMapped(cap)) {
            unmapEPTPDPT(
                cap_ept_pdpt_cap_get_capPDPTMappedASID(cap),
                cap_ept_pdpt_cap_get_capPDPTMappedAddress(cap),
                (ept_pdpte_t*)cap_ept_pdpt_cap_get_capPDPTBasePtr(cap));
        }
        break;

    case cap_ept_pd_cap:
        if (final && cap_ept_pd_cap_get_capPDIsMapped(cap)) {
            unmapEPTPageDirectory(
                cap_ept_pd_cap_get_capPDMappedASID(cap),
                cap_ept_pd_cap_get_capPDMappedAddress(cap),
                (ept_pde_t*)cap_ept_pd_cap_get_capPDBasePtr(cap));
        }
        break;

    case cap_ept_pt_cap:
        if (final && cap_ept_pt_cap_get_capPTIsMapped(cap)) {
            unmapEPTPageTable(
                cap_ept_pt_cap_get_capPTMappedASID(cap),
                cap_ept_pt_cap_get_capPTMappedAddress(cap),
                (ept_pte_t*)cap_ept_pt_cap_get_capPTBasePtr(cap));
        }
        break;


    default:
        return Mode_finaliseCap(cap, final);
    }

    fc_ret.remainder = cap_null_cap_new();
    fc_ret.cleanupInfo = cap_null_cap_new();
    return fc_ret;
}

bool_t __attribute__((__const__)) Arch_sameRegionAs(cap_t cap_a, cap_t cap_b)
{
    switch (cap_get_capType(cap_a)) {
    case cap_frame_cap:
        if (cap_get_capType(cap_b) == cap_frame_cap) {
            word_t botA, botB, topA, topB;
            botA = cap_frame_cap_get_capFBasePtr(cap_a);
            botB = cap_frame_cap_get_capFBasePtr(cap_b);
            topA = botA + ((1ul << (pageBitsForSize(cap_frame_cap_get_capFSize(cap_a))))-1ul);
            topB = botB + ((1ul << (pageBitsForSize(cap_frame_cap_get_capFSize(cap_b))))-1ul);
            return ((botA <= botB) && (topA >= topB) && (botB <= topB));
        }
        break;

    case cap_page_table_cap:
        if (cap_get_capType(cap_b) == cap_page_table_cap) {
            return cap_page_table_cap_get_capPTBasePtr(cap_a) ==
                   cap_page_table_cap_get_capPTBasePtr(cap_b);
        }
        break;

    case cap_page_directory_cap:
        if (cap_get_capType(cap_b) == cap_page_directory_cap) {
            return cap_page_directory_cap_get_capPDBasePtr(cap_a) ==
                   cap_page_directory_cap_get_capPDBasePtr(cap_b);
        }
        break;

    case cap_asid_control_cap:
        if (cap_get_capType(cap_b) == cap_asid_control_cap) {
            return true;
        }
        break;

    case cap_asid_pool_cap:
        if (cap_get_capType(cap_b) == cap_asid_pool_cap) {
            return cap_asid_pool_cap_get_capASIDPool(cap_a) ==
                   cap_asid_pool_cap_get_capASIDPool(cap_b);
        }
        break;

    case cap_io_port_cap:
        if (cap_get_capType(cap_b) == cap_io_port_cap) {
            word_t botA, botB, topA, topB;
            botA = cap_io_port_cap_get_capIOPortFirstPort(cap_a);
            botB = cap_io_port_cap_get_capIOPortFirstPort(cap_b);
            topA = cap_io_port_cap_get_capIOPortLastPort(cap_a);
            topB = cap_io_port_cap_get_capIOPortLastPort(cap_b);
            return ((botA <= botB) && (topA >= topB));
        }
        break;
    case cap_vcpu_cap:
        if (cap_get_capType(cap_b) == cap_vcpu_cap) {
            return cap_vcpu_cap_get_capVCPUPtr(cap_a) ==
                   cap_vcpu_cap_get_capVCPUPtr(cap_b);
        }
        break;

    case cap_ept_pml4_cap:
        if (cap_get_capType(cap_b) == cap_ept_pml4_cap) {
            return cap_ept_pml4_cap_get_capPML4BasePtr(cap_a) ==
                   cap_ept_pml4_cap_get_capPML4BasePtr(cap_b);
        }
        break;

    case cap_ept_pdpt_cap:
        if (cap_get_capType(cap_b) == cap_ept_pdpt_cap) {
            return cap_ept_pdpt_cap_get_capPDPTBasePtr(cap_a) ==
                   cap_ept_pdpt_cap_get_capPDPTBasePtr(cap_b);
        }
        break;

    case cap_ept_pd_cap:
        if (cap_get_capType(cap_b) == cap_ept_pd_cap) {
            return cap_ept_pd_cap_get_capPDBasePtr(cap_a) ==
                   cap_ept_pd_cap_get_capPDBasePtr(cap_b);
        }
        break;

    case cap_ept_pt_cap:
        if (cap_get_capType(cap_b) == cap_ept_pt_cap) {
            return cap_ept_pt_cap_get_capPTBasePtr(cap_a) ==
                   cap_ept_pt_cap_get_capPTBasePtr(cap_b);
        }
        break;



    }

    return Mode_sameRegionAs(cap_a, cap_b);
}

bool_t __attribute__((__const__)) Arch_sameObjectAs(cap_t cap_a, cap_t cap_b)
{
    if (cap_get_capType(cap_a) == cap_io_port_cap) {
        return cap_get_capType(cap_b) == cap_io_port_cap;
    }
    if (cap_get_capType(cap_a) == cap_frame_cap) {
        if (cap_get_capType(cap_b) == cap_frame_cap) {
            return ((cap_frame_cap_get_capFBasePtr(cap_a) ==
                     cap_frame_cap_get_capFBasePtr(cap_b)) &&
                    (cap_frame_cap_get_capFSize(cap_a) ==
                     cap_frame_cap_get_capFSize(cap_b)) &&
                    ((cap_frame_cap_get_capFIsDevice(cap_a) == 0) ==
                     (cap_frame_cap_get_capFIsDevice(cap_b) == 0)));
        }
    }
    return Arch_sameRegionAs(cap_a, cap_b);
}

word_t
Arch_getObjectSize(word_t t)
{
    switch (t) {
    case seL4_X86_4K:
        return pageBitsForSize(X86_SmallPage);
    case seL4_X86_LargePageObject:
        return pageBitsForSize(X86_LargePage);
    case seL4_X86_PageTableObject:
        return 12;
    case seL4_X86_PageDirectoryObject:
        return 12;
    case seL4_X86_PDPTObject:
        return 12;
    case 0xffffff:
        return 12;

    case seL4_X86_VCPUObject:
        return 14;
    case seL4_X86_EPTPML4Object:
        return (3 + 9);
    case seL4_X86_EPTPDPTObject:
        return (3 + 9);
    case seL4_X86_EPTPDObject:
        return (3 + 9);
    case seL4_X86_EPTPTObject:
        return (3 + 9);

    default:
        return Mode_getObjectSize(t);
    }
}

cap_t
Arch_createObject(object_t t, void *regionBase, word_t userSize, bool_t deviceMemory)
{

    switch (t) {
    case seL4_X86_VCPUObject: {
        vcpu_t *vcpu;
        vcpu = ((vcpu_t *)((word_t)regionBase));
        if (!vcpu_init(vcpu))
            return cap_null_cap_new();
        return cap_vcpu_cap_new(((word_t)(vcpu)));
    }
    case seL4_X86_EPTPML4Object:
        return cap_ept_pml4_cap_new(
                   0,
                   0,
                   (word_t)regionBase
               );
    case seL4_X86_EPTPDPTObject:
        return cap_ept_pdpt_cap_new(
                   0,
                   0,
                   0,
                   (word_t)regionBase
               );
    case seL4_X86_EPTPDObject:
        return cap_ept_pd_cap_new(
                   0,
                   0,
                   0,
                   (word_t)regionBase
               );
    case seL4_X86_EPTPTObject:
        return cap_ept_pt_cap_new(
                   0,
                   0,
                   0,
                   (word_t)regionBase
               );
    default:

        return Mode_createObject(t, regionBase, userSize, deviceMemory);

    }

}

exception_t
Arch_decodeInvocation(
    word_t invLabel,
    word_t length,
    cptr_t cptr,
    cte_t* slot,
    cap_t cap,
    extra_caps_t excaps,
    bool_t call,
    word_t* buffer
)
{
    switch (cap_get_capType(cap)) {
    case cap_asid_control_cap:
    case cap_asid_pool_cap:
        return decodeX86MMUInvocation(invLabel, length, cptr, slot, cap, excaps, buffer);
    case cap_io_port_cap:
        return decodeX86PortInvocation(invLabel, length, cptr, slot, cap, excaps, buffer);







    case cap_vcpu_cap:
        return decodeX86VCPUInvocation(invLabel, length, cptr, slot, cap, excaps, buffer);
    case cap_ept_pml4_cap:
    case cap_ept_pdpt_cap:
    case cap_ept_pd_cap:
    case cap_ept_pt_cap:
        return decodeX86EPTInvocation(invLabel, length, cptr, slot, cap, excaps, buffer);

    default:
        return Mode_decodeInvocation(invLabel, length, cptr, slot, cap, excaps, buffer);
    }
}

void
Arch_prepareThreadDelete(tcb_t *thread)
{

    fpuThreadDelete(thread);
}


exception_t decodeSetEPTRoot(cap_t cap, extra_caps_t extraCaps);
void Arch_leaveVMAsyncTransfer(tcb_t *tcb);

word_t __attribute__((__const__)) Arch_decodeTransfer(word_t flags)
{
    return 0;
}

exception_t __attribute__((__const__)) Arch_performTransfer(word_t arch, tcb_t *tcb_src, tcb_t *tcb_dest)
{
    return EXCEPTION_NONE;
}


void Arch_leaveVMAsyncTransfer(tcb_t *tcb)
{
    vcpu_sysvmenter_reply_to_user(tcb);
}

static exception_t performSetEPTRoot(tcb_t *tcb, cap_t cap, cte_t *slot)
{
    cte_t *rootSlot;
    exception_t e;

    rootSlot = (((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbArchEPTRoot));
    e = cteDelete(rootSlot, true);
    if (e != EXCEPTION_NONE) {
        return e;
    }

    cteInsert(cap, slot, rootSlot);

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return EXCEPTION_NONE;
}

exception_t decodeSetEPTRoot(cap_t cap, extra_caps_t excaps)
{
    cap_t rootCap;
    cte_t *rootSlot;
    deriveCap_ret_t dc_ret;

    rootSlot = excaps.excaprefs[0];

    if (rootSlot == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 60, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetEPTRoot: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    rootCap = rootSlot->cap;

    if (cap_get_capType(rootCap) != cap_ept_pml4_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 68, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetEPTRoot: EPT PDPT is invalid."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    dc_ret = deriveCap(rootSlot, rootCap);
    if (dc_ret.status != EXCEPTION_NONE) {
        return dc_ret.status;
    }

    if (!cap_ept_pml4_cap_get_capPML4IsMapped(dc_ret.cap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 79, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("decodeSetEPTRoot: Invalid EPT cap."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    return performSetEPTRoot(((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), dc_ret.cap, rootSlot);
}



void
Arch_migrateTCB(tcb_t *thread)
{

    if (nativeThreadUsingFPU(thread)) {
        switchFpuOwner(((void *)0), thread->tcbAffinity);
    }
}


void
Arch_setTCBIPCBuffer(tcb_t *thread, word_t bufferAddr)
{
}










const vcpu_gp_register_t crExitRegs[] = {
    VCPU_EAX, VCPU_ECX, VCPU_EDX, VCPU_EBX, VCPU_ESP, VCPU_EBP, VCPU_ESI, VCPU_EDI
};

typedef struct msr_bitmap {
    word_t bitmap[0x2000 / sizeof(word_t) / 8];
} msr_bitmap_t;

typedef struct msr_bitmaps {
    msr_bitmap_t low_msr_read;
    msr_bitmap_t high_msr_read;
    msr_bitmap_t low_msr_write;
    msr_bitmap_t high_msr_write;
} msr_bitmaps_t;

static struct __attribute__((packed)) {
    uint32_t revision;
    char data[4096 - sizeof(uint32_t)];
} vmxon_region __attribute__((__aligned__(4096)));

static msr_bitmaps_t msr_bitmap_region __attribute__((__aligned__((1ul << (12)))));

static char null_ept_space[12] __attribute__((__aligned__((1ul << (12)))));


static uint32_t vmcs_revision;


static vmx_ept_vpid_cap_msr_t vpid_capability;



static uint32_t pin_control_high;
static uint32_t pin_control_low;
static uint32_t primary_control_high;
static uint32_t primary_control_low;
static uint32_t secondary_control_high;
static uint32_t secondary_control_low;
static uint32_t entry_control_high;
static uint32_t entry_control_low;
static uint32_t exit_control_high;
static uint32_t exit_control_low;
static uint32_t cr0_high;
static uint32_t cr0_low;
static uint32_t cr4_high;
static uint32_t cr4_low;



static bool_t vmx_feature_vpid;
static bool_t vmx_feature_load_perf_global_ctrl;
static bool_t vmx_feature_ack_on_exit;

static vcpu_t *x86KSVPIDTable[(64 - 1) + 1];
static vpid_t x86KSNextVPID = 1;

static void
setMRs_vmexit(uint32_t reason, word_t qualification, tcb_t *tcb);

static inline bool_t
vmxon(paddr_t vmxon_region)
{
    uint8_t error;


    uint64_t vmxonreg = vmxon_region;
    __asm__ volatile(
        "vmxon %1; setnae %0"
        : "=q"(error)
        : "m"(vmxonreg)
        : "memory", "cc"
    );
    return !!error;
}

static void
vmclear(void *vmcs_ptr)
{
    uint64_t physical_address;
    physical_address = addrFromPPtr((void*)vmcs_ptr);
    __asm__ volatile (
        "vmclear %0"
        :
        : "m"(physical_address)
        : "cc"
    );
}

void
clearCurrentVCPU(void)
{
    vcpu_t *vcpu = ksSMP[(getCurrentCPUIndex())].cpu.x86KSCurrentVCPU;
    if (vcpu) {
        vmclear(vcpu);
        vcpu->launched = false;
        ksSMP[(getCurrentCPUIndex())].cpu.x86KSCurrentVCPU = ((void *)0);
    }
}

static void
vmptrld(void *vmcs_ptr)
{
    uint64_t physical_address;
    uint8_t error;
    physical_address = addrFromPPtr(vmcs_ptr);
    __asm__ volatile (
        "vmptrld %1; setna %0"
        : "=q"(error)
        : "m"(physical_address)
        : "cc"
    );



    if(!(!error)) _assert_fail("!error", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/vcpu.c", 149, __FUNCTION__);
}

static void
switchVCPU(vcpu_t *vcpu)
{

    if (vcpu->last_cpu != getCurrentCPUIndex() && ksSMP[(vcpu->last_cpu)].cpu.x86KSCurrentVCPU == vcpu) {

        doRemoteClearCurrentVCPU(vcpu->last_cpu);
    }

    clearCurrentVCPU();
    vmptrld(vcpu);

    if (vcpu->last_cpu != getCurrentCPUIndex()) {

        vmwrite(0x00006C0A, (word_t)&x86KSGlobalState[getCurrentCPUIndex()].x86KStss);
        vmwrite(0x00006C0C, (word_t)x86KSGlobalState[getCurrentCPUIndex()].x86KSgdt);
        vmwrite(0x00006C0E, (word_t)x86KSGlobalState[getCurrentCPUIndex()].x86KSidt);
        vmwrite(0x00006C10, (uint64_t)(word_t)((char *)&x86KSGlobalState[getCurrentCPUIndex()].x86KStss.tss.words[0] + 4));
    }
    vcpu->last_cpu = getCurrentCPUIndex();

    ksSMP[(getCurrentCPUIndex())].cpu.x86KSCurrentVCPU = vcpu;
}

static void
print_bits(word_t bits)
{
    bool_t first = true;
    while (bits) {
        int index = 64 - 1 - clzl(bits);
        if (first) {
            kprintf("%d", index);
            first = false;
        } else {
            kprintf(",%d", index);
        }
        bits &= ~(1ul << (index));
    }
}

static bool_t
check_fixed_value(word_t val, word_t low, word_t high)
{
    word_t not_high;
    word_t not_low;
    not_high = high & ~(high & val);
    if (not_high != 0) {
        kprintf("Failed to set bits: ");
        print_bits(not_high);
        return false;
    }


    not_low = ~low & ~(~low & ~val);
    if (not_low != 0) {
        kprintf("Incorrectly cleared bits: ");
        print_bits(not_low);
        return false;
    }
    return true;
}

static bool_t
vtx_check_fixed_values(word_t cr0, word_t cr4)
{
    if (!check_fixed_value(cr0, cr0_low, cr0_high)) {
        kprintf(" of CR0\n");
        return false;
    }
    if (!check_fixed_value(cr4, cr4_low, cr4_high)) {
        kprintf(" of CR4\n");
        return false;
    }
    return true;
}

static bool_t __attribute__((__section__(".boot.text")))
init_vtx_fixed_values(bool_t useTrueMsrs)
{
    uint32_t pin_control_mask =
        (1ul << (0)) |
        (1ul << (3)) |
        (1ul << (5));
    uint32_t primary_control_mask =
        (1ul << (25)) |
        (1ul << (28)) |
        (1ul << (31));
    uint32_t secondary_control_mask =
        (1ul << (1));
    uint32_t exit_control_mask =
        (1ul << (2)) |
        (1ul << (18)) |
        (1ul << (19)) |
        (1ul << (20)) |
        (1ul << (21));

    exit_control_mask |= (1ul << (9));


    uint32_t pinbased_ctls;
    uint32_t procbased_ctls;
    uint32_t exit_ctls;
    uint32_t entry_ctls;
    if (useTrueMsrs) {
        pinbased_ctls = 0x48D;
        procbased_ctls = 0x48E;
        exit_ctls = 0x48F;
        entry_ctls = 0x490;
    } else {
        pinbased_ctls = 0x481;
        procbased_ctls = 0x482;
        exit_ctls = 0x483;
        entry_ctls = 0x484;
    }
    pin_control_high = x86_rdmsr_low(pinbased_ctls);
    pin_control_low = x86_rdmsr_high(pinbased_ctls);
    primary_control_high = x86_rdmsr_low(procbased_ctls);
    primary_control_low = x86_rdmsr_high(procbased_ctls);
    secondary_control_high = x86_rdmsr_low(0x48B);
    secondary_control_low = x86_rdmsr_high(0x48B);
    exit_control_high = x86_rdmsr_low(exit_ctls);
    exit_control_low = x86_rdmsr_high(exit_ctls);
    entry_control_high = x86_rdmsr_low(entry_ctls);
    entry_control_low = x86_rdmsr_high(entry_ctls);

    cr0_high = x86_rdmsr_low(0x486);
    cr0_low = x86_rdmsr_low(0x487);
    cr4_high = x86_rdmsr_low(0x488);
    cr4_low = x86_rdmsr_low(0x489);



        vmx_feature_vpid = 0;
        kprintf("vt-x: VPIDs are not supported. Expect performance degredation\n");






    if (!(exit_control_low & (1ul << (12)))) {
        vmx_feature_load_perf_global_ctrl = 0;
        kprintf("vt-x: Load IA32_PERF_GLOBAL_CONTROL not supported. Hardware debugging may not work\n");
    } else {
        vmx_feature_load_perf_global_ctrl = 1;
        exit_control_mask |= (1ul << (12));
    }


    if (!(exit_control_low & (1ul << (15)))) {
        vmx_feature_ack_on_exit = 0;
        kprintf("vt-x: Interrupt ack on exit not supported. Expect performance degredation\n");
    } else {
        vmx_feature_ack_on_exit = 1;
        exit_control_mask |= (1ul << (15));
    }


    uint32_t missing;
    missing = (~pin_control_low) & pin_control_mask;
    if (missing) {
        kprintf("vt-x: Unsupported pin control features %lx\n", (long)missing);
        return false;
    }
    missing = (~primary_control_low) & primary_control_mask;
    if (missing) {
        kprintf("vt-x: Unsupported primary control features %lx\n", (long)missing);
        return false;
    }
    missing = (~secondary_control_low) & secondary_control_mask;
    if (missing) {
        kprintf("vt-x: Unsupported secondary control features %lx\n", (long)missing);
        return false;
    }
    missing = (~exit_control_low) & exit_control_mask;
    if (missing) {
        kprintf("vt-x: Unsupported exit control features %lx\n", (long)missing);
        return false;
    }


    pin_control_high |= pin_control_mask;
    primary_control_high |= primary_control_mask;
    secondary_control_high |= secondary_control_mask;
    exit_control_high |= exit_control_mask;

    entry_control_high |= (1ul << (15));
    return true;
}

static bool_t __attribute__((__section__(".boot.text")))
check_vtx_fixed_values(bool_t useTrueMsrs)
{
    uint32_t pinbased_ctls;
    uint32_t procbased_ctls;
    uint32_t exit_ctls;
    uint32_t entry_ctls;
    if (useTrueMsrs) {
        pinbased_ctls = 0x48D;
        procbased_ctls = 0x48E;
        exit_ctls = 0x48F;
        entry_ctls = 0x490;
    } else {
        pinbased_ctls = 0x481;
        procbased_ctls = 0x482;
        exit_ctls = 0x483;
        entry_ctls = 0x484;
    }
    uint32_t local_pin_control_high = x86_rdmsr_low(pinbased_ctls);
    uint32_t local_pin_control_low = x86_rdmsr_high(pinbased_ctls);
    uint32_t local_primary_control_high = x86_rdmsr_low(procbased_ctls);
    uint32_t local_primary_control_low = x86_rdmsr_high(procbased_ctls);
    uint32_t local_secondary_control_high = x86_rdmsr_low(0x48B);
    uint32_t local_secondary_control_low = x86_rdmsr_high(0x48B);
    uint32_t local_exit_control_high = x86_rdmsr_low(exit_ctls);
    uint32_t local_exit_control_low = x86_rdmsr_high(exit_ctls);
    uint32_t local_entry_control_high = x86_rdmsr_low(entry_ctls);
    uint32_t local_entry_control_low = x86_rdmsr_high(entry_ctls);

    uint32_t local_cr0_high = x86_rdmsr_low(0x486);
    uint32_t local_cr0_low = x86_rdmsr_low(0x487);
    uint32_t local_cr4_high = x86_rdmsr_low(0x488);
    uint32_t local_cr4_low = x86_rdmsr_low(0x489);


    if (secondary_control_low & (1ul << (7))) {
        local_secondary_control_high &= (1ul << (7));
        local_cr0_high &= ~((1ul << (31)) | (1ul << (0)));
    }
    return
        (local_pin_control_high & pin_control_high) == local_pin_control_high &&
        (~local_pin_control_low & pin_control_high) == 0 &&
        (local_primary_control_high & primary_control_high) == local_primary_control_high &&
        (~local_primary_control_low & primary_control_high) == 0 &&
        (local_secondary_control_high & secondary_control_high) == local_secondary_control_high &&
        (~local_secondary_control_low & secondary_control_high) == 0 &&
        (local_exit_control_high & exit_control_high) == local_exit_control_high &&
        (~local_exit_control_low & exit_control_high) == 0 &&
        (local_entry_control_high & entry_control_high) == local_entry_control_high &&
        (~local_entry_control_low & entry_control_high) == 0 &&
        local_cr0_high == cr0_high &&
        local_cr0_low == cr0_low &&
        local_cr4_high == cr4_high &&
        local_cr4_low == cr4_low;
}

static inline uint32_t
applyFixedBits(uint32_t original, uint32_t high, uint32_t low)
{
    original |= high;
    original &= low;
    return original;
}

static bool_t vcpu_support_available = false;

bool_t
vcpu_init(vcpu_t *vcpu)
{
    if (!vcpu_support_available)
        return false;

    vcpu->vcpuTCB = ((void *)0);
    vcpu->launched = false;

    memcpy(vcpu->vmcs, &vmcs_revision, 4);

    switchVCPU(vcpu);

    vcpu->cr0 = cr0_high & cr0_low;
    vcpu->cr0_shadow = 0;
    vcpu->cr0_mask = 0;
    vcpu->exception_bitmap = 0;
    vcpu->vpid = 0;

    vcpu->last_cpu = getCurrentCPUIndex();


    vmwrite(0x00002C00, x86_rdmsr(0x277));
    vmwrite(0x00002C02, x86_rdmsr(0xC0000080));



    if (vmx_feature_load_perf_global_ctrl) {
        vmwrite(0x00002C04, 0);
    }
    vmwrite(0x00006C00, read_cr0());
    vmwrite(0x00006C04, read_cr4());
    vmwrite(0x00006C06, 0);
    vmwrite(0x00006C08, 0);
    vmwrite(0x00006C0A, (word_t)&x86KSGlobalState[getCurrentCPUIndex()].x86KStss);
    vmwrite(0x00006C0C, (word_t)x86KSGlobalState[getCurrentCPUIndex()].x86KSgdt);
    vmwrite(0x00006C0E, (word_t)x86KSGlobalState[getCurrentCPUIndex()].x86KSidt);
    vmwrite(0x00004C00, (word_t)(1 << 3));
    vmwrite(0x00006C12, (word_t)&handle_syscall);
    if (!0) {
        vmwrite(0x00006C10, (uint64_t)(word_t)((char *)&x86KSGlobalState[getCurrentCPUIndex()].x86KStss.tss.words[0] + 4));
    }

    vmwrite(0x00006C14, (word_t)&vcpu->gp_registers[n_vcpu_gp_register]);
    vmwrite(0x00006C16, (word_t)&handle_vmexit);






    vmwrite(0x00000C00, (2 << 3));
    vmwrite(0x00000C02, (1 << 3));
    vmwrite(0x00000C04, (2 << 3));
    vmwrite(0x00000C06, (2 << 3));
    vmwrite(0x00000C08, 0);
    vmwrite(0x00000C0A, 0);
    vmwrite(0x00000C0C, (3 << 3));


    vmwrite(0x00004000, pin_control_high & pin_control_low);
    vmwrite(0x00004002, primary_control_high & primary_control_low);
    vmwrite(0x0000401E, secondary_control_high & secondary_control_low);
    vmwrite(0x0000400C, exit_control_high & exit_control_low);
    vmwrite(0x00004012, entry_control_high & entry_control_low);
    vmwrite(0x00002004, (word_t)kpptr_to_paddr(&msr_bitmap_region));
    vmwrite(0x00006800, vcpu->cr0);
    vmwrite(0x00006804, cr4_high & cr4_low);

    vmwrite(0x00002800, ~(word_t)0);
    vmwrite(0x00002801, ~(word_t)0);

    memset(vcpu->io, ~(word_t)0, 8192);
    vmwrite(0x00002000, addrFromPPtr(vcpu->io));
    vmwrite(0x00002002, addrFromPPtr((char *)vcpu->io + (8192 / 2)));

    return true;
}

static void
dissociateVcpuTcb(tcb_t *tcb, vcpu_t *vcpu)
{
    if(!(tcb->tcbArch.tcbVCPU == vcpu)) _assert_fail("tcb->tcbArch.tcbVCPU == vcpu", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/vcpu.c", 506, __FUNCTION__);
    if(!(vcpu->vcpuTCB == tcb)) _assert_fail("vcpu->vcpuTCB == tcb", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/vcpu.c", 507, __FUNCTION__);
    tcb->tcbArch.tcbVCPU = ((void *)0);
    vcpu->vcpuTCB = ((void *)0);
}

void
vcpu_finalise(vcpu_t *vcpu)
{
    if (vcpu->vcpuTCB) {
        dissociateVcpuTcb(vcpu->vcpuTCB, vcpu);
    }
    if (ksSMP[(vcpu->last_cpu)].cpu.x86KSCurrentVCPU == vcpu) {

        if (vcpu->last_cpu == getCurrentCPUIndex()) {
            doRemoteClearCurrentVCPU(vcpu->last_cpu);
        } else

        {
            clearCurrentVCPU();
        }
    }
}

static void
associateVcpuTcb(tcb_t *tcb, vcpu_t *vcpu)
{
    if (tcb->tcbArch.tcbVCPU) {
        dissociateVcpuTcb(tcb, tcb->tcbArch.tcbVCPU);
    }
    if (vcpu->vcpuTCB) {
        dissociateVcpuTcb(vcpu->vcpuTCB, vcpu);
    }
    vcpu->vcpuTCB = tcb;
    tcb->tcbArch.tcbVCPU = vcpu;
}

static exception_t
invokeVCPUWriteRegisters(vcpu_t *vcpu, word_t *buffer)
{
    int i;
    for (i = 0; i < n_vcpu_gp_register; i++) {
        vcpu->gp_registers[i] = getSyscallArg(i, buffer);
    }
    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return EXCEPTION_NONE;
}

static exception_t
decodeVCPUWriteRegisters(cap_t cap, word_t length, word_t *buffer)
{
    if (length < 7) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 558, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU WriteRegisters: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }
    return invokeVCPUWriteRegisters(((vcpu_t *)(cap_vcpu_cap_get_capVCPUPtr(cap))), buffer);
}

static void
performSetIOPortMask(vcpu_t *vcpu, uint16_t low, uint16_t high, int mask)
{
    while (low <= high) {
        int low_word = low / 64;
        int low_index = low % 64;
        int high_word = high / 64;

        if (low_index == 0 && low_word != high_word) {
            vcpu->io[low_word] = mask ? ~(word_t)0 : 0;
            low += 64;
        } else {
            if (mask) {
                vcpu->io[low_word] |= (1ul << (low_index));
            } else {
                vcpu->io[low_word] &= ~(1ul << (low_index));
            }
            low++;
        }
    }
}

static exception_t
invokeEnableIOPort(vcpu_t *vcpu, cte_t *slot, cap_t cap, uint16_t low, uint16_t high)
{

    clearVPIDIOPortMappings(cap_io_port_cap_get_capIOPortVPID(cap),
                            cap_io_port_cap_get_capIOPortFirstPort(cap),
                            cap_io_port_cap_get_capIOPortLastPort(cap));



    cap = cap_io_port_cap_set_capIOPortVPID(cap, vcpu->vpid);
    slot->cap = cap;
    performSetIOPortMask(vcpu, low, high, 0);
    return EXCEPTION_NONE;
}

static exception_t
decodeEnableIOPort(cap_t cap, word_t length, word_t* buffer, extra_caps_t excaps)
{
    vcpu_t *vcpu;
    cap_t ioCap;
    cte_t *ioSlot;
    uint16_t low, high;

    if (length < 2) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 612, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU EnableIOPort: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 617, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU EnableIOPort: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }
    ioSlot = excaps.excaprefs[0];
    ioCap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(ioCap) != cap_io_port_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 625, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU EnableIOPort: IOPort cap is not a IOPort cap."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    low = getSyscallArg(0, buffer);
    high = getSyscallArg(1, buffer);

    if (low < cap_io_port_cap_get_capIOPortFirstPort(ioCap) || high > cap_io_port_cap_get_capIOPortLastPort(ioCap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 634, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU EnableIOPort: Requested range not valid for given IOPort cap"); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 0;
        return EXCEPTION_SYSCALL_ERROR;
    }

    vcpu = ((vcpu_t *)(cap_vcpu_cap_get_capVCPUPtr(cap)));

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeEnableIOPort(vcpu, ioSlot, ioCap, low, high);
}

static exception_t
invokeDisableIOPort(vcpu_t *vcpu, uint16_t low, uint16_t high)
{
    performSetIOPortMask(vcpu, low, high, 1);
    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return EXCEPTION_NONE;
}

static exception_t
decodeDisableIOPort(cap_t cap, word_t length, word_t* buffer)
{
    vcpu_t *vcpu;
    uint16_t low, high;

    if (length < 2) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 661, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU EnableIOPort: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    low = getSyscallArg(0, buffer);
    high = getSyscallArg(1, buffer);

    vcpu = ((vcpu_t *)(cap_vcpu_cap_get_capVCPUPtr(cap)));

    return invokeDisableIOPort(vcpu, low, high);
}

static exception_t
invokeWriteVMCS(vcpu_t *vcpu, word_t *buffer, word_t field, word_t value)
{
    tcb_t *thread;
    thread = ksSMP[(getCurrentCPUIndex())].system.ksCurThread;
    if (ksSMP[(getCurrentCPUIndex())].cpu.x86KSCurrentVCPU != vcpu) {
        switchVCPU(vcpu);
    }
    switch (field) {
    case 0x00004004:
        vcpu->exception_bitmap = vcpu->cached_exception_bitmap = value;
        break;
    case 0x00006800:
        vcpu->cr0 = vcpu->cached_cr0 = value;
        break;
    case 0x00006000:
        vcpu->cr0_mask = vcpu->cached_cr0_mask = value;
        break;
    case 0x00006004:
        vcpu->cr0_shadow = vcpu->cached_cr0_shadow = value;
        break;
    }
    setMR(thread, buffer, 0, value);
    vmwrite(field, value);
    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return EXCEPTION_NONE;
}

static exception_t
decodeWriteVMCS(cap_t cap, word_t length, word_t* buffer)
{
    word_t field;
    word_t value;

    if (length < 2) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 709, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU WriteVMCS: Not enough arguments."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    field = getSyscallArg(0, buffer);
    value = getSyscallArg(1, buffer);
    switch (field) {
    case 0x0000681E:
    case 0x0000681C:
    case 0x00000800:
    case 0x00000802:
    case 0x00000804:
    case 0x00000806:
    case 0x00000808:
    case 0x0000080A:
    case 0x0000080C:
    case 0x0000080E:
    case 0x00002802:
    case 0x00002804:
    case 0x00002806:
    case 0x00002808:
    case 0x0000280A:
    case 0x0000280C:
    case 0x0000280E:
    case 0x00002810:
    case 0x00004800:
    case 0x00004802:
    case 0x00004804:
    case 0x00004806:
    case 0x00004808:
    case 0x0000480A:
    case 0x0000480C:
    case 0x0000480E:
    case 0x00004810:
    case 0x00004812:
    case 0x00004814:
    case 0x00004816:
    case 0x00004818:
    case 0x0000481A:
    case 0x0000481C:
    case 0x0000481E:
    case 0x00004820:
    case 0x00004822:
    case 0x00004824:
    case 0x00004826:
    case 0x00004828:
    case 0x0000482A:
    case 0x0000482E:
    case 0x00006806:
    case 0x00006808:
    case 0x0000680A:
    case 0x0000680C:
    case 0x0000680E:
    case 0x00006810:
    case 0x00006812:
    case 0x00006814:
    case 0x00006816:
    case 0x00006818:
    case 0x0000681A:
    case 0x00006820:
    case 0x00006822:
    case 0x00006824:
    case 0x00006826:
    case 0x00006000:
    case 0x00006002:
    case 0x00006004:
    case 0x00006006:
    case 0x00006802:
    case 0x00004004:
    case 0x00004016:
    case 0x00004018:
    case 0x0000401A:
        break;
    case 0x00004000:
        value = applyFixedBits(value, pin_control_high, pin_control_low);
        break;
    case 0x00004002:
        value = applyFixedBits(value, primary_control_high, primary_control_low);
        break;
    case 0x0000401E:
        value = applyFixedBits(value, secondary_control_high, secondary_control_low);
        break;
    case 0x0000400C:
        value = applyFixedBits(value, exit_control_high, exit_control_low);
        break;
    case 0x00006800:
        value = applyFixedBits(value, cr0_high, cr0_low);
        break;
    case 0x00006804:
        value = applyFixedBits(value, cr4_high, cr4_low);
        break;
    default:
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 802, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU WriteVMCS: Invalid field %lx.", (long)field); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
    return invokeWriteVMCS(((vcpu_t *)(cap_vcpu_cap_get_capVCPUPtr(cap))), buffer, field, value);
}

static word_t readVMCSField(vcpu_t *vcpu, word_t field)
{
    switch (field) {
    case 0x00004004:
        return vcpu->exception_bitmap;
    case 0x00006800:
        return vcpu->cr0;
    case 0x00006000:
        return vcpu->cr0_mask;
    case 0x00006004:
        return vcpu->cr0_shadow;
    }
    if (ksSMP[(getCurrentCPUIndex())].cpu.x86KSCurrentVCPU != vcpu) {
        switchVCPU(vcpu);
    }
    return vmread(field);
}

static exception_t
invokeReadVMCS(vcpu_t *vcpu, word_t field, word_t *buffer)
{
    tcb_t *thread;
    thread = ksSMP[(getCurrentCPUIndex())].system.ksCurThread;

    setMR(thread, buffer, 0, readVMCSField(vcpu, field));
    setRegister(thread, msgInfoRegister, wordFromMessageInfo(
                    seL4_MessageInfo_new(0, 0, 0, 1)));
    setThreadState(thread, ThreadState_Restart);
    return EXCEPTION_NONE;
}

static exception_t
decodeReadVMCS(cap_t cap, word_t length, word_t* buffer)
{
    if (length < 1) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 844, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU ReadVMCS: Not enough arguments."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
    word_t field = getSyscallArg(0, buffer);
    switch (field) {
    case 0x0000681E:
    case 0x0000681C:
    case 0x00000800:
    case 0x00000802:
    case 0x00000804:
    case 0x00000806:
    case 0x00000808:
    case 0x0000080A:
    case 0x0000080C:
    case 0x0000080E:
    case 0x00002802:
    case 0x00002804:
    case 0x00002806:
    case 0x00002808:
    case 0x0000280A:
    case 0x0000280C:
    case 0x0000280E:
    case 0x00002810:
    case 0x00004800:
    case 0x00004802:
    case 0x00004804:
    case 0x00004806:
    case 0x00004808:
    case 0x0000480A:
    case 0x0000480C:
    case 0x0000480E:
    case 0x00004810:
    case 0x00004812:
    case 0x00004814:
    case 0x00004816:
    case 0x00004818:
    case 0x0000481A:
    case 0x0000481C:
    case 0x0000481E:
    case 0x00004820:
    case 0x00004822:
    case 0x00004824:
    case 0x00004826:
    case 0x00004828:
    case 0x0000482A:
    case 0x0000482E:
    case 0x00006806:
    case 0x00006808:
    case 0x0000680A:
    case 0x0000680C:
    case 0x0000680E:
    case 0x00006810:
    case 0x00006812:
    case 0x00006814:
    case 0x00006816:
    case 0x00006818:
    case 0x0000681A:
    case 0x00006820:
    case 0x00006822:
    case 0x00006824:
    case 0x00006826:
    case 0x00006000:
    case 0x00006002:
    case 0x00006004:
    case 0x00006006:
    case 0x00004400:
    case 0x00004404:
    case 0x00004406:
    case 0x00004408:
    case 0x0000440A:
    case 0x0000440C:
    case 0x0000440E:
    case 0x00002400:
    case 0x00006402:
    case 0x00006404:
    case 0x00006406:
    case 0x00006408:
    case 0x0000640A:
    case 0x00004016:
    case 0x00004000:
    case 0x00004002:
    case 0x00004004:
    case 0x0000400C:
    case 0x00006800:
    case 0x00006802:
    case 0x00006804:
    case 0x00004018:
        break;
    default:
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 934, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU ReadVMCS: Invalid field %lx.", (long)field); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
    return invokeReadVMCS(((vcpu_t *)(cap_vcpu_cap_get_capVCPUPtr(cap))), field, buffer);
}

static exception_t
invokeSetTCB(vcpu_t *vcpu, tcb_t *tcb)
{
    associateVcpuTcb(tcb, vcpu);

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return EXCEPTION_NONE;
}

static exception_t
decodeSetTCB(cap_t cap, word_t length, word_t* buffer, extra_caps_t excaps)
{
    cap_t tcbCap;
    if ( excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 955, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU SetTCB: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }
    tcbCap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(tcbCap) != cap_thread_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 962, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB cap is not a TCB cap."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    return invokeSetTCB(((vcpu_t *)(cap_vcpu_cap_get_capVCPUPtr(cap))), ((tcb_t *)(cap_thread_cap_get_capTCBPtr(tcbCap))));
}

void
vcpu_update_state_sysvmenter(vcpu_t *vcpu)
{
    word_t *buffer;
    if (ksSMP[(getCurrentCPUIndex())].cpu.x86KSCurrentVCPU != vcpu) {
        switchVCPU(vcpu);
    }
    buffer = lookupIPCBuffer(false, ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
    if (!buffer) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 979, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("No IPC buffer."); kprintf(">>" "" "\n"); } while (0);
        return;
    }
    vmwrite(0x0000681E, getSyscallArg(0, buffer));
    vmwrite(0x00004002, applyFixedBits(getSyscallArg(1, buffer), primary_control_high, primary_control_low));
    vmwrite(0x00004016, getSyscallArg(2, buffer));
}

void
vcpu_sysvmenter_reply_to_user(tcb_t *tcb)
{
    vcpu_t *vcpu;

    vcpu = tcb->tcbArch.tcbVCPU;

    if(!(vcpu)) _assert_fail("vcpu", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/vcpu.c", 994, __FUNCTION__);

    if (ksSMP[(getCurrentCPUIndex())].cpu.x86KSCurrentVCPU != vcpu) {
        switchVCPU(vcpu);
    }

    setMRs_vmexit( -1, -1, tcb);

    setRegister(tcb, msgInfoRegister, 0 );
}

exception_t
decodeX86VCPUInvocation(
    word_t invLabel,
    word_t length,
    cptr_t cptr,
    cte_t* slot,
    cap_t cap,
    extra_caps_t excaps,
    word_t* buffer
)
{
    switch (invLabel) {
    case X86VCPUSetTCB:
        return decodeSetTCB(cap, length, buffer, excaps);
    case X86VCPUReadVMCS:
        return decodeReadVMCS(cap, length, buffer);
    case X86VCPUWriteVMCS:
        return decodeWriteVMCS(cap, length, buffer);
    case X86VCPUEnableIOPort:
        return decodeEnableIOPort(cap, length, buffer, excaps);
    case X86VCPUDisableIOPort:
        return decodeDisableIOPort(cap, length, buffer);
    case X86VCPUWriteRegisters:
        return decodeVCPUWriteRegisters(cap, length, buffer);
    default:
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1030, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("VCPU: Illegal operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
}

static bool_t
is_vtx_supported(void)
{


    return !!(x86_cpuid_ecx(0x1, 0) & (1ul << (5)));
}

static inline void
clear_bit(word_t *bitmap, word_t bit)
{
    int index = bit / (sizeof(word_t) * 8);
    int offset = bit % (sizeof(word_t) * 8);
    bitmap[index] &= ~(1ul << (offset));
}

__attribute__((__section__(".boot.text"))) bool_t
vtx_init(void)
{
    if (!is_vtx_supported()) {
        kprintf("vt-x: not supported\n");
        return false;
    }
    vmx_basic_msr_t vmx_basic;
    feature_control_msr_t feature_control;
    vmx_basic.words[0] = x86_rdmsr_low(0x480);
    vmx_basic.words[1] = x86_rdmsr_high(0x480);
    vmcs_revision = vmx_basic_msr_get_vmcs_revision(vmx_basic);
    feature_control.words[0] = x86_rdmsr_low(0x3A);
    if (!feature_control_msr_get_vmx_outside_smx(feature_control)) {

        if (feature_control_msr_get_lock(feature_control)) {
            kprintf("vt-x: feature locked\n");
            return false;
        }
        feature_control = feature_control_msr_set_vmx_outside_smx(feature_control, 1);
        x86_wrmsr_parts(0x3A, x86_rdmsr_high(0x3A), feature_control.words[0]);
    }

    if (!feature_control_msr_get_lock(feature_control)) {
        feature_control = feature_control_msr_set_lock(feature_control, 1);
        x86_wrmsr_parts(0x3A, x86_rdmsr_high(0x3A), feature_control.words[0]);
    }


    if (getCurrentCPUIndex() == 0) {
        if (!init_vtx_fixed_values(vmx_basic_msr_get_true_msrs(vmx_basic))) {
            kprintf("vt-x: lack of required features\n");
            return false;
        }


        if (secondary_control_low & (1ul << (7))) {
            secondary_control_high |= (1ul << (7));
            cr0_high &= ~((1ul << (31)) | (1ul << (0)));
        }


        if (secondary_control_low & (1ul << (7))) {
            secondary_control_high |= (1ul << (7));
            cr0_high &= ~((1ul << (31)) | (1ul << (0)));
        }
    }
    if (!check_vtx_fixed_values(vmx_basic_msr_get_true_msrs(vmx_basic))) {
        kprintf("vt-x: cores have inconsistent features\n");
        return false;
    }
    write_cr4(read_cr4() | (1ul << (13)) );

    vmxon_region.revision = vmcs_revision;


    if (!vtx_check_fixed_values(read_cr0(), read_cr4())) {
        return false;
    }
    if (vmxon(kpptr_to_paddr(&vmxon_region))) {
        kprintf("vt-x: vmxon failure\n");
        return false;
    }
    memset(&msr_bitmap_region, ~0, sizeof(msr_bitmap_region));

    clear_bit(msr_bitmap_region.low_msr_read.bitmap, 0x174);
    clear_bit(msr_bitmap_region.low_msr_read.bitmap, 0x175);
    clear_bit(msr_bitmap_region.low_msr_read.bitmap, 0x176);
    clear_bit(msr_bitmap_region.low_msr_write.bitmap, 0x174);
    clear_bit(msr_bitmap_region.low_msr_write.bitmap, 0x175);
    clear_bit(msr_bitmap_region.low_msr_write.bitmap, 0x176);




    vpid_capability.words[0] = x86_rdmsr_low(0x48C);
    vpid_capability.words[1] = x86_rdmsr_high(0x48C);


    if (!vmx_ept_vpid_cap_msr_get_ept_wb(vpid_capability)) {
        kprintf("vt-x: Expected wb attribute for EPT paging structure\n");
        return false;
    }
    if (!vmx_ept_vpid_cap_msr_get_ept_2m(vpid_capability)) {
        kprintf("vt-x: Expected supported for 2m pages\n");
        return false;
    }

    vcpu_support_available = true;

    return true;
}

static void
setMRs_vmexit(uint32_t reason, word_t qualification, tcb_t *tcb)
{
    word_t *buffer;
    int i;

    buffer = lookupIPCBuffer(true, tcb);

    setMR(tcb, buffer, 0, vmread(0x0000681E));
    setMR(tcb, buffer, 1, vmread(0x00004002));
    setMR(tcb, buffer, 2, vmread(0x00004016));
    setMR(tcb, buffer, 3, reason);
    setMR(tcb, buffer, 4, qualification);

    setMR(tcb, buffer, 5, vmread(0x0000440C));
    setMR(tcb, buffer, 6, vmread(0x00002400));
    setMR(tcb, buffer, 7, vmread(0x00006820));
    setMR(tcb, buffer, 8, vmread(0x00004824));
    setMR(tcb, buffer, 9, vmread(0x00006802));

    for (i = 0; i < n_vcpu_gp_register; i++) {
        setMR(tcb, buffer, 10 + i, tcb->tcbArch.tcbVCPU->gp_registers[i]);
    }
}

static void
handleVmxFault(uint32_t reason, word_t qualification)
{

    setRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, msgInfoRegister, 1);

    setMRs_vmexit(reason, qualification, ksSMP[(getCurrentCPUIndex())].system.ksCurThread);


    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Running);



    activateThread();
}

static inline void
finishVmexitSaving(void)
{
    vcpu_t *vcpu = ksSMP[(getCurrentCPUIndex())].cpu.x86KSCurrentVCPU;
    if(!(vcpu == ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU)) _assert_fail("vcpu == NODE_STATE(ksCurThread)->tcbArch.tcbVCPU", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/vcpu.c", 1190, __FUNCTION__);
    vcpu->launched = true;


    vcpu->cached_cr0 = vmread(0x00006800);
    if (vcpuThreadUsingFPU(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)) {



        vcpu->cr0 = vcpu->cached_cr0;
    } else {







        vcpu->cr0 = (vcpu->cached_cr0 & ~(1ul << (3)) ) | (ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->cr0 & (1ul << (3)) );
    }
}

exception_t
handleVmexit(void)
{
    uint32_t interrupt;

    word_t qualification;
    uint32_t reason;
    finishVmexitSaving();

    reason = vmread(0x00004402) & ((1ul << (16))-1ul);
    if (reason == EXTERNAL_INTERRUPT) {
        if (vmx_feature_ack_on_exit) {
            interrupt = vmread(0x00004404);
            ksSMP[(getCurrentCPUIndex())].cpu.x86KScurInterrupt = interrupt & 0xff;
            do { if((interrupt != int_remote_call_ipi)) { do { clh_lock_acquire(getCurrentCPUIndex(), true); } while(0); } } while(0);
            handleInterruptEntry();
        } else {


            receivePendingIRQ();
        }
        return EXCEPTION_NONE;
    }

    do { clh_lock_acquire(getCurrentCPUIndex(), false); } while(0);

    if (!vcpuThreadUsingFPU(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)) {





        if (reason == EXCEPTION_OR_NMI && !(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->exception_bitmap & (1ul << (int_unimpl_dev)))) {
            interrupt = vmread(0x00004404);

            if ((interrupt & 0xff) == int_unimpl_dev) {
                switchLocalFpuOwner(&ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->fpuState);
                return EXCEPTION_NONE;
            }
        } else if (reason == CONTROL_REGISTER && !(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->cr0_mask & (1ul << (3)) )) {







            qualification = vmread(0x00006400);
            vmx_data_exit_qualification_control_regster_t qual;
            qual.words[0] = qualification;


            switch (vmx_data_exit_qualification_control_regster_get_access_type(qual)) {
            case 0: {

                if (vmx_data_exit_qualification_control_regster_get_cr(qual) == 0) {
                    vcpu_gp_register_t source = crExitRegs[vmx_data_exit_qualification_control_regster_get_reg(qual)];
                    word_t value;
                    if (source == VCPU_ESP) {



                        value = vmread(0x0000681C);
                    } else {
                        value = ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->gp_registers[source];
                    }

                    ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->cr0 &= ~(1ul << (3)) ;

                    ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->cr0 |= value & (1ul << (3)) ;





                    if (!((value ^ ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->cr0_shadow) &
                            ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->cr0_mask)) {
                        return EXCEPTION_NONE;
                    }
                }
                break;
            }
            case 2: {

                ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->cr0 &= ~(1ul << (3)) ;
                return EXCEPTION_NONE;
            }
            case 3: {
                uint16_t value = vmx_data_exit_qualification_control_regster_get_data(qual);

                ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->cr0 &= ~(1ul << (3)) ;

                ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->cr0 |= value & (1ul << (3)) ;







                if (!((value ^ ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->cr0_shadow) &
                        ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU->cr0_mask & ((1ul << (4))-1ul))) {
                    return EXCEPTION_NONE;
                }
                break;
            }
            }
        }
    }
    switch (reason) {
    case EXCEPTION_OR_NMI:
    case MOV_DR:
    case TASK_SWITCH:
    case CONTROL_REGISTER:
    case IO:
    case MWAIT:
    case SIPI:
    case INVLPG:
    case INVEPT:
    case INVVPID:
    case VMCLEAR:
    case VMPTRLD:
    case VMPTRST:
    case VMREAD:
    case VMWRITE:
    case VMXON:
    case EPT_VIOLATION:
    case GDTR_OR_IDTR:
    case LDTR_OR_TR:
    case TPR_BELOW_THRESHOLD:
    case APIC_ACCESS:
        qualification = vmread(0x00006400);
        break;
    default:
        qualification = 0;
    }

    handleVmxFault(reason, qualification);

    return EXCEPTION_NONE;
}

exception_t
handleVmEntryFail(void)
{
    handleVmxFault(-1, -1);

    return EXCEPTION_NONE;
}


void
VMCheckBoundNotification(tcb_t *tcb)
{






    if(!(tcb->tcbAffinity == getCurrentCPUIndex())) _assert_fail("tcb->tcbAffinity == getCurrentCPUIndex()", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/vcpu.c", 1372, __FUNCTION__);
    notification_t *ntfnPtr = tcb->tcbBoundNotification;
    if (thread_state_ptr_get_tsType(&tcb->tcbState) == ThreadState_RunningVM
            && ntfnPtr && notification_ptr_get_state(ntfnPtr) == NtfnState_Active) {

        word_t badge = notification_ptr_get_ntfnMsgIdentifier(ntfnPtr);
        notification_ptr_set_state(ntfnPtr, NtfnState_Idle);
        setThreadState(tcb, ThreadState_Running);
        setRegister(tcb, badgeRegister, badge);
        Arch_leaveVMAsyncTransfer(tcb);




        if (tcb != ksSMP[(getCurrentCPUIndex())].system.ksCurThread) {
            possibleSwitchTo(tcb);
        }
    }
}


static void
invvpid_context(uint16_t vpid)
{
    struct {
        uint64_t vpid : 16;
        uint64_t rsvd : 48;
        uint64_t address;
    } __attribute__((packed)) operand = {vpid, 0, 0};
    __asm__ volatile("invvpid %0, %1" :: "m"(operand), "r"((word_t)1) : "cc");
}

static void
setEPTRoot(cap_t vmxSpace, vcpu_t* vcpu)
{
    paddr_t ept_root;
    if (cap_get_capType(vmxSpace) != cap_ept_pml4_cap ||
            !cap_ept_pml4_cap_get_capPML4IsMapped(vmxSpace)) {
        ept_root = kpptr_to_paddr(null_ept_space);
    } else {
        findEPTForASID_ret_t find_ret;
        ept_pml4e_t *pml4;

        pml4 = (ept_pml4e_t*)cap_ept_pml4_cap_get_capPML4BasePtr(vmxSpace);
        find_ret = findEPTForASID(cap_ept_pml4_cap_get_capPML4MappedASID(vmxSpace));
        if (find_ret.status != EXCEPTION_NONE || find_ret.ept != pml4) {
            ept_root = kpptr_to_paddr(null_ept_space);
        } else {
            ept_root = addrFromPPtr(pml4);
        }
    }
    if (ept_root != vcpu->last_ept_root) {
        vcpu->last_ept_root = ept_root;
        vmx_eptp_t eptp = vmx_eptp_new(
                              ept_root,
                              0,
                              3,
                              6
                          );
        vmwrite(0x0000201A, eptp.words[0]);
        if(!(vcpu->vpid != 0)) _assert_fail("vcpu->vpid != VPID_INVALID", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/vcpu.c", 1432, __FUNCTION__);
        if (vmx_feature_vpid) {
            invvpid_context(vcpu->vpid);
        }
    }
}

static void
handleLazyFpu(void)
{
    vcpu_t *vcpu = ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU;
    word_t cr0 = vcpu->cr0;
    word_t exception_bitmap = vcpu->exception_bitmap;
    word_t cr0_mask = vcpu->cr0_mask;
    word_t cr0_shadow = vcpu->cr0_shadow;


    if (!vcpuThreadUsingFPU(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)) {


        cr0 |= (1ul << (3)) ;




        exception_bitmap |= (1ul << (int_unimpl_dev));





        cr0_mask |= (1ul << (3)) ;





        if (!(vcpu->cr0_mask & (1ul << (3)) )) {
            cr0_shadow &= ~(1ul << (3)) ;
            cr0_shadow |= vcpu->cr0 & (1ul << (3)) ;
        }
    }
    if (cr0 != vcpu->cached_cr0) {
        vmwrite(0x00006800, cr0);
        vcpu->cached_cr0 = cr0;
    }
    if (exception_bitmap != vcpu->cached_exception_bitmap) {
        vmwrite(0x00004004, exception_bitmap);
        vcpu->cached_exception_bitmap = exception_bitmap;
    }
    if (cr0_mask != vcpu->cached_cr0_mask) {
        vmwrite(0x00006000, cr0_mask);
        vcpu->cached_cr0_mask = cr0_mask;
    }
    if (cr0_shadow != vcpu->cached_cr0_shadow) {
        vmwrite(0x00006004, cr0_shadow);
        vcpu->cached_cr0_shadow = cr0_shadow;
    }
}

void
clearVPIDIOPortMappings(vpid_t vpid, uint16_t first, uint16_t last)
{
    if (vpid == 0) {
        return;
    }
    vcpu_t *vcpu = x86KSVPIDTable[vpid];
    if (vcpu == ((void *)0)) {
        return;
    }
    if(!(vcpu->vpid == vpid)) _assert_fail("vcpu->vpid == vpid", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/vcpu.c", 1502, __FUNCTION__);
    performSetIOPortMask(vcpu, first, last, 1);
}

static inline vpid_t
nextVPID(vpid_t vpid)
{
    if (vpid == (64 - 1)) {
        return 1;
    } else {
        return vpid + 1;
    }
}

static void
invalidateVPID(vpid_t vpid)
{
    vcpu_t *vcpu = x86KSVPIDTable[vpid];


    memset(vcpu->io, ~0, sizeof(vcpu->io));

    if (vmx_feature_vpid) {
        invvpid_context(vpid);
    }
}

static vpid_t
findFreeVPID(void)
{
    vpid_t vpid;

    vpid = x86KSNextVPID;
    do {
        if (x86KSVPIDTable[vpid] == ((void *)0)) {
            return vpid;
        }
        vpid = nextVPID(vpid);
    } while (vpid != x86KSNextVPID);


    vpid = x86KSNextVPID;
    invalidateVPID(vpid);

    x86KSVPIDTable[vpid]->vpid = 0;
    x86KSVPIDTable[vpid] = ((void *)0);

    x86KSNextVPID = nextVPID(x86KSNextVPID);
    return vpid;
}

static void
storeVPID(vcpu_t *vcpu, vpid_t vpid)
{
    if(!(x86KSVPIDTable[vpid] == ((void *)0))) _assert_fail("x86KSVPIDTable[vpid] == NULL", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/vcpu.c", 1556, __FUNCTION__);
    if(!(vcpu->vpid == 0)) _assert_fail("vcpu->vpid == VPID_INVALID", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/arch/x86/object/vcpu.c", 1557, __FUNCTION__);
    x86KSVPIDTable[vpid] = vcpu;
    vcpu->vpid = vpid;
}

void
restoreVMCS(void)
{
    vcpu_t *expected_vmcs = ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbVCPU;


    if (ksSMP[(getCurrentCPUIndex())].cpu.x86KSCurrentVCPU != expected_vmcs) {
        switchVCPU(expected_vmcs);
    }


    if (getCurrentCR3().words[0] != expected_vmcs->last_host_cr3) {
        expected_vmcs->last_host_cr3 = getCurrentCR3().words[0];
        vmwrite(0x00006C02, getCurrentCR3().words[0]);
    }

    if (expected_vmcs->vpid == 0) {
        vpid_t vpid = findFreeVPID();
        storeVPID(expected_vmcs, vpid);
        if (vmx_feature_vpid) {
            vmwrite(0x00000000, vpid);
        }
    }
    setEPTRoot((((cte_t *)((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)&~((1ul << (11))-1ul)))+(tcbArchEPTRoot))->cap, expected_vmcs);
    handleLazyFpu();
}

void
invept(ept_pml4e_t *ept_pml4)
{
    if (vmx_ept_vpid_cap_msr_get_invept(vpid_capability)) {
        struct {
            uint64_t parts[2];
        } address;
        word_t type;
        if (vmx_ept_vpid_cap_msr_get_invept_single_context(vpid_capability)) {
            type = 1;
        } else if (vmx_ept_vpid_cap_msr_get_invept_all_context(vpid_capability)) {
            type = 2;
        } else {



            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1605, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Hardware claimed to support invept, yet provided no mechanism"); kprintf(">>" "" "\n"); } while (0);
            return;
        }

        address.parts[0] = addrFromPPtr((void*)ept_pml4);
        address.parts[1] = 0;
        __asm__ volatile (
            "invept %0, %1"
            :
            : "m"(address), "r"(type)
            : "memory"
        );
    }
}



static IpiModeRemoteCall_t remoteCall;

static inline void init_ipi_args(IpiModeRemoteCall_t func,
                                 word_t data1, word_t data2, word_t data3,
                                 word_t mask)
{
    remoteCall = func;
    ipi_args[0] = data1;
    ipi_args[1] = data2;
    ipi_args[2] = data3;


    totalCoreBarrier = popcountl(mask);
}

static void handleRemoteCall(IpiModeRemoteCall_t call, word_t arg0,
                             word_t arg1, word_t arg2, bool_t irqPath)
{


    if (clh_is_ipi_pending(getCurrentCPUIndex())) {
        switch ((IpiRemoteCall_t)call) {
        case IpiRemoteCall_Stall:
            ipiStallCoreCallback(irqPath);
            break;

        case IpiRemoteCall_InvalidatePageStructureCacheASID:
            invalidateLocalPageStructureCacheASID(arg0, arg1);
            break;

        case IpiRemoteCall_InvalidateTranslationSingle:
            invalidateLocalTranslationSingle(arg0);
            break;

        case IpiRemoteCall_InvalidateTranslationSingleASID:
            invalidateLocalTranslationSingleASID(arg0, arg1);
            break;

        case IpiRemoteCall_InvalidateTranslationAll:
            invalidateLocalTranslationAll();
            break;

        case IpiRemoteCall_switchFpuOwner:
            switchLocalFpuOwner((user_fpu_state_t *)arg0);
            break;


        case IpiRemoteCall_ClearCurrentVCPU:
            clearCurrentVCPU();
            break;
        case IpiRemoteCall_VMCheckBoundNotification:
            VMCheckBoundNotification((tcb_t*)arg0);
            break;

        default:
            Mode_handleRemoteCall(call, arg0, arg1, arg2);
            break;
        }

        big_kernel_lock.node_owners[getCurrentCPUIndex()].ipi = 0;
        ipi_wait(totalCoreBarrier);
    }
}


typedef int __assert_failed_invalid_number_of_supported_nodes[(16 <= (1 << 6)) ? 1 : -1];;
void ipi_send_mask(irq_t ipi, word_t mask, bool_t isBlocking)
{
    interrupt_t interrupt_ipi = ipi + 0x20;




    generic_ipi_send_mask(interrupt_ipi, mask, isBlocking);

}



void _fail(
    const char* s,
    const char* file,
    unsigned int line,
    const char* function)
{
    kprintf("seL4 called fail at %s:%u in function %s, saying \"%s\"\n", file, line, function, s)





     ;
    halt();
}

void _assert_fail(
    const char* assertion,
    const char* file,
    unsigned int line,
    const char* function)
{
    kprintf("seL4 failed assertion '%s' at %s:%u in function %s\n", assertion, file, line, function)




           ;
    halt();
}



bool_t benchmark_log_utilisation_enabled;
timestamp_t ksEnter;
timestamp_t benchmark_start_time;
timestamp_t benchmark_end_time;

void benchmark_track_utilisation_dump(void)
{
    uint64_t *buffer = ((uint64_t *) & (((seL4_IPCBuffer *)lookupIPCBuffer(true, ksSMP[(getCurrentCPUIndex())].system.ksCurThread))->msg[0]));
    tcb_t *tcb = ((void *)0);
    word_t tcb_cptr = getRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, capRegister);
    lookupCap_ret_t lu_ret;
    word_t cap_type;

    lu_ret = lookupCap(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, tcb_cptr);

    cap_type = cap_get_capType(lu_ret.cap);
    if (cap_type != cap_thread_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 33, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("SysBenchmarkFinalizeLog: cap is not a TCB, halting"); kprintf(">>" "" "\n"); } while (0);
        return;
    }

    tcb = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(lu_ret.cap)));
    buffer[BENCHMARK_TCB_UTILISATION] = tcb->benchmark.utilisation;
    buffer[BENCHMARK_IDLE_LOCALCPU_UTILISATION] = ksSMP[(getCurrentCPUIndex())].system.ksIdleThread->benchmark.utilisation;

    buffer[BENCHMARK_IDLE_TCBCPU_UTILISATION] = ksSMP[(tcb->tcbAffinity)].system.ksIdleThread->benchmark.utilisation;
    buffer[BENCHMARK_TOTAL_UTILISATION] = benchmark_end_time - benchmark_start_time;


}

void benchmark_track_reset_utilisation(void)
{
    tcb_t *tcb = ((void *)0);
    word_t tcb_cptr = getRegister(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, capRegister);
    lookupCap_ret_t lu_ret;
    word_t cap_type;

    lu_ret = lookupCap(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, tcb_cptr);

    cap_type = cap_get_capType(lu_ret.cap);
    if (cap_type != cap_thread_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 66, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("SysBenchmarkResetThreadUtilisation: cap is not a TCB, halting"); kprintf(">>" "" "\n"); } while (0);
        return;
    }

    tcb = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(lu_ret.cap)));

    tcb->benchmark.utilisation = 0;
    tcb->benchmark.schedule_start_time = 0;
}
static inline cap_t __attribute__((always_inline))
lookup_fp(cap_t cap, cptr_t cptr)
{
    word_t cptr2;
    cte_t *slot;
    word_t guardBits, radixBits, bits;
    word_t radix, capGuard;

    bits = 0;

    if (__builtin_expect(!!(! cap_capType_equals(cap, cap_cnode_cap)), 0)) {
        return cap_null_cap_new();
    }

    do {
        guardBits = cap_cnode_cap_get_capCNodeGuardSize(cap);
        radixBits = cap_cnode_cap_get_capCNodeRadix(cap);
        cptr2 = cptr << bits;

        capGuard = cap_cnode_cap_get_capCNodeGuard(cap);





        if (__builtin_expect(!!(guardBits), 1) && __builtin_expect(!!(cptr2 >> ((1 << 6) - guardBits) != capGuard), 0)) {
            return cap_null_cap_new();
        }

        radix = cptr2 << guardBits >> ((1 << 6) - radixBits);
        slot = ((cte_t *)(cap_cnode_cap_get_capCNodePtr(cap))) + radix;

        cap = slot->cap;
        bits += guardBits + radixBits;

    } while (__builtin_expect(!!(bits < (1 << 6) && cap_capType_equals(cap, cap_cnode_cap)), 0));

    if (__builtin_expect(!!(bits > (1 << 6)), 0)) {


        return cap_null_cap_new();
    }

    return cap;
}

static inline void
thread_state_ptr_set_tsType_np(thread_state_t *ts_ptr, word_t tsType)
{
    ts_ptr->words[0] = tsType;
}

static inline void
thread_state_ptr_mset_blockingObject_tsType(thread_state_t *ts_ptr,
                                            word_t ep_ref,
                                            word_t tsType)
{
    ts_ptr->words[0] = ep_ref | tsType;
}

static inline void
cap_reply_cap_ptr_new_np(cap_t *cap_ptr, word_t capReplyMaster,
                         word_t capTCBPtr)
{

    cap_ptr->words[1] = (word_t)capTCBPtr;
    cap_ptr->words[0] = (capReplyMaster) | ((word_t)cap_reply_cap << 59);




}

static inline void
endpoint_ptr_mset_epQueue_tail_state(endpoint_t *ep_ptr, word_t epQueue_tail,
                                     word_t state)
{
    ep_ptr->words[0] = epQueue_tail | state;
}

static inline void
endpoint_ptr_set_epQueue_head_np(endpoint_t *ep_ptr, word_t epQueue_head)
{
    ep_ptr->words[1] = epQueue_head;
}






void

__attribute__((__noreturn__))

fastpath_call(word_t cptr, word_t msgInfo)
{
    seL4_MessageInfo_t info;
    cap_t ep_cap;
    endpoint_t *ep_ptr;
    word_t length;
    tcb_t *dest;
    word_t badge;
    cte_t *replySlot, *callerSlot;
    cap_t newVTable;
    vspace_root_t *cap_pd;
    pde_t stored_hw_asid;
    word_t fault_type;
    dom_t dom;


    info = messageInfoFromWord_raw(msgInfo);
    length = seL4_MessageInfo_get_length(info);
    fault_type = seL4_Fault_get_seL4_FaultType(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbFault);



    if (__builtin_expect(!!(fastpath_mi_check(msgInfo) || fault_type != seL4_Fault_NullFault), 0)
                                                    ) {
        slowpath(SysCall);
    }


    ep_cap = lookup_fp((((cte_t *)((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)&~((1ul << (11))-1ul)))+(tcbCTable))->cap, cptr);


    if (__builtin_expect(!!(!cap_capType_equals(ep_cap, cap_endpoint_cap) || !cap_endpoint_cap_get_capCanSend(ep_cap)), 0)
                                                          ) {
        slowpath(SysCall);
    }


    ep_ptr = ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(ep_cap)));



    dest = ((tcb_t *)(endpoint_ptr_get_epQueue_head(ep_ptr)));


    if (__builtin_expect(!!(endpoint_ptr_get_state(ep_ptr) != EPState_Recv), 0)) {
        slowpath(SysCall);
    }
    newVTable = (((cte_t *)((word_t)(dest)&~((1ul << (11))-1ul)))+(tcbVTable))->cap;


    cap_pd = cap_vtable_cap_get_vspace_root_fp(newVTable);


    if (__builtin_expect(!!(! isValidVTableRoot_fp(newVTable)), 0)) {
        slowpath(SysCall);
    }
    stored_hw_asid.words[0] = cap_pml4_cap_get_capPML4MappedASID_fp(newVTable);

    dom = maxDom ? ksCurDomain : 0;

    if (__builtin_expect(!!(dest->tcbPriority < ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbPriority), 1) &&
            !isHighestPrio(dom, dest->tcbPriority)) {
        slowpath(SysCall);
    }



    if (__builtin_expect(!!(!cap_endpoint_cap_get_capCanGrant(ep_cap)), 0)) {
        slowpath(SysCall);
    }
    if (__builtin_expect(!!(dest->tcbDomain != ksCurDomain && maxDom), 0)) {
        slowpath(SysCall);
    }



    if (__builtin_expect(!!(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbAffinity != dest->tcbAffinity), 0)) {
        slowpath(SysCall);
    }
    endpoint_ptr_set_epQueue_head_np(ep_ptr, ((word_t)(dest->tcbEPNext)));
    if (__builtin_expect(!!(dest->tcbEPNext), 0)) {
        dest->tcbEPNext->tcbEPPrev = ((void *)0);
    } else {
        endpoint_ptr_mset_epQueue_tail_state(ep_ptr, 0, EPState_Idle);
    }

    badge = cap_endpoint_cap_get_capEPBadge(ep_cap);


    thread_state_ptr_set_tsType_np(&ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbState,
                                   ThreadState_BlockedOnReply);


    replySlot = (((cte_t *)((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)&~((1ul << (11))-1ul)))+(tcbReply));


    callerSlot = (((cte_t *)((word_t)(dest)&~((1ul << (11))-1ul)))+(tcbCaller));


    cap_reply_cap_ptr_new_np(&callerSlot->cap, 0, ((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)));
    mdb_node_ptr_set_mdbPrev_np(&callerSlot->cteMDBNode, ((word_t)(replySlot)));
    mdb_node_ptr_mset_mdbNext_mdbRevocable_mdbFirstBadged(
        &replySlot->cteMDBNode, ((word_t)(callerSlot)), 1, 1);

    fastpath_copy_mrs (length, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, dest);


    thread_state_ptr_set_tsType_np(&dest->tcbState,
                                   ThreadState_Running);
    switchToThread_fp(dest, cap_pd, stored_hw_asid);

    msgInfo = wordFromMessageInfo(seL4_MessageInfo_set_capsUnwrapped(info, 0));

    fastpath_restore(badge, msgInfo, ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
}

void
fastpath_reply_recv(word_t cptr, word_t msgInfo)
{
    seL4_MessageInfo_t info;
    cap_t ep_cap;
    endpoint_t *ep_ptr;
    word_t length;
    cte_t *callerSlot;
    cap_t callerCap;
    tcb_t *caller;
    word_t badge;
    tcb_t *endpointTail;
    word_t fault_type;

    cap_t newVTable;
    vspace_root_t *cap_pd;
    pde_t stored_hw_asid;
    dom_t dom;


    info = messageInfoFromWord_raw(msgInfo);
    length = seL4_MessageInfo_get_length(info);
    fault_type = seL4_Fault_get_seL4_FaultType(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbFault);



    if (__builtin_expect(!!(fastpath_mi_check(msgInfo) || fault_type != seL4_Fault_NullFault), 0)
                                                    ) {
        slowpath(SysReplyRecv);
    }


    ep_cap = lookup_fp((((cte_t *)((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)&~((1ul << (11))-1ul)))+(tcbCTable))->cap,
                       cptr);


    if (__builtin_expect(!!(!cap_capType_equals(ep_cap, cap_endpoint_cap) || !cap_endpoint_cap_get_capCanReceive(ep_cap)), 0)
                                                             ) {
        slowpath(SysReplyRecv);
    }


    if (ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbBoundNotification &&
            notification_ptr_get_state(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbBoundNotification) == NtfnState_Active) {
        slowpath(SysReplyRecv);
    }


    ep_ptr = ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(ep_cap)));


    if (__builtin_expect(!!(endpoint_ptr_get_state(ep_ptr) == EPState_Send), 0)) {
        slowpath(SysReplyRecv);
    }


    callerSlot = (((cte_t *)((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)&~((1ul << (11))-1ul)))+(tcbCaller));
    callerCap = callerSlot->cap;
    if (__builtin_expect(!!(!fastpath_reply_cap_check(callerCap)), 0)) {
        slowpath(SysReplyRecv);
    }


    caller = ((tcb_t *)(cap_reply_cap_get_capTCBPtr(callerCap)));
    fault_type = seL4_Fault_get_seL4_FaultType(caller->tcbFault);
    if (__builtin_expect(!!(fault_type != seL4_Fault_NullFault), 0)) {
        slowpath(SysReplyRecv);
    }


    newVTable = (((cte_t *)((word_t)(caller)&~((1ul << (11))-1ul)))+(tcbVTable))->cap;


    cap_pd = cap_vtable_cap_get_vspace_root_fp(newVTable);


    if (__builtin_expect(!!(! isValidVTableRoot_fp (newVTable)), 0)) {
        slowpath(SysReplyRecv);
    }







    stored_hw_asid.words[0] = cap_pml4_cap_get_capPML4MappedASID(newVTable);

    dom = maxDom ? ksCurDomain : 0;
    if (__builtin_expect(!!(!isHighestPrio(dom, caller->tcbPriority)), 0)) {
        slowpath(SysReplyRecv);
    }

    if (__builtin_expect(!!(caller->tcbDomain != ksCurDomain && maxDom), 0)) {
        slowpath(SysReplyRecv);
    }



    if (__builtin_expect(!!(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbAffinity != caller->tcbAffinity), 0)) {
        slowpath(SysReplyRecv);
    }
    thread_state_ptr_mset_blockingObject_tsType(
        &ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbState, (word_t)ep_ptr, ThreadState_BlockedOnReceive);


    endpointTail = endpoint_ptr_get_epQueue_tail_fp(ep_ptr);
    if (__builtin_expect(!!(!endpointTail), 1)) {
        ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbEPPrev = ((void *)0);
        ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbEPNext = ((void *)0);


        endpoint_ptr_set_epQueue_head_np(ep_ptr, ((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)));
        endpoint_ptr_mset_epQueue_tail_state(ep_ptr, ((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)),
                                             EPState_Recv);
    } else {

        endpointTail->tcbEPNext = ksSMP[(getCurrentCPUIndex())].system.ksCurThread;
        ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbEPPrev = endpointTail;
        ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbEPNext = ((void *)0);


        endpoint_ptr_mset_epQueue_tail_state(ep_ptr, ((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)),
                                             EPState_Recv);
    }


    mdb_node_ptr_mset_mdbNext_mdbRevocable_mdbFirstBadged(
        &((cte_t *)(mdb_node_get_mdbPrev(callerSlot->cteMDBNode)))->cteMDBNode,
        0, 1, 1);
    callerSlot->cap = cap_null_cap_new();
    callerSlot->cteMDBNode = mdb_node_new(0, false, false, 0);




    badge = 0;

    fastpath_copy_mrs (length, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, caller);


    thread_state_ptr_set_tsType_np(&caller->tcbState,
                                   ThreadState_Running);
    switchToThread_fp(caller, cap_pd, stored_hw_asid);

    msgInfo = wordFromMessageInfo(seL4_MessageInfo_set_capsUnwrapped(info, 0));

    fastpath_restore(badge, msgInfo, ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
}

lookup_fault_t current_lookup_fault;
seL4_Fault_t current_fault;
syscall_error_t current_syscall_error;



ndks_boot_t ndks_boot __attribute__((__section__(".boot.data")));

__attribute__((__section__(".boot.text"))) bool_t
insert_region(region_t reg)
{
    word_t i;

    if(!(reg.start <= reg.end)) _assert_fail("reg.start <= reg.end", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/kernel/boot.c", 33, __FUNCTION__);
    if (is_reg_empty(reg)) {
        return true;
    }
    for (i = 0; i < 16; i++) {
        if (is_reg_empty(ndks_boot.freemem[i])) {
            ndks_boot.freemem[i] = reg;
            return true;
        }
    }
    return false;
}

__attribute__((__section__(".boot.text"))) static inline word_t
reg_size(region_t reg)
{
    return reg.end - reg.start;
}

__attribute__((__section__(".boot.text"))) pptr_t
alloc_region(word_t size_bits)
{
    word_t i;
    word_t reg_index = 0;
    region_t reg = (region_t){ .start = 0, .end = 0 };
    region_t rem_small = (region_t){ .start = 0, .end = 0 };
    region_t rem_large = (region_t){ .start = 0, .end = 0 };
    region_t new_reg;
    region_t new_rem_small;
    region_t new_rem_large;







    for (i = 0; i < 16; i++) {

        if ((((((ndks_boot.freemem[i].start) - 1ul) >> (size_bits)) + 1ul) << (size_bits)) - ndks_boot.freemem[i].start <
                ndks_boot.freemem[i].end - (((ndks_boot.freemem[i].end) >> (size_bits)) << (size_bits))) {
            new_reg.start = (((((ndks_boot.freemem[i].start) - 1ul) >> (size_bits)) + 1ul) << (size_bits));
            new_reg.end = new_reg.start + (1ul << (size_bits));
        } else {
            new_reg.end = (((ndks_boot.freemem[i].end) >> (size_bits)) << (size_bits));
            new_reg.start = new_reg.end - (1ul << (size_bits));
        }
        if (new_reg.end > new_reg.start &&
                new_reg.start >= ndks_boot.freemem[i].start &&
                new_reg.end <= ndks_boot.freemem[i].end) {
            if (new_reg.start - ndks_boot.freemem[i].start < ndks_boot.freemem[i].end - new_reg.end) {
                new_rem_small.start = ndks_boot.freemem[i].start;
                new_rem_small.end = new_reg.start;
                new_rem_large.start = new_reg.end;
                new_rem_large.end = ndks_boot.freemem[i].end;
            } else {
                new_rem_large.start = ndks_boot.freemem[i].start;
                new_rem_large.end = new_reg.start;
                new_rem_small.start = new_reg.end;
                new_rem_small.end = ndks_boot.freemem[i].end;
            }
            if ( is_reg_empty(reg) ||
                    (reg_size(new_rem_small) < reg_size(rem_small)) ||
                    (reg_size(new_rem_small) == reg_size(rem_small) && reg_size(new_rem_large) < reg_size(rem_large)) ) {
                reg = new_reg;
                rem_small = new_rem_small;
                rem_large = new_rem_large;
                reg_index = i;
            }
        }
    }
    if (is_reg_empty(reg)) {
        kprintf("Kernel init failing: not enough memory\n");
        return 0;
    }

    ndks_boot.freemem[reg_index] = (region_t){ .start = 0, .end = 0 };

    insert_region(rem_large);
    if (!insert_region(rem_small)) {
        kprintf("alloc_region(): wasted 0x%lx bytes due to alignment, try to increase MAX_NUM_FREEMEM_REG\n", (word_t)(rem_small.end - rem_small.start))
                                                         ;
    }
    return reg.start;
}

__attribute__((__section__(".boot.text"))) void
write_slot(slot_ptr_t slot_ptr, cap_t cap)
{
    slot_ptr->cap = cap;

    slot_ptr->cteMDBNode = mdb_node_new(0, false, false, 0);
    mdb_node_ptr_set_mdbRevocable (&slot_ptr->cteMDBNode, true);
    mdb_node_ptr_set_mdbFirstBadged(&slot_ptr->cteMDBNode, true);
}




typedef int __assert_failed_root_cnode_size_valid[(18 < 32 - 5 && (1U << 18) >= seL4_NumInitialCaps) ? 1 : -1];



__attribute__((__section__(".boot.text"))) cap_t
create_root_cnode(void)
{
    pptr_t pptr;
    cap_t cap;


    ndks_boot.slot_pos_max = (1ul << (18));


    pptr = alloc_region(18 + 5);
    if (!pptr) {
        kprintf("Kernel init failing: could not create root cnode\n");
        return cap_null_cap_new();
    }
    memzero(((cte_t *)(pptr)), 1U << (18 + 5));
    cap =
        cap_cnode_cap_new(
            18,
            (1 << 6) - 18,
            0,
            pptr
        );


    write_slot((((slot_ptr_t)(pptr)) + (seL4_CapInitThreadCNode)), cap);

    return cap;
}

typedef int __assert_failed_irq_cnode_size[((1ul << (13 - 5)) > maxIRQ) ? 1 : -1];

__attribute__((__section__(".boot.text"))) bool_t
create_irq_cnode(void)
{
    pptr_t pptr;

    pptr = alloc_region(13);
    if (!pptr) {
        kprintf("Kernel init failing: could not create irq cnode\n");
        return false;
    }
    memzero((void*)pptr, 1 << 13);
    intStateIRQNode = (cte_t*)pptr;
    return true;
}


typedef int __assert_failed_num_domains_valid[(1 >= 1 && 1 <= 256) ? 1 : -1];

typedef int __assert_failed_num_priorities_valid[(256 >= 1 && 256 <= 256) ? 1 : -1];


__attribute__((__section__(".boot.text"))) void
create_domain_cap(cap_t root_cnode_cap)
{
    cap_t cap;
    word_t i;


    if(!(ksDomScheduleLength > 0)) _assert_fail("ksDomScheduleLength > 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/kernel/boot.c", 196, __FUNCTION__);
    for (i = 0; i < ksDomScheduleLength; i++) {
        if(!(ksDomSchedule[i].domain < 1)) _assert_fail("ksDomSchedule[i].domain < CONFIG_NUM_DOMAINS", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/kernel/boot.c", 198, __FUNCTION__);
        if(!(ksDomSchedule[i].length > 0)) _assert_fail("ksDomSchedule[i].length > 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/kernel/boot.c", 199, __FUNCTION__);
    }

    cap = cap_domain_cap_new();
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapDomain)), cap);
}


__attribute__((__section__(".boot.text"))) cap_t
create_ipcbuf_frame(cap_t root_cnode_cap, cap_t pd_cap, vptr_t vptr)
{
    cap_t cap;
    pptr_t pptr;


    pptr = alloc_region(12);
    if (!pptr) {
        kprintf("Kernel init failing: could not create ipc buffer frame\n");
        return cap_null_cap_new();
    }
    clearMemory((void*)pptr, 12);


    cap = create_mapped_it_frame_cap(pd_cap, pptr, vptr, 1 , false, false);
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadIPCBuffer)), cap);

    return cap;
}

__attribute__((__section__(".boot.text"))) void
create_bi_frame_cap(
    cap_t root_cnode_cap,
    cap_t pd_cap,
    pptr_t pptr,
    vptr_t vptr
)
{
    cap_t cap;


    cap = create_mapped_it_frame_cap(pd_cap, pptr, vptr, 1 , false, false);
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapBootInfoFrame)), cap);
}

__attribute__((__section__(".boot.text"))) region_t
allocate_extra_bi_region(word_t extra_size)
{

    if (extra_size == 0) {

        return (region_t) {
            0x1000, 0x1000
        };
    }
    word_t size_bits = 64 - 1 - clzl((((((extra_size) - 1ul) >> (12)) + 1ul) << (12)));
    pptr_t pptr = alloc_region(size_bits);
    if (!pptr) {
        kprintf("Kernel init failed: could not allocate extra bootinfo region size bits %lu\n", size_bits);
        return (region_t){ .start = 0, .end = 0 };
    }

    clearMemory((void*)pptr, size_bits);
    ndks_boot.bi_frame->extraLen = (1ul << (size_bits));

    return (region_t) {
        pptr, pptr + (1ul << (size_bits))
    };
}

__attribute__((__section__(".boot.text"))) pptr_t
allocate_bi_frame(
    node_id_t node_id,
    word_t num_nodes,
    vptr_t ipcbuf_vptr
)
{
    pptr_t pptr;


    pptr = alloc_region(12);
    if (!pptr) {
        kprintf("Kernel init failed: could not allocate bootinfo frame\n");
        return 0;
    }
    clearMemory((void*)pptr, 12);


    ndks_boot.bi_frame = ((seL4_BootInfo*)(pptr));
    ndks_boot.slot_pos_cur = seL4_NumInitialCaps;

    ((seL4_BootInfo*)(pptr))->nodeID = node_id;
    ((seL4_BootInfo*)(pptr))->numNodes = num_nodes;
    ((seL4_BootInfo*)(pptr))->numIOPTLevels = 0;
    ((seL4_BootInfo*)(pptr))->ipcBuffer = (seL4_IPCBuffer *) ipcbuf_vptr;
    ((seL4_BootInfo*)(pptr))->initThreadCNodeSizeBits = 18;
    ((seL4_BootInfo*)(pptr))->initThreadDomain = ksDomSchedule[ksDomScheduleIdx].domain;
    ((seL4_BootInfo*)(pptr))->extraLen = 0;
    ((seL4_BootInfo*)(pptr))->extraBIPages.start = 0;
    ((seL4_BootInfo*)(pptr))->extraBIPages.end = 0;

    return pptr;
}

__attribute__((__section__(".boot.text"))) bool_t
provide_cap(cap_t root_cnode_cap, cap_t cap)
{
    if (ndks_boot.slot_pos_cur >= ndks_boot.slot_pos_max) {
        kprintf("Kernel init failed: ran out of cap slots\n");
        return false;
    }
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (ndks_boot.slot_pos_cur)), cap);
    ndks_boot.slot_pos_cur++;
    return true;
}

__attribute__((__section__(".boot.text"))) create_frames_of_region_ret_t
create_frames_of_region(
    cap_t root_cnode_cap,
    cap_t pd_cap,
    region_t reg,
    bool_t do_map,
    sword_t pv_offset
)
{
    pptr_t f;
    cap_t frame_cap;
    seL4_SlotPos slot_pos_before;
    seL4_SlotPos slot_pos_after;

    slot_pos_before = ndks_boot.slot_pos_cur;

    for (f = reg.start; f < reg.end; f += (1ul << (12))) {
        if (do_map) {
            frame_cap = create_mapped_it_frame_cap(pd_cap, f, addrFromPPtr((void*)(f - pv_offset)), 1 , false, true);
        } else {
            frame_cap = create_unmapped_it_frame_cap(f, false);
        }
        if (!provide_cap(root_cnode_cap, frame_cap))
            return (create_frames_of_region_ret_t) {
            (seL4_SlotRegion){ .start = 0, .end = 0 }, false
        };
    }

    slot_pos_after = ndks_boot.slot_pos_cur;

    return (create_frames_of_region_ret_t) {
        (seL4_SlotRegion) { slot_pos_before, slot_pos_after }, true
    };
}

__attribute__((__section__(".boot.text"))) cap_t
create_it_asid_pool(cap_t root_cnode_cap)
{
    pptr_t ap_pptr;
    cap_t ap_cap;


    ap_pptr = alloc_region(12);
    if (!ap_pptr) {
        kprintf("Kernel init failed: failed to create initial thread asid pool\n");
        return cap_null_cap_new();
    }
    memzero(((asid_pool_t*)ap_pptr), 1 << 12);
    ap_cap = cap_asid_pool_cap_new(1 >> asidLowBits, ap_pptr);
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadASIDPool)), ap_cap);


    write_slot(
        (((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapASIDControl)),
        cap_asid_control_cap_new()
    );

    return ap_cap;
}

__attribute__((__section__(".boot.text"))) bool_t
create_idle_thread(void)
{
    pptr_t pptr;


    for (int i = 0; i < 16; i++) {

        pptr = alloc_region(11);
        if (!pptr) {
            kprintf("Kernel init failed: Unable to allocate tcb for idle thread\n");
            return false;
        }
        memzero((void *)pptr, 1 << 11);
        ksSMP[(i)].system.ksIdleThread = ((tcb_t *)(pptr + (1ul << ((11 - 1)))));
        configureIdleThread(ksSMP[(i)].system.ksIdleThread);

        setThreadName(ksSMP[(i)].system.ksIdleThread, "idle_thread");

        ksSMP[(i)].system.ksIdleThread->tcbAffinity = i;

    }

    return true;
}

__attribute__((__section__(".boot.text"))) tcb_t *
create_initial_thread(
    cap_t root_cnode_cap,
    cap_t it_pd_cap,
    vptr_t ui_v_entry,
    vptr_t bi_frame_vptr,
    vptr_t ipcbuf_vptr,
    cap_t ipcbuf_cap
)
{
    pptr_t pptr;
    cap_t cap;
    tcb_t* tcb;
    deriveCap_ret_t dc_ret;


    pptr = alloc_region(11);
    if (!pptr) {
        kprintf("Kernel init failed: Unable to allocate tcb for initial thread\n");
        return ((void *)0);
    }
    memzero((void*)pptr, 1 << 11);
    tcb = ((tcb_t *)(pptr + (1ul << ((11 - 1)))));
    tcb->tcbTimeSlice = 1;
    Arch_initContext(&tcb->tcbArch.tcbContext);


    dc_ret = deriveCap((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadIPCBuffer)), ipcbuf_cap);
    if (dc_ret.status != EXCEPTION_NONE) {
        kprintf("Failed to derive copy of IPC Buffer\n");
        return ((void *)0);
    }


    cteInsert(
        root_cnode_cap,
        (((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadCNode)),
        (((slot_ptr_t)(pptr)) + (tcbCTable))
    );
    cteInsert(
        it_pd_cap,
        (((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadVSpace)),
        (((slot_ptr_t)(pptr)) + (tcbVTable))
    );
    cteInsert(
        dc_ret.cap,
        (((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadIPCBuffer)),
        (((slot_ptr_t)(pptr)) + (tcbBuffer))
    );
    tcb->tcbIPCBuffer = ipcbuf_vptr;


    Arch_setTCBIPCBuffer(tcb, ipcbuf_vptr);

    setRegister(tcb, capRegister, bi_frame_vptr);
    setNextPC(tcb, ui_v_entry);


    tcb->tcbPriority = seL4_MaxPrio;
    tcb->tcbMCP = seL4_MaxPrio;
    setupReplyMaster(tcb);
    setThreadState(tcb, ThreadState_Running);

    ksCurDomain = ksDomSchedule[ksDomScheduleIdx].domain;
    ksDomainTime = ksDomSchedule[ksDomScheduleIdx].length;
    if(!(ksCurDomain < 1 && ksDomainTime > 0)) _assert_fail("ksCurDomain < CONFIG_NUM_DOMAINS && ksDomainTime > 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/kernel/boot.c", 465, __FUNCTION__);

    tcb->tcbAffinity = 0;


    cap = cap_thread_cap_new(((word_t)(tcb)));
    write_slot((((slot_ptr_t)((pptr_t)cap_get_capPtr(root_cnode_cap))) + (seL4_CapInitThreadTCB)), cap);


    setThreadName(tcb, "rootserver");


    return tcb;
}

__attribute__((__section__(".boot.text"))) void
init_core_state(tcb_t *scheduler_action)
{

    ksSMP[(getCurrentCPUIndex())].system.ksActiveFPUState = ((void *)0);



    ksSMP[(getCurrentCPUIndex())].system.ksDebugTCBs = ((void *)0);
    if (scheduler_action != ((tcb_t*)0) &&
            scheduler_action != ((tcb_t*) 1)) {
        tcbDebugAppend(scheduler_action);
    }
    tcbDebugAppend(ksSMP[(getCurrentCPUIndex())].system.ksIdleThread);

    ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction = scheduler_action;
    ksSMP[(getCurrentCPUIndex())].system.ksCurThread = ksSMP[(getCurrentCPUIndex())].system.ksIdleThread;
}

__attribute__((__section__(".boot.text"))) static bool_t
provide_untyped_cap(
    cap_t root_cnode_cap,
    bool_t device_memory,
    pptr_t pptr,
    word_t size_bits,
    seL4_SlotPos first_untyped_slot
)
{
    bool_t ret;
    cap_t ut_cap;
    word_t i = ndks_boot.slot_pos_cur - first_untyped_slot;
    if (i < 230) {
        ndks_boot.bi_frame->untypedList[i] = (seL4_UntypedDesc) {
            addrFromPPtr((void*)pptr), 0, 0, size_bits, device_memory
        };
        ut_cap = cap_untyped_cap_new(((1ul << ((size_bits) - 4))),
                                     device_memory, size_bits, pptr);
        ret = provide_cap(root_cnode_cap, ut_cap);
    } else {
        kprintf("Kernel init: Too many untyped regions for boot info\n");
        ret = true;
    }
    return ret;
}


__attribute__((__section__(".boot.text"))) static word_t boot_ctzl (word_t x)
{
    return ctzl(x);
}

__attribute__((__section__(".boot.text"))) bool_t
create_untypeds_for_region(
    cap_t root_cnode_cap,
    bool_t device_memory,
    region_t reg,
    seL4_SlotPos first_untyped_slot
)
{
    word_t align_bits;
    word_t size_bits;

    while (!is_reg_empty(reg)) {

        size_bits = 64 - 1 - clzl(reg.end - reg.start);


        if (reg.start != 0) {
            align_bits = boot_ctzl(reg.start);
        } else {
            align_bits = size_bits;
        }

        if (align_bits < size_bits) {
            size_bits = align_bits;
        }
        if (size_bits > 47) {
            size_bits = 47;
        }

        if (size_bits >= 4) {
            if (!provide_untyped_cap(root_cnode_cap, device_memory, reg.start, size_bits, first_untyped_slot)) {
                return false;
            }
        }
        reg.start += (1ul << (size_bits));
    }
    return true;
}

__attribute__((__section__(".boot.text"))) bool_t
create_kernel_untypeds(cap_t root_cnode_cap, region_t boot_mem_reuse_reg, seL4_SlotPos first_untyped_slot)
{
    word_t i;
    region_t reg;


    if (!create_untypeds_for_region(root_cnode_cap, false, boot_mem_reuse_reg, first_untyped_slot)) {
        return false;
    }


    for (i = 0; i < 16; i++) {
        reg = ndks_boot.freemem[i];
        ndks_boot.freemem[i] = (region_t){ .start = 0, .end = 0 };
        if (!create_untypeds_for_region(root_cnode_cap, false, reg, first_untyped_slot)) {
            return false;
        }
    }

    return true;
}

__attribute__((__section__(".boot.text"))) void
bi_finalise(void)
{
    seL4_SlotPos slot_pos_start = ndks_boot.slot_pos_cur;
    seL4_SlotPos slot_pos_end = ndks_boot.slot_pos_max;
    ndks_boot.bi_frame->empty = (seL4_SlotRegion) {
        slot_pos_start, slot_pos_end
    };
}

lookupCap_ret_t
lookupCap(tcb_t *thread, cptr_t cPtr)
{
    lookupSlot_raw_ret_t lu_ret;
    lookupCap_ret_t ret;

    lu_ret = lookupSlot(thread, cPtr);
    if (__builtin_expect(!!(lu_ret.status != EXCEPTION_NONE), 0)) {
        ret.status = lu_ret.status;
        ret.cap = cap_null_cap_new();
        return ret;
    }

    ret.status = EXCEPTION_NONE;
    ret.cap = lu_ret.slot->cap;
    return ret;
}

lookupCapAndSlot_ret_t
lookupCapAndSlot(tcb_t *thread, cptr_t cPtr)
{
    lookupSlot_raw_ret_t lu_ret;
    lookupCapAndSlot_ret_t ret;

    lu_ret = lookupSlot(thread, cPtr);
    if (__builtin_expect(!!(lu_ret.status != EXCEPTION_NONE), 0)) {
        ret.status = lu_ret.status;
        ret.slot = ((void *)0);
        ret.cap = cap_null_cap_new();
        return ret;
    }

    ret.status = EXCEPTION_NONE;
    ret.slot = lu_ret.slot;
    ret.cap = lu_ret.slot->cap;
    return ret;
}

lookupSlot_raw_ret_t
lookupSlot(tcb_t *thread, cptr_t capptr)
{
    cap_t threadRoot;
    resolveAddressBits_ret_t res_ret;
    lookupSlot_raw_ret_t ret;

    threadRoot = (((cte_t *)((word_t)(thread)&~((1ul << (11))-1ul)))+(tcbCTable))->cap;
    res_ret = resolveAddressBits(threadRoot, capptr, (1 << 6));

    ret.status = res_ret.status;
    ret.slot = res_ret.slot;
    return ret;
}

lookupSlot_ret_t
lookupSlotForCNodeOp(bool_t isSource, cap_t root, cptr_t capptr,
                     word_t depth)
{
    resolveAddressBits_ret_t res_ret;
    lookupSlot_ret_t ret;

    ret.slot = ((void *)0);

    if (__builtin_expect(!!(cap_get_capType(root) != cap_cnode_cap), 0)) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = isSource;
        current_lookup_fault = lookup_fault_invalid_root_new();
        ret.status = EXCEPTION_SYSCALL_ERROR;
        return ret;
    }

    if (__builtin_expect(!!(depth < 1 || depth > (1 << 6)), 0)) {
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 1;
        current_syscall_error.rangeErrorMax = (1 << 6);
        ret.status = EXCEPTION_SYSCALL_ERROR;
        return ret;
    }
    res_ret = resolveAddressBits(root, capptr, depth);
    if (__builtin_expect(!!(res_ret.status != EXCEPTION_NONE), 0)) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = isSource;

        ret.status = EXCEPTION_SYSCALL_ERROR;
        return ret;
    }

    if (__builtin_expect(!!(res_ret.bitsRemaining != 0), 0)) {
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = isSource;
        current_lookup_fault =
            lookup_fault_depth_mismatch_new(0, res_ret.bitsRemaining);
        ret.status = EXCEPTION_SYSCALL_ERROR;
        return ret;
    }

    ret.slot = res_ret.slot;
    ret.status = EXCEPTION_NONE;
    return ret;
}

lookupSlot_ret_t
lookupSourceSlot(cap_t root, cptr_t capptr, word_t depth)
{
    return lookupSlotForCNodeOp(true, root, capptr, depth);
}

lookupSlot_ret_t
lookupTargetSlot(cap_t root, cptr_t capptr, word_t depth)
{
    return lookupSlotForCNodeOp(false, root, capptr, depth);
}

lookupSlot_ret_t
lookupPivotSlot(cap_t root, cptr_t capptr, word_t depth)
{
    return lookupSlotForCNodeOp(true, root, capptr, depth);
}

resolveAddressBits_ret_t
resolveAddressBits(cap_t nodeCap, cptr_t capptr, word_t n_bits)
{
    resolveAddressBits_ret_t ret;
    word_t radixBits, guardBits, levelBits, guard;
    word_t capGuard, offset;
    cte_t *slot;

    ret.bitsRemaining = n_bits;
    ret.slot = ((void *)0);

    if (__builtin_expect(!!(cap_get_capType(nodeCap) != cap_cnode_cap), 0)) {
        current_lookup_fault = lookup_fault_invalid_root_new();
        ret.status = EXCEPTION_LOOKUP_FAULT;
        return ret;
    }

    while (1) {
        radixBits = cap_cnode_cap_get_capCNodeRadix(nodeCap);
        guardBits = cap_cnode_cap_get_capCNodeGuardSize(nodeCap);
        levelBits = radixBits + guardBits;


        if(!(levelBits != 0)) _assert_fail("levelBits != 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/kernel/cspace.c", 160, __FUNCTION__);

        capGuard = cap_cnode_cap_get_capCNodeGuard(nodeCap);





        guard = (capptr >> ((n_bits - guardBits) & ((1ul << (6))-1ul))) & ((1ul << (guardBits))-1ul);
        if (__builtin_expect(!!(guardBits > n_bits || guard != capGuard), 0)) {
            current_lookup_fault =
                lookup_fault_guard_mismatch_new(capGuard, n_bits, guardBits);
            ret.status = EXCEPTION_LOOKUP_FAULT;
            return ret;
        }

        if (__builtin_expect(!!(levelBits > n_bits), 0)) {
            current_lookup_fault =
                lookup_fault_depth_mismatch_new(levelBits, n_bits);
            ret.status = EXCEPTION_LOOKUP_FAULT;
            return ret;
        }

        offset = (capptr >> (n_bits - levelBits)) & ((1ul << (radixBits))-1ul);
        slot = ((cte_t *)(cap_cnode_cap_get_capCNodePtr(nodeCap))) + offset;

        if (__builtin_expect(!!(n_bits <= levelBits), 1)) {
            ret.status = EXCEPTION_NONE;
            ret.slot = slot;
            ret.bitsRemaining = 0;
            return ret;
        }



        n_bits -= levelBits;
        nodeCap = slot->cap;

        if (__builtin_expect(!!(cap_get_capType(nodeCap) != cap_cnode_cap), 0)) {
            ret.status = EXCEPTION_NONE;
            ret.slot = slot;
            ret.bitsRemaining = n_bits;
            return ret;
        }
    }

    ret.status = EXCEPTION_NONE;
    return ret;
}

void
handleFault(tcb_t *tptr)
{
    exception_t status;
    seL4_Fault_t fault = current_fault;

    status = sendFaultIPC(tptr);
    if (status != EXCEPTION_NONE) {
        handleDoubleFault(tptr, fault);
    }
}

exception_t
sendFaultIPC(tcb_t *tptr)
{
    cptr_t handlerCPtr;
    cap_t handlerCap;
    lookupCap_ret_t lu_ret;
    lookup_fault_t original_lookup_fault;

    original_lookup_fault = current_lookup_fault;

    handlerCPtr = tptr->tcbFaultHandler;
    lu_ret = lookupCap(tptr, handlerCPtr);
    if (lu_ret.status != EXCEPTION_NONE) {
        current_fault = seL4_Fault_CapFault_new(handlerCPtr, false);
        return EXCEPTION_FAULT;
    }
    handlerCap = lu_ret.cap;

    if (cap_get_capType(handlerCap) == cap_endpoint_cap &&
            cap_endpoint_cap_get_capCanSend(handlerCap) &&
            cap_endpoint_cap_get_capCanGrant(handlerCap)) {
        tptr->tcbFault = current_fault;
        if (seL4_Fault_get_seL4_FaultType(current_fault) == seL4_Fault_CapFault) {
            tptr->tcbLookupFailure = original_lookup_fault;
        }
        sendIPC(true, false,
                cap_endpoint_cap_get_capEPBadge(handlerCap),
                true, tptr,
                ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(handlerCap))));

        return EXCEPTION_NONE;
    } else {
        current_fault = seL4_Fault_CapFault_new(handlerCPtr, false);
        current_lookup_fault = lookup_fault_missing_capability_new(0);

        return EXCEPTION_FAULT;
    }
}


static void
print_fault(seL4_Fault_t f)
{
    switch (seL4_Fault_get_seL4_FaultType(f)) {
    case seL4_Fault_NullFault:
        kprintf("null fault");
        break;
    case seL4_Fault_CapFault:
        kprintf("cap fault in %s phase at address 0x%x", seL4_Fault_CapFault_get_inReceivePhase(f) ? "receive" : "send", (unsigned int)seL4_Fault_CapFault_get_address(f))

                                                                ;
        break;
    case seL4_Fault_VMFault:
        kprintf("vm fault on %s at address 0x%x with status 0x%x", seL4_Fault_VMFault_get_instructionFault(f) ? "code" : "data", (unsigned int)seL4_Fault_VMFault_get_address(f), (unsigned int)seL4_Fault_VMFault_get_FSR(f))


                                                           ;
        break;
    case seL4_Fault_UnknownSyscall:
        kprintf("unknown syscall 0x%x", (unsigned int)seL4_Fault_UnknownSyscall_get_syscallNumber(f))
                                                                            ;
        break;
    case seL4_Fault_UserException:
        kprintf("user exception 0x%x code 0x%x", (unsigned int)seL4_Fault_UserException_get_number(f), (unsigned int)seL4_Fault_UserException_get_code(f))

                                                                  ;
        break;
    default:
        kprintf("unknown fault");
        break;
    }
}



void
handleDoubleFault(tcb_t *tptr, seL4_Fault_t ex1)
{

    seL4_Fault_t ex2 = current_fault;
    kprintf("Caught ");
    print_fault(ex2);
    kprintf("\nwhile trying to handle:\n");
    print_fault(ex1);


    kprintf("\nin thread %p \"%s\" ", tptr, tptr->tcbName);


    kprintf("at address %p\n", (void*)getRestartPC(tptr));
    kprintf("With stack:\n");
    Arch_userStackTrace(tptr);


    setThreadState(tptr, ThreadState_Inactive);
}

__attribute__((externally_visible)) __attribute__((__aligned__(16)))
char kernel_stack_alloc[16][(1ul << (12))];

static seL4_MessageInfo_t
transferCaps(seL4_MessageInfo_t info, extra_caps_t caps,
             endpoint_t *endpoint, tcb_t *receiver,
             word_t *receiveBuffer);

static inline bool_t __attribute__((__pure__))
isBlocked(const tcb_t *thread)
{
    switch (thread_state_get_tsType(thread->tcbState)) {
    case ThreadState_Inactive:
    case ThreadState_BlockedOnReceive:
    case ThreadState_BlockedOnSend:
    case ThreadState_BlockedOnNotification:
    case ThreadState_BlockedOnReply:
        return true;

    default:
        return false;
    }
}

__attribute__((__section__(".boot.text"))) void
configureIdleThread(tcb_t *tcb)
{
    Arch_configureIdleThread(tcb);
    setThreadState(tcb, ThreadState_IdleThreadState);
}

void
activateThread(void)
{
    switch (thread_state_get_tsType(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbState)) {
    case ThreadState_Running:

    case ThreadState_RunningVM:

        break;

    case ThreadState_Restart: {
        word_t pc;

        pc = getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
        setNextPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, pc);
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Running);
        break;
    }

    case ThreadState_IdleThreadState:
        Arch_activateIdleThread(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
        break;

    default:
        _fail("Current thread is blocked", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/kernel/thread.c", 77, __func__);
    }
}

void
suspend(tcb_t *target)
{
    cancelIPC(target);
    setThreadState(target, ThreadState_Inactive);
    tcbSchedDequeue(target);
}

void
restart(tcb_t *target)
{
    if (isBlocked(target)) {
        cancelIPC(target);
        setupReplyMaster(target);
        setThreadState(target, ThreadState_Restart);
        do { tcbSchedEnqueue(target); remoteQueueUpdate(target); } while (0);
        possibleSwitchTo(target);
    }
}

void
doIPCTransfer(tcb_t *sender, endpoint_t *endpoint, word_t badge,
              bool_t grant, tcb_t *receiver)
{
    void *receiveBuffer, *sendBuffer;

    receiveBuffer = lookupIPCBuffer(true, receiver);

    if (__builtin_expect(!!(seL4_Fault_get_seL4_FaultType(sender->tcbFault) == seL4_Fault_NullFault), 1)) {
        sendBuffer = lookupIPCBuffer(false, sender);
        doNormalTransfer(sender, sendBuffer, endpoint, badge, grant,
                         receiver, receiveBuffer);
    } else {
        doFaultTransfer(badge, sender, receiver, receiveBuffer);
    }
}

void
doReplyTransfer(tcb_t *sender, tcb_t *receiver, cte_t *slot)
{
    if(!(thread_state_get_tsType(receiver->tcbState) == ThreadState_BlockedOnReply)) _assert_fail("thread_state_get_tsType(receiver->tcbState) == ThreadState_BlockedOnReply",
                                     "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/kernel/thread.c"
    ,
                                     122
    , __FUNCTION__)
                                      ;

    if (__builtin_expect(!!(seL4_Fault_get_seL4_FaultType(receiver->tcbFault) == seL4_Fault_NullFault), 1)) {
        doIPCTransfer(sender, ((void *)0), 0, true, receiver);

        cteDeleteOne(slot);
        setThreadState(receiver, ThreadState_Running);
        possibleSwitchTo(receiver);
    } else {
        bool_t restart;


        cteDeleteOne(slot);
        restart = handleFaultReply(receiver, sender);
        receiver->tcbFault = seL4_Fault_NullFault_new();
        if (restart) {
            setThreadState(receiver, ThreadState_Restart);
            possibleSwitchTo(receiver);
        } else {
            setThreadState(receiver, ThreadState_Inactive);
        }
    }
}

void
doNormalTransfer(tcb_t *sender, word_t *sendBuffer, endpoint_t *endpoint,
                 word_t badge, bool_t canGrant, tcb_t *receiver,
                 word_t *receiveBuffer)
{
    word_t msgTransferred;
    seL4_MessageInfo_t tag;
    exception_t status;
    extra_caps_t caps;

    tag = messageInfoFromWord(getRegister(sender, msgInfoRegister));

    if (canGrant) {
        status = lookupExtraCaps(sender, sendBuffer, tag);
        caps = current_extra_caps;
        if (__builtin_expect(!!(status != EXCEPTION_NONE), 0)) {
            caps.excaprefs[0] = ((void *)0);
        }
    } else {
        caps = current_extra_caps;
        caps.excaprefs[0] = ((void *)0);
    }

    msgTransferred = copyMRs(sender, sendBuffer, receiver, receiveBuffer,
                             seL4_MessageInfo_get_length(tag));

    tag = transferCaps(tag, caps, endpoint, receiver, receiveBuffer);

    tag = seL4_MessageInfo_set_length(tag, msgTransferred);
    setRegister(receiver, msgInfoRegister, wordFromMessageInfo(tag));
    setRegister(receiver, badgeRegister, badge);
}

void
doFaultTransfer(word_t badge, tcb_t *sender, tcb_t *receiver,
                word_t *receiverIPCBuffer)
{
    word_t sent;
    seL4_MessageInfo_t msgInfo;

    sent = setMRs_fault(sender, receiver, receiverIPCBuffer);
    msgInfo = seL4_MessageInfo_new(
                  seL4_Fault_get_seL4_FaultType(sender->tcbFault), 0, 0, sent);
    setRegister(receiver, msgInfoRegister, wordFromMessageInfo(msgInfo));
    setRegister(receiver, badgeRegister, badge);
}


static seL4_MessageInfo_t
transferCaps(seL4_MessageInfo_t info, extra_caps_t caps,
             endpoint_t *endpoint, tcb_t *receiver,
             word_t *receiveBuffer)
{
    word_t i;
    cte_t* destSlot;

    info = seL4_MessageInfo_set_extraCaps(info, 0);
    info = seL4_MessageInfo_set_capsUnwrapped(info, 0);

    if (__builtin_expect(!!(!caps.excaprefs[0] || !receiveBuffer), 1)) {
        return info;
    }

    destSlot = getReceiveSlots(receiver, receiveBuffer);

    for (i = 0; i < ((1ul<<(seL4_MsgExtraCapBits))-1) && caps.excaprefs[i] != ((void *)0); i++) {
        cte_t *slot = caps.excaprefs[i];
        cap_t cap = slot->cap;

        if (cap_get_capType(cap) == cap_endpoint_cap &&
                ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(cap))) == endpoint) {


            setExtraBadge(receiveBuffer,
                          cap_endpoint_cap_get_capEPBadge(cap), i);

            info = seL4_MessageInfo_set_capsUnwrapped(info,
                                                      seL4_MessageInfo_get_capsUnwrapped(info) | (1 << i));

        } else {
            deriveCap_ret_t dc_ret;

            if (!destSlot) {
                break;
            }

            dc_ret = deriveCap(slot, cap);

            if (dc_ret.status != EXCEPTION_NONE) {
                break;
            }
            if (cap_get_capType(dc_ret.cap) == cap_null_cap) {
                break;
            }

            cteInsert(dc_ret.cap, slot, destSlot);

            destSlot = ((void *)0);
        }
    }

    return seL4_MessageInfo_set_extraCaps(info, i);
}

void doNBRecvFailedTransfer(tcb_t *thread)
{

    setRegister(thread, badgeRegister, 0);
}

static void
nextDomain(void)
{
    ksDomScheduleIdx++;
    if (ksDomScheduleIdx >= ksDomScheduleLength) {
        ksDomScheduleIdx = 0;
    }
    ksWorkUnitsCompleted = 0;
    ksCurDomain = ksDomSchedule[ksDomScheduleIdx].domain;
    ksDomainTime = ksDomSchedule[ksDomScheduleIdx].length;
}

static void
scheduleChooseNewThread(void)
{
    if (ksDomainTime == 0) {
        nextDomain();
    }
    chooseThread();
}

void
schedule(void)
{
    if (ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction != ((tcb_t*)0)) {
        bool_t was_runnable;
        if (isRunnable(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)) {
            was_runnable = true;
            tcbSchedEnqueue(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
        } else {
            was_runnable = false;
        }

        if (ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction == ((tcb_t*) 1)) {
            scheduleChooseNewThread();
        } else {
            tcb_t *candidate = ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction;




            bool_t fastfail =
                ksSMP[(getCurrentCPUIndex())].system.ksCurThread == ksSMP[(getCurrentCPUIndex())].system.ksIdleThread
                || (candidate->tcbPriority < ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbPriority);
            if (fastfail &&
                    !isHighestPrio(ksCurDomain, candidate->tcbPriority)) {
                do { tcbSchedEnqueue(candidate); remoteQueueUpdate(candidate); } while (0);

                ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction = ((tcb_t*) 1);
                scheduleChooseNewThread();
            } else if (was_runnable && candidate->tcbPriority == ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbPriority) {



                do { tcbSchedAppend(candidate); remoteQueueUpdate(candidate); } while (0);
                ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction = ((tcb_t*) 1);
                scheduleChooseNewThread();
            } else {
                if(!(candidate != ksSMP[(getCurrentCPUIndex())].system.ksCurThread)) _assert_fail("candidate != NODE_STATE(ksCurThread)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/kernel/thread.c", 314, __FUNCTION__);
                switchToThread(candidate);
            }
        }
    }
    ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction = ((tcb_t*)0);

    doMaskReschedule(ksSMP[(getCurrentCPUIndex())].cpu.ipiReschedulePending);
    ksSMP[(getCurrentCPUIndex())].cpu.ipiReschedulePending = 0;

}

void
chooseThread(void)
{
    word_t prio;
    word_t dom;
    tcb_t *thread;

    if (1 > 1) {
        dom = ksCurDomain;
    } else {
        dom = 0;
    }

    if (__builtin_expect(!!(ksSMP[(getCurrentCPUIndex())].system.ksReadyQueuesL1Bitmap[dom]), 1)) {
        prio = getHighestPrio(dom);
        thread = ksSMP[(getCurrentCPUIndex())].system.ksReadyQueues[ready_queues_index(dom, prio)].head;
        if(!(thread)) _assert_fail("thread", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/kernel/thread.c", 342, __FUNCTION__);
        if(!(isRunnable(thread))) _assert_fail("isRunnable(thread)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/kernel/thread.c", 343, __FUNCTION__);
        switchToThread(thread);
    } else {
        switchToIdleThread();
    }
}

void
switchToThread(tcb_t *thread)
{

    benchmark_utilisation_switch(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, thread);

    Arch_switchToThread(thread);
    tcbSchedDequeue(thread);
    ksSMP[(getCurrentCPUIndex())].system.ksCurThread = thread;
}

void
switchToIdleThread(void)
{

    benchmark_utilisation_switch(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksIdleThread);

    Arch_switchToIdleThread();
    ksSMP[(getCurrentCPUIndex())].system.ksCurThread = ksSMP[(getCurrentCPUIndex())].system.ksIdleThread;
}

void
setDomain(tcb_t *tptr, dom_t dom)
{
    tcbSchedDequeue(tptr);
    tptr->tcbDomain = dom;
    if (isRunnable(tptr)) {
        do { tcbSchedEnqueue(tptr); remoteQueueUpdate(tptr); } while (0);
    }
    if (tptr == ksSMP[(getCurrentCPUIndex())].system.ksCurThread) {
        rescheduleRequired();
    }
}

void
setMCPriority(tcb_t *tptr, prio_t mcp)
{
    tptr->tcbMCP = mcp;
}

void
setPriority(tcb_t *tptr, prio_t prio)
{
    tcbSchedDequeue(tptr);
    tptr->tcbPriority = prio;
    if (isRunnable(tptr)) {
        do { tcbSchedEnqueue(tptr); remoteQueueUpdate(tptr); } while (0);
        rescheduleRequired();
    }
}





void
possibleSwitchTo(tcb_t* target)
{
    if (ksCurDomain != target->tcbDomain
            || target->tcbAffinity != getCurrentCPUIndex()) {
        do { tcbSchedEnqueue(target); remoteQueueUpdate(target); } while (0);
    } else if (ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction != ((tcb_t*)0)) {

        rescheduleRequired();
        do { tcbSchedEnqueue(target); remoteQueueUpdate(target); } while (0);
    } else {
        ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction = target;
    }
}

void
setThreadState(tcb_t *tptr, _thread_state_t ts)
{
    thread_state_ptr_set_tsType(&tptr->tcbState, ts);
    scheduleTCB(tptr);
}

void
scheduleTCB(tcb_t *tptr)
{
    if (tptr == ksSMP[(getCurrentCPUIndex())].system.ksCurThread &&
            ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction == ((tcb_t*)0) &&
            !isRunnable(tptr)) {
        rescheduleRequired();
    }
}

void
timerTick(void)
{
    switch (thread_state_get_tsType(ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbState)) {
    case ThreadState_Running:

    case ThreadState_RunningVM:

        if (ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbTimeSlice > 1) {
            ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbTimeSlice--;
        } else {
            ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbTimeSlice = 1;
            tcbSchedAppend(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
            rescheduleRequired();
        }
        break;
    default:

        break;
    }

    if (1 > 1) {
        ksDomainTime--;
        if (ksDomainTime == 0) {
            rescheduleRequired();
        }
    }
}

void
rescheduleRequired(void)
{
    if (ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction != ((tcb_t*)0)
            && ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction != ((tcb_t*) 1)) {
        do { tcbSchedEnqueue(ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction); remoteQueueUpdate(ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction); } while (0);
    }
    ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction = ((tcb_t*) 1);
}



void switchLocalFpuOwner(user_fpu_state_t *new_owner)
{
    enableFpu();
    if (ksSMP[(getCurrentCPUIndex())].system.ksActiveFPUState) {
        saveFpuState(ksSMP[(getCurrentCPUIndex())].system.ksActiveFPUState);
    }
    if (new_owner) {
        ksSMP[(getCurrentCPUIndex())].system.ksFPURestoresSinceSwitch = 0;
        loadFpuState(new_owner);
    } else {
        disableFpu();
    }
    ksSMP[(getCurrentCPUIndex())].system.ksActiveFPUState = new_owner;
}

void switchFpuOwner(user_fpu_state_t *new_owner, word_t cpu)
{

    if (cpu != getCurrentCPUIndex()) {
        doRemoteswitchFpuOwner(new_owner, cpu);
    } else

    {
        switchLocalFpuOwner(new_owner);
    }
}






exception_t
handleFPUFault(void)
{



    if(!(!nativeThreadUsingFPU(ksSMP[(getCurrentCPUIndex())].system.ksCurThread))) _assert_fail("!nativeThreadUsingFPU(NODE_STATE(ksCurThread))", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/machine/fpu.c", 59, __FUNCTION__);


    switchLocalFpuOwner(&ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbArch.tcbContext.fpuState);

    return EXCEPTION_NONE;
}


void fpuThreadDelete(tcb_t *thread)
{


    if (nativeThreadUsingFPU(thread)) {
        switchFpuOwner(((void *)0), thread->tcbAffinity);
    }
}



typedef __builtin_va_list va_list;

void
putchar(char c)
{
    putConsoleChar(c);
    if (c == '\n') {
        putConsoleChar('\r');
    }
}

static unsigned int
print_spaces(int n)
{
    for (int i = 0; i < n; i++) {
        putchar(' ');
    }

    return n;
}

static unsigned int
print_string(const char *s)
{
    unsigned int n;

    for (n = 0; *s; s++, n++) {
        putchar(*s);
    }

    return n;
}

static unsigned long
xdiv(unsigned long x, unsigned int denom)
{
    switch (denom) {
    case 16:
        return x / 16;
    case 10:
        return x / 10;
    default:
        return 0;
    }
}

static unsigned long
xmod(unsigned long x, unsigned int denom)
{
    switch (denom) {
    case 16:
        return x % 16;
    case 10:
        return x % 10;
    default:
        return 0;
    }
}

word_t
print_unsigned_long(unsigned long x, word_t ui_base)
{
    char out[sizeof(unsigned long) * 2 + 3];
    word_t i, j;
    unsigned int d;





    if (ui_base != 10 && ui_base != 16) {
        return 0;
    }

    if (x == 0) {
        putchar('0');
        return 1;
    }

    for (i = 0; x; x = xdiv(x, ui_base), i++) {
        d = xmod(x, ui_base);

        if (d >= 10) {
            out[i] = 'a' + d - 10;
        } else {
            out[i] = '0' + d;
        }
    }

    for (j = i; j > 0; j--) {
        putchar(out[j - 1]);
    }

    return i;
}



typedef int __assert_failed_print_unsigned_long_long_sizes[(sizeof(unsigned int) * 2 == sizeof(unsigned long long)) ? 1 : -1];

static unsigned int
print_unsigned_long_long(unsigned long long x, unsigned int ui_base)
{
    unsigned int upper, lower;
    unsigned int n = 0;
    unsigned int mask = 0xF0000000u;
    unsigned int shifts = 0;


    if (ui_base != 16) {
        return 0;
    }


    upper = (unsigned int) (x >> 32llu);
    lower = (unsigned int) x & 0xffffffff;


    if (upper > 0) {
        n += print_unsigned_long(upper, ui_base);

        while (!(mask & lower)) {
            putchar('0');
            n++;
            mask = mask >> 4;
            shifts++;
            if (shifts == 8) {
                break;
            }
        }
    }

    n += print_unsigned_long(lower, ui_base);

    return n;
}

static inline bool_t
isdigit(char c)
{
    return c >= '0' &&
           c <= '9';
}

static inline int
atoi(char c)
{
    return c - '0';
}

static int
vprintf(const char *format, va_list ap)
{
    unsigned int n;
    unsigned int formatting;
    int nspaces = 0;

    if (!format) {
        return 0;
    }

    n = 0;
    formatting = 0;
    while (*format) {
        if (formatting) {
            while (isdigit(*format)) {
                nspaces = nspaces * 10 + atoi(*format);
                format++;
                if (format == ((void *)0)) {
                    break;
                }
            }
            switch (*format) {
            case '%':
                putchar('%');
                n++;
                format++;
                break;

            case 'd': {
                int x = __builtin_va_arg(ap,int);

                if (x < 0) {
                    putchar('-');
                    n++;
                    x = -x;
                }

                n += print_unsigned_long(x, 10);
                format++;
                break;
            }

            case 'u':
                n += print_unsigned_long(__builtin_va_arg(ap,unsigned int), 10);
                format++;
                break;

            case 'x':
                n += print_unsigned_long(__builtin_va_arg(ap,unsigned int), 16);
                format++;
                break;

            case 'p': {
                unsigned long p = __builtin_va_arg(ap,unsigned long);
                if (p == 0) {
                    n += print_string("(nil)");
                } else {
                    n += print_string("0x");
                    n += print_unsigned_long(p, 16);
                }
                format++;
                break;
            }

            case 's':
                n += print_string(__builtin_va_arg(ap,char *));
                format++;
                break;

            case 'l':
                format++;
                switch (*format) {
                case 'd': {
                    long x = __builtin_va_arg(ap,long);

                    if (x < 0) {
                        putchar('-');
                        n++;
                        x = -x;
                    }

                    n += print_unsigned_long((unsigned long)x, 10);
                    format++;
                }
                break;
                case 'l':
                    if (*(format + 1) == 'x') {
                        n += print_unsigned_long_long(__builtin_va_arg(ap,unsigned long long), 16);
                    }
                    format += 2;
                    break;
                case 'u':
                    n += print_unsigned_long(__builtin_va_arg(ap,unsigned long), 10);
                    format++;
                    break;
                case 'x':
                    n += print_unsigned_long(__builtin_va_arg(ap,unsigned long), 16);
                    format++;
                    break;

                default:

                    return -1;
                }
                break;
            default:

                return -1;
            }

            n += print_spaces(nspaces - n);
            nspaces = 0;
            formatting = 0;
        } else {
            switch (*format) {
            case '%':
                formatting = 1;
                format++;
                break;

            default:
                putchar(*format);
                n++;
                format++;
                break;
            }
        }
    }

    return n;
}

word_t puts(const char *s)
{
    for (; *s; s++) {
        putchar(*s);
    }
    putchar('\n');
    return 0;
}

word_t
kprintf(const char *format, ...)
{
    va_list args;
    word_t i;

    __builtin_va_start(args,format);
    i = vprintf(format, args);
    __builtin_va_end(args);
    return i;
}

const register_t fault_messages[][(((n_syscallMessage)>(n_exceptionMessage))?(n_syscallMessage):(n_exceptionMessage))] = {
    [MessageID_Syscall] = { [seL4_UnknownSyscall_RAX] = RAX, [seL4_UnknownSyscall_RBX] = RBX, [seL4_UnknownSyscall_RCX] = RCX, [seL4_UnknownSyscall_RDX] = RDX, [seL4_UnknownSyscall_RSI] = RSI, [seL4_UnknownSyscall_RDI] = RDI, [seL4_UnknownSyscall_RBP] = RBP, [seL4_UnknownSyscall_R8] = R8, [seL4_UnknownSyscall_R9] = R9, [seL4_UnknownSyscall_R10] = R10, [seL4_UnknownSyscall_R11] = R11, [seL4_UnknownSyscall_R12] = R12, [seL4_UnknownSyscall_R13] = R13, [seL4_UnknownSyscall_R14] = R14, [seL4_UnknownSyscall_R15] = R15, [seL4_UnknownSyscall_FaultIP] = FaultIP, [seL4_UnknownSyscall_SP] = RSP, [seL4_UnknownSyscall_FLAGS] = FLAGS},
    [MessageID_Exception] = { [seL4_UserException_FaultIP] = FaultIP, [seL4_UserException_SP] = RSP, [seL4_UserException_FLAGS] = FLAGS}
};

exception_t preemptionPoint(void);




exception_t
preemptionPoint(void)
{

    ksWorkUnitsCompleted++;
    if (ksWorkUnitsCompleted >= 100) {
        ksWorkUnitsCompleted = 0;
        if (isIRQPending()) {
            return EXCEPTION_PREEMPTED;
        }
    }

    return EXCEPTION_NONE;
}



void migrateTCB(tcb_t *tcb, word_t new_core)
{

    tcbDebugRemove(tcb);

    Arch_migrateTCB(tcb);
    tcb->tcbAffinity = new_core;

    tcbDebugAppend(tcb);

}


smpStatedata_t ksSMP[16] __attribute__((__aligned__(64)));


word_t ksNumCPUs;


;
;
;
typedef int __assert_failed_ksReadyQueuesL1BitmapBigEnough[((((256 + (1 << 6) - 1) / (1 << 6)) - 1) <= (1 << 6)) ? 1 : -1];


;


;




;



;

;



;




word_t ksWorkUnitsCompleted;


irq_state_t intStateIRQTable[maxIRQ + 1];
cte_t *intStateIRQNode;


dom_t ksCurDomain;


word_t ksDomainTime;


word_t ksDomScheduleIdx;


word_t tlbLockCount = 0;


kernel_entry_t ksKernelEntry;

struct finaliseSlot_ret {
    exception_t status;
    bool_t success;
    cap_t cleanupInfo;
};
typedef struct finaliseSlot_ret finaliseSlot_ret_t;

static finaliseSlot_ret_t finaliseSlot(cte_t *slot, bool_t exposed);
static void emptySlot(cte_t *slot, cap_t cleanupInfo);
static exception_t reduceZombie(cte_t* slot, bool_t exposed);

exception_t
decodeCNodeInvocation(word_t invLabel, word_t length, cap_t cap,
                      extra_caps_t excaps, word_t *buffer)
{
    lookupSlot_ret_t lu_ret;
    cte_t *destSlot;
    word_t index, w_bits;
    exception_t status;


    if(!(cap_get_capType(cap) == cap_cnode_cap)) _assert_fail("cap_get_capType(cap) == cap_cnode_cap", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 50, __FUNCTION__);

    if (invLabel < CNodeRevoke || invLabel > CNodeSaveCaller) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 53, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNodeCap: Illegal Operation attempted."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (length < 2) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 59, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode operation: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }
    index = getSyscallArg(0, buffer);
    w_bits = getSyscallArg(1, buffer);

    lu_ret = lookupTargetSlot(cap, index, w_bits);
    if (lu_ret.status != EXCEPTION_NONE) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 68, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode operation: Target slot invalid."); kprintf(">>" "" "\n"); } while (0);
        return lu_ret.status;
    }
    destSlot = lu_ret.slot;

    if (invLabel >= CNodeCopy && invLabel <= CNodeMutate) {
        cte_t *srcSlot;
        word_t srcIndex, srcDepth, capData;
        bool_t isMove;
        seL4_CapRights_t cap_rights;
        cap_t srcRoot, newCap;
        deriveCap_ret_t dc_ret;
        cap_t srcCap;

        if (length < 4 || excaps.excaprefs[0] == ((void *)0)) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 83, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode Copy/Mint/Move/Mutate: Truncated message."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }
        srcIndex = getSyscallArg(2, buffer);
        srcDepth = getSyscallArg(3, buffer);

        srcRoot = excaps.excaprefs[0]->cap;

        status = ensureEmptySlot(destSlot);
        if (status != EXCEPTION_NONE) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 94, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode Copy/Mint/Move/Mutate: Destination not empty."); kprintf(">>" "" "\n"); } while (0);
            return status;
        }

        lu_ret = lookupSourceSlot(srcRoot, srcIndex, srcDepth);
        if (lu_ret.status != EXCEPTION_NONE) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 100, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode Copy/Mint/Move/Mutate: Invalid source slot."); kprintf(">>" "" "\n"); } while (0);
            return lu_ret.status;
        }
        srcSlot = lu_ret.slot;

        if (cap_get_capType(srcSlot->cap) == cap_null_cap) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 106, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode Copy/Mint/Move/Mutate: Source slot invalid or empty."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = 1;
            current_lookup_fault =
                lookup_fault_missing_capability_new(srcDepth);
            return EXCEPTION_SYSCALL_ERROR;
        }

        switch (invLabel) {
        case CNodeCopy:

            if (length < 5) {
                do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 118, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Truncated message for CNode Copy operation."); kprintf(">>" "" "\n"); } while (0);
                current_syscall_error.type = seL4_TruncatedMessage;
                return EXCEPTION_SYSCALL_ERROR;
            }

            cap_rights = rightsFromWord(getSyscallArg(4, buffer));
            srcCap = maskCapRights(cap_rights, srcSlot->cap);
            dc_ret = deriveCap(srcSlot, srcCap);
            if (dc_ret.status != EXCEPTION_NONE) {
                do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 127, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Error deriving cap for CNode Copy operation."); kprintf(">>" "" "\n"); } while (0);
                return dc_ret.status;
            }
            newCap = dc_ret.cap;
            isMove = false;

            break;

        case CNodeMint:
            if (length < 6) {
                do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 137, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode Mint: Truncated message."); kprintf(">>" "" "\n"); } while (0);
                current_syscall_error.type = seL4_TruncatedMessage;
                return EXCEPTION_SYSCALL_ERROR;
            }

            cap_rights = rightsFromWord(getSyscallArg(4, buffer));
            capData = getSyscallArg(5, buffer);
            srcCap = maskCapRights(cap_rights, srcSlot->cap);
            dc_ret = deriveCap(srcSlot,
                               updateCapData(false, capData, srcCap));
            if (dc_ret.status != EXCEPTION_NONE) {
                do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 148, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Error deriving cap for CNode Mint operation."); kprintf(">>" "" "\n"); } while (0);
                return dc_ret.status;
            }
            newCap = dc_ret.cap;
            isMove = false;

            break;

        case CNodeMove:
            newCap = srcSlot->cap;
            isMove = true;

            break;

        case CNodeMutate:
            if (length < 5) {
                do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 164, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode Mutate: Truncated message."); kprintf(">>" "" "\n"); } while (0);
                current_syscall_error.type = seL4_TruncatedMessage;
                return EXCEPTION_SYSCALL_ERROR;
            }

            capData = getSyscallArg(4, buffer);
            newCap = updateCapData(true, capData, srcSlot->cap);
            isMove = true;

            break;

        default:
            if(!(0)) _assert_fail("0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 176, __FUNCTION__);
            return EXCEPTION_NONE;
        }

        if (cap_get_capType(newCap) == cap_null_cap) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 181, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode Copy/Mint/Move/Mutate: Mutated cap would be invalid."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        if (isMove) {
            return invokeCNodeMove(newCap, srcSlot, destSlot);
        } else {
            return invokeCNodeInsert(newCap, srcSlot, destSlot);
        }
    }

    if (invLabel == CNodeRevoke) {
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return invokeCNodeRevoke(destSlot);
    }

    if (invLabel == CNodeDelete) {
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return invokeCNodeDelete(destSlot);
    }

    if (invLabel == CNodeSaveCaller) {
        status = ensureEmptySlot(destSlot);
        if (status != EXCEPTION_NONE) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 207, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode SaveCaller: Destination slot not empty."); kprintf(">>" "" "\n"); } while (0);
            return status;
        }

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return invokeCNodeSaveCaller(destSlot);
    }

    if (invLabel == CNodeCancelBadgedSends) {
        cap_t destCap;

        destCap = destSlot->cap;

        if (!hasCancelSendRights(destCap)) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 221, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode CancelBadgedSends: Target cap invalid."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return invokeCNodeCancelBadgedSends(destCap);
    }

    if (invLabel == CNodeRotate) {
        word_t pivotNewData, pivotIndex, pivotDepth;
        word_t srcNewData, srcIndex, srcDepth;
        cte_t *pivotSlot, *srcSlot;
        cap_t pivotRoot, srcRoot, newSrcCap, newPivotCap;

        if (length < 8 || excaps.excaprefs[0] == ((void *)0)
                || excaps.excaprefs[1] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }
        pivotNewData = getSyscallArg(2, buffer);
        pivotIndex = getSyscallArg(3, buffer);
        pivotDepth = getSyscallArg(4, buffer);
        srcNewData = getSyscallArg(5, buffer);
        srcIndex = getSyscallArg(6, buffer);
        srcDepth = getSyscallArg(7, buffer);

        pivotRoot = excaps.excaprefs[0]->cap;
        srcRoot = excaps.excaprefs[1]->cap;

        lu_ret = lookupSourceSlot(srcRoot, srcIndex, srcDepth);
        if (lu_ret.status != EXCEPTION_NONE) {
            return lu_ret.status;
        }
        srcSlot = lu_ret.slot;

        lu_ret = lookupPivotSlot(pivotRoot, pivotIndex, pivotDepth);
        if (lu_ret.status != EXCEPTION_NONE) {
            return lu_ret.status;
        }
        pivotSlot = lu_ret.slot;

        if (pivotSlot == srcSlot || pivotSlot == destSlot) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 263, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode Rotate: Pivot slot the same as source or dest slot."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (srcSlot != destSlot) {
            status = ensureEmptySlot(destSlot);
            if (status != EXCEPTION_NONE) {
                return status;
            }
        }

        if (cap_get_capType(srcSlot->cap) == cap_null_cap) {
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = 1;
            current_lookup_fault = lookup_fault_missing_capability_new(srcDepth);
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (cap_get_capType(pivotSlot->cap) == cap_null_cap) {
            current_syscall_error.type = seL4_FailedLookup;
            current_syscall_error.failedLookupWasSource = 0;
            current_lookup_fault = lookup_fault_missing_capability_new(pivotDepth);
            return EXCEPTION_SYSCALL_ERROR;
        }

        newSrcCap = updateCapData(true, srcNewData, srcSlot->cap);
        newPivotCap = updateCapData(true, pivotNewData, pivotSlot->cap);

        if (cap_get_capType(newSrcCap) == cap_null_cap) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 293, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode Rotate: Source cap invalid."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }

        if (cap_get_capType(newPivotCap) == cap_null_cap) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 299, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode Rotate: Pivot cap invalid."); kprintf(">>" "" "\n"); } while (0);
            current_syscall_error.type = seL4_IllegalOperation;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return invokeCNodeRotate(newSrcCap, newPivotCap,
                                 srcSlot, pivotSlot, destSlot);
    }

    return EXCEPTION_NONE;
}

exception_t
invokeCNodeRevoke(cte_t *destSlot)
{
    return cteRevoke(destSlot);
}

exception_t
invokeCNodeDelete(cte_t *destSlot)
{
    return cteDelete(destSlot, true);
}

exception_t
invokeCNodeCancelBadgedSends(cap_t cap)
{
    word_t badge = cap_endpoint_cap_get_capEPBadge(cap);
    if (badge) {
        endpoint_t* ep = (endpoint_t*)
                         cap_endpoint_cap_get_capEPPtr(cap);
        cancelBadgedSends(ep, badge);
    }
    return EXCEPTION_NONE;
}

exception_t
invokeCNodeInsert(cap_t cap, cte_t *srcSlot, cte_t *destSlot)
{
    cteInsert(cap, srcSlot, destSlot);

    return EXCEPTION_NONE;
}

exception_t
invokeCNodeMove(cap_t cap, cte_t *srcSlot, cte_t *destSlot)
{
    cteMove(cap, srcSlot, destSlot);

    return EXCEPTION_NONE;
}

exception_t
invokeCNodeRotate(cap_t cap1, cap_t cap2, cte_t *slot1,
                  cte_t *slot2, cte_t *slot3)
{
    if (slot1 == slot3) {
        cteSwap(cap1, slot1, cap2, slot2);
    } else {
        cteMove(cap2, slot2, slot3);
        cteMove(cap1, slot1, slot2);
    }

    return EXCEPTION_NONE;
}

exception_t
invokeCNodeSaveCaller(cte_t *destSlot)
{
    cap_t cap;
    cte_t *srcSlot;

    srcSlot = (((cte_t *)((word_t)(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)&~((1ul << (11))-1ul)))+(tcbCaller));
    cap = srcSlot->cap;

    switch (cap_get_capType(cap)) {
    case cap_null_cap:
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 377, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("CNode SaveCaller: Reply cap not present."); kprintf(">>" "" "\n"); } while (0);
        break;

    case cap_reply_cap:
        if (!cap_reply_cap_get_capReplyMaster(cap)) {
            cteMove(cap, srcSlot, destSlot);
        }
        break;

    default:
        _fail("caller capability must be null or reply", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 387, __func__);
        break;
    }

    return EXCEPTION_NONE;
}





static void
setUntypedCapAsFull(cap_t srcCap, cap_t newCap, cte_t *srcSlot)
{
    if ((cap_get_capType(srcCap) == cap_untyped_cap)
            && (cap_get_capType(newCap) == cap_untyped_cap)) {
        if ((cap_untyped_cap_get_capPtr(srcCap)
                == cap_untyped_cap_get_capPtr(newCap))
                && (cap_untyped_cap_get_capBlockSize(newCap)
                    == cap_untyped_cap_get_capBlockSize(srcCap))) {
            cap_untyped_cap_ptr_set_capFreeIndex(&(srcSlot->cap),
                                                 ((1ul << ((cap_untyped_cap_get_capBlockSize(srcCap)) - 4))));
        }
    }
}

void
cteInsert(cap_t newCap, cte_t *srcSlot, cte_t *destSlot)
{
    mdb_node_t srcMDB, newMDB;
    cap_t srcCap;
    bool_t newCapIsRevocable;

    srcMDB = srcSlot->cteMDBNode;
    srcCap = srcSlot->cap;

    switch (cap_get_capType(newCap)) {
    case cap_endpoint_cap:
        newCapIsRevocable = (cap_endpoint_cap_get_capEPBadge(newCap) !=
                             cap_endpoint_cap_get_capEPBadge(srcCap));
        break;

    case cap_notification_cap:
        newCapIsRevocable =
            (cap_notification_cap_get_capNtfnBadge(newCap) !=
             cap_notification_cap_get_capNtfnBadge(srcCap));
        break;

    case cap_irq_handler_cap:
        newCapIsRevocable = (cap_get_capType(srcCap) ==
                             cap_irq_control_cap);
        break;

    case cap_untyped_cap:
        newCapIsRevocable = true;
        break;

    default:
        newCapIsRevocable = false;
        break;
    }

    newMDB = mdb_node_set_mdbPrev(srcMDB, ((word_t)(srcSlot)));
    newMDB = mdb_node_set_mdbRevocable(newMDB, newCapIsRevocable);
    newMDB = mdb_node_set_mdbFirstBadged(newMDB, newCapIsRevocable);


    if(!(cap_get_capType(destSlot->cap) == cap_null_cap)) _assert_fail("cap_get_capType(destSlot->cap) == cap_null_cap", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 454, __FUNCTION__);

    if(!((cte_t*)mdb_node_get_mdbNext(destSlot->cteMDBNode) == ((void *)0) && (cte_t*)mdb_node_get_mdbPrev(destSlot->cteMDBNode) == ((void *)0))) _assert_fail("(cte_t*)mdb_node_get_mdbNext(destSlot->cteMDBNode) == NULL && (cte_t*)mdb_node_get_mdbPrev(destSlot->cteMDBNode) == NULL",
                                                                     "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c"
    ,
                                                                     457
    , __FUNCTION__)
                                                                      ;



    setUntypedCapAsFull(srcCap, newCap, srcSlot);

    destSlot->cap = newCap;
    destSlot->cteMDBNode = newMDB;
    mdb_node_ptr_set_mdbNext(&srcSlot->cteMDBNode, ((word_t)(destSlot)));
    if (mdb_node_get_mdbNext(newMDB)) {
        mdb_node_ptr_set_mdbPrev(
            &((cte_t *)(mdb_node_get_mdbNext(newMDB)))->cteMDBNode,
            ((word_t)(destSlot)));
    }
}

void
cteMove(cap_t newCap, cte_t *srcSlot, cte_t *destSlot)
{
    mdb_node_t mdb;
    word_t prev_ptr, next_ptr;


    if(!(cap_get_capType(destSlot->cap) == cap_null_cap)) _assert_fail("cap_get_capType(destSlot->cap) == cap_null_cap", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 480, __FUNCTION__);

    if(!((cte_t*)mdb_node_get_mdbNext(destSlot->cteMDBNode) == ((void *)0) && (cte_t*)mdb_node_get_mdbPrev(destSlot->cteMDBNode) == ((void *)0))) _assert_fail("(cte_t*)mdb_node_get_mdbNext(destSlot->cteMDBNode) == NULL && (cte_t*)mdb_node_get_mdbPrev(destSlot->cteMDBNode) == NULL",
                                                                     "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c"
    ,
                                                                     483
    , __FUNCTION__)
                                                                      ;

    mdb = srcSlot->cteMDBNode;
    destSlot->cap = newCap;
    srcSlot->cap = cap_null_cap_new();
    destSlot->cteMDBNode = mdb;
    srcSlot->cteMDBNode = mdb_node_new(0, false, false, 0);

    prev_ptr = mdb_node_get_mdbPrev(mdb);
    if (prev_ptr)
        mdb_node_ptr_set_mdbNext(
            &((cte_t *)(prev_ptr))->cteMDBNode,
            ((word_t)(destSlot)));

    next_ptr = mdb_node_get_mdbNext(mdb);
    if (next_ptr)
        mdb_node_ptr_set_mdbPrev(
            &((cte_t *)(next_ptr))->cteMDBNode,
            ((word_t)(destSlot)));
}

void
capSwapForDelete(cte_t *slot1, cte_t *slot2)
{
    cap_t cap1, cap2;

    if (slot1 == slot2) {
        return;
    }

    cap1 = slot1->cap;
    cap2 = slot2->cap;

    cteSwap(cap1, slot1, cap2, slot2);
}

void
cteSwap(cap_t cap1, cte_t *slot1, cap_t cap2, cte_t *slot2)
{
    mdb_node_t mdb1, mdb2;
    word_t next_ptr, prev_ptr;

    slot1->cap = cap2;
    slot2->cap = cap1;

    mdb1 = slot1->cteMDBNode;

    prev_ptr = mdb_node_get_mdbPrev(mdb1);
    if (prev_ptr)
        mdb_node_ptr_set_mdbNext(
            &((cte_t *)(prev_ptr))->cteMDBNode,
            ((word_t)(slot2)));

    next_ptr = mdb_node_get_mdbNext(mdb1);
    if (next_ptr)
        mdb_node_ptr_set_mdbPrev(
            &((cte_t *)(next_ptr))->cteMDBNode,
            ((word_t)(slot2)));

    mdb2 = slot2->cteMDBNode;
    slot1->cteMDBNode = mdb2;
    slot2->cteMDBNode = mdb1;

    prev_ptr = mdb_node_get_mdbPrev(mdb2);
    if (prev_ptr)
        mdb_node_ptr_set_mdbNext(
            &((cte_t *)(prev_ptr))->cteMDBNode,
            ((word_t)(slot1)));

    next_ptr = mdb_node_get_mdbNext(mdb2);
    if (next_ptr)
        mdb_node_ptr_set_mdbPrev(
            &((cte_t *)(next_ptr))->cteMDBNode,
            ((word_t)(slot1)));
}

exception_t
cteRevoke(cte_t *slot)
{
    cte_t *nextPtr;
    exception_t status;



    for (nextPtr = ((cte_t *)(mdb_node_get_mdbNext(slot->cteMDBNode)));
            nextPtr && isMDBParentOf(slot, nextPtr);
            nextPtr = ((cte_t *)(mdb_node_get_mdbNext(slot->cteMDBNode)))) {
        status = cteDelete(nextPtr, true);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        status = preemptionPoint();
        if (status != EXCEPTION_NONE) {
            return status;
        }
    }

    return EXCEPTION_NONE;
}

exception_t
cteDelete(cte_t *slot, bool_t exposed)
{
    finaliseSlot_ret_t fs_ret;

    fs_ret = finaliseSlot(slot, exposed);
    if (fs_ret.status != EXCEPTION_NONE) {
        return fs_ret.status;
    }

    if (exposed || fs_ret.success) {
        emptySlot(slot, fs_ret.cleanupInfo);
    }
    return EXCEPTION_NONE;
}

static void
emptySlot(cte_t *slot, cap_t cleanupInfo)
{
    if (cap_get_capType(slot->cap) != cap_null_cap) {
        mdb_node_t mdbNode;
        cte_t *prev, *next;

        mdbNode = slot->cteMDBNode;
        prev = ((cte_t *)(mdb_node_get_mdbPrev(mdbNode)));
        next = ((cte_t *)(mdb_node_get_mdbNext(mdbNode)));

        if (prev) {
            mdb_node_ptr_set_mdbNext(&prev->cteMDBNode, ((word_t)(next)));
        }
        if (next) {
            mdb_node_ptr_set_mdbPrev(&next->cteMDBNode, ((word_t)(prev)));
        }
        if (next)
            mdb_node_ptr_set_mdbFirstBadged(&next->cteMDBNode,
                                            mdb_node_get_mdbFirstBadged(next->cteMDBNode) ||
                                            mdb_node_get_mdbFirstBadged(mdbNode));
        slot->cap = cap_null_cap_new();
        slot->cteMDBNode = mdb_node_new(0, false, false, 0);

        postCapDeletion(cleanupInfo);
    }
}

static inline bool_t __attribute__((__const__))
capRemovable(cap_t cap, cte_t* slot)
{
    switch (cap_get_capType(cap)) {
    case cap_null_cap:
        return true;
    case cap_zombie_cap: {
        word_t n = cap_zombie_cap_get_capZombieNumber(cap);
        cte_t* z_slot = (cte_t*)cap_zombie_cap_get_capZombiePtr(cap);
        return (n == 0 || (n == 1 && slot == z_slot));
    }
    default:
        _fail("finaliseCap should only return Zombie or NullCap", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 640, __func__);
    }
}

static inline bool_t __attribute__((__const__))
capCyclicZombie(cap_t cap, cte_t *slot)
{
    return cap_get_capType(cap) == cap_zombie_cap &&
           ((cte_t *)(cap_zombie_cap_get_capZombiePtr(cap))) == slot;
}

static finaliseSlot_ret_t
finaliseSlot(cte_t *slot, bool_t immediate)
{
    bool_t final;
    finaliseCap_ret_t fc_ret;
    exception_t status;
    finaliseSlot_ret_t ret;

    while (cap_get_capType(slot->cap) != cap_null_cap) {
        final = isFinalCapability(slot);
        fc_ret = finaliseCap(slot->cap, final, false);

        if (capRemovable(fc_ret.remainder, slot)) {
            ret.status = EXCEPTION_NONE;
            ret.success = true;
            ret.cleanupInfo = fc_ret.cleanupInfo;
            return ret;
        }

        slot->cap = fc_ret.remainder;

        if (!immediate && capCyclicZombie(fc_ret.remainder, slot)) {
            ret.status = EXCEPTION_NONE;
            ret.success = false;
            ret.cleanupInfo = fc_ret.cleanupInfo;
            return ret;
        }

        status = reduceZombie(slot, immediate);
        if (status != EXCEPTION_NONE) {
            ret.status = status;
            ret.success = false;
            ret.cleanupInfo = cap_null_cap_new();
            return ret;
        }

        status = preemptionPoint();
        if (status != EXCEPTION_NONE) {
            ret.status = status;
            ret.success = false;
            ret.cleanupInfo = cap_null_cap_new();
            return ret;
        }
    }
    ret.status = EXCEPTION_NONE;
    ret.success = true;
    ret.cleanupInfo = cap_null_cap_new();
    return ret;
}

static exception_t
reduceZombie(cte_t* slot, bool_t immediate)
{
    cte_t* ptr;
    word_t n, type;
    exception_t status;

    if(!(cap_get_capType(slot->cap) == cap_zombie_cap)) _assert_fail("cap_get_capType(slot->cap) == cap_zombie_cap", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 708, __FUNCTION__);
    ptr = (cte_t*)cap_zombie_cap_get_capZombiePtr(slot->cap);
    n = cap_zombie_cap_get_capZombieNumber(slot->cap);
    type = cap_zombie_cap_get_capZombieType(slot->cap);


    if(!(n > 0)) _assert_fail("n > 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 714, __FUNCTION__);

    if (immediate) {
        cte_t* endSlot = &ptr[n - 1];

        status = cteDelete(endSlot, false);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        switch (cap_get_capType(slot->cap)) {
        case cap_null_cap:
            break;

        case cap_zombie_cap: {
            cte_t* ptr2 =
                (cte_t*)cap_zombie_cap_get_capZombiePtr(slot->cap);

            if (ptr == ptr2 &&
                    cap_zombie_cap_get_capZombieNumber(slot->cap) == n &&
                    cap_zombie_cap_get_capZombieType(slot->cap) == type) {
                if(!(cap_get_capType(endSlot->cap) == cap_null_cap)) _assert_fail("cap_get_capType(endSlot->cap) == cap_null_cap", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 735, __FUNCTION__);
                slot->cap =
                    cap_zombie_cap_set_capZombieNumber(slot->cap, n - 1);
            } else {



                if(!(ptr2 == slot && ptr != slot)) _assert_fail("ptr2 == slot && ptr != slot", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 742, __FUNCTION__);
            }
            break;
        }

        default:
            _fail("Expected recursion to result in Zombie.", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 748, __func__);
        }
    } else {

        if(!(ptr != slot)) _assert_fail("ptr != slot", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 752, __FUNCTION__);

        if (cap_get_capType(ptr->cap) == cap_zombie_cap) {

            if(!(ptr != ((cte_t *)(cap_zombie_cap_get_capZombiePtr(ptr->cap))))) _assert_fail("ptr != CTE_PTR(cap_zombie_cap_get_capZombiePtr(ptr->cap))", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c", 756, __FUNCTION__);
        }

        capSwapForDelete(ptr, slot);
    }
    return EXCEPTION_NONE;
}

void
cteDeleteOne(cte_t* slot)
{
    word_t cap_type = cap_get_capType(slot->cap);
    if (cap_type != cap_null_cap) {
        bool_t final;
        finaliseCap_ret_t fc_ret __attribute__((unused));




        final = isFinalCapability(slot);
        fc_ret = finaliseCap(slot->cap, final, true);

        if(!(capRemovable(fc_ret.remainder, slot) && cap_get_capType(fc_ret.cleanupInfo) == cap_null_cap)) _assert_fail("capRemovable(fc_ret.remainder, slot) && cap_get_capType(fc_ret.cleanupInfo) == cap_null_cap",
                                                                  "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/cnode.c"
        ,
                                                                  779
        , __FUNCTION__)
                                                                   ;
        emptySlot(slot, cap_null_cap_new());
    }
}

void
insertNewCap(cte_t *parent, cte_t *slot, cap_t cap)
{
    cte_t *next;

    next = ((cte_t *)(mdb_node_get_mdbNext(parent->cteMDBNode)));
    slot->cap = cap;
    slot->cteMDBNode = mdb_node_new(((word_t)(next)), true, true, ((word_t)(parent)));
    if (next) {
        mdb_node_ptr_set_mdbPrev(&next->cteMDBNode, ((word_t)(slot)));
    }
    mdb_node_ptr_set_mdbNext(&parent->cteMDBNode, ((word_t)(slot)));
}

void
setupReplyMaster(tcb_t *thread)
{
    cte_t *slot;

    slot = (((cte_t *)((word_t)(thread)&~((1ul << (11))-1ul)))+(tcbReply));
    if (cap_get_capType(slot->cap) == cap_null_cap) {


        slot->cap = cap_reply_cap_new(true, ((word_t)(thread)));
        slot->cteMDBNode = mdb_node_new(0, false, false, 0);
        mdb_node_ptr_set_mdbRevocable(&slot->cteMDBNode, true);
        mdb_node_ptr_set_mdbFirstBadged(&slot->cteMDBNode, true);
    }
}

bool_t __attribute__((__pure__))
isMDBParentOf(cte_t *cte_a, cte_t *cte_b)
{
    if (!mdb_node_get_mdbRevocable(cte_a->cteMDBNode)) {
        return false;
    }
    if (!sameRegionAs(cte_a->cap, cte_b->cap)) {
        return false;
    }
    switch (cap_get_capType(cte_a->cap)) {
    case cap_endpoint_cap: {
        word_t badge;

        badge = cap_endpoint_cap_get_capEPBadge(cte_a->cap);
        if (badge == 0) {
            return true;
        }
        return (badge == cap_endpoint_cap_get_capEPBadge(cte_b->cap)) &&
               !mdb_node_get_mdbFirstBadged(cte_b->cteMDBNode);
        break;
    }

    case cap_notification_cap: {
        word_t badge;

        badge = cap_notification_cap_get_capNtfnBadge(cte_a->cap);
        if (badge == 0) {
            return true;
        }
        return
            (badge == cap_notification_cap_get_capNtfnBadge(cte_b->cap)) &&
            !mdb_node_get_mdbFirstBadged(cte_b->cteMDBNode);
        break;
    }

    default:
        return true;
        break;
    }
}

exception_t
ensureNoChildren(cte_t *slot)
{
    if (mdb_node_get_mdbNext(slot->cteMDBNode) != 0) {
        cte_t *next;

        next = ((cte_t *)(mdb_node_get_mdbNext(slot->cteMDBNode)));
        if (isMDBParentOf(slot, next)) {
            current_syscall_error.type = seL4_RevokeFirst;
            return EXCEPTION_SYSCALL_ERROR;
        }
    }

    return EXCEPTION_NONE;
}

exception_t
ensureEmptySlot(cte_t *slot)
{
    if (cap_get_capType(slot->cap) != cap_null_cap) {
        current_syscall_error.type = seL4_DeleteFirst;
        return EXCEPTION_SYSCALL_ERROR;
    }

    return EXCEPTION_NONE;
}

bool_t __attribute__((__pure__))
isFinalCapability(cte_t *cte)
{
    mdb_node_t mdb;
    bool_t prevIsSameObject;

    mdb = cte->cteMDBNode;

    if (mdb_node_get_mdbPrev(mdb) == 0) {
        prevIsSameObject = false;
    } else {
        cte_t *prev;

        prev = ((cte_t *)(mdb_node_get_mdbPrev(mdb)));
        prevIsSameObject = sameObjectAs(prev->cap, cte->cap);
    }

    if (prevIsSameObject) {
        return false;
    } else {
        if (mdb_node_get_mdbNext(mdb) == 0) {
            return true;
        } else {
            cte_t *next;

            next = ((cte_t *)(mdb_node_get_mdbNext(mdb)));
            return !sameObjectAs(cte->cap, next->cap);
        }
    }
}

bool_t __attribute__((__pure__))
slotCapLongRunningDelete(cte_t *slot)
{
    if (cap_get_capType(slot->cap) == cap_null_cap) {
        return false;
    } else if (! isFinalCapability(slot)) {
        return false;
    }
    switch (cap_get_capType(slot->cap)) {
    case cap_thread_cap:
    case cap_zombie_cap:
    case cap_cnode_cap:
        return true;
    default:
        return false;
    }
}



cte_t *
getReceiveSlots(tcb_t *thread, word_t *buffer)
{
    cap_transfer_t ct;
    cptr_t cptr;
    lookupCap_ret_t luc_ret;
    lookupSlot_ret_t lus_ret;
    cte_t *slot;
    cap_t cnode;

    if (!buffer) {
        return ((void *)0);
    }

    ct = loadCapTransfer(buffer);
    cptr = ct.ctReceiveRoot;

    luc_ret = lookupCap(thread, cptr);
    if (luc_ret.status != EXCEPTION_NONE) {
        return ((void *)0);
    }
    cnode = luc_ret.cap;

    lus_ret = lookupTargetSlot(cnode, ct.ctReceiveIndex, ct.ctReceiveDepth);
    if (lus_ret.status != EXCEPTION_NONE) {
        return ((void *)0);
    }
    slot = lus_ret.slot;

    if (cap_get_capType(slot->cap) != cap_null_cap) {
        return ((void *)0);
    }

    return slot;
}

cap_transfer_t __attribute__((__pure__))
loadCapTransfer(word_t *buffer)
{
    const int offset = seL4_MsgMaxLength + ((1ul<<(seL4_MsgExtraCapBits))-1) + 2;
    return capTransferFromWords(buffer + offset);
}

static inline tcb_queue_t __attribute__((__pure__))
ep_ptr_get_queue(endpoint_t *epptr)
{
    tcb_queue_t queue;

    queue.head = (tcb_t*)endpoint_ptr_get_epQueue_head(epptr);
    queue.end = (tcb_t*)endpoint_ptr_get_epQueue_tail(epptr);

    return queue;
}

static inline void
ep_ptr_set_queue(endpoint_t *epptr, tcb_queue_t queue)
{
    endpoint_ptr_set_epQueue_head(epptr, (word_t)queue.head);
    endpoint_ptr_set_epQueue_tail(epptr, (word_t)queue.end);
}

void
sendIPC(bool_t blocking, bool_t do_call, word_t badge,
        bool_t canGrant, tcb_t *thread, endpoint_t *epptr)
{
    switch (endpoint_ptr_get_state(epptr)) {
    case EPState_Idle:
    case EPState_Send:
        if (blocking) {
            tcb_queue_t queue;


            thread_state_ptr_set_tsType(&thread->tcbState,
                                        ThreadState_BlockedOnSend);
            thread_state_ptr_set_blockingObject(
                &thread->tcbState, ((word_t)(epptr)));
            thread_state_ptr_set_blockingIPCBadge(
                &thread->tcbState, badge);
            thread_state_ptr_set_blockingIPCCanGrant(
                &thread->tcbState, canGrant);
            thread_state_ptr_set_blockingIPCIsCall(
                &thread->tcbState, do_call);

            scheduleTCB(thread);


            queue = ep_ptr_get_queue(epptr);
            queue = tcbEPAppend(thread, queue);
            endpoint_ptr_set_state(epptr, EPState_Send);
            ep_ptr_set_queue(epptr, queue);
        }
        break;

    case EPState_Recv: {
        tcb_queue_t queue;
        tcb_t *dest;


        queue = ep_ptr_get_queue(epptr);
        dest = queue.head;


        if(!(dest)) _assert_fail("dest", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/endpoint.c", 80, __FUNCTION__);


        queue = tcbEPDequeue(dest, queue);
        ep_ptr_set_queue(epptr, queue);

        if (!queue.head) {
            endpoint_ptr_set_state(epptr, EPState_Idle);
        }


        doIPCTransfer(thread, epptr, badge, canGrant, dest);

        setThreadState(dest, ThreadState_Running);
        possibleSwitchTo(dest);

        if (do_call ||
                seL4_Fault_ptr_get_seL4_FaultType(&thread->tcbFault) != seL4_Fault_NullFault) {
            if (canGrant) {
                setupCallerCap(thread, dest);
            } else {
                setThreadState(thread, ThreadState_Inactive);
            }
        }

        break;
    }
    }
}

void
receiveIPC(tcb_t *thread, cap_t cap, bool_t isBlocking)
{
    endpoint_t *epptr;
    notification_t *ntfnPtr;


    if(!(cap_get_capType(cap) == cap_endpoint_cap)) _assert_fail("cap_get_capType(cap) == cap_endpoint_cap", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/endpoint.c", 117, __FUNCTION__);

    epptr = ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(cap)));


    ntfnPtr = thread->tcbBoundNotification;
    if (ntfnPtr && notification_ptr_get_state(ntfnPtr) == NtfnState_Active) {
        completeSignal(ntfnPtr, thread);
    } else {
        switch (endpoint_ptr_get_state(epptr)) {
        case EPState_Idle:
        case EPState_Recv: {
            tcb_queue_t queue;

            if (isBlocking) {

                thread_state_ptr_set_tsType(&thread->tcbState,
                                            ThreadState_BlockedOnReceive);
                thread_state_ptr_set_blockingObject(
                    &thread->tcbState, ((word_t)(epptr)));

                scheduleTCB(thread);


                queue = ep_ptr_get_queue(epptr);
                queue = tcbEPAppend(thread, queue);
                endpoint_ptr_set_state(epptr, EPState_Recv);
                ep_ptr_set_queue(epptr, queue);
            } else {
                doNBRecvFailedTransfer(thread);
            }
            break;
        }

        case EPState_Send: {
            tcb_queue_t queue;
            tcb_t *sender;
            word_t badge;
            bool_t canGrant;
            bool_t do_call;


            queue = ep_ptr_get_queue(epptr);
            sender = queue.head;


            if(!(sender)) _assert_fail("sender", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/endpoint.c", 163, __FUNCTION__);


            queue = tcbEPDequeue(sender, queue);
            ep_ptr_set_queue(epptr, queue);

            if (!queue.head) {
                endpoint_ptr_set_state(epptr, EPState_Idle);
            }


            badge = thread_state_ptr_get_blockingIPCBadge(&sender->tcbState);
            canGrant =
                thread_state_ptr_get_blockingIPCCanGrant(&sender->tcbState);


            doIPCTransfer(sender, epptr, badge,
                          canGrant, thread);

            do_call = thread_state_ptr_get_blockingIPCIsCall(&sender->tcbState);

            if (do_call ||
                    seL4_Fault_get_seL4_FaultType(sender->tcbFault) != seL4_Fault_NullFault) {
                if (canGrant) {
                    setupCallerCap(sender, thread);
                } else {
                    setThreadState(sender, ThreadState_Inactive);
                }
            } else {
                setThreadState(sender, ThreadState_Running);
                possibleSwitchTo(sender);
            }

            break;
        }
        }
    }
}

void
replyFromKernel_error(tcb_t *thread)
{
    word_t len;
    word_t *ipcBuffer;

    ipcBuffer = lookupIPCBuffer(true, thread);
    setRegister(thread, badgeRegister, 0);
    len = setMRs_syscall_error(thread, ipcBuffer);
    setRegister(thread, msgInfoRegister, wordFromMessageInfo(
                    seL4_MessageInfo_new(current_syscall_error.type, 0, 0, len)));
}

void
replyFromKernel_success_empty(tcb_t *thread)
{
    setRegister(thread, badgeRegister, 0);
    setRegister(thread, msgInfoRegister, wordFromMessageInfo(
                    seL4_MessageInfo_new(0, 0, 0, 0)));
}

void
cancelIPC(tcb_t *tptr)
{
    thread_state_t *state = &tptr->tcbState;

    switch (thread_state_ptr_get_tsType(state)) {
    case ThreadState_BlockedOnSend:
    case ThreadState_BlockedOnReceive: {

        endpoint_t *epptr;
        tcb_queue_t queue;

        epptr = ((endpoint_t *)(thread_state_ptr_get_blockingObject(state)));


        if(!(endpoint_ptr_get_state(epptr) != EPState_Idle)) _assert_fail("endpoint_ptr_get_state(epptr) != EPState_Idle", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/endpoint.c", 238, __FUNCTION__);


        queue = ep_ptr_get_queue(epptr);
        queue = tcbEPDequeue(tptr, queue);
        ep_ptr_set_queue(epptr, queue);

        if (!queue.head) {
            endpoint_ptr_set_state(epptr, EPState_Idle);
        }

        setThreadState(tptr, ThreadState_Inactive);
        break;
    }

    case ThreadState_BlockedOnNotification:
        cancelSignal(tptr,
                     ((notification_t *)(thread_state_ptr_get_blockingObject(state))));
        break;

    case ThreadState_BlockedOnReply: {
        cte_t *slot, *callerCap;

        tptr->tcbFault = seL4_Fault_NullFault_new();


        slot = (((cte_t *)((word_t)(tptr)&~((1ul << (11))-1ul)))+(tcbReply));

        callerCap = ((cte_t *)(mdb_node_get_mdbNext(slot->cteMDBNode)));
        if (callerCap) {


            cteDeleteOne(callerCap);
        }

        break;
    }
    }
}

void
cancelAllIPC(endpoint_t *epptr)
{
    switch (endpoint_ptr_get_state(epptr)) {
    case EPState_Idle:
        break;

    default: {
        tcb_t *thread = ((tcb_t *)(endpoint_ptr_get_epQueue_head(epptr)));


        endpoint_ptr_set_state(epptr, EPState_Idle);
        endpoint_ptr_set_epQueue_head(epptr, 0);
        endpoint_ptr_set_epQueue_tail(epptr, 0);


        for (; thread; thread = thread->tcbEPNext) {
            setThreadState (thread, ThreadState_Restart);
            do { tcbSchedEnqueue(thread); remoteQueueUpdate(thread); } while (0);
        }

        rescheduleRequired();
        break;
    }
    }
}

void
cancelBadgedSends(endpoint_t *epptr, word_t badge)
{
    switch (endpoint_ptr_get_state(epptr)) {
    case EPState_Idle:
    case EPState_Recv:
        break;

    case EPState_Send: {
        tcb_t *thread, *next;
        tcb_queue_t queue = ep_ptr_get_queue(epptr);




        endpoint_ptr_set_state(epptr, EPState_Idle);
        endpoint_ptr_set_epQueue_head(epptr, 0);
        endpoint_ptr_set_epQueue_tail(epptr, 0);

        for (thread = queue.head; thread; thread = next) {
            word_t b = thread_state_ptr_get_blockingIPCBadge(
                           &thread->tcbState);
            next = thread->tcbEPNext;
            if (b == badge) {
                setThreadState(thread, ThreadState_Restart);
                do { tcbSchedEnqueue(thread); remoteQueueUpdate(thread); } while (0);
                queue = tcbEPDequeue(thread, queue);
            }
        }
        ep_ptr_set_queue(epptr, queue);

        if (queue.head) {
            endpoint_ptr_set_state(epptr, EPState_Send);
        }

        rescheduleRequired();

        break;
    }

    default:
        _fail("invalid EP state", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/endpoint.c", 346, __func__);
    }
}
static inline void resetTimer(void);
static inline void resetTimer()
{

}

exception_t
decodeIRQControlInvocation(word_t invLabel, word_t length,
                           cte_t *srcSlot, extra_caps_t excaps,
                           word_t *buffer)
{
    if (invLabel == IRQIssueIRQHandler) {
        word_t index, depth, irq_w;
        irq_t irq;
        cte_t *destSlot;
        cap_t cnodeCap;
        lookupSlot_ret_t lu_ret;
        exception_t status;

        if (length < 3 || excaps.excaprefs[0] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }
        irq_w = getSyscallArg(0, buffer);
        irq = (irq_t) irq_w;
        index = getSyscallArg(1, buffer);
        depth = getSyscallArg(2, buffer);

        cnodeCap = excaps.excaprefs[0]->cap;

        status = Arch_checkIRQ(irq_w);
        if (status != EXCEPTION_NONE) {
            return status;
        }

        if (isIRQActive(irq)) {
            current_syscall_error.type = seL4_RevokeFirst;
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 59, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Rejecting request for IRQ %u. Already active.", (int)irq); kprintf(">>" "" "\n"); } while (0);
            return EXCEPTION_SYSCALL_ERROR;
        }

        lu_ret = lookupTargetSlot(cnodeCap, index, depth);
        if (lu_ret.status != EXCEPTION_NONE) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 66, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Target slot for new IRQ Handler cap invalid: cap %lu, IRQ %u.", getExtraCPtr(buffer, 0), (int)irq); kprintf(">>" "" "\n"); } while (0)
                                                        ;
            return lu_ret.status;
        }
        destSlot = lu_ret.slot;

        status = ensureEmptySlot(destSlot);
        if (status != EXCEPTION_NONE) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 74, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Target slot for new IRQ Handler cap not empty: cap %lu, IRQ %u.", getExtraCPtr(buffer, 0), (int)irq); kprintf(">>" "" "\n"); } while (0)
                                                        ;
            return status;
        }

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return invokeIRQControl(irq, destSlot, srcSlot);
    } else {
        return Arch_decodeIRQControlInvocation(invLabel, length, srcSlot, excaps, buffer);
    }
}

exception_t
invokeIRQControl(irq_t irq, cte_t *handlerSlot, cte_t *controlSlot)
{
    setIRQState(IRQSignal, irq);
    cteInsert(cap_irq_handler_cap_new(irq), controlSlot, handlerSlot);

    return EXCEPTION_NONE;
}

exception_t
decodeIRQHandlerInvocation(word_t invLabel, irq_t irq,
                           extra_caps_t excaps)
{
    switch (invLabel) {
    case IRQAckIRQ:
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        invokeIRQHandler_AckIRQ(irq);
        return EXCEPTION_NONE;

    case IRQSetIRQHandler: {
        cap_t ntfnCap;
        cte_t *slot;

        if (excaps.excaprefs[0] == ((void *)0)) {
            current_syscall_error.type = seL4_TruncatedMessage;
            return EXCEPTION_SYSCALL_ERROR;
        }
        ntfnCap = excaps.excaprefs[0]->cap;
        slot = excaps.excaprefs[0];

        if (cap_get_capType(ntfnCap) != cap_notification_cap ||
                !cap_notification_cap_get_capNtfnCanSend(ntfnCap)) {
            if (cap_get_capType(ntfnCap) != cap_notification_cap) {
                do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 118, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IRQSetHandler: provided cap is not an notification capability."); kprintf(">>" "" "\n"); } while (0);
            } else {
                do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 120, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IRQSetHandler: caller does not have send rights on the endpoint."); kprintf(">>" "" "\n"); } while (0);
            }
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        invokeIRQHandler_SetIRQHandler(irq, ntfnCap, slot);
        return EXCEPTION_NONE;
    }

    case IRQClearIRQHandler:
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        invokeIRQHandler_ClearIRQHandler(irq);
        return EXCEPTION_NONE;

    default:
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 138, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("IRQHandler: Illegal operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
}

void
invokeIRQHandler_AckIRQ(irq_t irq)
{
    maskInterrupt(false, irq);
}

void
invokeIRQHandler_SetIRQHandler(irq_t irq, cap_t cap, cte_t *slot)
{
    cte_t *irqSlot;

    irqSlot = intStateIRQNode + irq;

    cteDeleteOne(irqSlot);
    cteInsert(cap, slot, irqSlot);
}

void
invokeIRQHandler_ClearIRQHandler(irq_t irq)
{
    cte_t *irqSlot;

    irqSlot = intStateIRQNode + irq;

    cteDeleteOne(irqSlot);
}

void
deletingIRQHandler(irq_t irq)
{
    cte_t *slot;

    slot = intStateIRQNode + irq;

    cteDeleteOne(slot);
}

void
deletedIRQHandler(irq_t irq)
{
    setIRQState(IRQInactive, irq);
}

void
handleInterrupt(irq_t irq)
{
    if (__builtin_expect(!!(irq > maxIRQ), 0)) {




        kprintf("Received IRQ %d, which is above the platforms maxIRQ of %d\n", (int)irq, (int)maxIRQ);
        maskInterrupt(true, irq);
        ackInterrupt(irq);
        return;
    }
    switch (intStateIRQTable[irq]) {
    case IRQSignal: {
        cap_t cap;

        cap = intStateIRQNode[irq].cap;

        if (cap_get_capType(cap) == cap_notification_cap &&
                cap_notification_cap_get_capNtfnCanSend(cap)) {
            sendSignal(((notification_t *)(cap_notification_cap_get_capNtfnPtr(cap))),
                       cap_notification_cap_get_capNtfnBadge(cap));
        } else {



        }
        maskInterrupt(true, irq);
        break;
    }

    case IRQTimer:
        timerTick();
        resetTimer();
        break;


    case IRQIPI:
        handleIPI(irq, true);
        break;


    case IRQReserved:



        handleReservedIRQ(irq);
        break;

    case IRQInactive:





        maskInterrupt(true, irq);



        break;

    default:

        _fail("Invalid IRQ state", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/interrupt.c", 251, __func__);
    }

    ackInterrupt(irq);
}

bool_t
isIRQActive(irq_t irq)
{
    return intStateIRQTable[irq] != IRQInactive;
}

void
setIRQState(irq_state_t irqState, irq_t irq)
{
    intStateIRQTable[irq] = irqState;
    maskInterrupt(irqState == IRQInactive, irq);
}



static inline tcb_queue_t __attribute__((__pure__))
ntfn_ptr_get_queue(notification_t *ntfnPtr)
{
    tcb_queue_t ntfn_queue;

    ntfn_queue.head = (tcb_t*)notification_ptr_get_ntfnQueue_head(ntfnPtr);
    ntfn_queue.end = (tcb_t*)notification_ptr_get_ntfnQueue_tail(ntfnPtr);

    return ntfn_queue;
}

static inline void
ntfn_ptr_set_queue(notification_t *ntfnPtr, tcb_queue_t ntfn_queue)
{
    notification_ptr_set_ntfnQueue_head(ntfnPtr, (word_t)ntfn_queue.head);
    notification_ptr_set_ntfnQueue_tail(ntfnPtr, (word_t)ntfn_queue.end);
}

static inline void
ntfn_set_active(notification_t *ntfnPtr, word_t badge)
{
    notification_ptr_set_state(ntfnPtr, NtfnState_Active);
    notification_ptr_set_ntfnMsgIdentifier(ntfnPtr, badge);
}


void
sendSignal(notification_t *ntfnPtr, word_t badge)
{
    switch (notification_ptr_get_state(ntfnPtr)) {
    case NtfnState_Idle: {
        tcb_t *tcb = (tcb_t*)notification_ptr_get_ntfnBoundTCB(ntfnPtr);

        if (tcb) {
            if (thread_state_ptr_get_tsType(&tcb->tcbState) == ThreadState_BlockedOnReceive) {

                cancelIPC(tcb);
                setThreadState(tcb, ThreadState_Running);
                setRegister(tcb, badgeRegister, badge);
                possibleSwitchTo(tcb);

            } else if (thread_state_ptr_get_tsType(&tcb->tcbState) == ThreadState_RunningVM) {

                if (tcb->tcbAffinity != getCurrentCPUIndex()) {
                    ntfn_set_active(ntfnPtr, badge);
                    doRemoteVMCheckBoundNotification(tcb->tcbAffinity, tcb);
                } else

                {
                    setThreadState(tcb, ThreadState_Running);
                    setRegister(tcb, badgeRegister, badge);
                    Arch_leaveVMAsyncTransfer(tcb);
                    possibleSwitchTo(tcb);
                }

            } else {
                ntfn_set_active(ntfnPtr, badge);
            }
        } else {
            ntfn_set_active(ntfnPtr, badge);
        }
        break;
    }
    case NtfnState_Waiting: {
        tcb_queue_t ntfn_queue;
        tcb_t *dest;

        ntfn_queue = ntfn_ptr_get_queue(ntfnPtr);
        dest = ntfn_queue.head;


        if(!(dest)) _assert_fail("dest", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/notification.c", 94, __FUNCTION__);


        ntfn_queue = tcbEPDequeue(dest, ntfn_queue);
        ntfn_ptr_set_queue(ntfnPtr, ntfn_queue);


        if (!ntfn_queue.head) {
            notification_ptr_set_state(ntfnPtr, NtfnState_Idle);
        }

        setThreadState(dest, ThreadState_Running);
        setRegister(dest, badgeRegister, badge);
        possibleSwitchTo(dest);
        break;
    }

    case NtfnState_Active: {
        word_t badge2;

        badge2 = notification_ptr_get_ntfnMsgIdentifier(ntfnPtr);
        badge2 |= badge;

        notification_ptr_set_ntfnMsgIdentifier(ntfnPtr, badge2);
        break;
    }
    }
}

void
receiveSignal(tcb_t *thread, cap_t cap, bool_t isBlocking)
{
    notification_t *ntfnPtr;

    ntfnPtr = ((notification_t *)(cap_notification_cap_get_capNtfnPtr(cap)));

    switch (notification_ptr_get_state(ntfnPtr)) {
    case NtfnState_Idle:
    case NtfnState_Waiting: {
        tcb_queue_t ntfn_queue;

        if (isBlocking) {

            thread_state_ptr_set_tsType(&thread->tcbState,
                                        ThreadState_BlockedOnNotification);
            thread_state_ptr_set_blockingObject(&thread->tcbState,
                                                ((word_t)(ntfnPtr)));
            scheduleTCB(thread);


            ntfn_queue = ntfn_ptr_get_queue(ntfnPtr);
            ntfn_queue = tcbEPAppend(thread, ntfn_queue);

            notification_ptr_set_state(ntfnPtr, NtfnState_Waiting);
            ntfn_ptr_set_queue(ntfnPtr, ntfn_queue);
        } else {
            doNBRecvFailedTransfer(thread);
        }

        break;
    }

    case NtfnState_Active:
        setRegister(
            thread, badgeRegister,
            notification_ptr_get_ntfnMsgIdentifier(ntfnPtr));
        notification_ptr_set_state(ntfnPtr, NtfnState_Idle);
        break;
    }
}

void
cancelAllSignals(notification_t *ntfnPtr)
{
    if (notification_ptr_get_state(ntfnPtr) == NtfnState_Waiting) {
        tcb_t *thread = ((tcb_t *)(notification_ptr_get_ntfnQueue_head(ntfnPtr)));

        notification_ptr_set_state(ntfnPtr, NtfnState_Idle);
        notification_ptr_set_ntfnQueue_head(ntfnPtr, 0);
        notification_ptr_set_ntfnQueue_tail(ntfnPtr, 0);


        for (; thread; thread = thread->tcbEPNext) {
            setThreadState(thread, ThreadState_Restart);
            do { tcbSchedEnqueue(thread); remoteQueueUpdate(thread); } while (0);
        }
        rescheduleRequired();
    }
}

void
cancelSignal(tcb_t *threadPtr, notification_t *ntfnPtr)
{
    tcb_queue_t ntfn_queue;


    if(!(notification_ptr_get_state(ntfnPtr) == NtfnState_Waiting)) _assert_fail("notification_ptr_get_state(ntfnPtr) == NtfnState_Waiting", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/notification.c", 190, __FUNCTION__);


    ntfn_queue = ntfn_ptr_get_queue(ntfnPtr);
    ntfn_queue = tcbEPDequeue(threadPtr, ntfn_queue);
    ntfn_ptr_set_queue(ntfnPtr, ntfn_queue);


    if (!ntfn_queue.head) {
        notification_ptr_set_state(ntfnPtr, NtfnState_Idle);
    }


    setThreadState(threadPtr, ThreadState_Inactive);
}

void
completeSignal(notification_t *ntfnPtr, tcb_t *tcb)
{
    word_t badge;

    if (__builtin_expect(!!(tcb && notification_ptr_get_state(ntfnPtr) == NtfnState_Active), 1)) {
        badge = notification_ptr_get_ntfnMsgIdentifier(ntfnPtr);
        setRegister(tcb, badgeRegister, badge);
        notification_ptr_set_state(ntfnPtr, NtfnState_Idle);
    } else {
        _fail("tried to complete signal with inactive notification object", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/notification.c", 216, __func__);
    }
}

static inline void
doUnbindNotification(notification_t *ntfnPtr, tcb_t *tcbptr)
{
    notification_ptr_set_ntfnBoundTCB(ntfnPtr, (word_t) 0);
    tcbptr->tcbBoundNotification = ((void *)0);
}

void
unbindMaybeNotification(notification_t *ntfnPtr)
{
    tcb_t *boundTCB;
    boundTCB = (tcb_t*)notification_ptr_get_ntfnBoundTCB(ntfnPtr);

    if (boundTCB) {
        doUnbindNotification(ntfnPtr, boundTCB);
    }
}

void
unbindNotification(tcb_t *tcb)
{
    notification_t *ntfnPtr;
    ntfnPtr = tcb->tcbBoundNotification;

    if (ntfnPtr) {
        doUnbindNotification(ntfnPtr, tcb);
    }
}

void
bindNotification(tcb_t *tcb, notification_t *ntfnPtr)
{
    notification_ptr_set_ntfnBoundTCB(ntfnPtr, (word_t)tcb);
    tcb->tcbBoundNotification = ntfnPtr;
}

word_t getObjectSize(word_t t, word_t userObjSize)
{
    if (t >= seL4_NonArchObjectTypeCount) {
        return Arch_getObjectSize(t);
    } else {
        switch (t) {
        case seL4_TCBObject:
            return 11;
        case seL4_EndpointObject:
            return 4;
        case seL4_NotificationObject:
            return 5;
        case seL4_CapTableObject:
            return 5 + userObjSize;
        case seL4_UntypedObject:
            return userObjSize;
        default:
            _fail("Invalid object type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/objecttype.c", 50, __func__);
            return 0;
        }
    }
}

deriveCap_ret_t
deriveCap(cte_t *slot, cap_t cap)
{
    deriveCap_ret_t ret;

    if (isArchCap(cap)) {
        return Arch_deriveCap(slot, cap);
    }

    switch (cap_get_capType(cap)) {
    case cap_zombie_cap:
        ret.status = EXCEPTION_NONE;
        ret.cap = cap_null_cap_new();
        break;

    case cap_irq_control_cap:
        ret.status = EXCEPTION_NONE;
        ret.cap = cap_null_cap_new();
        break;

    case cap_untyped_cap:
        ret.status = ensureNoChildren(slot);
        if (ret.status != EXCEPTION_NONE) {
            ret.cap = cap_null_cap_new();
        } else {
            ret.cap = cap;
        }
        break;

    case cap_reply_cap:
        ret.status = EXCEPTION_NONE;
        ret.cap = cap_null_cap_new();
        break;

    default:
        ret.status = EXCEPTION_NONE;
        ret.cap = cap;
    }

    return ret;
}

finaliseCap_ret_t
finaliseCap(cap_t cap, bool_t final, bool_t exposed)
{
    finaliseCap_ret_t fc_ret;

    if (isArchCap(cap)) {
        return Arch_finaliseCap(cap, final);
    }

    switch (cap_get_capType(cap)) {
    case cap_endpoint_cap:
        if (final) {
            cancelAllIPC(((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(cap))));
        }

        fc_ret.remainder = cap_null_cap_new();
        fc_ret.cleanupInfo = cap_null_cap_new();
        return fc_ret;

    case cap_notification_cap:
        if (final) {
            notification_t *ntfn = ((notification_t *)(cap_notification_cap_get_capNtfnPtr(cap)));

            unbindMaybeNotification(ntfn);
            cancelAllSignals(ntfn);
        }
        fc_ret.remainder = cap_null_cap_new();
        fc_ret.cleanupInfo = cap_null_cap_new();
        return fc_ret;

    case cap_reply_cap:
    case cap_null_cap:
    case cap_domain_cap:
        fc_ret.remainder = cap_null_cap_new();
        fc_ret.cleanupInfo = cap_null_cap_new();
        return fc_ret;
    }

    if (exposed) {
        _fail("finaliseCap: failed to finalise immediately.", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/objecttype.c", 137, __func__);
    }

    switch (cap_get_capType(cap)) {
    case cap_cnode_cap: {
        if (final) {
            fc_ret.remainder =
                Zombie_new(
                    1 << cap_cnode_cap_get_capCNodeRadix(cap),
                    cap_cnode_cap_get_capCNodeRadix(cap),
                    cap_cnode_cap_get_capCNodePtr(cap)
                );
            fc_ret.cleanupInfo = cap_null_cap_new();
            return fc_ret;
        }
        break;
    }

    case cap_thread_cap: {
        if (final) {
            tcb_t *tcb;
            cte_t *cte_ptr;

            tcb = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap)));
            remoteTCBStall(tcb);
            cte_ptr = (((cte_t *)((word_t)(tcb)&~((1ul << (11))-1ul)))+(tcbCTable));
            unbindNotification(tcb);
            suspend(tcb);

            tcbDebugRemove(tcb);

            Arch_prepareThreadDelete(tcb);
            fc_ret.remainder =
                Zombie_new(
                    tcbArchCNodeEntries,
                    (1ul << (6)),
                    ((word_t)(cte_ptr))
                );
            fc_ret.cleanupInfo = cap_null_cap_new();
            return fc_ret;
        }
        break;
    }

    case cap_zombie_cap:
        fc_ret.remainder = cap;
        fc_ret.cleanupInfo = cap_null_cap_new();
        return fc_ret;

    case cap_irq_handler_cap:
        if (final) {
            irq_t irq = cap_irq_handler_cap_get_capIRQ(cap);

            deletingIRQHandler(irq);

            fc_ret.remainder = cap_null_cap_new();
            fc_ret.cleanupInfo = cap;
            return fc_ret;
        }
        break;
    }

    fc_ret.remainder = cap_null_cap_new();
    fc_ret.cleanupInfo = cap_null_cap_new();
    return fc_ret;
}

bool_t __attribute__((__const__))
hasCancelSendRights(cap_t cap)
{
    switch (cap_get_capType(cap)) {
    case cap_endpoint_cap:
        return cap_endpoint_cap_get_capCanSend(cap) &&
               cap_endpoint_cap_get_capCanReceive(cap) &&
               cap_endpoint_cap_get_capCanGrant(cap);

    default:
        return false;
    }
}

bool_t __attribute__((__const__))
sameRegionAs(cap_t cap_a, cap_t cap_b)
{
    switch (cap_get_capType(cap_a)) {
    case cap_untyped_cap:
        if (cap_get_capIsPhysical(cap_b)) {
            word_t aBase, bBase, aTop, bTop;

            aBase = (word_t)((word_t *)(cap_untyped_cap_get_capPtr(cap_a)));
            bBase = (word_t)cap_get_capPtr(cap_b);

            aTop = aBase + ((1ul << (cap_untyped_cap_get_capBlockSize(cap_a)))-1ul);
            bTop = bBase + ((1ul << (cap_get_capSizeBits(cap_b)))-1ul);

            return (aBase <= bBase) && (bTop <= aTop) && (bBase <= bTop);
        }
        break;

    case cap_endpoint_cap:
        if (cap_get_capType(cap_b) == cap_endpoint_cap) {
            return cap_endpoint_cap_get_capEPPtr(cap_a) ==
                   cap_endpoint_cap_get_capEPPtr(cap_b);
        }
        break;

    case cap_notification_cap:
        if (cap_get_capType(cap_b) == cap_notification_cap) {
            return cap_notification_cap_get_capNtfnPtr(cap_a) ==
                   cap_notification_cap_get_capNtfnPtr(cap_b);
        }
        break;

    case cap_cnode_cap:
        if (cap_get_capType(cap_b) == cap_cnode_cap) {
            return (cap_cnode_cap_get_capCNodePtr(cap_a) ==
                    cap_cnode_cap_get_capCNodePtr(cap_b)) &&
                   (cap_cnode_cap_get_capCNodeRadix(cap_a) ==
                    cap_cnode_cap_get_capCNodeRadix(cap_b));
        }
        break;

    case cap_thread_cap:
        if (cap_get_capType(cap_b) == cap_thread_cap) {
            return cap_thread_cap_get_capTCBPtr(cap_a) ==
                   cap_thread_cap_get_capTCBPtr(cap_b);
        }
        break;

    case cap_reply_cap:
        if (cap_get_capType(cap_b) == cap_reply_cap) {
            return cap_reply_cap_get_capTCBPtr(cap_a) ==
                   cap_reply_cap_get_capTCBPtr(cap_b);
        }
        break;

    case cap_domain_cap:
        if (cap_get_capType(cap_b) == cap_domain_cap) {
            return true;
        }
        break;

    case cap_irq_control_cap:
        if (cap_get_capType(cap_b) == cap_irq_control_cap ||
                cap_get_capType(cap_b) == cap_irq_handler_cap) {
            return true;
        }
        break;

    case cap_irq_handler_cap:
        if (cap_get_capType(cap_b) == cap_irq_handler_cap) {
            return (irq_t)cap_irq_handler_cap_get_capIRQ(cap_a) ==
                   (irq_t)cap_irq_handler_cap_get_capIRQ(cap_b);
        }
        break;

    default:
        if (isArchCap(cap_a) &&
                isArchCap(cap_b)) {
            return Arch_sameRegionAs(cap_a, cap_b);
        }
        break;
    }

    return false;
}

bool_t __attribute__((__const__))
sameObjectAs(cap_t cap_a, cap_t cap_b)
{
    if (cap_get_capType(cap_a) == cap_untyped_cap) {
        return false;
    }
    if (cap_get_capType(cap_a) == cap_irq_control_cap &&
            cap_get_capType(cap_b) == cap_irq_handler_cap) {
        return false;
    }
    if (isArchCap(cap_a) && isArchCap(cap_b)) {
        return Arch_sameObjectAs(cap_a, cap_b);
    }
    return sameRegionAs(cap_a, cap_b);
}

cap_t __attribute__((__const__))
updateCapData(bool_t preserve, word_t newData, cap_t cap)
{
    if (isArchCap(cap)) {
        return Arch_updateCapData(preserve, newData, cap);
    }

    switch (cap_get_capType(cap)) {
    case cap_endpoint_cap:
        if (!preserve && cap_endpoint_cap_get_capEPBadge(cap) == 0) {
            return cap_endpoint_cap_set_capEPBadge(cap, newData);
        } else {
            return cap_null_cap_new();
        }

    case cap_notification_cap:
        if (!preserve && cap_notification_cap_get_capNtfnBadge(cap) == 0) {
            return cap_notification_cap_set_capNtfnBadge(cap, newData);
        } else {
            return cap_null_cap_new();
        }

    case cap_cnode_cap: {
        word_t guard, guardSize;
        seL4_CNode_CapData_t w = { .words = { newData } };

        guardSize = seL4_CNode_CapData_get_guardSize(w);

        if (guardSize + cap_cnode_cap_get_capCNodeRadix(cap) > (1 << 6)) {
            return cap_null_cap_new();
        } else {
            cap_t new_cap;

            guard = seL4_CNode_CapData_get_guard(w) & ((1ul << (guardSize))-1ul);
            new_cap = cap_cnode_cap_set_capCNodeGuard(cap, guard);
            new_cap = cap_cnode_cap_set_capCNodeGuardSize(new_cap,
                                                          guardSize);

            return new_cap;
        }
    }

    default:
        return cap;
    }
}

cap_t __attribute__((__const__))
maskCapRights(seL4_CapRights_t cap_rights, cap_t cap)
{
    if (isArchCap(cap)) {
        return Arch_maskCapRights(cap_rights, cap);
    }

    switch (cap_get_capType(cap)) {
    case cap_null_cap:
    case cap_domain_cap:
    case cap_cnode_cap:
    case cap_untyped_cap:
    case cap_reply_cap:
    case cap_irq_control_cap:
    case cap_irq_handler_cap:
    case cap_zombie_cap:
    case cap_thread_cap:
        return cap;

    case cap_endpoint_cap: {
        cap_t new_cap;

        new_cap = cap_endpoint_cap_set_capCanSend(
                      cap, cap_endpoint_cap_get_capCanSend(cap) &
                      seL4_CapRights_get_capAllowWrite(cap_rights));
        new_cap = cap_endpoint_cap_set_capCanReceive(
                      new_cap, cap_endpoint_cap_get_capCanReceive(cap) &
                      seL4_CapRights_get_capAllowRead(cap_rights));
        new_cap = cap_endpoint_cap_set_capCanGrant(
                      new_cap, cap_endpoint_cap_get_capCanGrant(cap) &
                      seL4_CapRights_get_capAllowGrant(cap_rights));

        return new_cap;
    }

    case cap_notification_cap: {
        cap_t new_cap;

        new_cap = cap_notification_cap_set_capNtfnCanSend(
                      cap, cap_notification_cap_get_capNtfnCanSend(cap) &
                      seL4_CapRights_get_capAllowWrite(cap_rights));
        new_cap = cap_notification_cap_set_capNtfnCanReceive(new_cap,
                                                             cap_notification_cap_get_capNtfnCanReceive(cap) &
                                                             seL4_CapRights_get_capAllowRead(cap_rights));

        return new_cap;
    }

    default:
        _fail("Invalid cap type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/objecttype.c", 416, __func__);
    }
}

cap_t
createObject(object_t t, void *regionBase, word_t userSize, bool_t deviceMemory)
{

    if (t >= (object_t) seL4_NonArchObjectTypeCount) {
        return Arch_createObject(t, regionBase, userSize, deviceMemory);
    }


    switch ((api_object_t)t) {
    case seL4_TCBObject: {
        tcb_t *tcb;
        tcb = ((tcb_t *)((word_t)regionBase + (1ul << ((11 - 1)))));






        Arch_initContext(&tcb->tcbArch.tcbContext);
        tcb->tcbTimeSlice = 1;
        tcb->tcbDomain = ksCurDomain;


        tcb->tcbAffinity = getCurrentCPUIndex();


        strlcpy(tcb->tcbName, "child of: '", ((1ul << (11)) - (1ul << ((11 - 1))) - sizeof(tcb_t)));
        strlcat(tcb->tcbName, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, ((1ul << (11)) - (1ul << ((11 - 1))) - sizeof(tcb_t)));
        strlcat(tcb->tcbName, "'", ((1ul << (11)) - (1ul << ((11 - 1))) - sizeof(tcb_t)));
        tcbDebugAppend(tcb);


        return cap_thread_cap_new(((word_t)(tcb)));
    }

    case seL4_EndpointObject:


        return cap_endpoint_cap_new(0, true, true, true,
                                    ((word_t)(regionBase)));

    case seL4_NotificationObject:


        return cap_notification_cap_new(0, true, true,
                                        ((word_t)(regionBase)));

    case seL4_CapTableObject:





        return cap_cnode_cap_new(userSize, 0, 0, ((word_t)(regionBase)));

    case seL4_UntypedObject:




        return cap_untyped_cap_new(0, !!deviceMemory, userSize, ((word_t)(regionBase)));

    default:
        _fail("Invalid object type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/objecttype.c", 484, __func__);
    }
}

void
createNewObjects(object_t t, cte_t *parent, slot_range_t slots,
                 void *regionBase, word_t userSize, bool_t deviceMemory)
{
    word_t objectSize;
    void *nextFreeArea;
    word_t i;
    word_t totalObjectSize __attribute__((unused));


    objectSize = getObjectSize(t, userSize);
    totalObjectSize = slots.length << objectSize;




    nextFreeArea = regionBase;
    for (i = 0; i < slots.length; i++) {


        cap_t cap = createObject(t, (void *)((word_t)nextFreeArea + (i << objectSize)), userSize, deviceMemory);


        insertNewCap(parent, &slots.cnode[slots.offset + i], cap);


    }
}

exception_t
decodeInvocation(word_t invLabel, word_t length,
                 cptr_t capIndex, cte_t *slot, cap_t cap,
                 extra_caps_t excaps, bool_t block, bool_t call,
                 word_t *buffer)
{
    if (isArchCap(cap)) {
        return Arch_decodeInvocation(invLabel, length, capIndex,
                                     slot, cap, excaps, call, buffer);
    }

    switch (cap_get_capType(cap)) {
    case cap_null_cap:
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;
        return EXCEPTION_SYSCALL_ERROR;

    case cap_zombie_cap:
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 0;
        return EXCEPTION_SYSCALL_ERROR;

    case cap_endpoint_cap:
        if (__builtin_expect(!!(!cap_endpoint_cap_get_capCanSend(cap)), 0)) {
                               ;
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performInvocation_Endpoint(
                   ((endpoint_t *)(cap_endpoint_cap_get_capEPPtr(cap))),
                   cap_endpoint_cap_get_capEPBadge(cap),
                   cap_endpoint_cap_get_capCanGrant(cap), block, call);

    case cap_notification_cap: {
        if (__builtin_expect(!!(!cap_notification_cap_get_capNtfnCanSend(cap)), 0)) {
                               ;
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performInvocation_Notification(
                   ((notification_t *)(cap_notification_cap_get_capNtfnPtr(cap))),
                   cap_notification_cap_get_capNtfnBadge(cap));
    }

    case cap_reply_cap:
        if (__builtin_expect(!!(cap_reply_cap_get_capReplyMaster(cap)), 0)) {
                               ;
            current_syscall_error.type = seL4_InvalidCapability;
            current_syscall_error.invalidCapNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return performInvocation_Reply(
                   ((tcb_t *)(cap_reply_cap_get_capTCBPtr(cap))), slot);

    case cap_thread_cap:
        return decodeTCBInvocation(invLabel, length, cap,
                                   slot, excaps, call, buffer);

    case cap_domain_cap:
        return decodeDomainInvocation(invLabel, length, excaps, buffer);

    case cap_cnode_cap:
        return decodeCNodeInvocation(invLabel, length, cap, excaps, buffer);

    case cap_untyped_cap:
        return decodeUntypedInvocation(invLabel, length, slot, cap, excaps,
                                       call, buffer);

    case cap_irq_control_cap:
        return decodeIRQControlInvocation(invLabel, length, slot,
                                          excaps, buffer);

    case cap_irq_handler_cap:
        return decodeIRQHandlerInvocation(invLabel,
                                          cap_irq_handler_cap_get_capIRQ(cap), excaps);

    default:
        _fail("Invalid cap type", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/objecttype.c", 607, __func__);
    }
}

exception_t
performInvocation_Endpoint(endpoint_t *ep, word_t badge,
                           bool_t canGrant, bool_t block,
                           bool_t call)
{
    sendIPC(block, call, badge, canGrant, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ep);

    return EXCEPTION_NONE;
}

exception_t
performInvocation_Notification(notification_t *ntfn, word_t badge)
{
    sendSignal(ntfn, badge);

    return EXCEPTION_NONE;
}

exception_t
performInvocation_Reply(tcb_t *thread, cte_t *slot)
{
    doReplyTransfer(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, thread, slot);
    return EXCEPTION_NONE;
}



static exception_t
checkPrio(prio_t prio, tcb_t *auth)
{
    prio_t mcp;

    mcp = auth->tcbMCP;


    if(!(mcp <= seL4_MaxPrio)) _assert_fail("mcp <= seL4_MaxPrio", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/tcb.c", 41, __FUNCTION__);


    if (prio > mcp) {
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = seL4_MinPrio;
        current_syscall_error.rangeErrorMax = mcp;
        return EXCEPTION_SYSCALL_ERROR;
    }

    return EXCEPTION_NONE;
}

static inline void
addToBitmap(word_t cpu, word_t dom, word_t prio)
{
    word_t l1index;
    word_t l1index_inverted;

    l1index = prio_to_l1index(prio);
    l1index_inverted = invert_l1index(l1index);

    ksSMP[(cpu)].system.ksReadyQueuesL1Bitmap[dom] |= (1ul << (l1index));




    ksSMP[(cpu)].system.ksReadyQueuesL2Bitmap[dom][l1index_inverted] |= (1ul << (prio & ((1ul << (6))-1ul)));
}

static inline void
removeFromBitmap(word_t cpu, word_t dom, word_t prio)
{
    word_t l1index;
    word_t l1index_inverted;

    l1index = prio_to_l1index(prio);
    l1index_inverted = invert_l1index(l1index);
    ksSMP[(cpu)].system.ksReadyQueuesL2Bitmap[dom][l1index_inverted] &= ~(1ul << (prio & ((1ul << (6))-1ul)));
    if (__builtin_expect(!!(!ksSMP[(cpu)].system.ksReadyQueuesL2Bitmap[dom][l1index_inverted]), 0)) {
        ksSMP[(cpu)].system.ksReadyQueuesL1Bitmap[dom] &= ~(1ul << (l1index));
    }
}


void
tcbSchedEnqueue(tcb_t *tcb)
{
    if (!thread_state_get_tcbQueued(tcb->tcbState)) {
        tcb_queue_t queue;
        dom_t dom;
        prio_t prio;
        word_t idx;

        dom = tcb->tcbDomain;
        prio = tcb->tcbPriority;
        idx = ready_queues_index(dom, prio);
        queue = ksSMP[(tcb->tcbAffinity)].system.ksReadyQueues[idx];

        if (!queue.end) {
            queue.end = tcb;
            addToBitmap(tcb->tcbAffinity, dom, prio);
        } else {
            queue.head->tcbSchedPrev = tcb;
        }
        tcb->tcbSchedPrev = ((void *)0);
        tcb->tcbSchedNext = queue.head;
        queue.head = tcb;

        ksSMP[(tcb->tcbAffinity)].system.ksReadyQueues[idx] = queue;

        thread_state_ptr_set_tcbQueued(&tcb->tcbState, true);
    }
}


void
tcbSchedAppend(tcb_t *tcb)
{
    if (!thread_state_get_tcbQueued(tcb->tcbState)) {
        tcb_queue_t queue;
        dom_t dom;
        prio_t prio;
        word_t idx;

        dom = tcb->tcbDomain;
        prio = tcb->tcbPriority;
        idx = ready_queues_index(dom, prio);
        queue = ksSMP[(tcb->tcbAffinity)].system.ksReadyQueues[idx];

        if (!queue.head) {
            queue.head = tcb;
            addToBitmap(tcb->tcbAffinity, dom, prio);
        } else {
            queue.end->tcbSchedNext = tcb;
        }
        tcb->tcbSchedPrev = queue.end;
        tcb->tcbSchedNext = ((void *)0);
        queue.end = tcb;

        ksSMP[(tcb->tcbAffinity)].system.ksReadyQueues[idx] = queue;

        thread_state_ptr_set_tcbQueued(&tcb->tcbState, true);
    }
}


void
tcbSchedDequeue(tcb_t *tcb)
{
    if (thread_state_get_tcbQueued(tcb->tcbState)) {
        tcb_queue_t queue;
        dom_t dom;
        prio_t prio;
        word_t idx;

        dom = tcb->tcbDomain;
        prio = tcb->tcbPriority;
        idx = ready_queues_index(dom, prio);
        queue = ksSMP[(tcb->tcbAffinity)].system.ksReadyQueues[idx];

        if (tcb->tcbSchedPrev) {
            tcb->tcbSchedPrev->tcbSchedNext = tcb->tcbSchedNext;
        } else {
            queue.head = tcb->tcbSchedNext;
            if (__builtin_expect(!!(!tcb->tcbSchedNext), 1)) {
                removeFromBitmap(tcb->tcbAffinity, dom, prio);
            }
        }

        if (tcb->tcbSchedNext) {
            tcb->tcbSchedNext->tcbSchedPrev = tcb->tcbSchedPrev;
        } else {
            queue.end = tcb->tcbSchedPrev;
        }

        ksSMP[(tcb->tcbAffinity)].system.ksReadyQueues[idx] = queue;

        thread_state_ptr_set_tcbQueued(&tcb->tcbState, false);
    }
}


void tcbDebugAppend(tcb_t *tcb)
{

    tcb->tcbDebugPrev = ((void *)0);

    tcb->tcbDebugNext = ksSMP[(tcb->tcbAffinity)].system.ksDebugTCBs;

    if (ksSMP[(tcb->tcbAffinity)].system.ksDebugTCBs) {
        ksSMP[(tcb->tcbAffinity)].system.ksDebugTCBs->tcbDebugPrev = tcb;
    }

    ksSMP[(tcb->tcbAffinity)].system.ksDebugTCBs = tcb;
}

void tcbDebugRemove(tcb_t *tcb)
{
    if(!(ksSMP[(tcb->tcbAffinity)].system.ksDebugTCBs != ((void *)0))) _assert_fail("NODE_STATE_ON_CORE(ksDebugTCBs, tcb->tcbAffinity) != NULL", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/tcb.c", 200, __FUNCTION__);
    if (tcb == ksSMP[(tcb->tcbAffinity)].system.ksDebugTCBs) {
        ksSMP[(tcb->tcbAffinity)].system.ksDebugTCBs = ksSMP[(tcb->tcbAffinity)].system.ksDebugTCBs->tcbDebugNext;
    } else {
        if(!(tcb->tcbDebugPrev)) _assert_fail("tcb->tcbDebugPrev", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/tcb.c", 204, __FUNCTION__);
        tcb->tcbDebugPrev->tcbDebugNext = tcb->tcbDebugNext;
    }

    if (tcb->tcbDebugNext) {
        tcb->tcbDebugNext->tcbDebugPrev = tcb->tcbDebugPrev;
    }

    tcb->tcbDebugPrev = ((void *)0);
    tcb->tcbDebugNext = ((void *)0);
}



tcb_queue_t
tcbEPAppend(tcb_t *tcb, tcb_queue_t queue)
{
    if (!queue.head) {
        queue.head = tcb;
    } else {
        queue.end->tcbEPNext = tcb;
    }
    tcb->tcbEPPrev = queue.end;
    tcb->tcbEPNext = ((void *)0);
    queue.end = tcb;

    return queue;
}


tcb_queue_t
tcbEPDequeue(tcb_t *tcb, tcb_queue_t queue)
{
    if (tcb->tcbEPPrev) {
        tcb->tcbEPPrev->tcbEPNext = tcb->tcbEPNext;
    } else {
        queue.head = tcb->tcbEPNext;
    }

    if (tcb->tcbEPNext) {
        tcb->tcbEPNext->tcbEPPrev = tcb->tcbEPPrev;
    } else {
        queue.end = tcb->tcbEPPrev;
    }

    return queue;
}

cptr_t __attribute__((__pure__))
getExtraCPtr(word_t *bufferPtr, word_t i)
{
    return (cptr_t)bufferPtr[seL4_MsgMaxLength + 2 + i];
}

void
setExtraBadge(word_t *bufferPtr, word_t badge,
              word_t i)
{
    bufferPtr[seL4_MsgMaxLength + 2 + i] = badge;
}

void
setupCallerCap(tcb_t *sender, tcb_t *receiver)
{
    cte_t *replySlot, *callerSlot;
    cap_t masterCap __attribute__((unused)), callerCap __attribute__((unused));

    setThreadState(sender, ThreadState_BlockedOnReply);
    replySlot = (((cte_t *)((word_t)(sender)&~((1ul << (11))-1ul)))+(tcbReply));
    masterCap = replySlot->cap;

    if(!(cap_get_capType(masterCap) == cap_reply_cap)) _assert_fail("cap_get_capType(masterCap) == cap_reply_cap", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/tcb.c", 275, __FUNCTION__);
    if(!(cap_reply_cap_get_capReplyMaster(masterCap))) _assert_fail("cap_reply_cap_get_capReplyMaster(masterCap)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/tcb.c", 276, __FUNCTION__);
    if(!(((tcb_t *)(cap_reply_cap_get_capTCBPtr(masterCap))) == sender)) _assert_fail("TCB_PTR(cap_reply_cap_get_capTCBPtr(masterCap)) == sender", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/tcb.c", 277, __FUNCTION__);
    callerSlot = (((cte_t *)((word_t)(receiver)&~((1ul << (11))-1ul)))+(tcbCaller));
    callerCap = callerSlot->cap;

    if(!(cap_get_capType(callerCap) == cap_null_cap)) _assert_fail("cap_get_capType(callerCap) == cap_null_cap", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/tcb.c", 281, __FUNCTION__);
    cteInsert(cap_reply_cap_new(false, ((word_t)(sender))),
              replySlot, callerSlot);
}

void
deleteCallerCap(tcb_t *receiver)
{
    cte_t *callerSlot;

    callerSlot = (((cte_t *)((word_t)(receiver)&~((1ul << (11))-1ul)))+(tcbCaller));

    cteDeleteOne(callerSlot);
}

extra_caps_t current_extra_caps;

exception_t
lookupExtraCaps(tcb_t* thread, word_t *bufferPtr, seL4_MessageInfo_t info)
{
    lookupSlot_raw_ret_t lu_ret;
    cptr_t cptr;
    word_t i, length;

    if (!bufferPtr) {
        current_extra_caps.excaprefs[0] = ((void *)0);
        return EXCEPTION_NONE;
    }

    length = seL4_MessageInfo_get_extraCaps(info);

    for (i = 0; i < length; i++) {
        cptr = getExtraCPtr(bufferPtr, i);

        lu_ret = lookupSlot(thread, cptr);
        if (lu_ret.status != EXCEPTION_NONE) {
            current_fault = seL4_Fault_CapFault_new(cptr, false);
            return lu_ret.status;
        }

        current_extra_caps.excaprefs[i] = lu_ret.slot;
    }
    if (i < ((1ul<<(seL4_MsgExtraCapBits))-1)) {
        current_extra_caps.excaprefs[i] = ((void *)0);
    }

    return EXCEPTION_NONE;
}


word_t
copyMRs(tcb_t *sender, word_t *sendBuf, tcb_t *receiver,
        word_t *recvBuf, word_t n)
{
    word_t i;


    for (i = 0; i < n && i < n_msgRegisters; i++) {
        setRegister(receiver, msgRegisters[i],
                    getRegister(sender, msgRegisters[i]));
    }

    if (!recvBuf || !sendBuf) {
        return i;
    }


    for (; i < n; i++) {
        recvBuf[i + 1] = sendBuf[i + 1];
    }

    return i;
}




void
remoteQueueUpdate(tcb_t *tcb)
{

    if (tcb->tcbAffinity != getCurrentCPUIndex() && tcb->tcbDomain == ksCurDomain) {
        tcb_t *targetCurThread = ksSMP[(tcb->tcbAffinity)].system.ksCurThread;


        if (targetCurThread == ksSMP[(tcb->tcbAffinity)].system.ksIdleThread ||
                tcb->tcbPriority > targetCurThread->tcbPriority) {
            ksSMP[(getCurrentCPUIndex())].cpu.ipiReschedulePending |= (1ul << (tcb->tcbAffinity));
        }
    }
}




void
remoteTCBStall(tcb_t *tcb)
{

    if (tcb->tcbAffinity != getCurrentCPUIndex() &&
            ksSMP[(tcb->tcbAffinity)].system.ksCurThread == tcb) {
        doRemoteStall(tcb->tcbAffinity);
        ksSMP[(getCurrentCPUIndex())].cpu.ipiReschedulePending |= (1ul << (tcb->tcbAffinity));
    }
}

static exception_t
invokeTCB_SetAffinity(tcb_t *thread, word_t affinity)
{


    tcbSchedDequeue(thread);
    migrateTCB(thread, affinity);
    if (isRunnable(thread)) {
        do { tcbSchedAppend(thread); remoteQueueUpdate(thread); } while (0);
    }

    if (thread == ksSMP[(getCurrentCPUIndex())].system.ksCurThread) {
        rescheduleRequired();
    }
    return EXCEPTION_NONE;
}

static exception_t
decodeSetAffinity(cap_t cap, word_t length, word_t *buffer)
{
    tcb_t *tcb;
    word_t affinity;

    if (length < 1) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 411, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetAffinity: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tcb = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap)));

    affinity = getSyscallArg(0, buffer);
    if (affinity >= ksNumCPUs) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 420, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetAffinity: Requested CPU does not exist."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_SetAffinity(tcb, affinity);
}




exception_t
decodeTCBInvocation(word_t invLabel, word_t length, cap_t cap,
                    cte_t* slot, extra_caps_t excaps, bool_t call,
                    word_t *buffer)
{

    remoteTCBStall(((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))));

    switch (invLabel) {
    case TCBReadRegisters:

        return decodeReadRegisters(cap, length, call, buffer);

    case TCBWriteRegisters:
        return decodeWriteRegisters(cap, length, buffer);

    case TCBCopyRegisters:
        return decodeCopyRegisters(cap, length, excaps, buffer);

    case TCBSuspend:

        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return invokeTCB_Suspend(
                   ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))));

    case TCBResume:
        setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        return invokeTCB_Resume(
                   ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))));

    case TCBConfigure:
        return decodeTCBConfigure(cap, length, slot, excaps, buffer);

    case TCBSetPriority:
        return decodeSetPriority(cap, length, excaps, buffer);

    case TCBSetMCPriority:
        return decodeSetMCPriority(cap, length, excaps, buffer);

    case TCBSetSchedParams:
        return decodeSetSchedParams(cap, length, excaps, buffer);

    case TCBSetIPCBuffer:
        return decodeSetIPCBuffer(cap, length, slot, excaps, buffer);

    case TCBSetSpace:
        return decodeSetSpace(cap, length, slot, excaps, buffer);

    case TCBBindNotification:
        return decodeBindNotification(cap, excaps);

    case TCBUnbindNotification:
        return decodeUnbindNotification(cap);


    case TCBSetAffinity:
        return decodeSetAffinity(cap, length, buffer);




    case TCBSetEPTRoot:
        return decodeSetEPTRoot(cap, excaps);
    default:

        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 748, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB: Illegal operation."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }
}

enum CopyRegistersFlags {
    CopyRegisters_suspendSource = 0,
    CopyRegisters_resumeTarget = 1,
    CopyRegisters_transferFrame = 2,
    CopyRegisters_transferInteger = 3
};

exception_t
decodeCopyRegisters(cap_t cap, word_t length,
                    extra_caps_t excaps, word_t *buffer)
{
    word_t transferArch;
    tcb_t *srcTCB;
    cap_t source_cap;
    word_t flags;

    if (length < 1 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 771, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB CopyRegisters: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    flags = getSyscallArg(0, buffer);

    transferArch = Arch_decodeTransfer(flags >> 8);

    source_cap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(source_cap) == cap_thread_cap) {
        srcTCB = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(source_cap)));
    } else {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 785, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB CopyRegisters: Invalid source TCB."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_CopyRegisters(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), srcTCB,
               flags & (1ul << (CopyRegisters_suspendSource)),
               flags & (1ul << (CopyRegisters_resumeTarget)),
               flags & (1ul << (CopyRegisters_transferFrame)),
               flags & (1ul << (CopyRegisters_transferInteger)),
               transferArch);

}

enum ReadRegistersFlags {
    ReadRegisters_suspend = 0
};

exception_t
decodeReadRegisters(cap_t cap, word_t length, bool_t call,
                    word_t *buffer)
{
    word_t transferArch, flags, n;
    tcb_t* thread;

    if (length < 2) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 814, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB ReadRegisters: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    flags = getSyscallArg(0, buffer);
    n = getSyscallArg(1, buffer);

    if (n < 1 || n > n_frameRegisters + n_gpRegisters) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 824, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB ReadRegisters: Attempted to read an invalid number of registers (%d).", (int)n); kprintf(">>" "" "\n"); } while (0)
                         ;
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 1;
        current_syscall_error.rangeErrorMax = n_frameRegisters +
                                              n_gpRegisters;
        return EXCEPTION_SYSCALL_ERROR;
    }

    transferArch = Arch_decodeTransfer(flags >> 8);

    thread = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap)));
    if (thread == ksSMP[(getCurrentCPUIndex())].system.ksCurThread) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 836, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB ReadRegisters: Attempted to read our own registers."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_ReadRegisters(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))),
               flags & (1ul << (ReadRegisters_suspend)),
               n, transferArch, call);
}

enum WriteRegistersFlags {
    WriteRegisters_resume = 0
};

exception_t
decodeWriteRegisters(cap_t cap, word_t length, word_t *buffer)
{
    word_t flags, w;
    word_t transferArch;
    tcb_t* thread;

    if (length < 2) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 860, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB WriteRegisters: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    flags = getSyscallArg(0, buffer);
    w = getSyscallArg(1, buffer);

    if (length - 2 < w) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 870, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB WriteRegisters: Message too short for requested write size (%d/%d).", (int)(length - 2), (int)w); kprintf(">>" "" "\n"); } while (0)
                                            ;
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    transferArch = Arch_decodeTransfer(flags >> 8);

    thread = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap)));
    if (thread == ksSMP[(getCurrentCPUIndex())].system.ksCurThread) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 879, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB WriteRegisters: Attempted to write our own registers."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_WriteRegisters(thread,
                                    flags & (1ul << (WriteRegisters_resume)),
                                    w, transferArch, buffer);
}



exception_t
decodeTCBConfigure(cap_t cap, word_t length, cte_t* slot,
                   extra_caps_t rootCaps, word_t *buffer)
{
    cte_t *bufferSlot, *cRootSlot, *vRootSlot;
    cap_t bufferCap, cRootCap, vRootCap;
    deriveCap_ret_t dc_ret;
    cptr_t faultEP;
    word_t cRootData, vRootData, bufferAddr;

    if (length < 4 || rootCaps.excaprefs[0] == ((void *)0)
            || rootCaps.excaprefs[1] == ((void *)0)
            || rootCaps.excaprefs[2] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 905, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB Configure: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    faultEP = getSyscallArg(0, buffer);
    cRootData = getSyscallArg(1, buffer);
    vRootData = getSyscallArg(2, buffer);
    bufferAddr = getSyscallArg(3, buffer);

    cRootSlot = rootCaps.excaprefs[0];
    cRootCap = rootCaps.excaprefs[0]->cap;
    vRootSlot = rootCaps.excaprefs[1];
    vRootCap = rootCaps.excaprefs[1]->cap;
    bufferSlot = rootCaps.excaprefs[2];
    bufferCap = rootCaps.excaprefs[2]->cap;

    if (bufferAddr == 0) {
        bufferSlot = ((void *)0);
    } else {
        dc_ret = deriveCap(bufferSlot, bufferCap);
        if (dc_ret.status != EXCEPTION_NONE) {
            return dc_ret.status;
        }
        bufferCap = dc_ret.cap;

        exception_t e = checkValidIPCBuffer(bufferAddr, bufferCap);
        if (e != EXCEPTION_NONE) {
            return e;
        }
    }

    if (slotCapLongRunningDelete(
                (((cte_t *)((word_t)(cap_thread_cap_get_capTCBPtr(cap))&~((1ul << (11))-1ul)))+(tcbCTable))) ||
            slotCapLongRunningDelete(
                (((cte_t *)((word_t)(cap_thread_cap_get_capTCBPtr(cap))&~((1ul << (11))-1ul)))+(tcbVTable)))) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 941, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB Configure: CSpace or VSpace currently being deleted."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cRootData != 0) {
        cRootCap = updateCapData(false, cRootData, cRootCap);
    }

    dc_ret = deriveCap(cRootSlot, cRootCap);
    if (dc_ret.status != EXCEPTION_NONE) {
        return dc_ret.status;
    }
    cRootCap = dc_ret.cap;

    if (cap_get_capType(cRootCap) != cap_cnode_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 957, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB Configure: CSpace cap is invalid."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (vRootData != 0) {
        vRootCap = updateCapData(false, vRootData, vRootCap);
    }

    dc_ret = deriveCap(vRootSlot, vRootCap);
    if (dc_ret.status != EXCEPTION_NONE) {
        return dc_ret.status;
    }
    vRootCap = dc_ret.cap;

    if (!isValidVTableRoot(vRootCap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 973, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB Configure: VSpace cap is invalid."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), slot,
               faultEP, 0, 0,
               cRootCap, cRootSlot,
               vRootCap, vRootSlot,
               bufferAddr, bufferCap,
               bufferSlot, thread_control_update_space |
               thread_control_update_ipc_buffer);
}

exception_t
decodeSetPriority(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer)
{
    if (length < 1 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 993, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetPriority: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    prio_t newPrio = getSyscallArg(0, buffer);
    cap_t authCap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(authCap) != cap_thread_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1002, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Set priority: authority cap not a TCB."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tcb_t *authTCB = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(authCap)));
    exception_t status = checkPrio(newPrio, authTCB);
    if (status != EXCEPTION_NONE) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1012, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetPriority: Requested priority %lu too high (max %lu).", (unsigned long) newPrio, (unsigned long) authTCB->tcbMCP); kprintf(">>" "" "\n"); } while (0)
                                                                           ;
        return status;
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), ((void *)0),
               0, 0, newPrio,
               cap_null_cap_new(), ((void *)0),
               cap_null_cap_new(), ((void *)0),
               0, cap_null_cap_new(),
               ((void *)0), thread_control_update_priority);
}

exception_t
decodeSetMCPriority(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer)
{
    if (length < 1 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1030, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetMCPriority: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    prio_t newMcp = getSyscallArg(0, buffer);
    cap_t authCap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(authCap) != cap_thread_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1039, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetMCPriority: authority cap not a TCB."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tcb_t *authTCB = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(authCap)));
    exception_t status = checkPrio(newMcp, authTCB);
    if (status != EXCEPTION_NONE) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1049, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetMCPriority: Requested maximum controlled priority %lu too high (max %lu).", (unsigned long) newMcp, (unsigned long) authTCB->tcbMCP); kprintf(">>" "" "\n"); } while (0)
                                                                          ;
        return status;
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), ((void *)0),
               0, newMcp, 0,
               cap_null_cap_new(), ((void *)0),
               cap_null_cap_new(), ((void *)0),
               0, cap_null_cap_new(),
               ((void *)0), thread_control_update_mcp);
}

exception_t
decodeSetSchedParams(cap_t cap, word_t length, extra_caps_t excaps, word_t *buffer)
{
    if (length < 2 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1067, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetSchedParams: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    prio_t newMcp = getSyscallArg(0, buffer);
    prio_t newPrio = getSyscallArg(1, buffer);
    cap_t authCap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(authCap) != cap_thread_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1077, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetSchedParams: authority cap not a TCB."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidCapability;
        current_syscall_error.invalidCapNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tcb_t *authTCB = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(authCap)));
    exception_t status = checkPrio(newMcp, authTCB);
    if (status != EXCEPTION_NONE) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1087, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetSchedParams: Requested maximum controlled priority %lu too high (max %lu).", (unsigned long) newMcp, (unsigned long) authTCB->tcbMCP); kprintf(">>" "" "\n"); } while (0)
                                                                          ;
        return status;
    }

    status = checkPrio(newPrio, authTCB);
    if (status != EXCEPTION_NONE) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1094, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetSchedParams: Requested priority %lu too high (max %lu).", (unsigned long) newMcp, (unsigned long) authTCB->tcbMCP); kprintf(">>" "" "\n"); } while (0)
                                                                          ;
        return status;
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), ((void *)0),
               0, newMcp, newPrio,
               cap_null_cap_new(), ((void *)0),
               cap_null_cap_new(), ((void *)0),
               0, cap_null_cap_new(),
               ((void *)0), thread_control_update_mcp |
               thread_control_update_priority);
}


exception_t
decodeSetIPCBuffer(cap_t cap, word_t length, cte_t* slot,
                   extra_caps_t excaps, word_t *buffer)
{
    cptr_t cptr_bufferPtr;
    cap_t bufferCap;
    cte_t *bufferSlot;

    if (length < 1 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1119, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetIPCBuffer: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    cptr_bufferPtr = getSyscallArg(0, buffer);
    bufferSlot = excaps.excaprefs[0];
    bufferCap = excaps.excaprefs[0]->cap;

    if (cptr_bufferPtr == 0) {
        bufferSlot = ((void *)0);
    } else {
        exception_t e;
        deriveCap_ret_t dc_ret;

        dc_ret = deriveCap(bufferSlot, bufferCap);
        if (dc_ret.status != EXCEPTION_NONE) {
            return dc_ret.status;
        }
        bufferCap = dc_ret.cap;
        e = checkValidIPCBuffer(cptr_bufferPtr, bufferCap);
        if (e != EXCEPTION_NONE) {
            return e;
        }
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), slot,
               0, 0, 0,
               cap_null_cap_new(), ((void *)0),
               cap_null_cap_new(), ((void *)0),
               cptr_bufferPtr, bufferCap,
               bufferSlot, thread_control_update_ipc_buffer);
}

exception_t
decodeSetSpace(cap_t cap, word_t length, cte_t* slot,
               extra_caps_t excaps, word_t *buffer)
{
    cptr_t faultEP;
    word_t cRootData, vRootData;
    cte_t *cRootSlot, *vRootSlot;
    cap_t cRootCap, vRootCap;
    deriveCap_ret_t dc_ret;

    if (length < 3 || excaps.excaprefs[0] == ((void *)0)
            || excaps.excaprefs[1] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1167, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetSpace: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    faultEP = getSyscallArg(0, buffer);
    cRootData = getSyscallArg(1, buffer);
    vRootData = getSyscallArg(2, buffer);

    cRootSlot = excaps.excaprefs[0];
    cRootCap = excaps.excaprefs[0]->cap;
    vRootSlot = excaps.excaprefs[1];
    vRootCap = excaps.excaprefs[1]->cap;

    if (slotCapLongRunningDelete(
                (((cte_t *)((word_t)(cap_thread_cap_get_capTCBPtr(cap))&~((1ul << (11))-1ul)))+(tcbCTable))) ||
            slotCapLongRunningDelete(
                (((cte_t *)((word_t)(cap_thread_cap_get_capTCBPtr(cap))&~((1ul << (11))-1ul)))+(tcbVTable)))) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1185, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetSpace: CSpace or VSpace currently being deleted."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (cRootData != 0) {
        cRootCap = updateCapData(false, cRootData, cRootCap);
    }

    dc_ret = deriveCap(cRootSlot, cRootCap);
    if (dc_ret.status != EXCEPTION_NONE) {
        return dc_ret.status;
    }
    cRootCap = dc_ret.cap;

    if (cap_get_capType(cRootCap) != cap_cnode_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1201, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetSpace: Invalid CNode cap."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (vRootData != 0) {
        vRootCap = updateCapData(false, vRootData, vRootCap);
    }

    dc_ret = deriveCap(vRootSlot, vRootCap);
    if (dc_ret.status != EXCEPTION_NONE) {
        return dc_ret.status;
    }
    vRootCap = dc_ret.cap;

    if (!isValidVTableRoot(vRootCap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1217, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB SetSpace: Invalid VSpace cap."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_ThreadControl(
               ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap))), slot,
               faultEP,
               0, 0,
               cRootCap, cRootSlot,
               vRootCap, vRootSlot,
               0, cap_null_cap_new(), ((void *)0), thread_control_update_space);
}

exception_t
decodeDomainInvocation(word_t invLabel, word_t length, extra_caps_t excaps, word_t *buffer)
{
    word_t domain;
    cap_t tcap;

    if (__builtin_expect(!!(invLabel != DomainSetSet), 0)) {
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (__builtin_expect(!!(length == 0), 0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1244, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Domain Configure: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    } else {
        domain = getSyscallArg(0, buffer);
        if (domain >= 1) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1251, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Domain Configure: invalid domain (%lu >= %u).", domain, 1); kprintf(">>" "" "\n"); } while (0)
                                                 ;
            current_syscall_error.type = seL4_InvalidArgument;
            current_syscall_error.invalidArgumentNumber = 0;
            return EXCEPTION_SYSCALL_ERROR;
        }
    }

    if (__builtin_expect(!!(excaps.excaprefs[0] == ((void *)0)), 0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1259, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Domain Configure: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tcap = excaps.excaprefs[0]->cap;
    if (__builtin_expect(!!(cap_get_capType(tcap) != cap_thread_cap), 0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1266, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Domain Configure: thread cap required."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    setDomain(((tcb_t *)(cap_thread_cap_get_capTCBPtr(tcap))), domain);
    return EXCEPTION_NONE;
}

exception_t
decodeBindNotification(cap_t cap, extra_caps_t excaps)
{
    notification_t *ntfnPtr;
    tcb_t *tcb;
    cap_t ntfn_cap;

    if (excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1285, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB BindNotification: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }

    tcb = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap)));

    if (tcb->tcbBoundNotification) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1293, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB BindNotification: TCB already has a bound notification."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    ntfn_cap = excaps.excaprefs[0]->cap;

    if (cap_get_capType(ntfn_cap) == cap_notification_cap) {
        ntfnPtr = ((notification_t *)(cap_notification_cap_get_capNtfnPtr(ntfn_cap)));
    } else {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1303, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB BindNotification: Notification is invalid."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (!cap_notification_cap_get_capNtfnCanReceive(ntfn_cap)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1309, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB BindNotification: Insufficient access rights"); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if ((tcb_t*)notification_ptr_get_ntfnQueue_head(ntfnPtr)
            || (tcb_t*)notification_ptr_get_ntfnBoundTCB(ntfnPtr)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1316, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB BindNotification: Notification cannot be bound."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }


    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_NotificationControl(tcb, ntfnPtr);
}

exception_t
decodeUnbindNotification(cap_t cap)
{
    tcb_t *tcb;

    tcb = ((tcb_t *)(cap_thread_cap_get_capTCBPtr(cap)));

    if (!tcb->tcbBoundNotification) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 1334, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("TCB UnbindNotification: TCB already has no bound Notification."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }

    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeTCB_NotificationControl(tcb, ((void *)0));
}



exception_t
invokeTCB_Suspend(tcb_t *thread)
{
    suspend(thread);
    return EXCEPTION_NONE;
}

exception_t
invokeTCB_Resume(tcb_t *thread)
{
    restart(thread);
    return EXCEPTION_NONE;
}

exception_t
invokeTCB_ThreadControl(tcb_t *target, cte_t* slot,
                        cptr_t faultep, prio_t mcp, prio_t priority,
                        cap_t cRoot_newCap, cte_t *cRoot_srcSlot,
                        cap_t vRoot_newCap, cte_t *vRoot_srcSlot,
                        word_t bufferAddr, cap_t bufferCap,
                        cte_t *bufferSrcSlot,
                        thread_control_flag_t updateFlags)
{
    exception_t e;
    cap_t tCap = cap_thread_cap_new((word_t)target);

    if (updateFlags & thread_control_update_space) {
        target->tcbFaultHandler = faultep;
    }

    if (updateFlags & thread_control_update_mcp) {
        setMCPriority(target, mcp);
    }

    if (updateFlags & thread_control_update_priority) {
        setPriority(target, priority);
    }

    if (updateFlags & thread_control_update_space) {
        cte_t *rootSlot;

        rootSlot = (((cte_t *)((word_t)(target)&~((1ul << (11))-1ul)))+(tcbCTable));
        e = cteDelete(rootSlot, true);
        if (e != EXCEPTION_NONE) {
            return e;
        }
        if (sameObjectAs(cRoot_newCap, cRoot_srcSlot->cap) &&
                sameObjectAs(tCap, slot->cap)) {
            cteInsert(cRoot_newCap, cRoot_srcSlot, rootSlot);
        }
    }

    if (updateFlags & thread_control_update_space) {
        cte_t *rootSlot;

        rootSlot = (((cte_t *)((word_t)(target)&~((1ul << (11))-1ul)))+(tcbVTable));
        e = cteDelete(rootSlot, true);
        if (e != EXCEPTION_NONE) {
            return e;
        }
        if (sameObjectAs(vRoot_newCap, vRoot_srcSlot->cap) &&
                sameObjectAs(tCap, slot->cap)) {
            cteInsert(vRoot_newCap, vRoot_srcSlot, rootSlot);
        }
    }

    if (updateFlags & thread_control_update_ipc_buffer) {
        cte_t *bufferSlot;

        bufferSlot = (((cte_t *)((word_t)(target)&~((1ul << (11))-1ul)))+(tcbBuffer));
        e = cteDelete(bufferSlot, true);
        if (e != EXCEPTION_NONE) {
            return e;
        }
        target->tcbIPCBuffer = bufferAddr;

        Arch_setTCBIPCBuffer(target, bufferAddr);

        if (bufferSrcSlot && sameObjectAs(bufferCap, bufferSrcSlot->cap) &&
                sameObjectAs(tCap, slot->cap)) {
            cteInsert(bufferCap, bufferSrcSlot, bufferSlot);
        }

        if (target == ksSMP[(getCurrentCPUIndex())].system.ksCurThread) {
            rescheduleRequired();
        }
    }

    return EXCEPTION_NONE;
}

exception_t
invokeTCB_CopyRegisters(tcb_t *dest, tcb_t *tcb_src,
                        bool_t suspendSource, bool_t resumeTarget,
                        bool_t transferFrame, bool_t transferInteger,
                        word_t transferArch)
{
    if (suspendSource) {
        suspend(tcb_src);
    }

    if (resumeTarget) {
        restart(dest);
    }

    if (transferFrame) {
        word_t i;
        word_t v;
        word_t pc;

        for (i = 0; i < n_frameRegisters; i++) {
            v = getRegister(tcb_src, frameRegisters[i]);
            setRegister(dest, frameRegisters[i], v);
        }

        pc = getRestartPC(dest);
        setNextPC(dest, pc);
    }

    if (transferInteger) {
        word_t i;
        word_t v;

        for (i = 0; i < n_gpRegisters; i++) {
            v = getRegister(tcb_src, gpRegisters[i]);
            setRegister(dest, gpRegisters[i], v);
        }
    }

    Arch_postModifyRegisters(dest);

    if (dest == ksSMP[(getCurrentCPUIndex())].system.ksCurThread) {


        rescheduleRequired();
    }

    return Arch_performTransfer(transferArch, tcb_src, dest);
}







exception_t
invokeTCB_ReadRegisters(tcb_t *tcb_src, bool_t suspendSource,
                        word_t n, word_t arch, bool_t call)
{
    word_t i, j;
    exception_t e;
    tcb_t *thread;

    thread = ksSMP[(getCurrentCPUIndex())].system.ksCurThread;

    if (suspendSource) {
        suspend(tcb_src);
    }

    e = Arch_performTransfer(arch, tcb_src, ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
    if (e != EXCEPTION_NONE) {
        return e;
    }

    if (call) {
        word_t *ipcBuffer;

        ipcBuffer = lookupIPCBuffer(true, thread);

        setRegister(thread, badgeRegister, 0);

        for (i = 0; i < n && i < n_frameRegisters && i < n_msgRegisters; i++) {
            setRegister(thread, msgRegisters[i],
                        getRegister(tcb_src, frameRegisters[i]));
        }

        if (ipcBuffer != ((void *)0) && i < n && i < n_frameRegisters) {
            for (; i < n && i < n_frameRegisters; i++) {
                ipcBuffer[i + 1] = getRegister(tcb_src, frameRegisters[i]);
            }
        }

        j = i;

        for (i = 0; i < n_gpRegisters && i + n_frameRegisters < n
                && i + n_frameRegisters < n_msgRegisters; i++) {
            setRegister(thread, msgRegisters[i + n_frameRegisters],
                        getRegister(tcb_src, gpRegisters[i]));
        }

        if (ipcBuffer != ((void *)0) && i < n_gpRegisters
                && i + n_frameRegisters < n) {
            for (; i < n_gpRegisters && i + n_frameRegisters < n; i++) {
                ipcBuffer[i + n_frameRegisters + 1] =
                    getRegister(tcb_src, gpRegisters[i]);
            }
        }

        setRegister(thread, msgInfoRegister, wordFromMessageInfo(
                        seL4_MessageInfo_new(0, 0, 0, i + j)));
    }
    setThreadState(thread, ThreadState_Running);

    return EXCEPTION_NONE;
}

exception_t
invokeTCB_WriteRegisters(tcb_t *dest, bool_t resumeTarget,
                         word_t n, word_t arch, word_t *buffer)
{
    word_t i;
    word_t pc;
    exception_t e;
    bool_t archInfo;

    e = Arch_performTransfer(arch, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, dest);
    if (e != EXCEPTION_NONE) {
        return e;
    }

    if (n > n_frameRegisters + n_gpRegisters) {
        n = n_frameRegisters + n_gpRegisters;
    }

    archInfo = Arch_getSanitiseRegisterInfo(dest);

    for (i = 0; i < n_frameRegisters && i < n; i++) {

        setRegister(dest, frameRegisters[i],
                    sanitiseRegister(frameRegisters[i],
                                     getSyscallArg(i + 2, buffer), archInfo));
    }

    for (i = 0; i < n_gpRegisters && i + n_frameRegisters < n; i++) {
        setRegister(dest, gpRegisters[i],
                    sanitiseRegister(gpRegisters[i],
                                     getSyscallArg(i + n_frameRegisters + 2,
                                                   buffer), archInfo));
    }

    pc = getRestartPC(dest);
    setNextPC(dest, pc);

    Arch_postModifyRegisters(dest);

    if (resumeTarget) {
        restart(dest);
    }

    if (dest == ksSMP[(getCurrentCPUIndex())].system.ksCurThread) {


        rescheduleRequired();
    }

    return EXCEPTION_NONE;
}

exception_t
invokeTCB_NotificationControl(tcb_t *tcb, notification_t *ntfnPtr)
{
    if (ntfnPtr) {
        bindNotification(tcb, ntfnPtr);
    } else {
        unbindNotification(tcb);
    }

    return EXCEPTION_NONE;
}


void
setThreadName(tcb_t *tcb, const char *name)
{
    strlcpy(tcb->tcbName, name, ((1ul << (11)) - (1ul << ((11 - 1))) - sizeof(tcb_t)));
}


word_t
setMRs_syscall_error(tcb_t *thread, word_t *receiveIPCBuffer)
{
    switch (current_syscall_error.type) {
    case seL4_InvalidArgument:
        return setMR(thread, receiveIPCBuffer, 0,
                     current_syscall_error.invalidArgumentNumber);

    case seL4_InvalidCapability:
        return setMR(thread, receiveIPCBuffer, 0,
                     current_syscall_error.invalidCapNumber);

    case seL4_IllegalOperation:
        return 0;

    case seL4_RangeError:
        setMR(thread, receiveIPCBuffer, 0,
              current_syscall_error.rangeErrorMin);
        return setMR(thread, receiveIPCBuffer, 1,
                     current_syscall_error.rangeErrorMax);

    case seL4_AlignmentError:
        return 0;

    case seL4_FailedLookup:
        setMR(thread, receiveIPCBuffer, 0,
              current_syscall_error.failedLookupWasSource ? 1 : 0);
        return setMRs_lookup_failure(thread, receiveIPCBuffer,
                                     current_lookup_fault, 1);

    case seL4_TruncatedMessage:
    case seL4_DeleteFirst:
    case seL4_RevokeFirst:
        return 0;
    case seL4_NotEnoughMemory:
        return setMR(thread, receiveIPCBuffer, 0,
                     current_syscall_error.memoryLeft);
    default:
        _fail("Invalid syscall error", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/object/tcb.c", 1662, __func__);
    }
}

static word_t
alignUp(word_t baseValue, word_t alignment)
{
    return (baseValue + ((1ul << (alignment)) - 1)) & ~((1ul << (alignment))-1ul);
}

exception_t
decodeUntypedInvocation(word_t invLabel, word_t length, cte_t *slot,
                        cap_t cap, extra_caps_t excaps,
                        bool_t call, word_t *buffer)
{
    word_t newType, userObjSize, nodeIndex;
    word_t nodeDepth, nodeOffset, nodeWindow;
    cte_t *rootSlot __attribute__((unused));
    exception_t status;
    cap_t nodeCap;
    lookupSlot_ret_t lu_ret;
    word_t nodeSize;
    word_t i;
    slot_range_t slots;
    word_t freeRef, alignedFreeRef, objectSize, untypedFreeBytes;
    word_t freeIndex;
    bool_t deviceMemory;
    bool_t reset;


    if (invLabel != UntypedRetype) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 52, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped cap: Illegal operation attempted."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_IllegalOperation;
        return EXCEPTION_SYSCALL_ERROR;
    }


    if (length < 6 || excaps.excaprefs[0] == ((void *)0)) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 59, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped invocation: Truncated message."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_TruncatedMessage;
        return EXCEPTION_SYSCALL_ERROR;
    }


    newType = getSyscallArg(0, buffer);
    userObjSize = getSyscallArg(1, buffer);
    nodeIndex = getSyscallArg(2, buffer);
    nodeDepth = getSyscallArg(3, buffer);
    nodeOffset = getSyscallArg(4, buffer);
    nodeWindow = getSyscallArg(5, buffer);

    rootSlot = excaps.excaprefs[0];


    if (newType >= seL4_ObjectTypeCount) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 76, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped Retype: Invalid object type."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 0;
        return EXCEPTION_SYSCALL_ERROR;
    }

    objectSize = getObjectSize(newType, userObjSize);




    if (userObjSize >= (1 << 6) || objectSize > 47) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 88, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped Retype: Invalid object size."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = 47;
        return EXCEPTION_SYSCALL_ERROR;
    }


    if (newType == seL4_CapTableObject && userObjSize == 0) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 97, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped Retype: Requested CapTable size too small."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }


    if (newType == seL4_UntypedObject && userObjSize < 4) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 105, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped Retype: Requested UntypedItem size too small."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }


    if (nodeDepth == 0) {
        nodeCap = excaps.excaprefs[0]->cap;
    } else {
        cap_t rootCap = excaps.excaprefs[0]->cap;
        lu_ret = lookupTargetSlot(rootCap, nodeIndex, nodeDepth);
        if (lu_ret.status != EXCEPTION_NONE) {
            do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 118, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped Retype: Invalid destination address."); kprintf(">>" "" "\n"); } while (0);
            return lu_ret.status;
        }
        nodeCap = lu_ret.slot->cap;
    }


    if (cap_get_capType(nodeCap) != cap_cnode_cap) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 126, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped Retype: Destination cap invalid or read-only."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_FailedLookup;
        current_syscall_error.failedLookupWasSource = 0;
        current_lookup_fault = lookup_fault_missing_capability_new(nodeDepth);
        return EXCEPTION_SYSCALL_ERROR;
    }


    nodeSize = 1ul << cap_cnode_cap_get_capCNodeRadix(nodeCap);
    if (nodeOffset > nodeSize - 1) {
                                  ;
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = nodeSize - 1;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (nodeWindow < 1 || nodeWindow > 256) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 145, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped Retype: Number of requested objects (%d) too small or large.", (int)nodeWindow); kprintf(">>" "" "\n"); } while (0)
                                  ;
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 1;
        current_syscall_error.rangeErrorMax = 256;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (nodeWindow > nodeSize - nodeOffset) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 152, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped Retype: Requested destination window overruns size of node."); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 1;
        current_syscall_error.rangeErrorMax = nodeSize - nodeOffset;
        return EXCEPTION_SYSCALL_ERROR;
    }


    slots.cnode = ((cte_t *)(cap_cnode_cap_get_capCNodePtr(nodeCap)));
    slots.offset = nodeOffset;
    slots.length = nodeWindow;
    for (i = nodeOffset; i < nodeOffset + nodeWindow; i++) {
        status = ensureEmptySlot(slots.cnode + i);
        if (status != EXCEPTION_NONE) {
                             ;
            return status;
        }
    }
    status = ensureNoChildren(slot);
    if (status != EXCEPTION_NONE) {
        freeIndex = cap_untyped_cap_get_capFreeIndex(cap);
        reset = false;
    } else {
        freeIndex = 0;
        reset = true;
    }
    freeRef = ((word_t)(((word_t)(cap_untyped_cap_get_capPtr(cap))) + ((freeIndex)<<4)));
    untypedFreeBytes = (1ul << (cap_untyped_cap_get_capBlockSize(cap))) -
                       ((freeIndex)<<4);

    if ((untypedFreeBytes >> objectSize) < nodeWindow) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 209, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped Retype: Insufficient memory " "(%lu * %lu bytes needed, %lu bytes available).", (word_t)nodeWindow, (objectSize >= (1 << 6) ? -1 : (1ul << objectSize)), (word_t)(untypedFreeBytes)); kprintf(">>" "" "\n"); } while (0)



                                             ;
        current_syscall_error.type = seL4_NotEnoughMemory;
        current_syscall_error.memoryLeft = untypedFreeBytes;
        return EXCEPTION_SYSCALL_ERROR;
    }

    deviceMemory = cap_untyped_cap_get_capIsDevice(cap);
    if ((deviceMemory && !Arch_isFrameType(newType))
            && newType != seL4_UntypedObject) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 218, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Untyped Retype: Creating kernel objects with device untyped"); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_InvalidArgument;
        current_syscall_error.invalidArgumentNumber = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }



    alignedFreeRef = alignUp(freeRef, objectSize);


    setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
    return invokeUntyped_Retype(slot, reset,
                                (void*)alignedFreeRef, newType, userObjSize,
                                slots, deviceMemory);
}

static exception_t
resetUntypedCap(cte_t *srcSlot)
{
    cap_t prev_cap = srcSlot->cap;
    word_t block_size = cap_untyped_cap_get_capBlockSize(prev_cap);
    void *regionBase = ((word_t *)(cap_untyped_cap_get_capPtr(prev_cap)));
    int chunk = 8;
    word_t offset = ((cap_untyped_cap_get_capFreeIndex(prev_cap))<<4);
    exception_t status;
    bool_t deviceMemory = cap_untyped_cap_get_capIsDevice(prev_cap);

    if (offset == 0) {
        return EXCEPTION_NONE;
    }






    if (deviceMemory || block_size < chunk) {
        if (! deviceMemory) {
            clearMemory(regionBase, block_size);
        }
        srcSlot->cap = cap_untyped_cap_set_capFreeIndex(prev_cap, 0);
    } else {
        for (offset = (((offset - 1) >> (chunk)) << (chunk));
                offset != - (1ul << (chunk)); offset -= (1ul << (chunk))) {
            clearMemory(((void *)(((word_t)(regionBase)) + (offset))), chunk);
            srcSlot->cap = cap_untyped_cap_set_capFreeIndex(prev_cap, ((offset)>>4));
            status = preemptionPoint();
            if (status != EXCEPTION_NONE) {
                return status;
            }
        }
    }
    return EXCEPTION_NONE;
}

exception_t
invokeUntyped_Retype(cte_t *srcSlot,
                     bool_t reset, void* retypeBase,
                     object_t newType, word_t userSize,
                     slot_range_t destSlots, bool_t deviceMemory)
{
    word_t freeRef;
    word_t totalObjectSize;
    void *regionBase = ((word_t *)(cap_untyped_cap_get_capPtr(srcSlot->cap)));
    exception_t status;

    freeRef = ((word_t)(((word_t)(regionBase)) + ((cap_untyped_cap_get_capFreeIndex(srcSlot->cap))<<4)));

    if (reset) {
        status = resetUntypedCap(srcSlot);
        if (status != EXCEPTION_NONE) {
            return status;
        }
    }


    totalObjectSize = destSlots.length << getObjectSize(newType, userSize);
    freeRef = (word_t)retypeBase + totalObjectSize;
    srcSlot->cap = cap_untyped_cap_set_capFreeIndex(srcSlot->cap,
                                                    (((word_t)(freeRef) - (word_t)(regionBase))>>4));


    createNewObjects(newType, srcSlot, destSlots, retypeBase, userSize,
                     deviceMemory);

    return EXCEPTION_NONE;
}

enum acpi_type {
    ACPI_RSDP,
    ACPI_RSDT
};


typedef struct acpi_dmar {
    acpi_header_t header;
    uint8_t host_addr_width;
    uint8_t flags;
    uint8_t reserved[10];
} acpi_dmar_t;
typedef int __assert_failed_acpi_dmar_packed[(sizeof(acpi_dmar_t) == sizeof(acpi_header_t) + 12) ? 1 : -1];



typedef struct acpi_dmar_header {
    uint16_t type;
    uint16_t length;
} acpi_dmar_header_t;
typedef int __assert_failed_acpi_dmar_header_packed[(sizeof(acpi_dmar_header_t) == 4) ? 1 : -1];


enum acpi_table_dmar_struct_type {
    DMAR_DRHD = 0,
    DMAR_RMRR = 1,
    DMAR_ATSR = 2,
};


typedef struct acpi_dmar_drhd {
    acpi_dmar_header_t header;
    uint8_t flags;
    uint8_t reserved;
    uint16_t segment;
    uint32_t reg_base[2];
} acpi_dmar_drhd_t;
typedef int __assert_failed_acpi_dmar_drhd_packed[(sizeof(acpi_dmar_drhd_t) == sizeof(acpi_dmar_header_t) + 12) ? 1 : -1];



typedef struct acpi_dmar_devscope {
    uint8_t type;
    uint8_t length;
    uint16_t reserved;
    uint8_t enum_id;
    uint8_t start_bus;
    struct {
        uint8_t dev;
        uint8_t fun;
    } path_0;
} acpi_dmar_devscope_t;
typedef int __assert_failed_acpi_dmar_devscope_packed[(sizeof(acpi_dmar_devscope_t) == 8) ? 1 : -1];


typedef struct acpi_dmar_rmrr {
    acpi_dmar_header_t header;
    uint16_t reserved;
    uint16_t segment;
    uint32_t reg_base[2];
    uint32_t reg_limit[2];
    acpi_dmar_devscope_t devscope_0;
} acpi_dmar_rmrr_t;
typedef int __assert_failed_acpi_dmar_rmrr_packed[(sizeof(acpi_dmar_rmrr_t) == sizeof(acpi_dmar_header_t) + 20 + sizeof(acpi_dmar_devscope_t)) ? 1 : -1];



typedef struct acpi_fadt {
    acpi_header_t header;
    uint8_t reserved[76];
    uint32_t flags;
} acpi_fadt_t;
typedef int __assert_failed_acpi_fadt_packed[(sizeof(acpi_fadt_t) == sizeof(acpi_header_t) + 80) ? 1 : -1];



typedef struct acpi_madt {
    acpi_header_t header;
    uint32_t apic_addr;
    uint32_t flags;
} acpi_madt_t;
typedef int __assert_failed_acpi_madt_packed[(sizeof(acpi_madt_t) == sizeof(acpi_header_t) + 8) ? 1 : -1];


typedef struct acpi_madt_header {
    uint8_t type;
    uint8_t length;
} acpi_madt_header_t;
typedef int __assert_failed_acpi_madt_header_packed[(sizeof(acpi_madt_header_t) == 2) ? 1 : -1];

enum acpi_table_madt_struct_type {
    MADT_APIC = 0,
    MADT_IOAPIC = 1,
    MADT_ISO = 2,
    MADT_x2APIC = 9
};

typedef struct acpi_madt_apic {
    acpi_madt_header_t header;
    uint8_t cpu_id;
    uint8_t apic_id;
    uint32_t flags;
} acpi_madt_apic_t;
typedef int __assert_failed_acpi_madt_apic_packed[(sizeof(acpi_madt_apic_t) == sizeof(acpi_madt_header_t) + 6) ? 1 : -1];


typedef struct acpi_madt_x2apic {
    acpi_madt_header_t header;
    uint16_t reserved;
    uint32_t x2apic_id;
    uint32_t flags;
    uint32_t acpi_processor_uid;
} acpi_madt_x2apic_t;
typedef int __assert_failed_acpi_madt_x2apic_packed[(sizeof(acpi_madt_x2apic_t) == sizeof(acpi_madt_header_t) + 14) ? 1 : -1];


typedef struct acpi_madt_ioapic {
    acpi_madt_header_t header;
    uint8_t ioapic_id;
    uint8_t reserved[1];
    uint32_t ioapic_addr;
    uint32_t gsib;
} acpi_madt_ioapic_t;
typedef int __assert_failed_acpi_madt_ioapic_packed[(sizeof(acpi_madt_ioapic_t) == sizeof(acpi_madt_header_t) + 10) ? 1 : -1];


typedef struct acpi_madt_iso {
    acpi_madt_header_t header;
    uint8_t bus;
    uint8_t source;
    uint32_t gsi;
    uint16_t flags;
} acpi_madt_iso_t;







const char acpi_str_rsd[] = {'R', 'S', 'D', ' ', 'P', 'T', 'R', ' ', 0};
const char acpi_str_fadt[] = {'F', 'A', 'C', 'P', 0};
const char acpi_str_apic[] = {'A', 'P', 'I', 'C', 0};
const char acpi_str_dmar[] = {'D', 'M', 'A', 'R', 0};

__attribute__((__section__(".boot.text"))) static uint8_t
acpi_calc_checksum(char* start, uint32_t length)
{
    uint8_t checksum = 0;

    while (length > 0) {
        checksum += *start;
        start++;
        length--;
    }
    return checksum;
}

__attribute__((__section__(".boot.text"))) static acpi_rsdp_t*
acpi_get_rsdp(void)
{
    char* addr;

    for (addr = (char*)0x0e0000; addr < (char*)0x100000; addr += 16) {
        if (strncmp(addr, acpi_str_rsd, 8) == 0) {
            if (acpi_calc_checksum(addr, ACPI_V1_SIZE) == 0) {
                return (acpi_rsdp_t*)addr;
            }
        }
    }
    return ((void *)0);
}

__attribute__((__section__(".boot.text"))) static void*
acpi_table_init(void* entry, enum acpi_type table_type)
{
    void* acpi_table;
    unsigned int pages_for_table;
    unsigned int pages_for_header = 1;


    unsigned long offset_in_page = (unsigned long)entry & ((1ul << (21))-1ul);
    if (((1ul << (21))-1ul) - offset_in_page < sizeof(acpi_rsdp_t)) {
        pages_for_header++;
    }


    acpi_table = map_temp_boot_page(entry, pages_for_header);

    switch (table_type) {
    case ACPI_RSDP: {
        acpi_rsdp_t *rsdp_entry = (acpi_rsdp_t*)entry;
        pages_for_table = (rsdp_entry->length + offset_in_page) / ((1ul << (21))-1ul) + 1;
        break;
    }
    case ACPI_RSDT: {
        acpi_rsdt_t *rsdt_entry = (acpi_rsdt_t*)entry;
        pages_for_table = (rsdt_entry->header.length + offset_in_page) / ((1ul << (21))-1ul) + 1;
        break;
    }
    default:
        kprintf("Error: Mapping unknown ACPI table type\n");
        if(!(false)) _assert_fail("false", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/plat/pc99/machine/acpi.c", 222, __FUNCTION__);
        return ((void *)0);
    }


    acpi_table = map_temp_boot_page(entry, pages_for_table);

    return acpi_table;
}

__attribute__((__section__(".boot.text"))) bool_t
acpi_init(acpi_rsdp_t *rsdp_data)
{
    acpi_rsdp_t* acpi_rsdp = acpi_get_rsdp();

    if (acpi_rsdp == ((void *)0)) {
        kprintf("BIOS: No ACPI support detected\n");
        return false;
    }
    kprintf("ACPI: RSDP paddr=%p\n", acpi_rsdp);
    acpi_rsdp = acpi_table_init(acpi_rsdp, ACPI_RSDP);
    kprintf("ACPI: RSDP vaddr=%p\n", acpi_rsdp);


    *rsdp_data = *acpi_rsdp;


    return acpi_validate_rsdp(rsdp_data);
}

__attribute__((__section__(".boot.text"))) bool_t
acpi_validate_rsdp(acpi_rsdp_t *acpi_rsdp)
{
    acpi_rsdt_t* acpi_rsdt;
    acpi_rsdt_t* acpi_rsdt_mapped;

    if (acpi_calc_checksum((char*)acpi_rsdp, ACPI_V1_SIZE) != 0) {
        kprintf("BIOS: ACPIv1 information corrupt\n");
        return false;
    }

    if (acpi_rsdp->revision > 0 && acpi_calc_checksum((char*)acpi_rsdp, sizeof(*acpi_rsdp)) != 0) {
        kprintf("BIOS: ACPIv2 information corrupt\n");
        return false;
    }


    acpi_rsdt = (acpi_rsdt_t*)(word_t)acpi_rsdp->rsdt_address;
    kprintf("ACPI: RSDT paddr=%p\n", acpi_rsdt);
    acpi_rsdt_mapped = (acpi_rsdt_t*)acpi_table_init(acpi_rsdt, ACPI_RSDT);
    kprintf("ACPI: RSDT vaddr=%p\n", acpi_rsdt_mapped);

    if(!(acpi_rsdt_mapped->header.length > 0)) _assert_fail("acpi_rsdt_mapped->header.length > 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/plat/pc99/machine/acpi.c", 274, __FUNCTION__);
    if (acpi_calc_checksum((char*)acpi_rsdt_mapped, acpi_rsdt_mapped->header.length) != 0) {
        kprintf("ACPI: RSDT checksum failure\n");
        return false;
    }

    return true;
}

__attribute__((__section__(".boot.text"))) uint32_t
acpi_madt_scan(
    acpi_rsdp_t* acpi_rsdp,
    cpu_id_t* cpu_list,
    uint32_t* num_ioapic,
    paddr_t* ioapic_paddrs
)
{
    unsigned int entries;
    uint32_t num_cpu;
    uint32_t count;
    acpi_madt_t* acpi_madt;
    acpi_madt_header_t* acpi_madt_header;

    acpi_rsdt_t* acpi_rsdt_mapped;
    acpi_madt_t* acpi_madt_mapped;
    acpi_rsdt_mapped = (acpi_rsdt_t*)acpi_table_init((acpi_rsdt_t*)(word_t)acpi_rsdp->rsdt_address, ACPI_RSDT);

    num_cpu = 0;
    *num_ioapic = 0;

    if(!(acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t))) _assert_fail("acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/plat/pc99/machine/acpi.c", 304, __FUNCTION__);

    entries = (acpi_rsdt_mapped->header.length - sizeof(acpi_header_t)) / sizeof(uint32_t);
    for (count = 0; count < entries; count++) {
        acpi_madt = (acpi_madt_t*)(word_t)acpi_rsdt_mapped->entry[count];
        acpi_madt_mapped = (acpi_madt_t*)acpi_table_init(acpi_madt, ACPI_RSDT);

        if (strncmp(acpi_str_apic, acpi_madt_mapped->header.signature, 4) == 0) {
            kprintf("ACPI: MADT paddr=%p\n", acpi_madt);
            kprintf("ACPI: MADT vaddr=%p\n", acpi_madt_mapped);
            kprintf("ACPI: MADT apic_addr=0x%x\n", acpi_madt_mapped->apic_addr);
            kprintf("ACPI: MADT flags=0x%x\n", acpi_madt_mapped->flags);

            acpi_madt_header = (acpi_madt_header_t*)(acpi_madt_mapped + 1);

            while ((char*)acpi_madt_header < (char*)acpi_madt_mapped + acpi_madt_mapped->header.length) {
                switch (acpi_madt_header->type) {







                case MADT_APIC: {

                    uint8_t cpu_id = ((acpi_madt_apic_t*)acpi_madt_header)->apic_id;
                    uint32_t flags = ((acpi_madt_apic_t*)acpi_madt_header)->flags;
                    if (flags == 1) {
                        kprintf("ACPI: MADT_APIC apic_id=0x%x\n", cpu_id);
                        if (num_cpu == 16) {
                            kprintf("ACPI: Not recording this APIC, only support %d\n", 16);
                        } else {
                            cpu_list[num_cpu] = cpu_id;
                            num_cpu++;
                        }
                    }
                    break;
                }
                case MADT_x2APIC: {
                    uint32_t cpu_id = ((acpi_madt_x2apic_t*)acpi_madt_header)->x2apic_id;
                    uint32_t flags = ((acpi_madt_x2apic_t*)acpi_madt_header)->flags;
                    if (flags == 1) {
                        kprintf("ACPI: MADT_x2APIC apic_id=0x%x\n", cpu_id);
                        if (num_cpu == 16) {
                            kprintf("ACPI: Not recording this APIC, only support %d\n", 16);
                        } else {
                            cpu_list[num_cpu] = cpu_id;
                            num_cpu++;
                        }
                    }
                    break;
                }
                case MADT_IOAPIC:
                    kprintf("ACPI: MADT_IOAPIC ioapic_id=%d ioapic_addr=0x%x gsib=%d\n", ((acpi_madt_ioapic_t*)acpi_madt_header)->ioapic_id, ((acpi_madt_ioapic_t*)acpi_madt_header)->ioapic_addr, ((acpi_madt_ioapic_t*)acpi_madt_header)->gsib)




                     ;
                    if (*num_ioapic == 1) {
                        kprintf("ACPI: Not recording this IOAPIC, only support %d\n", 1);
                    } else {
                        ioapic_paddrs[*num_ioapic] = ((acpi_madt_ioapic_t*)acpi_madt_header)->ioapic_addr;
                        (*num_ioapic)++;
                    }
                    break;
                case MADT_ISO:
                    kprintf("ACPI: MADT_ISO bus=%d source=%d gsi=%d flags=0x%x\n", ((acpi_madt_iso_t*)acpi_madt_header)->bus, ((acpi_madt_iso_t*)acpi_madt_header)->source, ((acpi_madt_iso_t*)acpi_madt_header)->gsi, ((acpi_madt_iso_t*)acpi_madt_header)->flags)



                                                                       ;
                    break;
                default:
                    break;
                }
                acpi_madt_header = (acpi_madt_header_t*)((char*)acpi_madt_header + acpi_madt_header->length);
            }
        }
    }

    kprintf("ACPI: %d CPU(s) detected\n", num_cpu);

    return num_cpu;
}

__attribute__((__section__(".boot.text"))) bool_t
acpi_fadt_scan(
    acpi_rsdp_t* acpi_rsdp
)
{
    unsigned int entries;
    uint32_t count;
    acpi_fadt_t* acpi_fadt;

    acpi_rsdt_t* acpi_rsdt_mapped;
    acpi_fadt_t* acpi_fadt_mapped;
    acpi_rsdt_mapped = (acpi_rsdt_t*)acpi_table_init((acpi_rsdt_t*)(word_t)acpi_rsdp->rsdt_address, ACPI_RSDT);

    if(!(acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t))) _assert_fail("acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/plat/pc99/machine/acpi.c", 404, __FUNCTION__);

    entries = (acpi_rsdt_mapped->header.length - sizeof(acpi_header_t)) / sizeof(uint32_t);
    for (count = 0; count < entries; count++) {
        acpi_fadt = (acpi_fadt_t*)(word_t)acpi_rsdt_mapped->entry[count];
        acpi_fadt_mapped = (acpi_fadt_t*)acpi_table_init(acpi_fadt, ACPI_RSDT);

        if (strncmp(acpi_str_fadt, acpi_fadt_mapped->header.signature, 4) == 0) {
            kprintf("ACPI: FADT paddr=%p\n", acpi_fadt);
            kprintf("ACPI: FADT vaddr=%p\n", acpi_fadt_mapped);
            kprintf("ACPI: FADT flags=0x%x\n", acpi_fadt_mapped->flags);

            if (0 &&
                    acpi_fadt_mapped->flags & (1ul << (19))) {
                kprintf("system requires apic physical mode\n");
                return false;
            }
        }
    }

    return true;
}

__attribute__((__section__(".boot.text"))) void
acpi_dmar_scan(
    acpi_rsdp_t* acpi_rsdp,
    paddr_t* drhu_list,
    uint32_t* num_drhu,
    uint32_t max_drhu_list_len,
    acpi_rmrr_list_t *rmrr_list
)
{
    word_t i;
    unsigned int entries;
    uint32_t count;
    uint32_t reg_basel, reg_baseh;
    int rmrr_count;
    dev_id_t dev_id;

    acpi_dmar_t* acpi_dmar;
    acpi_dmar_header_t* acpi_dmar_header;
    acpi_dmar_rmrr_t* acpi_dmar_rmrr;
    acpi_dmar_devscope_t* acpi_dmar_devscope;

    acpi_rsdt_t* acpi_rsdt_mapped;
    acpi_dmar_t* acpi_dmar_mapped;

    acpi_rsdt_mapped = (acpi_rsdt_t*)acpi_table_init((acpi_rsdt_t*)(word_t)acpi_rsdp->rsdt_address, ACPI_RSDT);

    *num_drhu = 0;
    rmrr_count = 0;

    if(!(acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t))) _assert_fail("acpi_rsdt_mapped->header.length >= sizeof(acpi_header_t)", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/plat/pc99/machine/acpi.c", 456, __FUNCTION__);
    entries = (acpi_rsdt_mapped->header.length - sizeof(acpi_header_t)) / sizeof(uint32_t);
    for (count = 0; count < entries; count++) {
        acpi_dmar = (acpi_dmar_t*)(word_t)acpi_rsdt_mapped->entry[count];
        acpi_dmar_mapped = (acpi_dmar_t*)acpi_table_init(acpi_dmar, ACPI_RSDT);

        if (strncmp(acpi_str_dmar, acpi_dmar_mapped->header.signature, 4) == 0) {
            kprintf("ACPI: DMAR paddr=%p\n", acpi_dmar);
            kprintf("ACPI: DMAR vaddr=%p\n", acpi_dmar_mapped);
            kprintf("ACPI: IOMMU host address width: %d\n", acpi_dmar_mapped->host_addr_width + 1);
            acpi_dmar_header = (acpi_dmar_header_t*)(acpi_dmar_mapped + 1);

            while ((char*)acpi_dmar_header < (char*)acpi_dmar_mapped + acpi_dmar_mapped->header.length) {
                switch (acpi_dmar_header->type) {

                case DMAR_DRHD:
                    if (*num_drhu == max_drhu_list_len) {
                        kprintf("ACPI: too many IOMMUs, disabling IOMMU support\n");

                        *num_drhu = 0;
                        return;
                    }
                    reg_basel = ((acpi_dmar_drhd_t*)acpi_dmar_header)->reg_base[0];
                    reg_baseh = ((acpi_dmar_drhd_t*)acpi_dmar_header)->reg_base[1];

                    if (reg_baseh != 0) {
                        kprintf("ACPI: DMAR_DRHD reg_base exceeds 32 bit, disabling IOMMU support\n");

                        *num_drhu = 0;
                        return;
                    }
                    drhu_list[*num_drhu] = (paddr_t)reg_basel;
                    (*num_drhu)++;
                    break;

                case DMAR_RMRR:

                    acpi_dmar_rmrr = (acpi_dmar_rmrr_t*)acpi_dmar_header;
                    if (acpi_dmar_rmrr->reg_base[1] != 0 ||
                            acpi_dmar_rmrr->reg_limit[1] != 0) {
                        kprintf("ACPI: RMRR device above 4GiB, disabling IOMMU support\n");
                        *num_drhu = 0;
                        return ;
                    }

                    for (i = 0; i <= (acpi_dmar_header->length - sizeof(acpi_dmar_rmrr_t)) / sizeof(acpi_dmar_devscope_t); i++) {
                        acpi_dmar_devscope = &acpi_dmar_rmrr->devscope_0 + i;

                        if (acpi_dmar_devscope->type != 1) {

                            kprintf("ACPI: RMRR device scope: non-PCI-Endpoint-Devices not supported yet, disabling IOMMU support\n");
                            *num_drhu = 0;
                            return;
                        }

                        if (acpi_dmar_devscope->length > sizeof(acpi_dmar_devscope_t)) {

                            kprintf("ACPI: RMRR device scope: devices behind bridges not supported yet, disabling IOMMU support\n");
                            *num_drhu = 0;
                            return;
                        }

                        dev_id =
                            (((acpi_dmar_devscope->start_bus) << 8u) | ((acpi_dmar_devscope->path_0.dev) << 3u) | (acpi_dmar_devscope->path_0.fun))



                             ;

                        if (rmrr_count == 32) {
                            kprintf("ACPI: Too many RMRR entries, disabling IOMMU support\n");
                            *num_drhu = 0;
                            return;
                        }
                        kprintf("\tACPI: registering RMRR entry for region for device: bus=0x%x dev=0x%x fun=0x%x\n", acpi_dmar_devscope->start_bus, acpi_dmar_devscope->path_0.dev, acpi_dmar_devscope->path_0.fun)



                               ;

                        rmrr_list->entries[rmrr_count].device = dev_id;
                        rmrr_list->entries[rmrr_count].base = acpi_dmar_rmrr->reg_base[0];
                        rmrr_list->entries[rmrr_count].limit = acpi_dmar_rmrr->reg_limit[0];
                        rmrr_count++;
                    }
                    break;

                case DMAR_ATSR:

                    break;

                default:
                    kprintf("ACPI: Unknown DMA remapping structure type: %x\n", acpi_dmar_header->type);
                }
                acpi_dmar_header = (acpi_dmar_header_t*)((char*)acpi_dmar_header + acpi_dmar_header->length);
            }
        }
    }
    rmrr_list->num = rmrr_count;
    kprintf("ACPI: %d IOMMUs detected\n", *num_drhu);
}


__attribute__((__section__(".boot.text"))) bool_t platAddDevices(void)
{



    if ((1ul << (47)) > 0xFFFFFFF8) {
        if (!add_allocated_p_region( (p_region_t) {
        (word_t)0xFFFFFFF8, (word_t)0xFFFFFFF8 + 8
        })) {
            return false;
        }
    }
    return true;
}





__attribute__((__section__(".boot.text"))) static inline uint32_t
measure_tsc_khz(void)
{
    for (int i = 0; i < 10; i++) {


        uint64_t old_ticks = x86_rdtsc();


        pit_wait_wraparound();

        uint64_t new_ticks = x86_rdtsc();

        uint64_t diff = new_ticks - old_ticks;

        if ((uint32_t)diff == diff && new_ticks > old_ticks) {
            return (uint32_t)diff / 50;
        }

        kprintf("warning: TSC frequency too high (%d retries remaining)\n", 10 - i - 1)
                                        ;
    }

    _fail("TSC frequency too high", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/plat/pc99/machine/hardware.c", 75, __func__);


    return 0;
}

__attribute__((__section__(".boot.text"))) uint32_t
tsc_init(void)
{

    x86_cpu_identity_t *model_info = x86_cpuid_get_model_info();
    uint32_t valid_models[] = {
        0x1E , 0x1A , 0x2E ,
        0x2A , 0x2D ,
        0x3C, 0x3F, 0x45, 0x46,
        0x9A, 0x3E, 0x3A,

        0x56, 0x4F, 0x47, 0x3D,
        0x4E, 0x5E
    };


    if (model_info->family == (0x06)) {
        for (int i = 0; i < (sizeof(valid_models) / sizeof(valid_models[0])); i++) {
            if (model_info->model == valid_models[i]) {





                rdmsr_safe_result_t info = x86_rdmsr_safe(0xCE);
                if (info.success) {
                    uint32_t ratio = (((uint32_t) info.value) & 0xFF00) >> 8u;

                    if (ratio != 0) {

                        if (model_info->model == 0x1E ||
                                model_info->model == 0x1A ||
                                model_info->model == 0x2E ) {
                            return ratio * 13333u / 100u;
                        } else {
                            return ratio * 100u;
                        }
                    }
                }

                break;
            }
        }
    }


    pit_init();


    pit_wait_wraparound();


    uint32_t tsc_khz = measure_tsc_khz();


    return tsc_khz / 1000u;
}


void
serial_init(uint16_t port)
{
    while (!(in8(port + 5) & 0x60));

    out8(port + 1, 0x00);
    out8(port + 3, 0x80);
    out8(port, 0x01);
    out8(port + 1, 0x00);
    out8(port + 3, 0x03);
    out8(port + 4, 0x0b);

    in8(port);
    in8(port + 5);
    in8(port + 6);
}



void
putConsoleChar(unsigned char a)
{
    while (x86KSconsolePort && !(in8(x86KSconsolePort + 5) & 0x20));
    out8(x86KSconsolePort, a);
}



void
putDebugChar(unsigned char a)
{
    while (x86KSdebugPort && (in8(x86KSdebugPort + 5) & 0x20) == 0);
    out8(x86KSdebugPort, a);
}

unsigned char
getDebugChar(void)
{
    while ((in8(x86KSdebugPort + 5) & 1) == 0);
    return in8(x86KSdebugPort);
}



static uint32_t ioredtbl_state[24 * 1];


static uint32_t num_ioapics = 0;

static void ioapic_write(uint32_t ioapic, word_t reg, uint32_t value)
{
    *(volatile uint32_t*)((word_t)((0xffffffffc0000000ul + (1ul << (12))) + ioapic * (1ul << (12))) + reg) = value;
}

static uint32_t ioapic_read(uint32_t ioapic, word_t reg)
{
    return *(volatile uint32_t*)((word_t)((0xffffffffc0000000ul + (1ul << (12))) + ioapic * (1ul << (12))) + reg);
}

static void single_ioapic_init(word_t ioapic, cpu_id_t delivery_cpu)
{
    uint32_t i;





    for (i = 0; i < 24; i++) {

        ioapic_write(ioapic, 0x00, ((0x10 + (i) * 2) + 1));
        ioapic_write(ioapic, 0x10, (ioapic_read(ioapic, 0x10) & ((1ul << (24))-1ul)) | (delivery_cpu << 24));

        ioredtbl_state[i] = (1ul << (16));
        ioapic_write(ioapic, 0x00, (0x10 + (i) * 2));

        ioredtbl_state[i] |= ioapic_read(ioapic, 0x10) & ~((1ul << (16))-1ul);
        ioapic_write(ioapic, 0x10, ioredtbl_state[i]);
    }
}

static cpu_id_t ioapic_target_cpu = 0;
void ioapic_init(uint32_t num_nodes, cpu_id_t *cpu_list, uint32_t num_ioapic)
{
    uint32_t ioapic;
    num_ioapics = num_ioapic;
    ioapic_target_cpu = cpu_list[0];

    for (ioapic = 0; ioapic < num_ioapic; ioapic++) {

        single_ioapic_init(ioapic, cpu_list[0]);
    }
}

void ioapic_mask(bool_t mask, uint32_t ioapic, uint32_t pin)
{
    int index = ioapic * 24 + pin;
    if (ioapic >= num_ioapics || pin >= 24) {

        return;
    }
    if (mask) {

        if (!(ioredtbl_state[index] & (1ul << (15))))
            return;
        ioredtbl_state[index] |= (1ul << (16));
    } else {
        ioredtbl_state[index] &= ~(1ul << (16));


        if(!((ioredtbl_state[index] & 0xff) != 0)) _assert_fail("(ioredtbl_state[index] & 0xff) != 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/plat/pc99/machine/ioapic.c", 106, __FUNCTION__);
    }
    ioapic_write(ioapic, 0x00, (0x10 + (pin) * 2));
    ioapic_write(ioapic, 0x10, ioredtbl_state[index]);
}

exception_t ioapic_decode_map_pin_to_vector(word_t ioapic, word_t pin, word_t level,
                                            word_t polarity, word_t vector)
{
    if (ioapic >= num_ioapics) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 116, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Invalid IOAPIC %ld, only have %ld", (long)ioapic, (long)num_ioapics); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = num_ioapics - 1;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (pin >= 24) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 123, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Invalid IOAPIC pin %ld, there are %d pins", (long)pin, 24); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = 24 - 1;
        return EXCEPTION_SYSCALL_ERROR;
    }

    if (level != 0 && level != 1) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 131, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Level should be 0 or 1, not %d", (int)level); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }
    if (polarity != 0 && polarity != 1) {
        do { kprintf("" "" "<<" "" "" "seL4(CPU %lu)" "" "" " [%s/%d T%p \"%s\" @%lx]: ", getCurrentCPUIndex(), __func__, 138, ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbName, (word_t)getRestartPC(ksSMP[(getCurrentCPUIndex())].system.ksCurThread)); kprintf("Polarity should be 0 or 1, not %d", (int)polarity); kprintf(">>" "" "\n"); } while (0);
        current_syscall_error.type = seL4_RangeError;
        current_syscall_error.rangeErrorMin = 0;
        current_syscall_error.rangeErrorMax = 1;
        return EXCEPTION_SYSCALL_ERROR;
    }
    return EXCEPTION_NONE;
}

void ioapic_map_pin_to_vector(word_t ioapic, word_t pin, word_t level,
                              word_t polarity, word_t vector)
{
    uint32_t ioredtbl_high = 0;
    uint32_t index = 0;

    index = ioapic * 24 + pin;
    ioapic_write(ioapic, 0x00, ((0x10 + (pin) * 2) + 1));
    ioredtbl_high = ioapic_read(ioapic, 0x10) & ((1ul << (24))-1ul);

    ioredtbl_high |= (ioapic_target_cpu << 24);
    ioapic_write(ioapic, 0x10, ioredtbl_high);

    ioredtbl_state[index] = (1ul << (16)) |
                            (level << 15) |
                            (polarity << 13) |
                            vector;

    ioapic_write(ioapic, 0x00, (0x10 + (pin) * 2));

    ioredtbl_state[index] |= ioapic_read(ioapic, 0x10) & ~((1ul << (16))-1ul);
    ioapic_write(ioapic, 0x10, ioredtbl_state[index]);
}






__attribute__((__section__(".boot.text"))) void
pic_remap_irqs(interrupt_t interrupt)
{
    out8(0x20, 0x11);
    out8(0xa0, 0x11);
    out8(0x20 + 1, interrupt);
    out8(0xa0 + 1, interrupt + 8);
    out8(0x20 + 1, 0x04);
    out8(0xa0 + 1, 0x02);
    out8(0x20 + 1, 0x01);
    out8(0xa0 + 1, 0x01);
    out8(0x20 + 1, 0x0);
    out8(0xa0 + 1, 0x0);
}

__attribute__((__section__(".boot.text"))) void pic_disable(void)
{


    out8(0x20 + 1, 0xff);
    out8(0xa0 + 1, 0xff);
}

void pic_mask_irq(bool_t mask, irq_t irq)
{
    uint8_t bit_mask;
    uint16_t pic_port;

    if(!(irq >= irq_isa_min)) _assert_fail("irq >= irq_isa_min", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/plat/pc99/machine/pic.c", 49, __FUNCTION__);
    if(!(irq <= irq_isa_max)) _assert_fail("irq <= irq_isa_max", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/plat/pc99/machine/pic.c", 50, __FUNCTION__);

    if (irq < 8) {
        bit_mask = (1ul << (irq));
        pic_port = 0x20 + 1;
    } else {
        bit_mask = (1ul << (irq - 8));
        pic_port = 0xa0 + 1;
    }

    if (mask) {

        out8(pic_port, (in8(pic_port) | bit_mask));
    } else {

        out8(pic_port, (in8(pic_port) & ~bit_mask));
    }
}

bool_t pic_is_irq_pending(void)
{

    uint8_t irr;


    out8(0x20, 0x0a);


    irr = in8(0x20);




    return irr != 0;
}

static uint16_t pic_get_isr(void)
{
    out8(0x20, 0x0b);
    out8(0xa0, 0x0b);
    return (((uint16_t)in8(0xa0)) << 8) | in8(0x20);
}

void pic_ack_active_irq(void)
{
    irq_t irq = getActiveIRQ();
    if (irq >= irq_isa_min + 8) {




        if (irq != irq_isa_min + 15 || (pic_get_isr() & (1ul << (15)))) {
            out8(0xa0, 0x20);
        }
    }


    if (irq != irq_isa_min + 7 || (pic_get_isr() & (1ul << (7)))) {
        out8(0x20, 0x20);
    }
}
__attribute__((__section__(".boot.text"))) void
pit_init(void)
{
    uint16_t divisor = (1193182 * 50) / 1000;

    out8(0x43, 0x34);
    out8(0x40, divisor & 0xff);
    out8(0x40, divisor >> 8);
}

__attribute__((__section__(".boot.text"))) void
pit_wait_wraparound(void)
{
    uint16_t count;
    uint16_t count_old;

    out8(0x43, 0x00);
    count = in8(0x40);
    count |= (in8(0x40) << 8);
    count_old = count;

    while (count <= count_old) {
        count_old = count;
        out8(0x43, 0x00);
        count = in8(0x40);
        count |= (in8(0x40) << 8);
    }
}
void ipiStallCoreCallback(bool_t irqPath)
{
    if (clh_is_self_in_queue() && !irqPath) {






        if (thread_state_ptr_get_tsType(&ksSMP[(getCurrentCPUIndex())].system.ksCurThread->tcbState) == ThreadState_Running) {
            setThreadState(ksSMP[(getCurrentCPUIndex())].system.ksCurThread, ThreadState_Restart);
        }

        tcbSchedEnqueue(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
        switchToIdleThread();
        ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction = ((tcb_t*)0);


        big_kernel_lock.node_owners[getCurrentCPUIndex()].ipi = 0;
        ipi_wait(totalCoreBarrier);


        while (big_kernel_lock.node_owners[getCurrentCPUIndex()].next->value != CLHState_Granted) {
            if (clh_is_ipi_pending(getCurrentCPUIndex())) {


                if(!((IpiRemoteCall_t)remoteCall != IpiRemoteCall_Stall)) _assert_fail("(IpiRemoteCall_t)remoteCall != IpiRemoteCall_Stall", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/smp/ipi.c", 52, __FUNCTION__);
                handleIPI(irq_remote_call_ipi, irqPath);
            }
            arch_pause();
        }


        __asm__ volatile("" ::: "memory");


        activateThread();
        restore_user_context();
    } else {




        tcbSchedEnqueue(ksSMP[(getCurrentCPUIndex())].system.ksCurThread);
        switchToIdleThread();

        ksSMP[(getCurrentCPUIndex())].system.ksSchedulerAction = ((tcb_t*)0);
    }
}

void handleIPI(irq_t irq, bool_t irqPath)
{
    if (irq == irq_remote_call_ipi) {
        handleRemoteCall(remoteCall, get_ipi_arg(0), get_ipi_arg(1), get_ipi_arg(2), irqPath);
    } else if (irq == irq_reschedule_ipi) {
        rescheduleRequired();
    } else {
        _fail("Invalid IPI", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/smp/ipi.c", 83, __func__);
    }
}

void doRemoteMaskOp(IpiRemoteCall_t func, word_t data1, word_t data2, word_t data3, word_t mask)
{

    mask &= ~(1ul << (getCurrentCPUIndex()));



    if (mask != 0) {
        init_ipi_args(func, data1, data2, data3, mask);


        __asm__ volatile("" ::: "memory");
        ipi_send_mask(irq_remote_call_ipi, mask, true);
        ipi_wait(totalCoreBarrier);
    }
}

void doMaskReschedule(word_t mask)
{

    mask &= ~(1ul << (getCurrentCPUIndex()));
    if (mask != 0) {
        ipi_send_mask(irq_reschedule_ipi, mask, false);
    }
}

void generic_ipi_send_mask(irq_t ipi, word_t mask, bool_t isBlocking)
{
    word_t nr_target_cores = 0;
    uint16_t target_cores[16];

    while (mask) {
        int index = (1 << 6) - 1 - clzl(mask);
        if (isBlocking) {
            big_kernel_lock.node_owners[index].ipi = 1;
            target_cores[nr_target_cores] = index;
            nr_target_cores++;
        } else {
            apic_send_ipi_core(ipi, cpuIndexToID(index));
        }
        mask &= ~(1ul << (index));
    }

    if (nr_target_cores > 0) {

        __asm__ volatile("" ::: "memory");
        for (int i = 0; i < nr_target_cores; i++) {
            apic_send_ipi_core(ipi, cpuIndexToID(target_cores[i]));
        }
    }
}



clh_lock_t big_kernel_lock __attribute__((__aligned__(64)));

__attribute__((__section__(".boot.text"))) void
clh_lock_init(void)
{
    for (int i = 0; i < 16; i++) {
        big_kernel_lock.node_owners[i].node = &big_kernel_lock.nodes[i];
    }


    big_kernel_lock.nodes[16].value = CLHState_Granted;
    big_kernel_lock.head = &big_kernel_lock.nodes[16];
}

word_t strnlen(const char *s, word_t maxlen)
{
    word_t len;
    for (len = 0; len < maxlen && s[len]; len++);
    return len;
}

word_t strlcpy(char *dest, const char *src, word_t size)
{
    word_t len;
    for (len = 0; len + 1 < size && src[len]; len++) {
        dest[len] = src[len];
    }
    dest[len] = '\0';
    return len;
}

word_t strlcat(char *dest, const char *src, word_t size)
{
    word_t len;

    for (len = 0; len < size && dest[len]; len++);


    if (len < size) {
        for (; len + 1 < size && *src; len++, src++) {
            dest[len] = *src;
        }
        dest[len] = '\0';
    }
    return len;
}





typedef unsigned long __attribute__((__may_alias__)) ulong_alias;






void
memzero(void *s, unsigned long n)
{
    uint8_t *p = s;


    if(!((unsigned long)s % sizeof(unsigned long) == 0)) _assert_fail("(unsigned long)s % sizeof(unsigned long) == 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/util.c", 32, __FUNCTION__);
    if(!(n % sizeof(unsigned long) == 0)) _assert_fail("n % sizeof(unsigned long) == 0", "/home/tor/gen/20.05-tor/contrib/sel4-7935487f91a31c0cd8aaf09278f6312af56bb935/src/kernel/sel4/src/util.c", 33, __FUNCTION__);







    while (n != 0) {
        *(ulong_alias *)p = 0;
        p += sizeof(ulong_alias);
        n -= sizeof(ulong_alias);
    }
}

void* __attribute__((externally_visible))
memset(void *s, unsigned long c, unsigned long n)
{
    uint8_t *p;





    if (__builtin_expect(!!(c == 0 && ((unsigned long)s % sizeof(unsigned long)) == 0 && (n % sizeof(unsigned long)) == 0), 1)) {
        memzero(s, n);
    } else {

        for (p = (uint8_t *)s; n > 0; n--, p++) {
            *p = (uint8_t)c;
        }
    }

    return s;
}

void* __attribute__((externally_visible))
memcpy(void* ptr_dst, const void* ptr_src, unsigned long n)
{
    uint8_t *p;
    const uint8_t *q;

    for (p = (uint8_t *)ptr_dst, q = (const uint8_t *)ptr_src; n; n--, p++, q++) {
        *p = *q;
    }

    return ptr_dst;
}

int __attribute__((__pure__))
strncmp(const char* s1, const char* s2, int n)
{
    word_t i;
    int diff;

    for (i = 0; i < n; i++) {
        diff = ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i];
        if (diff != 0 || s1[i] == '\0') {
            return diff;
        }
    }

    return 0;
}

long __attribute__((__const__))
char_to_long(char c)
{
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return -1;
}

long __attribute__((__pure__))
str_to_long(const char* str)
{
    unsigned int base;
    long res;
    long val = 0;
    char c;


    if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X')) {
        base = 16;
        str += 2;
    } else {
        base = 10;
    }

    if (!*str) {
        return -1;
    }

    c = *str;
    while (c != '\0') {
        res = char_to_long(c);
        if (res == -1 || res >= base) {
            return -1;
        }
        val = val * base + res;
        str++;
        c = *str;
    }

    return val;
}


const dschedule_t ksDomSchedule[] = {
    { .domain = 0, .length = 1 },
};

const word_t ksDomScheduleLength = sizeof(ksDomSchedule) / sizeof(dschedule_t);
