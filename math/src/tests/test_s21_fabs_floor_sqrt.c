#include "s21_math_tests.h"

START_TEST(MATH_TEST_FABS_1) {
  double meaning = 1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_2) {
  double meaning = -1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_3) {
  double meaning = -0;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_4) {
  double meaning = 0;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_5) {
  double meaning = S21_NAN;
  double numberS21 = 0;
  numberS21 = s21_fabs(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_FABS_6) {
  double meaning = -S21_NAN;
  double numberS21 = 0;
  numberS21 = s21_fabs(meaning);
  ck_assert(isnan(numberS21) > 0);
}
END_TEST

START_TEST(MATH_TEST_FABS_7) {
  double meaning = S21_INFINITY;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_8) {
  double meaning = -INFINITY;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_9) {
  double meaning = -9999;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_10) {
  double meaning = 1.79769e+308;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_11) {
  double meaning = -1.79769e+308;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_12) {
  double meaning = 2.22507e-308;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_13) {
  double meaning = -2.22507e-308;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_14) {
  double meaning = 0.1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_15) {
  double meaning = -0.1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_16) {
  double meaning = 0.00000008;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_17) {
  double meaning = -0.00000008;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_18) {
  double meaning = 0.0;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_19) {
  double meaning = -0.0;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_20) {
  double meaning = 349587322;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_21) {
  double meaning = -349587322;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_22) {
  double meaning = 212.22507e-308;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FABS_23) {
  double meaning = -1.79769e+308;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_fabs(meaning);
  number = fabs(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

// FLOOOR TEST

START_TEST(MATH_TEST_FLOOR_1) {
  double meaning = 0;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_2) {
  double meaning = -0;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_3) {
  double meaning = 1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_4) {
  double meaning = -1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_5) {
  double meaning = 0.1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_6) {
  double meaning = -0.1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_7) {
  double meaning = 1.1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_8) {
  double meaning = -1.1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_9) {
  double meaning = 13423.9865;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_10) {
  double meaning = -13423.9865;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_11) {
  double meaning = S21_NAN;
  double numberS21 = 0;
  numberS21 = s21_floor(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_FLOOR_12) {
  double meaning = -S21_NAN;
  double numberS21 = 0;
  numberS21 = s21_floor(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_FLOOR_13) {
  double meaning = INFINITY;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_14) {
  double meaning = -INFINITY;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_15) {
  double meaning = 1.79769e+30;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_16) {
  double meaning = -1.79769e+30;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_17) {
  double meaning = 2.22507e-308;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_18) {
  double meaning = -2.22507e-308;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_19) {
  double meaning = 0.000008;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_FLOOR_20) {
  double meaning = -0.000008;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_floor(meaning);
  number = floor(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_SQRT_1) {
  double meaning = 1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq_tol(numberS21, number, 1e-6);
}
END_TEST

START_TEST(MATH_TEST_SQRT_2) {
  double meaning = -1;
  double numberS21 = 0;
  numberS21 = s21_sqrt(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_SQRT_3) {
  double meaning = -0;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_SQRT_4) {
  double meaning = 0;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_SQRT_5) {
  double meaning = S21_NAN;
  double numberS21 = 0;
  numberS21 = s21_fabs(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_SQRT_6) {
  double meaning = -S21_NAN;
  double numberS21 = 0;
  numberS21 = s21_sqrt(meaning);
  ck_assert(isnan(numberS21) > 0);
}
END_TEST

START_TEST(MATH_TEST_SQRT_7) {
  double meaning = INFINITY;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_SQRT_8) {
  double meaning = -INFINITY;
  double numberS21 = 0;
  numberS21 = s21_sqrt(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_SQRT_9) {
  double meaning = -9999;
  double numberS21 = 0;
  numberS21 = s21_sqrt(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_SQRT_10) {
  double meaning = 1.79769;
  long double numberS21 = 0;
  long double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq_tol(numberS21, number, 1e-6);
}
END_TEST

START_TEST(MATH_TEST_SQRT_11) {
  double meaning = -1.79769e+308;
  double numberS21 = 0;
  numberS21 = s21_sqrt(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_SQRT_12) {
  double meaning = 2.22507e-308;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq_tol(numberS21, number, 1e-6);
}
END_TEST

START_TEST(MATH_TEST_SQRT_13) {
  double meaning = -2.22507e-308;
  double numberS21 = 0;
  numberS21 = s21_sqrt(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_SQRT_14) {
  double meaning = 0.1;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq_tol(numberS21, number, 1e-6);
}
END_TEST

START_TEST(MATH_TEST_SQRT_15) {
  double meaning = -0.1;
  double numberS21 = 0;
  numberS21 = s21_sqrt(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_SQRT_16) {
  double meaning = 0.00000008;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq_tol(numberS21, number, 1e-6);
}
END_TEST

START_TEST(MATH_TEST_SQRT_17) {
  double meaning = -0.00000008;
  double numberS21 = 0;
  numberS21 = s21_sqrt(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_SQRT_18) {
  double meaning = 0.0;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_SQRT_19) {
  double meaning = -0.0;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq(numberS21, number);
}
END_TEST

START_TEST(MATH_TEST_SQRT_20) {
  double meaning = 349587322;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq_tol(numberS21, number, 1e-6);
}
END_TEST

START_TEST(MATH_TEST_SQRT_21) {
  double meaning = -349587322;
  double numberS21 = 0;
  numberS21 = s21_sqrt(meaning);
  ck_assert(isnan(numberS21));
}
END_TEST

START_TEST(MATH_TEST_SQRT_22) {
  double meaning = 212.22507e-308;
  double numberS21 = 0;
  double number = 0;
  numberS21 = s21_sqrt(meaning);
  number = sqrt(meaning);
  ck_assert_double_eq_tol(numberS21, number, 1e-6);
}
END_TEST

START_TEST(MATH_TEST_SQRT_23) {
  for (double meaning = 0; meaning < 21; meaning += 3) {
    double numberS21 = s21_sqrt(meaning);
    double number = sqrt(meaning);
    ck_assert_double_eq_tol(numberS21, number, 1e-6);
  }
}
END_TEST

Suite *s21_fabs_floor_sqrt_suite(void) {
  Suite *s = suite_create("s21_fabs_floor_sqrt");
  TCase *tc_fabs, *tc_cos, *tc_sqrt;

  tc_fabs = tcase_create("MATH_TEST_FABS\n");
  tcase_add_test(tc_fabs, MATH_TEST_FABS_1);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_2);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_3);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_4);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_5);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_6);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_7);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_8);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_9);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_10);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_11);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_12);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_13);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_14);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_15);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_16);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_17);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_18);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_19);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_20);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_21);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_22);
  tcase_add_test(tc_fabs, MATH_TEST_FABS_23);
  suite_add_tcase(s, tc_fabs);

  tc_cos = tcase_create("MATH_TEST_FLOOR\n");
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_1);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_2);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_3);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_4);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_5);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_6);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_7);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_8);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_9);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_10);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_11);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_12);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_13);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_14);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_15);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_16);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_17);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_18);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_19);
  tcase_add_test(tc_cos, MATH_TEST_FLOOR_20);
  suite_add_tcase(s, tc_cos);

  tc_sqrt = tcase_create("MATH_TEST_SQRT\n");
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_1);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_2);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_3);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_4);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_5);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_6);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_7);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_8);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_9);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_10);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_11);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_12);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_13);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_14);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_15);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_16);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_17);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_18);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_19);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_20);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_21);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_22);
  tcase_add_test(tc_sqrt, MATH_TEST_SQRT_23);
  suite_add_tcase(s, tc_sqrt);
  return s;
}
