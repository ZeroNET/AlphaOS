#ifndef CTYPES_H

#include "stddef.h"

typedef char		int8_t;
typedef short		int16_t;
typedef int 		int32_t;
typedef long long	int64_t;

typedef unsigned char 		uint8_t;
typedef unsigned short 		uint16_t;
typedef unsigned int 		uint32_t;
typedef unsigned long long	uint64_t;

typedef long intptr_t;
typedef unsigned long uintptr_t;

#define isalnum(c) \
	( (isalpha((c)) || isdigit((c)) )

#define isalpha(c) \
	(isupper((c)) || islower((c)))

#define iscntrl(c) \
	(!isprint(c))

#define isdigit(c) \
	((c)>='0' && (c)<='9')

#define isgraph(c) \
	(isprint(c) && (c)==' ')

#define islower(c) \
	((c)>=97 && (c)<=122)

#define isprint(c) \
	(((c)>=32 && (c)<=126) || ((c)>=161 && (c)<=254))

#define ispunct(c) \
	(isprint((c)) && !isalnum((c)) && !isspace((c)))

#define isspace(c) \
	((c)==' ' || (c)=='\f' || (c)=='\n' || (c)=='\r' || (c)=='\t' || (c)=='\v')

#define isupper(c) \
	((c) >= 'A' && (c) <= 'Z')

#define isxdigit(c) \
	( isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') )

#define tolower(c) \
	((c >= 'A' && c <= 'Z') ? (c+32) : (c))

#define toupper(c) \
	((c >= 'a' && c <= 'z') ? (c-32) : (c))
#endif
