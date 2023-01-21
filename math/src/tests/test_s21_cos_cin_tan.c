#include "s21_math_tests.h"

START_TEST(s21_math_cos_1) { ck_assert_float_eq(s21_cos(0), cos(0)); }
END_TEST

START_TEST(s21_math_cos_2) { ck_assert_float_eq(s21_cos(-1), cos(-1)); }
END_TEST

START_TEST(s21_math_cos_3) {
  ck_assert_double_eq_tol(s21_cos(0), cosl(0), 1e-06);
}
END_TEST

START_TEST(s21_math_cos_4) { ck_assert_ldouble_nan(s21_cos(-INFINITY)); }
END_TEST

START_TEST(s21_math_cos_5) { ck_assert_ldouble_nan(cosl(-INFINITY)); }
END_TEST

START_TEST(s21_math_cos_6) { ck_assert_ldouble_nan(s21_cos(INFINITY)); }
END_TEST

START_TEST(s21_math_cos_7) { ck_assert_ldouble_nan(cosl(INFINITY)); }
END_TEST

START_TEST(s21_math_cos_8) { ck_assert_ldouble_nan(s21_cos(NAN)); }
END_TEST

START_TEST(s21_math_cos_9) { ck_assert_ldouble_nan(cosl(NAN)); }
END_TEST

START_TEST(s21_math_cos_10) {
  ck_assert_double_eq_tol(s21_cos(0.0), cosl(0.0), 1e-06);
}
END_TEST

