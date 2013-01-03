#include <text.h>
#include <stdio.h>
#include <cstring.h>
#include <stddef.h>
#include <stdarg.h>

int printf(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	char *str;
	vsprintf(str, fmt, args);
	kprint(str);
	va_end(args);
	return strlen(str);
}
