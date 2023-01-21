#include "s21_math_tests.h"

START_TEST(s21_math_acos_1) { ck_assert_float_eq(s21_acos(0), acos(0)); }
END_TEST

START_TEST(s21_math_acos_2) { ck_assert_float_eq(s21_acos(-1), acos(-1)); }
END_TEST

START_TEST(s21_math_acos_3) {
  ck_assert_double_eq_tol(s21_acos(0), acosl(0), 1e-06);
}
END_TEST

START_TEST(s21_math_acos_4) {
  ck_assert_ldouble_nan(s21_acos(-INFINITY));
  ck_assert_ldouble_nan(acos(-INFINITY));
}
END_TEST

START_TEST(s21_math_acos_5) {
  ck_assert_ldouble_nan(s21_acos(INFINITY));
  ck_assert_ldouble_nan(acos(INFINITY));
}
END_TEST

START_TEST(s21_math_acos_6) {
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(acos(NAN));
}
END_TEST

START_TEST(s21_math_acos_7) {
  ck_assert_double_eq_tol(s21_acos(0.0), acosl(0.0), 1e-06);
}
END_TEST

START_TEST(s21_math_acos_8) {
  ck_assert_double_eq_tol(s21_acos(M_PI / 4), acosl(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(s21_math_acos_9) {
  ck_assert_double_eq_tol(s21_acos(M_PI / 6), acosl(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(s21_math_acos_10) {
  ck_assert_ldouble_nan(s21_acos(M_PI / 3));
  ck_assert_ldouble_nan(acos(M_PI / 3));
}
END_TEST

START_TEST(s21_math_acos_11) {
  ck_assert_ldouble_nan(s21_acos(M_PI / 2));
  ck_assert_ldouble_nan(acos(M_PI / 2));
}
END_TEST

START_TEST(s21_math_acos_12) {
  ck_assert_ldouble_nan(s21_acos(3 * M_PI / 2));
  ck_assert_ldouble_nan(acos(3 * M_PI / 2));
}
END_TEST

START_TEST(s21_math_acos_13) {
  ck_assert_ldouble_nan(s21_acos(2 * M_PI));
  ck_assert_ldouble_nan(acos(2 * M_PI));
}
END_TEST

START_TEST(s21_math_asin_1) {
  ck_assert_double_eq_tol(s21_asin(0), asinl(0), 1e-06);
}
END_TEST

START_TEST(s21_math_asin_2) {
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(asin(-INFINITY));
}
END_TEST

START_TEST(s21_math_asin_3) {
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(asin(INFINITY));
}
END_TEST

START_TEST(s21_math_asin_4) {
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(asin(NAN));
}
END_TEST

START_TEST(s21_math_asin_5) {
  ck_assert_double_eq_tol(s21_asin(0.0), asin(0.0), 1e-06);
}
END_TEST

START_TEST(s21_math_asin_6) {
  ck_assert_double_eq_tol(s21_asin(M_PI / 6), asin(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(s21_math_asin_7) {
  ck_assert_double_eq_tol(s21_asin(M_PI / 4), asin(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(s21_math_asin_8) {
  ck_assert_ldouble_nan(s21_asin(M_PI / 3));
  ck_assert_ldouble_nan(asin(M_PI / 3));
}
END_TEST

START_TEST(s21_math_asin_9) {
  ck_assert_ldouble_nan(s21_asin(M_PI / 2));
  ck_assert_ldouble_nan(asin(M_PI / 2));
}
END_TEST

START_TEST(s21_math_asin_10) {
  ck_assert_ldouble_nan(s21_asin(3 * M_PI / 2));
  ck_assert_ldouble_nan(asin(3 * M_PI / 2));
}
END_TEST

START_TEST(s21_math_asin_11) {
  ck_assert_ldouble_nan(s21_asin(2 * M_PI));
  ck_assert_ldouble_nan(asin(2 * M_PI));
}
END_TEST

START_TEST(s21_math_asin_12) {
  ck_assert_ldouble_nan(s21_asin(-2 * M_PI));
  ck_assert_ldouble_nan(asin(-2 * M_PI));
}
END_TEST

START_TEST(s21_math_asin_13) {
  ck_assert_ldouble_nan(s21_asin(-3 * M_PI));
  ck_assert_ldouble_nan(asin(-3 * M_PI));
}
END_TEST

START_TEST(s21_math_asin_14) {
  ck_assert_ldouble_nan(s21_asin(-S21_PI));
  ck_assert_ldouble_nan(asin(-S21_PI));
}
END_TEST

START_TEST(s21_math_atan_1) {
  ck_assert_double_eq_tol(s21_atan(-INFINITY), atanl(-INFINITY), 1e-06);
}
END_TEST

START_TEST(s21_math_atan_2) {
  ck_assert_double_eq_tol(s21_atan(INFINITY), atanl(INFINITY), 1e-06);
}
END_TEST

START_TEST(s21_math_atan_3) {
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

START_TEST(s21_math_atan_4) {
  ck_assert_double_eq_tol(s21_atan(0.0), atanl(0.0), 1e-06);
}
END_TEST

START_TEST(s21_math_atan_5) {
  ck_assert_double_eq_tol(s21_atan(M_PI / 6), atanl(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(s21_math_atan_6) {
  ck_assert_double_eq_tol(s21_atan(M_PI / 4), atanl(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(s21_math_atan_7) {
  ck_assert_double_eq_tol(s21_atan(-2 * M_PI), atanl(-2 * M_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_atan_8) {
  ck_assert_double_eq_tol(s21_atan(M_PI), atanl(M_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_atan_9) {
  ck_assert_double_eq_tol(s21_atan(M_PI / 3), atanl(M_PI / 3), 1e-06);
}
END_TEST

START_TEST(s21_math_atan_10) {
  ck_assert_double_eq_tol(s21_atan(3 * M_PI / 3), atanl(3 * M_PI / 3), 1e-06);
}
END_TEST

Suite *s21_acos_asin_atan_suite(void) {
  Suite *s = suite_create("s21_acos_asin_atan");
  TCase *tc_acos, *tc_asin, *tc_atan;

  tc_acos = tcase_create("s21_acos_case\n");
  tcase_add_test(tc_acos, s21_math_acos_1);
  tcase_add_test(tc_acos, s21_math_acos_2);
  tcase_add_test(tc_acos, s21_math_acos_3);
  tcase_add_test(tc_acos, s21_math_acos_4);
  tcase_add_test(tc_acos, s21_math_acos_5);
  tcase_add_test(tc_acos, s21_math_acos_6);
  tcase_add_test(tc_acos, s21_math_acos_7);
  tcase_add_test(tc_acos, s21_math_acos_8);
  tcase_add_test(tc_acos, s21_math_acos_9);
  tcase_add_test(tc_acos, s21_math_acos_10);
  tcase_add_test(tc_acos, s21_math_acos_11);
  tcase_add_test(tc_acos, s21_math_acos_12);
  tcase_add_test(tc_acos, s21_math_acos_13);
  suite_add_tcase(s, tc_acos);

  tc_asin = tcase_create("s21_asin_case\n");
  tcase_add_test(tc_asin, s21_math_asin_1);
  tcase_add_test(tc_asin, s21_math_asin_2);
  tcase_add_test(tc_asin, s21_math_asin_3);
  tcase_add_test(tc_asin, s21_math_asin_4);
  tcase_add_test(tc_asin, s21_math_asin_5);
  tcase_add_test(tc_asin, s21_math_asin_6);
  tcase_add_test(tc_asin, s21_math_asin_7);
  tcase_add_test(tc_asin, s21_math_asin_8);
  tcase_add_test(tc_asin, s21_math_asin_9);
  tcase_add_test(tc_asin, s21_math_asin_10);
  tcase_add_test(tc_asin, s21_math_asin_11);
  tcase_add_test(tc_asin, s21_math_asin_12);
  tcase_add_test(tc_asin, s21_math_asin_13);
  tcase_add_test(tc_asin, s21_math_asin_14);
  suite_add_tcase(s, tc_asin);

  tc_atan = tcase_create("s21_atan_case\n");
  tcase_add_test(tc_atan, s21_math_atan_1);
  tcase_add_test(tc_atan, s21_math_atan_2);
  tcase_add_test(tc_atan, s21_math_atan_3);
  tcase_add_test(tc_atan, s21_math_atan_4);
  tcase_add_test(tc_atan, s21_math_atan_5);
  tcase_add_test(tc_atan, s21_math_atan_6);
  tcase_add_test(tc_atan, s21_math_atan_7);
  tcase_add_test(tc_atan, s21_math_atan_8);
  tcase_add_test(tc_atan, s21_math_atan_9);
  tcase_add_test(tc_atan, s21_math_atan_10);
  suite_add_tcase(s, tc_atan);

  return s;
}
