typedef unsigned long word_t;
int stack_amount;
static inline void x86_flush_rsb(void)
{
    /* perform 32 near calls with a non zero displacement to flush the rsb with
     * speculation traps. */
    word_t iter = 32;
    __asm__ volatile(
        "1:\n"
        "sub $2, %[iter]\n"
        "call 2f\n"
        "pause\n"
        "jmp 1b\n"
        "2:\n"
        "call 3f\n"
        "pause\n"
        "jmp 2b\n"
        "3:\n"
        "cmp $0, %[iter]\n"
        "jne 1b\n"

        "add %[stack_amount], %%rsp\n"



        : [iter]"+r"(iter)
        : [stack_amount]"i"(sizeof(word_t) * iter)
        : "cc"
    );
}

void
//Arch_switchToThread(tcb_t* tcb)
Arch_switchToThread(void* tcb)
{
    /* set PD */
//    setVMRoot(tcb);

//    __asm__ volatile("movq %[value], %%gs:%c[offset]"
//                 :
//                 : [value] "r" (&tcb->tcbArch.tcbContext.registers[Error + 1]),
//                 [offset] "i" (__builtin_offsetof(nodeInfo_t, currentThreadUserContext)));

//    if (0) {
//        x86_ibpb();
//    }

    if (0) {
        x86_flush_rsb();
    }
}


