#include "cstring.h"

#ifdef TEST
void *_memcpy(void *dst, const void *src, size_t num)
#else
void *memcpy(void *dst, const void *src, size_t num)
#endif
{
		int i;
        for(i = 0; num--; i++)
                ((char *)dst)[i] = ((char *)src)[i];
        return dst;
}

#ifdef TEST

int initialize()
{
	char str[]="Hello World!";
	char str_[6];
	_memcpy(str_, str, 5);
	str_[5] = '\0';
	if(strcmp(str_, "Hello") == 0)
		return 1;
	else
		return 0;
}

#endif