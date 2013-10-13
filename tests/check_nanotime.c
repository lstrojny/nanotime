#include <sys/time.h>
#include <check.h>
#include "../src/nanotime.h"

START_TEST(test_nanotime_nano_timespec)
{
	struct timespec ts;
	struct timeval tv;
	gettimeofday(&tv, NULL);

	ck_assert_int_eq(nano_timespec(&ts), NANO_SUCCESS);
	ck_assert(ts.tv_sec > 0);
	ck_assert_int_eq(ts.tv_sec, tv.tv_sec);
	ck_assert(ts.tv_nsec > 0);
}
END_TEST

START_TEST(test_nanotime_nano_time)
{
	long double now;
	struct timeval tv;
	gettimeofday(&tv, NULL);

	ck_assert_int_eq(nano_time(&now), NANO_SUCCESS);
	ck_assert(now > 0);
	ck_assert(now > (long double) tv.tv_sec);
}
END_TEST

START_TEST(test_nanotime_nano_second)
{
	unsigned long sec, ref;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	// Convert to nanoseconds
	ref = (unsigned long) tv.tv_sec * 1E9;

	ck_assert_int_eq(nano_second(&sec), NANO_SUCCESS);
	ck_assert(sec > 0);
	ck_assert(sec > ref);
}
END_TEST

Suite * nanotime_suite(void)
{
	Suite *suite = suite_create("nanotime");
	TCase *test_case = tcase_create("nanotime");
	tcase_add_test(test_case, test_nanotime_nano_timespec);
	tcase_add_test(test_case, test_nanotime_nano_time);
	tcase_add_test(test_case, test_nanotime_nano_second);
	suite_add_tcase(suite, test_case);

	return suite;
}

int main()
{
	int number_failed;
	Suite *suite = nanotime_suite();
	SRunner *runner = srunner_create(suite);
	srunner_run_all(runner, CK_NORMAL);
	number_failed = srunner_ntests_failed(runner);
	return number_failed;
}

