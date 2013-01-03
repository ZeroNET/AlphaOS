#include "cstring.h"

#ifdef TEST
int _strncmp(const char *str, const char *str_, size_t num)
#else
int strncmp(const char *str, const char *str_, size_t num)
#endif
{
	if(num == 0) return 0;
	int i = 0;
	while(str[i] && str_[i] && (num-- > 0))
		;
	return (int)(str[i] - str_[i]);
}

#ifdef TEST

int initialize()
{
	if(_strncmp("Hello World!", "Hello World!", strlen("Hello World!")) == 0)
		return 1;
	else
		return 0;
}

#endif