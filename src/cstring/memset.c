#include "cstring.h"

#ifdef TEST
void *_memset(void *ptr, int c, size_t num)
#else
void *memset(void *ptr, int c, size_t num)
#endif
{
	if(num < 1)
		return ptr;

	int i;
	for(i=0; num--; i++)
		((char *)ptr)[i] = c;
	return ptr;
}

#ifdef TEST

int initialize()
{
	char str[] = "almost every programmer should know memset!";
	_memset (str,'-',6);
	if(strcmp(str, "------ every programmer should know memset!") == 0)
		return 1;
	else
		return 0;
}

#endif