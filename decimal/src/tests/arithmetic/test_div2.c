
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../s21_decimal.h"
#include "../test.h"

// #define __DEBUG

START_TEST(test_div401) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 9364712231340627836019760.832
  s21_decimal decimal_check = {{0x9ACD5EC0, 0x4BCA35AA, 0x1E424EF3, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div402) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -9364712231340627836019760.832
  s21_decimal decimal_check = {
      {0x9ACD5EC0, 0x4BCA35AA, 0x1E424EF3, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div403) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // 9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div404) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // -9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div405) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 79149013500763574019524425908
  s21_decimal decimal_check = {{0xFBE878B4, 0x6170458F, 0xFFBE878B, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div406) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // -79149013500763574019524425908
  s21_decimal decimal_check = {
      {0xFBE878B4, 0x6170458F, 0xFFBE878B, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div407) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div408) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div409) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395033.4
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div410) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759354395033.4
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div411) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div412) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div413) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div414) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div415) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // -55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div416) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // 55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div417) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // 21669104637638919604.083853925
  s21_decimal decimal_check = {{0x63478A65, 0x327B2965, 0x46044364, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div418) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // -21669104637638919604.083853925
  s21_decimal decimal_check = {
      {0x63478A65, 0x327B2965, 0x46044364, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div419) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // 126429998059967356684.63712959
  s21_decimal decimal_check = {{0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div420) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -126429998059967356684.63712959
  s21_decimal decimal_check = {
      {0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80080000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div421) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div422) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div423) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div424) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div425) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div426) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div427) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div428) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div429) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -1.9999999999999999998915797827
  s21_decimal decimal_check = {
      {0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div430) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 1.9999999999999999998915797827
  s21_decimal decimal_check = {{0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div431) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -1.9999999999999999999999999999
  s21_decimal decimal_check = {
      {0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div432) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal_check = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div433) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -19999999999999999999999999999
  s21_decimal decimal_check = {
      {0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div434) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 19999999999999999999999999999
  s21_decimal decimal_check = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div435) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // -18446744069414584320.999999999
  s21_decimal decimal_check = {
      {0x3B9AC9FF, 0xC4653600, 0x3B9AC9FF, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div436) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // 18446744069414584320.999999999
  s21_decimal decimal_check = {{0x3B9AC9FF, 0xC4653600, 0x3B9AC9FF, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div437) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // -1.0000000002328306436538696289
  s21_decimal decimal_check = {
      {0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div438) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000002328306436538696289
  s21_decimal decimal_check = {{0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div439) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // -18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div440) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // 18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div441) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // -36893488147419103231.999999999
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0x773593FF, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div442) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // 36893488147419103231.999999999
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x773593FF, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div443) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // -9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div444) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // 9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div445) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // -15845632502852867518708790067
  s21_decimal decimal_check = {
      {0x33333333, 0x33333333, 0x33333333, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div446) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 15845632502852867518708790067
  s21_decimal decimal_check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div447) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // -39614081257132168796771975167
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div448) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 39614081257132168796771975167
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div449) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div450) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div451) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div452) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div453) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950326
  s21_decimal decimal_check = {
      {0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div454) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950326
  s21_decimal decimal_check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div455) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div456) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div457) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div458) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div459) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div460) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div461) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div462) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div463) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -10000000000000000000000000000
  s21_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div464) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 10000000000000000000000000000
  s21_decimal decimal_check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div465) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // -1320469375237738959892399172.1
  s21_decimal decimal_check = {
      {0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div466) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // 1320469375237738959892399172.1
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div467) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div468) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div469) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div470) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div471) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div472) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div473) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // -1999999999534338.7126922607422
  s21_decimal decimal_check = {
      {0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0x800D0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div474) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 1999999999534338.7126922607422
  s21_decimal decimal_check = {{0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0xD0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div475) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // -1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div476) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // 1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div477) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // -368934881474191032319999.99999
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0x773593FF, 0x80050000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div478) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // 368934881474191032319999.99999
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x773593FF, 0x50000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div479) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div480) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // 1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div481) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div482) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div483) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // -55340232234013556738999999999
  s21_decimal decimal_check = {
      {0xB2D05DFF, 0xB2D05E00, 0xB2D05E00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div484) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // 55340232234013556738999999999
  s21_decimal decimal_check = {{0xB2D05DFF, 0xB2D05E00, 0xB2D05E00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div485) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -9364712231340627836019760.832
  s21_decimal decimal_check = {
      {0x9ACD5EC0, 0x4BCA35AA, 0x1E424EF3, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div486) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // 9364712231340627836019760.832
  s21_decimal decimal_check = {{0x9ACD5EC0, 0x4BCA35AA, 0x1E424EF3, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div487) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // -9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div488) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // 9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div489) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // -79149013500763574019524425908
  s21_decimal decimal_check = {
      {0xFBE878B4, 0x6170458F, 0xFFBE878B, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div490) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // 79149013500763574019524425908
  s21_decimal decimal_check = {{0xFBE878B4, 0x6170458F, 0xFFBE878B, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div491) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div492) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div493) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395033.4
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div494) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395033.4
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div495) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div496) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div497) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div498) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div499) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // 55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div500) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // -55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div501) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // -21669104637638919604.083853925
  s21_decimal decimal_check = {
      {0x63478A65, 0x327B2965, 0x46044364, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div502) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // 21669104637638919604.083853925
  s21_decimal decimal_check = {{0x63478A65, 0x327B2965, 0x46044364, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div503) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // -126429998059967356684.63712959
  s21_decimal decimal_check = {
      {0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80080000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div504) {
  // -79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 126429998059967356684.63712959
  s21_decimal decimal_check = {{0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div505) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.3333333333333333333333333333
  s21_decimal decimal_check = {{0x5555555, 0x14B700CB, 0xAC544CA, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div506) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.3333333333333333333333333333
  s21_decimal decimal_check = {{0x5555555, 0x14B700CB, 0xAC544CA, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div507) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 3.3333333333333333333333333333
  s21_decimal decimal_check = {{0x35555555, 0xCF2607EE, 0x6BB4AFE4, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div508) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -3.3333333333333333333333333333
  s21_decimal decimal_check = {
      {0x35555555, 0xCF2607EE, 0x6BB4AFE4, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div509) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.3333333333333333333333333333
  s21_decimal decimal_check = {{0x5555555, 0x14B700CB, 0xAC544CA, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div510) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.3333333333333333333333333333
  s21_decimal decimal_check = {{0x5555555, 0x14B700CB, 0xAC544CA, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div511) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div512) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div513) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.6666666666666666666305265942
  s21_decimal decimal_check = {{0xF5202116, 0x296E0195, 0x158A8994, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div514) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.6666666666666666666305265942
  s21_decimal decimal_check = {
      {0xF5202116, 0x296E0195, 0x158A8994, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div515) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.6666666666666666666666666667
  s21_decimal decimal_check = {{0xAAAAAAB, 0x296E0196, 0x158A8994, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div516) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.6666666666666666666666666667
  s21_decimal decimal_check = {{0xAAAAAAB, 0x296E0196, 0x158A8994, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div517) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 6666666666666666666666666666.6
  s21_decimal decimal_check = {{0x6AAAAAAA, 0x9E4C0FDC, 0xD7695FC9, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div518) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -6666666666666666666666666666.6
  s21_decimal decimal_check = {
      {0x6AAAAAAA, 0x9E4C0FDC, 0xD7695FC9, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div519) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 6148914689804861440.3333333332
  s21_decimal decimal_check = {{0xC6AEA154, 0x8EA6B400, 0xC6AEA154, 0xA0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div520) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // -6148914689804861440.3333333332
  s21_decimal decimal_check = {
      {0xC6AEA154, 0x8EA6B400, 0xC6AEA154, 0x800A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div521) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 0.3333333334109435478846232096
  s21_decimal decimal_check = {{0x1A0C5620, 0x1F7C4595, 0xAC544CA, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div522) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -0.3333333334109435478846232096
  s21_decimal decimal_check = {{0x1A0C5620, 0x1F7C4595, 0xAC544CA, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div523) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 6148914691236517205.3333333333
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0xC6AEA155, 0xA0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div524) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -6148914691236517205.3333333333
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0xC6AEA155, 0x800A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div525) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 12297829382473034410.666666667
  s21_decimal decimal_check = {{0xAAAAAAAB, 0xAAAAAAAA, 0x27BC86AA, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div526) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -12297829382473034410.666666667
  s21_decimal decimal_check = {
      {0xAAAAAAAB, 0xAAAAAAAA, 0x27BC86AA, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div527) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 3074457345976172544.0416666666
  s21_decimal decimal_check = {{0x18D5D42A, 0xDC565300, 0x635750AA, 0xA0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div528) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -3074457345976172544.0416666666
  s21_decimal decimal_check = {
      {0x18D5D42A, 0xDC565300, 0x635750AA, 0x800A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div529) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // 5281877500950955839569596689
  s21_decimal decimal_check = {{0x11111111, 0x11111111, 0x11111111, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div530) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -5281877500950955839569596689
  s21_decimal decimal_check = {
      {0x11111111, 0x11111111, 0x11111111, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div531) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 13204693752377389598923991722
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div532) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -13204693752377389598923991722
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div533) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 13204693752377389598923992383
  s21_decimal decimal_check = {{0xAAAAAD3F, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div534) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -13204693752377389598923992383
  s21_decimal decimal_check = {
      {0xAAAAAD3F, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div535) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 13204693752377389598923991723
  s21_decimal decimal_check = {{0xAAAAAAAB, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div536) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -13204693752377389598923991723
  s21_decimal decimal_check = {
      {0xAAAAAAAB, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div537) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 26409387504754779197847983442
  s21_decimal decimal_check = {{0x55555552, 0x55555555, 0x55555555, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div538) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -26409387504754779197847983442
  s21_decimal decimal_check = {
      {0x55555552, 0x55555555, 0x55555555, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div539) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div540) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div541) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div542) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div543) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div544) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div545) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 26409387504754779197847983448
  s21_decimal decimal_check = {{0x55555558, 0x55555555, 0x55555555, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div546) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -26409387504754779197847983448
  s21_decimal decimal_check = {
      {0x55555558, 0x55555555, 0x55555555, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div547) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 3333333333333333333333333333.3
  s21_decimal decimal_check = {{0x35555555, 0xCF2607EE, 0x6BB4AFE4, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div548) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -3333333333333333333333333333.3
  s21_decimal decimal_check = {
      {0x35555555, 0xCF2607EE, 0x6BB4AFE4, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div549) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 440156458412579653297466390.71
  s21_decimal decimal_check = {{0xE38E38DF, 0x38E38E38, 0x8E38E38E, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div550) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // -440156458412579653297466390.71
  s21_decimal decimal_check = {
      {0xE38E38DF, 0x38E38E38, 0x8E38E38E, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div551) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 52818775009509558395695966890
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div552) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -52818775009509558395695966890
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div553) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div554) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div555) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div556) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div557) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 666666666511446.23756408691406
  s21_decimal decimal_check = {{0xCC5E9ACE, 0xC6E2B012, 0xD7695FC8, 0xE0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div558) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -666666666511446.23756408691406
  s21_decimal decimal_check = {
      {0xCC5E9ACE, 0xC6E2B012, 0xD7695FC8, 0x800E0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div559) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 614891469123651720533333333.33
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0xC6AEA155, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div560) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // -614891469123651720533333333.33
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0xC6AEA155, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div561) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 122978293824730344106666.66667
  s21_decimal decimal_check = {{0xAAAAAAAB, 0xAAAAAAAA, 0x27BC86AA, 0x50000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div562) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // -122978293824730344106666.66667
  s21_decimal decimal_check = {
      {0xAAAAAAAB, 0xAAAAAAAA, 0x27BC86AA, 0x80050000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div563) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 614891469266817297100000000
  s21_decimal decimal_check = {{0xACA74B00, 0x5751F5AA, 0x1FCA055, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div564) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // -614891469266817297100000000
  s21_decimal decimal_check = {{0xACA74B00, 0x5751F5AA, 0x1FCA055, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div565) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // 26412028707625541752023185764
  s21_decimal decimal_check = {{0x10307964, 0x3A54C753, 0x555784A1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div566) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // -26412028707625541752023185764
  s21_decimal decimal_check = {
      {0x10307964, 0x3A54C753, 0x555784A1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div567) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // 18446744078004518913000000000
  s21_decimal decimal_check = {{0x3B9ACA00, 0x3B9ACA00, 0x3B9ACA00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div568) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // -18446744078004518913000000000
  s21_decimal decimal_check = {
      {0x3B9ACA00, 0x3B9ACA00, 0x3B9ACA00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div569) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 3121570743780209278673253.6109
  s21_decimal decimal_check = {{0xAEAC912D, 0xFCA20838, 0x64DD072A, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div570) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -3121570743780209278673253.6109
  s21_decimal decimal_check = {
      {0xAEAC912D, 0xFCA20838, 0x64DD072A, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div571) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // 3301173438094347399730997930.6
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x6AAAAAAA, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div572) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // -3301173438094347399730997930.6
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0x6AAAAAAA, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div573) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 26383004500254524673174808636
  s21_decimal decimal_check = {{0x53F8283C, 0xCB256C85, 0x553F8283, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div574) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // -26383004500254524673174808636
  s21_decimal decimal_check = {
      {0x53F8283C, 0xCB256C85, 0x553F8283, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div575) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // 26409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div576) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -26409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div577) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // 2640938750475477919784798344.5
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div578) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // -2640938750475477919784798344.5
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div579) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div580) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div581) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div582) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div583) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // -18.48021425833517128808506113
  s21_decimal decimal_check = {{0xF8F9A301, 0x3C032447, 0x5F8A5C2, 0x801A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div584) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // 18.48021425833517128808506113
  s21_decimal decimal_check = {{0xF8F9A301, 0x3C032447, 0x5F8A5C2, 0x1A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div585) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // 7223034879212973201.3612846418
  s21_decimal decimal_check = {{0xA043CD52, 0xFD9A89FC, 0xE9638B4D, 0xA0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div586) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // -7223034879212973201.3612846418
  s21_decimal decimal_check = {
      {0xA043CD52, 0xFD9A89FC, 0xE9638B4D, 0x800A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div587) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // 42143332686655785561.545709863
  s21_decimal decimal_check = {{0xA93B1927, 0xBB8A4640, 0x882C25D2, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div588) {
  // 26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -42143332686655785561.545709863
  s21_decimal decimal_check = {
      {0xA93B1927, 0xBB8A4640, 0x882C25D2, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div589) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.3333333333333333333333333333
  s21_decimal decimal_check = {{0x5555555, 0x14B700CB, 0xAC544CA, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div590) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.3333333333333333333333333333
  s21_decimal decimal_check = {{0x5555555, 0x14B700CB, 0xAC544CA, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div591) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -3.3333333333333333333333333333
  s21_decimal decimal_check = {
      {0x35555555, 0xCF2607EE, 0x6BB4AFE4, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div592) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 3.3333333333333333333333333333
  s21_decimal decimal_check = {{0x35555555, 0xCF2607EE, 0x6BB4AFE4, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div593) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.3333333333333333333333333333
  s21_decimal decimal_check = {{0x5555555, 0x14B700CB, 0xAC544CA, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div594) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.3333333333333333333333333333
  s21_decimal decimal_check = {{0x5555555, 0x14B700CB, 0xAC544CA, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div595) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div596) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div597) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.6666666666666666666305265942
  s21_decimal decimal_check = {
      {0xF5202116, 0x296E0195, 0x158A8994, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div598) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.6666666666666666666305265942
  s21_decimal decimal_check = {{0xF5202116, 0x296E0195, 0x158A8994, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div599) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.6666666666666666666666666667
  s21_decimal decimal_check = {{0xAAAAAAB, 0x296E0196, 0x158A8994, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div600) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.6666666666666666666666666667
  s21_decimal decimal_check = {{0xAAAAAAB, 0x296E0196, 0x158A8994, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div601) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -6666666666666666666666666666.6
  s21_decimal decimal_check = {
      {0x6AAAAAAA, 0x9E4C0FDC, 0xD7695FC9, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div602) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 6666666666666666666666666666.6
  s21_decimal decimal_check = {{0x6AAAAAAA, 0x9E4C0FDC, 0xD7695FC9, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div603) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // -6148914689804861440.3333333332
  s21_decimal decimal_check = {
      {0xC6AEA154, 0x8EA6B400, 0xC6AEA154, 0x800A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div604) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // 6148914689804861440.3333333332
  s21_decimal decimal_check = {{0xC6AEA154, 0x8EA6B400, 0xC6AEA154, 0xA0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div605) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // -0.3333333334109435478846232096
  s21_decimal decimal_check = {{0x1A0C5620, 0x1F7C4595, 0xAC544CA, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div606) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 0.3333333334109435478846232096
  s21_decimal decimal_check = {{0x1A0C5620, 0x1F7C4595, 0xAC544CA, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div607) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // -6148914691236517205.3333333333
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0xC6AEA155, 0x800A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div608) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // 6148914691236517205.3333333333
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0xC6AEA155, 0xA0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div609) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // -12297829382473034410.666666667
  s21_decimal decimal_check = {
      {0xAAAAAAAB, 0xAAAAAAAA, 0x27BC86AA, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div610) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // 12297829382473034410.666666667
  s21_decimal decimal_check = {{0xAAAAAAAB, 0xAAAAAAAA, 0x27BC86AA, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div611) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // -3074457345976172544.0416666666
  s21_decimal decimal_check = {
      {0x18D5D42A, 0xDC565300, 0x635750AA, 0x800A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div612) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // 3074457345976172544.0416666666
  s21_decimal decimal_check = {{0x18D5D42A, 0xDC565300, 0x635750AA, 0xA0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div613) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // -5281877500950955839569596689
  s21_decimal decimal_check = {
      {0x11111111, 0x11111111, 0x11111111, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div614) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 5281877500950955839569596689
  s21_decimal decimal_check = {{0x11111111, 0x11111111, 0x11111111, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div615) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // -13204693752377389598923991722
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div616) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 13204693752377389598923991722
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div617) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -13204693752377389598923992383
  s21_decimal decimal_check = {
      {0xAAAAAD3F, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div618) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 13204693752377389598923992383
  s21_decimal decimal_check = {{0xAAAAAD3F, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div619) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -13204693752377389598923991723
  s21_decimal decimal_check = {
      {0xAAAAAAAB, 0xAAAAAAAA, 0x2AAAAAAA, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div620) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 13204693752377389598923991723
  s21_decimal decimal_check = {{0xAAAAAAAB, 0xAAAAAAAA, 0x2AAAAAAA, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div621) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -26409387504754779197847983442
  s21_decimal decimal_check = {
      {0x55555552, 0x55555555, 0x55555555, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div622) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 26409387504754779197847983442
  s21_decimal decimal_check = {{0x55555552, 0x55555555, 0x55555555, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div623) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div624) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div625) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div626) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div627) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div628) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div629) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -26409387504754779197847983448
  s21_decimal decimal_check = {
      {0x55555558, 0x55555555, 0x55555555, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div630) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 26409387504754779197847983448
  s21_decimal decimal_check = {{0x55555558, 0x55555555, 0x55555555, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div631) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -3333333333333333333333333333.3
  s21_decimal decimal_check = {
      {0x35555555, 0xCF2607EE, 0x6BB4AFE4, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div632) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 3333333333333333333333333333.3
  s21_decimal decimal_check = {{0x35555555, 0xCF2607EE, 0x6BB4AFE4, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div633) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // -440156458412579653297466390.71
  s21_decimal decimal_check = {
      {0xE38E38DF, 0x38E38E38, 0x8E38E38E, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div634) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // 440156458412579653297466390.71
  s21_decimal decimal_check = {{0xE38E38DF, 0x38E38E38, 0x8E38E38E, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div635) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -52818775009509558395695966890
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div636) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 52818775009509558395695966890
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div637) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div638) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div639) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div640) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div641) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // -666666666511446.23756408691406
  s21_decimal decimal_check = {
      {0xCC5E9ACE, 0xC6E2B012, 0xD7695FC8, 0x800E0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div642) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 666666666511446.23756408691406
  s21_decimal decimal_check = {{0xCC5E9ACE, 0xC6E2B012, 0xD7695FC8, 0xE0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div643) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // -614891469123651720533333333.33
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0xC6AEA155, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div644) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // 614891469123651720533333333.33
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0xC6AEA155, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div645) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // -122978293824730344106666.66667
  s21_decimal decimal_check = {
      {0xAAAAAAAB, 0xAAAAAAAA, 0x27BC86AA, 0x80050000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div646) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // 122978293824730344106666.66667
  s21_decimal decimal_check = {{0xAAAAAAAB, 0xAAAAAAAA, 0x27BC86AA, 0x50000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div647) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -614891469266817297100000000
  s21_decimal decimal_check = {{0xACA74B00, 0x5751F5AA, 0x1FCA055, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div648) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // 614891469266817297100000000
  s21_decimal decimal_check = {{0xACA74B00, 0x5751F5AA, 0x1FCA055, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div649) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // -26412028707625541752023185764
  s21_decimal decimal_check = {
      {0x10307964, 0x3A54C753, 0x555784A1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div650) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // 26412028707625541752023185764
  s21_decimal decimal_check = {{0x10307964, 0x3A54C753, 0x555784A1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div651) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // -18446744078004518913000000000
  s21_decimal decimal_check = {
      {0x3B9ACA00, 0x3B9ACA00, 0x3B9ACA00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div652) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // 18446744078004518913000000000
  s21_decimal decimal_check = {{0x3B9ACA00, 0x3B9ACA00, 0x3B9ACA00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div653) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -3121570743780209278673253.6109
  s21_decimal decimal_check = {
      {0xAEAC912D, 0xFCA20838, 0x64DD072A, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div654) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // 3121570743780209278673253.6109
  s21_decimal decimal_check = {{0xAEAC912D, 0xFCA20838, 0x64DD072A, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div655) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // -3301173438094347399730997930.6
  s21_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0x6AAAAAAA, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div656) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // 3301173438094347399730997930.6
  s21_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x6AAAAAAA, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div657) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // -26383004500254524673174808636
  s21_decimal decimal_check = {
      {0x53F8283C, 0xCB256C85, 0x553F8283, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div658) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // 26383004500254524673174808636
  s21_decimal decimal_check = {{0x53F8283C, 0xCB256C85, 0x553F8283, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div659) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // -26409387504754779197847983445
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div660) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 26409387504754779197847983445
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div661) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // -2640938750475477919784798344.5
  s21_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div662) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // 2640938750475477919784798344.5
  s21_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div663) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div664) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div665) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div666) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div667) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // 18.48021425833517128808506113
  s21_decimal decimal_check = {{0xF8F9A301, 0x3C032447, 0x5F8A5C2, 0x1A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div668) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // -18.48021425833517128808506113
  s21_decimal decimal_check = {{0xF8F9A301, 0x3C032447, 0x5F8A5C2, 0x801A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div669) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // -7223034879212973201.3612846418
  s21_decimal decimal_check = {
      {0xA043CD52, 0xFD9A89FC, 0xE9638B4D, 0x800A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div670) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // 7223034879212973201.3612846418
  s21_decimal decimal_check = {{0xA043CD52, 0xFD9A89FC, 0xE9638B4D, 0xA0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div671) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // -42143332686655785561.545709863
  s21_decimal decimal_check = {
      {0xA93B1927, 0xBB8A4640, 0x882C25D2, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div672) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 42143332686655785561.545709863
  s21_decimal decimal_check = {{0xA93B1927, 0xBB8A4640, 0x882C25D2, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div673) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000271050543
  s21_decimal decimal_check = {{0x9827E72F, 0x1F128130, 0x1027E72F, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div674) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000271050543
  s21_decimal decimal_check = {
      {0x9827E72F, 0x1F128130, 0x1027E72F, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div675) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 5.0000000000000000002710505432
  s21_decimal decimal_check = {{0xF18F07D8, 0x36B90BE5, 0xA18F07D7, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div676) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -5.0000000000000000002710505432
  s21_decimal decimal_check = {
      {0xF18F07D8, 0x36B90BE5, 0xA18F07D7, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div677) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5000000000000000000271050543
  s21_decimal decimal_check = {{0x9827E72F, 0x1F128130, 0x1027E72F, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div678) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000271050543
  s21_decimal decimal_check = {
      {0x9827E72F, 0x1F128130, 0x1027E72F, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div679) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.500000000000000000081315163
  s21_decimal decimal_check = {{0x60D8C55B, 0xEFB8C05B, 0x4D8C55A, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div680) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.500000000000000000081315163
  s21_decimal decimal_check = {{0x60D8C55B, 0xEFB8C05B, 0x4D8C55A, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div681) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div682) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div683) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 1.0000000000000000000542101086
  s21_decimal decimal_check = {{0x304FCE5E, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div684) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -1.0000000000000000000542101086
  s21_decimal decimal_check = {
      {0x304FCE5E, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div685) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 10000000000000000000542101086
  s21_decimal decimal_check = {{0x304FCE5E, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div686) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -10000000000000000000542101086
  s21_decimal decimal_check = {
      {0x304FCE5E, 0x3E250261, 0x204FCE5E, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div687) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 9223372034707292161
  s21_decimal decimal_check = {{0x80000001, 0x7FFFFFFF, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div688) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // -9223372034707292161
  s21_decimal decimal_check = {{0x80000001, 0x7FFFFFFF, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div689) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 0.5000000001164153218540398688
  s21_decimal decimal_check = {{0xB73A6860, 0x2F3A685F, 0x1027E72F, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div690) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000001164153218540398688
  s21_decimal decimal_check = {
      {0xB73A6860, 0x2F3A685F, 0x1027E72F, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div691) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 9223372036854775808.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x5, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div692) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -9223372036854775808.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x5, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div693) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 18446744073709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div694) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -18446744073709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div695) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 4611686018964258816.3125
  s21_decimal decimal_check = {{0xC35, 0x4E2, 0x9C4, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div696) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -4611686018964258816.3125
  s21_decimal decimal_check = {{0xC35, 0x4E2, 0x9C4, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div697) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // 7922816251426433759783891763
  s21_decimal decimal_check = {{0xB3333333, 0x99999999, 0x19999999, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div698) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759783891763
  s21_decimal decimal_check = {
      {0xB3333333, 0x99999999, 0x19999999, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div699) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 19807040628566084399459729408
  s21_decimal decimal_check = {{0x40000000, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div700) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -19807040628566084399459729408
  s21_decimal decimal_check = {{0x40000000, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div701) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 19807040628566084399459730398
  s21_decimal decimal_check = {{0x400003DE, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div702) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -19807040628566084399459730398
  s21_decimal decimal_check = {{0x400003DE, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div703) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 19807040628566084399459729409
  s21_decimal decimal_check = {{0x40000001, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div704) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -19807040628566084399459729409
  s21_decimal decimal_check = {{0x40000001, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div705) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 39614081257132168798919458812
  s21_decimal decimal_check = {{0x7FFFFFFC, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div706) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -39614081257132168798919458812
  s21_decimal decimal_check = {{0x7FFFFFFC, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div707) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div708) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div709) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div710) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div711) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div712) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div713) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 39614081257132168798919458820
  s21_decimal decimal_check = {{0x80000004, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div714) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -39614081257132168798919458820
  s21_decimal decimal_check = {{0x80000004, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div715) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 5000000000000000000271050543.2
  s21_decimal decimal_check = {{0xF18F07D8, 0x36B90BE5, 0xA18F07D7, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div716) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -5000000000000000000271050543.2
  s21_decimal decimal_check = {
      {0xF18F07D8, 0x36B90BE5, 0xA18F07D7, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div717) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 660234687618869479981990980.21
  s21_decimal decimal_check = {{0x2AAAAAA5, 0x55555556, 0xD5555555, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div718) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // -660234687618869479981990980.21
  s21_decimal decimal_check = {
      {0x2AAAAAA5, 0x55555556, 0xD5555555, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div719) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div720) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div721) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div722) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div723) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div724) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div725) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 999999999767169.3564003404797
  s21_decimal decimal_check = {{0xF22ACBFD, 0x1DD53402, 0x204FCE5E, 0xD0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div726) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -999999999767169.3564003404797
  s21_decimal decimal_check = {
      {0xF22ACBFD, 0x1DD53402, 0x204FCE5E, 0x800D0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div727) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 922337203685477580850000000
  s21_decimal decimal_check = {{0x2FAF080, 0x0, 0x2FAF080, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div728) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // -922337203685477580850000000
  s21_decimal decimal_check = {{0x2FAF080, 0x0, 0x2FAF080, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div729) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 184467440737095516170000
  s21_decimal decimal_check = {{0x2710, 0x0, 0x2710, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div730) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // -184467440737095516170000
  s21_decimal decimal_check = {{0x2710, 0x0, 0x2710, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div731) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 922337203900225945700000000
  s21_decimal decimal_check = {{0x5F5E100, 0x2FAF080, 0x2FAF080, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div732) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // -922337203900225945700000000
  s21_decimal decimal_check = {{0x5F5E100, 0x2FAF080, 0x2FAF080, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div733) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // 39618043061438312630182477064
  s21_decimal decimal_check = {{0x184BFD08, 0xD77F2AFD, 0x800346F1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div734) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // -39618043061438312630182477064
  s21_decimal decimal_check = {
      {0x184BFD08, 0xD77F2AFD, 0x800346F1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div735) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // 27670116117006778371000000001
  s21_decimal decimal_check = {{0xB2D05E01, 0x59682F00, 0x59682F00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div736) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // -27670116117006778371000000001
  s21_decimal decimal_check = {
      {0xB2D05E01, 0x59682F00, 0x59682F00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div737) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 4682356115670313918263711.45
  s21_decimal decimal_check = {{0x22DA6249, 0x5D63B5E2, 0x18350BF, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div738) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -4682356115670313918263711.45
  s21_decimal decimal_check = {{0x22DA6249, 0x5D63B5E2, 0x18350BF, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div739) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // 4951760157141521099864932352
  s21_decimal decimal_check = {{0x10000000, 0x0, 0x10000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div740) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // -4951760157141521099864932352
  s21_decimal decimal_check = {{0x10000000, 0x0, 0x10000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div741) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 39574506750381787011907551265
  s21_decimal decimal_check = {{0x7DD38021, 0xB0B822C8, 0x7FDF43C5, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div742) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // -39574506750381787011907551265
  s21_decimal decimal_check = {
      {0x7DD38021, 0xB0B822C8, 0x7FDF43C5, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div743) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // 39614081257132168798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div744) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -39614081257132168798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div745) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // 3961408125713216879891945881.6
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div746) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // -3961408125713216879891945881.6
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div747) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div748) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div749) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div750) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div751) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // -27.72032138750275693363031333
  s21_decimal decimal_check = {{0xFE6B6D25, 0x5A04B66B, 0x8F4F8A3, 0x801A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div752) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // 27.72032138750275693363031333
  s21_decimal decimal_check = {{0xFE6B6D25, 0x5A04B66B, 0x8F4F8A3, 0x1A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div753) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // 10834552318819459802.629269221
  s21_decimal decimal_check = {{0xD4A5E6E5, 0x193D94B2, 0x230221B2, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div754) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // -10834552318819459802.629269221
  s21_decimal decimal_check = {
      {0xD4A5E6E5, 0x193D94B2, 0x230221B2, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div755) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // 63214999029983678345.745456759
  s21_decimal decimal_check = {{0xCA1ADE77, 0x194F6961, 0xCC4238BC, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div756) {
  // 39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -63214999029983678345.745456759
  s21_decimal decimal_check = {
      {0xCA1ADE77, 0x194F6961, 0xCC4238BC, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div757) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000271050543
  s21_decimal decimal_check = {
      {0x9827E72F, 0x1F128130, 0x1027E72F, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div758) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000000000000000271050543
  s21_decimal decimal_check = {{0x9827E72F, 0x1F128130, 0x1027E72F, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div759) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -5.0000000000000000002710505432
  s21_decimal decimal_check = {
      {0xF18F07D8, 0x36B90BE5, 0xA18F07D7, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div760) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 5.0000000000000000002710505432
  s21_decimal decimal_check = {{0xF18F07D8, 0x36B90BE5, 0xA18F07D7, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div761) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000271050543
  s21_decimal decimal_check = {
      {0x9827E72F, 0x1F128130, 0x1027E72F, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div762) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000000000000000271050543
  s21_decimal decimal_check = {{0x9827E72F, 0x1F128130, 0x1027E72F, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div763) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.500000000000000000081315163
  s21_decimal decimal_check = {{0x60D8C55B, 0xEFB8C05B, 0x4D8C55A, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div764) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.500000000000000000081315163
  s21_decimal decimal_check = {{0x60D8C55B, 0xEFB8C05B, 0x4D8C55A, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div765) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div766) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div767) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -1.0000000000000000000542101086
  s21_decimal decimal_check = {
      {0x304FCE5E, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div768) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 1.0000000000000000000542101086
  s21_decimal decimal_check = {{0x304FCE5E, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div769) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -10000000000000000000542101086
  s21_decimal decimal_check = {
      {0x304FCE5E, 0x3E250261, 0x204FCE5E, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div770) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 10000000000000000000542101086
  s21_decimal decimal_check = {{0x304FCE5E, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div771) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // -9223372034707292161
  s21_decimal decimal_check = {{0x80000001, 0x7FFFFFFF, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div772) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // 9223372034707292161
  s21_decimal decimal_check = {{0x80000001, 0x7FFFFFFF, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div773) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // -0.5000000001164153218540398688
  s21_decimal decimal_check = {
      {0xB73A6860, 0x2F3A685F, 0x1027E72F, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div774) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000001164153218540398688
  s21_decimal decimal_check = {{0xB73A6860, 0x2F3A685F, 0x1027E72F, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div775) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // -9223372036854775808.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x5, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div776) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // 9223372036854775808.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x5, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div777) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // -18446744073709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div778) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // 18446744073709551617
  s21_decimal decimal_check = {{0x1, 0x0, 0x1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div779) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // -4611686018964258816.3125
  s21_decimal decimal_check = {{0xC35, 0x4E2, 0x9C4, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div780) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // 4611686018964258816.3125
  s21_decimal decimal_check = {{0xC35, 0x4E2, 0x9C4, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div781) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // -7922816251426433759783891763
  s21_decimal decimal_check = {
      {0xB3333333, 0x99999999, 0x19999999, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div782) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759783891763
  s21_decimal decimal_check = {{0xB3333333, 0x99999999, 0x19999999, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div783) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // -19807040628566084399459729408
  s21_decimal decimal_check = {{0x40000000, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div784) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 19807040628566084399459729408
  s21_decimal decimal_check = {{0x40000000, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div785) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -19807040628566084399459730398
  s21_decimal decimal_check = {{0x400003DE, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div786) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 19807040628566084399459730398
  s21_decimal decimal_check = {{0x400003DE, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div787) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -19807040628566084399459729409
  s21_decimal decimal_check = {{0x40000001, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div788) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 19807040628566084399459729409
  s21_decimal decimal_check = {{0x40000001, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div789) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -39614081257132168798919458812
  s21_decimal decimal_check = {{0x7FFFFFFC, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div790) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 39614081257132168798919458812
  s21_decimal decimal_check = {{0x7FFFFFFC, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div791) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div792) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div793) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div794) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div795) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div796) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div797) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -39614081257132168798919458820
  s21_decimal decimal_check = {{0x80000004, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div798) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 39614081257132168798919458820
  s21_decimal decimal_check = {{0x80000004, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div799) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -5000000000000000000271050543.2
  s21_decimal decimal_check = {
      {0xF18F07D8, 0x36B90BE5, 0xA18F07D7, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div800) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 5000000000000000000271050543.2
  s21_decimal decimal_check = {{0xF18F07D8, 0x36B90BE5, 0xA18F07D7, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

Suite *div_suite2(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("div2");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_div401);
  tcase_add_test(tc_core, test_div402);
  tcase_add_test(tc_core, test_div403);
  tcase_add_test(tc_core, test_div404);
  tcase_add_test(tc_core, test_div405);
  tcase_add_test(tc_core, test_div406);
  tcase_add_test(tc_core, test_div407);
  tcase_add_test(tc_core, test_div408);
  tcase_add_test(tc_core, test_div409);
  tcase_add_test(tc_core, test_div410);
  tcase_add_test(tc_core, test_div411);
  tcase_add_test(tc_core, test_div412);
  tcase_add_test(tc_core, test_div413);
  tcase_add_test(tc_core, test_div414);
  tcase_add_test(tc_core, test_div415);
  tcase_add_test(tc_core, test_div416);
  tcase_add_test(tc_core, test_div417);
  tcase_add_test(tc_core, test_div418);
  tcase_add_test(tc_core, test_div419);
  tcase_add_test(tc_core, test_div420);
  tcase_add_test(tc_core, test_div421);
  tcase_add_test(tc_core, test_div422);
  tcase_add_test(tc_core, test_div423);
  tcase_add_test(tc_core, test_div424);
  tcase_add_test(tc_core, test_div425);
  tcase_add_test(tc_core, test_div426);
  tcase_add_test(tc_core, test_div427);
  tcase_add_test(tc_core, test_div428);
  tcase_add_test(tc_core, test_div429);
  tcase_add_test(tc_core, test_div430);
  tcase_add_test(tc_core, test_div431);
  tcase_add_test(tc_core, test_div432);
  tcase_add_test(tc_core, test_div433);
  tcase_add_test(tc_core, test_div434);
  tcase_add_test(tc_core, test_div435);
  tcase_add_test(tc_core, test_div436);
  tcase_add_test(tc_core, test_div437);
  tcase_add_test(tc_core, test_div438);
  tcase_add_test(tc_core, test_div439);
  tcase_add_test(tc_core, test_div440);
  tcase_add_test(tc_core, test_div441);
  tcase_add_test(tc_core, test_div442);
  tcase_add_test(tc_core, test_div443);
  tcase_add_test(tc_core, test_div444);
  tcase_add_test(tc_core, test_div445);
  tcase_add_test(tc_core, test_div446);
  tcase_add_test(tc_core, test_div447);
  tcase_add_test(tc_core, test_div448);
  tcase_add_test(tc_core, test_div449);
  tcase_add_test(tc_core, test_div450);
  tcase_add_test(tc_core, test_div451);
  tcase_add_test(tc_core, test_div452);
  tcase_add_test(tc_core, test_div453);
  tcase_add_test(tc_core, test_div454);
  tcase_add_test(tc_core, test_div455);
  tcase_add_test(tc_core, test_div456);
  tcase_add_test(tc_core, test_div457);
  tcase_add_test(tc_core, test_div458);
  tcase_add_test(tc_core, test_div459);
  tcase_add_test(tc_core, test_div460);
  tcase_add_test(tc_core, test_div461);
  tcase_add_test(tc_core, test_div462);
  tcase_add_test(tc_core, test_div463);
  tcase_add_test(tc_core, test_div464);
  tcase_add_test(tc_core, test_div465);
  tcase_add_test(tc_core, test_div466);
  tcase_add_test(tc_core, test_div467);
  tcase_add_test(tc_core, test_div468);
  tcase_add_test(tc_core, test_div469);
  tcase_add_test(tc_core, test_div470);
  tcase_add_test(tc_core, test_div471);
  tcase_add_test(tc_core, test_div472);
  tcase_add_test(tc_core, test_div473);
  tcase_add_test(tc_core, test_div474);
  tcase_add_test(tc_core, test_div475);
  tcase_add_test(tc_core, test_div476);
  tcase_add_test(tc_core, test_div477);
  tcase_add_test(tc_core, test_div478);
  tcase_add_test(tc_core, test_div479);
  tcase_add_test(tc_core, test_div480);
  tcase_add_test(tc_core, test_div481);
  tcase_add_test(tc_core, test_div482);
  tcase_add_test(tc_core, test_div483);
  tcase_add_test(tc_core, test_div484);
  tcase_add_test(tc_core, test_div485);
  tcase_add_test(tc_core, test_div486);
  tcase_add_test(tc_core, test_div487);
  tcase_add_test(tc_core, test_div488);
  tcase_add_test(tc_core, test_div489);
  tcase_add_test(tc_core, test_div490);
  tcase_add_test(tc_core, test_div491);
  tcase_add_test(tc_core, test_div492);
  tcase_add_test(tc_core, test_div493);
  tcase_add_test(tc_core, test_div494);
  tcase_add_test(tc_core, test_div495);
  tcase_add_test(tc_core, test_div496);
  tcase_add_test(tc_core, test_div497);
  tcase_add_test(tc_core, test_div498);
  tcase_add_test(tc_core, test_div499);
  tcase_add_test(tc_core, test_div500);
  tcase_add_test(tc_core, test_div501);
  tcase_add_test(tc_core, test_div502);
  tcase_add_test(tc_core, test_div503);
  tcase_add_test(tc_core, test_div504);
  tcase_add_test(tc_core, test_div505);
  tcase_add_test(tc_core, test_div506);
  tcase_add_test(tc_core, test_div507);
  tcase_add_test(tc_core, test_div508);
  tcase_add_test(tc_core, test_div509);
  tcase_add_test(tc_core, test_div510);
  tcase_add_test(tc_core, test_div511);
  tcase_add_test(tc_core, test_div512);
  tcase_add_test(tc_core, test_div513);
  tcase_add_test(tc_core, test_div514);
  tcase_add_test(tc_core, test_div515);
  tcase_add_test(tc_core, test_div516);
  tcase_add_test(tc_core, test_div517);
  tcase_add_test(tc_core, test_div518);
  tcase_add_test(tc_core, test_div519);
  tcase_add_test(tc_core, test_div520);
  tcase_add_test(tc_core, test_div521);
  tcase_add_test(tc_core, test_div522);
  tcase_add_test(tc_core, test_div523);
  tcase_add_test(tc_core, test_div524);
  tcase_add_test(tc_core, test_div525);
  tcase_add_test(tc_core, test_div526);
  tcase_add_test(tc_core, test_div527);
  tcase_add_test(tc_core, test_div528);
  tcase_add_test(tc_core, test_div529);
  tcase_add_test(tc_core, test_div530);
  tcase_add_test(tc_core, test_div531);
  tcase_add_test(tc_core, test_div532);
  tcase_add_test(tc_core, test_div533);
  tcase_add_test(tc_core, test_div534);
  tcase_add_test(tc_core, test_div535);
  tcase_add_test(tc_core, test_div536);
  tcase_add_test(tc_core, test_div537);
  tcase_add_test(tc_core, test_div538);
  tcase_add_test(tc_core, test_div539);
  tcase_add_test(tc_core, test_div540);
  tcase_add_test(tc_core, test_div541);
  tcase_add_test(tc_core, test_div542);
  tcase_add_test(tc_core, test_div543);
  tcase_add_test(tc_core, test_div544);
  tcase_add_test(tc_core, test_div545);
  tcase_add_test(tc_core, test_div546);
  tcase_add_test(tc_core, test_div547);
  tcase_add_test(tc_core, test_div548);
  tcase_add_test(tc_core, test_div549);
  tcase_add_test(tc_core, test_div550);
  tcase_add_test(tc_core, test_div551);
  tcase_add_test(tc_core, test_div552);
  tcase_add_test(tc_core, test_div553);
  tcase_add_test(tc_core, test_div554);
  tcase_add_test(tc_core, test_div555);
  tcase_add_test(tc_core, test_div556);
  tcase_add_test(tc_core, test_div557);
  tcase_add_test(tc_core, test_div558);
  tcase_add_test(tc_core, test_div559);
  tcase_add_test(tc_core, test_div560);
  tcase_add_test(tc_core, test_div561);
  tcase_add_test(tc_core, test_div562);
  tcase_add_test(tc_core, test_div563);
  tcase_add_test(tc_core, test_div564);
  tcase_add_test(tc_core, test_div565);
  tcase_add_test(tc_core, test_div566);
  tcase_add_test(tc_core, test_div567);
  tcase_add_test(tc_core, test_div568);
  tcase_add_test(tc_core, test_div569);
  tcase_add_test(tc_core, test_div570);
  tcase_add_test(tc_core, test_div571);
  tcase_add_test(tc_core, test_div572);
  tcase_add_test(tc_core, test_div573);
  tcase_add_test(tc_core, test_div574);
  tcase_add_test(tc_core, test_div575);
  tcase_add_test(tc_core, test_div576);
  tcase_add_test(tc_core, test_div577);
  tcase_add_test(tc_core, test_div578);
  tcase_add_test(tc_core, test_div579);
  tcase_add_test(tc_core, test_div580);
  tcase_add_test(tc_core, test_div581);
  tcase_add_test(tc_core, test_div582);
  tcase_add_test(tc_core, test_div583);
  tcase_add_test(tc_core, test_div584);
  tcase_add_test(tc_core, test_div585);
  tcase_add_test(tc_core, test_div586);
  tcase_add_test(tc_core, test_div587);
  tcase_add_test(tc_core, test_div588);
  tcase_add_test(tc_core, test_div589);
  tcase_add_test(tc_core, test_div590);
  tcase_add_test(tc_core, test_div591);
  tcase_add_test(tc_core, test_div592);
  tcase_add_test(tc_core, test_div593);
  tcase_add_test(tc_core, test_div594);
  tcase_add_test(tc_core, test_div595);
  tcase_add_test(tc_core, test_div596);
  tcase_add_test(tc_core, test_div597);
  tcase_add_test(tc_core, test_div598);
  tcase_add_test(tc_core, test_div599);
  tcase_add_test(tc_core, test_div600);
  tcase_add_test(tc_core, test_div601);
  tcase_add_test(tc_core, test_div602);
  tcase_add_test(tc_core, test_div603);
  tcase_add_test(tc_core, test_div604);
  tcase_add_test(tc_core, test_div605);
  tcase_add_test(tc_core, test_div606);
  tcase_add_test(tc_core, test_div607);
  tcase_add_test(tc_core, test_div608);
  tcase_add_test(tc_core, test_div609);
  tcase_add_test(tc_core, test_div610);
  tcase_add_test(tc_core, test_div611);
  tcase_add_test(tc_core, test_div612);
  tcase_add_test(tc_core, test_div613);
  tcase_add_test(tc_core, test_div614);
  tcase_add_test(tc_core, test_div615);
  tcase_add_test(tc_core, test_div616);
  tcase_add_test(tc_core, test_div617);
  tcase_add_test(tc_core, test_div618);
  tcase_add_test(tc_core, test_div619);
  tcase_add_test(tc_core, test_div620);
  tcase_add_test(tc_core, test_div621);
  tcase_add_test(tc_core, test_div622);
  tcase_add_test(tc_core, test_div623);
  tcase_add_test(tc_core, test_div624);
  tcase_add_test(tc_core, test_div625);
  tcase_add_test(tc_core, test_div626);
  tcase_add_test(tc_core, test_div627);
  tcase_add_test(tc_core, test_div628);
  tcase_add_test(tc_core, test_div629);
  tcase_add_test(tc_core, test_div630);
  tcase_add_test(tc_core, test_div631);
  tcase_add_test(tc_core, test_div632);
  tcase_add_test(tc_core, test_div633);
  tcase_add_test(tc_core, test_div634);
  tcase_add_test(tc_core, test_div635);
  tcase_add_test(tc_core, test_div636);
  tcase_add_test(tc_core, test_div637);
  tcase_add_test(tc_core, test_div638);
  tcase_add_test(tc_core, test_div639);
  tcase_add_test(tc_core, test_div640);
  tcase_add_test(tc_core, test_div641);
  tcase_add_test(tc_core, test_div642);
  tcase_add_test(tc_core, test_div643);
  tcase_add_test(tc_core, test_div644);
  tcase_add_test(tc_core, test_div645);
  tcase_add_test(tc_core, test_div646);
  tcase_add_test(tc_core, test_div647);
  tcase_add_test(tc_core, test_div648);
  tcase_add_test(tc_core, test_div649);
  tcase_add_test(tc_core, test_div650);
  tcase_add_test(tc_core, test_div651);
  tcase_add_test(tc_core, test_div652);
  tcase_add_test(tc_core, test_div653);
  tcase_add_test(tc_core, test_div654);
  tcase_add_test(tc_core, test_div655);
  tcase_add_test(tc_core, test_div656);
  tcase_add_test(tc_core, test_div657);
  tcase_add_test(tc_core, test_div658);
  tcase_add_test(tc_core, test_div659);
  tcase_add_test(tc_core, test_div660);
  tcase_add_test(tc_core, test_div661);
  tcase_add_test(tc_core, test_div662);
  tcase_add_test(tc_core, test_div663);
  tcase_add_test(tc_core, test_div664);
  tcase_add_test(tc_core, test_div665);
  tcase_add_test(tc_core, test_div666);
  tcase_add_test(tc_core, test_div667);
  tcase_add_test(tc_core, test_div668);
  tcase_add_test(tc_core, test_div669);
  tcase_add_test(tc_core, test_div670);
  tcase_add_test(tc_core, test_div671);
  tcase_add_test(tc_core, test_div672);
  tcase_add_test(tc_core, test_div673);
  tcase_add_test(tc_core, test_div674);
  tcase_add_test(tc_core, test_div675);
  tcase_add_test(tc_core, test_div676);
  tcase_add_test(tc_core, test_div677);
  tcase_add_test(tc_core, test_div678);
  tcase_add_test(tc_core, test_div679);
  tcase_add_test(tc_core, test_div680);
  tcase_add_test(tc_core, test_div681);
  tcase_add_test(tc_core, test_div682);
  tcase_add_test(tc_core, test_div683);
  tcase_add_test(tc_core, test_div684);
  tcase_add_test(tc_core, test_div685);
  tcase_add_test(tc_core, test_div686);
  tcase_add_test(tc_core, test_div687);
  tcase_add_test(tc_core, test_div688);
  tcase_add_test(tc_core, test_div689);
  tcase_add_test(tc_core, test_div690);
  tcase_add_test(tc_core, test_div691);
  tcase_add_test(tc_core, test_div692);
  tcase_add_test(tc_core, test_div693);
  tcase_add_test(tc_core, test_div694);
  tcase_add_test(tc_core, test_div695);
  tcase_add_test(tc_core, test_div696);
  tcase_add_test(tc_core, test_div697);
  tcase_add_test(tc_core, test_div698);
  tcase_add_test(tc_core, test_div699);
  tcase_add_test(tc_core, test_div700);
  tcase_add_test(tc_core, test_div701);
  tcase_add_test(tc_core, test_div702);
  tcase_add_test(tc_core, test_div703);
  tcase_add_test(tc_core, test_div704);
  tcase_add_test(tc_core, test_div705);
  tcase_add_test(tc_core, test_div706);
  tcase_add_test(tc_core, test_div707);
  tcase_add_test(tc_core, test_div708);
  tcase_add_test(tc_core, test_div709);
  tcase_add_test(tc_core, test_div710);
  tcase_add_test(tc_core, test_div711);
  tcase_add_test(tc_core, test_div712);
  tcase_add_test(tc_core, test_div713);
  tcase_add_test(tc_core, test_div714);
  tcase_add_test(tc_core, test_div715);
  tcase_add_test(tc_core, test_div716);
  tcase_add_test(tc_core, test_div717);
  tcase_add_test(tc_core, test_div718);
  tcase_add_test(tc_core, test_div719);
  tcase_add_test(tc_core, test_div720);
  tcase_add_test(tc_core, test_div721);
  tcase_add_test(tc_core, test_div722);
  tcase_add_test(tc_core, test_div723);
  tcase_add_test(tc_core, test_div724);
  tcase_add_test(tc_core, test_div725);
  tcase_add_test(tc_core, test_div726);
  tcase_add_test(tc_core, test_div727);
  tcase_add_test(tc_core, test_div728);
  tcase_add_test(tc_core, test_div729);
  tcase_add_test(tc_core, test_div730);
  tcase_add_test(tc_core, test_div731);
  tcase_add_test(tc_core, test_div732);
  tcase_add_test(tc_core, test_div733);
  tcase_add_test(tc_core, test_div734);
  tcase_add_test(tc_core, test_div735);
  tcase_add_test(tc_core, test_div736);
  tcase_add_test(tc_core, test_div737);
  tcase_add_test(tc_core, test_div738);
  tcase_add_test(tc_core, test_div739);
  tcase_add_test(tc_core, test_div740);
  tcase_add_test(tc_core, test_div741);
  tcase_add_test(tc_core, test_div742);
  tcase_add_test(tc_core, test_div743);
  tcase_add_test(tc_core, test_div744);
  tcase_add_test(tc_core, test_div745);
  tcase_add_test(tc_core, test_div746);
  tcase_add_test(tc_core, test_div747);
  tcase_add_test(tc_core, test_div748);
  tcase_add_test(tc_core, test_div749);
  tcase_add_test(tc_core, test_div750);
  tcase_add_test(tc_core, test_div751);
  tcase_add_test(tc_core, test_div752);
  tcase_add_test(tc_core, test_div753);
  tcase_add_test(tc_core, test_div754);
  tcase_add_test(tc_core, test_div755);
  tcase_add_test(tc_core, test_div756);
  tcase_add_test(tc_core, test_div757);
  tcase_add_test(tc_core, test_div758);
  tcase_add_test(tc_core, test_div759);
  tcase_add_test(tc_core, test_div760);
  tcase_add_test(tc_core, test_div761);
  tcase_add_test(tc_core, test_div762);
  tcase_add_test(tc_core, test_div763);
  tcase_add_test(tc_core, test_div764);
  tcase_add_test(tc_core, test_div765);
  tcase_add_test(tc_core, test_div766);
  tcase_add_test(tc_core, test_div767);
  tcase_add_test(tc_core, test_div768);
  tcase_add_test(tc_core, test_div769);
  tcase_add_test(tc_core, test_div770);
  tcase_add_test(tc_core, test_div771);
  tcase_add_test(tc_core, test_div772);
  tcase_add_test(tc_core, test_div773);
  tcase_add_test(tc_core, test_div774);
  tcase_add_test(tc_core, test_div775);
  tcase_add_test(tc_core, test_div776);
  tcase_add_test(tc_core, test_div777);
  tcase_add_test(tc_core, test_div778);
  tcase_add_test(tc_core, test_div779);
  tcase_add_test(tc_core, test_div780);
  tcase_add_test(tc_core, test_div781);
  tcase_add_test(tc_core, test_div782);
  tcase_add_test(tc_core, test_div783);
  tcase_add_test(tc_core, test_div784);
  tcase_add_test(tc_core, test_div785);
  tcase_add_test(tc_core, test_div786);
  tcase_add_test(tc_core, test_div787);
  tcase_add_test(tc_core, test_div788);
  tcase_add_test(tc_core, test_div789);
  tcase_add_test(tc_core, test_div790);
  tcase_add_test(tc_core, test_div791);
  tcase_add_test(tc_core, test_div792);
  tcase_add_test(tc_core, test_div793);
  tcase_add_test(tc_core, test_div794);
  tcase_add_test(tc_core, test_div795);
  tcase_add_test(tc_core, test_div796);
  tcase_add_test(tc_core, test_div797);
  tcase_add_test(tc_core, test_div798);
  tcase_add_test(tc_core, test_div799);
  tcase_add_test(tc_core, test_div800);

  suite_add_tcase(s, tc_core);
  return s;
}
