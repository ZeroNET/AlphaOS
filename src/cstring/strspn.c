#include "cstring.h"

#ifdef TEST
size_t _strspn(const char *str, const char *str_)
#else
size_t strspn(const char *str, const char *str_)
#endif
{
	const char *p = str, *sp;
	char c,sc;

cont:
	c = *p++;
	for(sp = str_; (sc = *sp++) != 0;)
		if(sc == c)
			goto cont;
	return (p - 1 - str);
}

#ifdef TEST

int initialize()
{
	char str[] = "83110 W0RLD";
	char num[] = "0123456789";
	if(_strspn(str, num) == 5)
		return 1;
	else
		return 0;
}

#endif