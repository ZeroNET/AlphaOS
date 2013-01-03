#ifndef FLOAT_H
#define FLOAT_H

#define FLT_ROUNDS 1

#define FLT_EVAL_METHOD 0

#define FLT_RADIX 2

#define FLT_MANT_DIG 53

#define DBL_MANT_DIG FLT_MANT_DIG

#define LDBL_MANT_DIG DBL_MANT_DIG

#if LDBL_MANT_DIG == 53
#define DECIMAL_DIG 17
#else
#define DECIMAL_DIG 36
#endif

#define FLT_DIG 17

#define DBL_DIG FLT_DIG

#define LDBL_DIG DBL_DIG

#define FLT_MIN_EXP (-1024)

#define DBL_MIN_EXP FLT_MIN_EXP

#define LDBL_MIN_EXP DBL_MIN_EXP

#define FLT_MIN_10_EXP (-307)

#define DBL_MIN_10_EXP FLT_MIN_10_EXP

#define LDBL_MIN_10_EXP DBL_MIN_10_EXP

#define FLT_MAX_10_EXP (+308)

#define DBL_MAX_10_EXP FLT_MAX_10_EXP

#define LDBL_MAX_10_EXP DBL_MAX_10_EXP

#define FLT_MAX_EXP (+1023)

#define DBL_MAX_EXP FLT_MAX_EXP

#define LDBL_MAX_EXP DBL_MAX_EXP

#define FLT_MAX 1.7976931348623157E+308

#define DBL_MAX FLT_MAX

#define LDBL_MAX DBL_MAX

#define FLT_MIN 2.2250738585072014E-308

#define DBL_MIN FLT_MIN

#define LDBL_MIN DBL_MIN

#define FLT_EPSILON 4.4408920985006272E-16

#define DBL_EPSILON FLT_EPSILON

#define LDBL_EPSILON DBL_EPSILON

#endif