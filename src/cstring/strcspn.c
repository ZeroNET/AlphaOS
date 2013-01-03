#include "cstring.h"

#ifdef TEST
size_t _strcspn(const char *str, const char *str_)
#else
size_t strcspn(const char *str, const char *str_)
#endif
{
	int i;
	const char *s;

	for(i = 0; *str; str++, i++)
	{
		for(s = str_; *s; s++)
			if(*str == *s) return i;
	}
	return i;
}

#ifdef TEST

int initialize()
{
	char str[] = "fcba73";
	char keys[] = "1234567890";
	if(_strcspn(str,keys) == 4)
		return 1;
	else
		return 0;
}

#endif