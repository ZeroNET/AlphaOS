#include "cstring.h"

char *strstr(const char *str, const char *str_)
{
	char *cp = (char *)str;
	char *s,*s_;

	if(!*str_)
		return ((char *)str);
	while(*cp)
	{
		s = cp;
		s_ = (char *)str_;

		while(*s && *s_ && !(*s-*s_))
			s++,s_++;
		if(!*s_)
			return cp;
		cp++;
	}
	return NULL;
}

#ifdef TEST

int initialize()
{
	return 0;
}

#endif