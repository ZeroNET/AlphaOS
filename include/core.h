/* AlphaOS v0.1
 * Copyright (c) 2012, Robert Schofield and Matthew Carey
 * All rights reserved.
 */

#ifndef CORE_H
#define CORE_H
#define DIE(msg) die(msg, __FILE__, __LINE__)
// Some nice typedefs, to standardise sizes across platforms.
// These typedefs are written for 32-bit X86.
typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;

typedef unsigned int   uint32_t;
typedef          int   sint32_t;
typedef unsigned long long   uint64_t;
typedef          long long   sint64_t;
typedef unsigned short uint16_t;
typedef          short sint16_t;
typedef unsigned char  uint8_t;
typedef          char  sint8_t;
typedef long off_t;

typedef char *string;
typedef int bool;
typedef char *ptr;
#define true 1
#define false 0

void outportb(u16int port, u8int value);
u8int inportb(u16int port);
u16int inportw(u16int port);
void kmemcpy(u8int *dest, const u8int *src, u32int len);
void kmemset(u8int *dest, u8int val, u32int len);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
void die(char *msg, char *file, u32int line);
char *itoa(int value, char *str, int radix);
char *dtostr(double db, char *str, int prec);
/* This defines what the stack looks like after an ISR was running */
struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
};

typedef struct regs regs;

#endif // CORE_H