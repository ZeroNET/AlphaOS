#include "kernel/a20.h"

unsigned short check_a20()
{
	unsigned short i;
	asm ("xorl %%eax, %%eax\n"
		 "incl %%eax\n"
		 "movl %%eax, 0x000000\n"
		 "cmpl %%eax, 0x100000\n"
		 :"=r"(i)
		 :
		 :"%eax"
		);
	return i;
}