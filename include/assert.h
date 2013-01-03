#ifndef ASSERT_H
#define ASSERT_H

#ifndef DEBUG
#define ASSERT(x)
#else
#define ASSERT(x) ((x) ? 1 : 0)
#endif

#endif