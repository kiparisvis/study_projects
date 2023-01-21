#include "s21_math_tests.h"

START_TEST(TEST_CEIL_1) {
  double x = 0;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_2) {
  double x = -0;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_3) {
  double x = 1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_4) {
  double x = -1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_5) {
  double x = 0.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_6) {
  double x = -0.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_7) {
  double x = 1.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_8) {
  double x = -1.1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_9) {
  double x = 1234.1234;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_10) {
  double x = -1234.1234;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_11) {
  double x = S21_NAN;
  double res_s21 = 0;
  res_s21 = s21_ceil(x);
  ck_assert(isnan(res_s21));
}
END_TEST

START_TEST(TEST_CEIL_12) {
  double x = -S21_NAN;
  double res_s21 = 0;
  res_s21 = s21_ceil(x);
  ck_assert(isnan(res_s21));
}
END_TEST

START_TEST(TEST_CEIL_13) {
  double x = S21_INF;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_14) {
  double x = S21_NEG_INF;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_15) {
  double x = 0.123456789;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_16) {
  double x = -0.123456789;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_17) {
  double x = 987364589238457.9;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_18) {
  double x = -987364589238457.9;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_CEIL_19) {
  double x = -1e-23;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_ceil(x);
  res = ceil(x);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FMOD_1) {
  double x = 0;
  double y = 0;
  double res_s21 = 0;
  res_s21 = s21_fmod(x, y);
  ck_assert(isnan(res_s21));
}
END_TEST

START_TEST(TEST_FMOD_2) {
  double x = -1;
  double y = -1;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_fmod(x, y);
  res = fmod(x, y);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FMOD_3) {
  double x = S21_INF;
  double y = 1;
  double res_s21 = 0;
  res_s21 = s21_fmod(x, y);
  ck_assert(isnan(res_s21));
}
END_TEST

START_TEST(TEST_FMOD_4) {
  double x = S21_NAN;
  double y = 0;
  double res_s21 = 0;
  res_s21 = s21_fmod(x, y);
  ck_assert(isnan(res_s21));
}
END_TEST

START_TEST(TEST_FMOD_5) {
  double x = 0;
  double y = S21_NAN;
  double res_s21 = 0;
  res_s21 = s21_fmod(x, y);
  ck_assert(isnan(res_s21));
}
END_TEST

START_TEST(TEST_FMOD_6) {
  double x = 123.234;
  double y = 56.23;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_fmod(x, y);
  res = fmod(x, y);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FMOD_7) {
  double x = -234.567;
  double y = 2345.5678;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_fmod(x, y);
  res = fmod(x, y);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FMOD_8) {
  double x = -1.3456345;
  double y = 0.3;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_fmod(x, y);
  res = fmod(x, y);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FMOD_9) {
  double x = 8912.3453424;
  double y = 2342.3456234567;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_fmod(x, y);
  res = fmod(x, y);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FMOD_10) {
  double x = 129.123234;
  double y = -123.3234;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_fmod(x, y);
  res = fmod(x, y);
  ck_assert_double_eq(res_s21, res);
}
END_TEST

START_TEST(TEST_FMOD_11) {
  double x = S21_NEG_INF;
  double y = -123.32357234;
  double res_s21 = 0;
  res_s21 = s21_fmod(x, y);
  ck_assert(isnan(res_s21));
}
END_TEST

START_TEST(TEST_FMOD_12) {
  for (double x = -1500; x < 1500; x += 123) {
    for (double y = -12; y < 12; y += 1.25) {
      ck_assert_double_eq(fmod(x, y), s21_fmod(x, y));
      ck_assert_double_eq(fmod(y, x), s21_fmod(y, x));
    }
  }
}
END_TEST

START_TEST(TEST_LOG_1) {
  double x = S21_NEG_INF;
  double res_s21 = 0;
  res_s21 = s21_log(x);
  ck_assert_ldouble_nan(res_s21);
}
END_TEST

START_TEST(TEST_LOG_2) {
  double x = S21_INF;
  double res_s21 = 0;
  res_s21 = s21_log(x);
  ck_assert_ldouble_infinite(res_s21);
}
END_TEST

START_TEST(TEST_LOG_3) {
  double x = -1;
  double res_s21 = 0;
  res_s21 = s21_log(x);
  ck_assert_ldouble_nan(res_s21);
}
END_TEST

START_TEST(TEST_LOG_4) {
  double x = 12;
  double res_s21 = 0;
  double res = 0;
  res_s21 = s21_log(x);
  res = log(x);
  ck_assert_ldouble_eq_tol(res_s21, res, 1e-6);
}
END_TEST

START_TEST(TEST_LOG_5) {
  double x = S21_NAN;
  double res_s21 = 0;
  res_s21 = s21_log(x);
  ck_assert_ldouble_nan(res_s21);
}
END_TEST

START_TEST(TEST_LOG_6) {
  double x = -0.1;
  double res_s21 = 0;
  res_s21 = s21_log(x);
  ck_assert_ldouble_nan(res_s21);
}
END_TEST

START_TEST(TEST_LOG_7) {
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_8) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_9) { ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6); }
END_TEST

START_TEST(TEST_LOG_10) {
  ck_assert_ldouble_eq_tol(s21_log(100), log(100), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_11) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_12) {
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_13) {
  ck_assert_ldouble_eq_tol(s21_log(S21_PI / 3), log(S21_PI / 3), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_14) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e-6), log(9.234578353457e-6),
                           1e-6);
}
END_TEST

START_TEST(TEST_LOG_15) {
  ck_assert_ldouble_eq_tol(s21_log(9.234578353457e6), log(9.234578353457e6),
                           1e-6);
}
END_TEST

