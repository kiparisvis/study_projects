#include "s21_math_tests.h"

START_TEST(exp_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_4) {
  double x = 999999999999;
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_infinite(exp(x));
}
END_TEST

START_TEST(exp_test_5) {
  double x = -999999999999;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_6) {
  double x = DBL_MAX;
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_infinite(exp(x));
}
END_TEST

START_TEST(exp_test_7) {
  double x = -DBL_MAX;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_8) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_9) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
}
END_TEST

START_TEST(exp_test_10) {
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(exp(NAN));
}
END_TEST

START_TEST(exp_test_11) {
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_infinite(exp(INFINITY));
}
END_TEST

START_TEST(exp_test_12) {
  ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), exp(-INFINITY), S21_EPS);
}
END_TEST

Suite *s21_exp_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_exp");

  tc = tcase_create("s21_exp_case");
  tcase_add_test(tc, exp_test_1);
  tcase_add_test(tc, exp_test_2);
  tcase_add_test(tc, exp_test_3);
  tcase_add_test(tc, exp_test_4);
  tcase_add_test(tc, exp_test_5);
  tcase_add_test(tc, exp_test_6);
  tcase_add_test(tc, exp_test_7);
  tcase_add_test(tc, exp_test_8);
  tcase_add_test(tc, exp_test_9);
  tcase_add_test(tc, exp_test_10);
  tcase_add_test(tc, exp_test_11);
  tcase_add_test(tc, exp_test_12);
  suite_add_tcase(s, tc);

  return s;
}