START_TEST(s21_math_cos_11) {
  ck_assert_double_eq_tol(s21_cos(M_PI / 4), cosl(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(s21_math_cos_12) {
  ck_assert_double_eq_tol(s21_cos(M_PI / 6), cosl(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(s21_math_cos_13) {
  ck_assert_double_eq_tol(s21_cos(M_PI / 3), cosl(M_PI / 3), 1e-06);
}
END_TEST

START_TEST(s21_math_cos_14) {
  ck_assert_double_eq_tol(s21_cos(M_PI / 2), cosl(M_PI / 2), 1e-06);
}
END_TEST

START_TEST(s21_math_cos_15) {
  ck_assert_double_eq_tol(s21_cos(3 * M_PI / 2), cosl(3 * M_PI / 2), 1e-06);
}
END_TEST

START_TEST(s21_math_cos_16) {
  ck_assert_double_eq_tol(s21_cos(2 * M_PI), cosl(2 * M_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_sin_1) {
  ck_assert_double_eq_tol(s21_sin(0), sinl(0), 1e-06);
}
END_TEST

START_TEST(s21_math_sin_2) { ck_assert_ldouble_nan(s21_sin(-INFINITY)); }
END_TEST

START_TEST(s21_math_sin_3) { ck_assert_ldouble_nan(sinl(-INFINITY)); }
END_TEST

START_TEST(s21_math_sin_4) { ck_assert_ldouble_nan(s21_sin(INFINITY)); }
END_TEST

START_TEST(s21_math_sin_5) { ck_assert_ldouble_nan(sinl(INFINITY)); }
END_TEST

START_TEST(s21_math_sin_6) { ck_assert_ldouble_nan(s21_sin(NAN)); }
END_TEST

START_TEST(s21_math_sin_7) { ck_assert_ldouble_nan(sinl(NAN)); }
END_TEST

START_TEST(s21_math_sin_8) {
  ck_assert_double_eq_tol(s21_sin(0.0), sin(0.0), 1e-06);
}
END_TEST

START_TEST(s21_math_sin_9) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 6), sin(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(s21_math_sin_10) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 4), sin(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(s21_math_sin_11) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 3), sin(M_PI / 3), 1e-06);
}
END_TEST

START_TEST(s21_math_sin_12) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 2), sin(M_PI / 2), 1e-06);
}
END_TEST

START_TEST(s21_math_sin_13) {
  ck_assert_double_eq_tol(s21_sin(3 * M_PI / 2), sin(3 * M_PI / 2), 1e-06);
}
END_TEST

START_TEST(s21_math_sin_14) {
  ck_assert_double_eq_tol(s21_sin(2 * M_PI), sin(2 * M_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_sin_15) {
  ck_assert_double_eq_tol(s21_sin(-2 * M_PI), sin(-2 * M_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_sin_16) {
  ck_assert_double_eq_tol(s21_sin(-3 * M_PI), sin(-3 * M_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_sin_17) {
  ck_assert_double_eq_tol(s21_sin(-S21_PI), sin(-S21_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_1) {
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
  ck_assert_ldouble_nan(tan(-INFINITY));
}
END_TEST

START_TEST(s21_math_tan_2) {
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(tan(INFINITY));
}
END_TEST

START_TEST(s21_math_tan_3) {
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(tan(NAN));
}
END_TEST

START_TEST(s21_math_tan_4) {
  ck_assert_double_eq_tol(s21_tan(0.0), tanl(0.0), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_5) {
  ck_assert_double_eq_tol(s21_tan(M_PI / 6), tanl(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_6) {
  ck_assert_double_eq_tol(s21_tan(M_PI / 4), tanl(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_7) {
  ck_assert_double_eq_tol(s21_tan(-2 * M_PI), tanl(-2 * M_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_8) {
  ck_assert_double_eq_tol(s21_tan(M_PI), tanl(M_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_9) {
  ck_assert_double_eq_tol(s21_tan(M_PI / 3), tanl(M_PI / 3), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_10) {
  ck_assert_double_eq_tol(s21_tan(3 * M_PI / 2), tanl(3 * M_PI / 2), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_11) {
  ck_assert_double_eq_tol(s21_tan(-M_PI), tanl(-M_PI), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_12) {
  ck_assert_double_eq_tol(s21_tan(-M_PI / 3), tanl(-M_PI / 3), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_13) {
  ck_assert_double_eq_tol(s21_tan(-174.532925199433), tanl(-174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(s21_math_tan_14) {
  ck_assert_double_eq_tol(s21_tan(174.532925199433), tanl(174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(s21_math_tan_15) {
  ck_assert_double_eq_tol(s21_tan(S21_PI / 2), tanl(S21_PI / 2), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_16) {
  ck_assert_double_eq_tol(s21_tan(-S21_PI / 2), tanl(-S21_PI / 2), 1e-06);
}
END_TEST

START_TEST(s21_math_tan_17) {
  ck_assert_float_eq(s21_tan(-15.01), tan(-15.01));
}
END_TEST

START_TEST(s21_math_tan_18) {
  ck_assert_float_eq(s21_tan(0.00001), tan(0.00001));
}
END_TEST

Suite *s21_cos_sin_tan_suite(void) {
  Suite *s = suite_create("s21_cos_sin_tan");
  TCase *tc_cos, *tc_sin, *tc_tan;

  tc_cos = tcase_create("s21_math_cos\n");
  tcase_add_test(tc_cos, s21_math_cos_1);
  tcase_add_test(tc_cos, s21_math_cos_2);
  tcase_add_test(tc_cos, s21_math_cos_3);
  tcase_add_test(tc_cos, s21_math_cos_4);
  tcase_add_test(tc_cos, s21_math_cos_5);
  tcase_add_test(tc_cos, s21_math_cos_6);
  tcase_add_test(tc_cos, s21_math_cos_7);
  tcase_add_test(tc_cos, s21_math_cos_8);
  tcase_add_test(tc_cos, s21_math_cos_9);
  tcase_add_test(tc_cos, s21_math_cos_10);
  tcase_add_test(tc_cos, s21_math_cos_11);
  tcase_add_test(tc_cos, s21_math_cos_12);
  tcase_add_test(tc_cos, s21_math_cos_13);
  tcase_add_test(tc_cos, s21_math_cos_14);
  tcase_add_test(tc_cos, s21_math_cos_15);
  tcase_add_test(tc_cos, s21_math_cos_16);
  suite_add_tcase(s, tc_cos);

  tc_sin = tcase_create("s21_math_sin\n");
  tcase_add_test(tc_sin, s21_math_sin_1);
  tcase_add_test(tc_sin, s21_math_sin_2);
  tcase_add_test(tc_sin, s21_math_sin_3);
  tcase_add_test(tc_sin, s21_math_sin_4);
  tcase_add_test(tc_sin, s21_math_sin_5);
  tcase_add_test(tc_sin, s21_math_sin_6);
  tcase_add_test(tc_sin, s21_math_sin_7);
  tcase_add_test(tc_sin, s21_math_sin_8);
  tcase_add_test(tc_sin, s21_math_sin_9);
  tcase_add_test(tc_sin, s21_math_sin_10);
  tcase_add_test(tc_sin, s21_math_sin_11);
  tcase_add_test(tc_sin, s21_math_sin_12);
  tcase_add_test(tc_sin, s21_math_sin_13);
  tcase_add_test(tc_sin, s21_math_sin_14);
  tcase_add_test(tc_sin, s21_math_sin_15);
  tcase_add_test(tc_sin, s21_math_sin_16);
  tcase_add_test(tc_sin, s21_math_sin_17);
  suite_add_tcase(s, tc_sin);

  tc_tan = tcase_create("s21_math_tan\n");
  tcase_add_test(tc_tan, s21_math_tan_1);
  tcase_add_test(tc_tan, s21_math_tan_2);
  tcase_add_test(tc_tan, s21_math_tan_3);
  tcase_add_test(tc_tan, s21_math_tan_4);
  tcase_add_test(tc_tan, s21_math_tan_5);
  tcase_add_test(tc_tan, s21_math_tan_6);
  tcase_add_test(tc_tan, s21_math_tan_7);
  tcase_add_test(tc_tan, s21_math_tan_8);
  tcase_add_test(tc_tan, s21_math_tan_9);
  tcase_add_test(tc_tan, s21_math_tan_10);
  tcase_add_test(tc_tan, s21_math_tan_11);
  tcase_add_test(tc_tan, s21_math_tan_12);
  tcase_add_test(tc_tan, s21_math_tan_13);
  tcase_add_test(tc_tan, s21_math_tan_14);
  tcase_add_test(tc_tan, s21_math_tan_15);
  tcase_add_test(tc_tan, s21_math_tan_16);
  tcase_add_test(tc_tan, s21_math_tan_17);
  tcase_add_test(tc_tan, s21_math_tan_18);
  suite_add_tcase(s, tc_tan);

  return s;
}
