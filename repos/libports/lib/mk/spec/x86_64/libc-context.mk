LIBC_SYS_AMD64_DIR = $(LIBC_DIR)/lib/libc/amd64/sys

SRC_S  = getcontext.S setcontext.S swapcontext.S

include $(REP_DIR)/lib/mk/libc-common.inc

vpath %.S $(LIBC_SYS_AMD64_DIR)

CC_CXX_WARN_STRICT =
