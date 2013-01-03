#include "cstring.h"

#ifdef TEST
char *_strcat(char *dst, const char *src)
#else
char *strcat(char *dst, const char *src)
#endif
{
	int i,j;
	for(i=0; dst[i]; i++)
		;
	for(j=0; src[j]; j++)
		dst[i++] = src[j];
	dst[i] = 0;
	return dst;
}

#ifdef TEST

int initialize()
{
	char *str[80];
	strcpy(str, "Hello ");
	_strcat(str, "World!");
	if(strcmp(str, "Hello World!") == 0)
		return 1;
	else
		return 0;
}

#endif
