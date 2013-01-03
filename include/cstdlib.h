#ifndef CSTDLIB_H
#define CSTDLIB_H

#include "include/stddef.h"

int atoi(const char *str);

long int atol(const char *str);

double atof(const char *str);

double strtod(const char *s);

long int strtol(const char *s);

unsigned long int strtoul(const char *s);

int abs(int i);

long int labs(long int i);

div_t div(int num, int den);

ldiv_t ldiv(long int num, long int den);

typedef struct div__ {
	int quot,rem;
} div_t;

typedef struct ldiv__ {
	long int quot, rem;
} ldiv_t;



#endif