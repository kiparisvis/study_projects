#include "s21_math.h"
#include "tests/s21_math_tests.h"

int main(void) {
  setlocale(LC_ALL, "en_US.UTF-8");
  int failed = 0;
  Suite *abs, *exp, *pow;
  Suite *acos_asin_atan;
  Suite *ceil_fmod_log;
  Suite *cos_sin_tan;
  Suite *fabs_floor_sqrt;
  SRunner *runner;

  abs = s21_abs_suite();
  exp = s21_exp_suite();
  pow = s21_pow_suite();

  acos_asin_atan = s21_acos_asin_atan_suite();

  ceil_fmod_log = s21_ceil_fmod_log_suite();

  cos_sin_tan = s21_cos_sin_tan_suite();

  fabs_floor_sqrt = s21_fabs_floor_sqrt_suite();

  runner = srunner_create(abs);
  srunner_add_suite(runner, exp);
  srunner_add_suite(runner, pow);
  srunner_add_suite(runner, acos_asin_atan);
  srunner_add_suite(runner, ceil_fmod_log);
  srunner_add_suite(runner, cos_sin_tan);
  srunner_add_suite(runner, fabs_floor_sqrt);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
