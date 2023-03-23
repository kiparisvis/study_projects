#include "tests.h"

START_TEST(test_1) {
  char infix_string[255] = "1+2-3*4";
  double answer = calc_infix_string_without_x(infix_string);
  double ch = 1 + 2 - 3 * 4;
  ck_assert_double_eq_tol(answer, ch, 1e-07);
}
END_TEST

START_TEST(test_2) {
  char infix_string[255] = "-1modcos(1)+acos(1)";
  double answer = calc_infix_string_without_x(infix_string);
  double ch = fmod(-1, cos(1)) + acos(1);
  ck_assert_double_eq_tol(answer, ch, 1e-07);
}
END_TEST

START_TEST(test_3) {
  char infix_string[255] = "+sqrt(4)^3-log(2)/ln(4)";
  double answer = calc_infix_string_without_x(infix_string);
  double ch = pow(sqrt(4), 3) - log10(2) / log(4);
  ck_assert_double_eq_tol(answer, ch, 1e-07);
}
END_TEST

START_TEST(test_4) {
  char infix_string[255] = "sin(+x)*asin(1)*atan(2)*tan(1)";
  double answer = calc_infix_string_with_x(infix_string, 1);
  double ch = sin(1) * asin(1) * atan(2) * tan(1);
  ck_assert_double_eq_tol(answer, ch, 1e-07);
}
END_TEST

START_TEST(test_5) {
  char infix_string[255] = "1.8";
  double answer = calc_infix_string_without_x(infix_string);
  double ch = 1.8;
  ck_assert_double_eq_tol(answer, ch, 1e-07);
}
END_TEST

int main(void) {
  Suite *s = suite_create("suite_polish_tests");
  TCase *tc = tcase_create("polish_tests");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);

  suite_add_tcase(s, tc);

  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
  return 0;
}
