#ifndef STDDEF_H
#define STDDEF_H

#ifdef ARCH_64
typedef unsigned long size_t;
typedef signed   long ptrdiff_t;
#else
typedef unsigned      size_t;
typedef signed   int  ptrdiff_t;
#endif

#define NULL ((void*)0)

#define offsetof(st, m) \
     ((size_t) ( (char *)&((st *)0)->m - (char *)0 ))
     
#endif