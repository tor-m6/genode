/*
 * \brief  setcontext/getcontext/makecontext/swapcontext simple test
 * \author Alexander Tormasov
 * \date   2021-03-12
 */


/* libC includes */
extern "C" {
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/limits.h>
#include <sys/random.h>
#include <sys/resource.h>
#include <sys/syscall.h>
#include <time.h>
#include <time.h>
#include <unistd.h>
#include <ucontext.h>
}

#define MEM 64000
ucontext_t T1, T2, Main, a;

void fn1()
{
	printf("this is from 1\n");
	setcontext(&Main);
}

void fn2()
{
	printf("this is from 2\n");
	setcontext(&a);
	printf("finished 1\n");
}

void start()
{
	getcontext(&a);
	a.uc_link = 0;
	a.uc_stack.ss_sp = alloc_secondary_stack("test",MEM);
	a.uc_stack.ss_size = MEM;
	a.uc_stack.ss_flags = 0;
	makecontext(&a, &fn1, 0);
}

int main(int argc, char **argv)
{
	printf("--- mcontext test ---\n");
	printf("start... ucontext_t size: %ld\n", sizeof(a));
	start();
	printf("context prepared for func: %p\n",
	       a.uc_mcontext.gregs[REG_RIP]);
	getcontext(&Main);
	getcontext(&T1);
	T1.uc_link = 0;
	T1.uc_stack.ss_sp = alloc_secondary_stack("test",MEM);
	T1.uc_stack.ss_size = MEM;
	T1.uc_stack.ss_flags = 0;
	makecontext(&T1, &fn1, 0);
	printf("swapcontext stacks: %p to %p\n", Main.uc_stack.ss_sp, T1.uc_stack.ss_sp);
	swapcontext(&Main, &T1);
	printf("swapcontext done\n");
	getcontext(&T2);
	T2.uc_link = 0;
	T2.uc_stack.ss_sp = alloc_secondary_stack("test",MEM);
	T2.uc_stack.ss_size = MEM;
	T2.uc_stack.ss_flags = 0;
	makecontext(&T2, &fn2, 0);
	swapcontext(&Main, &T2);
	printf("completed\n");
	exit(0);
}
