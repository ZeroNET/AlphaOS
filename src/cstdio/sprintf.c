#include "stdarg.h"
#include "stddef.h"
#include "cstring.h"

int sprintf(char *buf, const char *fmt, ...)
{
  va_list args;
  int n;

  va_start(args, fmt);
  n = vsprintf(buf, fmt, args);
  va_end(args);

  return n;
}


#ifdef TEST
int initialize()
{
	char *string_test; sprintf(string_test, "Hello %s!", "World");
	if(strcmp(string_test, "Hello World!") == 0)
		return 1;
	else
		return 0;
}
#endif
