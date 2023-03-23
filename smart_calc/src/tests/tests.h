#ifndef TEST
#define TEST

#include <check.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "../c_calc_polish.h"

void run_tests(void);
void run_testcase(Suite *testcase);

double get_rand(double min, double max);
#endif  //  TEST
