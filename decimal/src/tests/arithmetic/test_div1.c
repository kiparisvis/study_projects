
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../s21_decimal.h"
#include "../test.h"

// #define __DEBUG

START_TEST(test_div1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div6) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div8) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1.9999999999999999998915797827
  s21_decimal decimal_check = {{0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div10) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1.9999999999999999998915797827
  s21_decimal decimal_check = {
      {0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div12) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 20000000000000000000000000000
  s21_decimal decimal_check = {{0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div14) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -20000000000000000000000000000
  s21_decimal decimal_check = {
      {0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 18446744069414584321
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div16) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // -18446744069414584321
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 1.0000000002328306436538696289
  s21_decimal decimal_check = {{0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div18) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000002328306436538696289
  s21_decimal decimal_check = {
      {0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div20) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 36893488147419103232
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div22) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -36893488147419103232
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div24) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // 15845632502852867518708790067
  s21_decimal decimal_check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div26) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -15845632502852867518708790067
  s21_decimal decimal_check = {
      {0x33333333, 0x33333333, 0x33333333, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div28) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div30) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div32) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950327
  s21_decimal decimal_check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div34) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950327
  s21_decimal decimal_check = {
      {0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div36) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div38) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div40) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div42) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 10000000000000000000000000000
  s21_decimal decimal_check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div44) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -10000000000000000000000000000
  s21_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 1320469375237738959892399172.1
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div46) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // -1320469375237738959892399172.1
  s21_decimal decimal_check = {
      {0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div48) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div50) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div52) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 1999999999534338.7126922607422
  s21_decimal decimal_check = {{0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0xD0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div54) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -1999999999534338.7126922607422
  s21_decimal decimal_check = {
      {0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0x800D0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div56) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // -1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 368934881474191032320000
  s21_decimal decimal_check = {{0x0, 0x0, 0x4E20, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div58) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // -368934881474191032320000
  s21_decimal decimal_check = {{0x0, 0x0, 0x4E20, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div60) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // -1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div61) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div62) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div63) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // 55340232234013556739000000000
  s21_decimal decimal_check = {{0xB2D05E00, 0xB2D05E00, 0xB2D05E00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div64) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // -55340232234013556739000000000
  s21_decimal decimal_check = {
      {0xB2D05E00, 0xB2D05E00, 0xB2D05E00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div65) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 9364712231340627836019760.833
  s21_decimal decimal_check = {{0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div66) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -9364712231340627836019760.833
  s21_decimal decimal_check = {
      {0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div67) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // 9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div68) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // -9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div69) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 79149013500763574019524425909
  s21_decimal decimal_check = {{0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div70) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // -79149013500763574019524425909
  s21_decimal decimal_check = {
      {0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div71) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div72) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div73) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div74) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div75) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div76) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div77) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div78) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div79) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // -55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div80) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // 55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div81) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // 21669104637638919604.083853925
  s21_decimal decimal_check = {{0x63478A65, 0x327B2965, 0x46044364, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div82) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // -21669104637638919604.083853925
  s21_decimal decimal_check = {
      {0x63478A65, 0x327B2965, 0x46044364, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div83) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // 126429998059967356684.63712959
  s21_decimal decimal_check = {{0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div84) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -126429998059967356684.63712959
  s21_decimal decimal_check = {
      {0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80080000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div85) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div86) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div87) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div88) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div89) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div90) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div91) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div92) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div93) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -1.9999999999999999998915797827
  s21_decimal decimal_check = {
      {0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div94) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 1.9999999999999999998915797827
  s21_decimal decimal_check = {{0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div95) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div96) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div97) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -20000000000000000000000000000
  s21_decimal decimal_check = {
      {0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div98) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 20000000000000000000000000000
  s21_decimal decimal_check = {{0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div99) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // -18446744069414584321
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div100) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // 18446744069414584321
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div101) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // -1.0000000002328306436538696289
  s21_decimal decimal_check = {
      {0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div102) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000002328306436538696289
  s21_decimal decimal_check = {{0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div103) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // -18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div104) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // 18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div105) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // -36893488147419103232
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div106) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // 36893488147419103232
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div107) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // -9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div108) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // 9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div109) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // -15845632502852867518708790067
  s21_decimal decimal_check = {
      {0x33333333, 0x33333333, 0x33333333, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div110) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 15845632502852867518708790067
  s21_decimal decimal_check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div111) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // -39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div112) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div113) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div114) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div115) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div116) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div117) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950327
  s21_decimal decimal_check = {
      {0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div118) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950327
  s21_decimal decimal_check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div119) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div120) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div121) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div122) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div123) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div124) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div125) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div126) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div127) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -10000000000000000000000000000
  s21_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div128) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 10000000000000000000000000000
  s21_decimal decimal_check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div129) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // -1320469375237738959892399172.1
  s21_decimal decimal_check = {
      {0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div130) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // 1320469375237738959892399172.1
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div131) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div132) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div133) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div134) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div135) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div136) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div137) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // -1999999999534338.7126922607422
  s21_decimal decimal_check = {
      {0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0x800D0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div138) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 1999999999534338.7126922607422
  s21_decimal decimal_check = {{0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0xD0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div139) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // -1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div140) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // 1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div141) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // -368934881474191032320000
  s21_decimal decimal_check = {{0x0, 0x0, 0x4E20, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div142) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // 368934881474191032320000
  s21_decimal decimal_check = {{0x0, 0x0, 0x4E20, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div143) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div144) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // 1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div145) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div146) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div147) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // -55340232234013556739000000000
  s21_decimal decimal_check = {
      {0xB2D05E00, 0xB2D05E00, 0xB2D05E00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div148) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // 55340232234013556739000000000
  s21_decimal decimal_check = {{0xB2D05E00, 0xB2D05E00, 0xB2D05E00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div149) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -9364712231340627836019760.833
  s21_decimal decimal_check = {
      {0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div150) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // 9364712231340627836019760.833
  s21_decimal decimal_check = {{0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div151) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // -9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div152) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // 9903520314283042199192993792
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div153) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // -79149013500763574019524425909
  s21_decimal decimal_check = {
      {0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div154) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // 79149013500763574019524425909
  s21_decimal decimal_check = {{0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div155) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div156) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div157) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div158) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div159) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div160) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div161) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div162) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div163) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // 55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div164) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // -55.440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div165) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // -21669104637638919604.083853925
  s21_decimal decimal_check = {
      {0x63478A65, 0x327B2965, 0x46044364, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div166) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // 21669104637638919604.083853925
  s21_decimal decimal_check = {{0x63478A65, 0x327B2965, 0x46044364, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div167) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // -126429998059967356684.63712959
  s21_decimal decimal_check = {
      {0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80080000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div168) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 126429998059967356684.63712959
  s21_decimal decimal_check = {{0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div169) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div170) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div171) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div172) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div173) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div174) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div175) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div176) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div177) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.1999999999999999999891579783
  s21_decimal decimal_check = {{0xC989A387, 0x3FA10079, 0x6765C79, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div178) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.1999999999999999999891579783
  s21_decimal decimal_check = {{0xC989A387, 0x3FA10079, 0x6765C79, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div179) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div180) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div181) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 2000000000000000000000000000
  s21_decimal decimal_check = {{0xD0000000, 0x3FA10079, 0x6765C79, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div182) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -2000000000000000000000000000
  s21_decimal decimal_check = {{0xD0000000, 0x3FA10079, 0x6765C79, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div183) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 1844674406941458432.1
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div184) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // -1844674406941458432.1
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div185) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 0.1000000000232830643653869629
  s21_decimal decimal_check = {{0x87D0803D, 0xA30BAE79, 0x33B2E3C, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div186) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -0.1000000000232830643653869629
  s21_decimal decimal_check = {{0x87D0803D, 0xA30BAE79, 0x33B2E3C, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div187) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 1844674407370955161.6
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div188) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -1844674407370955161.6
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div189) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 3689348814741910323.2
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div190) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -3689348814741910323.2
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div191) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 922337203792851763.2125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div192) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -922337203792851763.2125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div193) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // 1584563250285286751870879006.7
  s21_decimal decimal_check = {{0x33333333, 0x33333333, 0x33333333, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div194) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -1584563250285286751870879006.7
  s21_decimal decimal_check = {
      {0x33333333, 0x33333333, 0x33333333, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div195) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div196) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div197) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 3961408125713216879677197714.8
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div198) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -3961408125713216879677197714.8
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div199) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 3961408125713216879677197516.9
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div200) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -3961408125713216879677197516.9
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div201) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 7922816251426433759354395032.7
  s21_decimal decimal_check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div202) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -7922816251426433759354395032.7
  s21_decimal decimal_check = {
      {0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div203) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div204) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div205) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div206) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div207) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div208) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div209) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div210) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div211) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 1000000000000000000000000000
  s21_decimal decimal_check = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div212) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -1000000000000000000000000000
  s21_decimal decimal_check = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div213) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 132046937523773895989239917.21
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div214) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // -132046937523773895989239917.21
  s21_decimal decimal_check = {
      {0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div215) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 15845632502852867518708790067
  s21_decimal decimal_check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div216) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -15845632502852867518708790067
  s21_decimal decimal_check = {
      {0x33333333, 0x33333333, 0x33333333, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div217) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div218) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div219) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div220) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div221) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 199999999953433.87126922607422
  s21_decimal decimal_check = {{0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0xE0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div222) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -199999999953433.87126922607422
  s21_decimal decimal_check = {
      {0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0x800E0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div223) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 184467440737095516160000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x989680, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div224) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // -184467440737095516160000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x989680, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div225) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 36893488147419103232000
  s21_decimal decimal_check = {{0x0, 0x0, 0x7D0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div226) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // -36893488147419103232000
  s21_decimal decimal_check = {{0x0, 0x0, 0x7D0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div227) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 184467440780045189130000000
  s21_decimal decimal_check = {{0x989680, 0x989680, 0x989680, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div228) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // -184467440780045189130000000
  s21_decimal decimal_check = {{0x989680, 0x989680, 0x989680, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div229) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // 7923608612287662525606955729
  s21_decimal decimal_check = {{0xB80E8AD1, 0x917FD565, 0x199A4163, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div230) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // -7923608612287662525606955729
  s21_decimal decimal_check = {
      {0xB80E8AD1, 0x917FD565, 0x199A4163, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div231) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // 5534023223401355673900000000
  s21_decimal decimal_check = {{0x11E1A300, 0x11E1A300, 0x11E1A300, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div232) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // -5534023223401355673900000000
  s21_decimal decimal_check = {
      {0x11E1A300, 0x11E1A300, 0x11E1A300, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div233) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 936471223134062783601976.0833
  s21_decimal decimal_check = {{0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div234) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -936471223134062783601976.0833
  s21_decimal decimal_check = {
      {0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div235) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // 990352031428304219919299379.2
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div236) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // -990352031428304219919299379.2
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div237) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 7914901350076357401952442590.9
  s21_decimal decimal_check = {{0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div238) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // -7914901350076357401952442590.9
  s21_decimal decimal_check = {
      {0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div239) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div240) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div241) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // 792281625142643375935439503.35
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div242) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // -792281625142643375935439503.35
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div243) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div244) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div245) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div246) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div247) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // -5.5440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div248) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // 5.5440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div249) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // 2166910463763891960.4083853925
  s21_decimal decimal_check = {{0x63478A65, 0x327B2965, 0x46044364, 0xA0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div250) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // -2166910463763891960.4083853925
  s21_decimal decimal_check = {
      {0x63478A65, 0x327B2965, 0x46044364, 0x800A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div251) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // 12642999805996735668.463712959
  s21_decimal decimal_check = {{0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div252) {
  // 7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -12642999805996735668.463712959
  s21_decimal decimal_check = {
      {0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div253) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div254) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div255) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div256) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div257) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div258) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div259) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div260) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div261) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.1999999999999999999891579783
  s21_decimal decimal_check = {{0xC989A387, 0x3FA10079, 0x6765C79, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div262) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.1999999999999999999891579783
  s21_decimal decimal_check = {{0xC989A387, 0x3FA10079, 0x6765C79, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div263) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div264) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.2
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div265) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -2000000000000000000000000000
  s21_decimal decimal_check = {{0xD0000000, 0x3FA10079, 0x6765C79, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div266) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 2000000000000000000000000000
  s21_decimal decimal_check = {{0xD0000000, 0x3FA10079, 0x6765C79, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div267) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // -1844674406941458432.1
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div268) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // 1844674406941458432.1
  s21_decimal decimal_check = {{0x1, 0xFFFFFFFF, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div269) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // -0.1000000000232830643653869629
  s21_decimal decimal_check = {{0x87D0803D, 0xA30BAE79, 0x33B2E3C, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div270) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 0.1000000000232830643653869629
  s21_decimal decimal_check = {{0x87D0803D, 0xA30BAE79, 0x33B2E3C, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div271) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // -1844674407370955161.6
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div272) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // 1844674407370955161.6
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div273) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // -3689348814741910323.2
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div274) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // 3689348814741910323.2
  s21_decimal decimal_check = {{0x0, 0x0, 0x2, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div275) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // -922337203792851763.2125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div276) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // 922337203792851763.2125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div277) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // -1584563250285286751870879006.7
  s21_decimal decimal_check = {
      {0x33333333, 0x33333333, 0x33333333, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div278) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 1584563250285286751870879006.7
  s21_decimal decimal_check = {{0x33333333, 0x33333333, 0x33333333, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div279) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // -3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div280) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div281) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -3961408125713216879677197714.8
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div282) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 3961408125713216879677197714.8
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div283) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -3961408125713216879677197516.9
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div284) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 3961408125713216879677197516.9
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div285) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -7922816251426433759354395032.7
  s21_decimal decimal_check = {
      {0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div286) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 7922816251426433759354395032.7
  s21_decimal decimal_check = {{0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div287) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div288) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div289) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div290) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div291) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div292) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div293) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div294) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div295) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -1000000000000000000000000000
  s21_decimal decimal_check = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div296) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 1000000000000000000000000000
  s21_decimal decimal_check = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div297) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // -132046937523773895989239917.21
  s21_decimal decimal_check = {
      {0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div298) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // 132046937523773895989239917.21
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div299) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -15845632502852867518708790067
  s21_decimal decimal_check = {
      {0x33333333, 0x33333333, 0x33333333, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div300) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 15845632502852867518708790067
  s21_decimal decimal_check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div301) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div302) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div303) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div304) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div305) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // -199999999953433.87126922607422
  s21_decimal decimal_check = {
      {0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0x800E0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div306) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 199999999953433.87126922607422
  s21_decimal decimal_check = {{0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0xE0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div307) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // -184467440737095516160000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x989680, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div308) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // 184467440737095516160000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x989680, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div309) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // -36893488147419103232000
  s21_decimal decimal_check = {{0x0, 0x0, 0x7D0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div310) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // 36893488147419103232000
  s21_decimal decimal_check = {{0x0, 0x0, 0x7D0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div311) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -184467440780045189130000000
  s21_decimal decimal_check = {{0x989680, 0x989680, 0x989680, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div312) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // 184467440780045189130000000
  s21_decimal decimal_check = {{0x989680, 0x989680, 0x989680, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div313) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // -7923608612287662525606955729
  s21_decimal decimal_check = {
      {0xB80E8AD1, 0x917FD565, 0x199A4163, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div314) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // 7923608612287662525606955729
  s21_decimal decimal_check = {{0xB80E8AD1, 0x917FD565, 0x199A4163, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div315) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // -5534023223401355673900000000
  s21_decimal decimal_check = {
      {0x11E1A300, 0x11E1A300, 0x11E1A300, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div316) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // 5534023223401355673900000000
  s21_decimal decimal_check = {{0x11E1A300, 0x11E1A300, 0x11E1A300, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div317) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -936471223134062783601976.0833
  s21_decimal decimal_check = {
      {0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div318) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // 936471223134062783601976.0833
  s21_decimal decimal_check = {{0x9ACD5EC1, 0x4BCA35AA, 0x1E424EF3, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div319) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // -990352031428304219919299379.2
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div320) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // 990352031428304219919299379.2
  s21_decimal decimal_check = {{0x0, 0x0, 0x20000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div321) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // -7914901350076357401952442590.9
  s21_decimal decimal_check = {
      {0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div322) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // 7914901350076357401952442590.9
  s21_decimal decimal_check = {{0xFBE878B5, 0x6170458F, 0xFFBE878B, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div323) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div324) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div325) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // -792281625142643375935439503.35
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div326) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // 792281625142643375935439503.35
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div327) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div328) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div329) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div330) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div331) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // 5.5440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div332) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // -5.5440642775005513864255183391
  s21_decimal decimal_check = {{0x2D411A1F, 0x85E406F, 0xB3236CC3, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div333) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // -2166910463763891960.4083853925
  s21_decimal decimal_check = {
      {0x63478A65, 0x327B2965, 0x46044364, 0x800A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div334) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // 2166910463763891960.4083853925
  s21_decimal decimal_check = {{0x63478A65, 0x327B2965, 0x46044364, 0xA0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div335) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // -12642999805996735668.463712959
  s21_decimal decimal_check = {
      {0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div336) {
  // -7922816251426433759354395033.5
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 12642999805996735668.463712959
  s21_decimal decimal_check = {{0xFF91BABF, 0xD1DCAEAC, 0x28DA0B58, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div337) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div338) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div339) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div340) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -10
  s21_decimal decimal_check = {{0xA, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div341) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div342) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div343) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div344) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div345) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 1.9999999999999999998915797827
  s21_decimal decimal_check = {{0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div346) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1.9999999999999999998915797827
  s21_decimal decimal_check = {
      {0xDF606343, 0x7C4A04C1, 0x409F9CBC, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div347) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 1.9999999999999999999999999999
  s21_decimal decimal_check = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div348) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal_check = {
      {0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div349) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 19999999999999999999999999999
  s21_decimal decimal_check = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div350) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -19999999999999999999999999999
  s21_decimal decimal_check = {
      {0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div351) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 18446744069414584320.999999999
  s21_decimal decimal_check = {{0x3B9AC9FF, 0xC4653600, 0x3B9AC9FF, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div352) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // -18446744069414584320.999999999
  s21_decimal decimal_check = {
      {0x3B9AC9FF, 0xC4653600, 0x3B9AC9FF, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div353) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 1.0000000002328306436538696289
  s21_decimal decimal_check = {{0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div354) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -1.0000000002328306436538696289
  s21_decimal decimal_check = {
      {0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div355) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div356) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div357) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 36893488147419103231.999999999
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x773593FF, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div358) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -36893488147419103231.999999999
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0x773593FF, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div359) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x30000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div360) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -9223372037928517632.125
  s21_decimal decimal_check = {{0x7D, 0xFA, 0x1F4, 0x80030000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div361) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // 15845632502852867518708790067
  s21_decimal decimal_check = {{0x33333333, 0x33333333, 0x33333333, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div362) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -15845632502852867518708790067
  s21_decimal decimal_check = {
      {0x33333333, 0x33333333, 0x33333333, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div363) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 39614081257132168796771975167
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div364) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -39614081257132168796771975167
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div365) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div366) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -39614081257132168796771977148
  s21_decimal decimal_check = {{0x7BC, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div367) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div368) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -39614081257132168796771975169
  s21_decimal decimal_check = {{0x1, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div369) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950326
  s21_decimal decimal_check = {{0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div370) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -79228162514264337593543950326
  s21_decimal decimal_check = {
      {0xFFFFFFF6, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div371) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div372) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div373) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div374) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div375) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div376) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div377) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div378) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div379) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 10000000000000000000000000000
  s21_decimal decimal_check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div380) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -10000000000000000000000000000
  s21_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div381) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 1320469375237738959892399172.1
  s21_decimal decimal_check = {{0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div382) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // -1320469375237738959892399172.1
  s21_decimal decimal_check = {
      {0xAAAAAAA9, 0xAAAAAAAA, 0x2AAAAAAA, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div383) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div384) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div385) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div386) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div387) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div388) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div389) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 1999999999534338.7126922607422
  s21_decimal decimal_check = {{0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0xD0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div390) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -1999999999534338.7126922607422
  s21_decimal decimal_check = {
      {0xA3B5FB3E, 0x3BAA6805, 0x409F9CBC, 0x800D0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div391) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div392) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // -1844674407370955161600000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div393) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 368934881474191032319999.99999
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x773593FF, 0x50000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div394) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // -368934881474191032319999.99999
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0x773593FF, 0x80050000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div395) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div396) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // -1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div397) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div398) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div399) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // 55340232234013556738999999999
  s21_decimal decimal_check = {{0xB2D05DFF, 0xB2D05E00, 0xB2D05E00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div400) {
  // 79228162514264337593543950334
  s21_decimal decimal1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // -55340232234013556738999999999
  s21_decimal decimal_check = {
      {0xB2D05DFF, 0xB2D05E00, 0xB2D05E00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

Suite *div_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("div1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_div1);
  tcase_add_test(tc_core, test_div2);
  tcase_add_test(tc_core, test_div3);
  tcase_add_test(tc_core, test_div4);
  tcase_add_test(tc_core, test_div5);
  tcase_add_test(tc_core, test_div6);
  tcase_add_test(tc_core, test_div7);
  tcase_add_test(tc_core, test_div8);
  tcase_add_test(tc_core, test_div9);
  tcase_add_test(tc_core, test_div10);
  tcase_add_test(tc_core, test_div11);
  tcase_add_test(tc_core, test_div12);
  tcase_add_test(tc_core, test_div13);
  tcase_add_test(tc_core, test_div14);
  tcase_add_test(tc_core, test_div15);
  tcase_add_test(tc_core, test_div16);
  tcase_add_test(tc_core, test_div17);
  tcase_add_test(tc_core, test_div18);
  tcase_add_test(tc_core, test_div19);
  tcase_add_test(tc_core, test_div20);
  tcase_add_test(tc_core, test_div21);
  tcase_add_test(tc_core, test_div22);
  tcase_add_test(tc_core, test_div23);
  tcase_add_test(tc_core, test_div24);
  tcase_add_test(tc_core, test_div25);
  tcase_add_test(tc_core, test_div26);
  tcase_add_test(tc_core, test_div27);
  tcase_add_test(tc_core, test_div28);
  tcase_add_test(tc_core, test_div29);
  tcase_add_test(tc_core, test_div30);
  tcase_add_test(tc_core, test_div31);
  tcase_add_test(tc_core, test_div32);
  tcase_add_test(tc_core, test_div33);
  tcase_add_test(tc_core, test_div34);
  tcase_add_test(tc_core, test_div35);
  tcase_add_test(tc_core, test_div36);
  tcase_add_test(tc_core, test_div37);
  tcase_add_test(tc_core, test_div38);
  tcase_add_test(tc_core, test_div39);
  tcase_add_test(tc_core, test_div40);
  tcase_add_test(tc_core, test_div41);
  tcase_add_test(tc_core, test_div42);
  tcase_add_test(tc_core, test_div43);
  tcase_add_test(tc_core, test_div44);
  tcase_add_test(tc_core, test_div45);
  tcase_add_test(tc_core, test_div46);
  tcase_add_test(tc_core, test_div47);
  tcase_add_test(tc_core, test_div48);
  tcase_add_test(tc_core, test_div49);
  tcase_add_test(tc_core, test_div50);
  tcase_add_test(tc_core, test_div51);
  tcase_add_test(tc_core, test_div52);
  tcase_add_test(tc_core, test_div53);
  tcase_add_test(tc_core, test_div54);
  tcase_add_test(tc_core, test_div55);
  tcase_add_test(tc_core, test_div56);
  tcase_add_test(tc_core, test_div57);
  tcase_add_test(tc_core, test_div58);
  tcase_add_test(tc_core, test_div59);
  tcase_add_test(tc_core, test_div60);
  tcase_add_test(tc_core, test_div61);
  tcase_add_test(tc_core, test_div62);
  tcase_add_test(tc_core, test_div63);
  tcase_add_test(tc_core, test_div64);
  tcase_add_test(tc_core, test_div65);
  tcase_add_test(tc_core, test_div66);
  tcase_add_test(tc_core, test_div67);
  tcase_add_test(tc_core, test_div68);
  tcase_add_test(tc_core, test_div69);
  tcase_add_test(tc_core, test_div70);
  tcase_add_test(tc_core, test_div71);
  tcase_add_test(tc_core, test_div72);
  tcase_add_test(tc_core, test_div73);
  tcase_add_test(tc_core, test_div74);
  tcase_add_test(tc_core, test_div75);
  tcase_add_test(tc_core, test_div76);
  tcase_add_test(tc_core, test_div77);
  tcase_add_test(tc_core, test_div78);
  tcase_add_test(tc_core, test_div79);
  tcase_add_test(tc_core, test_div80);
  tcase_add_test(tc_core, test_div81);
  tcase_add_test(tc_core, test_div82);
  tcase_add_test(tc_core, test_div83);
  tcase_add_test(tc_core, test_div84);
  tcase_add_test(tc_core, test_div85);
  tcase_add_test(tc_core, test_div86);
  tcase_add_test(tc_core, test_div87);
  tcase_add_test(tc_core, test_div88);
  tcase_add_test(tc_core, test_div89);
  tcase_add_test(tc_core, test_div90);
  tcase_add_test(tc_core, test_div91);
  tcase_add_test(tc_core, test_div92);
  tcase_add_test(tc_core, test_div93);
  tcase_add_test(tc_core, test_div94);
  tcase_add_test(tc_core, test_div95);
  tcase_add_test(tc_core, test_div96);
  tcase_add_test(tc_core, test_div97);
  tcase_add_test(tc_core, test_div98);
  tcase_add_test(tc_core, test_div99);
  tcase_add_test(tc_core, test_div100);
  tcase_add_test(tc_core, test_div101);
  tcase_add_test(tc_core, test_div102);
  tcase_add_test(tc_core, test_div103);
  tcase_add_test(tc_core, test_div104);
  tcase_add_test(tc_core, test_div105);
  tcase_add_test(tc_core, test_div106);
  tcase_add_test(tc_core, test_div107);
  tcase_add_test(tc_core, test_div108);
  tcase_add_test(tc_core, test_div109);
  tcase_add_test(tc_core, test_div110);
  tcase_add_test(tc_core, test_div111);
  tcase_add_test(tc_core, test_div112);
  tcase_add_test(tc_core, test_div113);
  tcase_add_test(tc_core, test_div114);
  tcase_add_test(tc_core, test_div115);
  tcase_add_test(tc_core, test_div116);
  tcase_add_test(tc_core, test_div117);
  tcase_add_test(tc_core, test_div118);
  tcase_add_test(tc_core, test_div119);
  tcase_add_test(tc_core, test_div120);
  tcase_add_test(tc_core, test_div121);
  tcase_add_test(tc_core, test_div122);
  tcase_add_test(tc_core, test_div123);
  tcase_add_test(tc_core, test_div124);
  tcase_add_test(tc_core, test_div125);
  tcase_add_test(tc_core, test_div126);
  tcase_add_test(tc_core, test_div127);
  tcase_add_test(tc_core, test_div128);
  tcase_add_test(tc_core, test_div129);
  tcase_add_test(tc_core, test_div130);
  tcase_add_test(tc_core, test_div131);
  tcase_add_test(tc_core, test_div132);
  tcase_add_test(tc_core, test_div133);
  tcase_add_test(tc_core, test_div134);
  tcase_add_test(tc_core, test_div135);
  tcase_add_test(tc_core, test_div136);
  tcase_add_test(tc_core, test_div137);
  tcase_add_test(tc_core, test_div138);
  tcase_add_test(tc_core, test_div139);
  tcase_add_test(tc_core, test_div140);
  tcase_add_test(tc_core, test_div141);
  tcase_add_test(tc_core, test_div142);
  tcase_add_test(tc_core, test_div143);
  tcase_add_test(tc_core, test_div144);
  tcase_add_test(tc_core, test_div145);
  tcase_add_test(tc_core, test_div146);
  tcase_add_test(tc_core, test_div147);
  tcase_add_test(tc_core, test_div148);
  tcase_add_test(tc_core, test_div149);
  tcase_add_test(tc_core, test_div150);
  tcase_add_test(tc_core, test_div151);
  tcase_add_test(tc_core, test_div152);
  tcase_add_test(tc_core, test_div153);
  tcase_add_test(tc_core, test_div154);
  tcase_add_test(tc_core, test_div155);
  tcase_add_test(tc_core, test_div156);
  tcase_add_test(tc_core, test_div157);
  tcase_add_test(tc_core, test_div158);
  tcase_add_test(tc_core, test_div159);
  tcase_add_test(tc_core, test_div160);
  tcase_add_test(tc_core, test_div161);
  tcase_add_test(tc_core, test_div162);
  tcase_add_test(tc_core, test_div163);
  tcase_add_test(tc_core, test_div164);
  tcase_add_test(tc_core, test_div165);
  tcase_add_test(tc_core, test_div166);
  tcase_add_test(tc_core, test_div167);
  tcase_add_test(tc_core, test_div168);
  tcase_add_test(tc_core, test_div169);
  tcase_add_test(tc_core, test_div170);
  tcase_add_test(tc_core, test_div171);
  tcase_add_test(tc_core, test_div172);
  tcase_add_test(tc_core, test_div173);
  tcase_add_test(tc_core, test_div174);
  tcase_add_test(tc_core, test_div175);
  tcase_add_test(tc_core, test_div176);
  tcase_add_test(tc_core, test_div177);
  tcase_add_test(tc_core, test_div178);
  tcase_add_test(tc_core, test_div179);
  tcase_add_test(tc_core, test_div180);
  tcase_add_test(tc_core, test_div181);
  tcase_add_test(tc_core, test_div182);
  tcase_add_test(tc_core, test_div183);
  tcase_add_test(tc_core, test_div184);
  tcase_add_test(tc_core, test_div185);
  tcase_add_test(tc_core, test_div186);
  tcase_add_test(tc_core, test_div187);
  tcase_add_test(tc_core, test_div188);
  tcase_add_test(tc_core, test_div189);
  tcase_add_test(tc_core, test_div190);
  tcase_add_test(tc_core, test_div191);
  tcase_add_test(tc_core, test_div192);
  tcase_add_test(tc_core, test_div193);
  tcase_add_test(tc_core, test_div194);
  tcase_add_test(tc_core, test_div195);
  tcase_add_test(tc_core, test_div196);
  tcase_add_test(tc_core, test_div197);
  tcase_add_test(tc_core, test_div198);
  tcase_add_test(tc_core, test_div199);
  tcase_add_test(tc_core, test_div200);
  tcase_add_test(tc_core, test_div201);
  tcase_add_test(tc_core, test_div202);
  tcase_add_test(tc_core, test_div203);
  tcase_add_test(tc_core, test_div204);
  tcase_add_test(tc_core, test_div205);
  tcase_add_test(tc_core, test_div206);
  tcase_add_test(tc_core, test_div207);
  tcase_add_test(tc_core, test_div208);
  tcase_add_test(tc_core, test_div209);
  tcase_add_test(tc_core, test_div210);
  tcase_add_test(tc_core, test_div211);
  tcase_add_test(tc_core, test_div212);
  tcase_add_test(tc_core, test_div213);
  tcase_add_test(tc_core, test_div214);
  tcase_add_test(tc_core, test_div215);
  tcase_add_test(tc_core, test_div216);
  tcase_add_test(tc_core, test_div217);
  tcase_add_test(tc_core, test_div218);
  tcase_add_test(tc_core, test_div219);
  tcase_add_test(tc_core, test_div220);
  tcase_add_test(tc_core, test_div221);
  tcase_add_test(tc_core, test_div222);
  tcase_add_test(tc_core, test_div223);
  tcase_add_test(tc_core, test_div224);
  tcase_add_test(tc_core, test_div225);
  tcase_add_test(tc_core, test_div226);
  tcase_add_test(tc_core, test_div227);
  tcase_add_test(tc_core, test_div228);
  tcase_add_test(tc_core, test_div229);
  tcase_add_test(tc_core, test_div230);
  tcase_add_test(tc_core, test_div231);
  tcase_add_test(tc_core, test_div232);
  tcase_add_test(tc_core, test_div233);
  tcase_add_test(tc_core, test_div234);
  tcase_add_test(tc_core, test_div235);
  tcase_add_test(tc_core, test_div236);
  tcase_add_test(tc_core, test_div237);
  tcase_add_test(tc_core, test_div238);
  tcase_add_test(tc_core, test_div239);
  tcase_add_test(tc_core, test_div240);
  tcase_add_test(tc_core, test_div241);
  tcase_add_test(tc_core, test_div242);
  tcase_add_test(tc_core, test_div243);
  tcase_add_test(tc_core, test_div244);
  tcase_add_test(tc_core, test_div245);
  tcase_add_test(tc_core, test_div246);
  tcase_add_test(tc_core, test_div247);
  tcase_add_test(tc_core, test_div248);
  tcase_add_test(tc_core, test_div249);
  tcase_add_test(tc_core, test_div250);
  tcase_add_test(tc_core, test_div251);
  tcase_add_test(tc_core, test_div252);
  tcase_add_test(tc_core, test_div253);
  tcase_add_test(tc_core, test_div254);
  tcase_add_test(tc_core, test_div255);
  tcase_add_test(tc_core, test_div256);
  tcase_add_test(tc_core, test_div257);
  tcase_add_test(tc_core, test_div258);
  tcase_add_test(tc_core, test_div259);
  tcase_add_test(tc_core, test_div260);
  tcase_add_test(tc_core, test_div261);
  tcase_add_test(tc_core, test_div262);
  tcase_add_test(tc_core, test_div263);
  tcase_add_test(tc_core, test_div264);
  tcase_add_test(tc_core, test_div265);
  tcase_add_test(tc_core, test_div266);
  tcase_add_test(tc_core, test_div267);
  tcase_add_test(tc_core, test_div268);
  tcase_add_test(tc_core, test_div269);
  tcase_add_test(tc_core, test_div270);
  tcase_add_test(tc_core, test_div271);
  tcase_add_test(tc_core, test_div272);
  tcase_add_test(tc_core, test_div273);
  tcase_add_test(tc_core, test_div274);
  tcase_add_test(tc_core, test_div275);
  tcase_add_test(tc_core, test_div276);
  tcase_add_test(tc_core, test_div277);
  tcase_add_test(tc_core, test_div278);
  tcase_add_test(tc_core, test_div279);
  tcase_add_test(tc_core, test_div280);
  tcase_add_test(tc_core, test_div281);
  tcase_add_test(tc_core, test_div282);
  tcase_add_test(tc_core, test_div283);
  tcase_add_test(tc_core, test_div284);
  tcase_add_test(tc_core, test_div285);
  tcase_add_test(tc_core, test_div286);
  tcase_add_test(tc_core, test_div287);
  tcase_add_test(tc_core, test_div288);
  tcase_add_test(tc_core, test_div289);
  tcase_add_test(tc_core, test_div290);
  tcase_add_test(tc_core, test_div291);
  tcase_add_test(tc_core, test_div292);
  tcase_add_test(tc_core, test_div293);
  tcase_add_test(tc_core, test_div294);
  tcase_add_test(tc_core, test_div295);
  tcase_add_test(tc_core, test_div296);
  tcase_add_test(tc_core, test_div297);
  tcase_add_test(tc_core, test_div298);
  tcase_add_test(tc_core, test_div299);
  tcase_add_test(tc_core, test_div300);
  tcase_add_test(tc_core, test_div301);
  tcase_add_test(tc_core, test_div302);
  tcase_add_test(tc_core, test_div303);
  tcase_add_test(tc_core, test_div304);
  tcase_add_test(tc_core, test_div305);
  tcase_add_test(tc_core, test_div306);
  tcase_add_test(tc_core, test_div307);
  tcase_add_test(tc_core, test_div308);
  tcase_add_test(tc_core, test_div309);
  tcase_add_test(tc_core, test_div310);
  tcase_add_test(tc_core, test_div311);
  tcase_add_test(tc_core, test_div312);
  tcase_add_test(tc_core, test_div313);
  tcase_add_test(tc_core, test_div314);
  tcase_add_test(tc_core, test_div315);
  tcase_add_test(tc_core, test_div316);
  tcase_add_test(tc_core, test_div317);
  tcase_add_test(tc_core, test_div318);
  tcase_add_test(tc_core, test_div319);
  tcase_add_test(tc_core, test_div320);
  tcase_add_test(tc_core, test_div321);
  tcase_add_test(tc_core, test_div322);
  tcase_add_test(tc_core, test_div323);
  tcase_add_test(tc_core, test_div324);
  tcase_add_test(tc_core, test_div325);
  tcase_add_test(tc_core, test_div326);
  tcase_add_test(tc_core, test_div327);
  tcase_add_test(tc_core, test_div328);
  tcase_add_test(tc_core, test_div329);
  tcase_add_test(tc_core, test_div330);
  tcase_add_test(tc_core, test_div331);
  tcase_add_test(tc_core, test_div332);
  tcase_add_test(tc_core, test_div333);
  tcase_add_test(tc_core, test_div334);
  tcase_add_test(tc_core, test_div335);
  tcase_add_test(tc_core, test_div336);
  tcase_add_test(tc_core, test_div337);
  tcase_add_test(tc_core, test_div338);
  tcase_add_test(tc_core, test_div339);
  tcase_add_test(tc_core, test_div340);
  tcase_add_test(tc_core, test_div341);
  tcase_add_test(tc_core, test_div342);
  tcase_add_test(tc_core, test_div343);
  tcase_add_test(tc_core, test_div344);
  tcase_add_test(tc_core, test_div345);
  tcase_add_test(tc_core, test_div346);
  tcase_add_test(tc_core, test_div347);
  tcase_add_test(tc_core, test_div348);
  tcase_add_test(tc_core, test_div349);
  tcase_add_test(tc_core, test_div350);
  tcase_add_test(tc_core, test_div351);
  tcase_add_test(tc_core, test_div352);
  tcase_add_test(tc_core, test_div353);
  tcase_add_test(tc_core, test_div354);
  tcase_add_test(tc_core, test_div355);
  tcase_add_test(tc_core, test_div356);
  tcase_add_test(tc_core, test_div357);
  tcase_add_test(tc_core, test_div358);
  tcase_add_test(tc_core, test_div359);
  tcase_add_test(tc_core, test_div360);
  tcase_add_test(tc_core, test_div361);
  tcase_add_test(tc_core, test_div362);
  tcase_add_test(tc_core, test_div363);
  tcase_add_test(tc_core, test_div364);
  tcase_add_test(tc_core, test_div365);
  tcase_add_test(tc_core, test_div366);
  tcase_add_test(tc_core, test_div367);
  tcase_add_test(tc_core, test_div368);
  tcase_add_test(tc_core, test_div369);
  tcase_add_test(tc_core, test_div370);
  tcase_add_test(tc_core, test_div371);
  tcase_add_test(tc_core, test_div372);
  tcase_add_test(tc_core, test_div373);
  tcase_add_test(tc_core, test_div374);
  tcase_add_test(tc_core, test_div375);
  tcase_add_test(tc_core, test_div376);
  tcase_add_test(tc_core, test_div377);
  tcase_add_test(tc_core, test_div378);
  tcase_add_test(tc_core, test_div379);
  tcase_add_test(tc_core, test_div380);
  tcase_add_test(tc_core, test_div381);
  tcase_add_test(tc_core, test_div382);
  tcase_add_test(tc_core, test_div383);
  tcase_add_test(tc_core, test_div384);
  tcase_add_test(tc_core, test_div385);
  tcase_add_test(tc_core, test_div386);
  tcase_add_test(tc_core, test_div387);
  tcase_add_test(tc_core, test_div388);
  tcase_add_test(tc_core, test_div389);
  tcase_add_test(tc_core, test_div390);
  tcase_add_test(tc_core, test_div391);
  tcase_add_test(tc_core, test_div392);
  tcase_add_test(tc_core, test_div393);
  tcase_add_test(tc_core, test_div394);
  tcase_add_test(tc_core, test_div395);
  tcase_add_test(tc_core, test_div396);
  tcase_add_test(tc_core, test_div397);
  tcase_add_test(tc_core, test_div398);
  tcase_add_test(tc_core, test_div399);
  tcase_add_test(tc_core, test_div400);

  suite_add_tcase(s, tc_core);
  return s;
}
