#include <time.h>
#include <stdio.h>

#ifdef __MACH__
#include <mach/mach.h>
#include <mach/clock.h>
#define NANO extern
#else
#include <sys/time.h>
#define NANO
#endif

#define NANO_FAILURE -1
#define NANO_SUCCESS 0
#define NANO_EXPECTED(X) X == NANO_SUCCESS
#define NANO_UNEXPECTED(X) X == NANO_FAILURE
#define nano_return_t short

NANO nano_return_t current_nano_second(unsigned long *second);
NANO nano_return_t current_nano_time(long double *time);
NANO nano_return_t nano_now(struct timespec *now);

NANO nano_return_t nano_now(struct timespec *now)
{
#ifdef __MACH__
	clock_serv_t clock_service;
	mach_timespec_t mach_time;

	if (host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &clock_service) != 0) {
		return NANO_FAILURE;
	}

	if (clock_get_time(clock_service, &mach_time) != 0) {
		return NANO_FAILURE;
	}

	if (mach_port_deallocate(mach_task_self(), clock_service) != 0) {
		return NANO_FAILURE;
	}

	now->tv_sec = mach_time.tv_sec;
	now->tv_nsec = mach_time.tv_nsec;
#else
	if (clock_gettime(CLOCK_REALTIME, now) != 0) {
		return NANO_FAILURE;
	}
#endif

	return NANO_SUCCESS;
}

NANO nano_return_t current_nano_second(unsigned long *second)
{
	struct timespec now;

	if (NANO_UNEXPECTED(nano_now(&now))) {
		return NANO_FAILURE;
	}

	*second = now.tv_sec * 1E9 + now.tv_nsec;

	return NANO_SUCCESS;
}

NANO nano_return_t current_nano_time(long double *time)
{
	struct timespec now;

	if (NANO_UNEXPECTED(nano_now(&now))) {
		return NANO_FAILURE;
	}

	*time = (long double) now.tv_sec + now.tv_nsec / 1E9;

	return NANO_SUCCESS;
}

int main()
{
	unsigned long nano_sec;
	long double now;

	if (NANO_UNEXPECTED(current_nano_second(&nano_sec))) {
		return 1;
	}

	if (NANO_UNEXPECTED(current_nano_time(&now))) {
		return 1;
	}

	printf("%ld\n", nano_sec);
	printf("%1.10Lf\n", now);

	return 0;
}
