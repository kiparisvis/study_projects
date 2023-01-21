#ifndef SRC_TESTS_S21_MATH_TESTS_H_
#define SRC_TESTS_S21_MATH_TESTS_H_

#include <locale.h>

#include <math.h>

#include <check.h>

#include "../s21_math.h"

#define S21_EPS 1e-06
#define S21_EPS_B 1

Suite *s21_abs_suite(void);
Suite *s21_exp_suite(void);
Suite *s21_pow_suite(void);

Suite *s21_acos_asin_atan_suite(void);

Suite *s21_ceil_fmod_log_suite(void);

Suite *s21_cos_sin_tan_suite(void);

Suite *s21_fabs_floor_sqrt_suite(void);

#endif  // SRC_TESTS_S21_MATH_TESTS_H_
