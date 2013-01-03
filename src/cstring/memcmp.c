#include "cstring.h"

#ifdef TEST
int _memcmp(const void *ptr, const void *ptr_, size_t num)
#else
int memcmp(const void *ptr, const void *ptr_, size_t num)
#endif
{
	unsigned int i;
	for(i=0; i < num; i++)
		if(((char *)ptr)[i] != ((char *)ptr_)[i]) return (int)(((char *)ptr)[i] - ((char *)ptr_)[i]);
	return 0;
}

#ifdef TEST

int initialize()
{
	int i,j,k;
	i = _memcmp("A","A",1);
	j = _memcmp("B","A",1);
	k = _memcmp("A","B",1);
	if(i == 0 && j > 0 && k < 0)
		return 1;
	else
		return 0;
}

#endif