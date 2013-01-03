#include "cstring.h"

size_t strxfrm(char *dst, const char *src, size_t num)
{
	if(num == 0) return strlen(src);
	int len = strlen(src);
	int cpsz = (len < num ? len : num - 1);
	memcpy(dst, src, cpsz);
	dst[cpsz] = 0;
	return len;
}

#ifdef TEST

int initialize()
{
	return 0;
}

#endif