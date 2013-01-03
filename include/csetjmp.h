#ifndef SETJMP_H
#define SETJMP_H

typedef struct 
{
  unsigned long ebp;
  unsigned long ebx;
  unsigned long edi;
  unsigned long esi;
  unsigned long esp;
  unsigned long eip;
} jmp_buf[1];

#ifdef  __cplusplus
extern "C" {
#endif

int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int value);

#ifdef  __cplusplus
}
#endif

#endif
