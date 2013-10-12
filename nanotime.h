#include <time.h>
#ifdef __MACH__
#define NANO extern
#else
#define NANO
#endif

#define NANO_FAILURE -1
#define NANO_SUCCESS 0
#define NANO_EXPECTED(X) X == NANO_SUCCESS
#define NANO_UNEXPECTED(X) X == NANO_FAILURE
#define nano_return_t short

NANO nano_return_t nano_second(unsigned long *second);
NANO nano_return_t nano_time(long double *time);
NANO nano_return_t nano_timespec(struct timespec *now);
