#include "s21_math_tests.h"

START_TEST(abs_test_1) {
  int x = 0;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_2) {
  int x = 1;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_3) {
  int x = -1;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_4) {
  int x = -2147483648;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_5) {
  int x = 2147483647;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_6) {
  int x = 21;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_7) {
  int x = 47;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

Suite *s21_abs_suite(void) {
  Suite *s;
  TCase *tc_zero, *tc_posit_int, *tc_negat_int, *tc_posit_long, *tc_negat_long;

  s = suite_create("s21_abs");

  tc_zero = tcase_create("s21_Zero");
  tcase_add_test(tc_zero, abs_test_1);
  suite_add_tcase(s, tc_zero);

  tc_posit_int = tcase_create("s21_Positive_Int");
  tcase_add_test(tc_posit_int, abs_test_2);
  tcase_add_test(tc_posit_int, abs_test_5);
  suite_add_tcase(s, tc_posit_int);

  tc_negat_int = tcase_create("s21_Negative_Int");
  tcase_add_test(tc_negat_int, abs_test_3);
  tcase_add_test(tc_negat_int, abs_test_4);
  suite_add_tcase(s, tc_negat_int);

  tc_posit_long = tcase_create("s21_Positive_Long");
  tcase_add_test(tc_posit_long, abs_test_7);
  suite_add_tcase(s, tc_posit_long);

  tc_negat_long = tcase_create("s21_Negative_Long");
  tcase_add_test(tc_negat_long, abs_test_6);
  suite_add_tcase(s, tc_negat_long);

  return s;
}
