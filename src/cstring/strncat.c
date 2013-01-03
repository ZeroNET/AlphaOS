#include "cstring.h"

#ifdef TEST
char *_strncat(char *dst, const char *src, size_t num)
#else
char *strncat(char *dst, const char *src, size_t num)
#endif
{
	int i,j;
	for(i=0;dst[i];i++)
		;
	for(j=0;(num-- > 0) && src[j];j++)
		dst[i++] = src[j];
	dst[i] = 0;
	return dst;
}

#ifdef TEST

int initialize()
{
	char str[] = "Hello ";
	_strncat(str, "World!", strlen("World!"));
	if(!strcmp(str, "Hello World!"))
		return 1;
	else
		return 0;
}

#endif