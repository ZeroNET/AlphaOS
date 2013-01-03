#include "cstring.h"

size_t strlen(const char *str)
{
	size_t i;
	for(i = 0; str[i]; i++)
		;
	return i;
}

#ifdef TEST

int initialize()
{
	if(strlen("Hi") == 2)
		return 1;
	else
		return 0;
}

#endif