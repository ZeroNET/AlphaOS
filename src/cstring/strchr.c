#include "cstring.h"

#ifdef  TEST
char *_strchr(const char *str, int c)
#else
char *strchr(const char *str, int c)
#endif
{
	int i;
	for(i=0;str[i];i++)
		if(str[i] == (char )c) return (char *)(str + i);
	if(str[i] == (char )c) return (char *)(str + i);
	return NULL;
}

#ifdef TEST

int initialize()
{
	char str[] = "Hello World!";
	char *pch;
	pch = _strchr(str, ' ');
	if(strcmp(pch, "World!"))
		return 1;
	else
		return 0;
}

#endif