START_TEST(TEST_LOG_16) {
  ck_assert_ldouble_eq_tol(s21_log(1234567.000000004), log(1234567.000000004),
                           1e-6);
}
END_TEST

START_TEST(TEST_LOG_17) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-16), log(1.1e-16), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_18) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-45), log(1.1e-45), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_19) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-18), log(1.1e-18), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_20) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-19), log(1.1e-19), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_21) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-23), log(1.1e-23), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_22) {
  ck_assert_ldouble_eq_tol(s21_log(987654321123.123e-30),
                           log(987654321123.123e-30), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_23) {
  ck_assert_ldouble_eq_tol(s21_log(98765.123e-11), log(98765.123e-11), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_24) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-17), log(1.1e-17), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_25) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-15), log(1.1e-15), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_26) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-14), log(1.1e-14), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_27) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-13), log(1.1e-13), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_28) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-12), log(1.1e-12), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_29) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-11), log(1.1e-11), 1e-6);
}
END_TEST

START_TEST(TEST_LOG_30) {
  ck_assert_ldouble_eq_tol(s21_log(1.1e-80), log(1.1e-80), 1e-6);
}
END_TEST

Suite *s21_ceil_fmod_log_suite(void) {
  Suite *s = suite_create("s21_ceil_fmod_log");
  TCase *tc_ceil, *tc_fmod, *tc_log;

  tc_ceil = tcase_create("TEST_CEIL\n");
  tcase_add_test(tc_ceil, TEST_CEIL_1);
  tcase_add_test(tc_ceil, TEST_CEIL_2);
  tcase_add_test(tc_ceil, TEST_CEIL_3);
  tcase_add_test(tc_ceil, TEST_CEIL_4);
  tcase_add_test(tc_ceil, TEST_CEIL_5);
  tcase_add_test(tc_ceil, TEST_CEIL_6);
  tcase_add_test(tc_ceil, TEST_CEIL_7);
  tcase_add_test(tc_ceil, TEST_CEIL_8);
  tcase_add_test(tc_ceil, TEST_CEIL_9);
  tcase_add_test(tc_ceil, TEST_CEIL_10);
  tcase_add_test(tc_ceil, TEST_CEIL_11);
  tcase_add_test(tc_ceil, TEST_CEIL_12);
  tcase_add_test(tc_ceil, TEST_CEIL_13);
  tcase_add_test(tc_ceil, TEST_CEIL_14);
  tcase_add_test(tc_ceil, TEST_CEIL_15);
  tcase_add_test(tc_ceil, TEST_CEIL_16);
  tcase_add_test(tc_ceil, TEST_CEIL_17);
  tcase_add_test(tc_ceil, TEST_CEIL_18);
  tcase_add_test(tc_ceil, TEST_CEIL_19);
  suite_add_tcase(s, tc_ceil);

  tc_fmod = tcase_create("TEST_FMOD\n");
  tcase_add_test(tc_fmod, TEST_FMOD_1);
  tcase_add_test(tc_fmod, TEST_FMOD_2);
  tcase_add_test(tc_fmod, TEST_FMOD_3);
  tcase_add_test(tc_fmod, TEST_FMOD_4);
  tcase_add_test(tc_fmod, TEST_FMOD_5);
  tcase_add_test(tc_fmod, TEST_FMOD_6);
  tcase_add_test(tc_fmod, TEST_FMOD_7);
  tcase_add_test(tc_fmod, TEST_FMOD_8);
  tcase_add_test(tc_fmod, TEST_FMOD_9);
  tcase_add_test(tc_fmod, TEST_FMOD_10);
  tcase_add_test(tc_fmod, TEST_FMOD_11);
  tcase_add_test(tc_fmod, TEST_FMOD_12);
  suite_add_tcase(s, tc_fmod);

  tc_log = tcase_create("TEST_LOG\n");
  tcase_add_test(tc_log, TEST_LOG_1);
  tcase_add_test(tc_log, TEST_LOG_2);
  tcase_add_test(tc_log, TEST_LOG_3);
  tcase_add_test(tc_log, TEST_LOG_4);
  tcase_add_test(tc_log, TEST_LOG_5);
  tcase_add_test(tc_log, TEST_LOG_6);
  tcase_add_test(tc_log, TEST_LOG_7);
  tcase_add_test(tc_log, TEST_LOG_8);
  tcase_add_test(tc_log, TEST_LOG_9);
  tcase_add_test(tc_log, TEST_LOG_10);
  tcase_add_test(tc_log, TEST_LOG_11);
  tcase_add_test(tc_log, TEST_LOG_12);
  tcase_add_test(tc_log, TEST_LOG_13);
  tcase_add_test(tc_log, TEST_LOG_14);
  tcase_add_test(tc_log, TEST_LOG_15);
  tcase_add_test(tc_log, TEST_LOG_16);
  tcase_add_test(tc_log, TEST_LOG_17);
  tcase_add_test(tc_log, TEST_LOG_18);
  tcase_add_test(tc_log, TEST_LOG_19);
  tcase_add_test(tc_log, TEST_LOG_20);
  tcase_add_test(tc_log, TEST_LOG_21);
  tcase_add_test(tc_log, TEST_LOG_22);
  tcase_add_test(tc_log, TEST_LOG_23);
  tcase_add_test(tc_log, TEST_LOG_24);
  tcase_add_test(tc_log, TEST_LOG_25);
  tcase_add_test(tc_log, TEST_LOG_26);
  tcase_add_test(tc_log, TEST_LOG_27);
  tcase_add_test(tc_log, TEST_LOG_28);
  tcase_add_test(tc_log, TEST_LOG_29);
  tcase_add_test(tc_log, TEST_LOG_30);
  suite_add_tcase(s, tc_log);

  return s;
}
