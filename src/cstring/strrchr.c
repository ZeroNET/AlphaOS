#include "cstring.h"

char *strrchr(const char *cp, int ch)
{
    char *save;
    char c;

    for (save = (char *) 0; (c = *cp); cp++) {
	if (c == ch)
	    save = (char *) cp;
    }

    return save;
}

#ifdef TEST

int initialize()
{
	char str[] = "Hello World!";
	if(strcmp(strrchr("Hello World!",(int)'o'), "orld!") == 0)
		return 1;
	else
		return 0;
}

#endif