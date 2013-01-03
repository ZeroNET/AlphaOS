#include "cstring.h"

#ifdef TEST
int _strcmp(const char *str, const char *str_)
#else
int strcmp(const char *str, const char *str_)
#endif
{
	int i;
	for(i=0; str[i] && str_[i]; i++)
		if(str[i] != str_[i]) return (int)(str[i] - str_[i]);
	return 0;
}

#ifdef TEST

int initialize()
{
	char *str = "Hello World!";
	char *str_ = "Hello World!";
	if(_strcmp(str, str_) == 0)
		return 1;
	else
		return 0;
}

#endif