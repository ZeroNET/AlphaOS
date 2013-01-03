#include "cstring.h"

char *strtok(char *str, const char *delim)
{
	char *s,*s_;
	static char *save_s;

	if(str == NULL)
	{
		str = save_s;
		if(str == NULL) return (char *)NULL;
	}
	s = str + strspn(str, delim);
	if(*s == '\0')
	{
		save_s = NULL;
		return (char *)NULL;
	}

	s_ = strpbrk(s, delim);
	if(s_ != NULL)
		*s_++ = '\0';
	save_s = s_;
	return s;
}

#ifdef TEST

int initialize()
{
	return 0;
}

#endif