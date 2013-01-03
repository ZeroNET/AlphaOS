#include "cstring.h"

#ifdef TEST
const void *_memchr(const void *ptr, int value, size_t num)
#else
const void *memchr(const void *ptr, int value, size_t num)
#endif
{
	if(num < 1) return NULL;
	const unsigned char *p = (const unsigned char *)ptr;
	while(num--)
		if(*p++ == (char)value)
			return (void *)(p - 1);
	return NULL;
}

#ifdef TEST
#include <stdio.h>

int initialize()
{
	char *str = "Hello World!";
	char *p   = (char *) _memchr(str,'W',12);
	if(strcmp(p,"World!") == 0)
		return 1;
	else
		return 0;
}

#endif