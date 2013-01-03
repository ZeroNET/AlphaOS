#include "cstring.h"

#ifdef TEST
char *_strpbrk(const char *str, const char *str_)
#else
char *strpbrk(const char *str, const char *str_)
#endif
{
	const char *s;
	for(;*str;str++)
	{
		for(s = str_; *s; s++)
			if(*str == *s) return (char *)str;
	}
	return NULL;
}

#ifdef TEST

int initialize()
{
	char str[] = "Hello World!";
	char keys[] = "W";
	if(strcmp(_strpbrk(str, keys), "World!") == 0)
		return 1;
	else
		return 0;
}

#endif