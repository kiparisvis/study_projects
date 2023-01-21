#include "s21_math_tests.h"

START_TEST(pow_test_001) {
  double base = +0;
  double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_002) {
  double base = +0;
  double exp = 4;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_011) {
  double base = -0;
  double exp = -1;
  ck_assert_ldouble_infinite(powl(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_021) {
  double base = 1;
  double exp = 169;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_031) {
  double base = -1;
  double exp = -169;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_041) {
  double base = 169;
  double exp = 0.88;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_051) {
  double base = -169;
  double exp = -8.77;
  ck_assert_ldouble_nan(powl(base, exp));
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_052) {
  double base = -169;
  double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_061) {
  double base = NAN;
  double exp = NAN;
  ck_assert_ldouble_nan(powl(base, exp));
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_071) {
  double base = INFINITY;
  double exp = 1;
  ck_assert_ldouble_infinite(powl(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_081) {
  double base = -INFINITY;
  double exp = -0.88;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_091) {
  double base = -INFINITY;
  double exp = 1;
  ck_assert_ldouble_infinite(powl(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_101) {
  double base = 0.88;
  double exp = -8.77;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), powl(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_111) {
  long double base = -0.88;
  long double exp = 0.00000001;
  ck_assert_ldouble_nan(powl(base, exp));
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_121) {
  long double base = 9999999999999999;
  long double exp = 1;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_122) {
  long double base = 9999999999999999;
  long double exp = 0.88;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_EPS_B);
}
END_TEST

START_TEST(pow_test_132) {
  long double base = -0.1;
  long double exp = -DBL_MAX;
  ck_assert_ldouble_infinite(powl(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

Suite *s21_pow_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_pow");

  tc = tcase_create("s21_pow_case");
  tcase_add_test(tc, pow_test_001);
  tcase_add_test(tc, pow_test_002);
  tcase_add_test(tc, pow_test_011);
  tcase_add_test(tc, pow_test_021);
  tcase_add_test(tc, pow_test_031);
  tcase_add_test(tc, pow_test_041);
  tcase_add_test(tc, pow_test_051);
  tcase_add_test(tc, pow_test_052);
  tcase_add_test(tc, pow_test_061);
  tcase_add_test(tc, pow_test_071);
  tcase_add_test(tc, pow_test_081);
  tcase_add_test(tc, pow_test_091);
  tcase_add_test(tc, pow_test_101);
  tcase_add_test(tc, pow_test_111);
  tcase_add_test(tc, pow_test_121);
  tcase_add_test(tc, pow_test_122);
  tcase_add_test(tc, pow_test_132);

  suite_add_tcase(s, tc);

  return s;
}

/*
    0,
    -0,
    -1,
    1,
    169,
    -169,
    NAN,
    INFINITY,
    -INFINITY,
    0.88,
    -0.88,
    8.77,
    -8.77,
    0.00000001,
    -0.00000001
*/
