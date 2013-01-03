#include "cstring.h"

#ifdef TEST
char *_strcpy(char *dst, const char *src)
#else
char *strcpy(char *dst, const char *src)
#endif
{
	int i = 0;
	while(dst[i] = src[i++]);
	return dst;
}

#ifdef TEST

int initialize()
{
	char dst[13];
	_strcpy(dst, "Hello World!");
	if(strcmp(dst, "Hello World!") == 0)
		return 1;
	else
		return 0;
}

#endif