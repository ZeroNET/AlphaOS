/* AlphaOS v0.1
 * Copyright (c) 2012, Robert Schofield and Matthew Carey
 * All rights reserved.
 */

#include "core.h"

// Write a byte out to the specified port.
void outportb(u16int port, u8int value)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (value)); 
                         //The correct way for the ASM calls is 
                         //prefixed and suffixed with double underscores
}

u8int inportb(u16int port)
{
    u8int ret;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

u16int inportw(u16int port)
{
    u16int ret;
    __asm__ __volatile__ ("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

// Copy len bytes from src to dest.
void kmemcpy(u8int *dest, const u8int *src, u32int len)
{
  const char *sp = (const char *)src; /* src pointer, cast */
   char *dp = (char *)dest; /* destination pointer, cast */
   for( ; len != 0; len--) *dp++ = *sp++;
   //return dest;
} 


// Write len copies of val into dest.
void kmemset(u8int *dest, u8int val, u32int len)
{
    char *dp = (char *)dest;
    for( ; len != 0; len--) *dp++ = val;
    //return dest;
}


void die(char *msg, char *file, u32int line)
{
  kprintf("\nError in %s at %d\nReason: %s\n", file, line, msg);
}


char* itoa(int value, char* str, int radix) {
    static char dig[] =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz";
    int n = 0, neg = 0;
    unsigned int v;
    char* p, *q;
    char c;
    char *save = str;
 
    if (radix == 10 && value < 0) {
        value = -value;
        neg = 1;
    }
    v = value;
    do {
        str[n++] = dig[v%radix];
        v /= radix;
    } while (v);
    if (neg)
        str[n++] = '-';
    str[n] = '\0';
 
    for (p = str, q = p + (n-1); p < q; ++p, --q)
        c = *p, *p = *q, *q = c;
    str = save;
    return str;
}

double modulus(double a, double b)
{
  int result = (int)( a / b );
  return a - (double)( result ) * b;
}

char *dtostr(double db, char *str, int prec)
{
  char *str_;
  char *save = str_; // BLANK PTR
  int temp_int = 0; 
  int dec = 0;
  double tmp_db = db;
  if(db == 0.0) //IF ITS 0.0 WE CAN RETURN
  {
    strcpy(str_, "0.0");
    return save;
  }
  while(modulus(tmp_db, 1.0) != 0)
  {
    tmp_db *= 10; // MULTIPLY BY TEN TO DROP A DIGIT AFTER THE DECIMAL
    dec++;        // INCREMENT THE DECIMAL PLACE VALUE
  }
  string int_str;
  itoa((int)tmp_db, int_str, 10); // "12345"
  int str_len = strlen(int_str);  // ^ 5
  while(str_len != dec++) *str_++ = *int_str++;
  *str_++ = '.';
  if(prec == -1) {
    while(*int_str++ != '\0') *str_++ = *int_str;
  }
  else
  {
    if(prec == 0)
    {
      *str_++ = '0';
    }
    else
    {
      for(; prec != 0; prec--)
      {
        if(*int_str == '\0')
        {
          *str_++ = '0';
        }
        else
        {
          *str_++ = *int_str++;
        }
      }
    }
  }
  *str_ = '\0';
  str = save;
  return save;
}
