#include "cstring.h"

#ifdef TEST
int _strcoll(const char *str, const char *str_)
#else
int strcoll(const char *str, const char *str_)
#endif
{
	return strcmp(str, str_);
}

#ifdef TEST

int initialize()
{
	if(_strcoll("Hello World!","Hello World!") == 0)
		return 1;
	else
		return 0;
}

#endif