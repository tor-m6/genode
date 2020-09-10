TARGET = test-go
SRC_GO = main.go
# important! file mycontext.cc shdould be complied with -fno-omit-frame-pointer with my .s file
SRC_CC = dummy.cc mycontext.cc
SRC_S  = myacontext.s
LIBS   = base stdcxx libc libm libgo

CC_OLEVEL = -O0 -fno-omit-frame-pointer

OS_DIR := $(BASE_DIR)-$(KERNEL)/src
CC_CXX_OPT += -I$(OS_DIR)/include
CC_CXX_OPT += -I$(BASE_DIR)/src/include
CC_CXX_OPT += -I$(BASE_DIR)/src/core/include

# add place where compiled packages appears
GCCGO_CMD_LINE = genode-x86-gccgo -B$(BUILD_BASE_DIR)/noux-pkg/libgo

TOOL_PATH:=$(dir $(GOC))

LD_CMD = genode-x86-gcc -B ${TOOL_PATH}/x86/gcc/gcc/

# order is important; problem in correct initializers order for different so libs for Env
LD_LIBGCC = \
${LIB_CACHE_DIR}/base-$(KERNEL)-common/base-$(KERNEL)-common.lib.a \
${LIB_CACHE_DIR}/startup-$(KERNEL)/startup-$(KERNEL).lib.a \
${LIB_CACHE_DIR}/cxx/cxx.lib.a \
${LIB_CACHE_DIR}/libc-stdlib/libc-stdlib.lib.a \
${LIB_CACHE_DIR}/libc-gen/libc-gen.lib.a  \
${LIB_CACHE_DIR}/libgo/libgobegin.a \
${LIB_CACHE_DIR}/libgo/libgolibbegin.a \
${LIB_CACHE_DIR}/libgo/libgo.a \
${TOOL_PATH}/../lib/gcc/x86_64-pc-elf/8.3.0/64/libgcc_eh.a \
${TOOL_PATH}/../lib/gcc/x86_64-pc-elf/8.3.0/64/libgcc.a


CUSTOM_GO = $(GCCGO_CMD_LINE)

CC_CXX_WARN_STRICT =
