#ifndef SRC_S21_1DECIMAL_DECIMAL_CREATE_DECIMAL_H_
#define SRC_S21_1DECIMAL_DECIMAL_CREATE_DECIMAL_H_

#include "../../s21_decimal.h"

int s21_is_correct_decimal(s21_decimal decimal);
int s21_decimal_get_sign(s21_decimal decimal);
int s21_decimal_get_power(s21_decimal decimal);
int s21_decimal_get_empty1(s21_decimal decimal);
int s21_decimal_get_empty2(s21_decimal decimal);
void s21_decimal_set_sign(s21_decimal *decimal, int sign);
void s21_decimal_set_power(s21_decimal *decimal, int power);
void s21_decimal_null_service_bits(s21_decimal *value);
int s21_even_or_odd(s21_decimal decimal);

s21_decimal s21_create_decimal_from_array(int data0, int data1, int data2,
                                          int data3);
s21_decimal s21_create_decimal_from_data(int sign, int power, int data0,
                                         int data1, int data2);
s21_decimal s21_create_decimal_from_strings(char *str0, char *str1, char *str2,
                                            char *str3);
int s21_decimal_set_bits_from_string(int *bits, char *str);
void s21_clear_decimal(s21_decimal *decimal);
s21_decimal s21_decimal_get_zero(void);
s21_decimal s21_decimal_get_one(void);
s21_decimal s21_decimal_get_five(void);
s21_decimal s21_decimal_get_ten(void);
s21_decimal s21_decimal_get_ten_pow(int pow);
s21_decimal s21_decimal_get_int_max(void);
s21_decimal s21_decimal_get_int_min(void);
s21_decimal s21_decimal_get_inf(void);

s21_decimal s21_decimal_add_mantissa(s21_decimal a, s21_decimal b);
int s21_decimal_div_mantissa(s21_decimal div, s21_decimal div2,
                             s21_decimal *res, s21_decimal *rem);
s21_decimal s21_decimal_shift_mantissa_left(s21_decimal decimal, int index,
                                            s21_decimal *result);
s21_decimal s21_decimal_shift_mantissa_right(s21_decimal decimal, int index);
int s21_decimal_mantissa_is_zero(s21_decimal decimal);

static const s21_decimal all_ten_pows[29] = {
    [0] = {{0x1, 0x0, 0x0, 0x0}},
    [1] = {{0xA, 0x0, 0x0, 0x0}},
    [2] = {{0x64, 0x0, 0x0, 0x0}},
    [3] = {{0x3E8, 0x0, 0x0, 0x0}},
    [4] = {{0x2710, 0x0, 0x0, 0x0}},
    [5] = {{0x186A0, 0x0, 0x0, 0x0}},
    [6] = {{0xF4240, 0x0, 0x0, 0x0}},
    [7] = {{0x989680, 0x0, 0x0, 0x0}},
    [8] = {{0x5F5E100, 0x0, 0x0, 0x0}},
    [9] = {{0x3B9ACA00, 0x0, 0x0, 0x0}},
    [10] = {{0x540BE400, 0x2, 0x0, 0x0}},
    [11] = {{0x4876E800, 0x17, 0x0, 0x0}},
    [12] = {{0xD4A51000, 0xE8, 0x0, 0x0}},
    [13] = {{0x4E72A000, 0x918, 0x0, 0x0}},
    [14] = {{0x107A4000, 0x5AF3, 0x0, 0x0}},
    [15] = {{0xA4C68000, 0x38D7E, 0x0, 0x0}},
    [16] = {{0x6FC10000, 0x2386F2, 0x0, 0x0}},
    [17] = {{0x5D8A0000, 0x1634578, 0x0, 0x0}},
    [18] = {{0xA7640000, 0xDE0B6B3, 0x0, 0x0}},
    [19] = {{0x89E80000, 0x8AC72304, 0x0, 0x0}},
    [20] = {{0x63100000, 0x6BC75E2D, 0x5, 0x0}},
    [21] = {{0xDEA00000, 0x35C9ADC5, 0x36, 0x0}},
    [22] = {{0xB2400000, 0x19E0C9BA, 0x21E, 0x0}},
    [23] = {{0xF6800000, 0x2C7E14A, 0x152D, 0x0}},
    [24] = {{0xA1000000, 0x1BCECCED, 0xD3C2, 0x0}},
    [25] = {{0x4A000000, 0x16140148, 0x84595, 0x0}},
    [26] = {{0xE4000000, 0xDCC80CD2, 0x52B7D2, 0x0}},
    [27] = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x0}},
    [28] = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}},
};

#endif  //  SRC_S21_DECIMAL_DECIMAL_CREATE_DECIMAL_H_
