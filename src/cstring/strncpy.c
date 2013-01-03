#include "cstring.h"

#ifdef TEST
char *_strncpy(char *dst, const char *src, size_t num)
#else
char *strncpy(char *dst, const char *src, size_t num)
#endif
{
	int i = 0;
	while((num-- > 0) && (dst[i] = src[i++]));
	return dst;
}

#ifdef TEST

int initialize()
{
	char str[strlen("Hello World!") + 1];
	if(strcmp(_strncpy(str,"Hello World!",strlen("Hello World!")), "Hello World!") == 0)
		return 1;
	else
		return 0;
}

#endif