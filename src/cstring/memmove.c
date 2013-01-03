#include "cstring.h"

#ifdef TEST
void *_memmove(void *dst, const void *src, size_t num)
#else
void *memmove(void *dst, const void *src, size_t num)
#endif
{
	size_t i;
	if(( unsigned long)dst % sizeof(long) == 0 &&
		(unsigned long)src % sizeof(long) == 0 &&
		num % sizeof(long) == 0)
	{
		for(i = num/sizeof(long); i>0; i--)
			((long *)dst)[i-1] = ((long *)src)[i-1];
	}
	else
	{
		for(i = num; i>0; i--)
			((char *)dst)[i-1] = ((char *)src)[i-1];
	}
	return dst;
}

#ifdef TEST

int initialize()
{
	char str[] = "memmove can be very useful......";
  	_memmove (str+20,str+15,11);
  	if(strcmp(str, "memmove can be very very useful.") == 0)
  		return 1;
	else
		return 0;
}

#endif