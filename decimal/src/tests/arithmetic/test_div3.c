
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../s21_decimal.h"
#include "../test.h"

// #define __DEBUG

START_TEST(test_div801) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // -660234687618869479981990980.21
  s21_decimal decimal_check = {
      {0x2AAAAAA5, 0x55555556, 0xD5555555, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div802) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // 660234687618869479981990980.21
  s21_decimal decimal_check = {{0x2AAAAAA5, 0x55555556, 0xD5555555, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div803) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div804) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div805) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div806) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div807) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div808) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div809) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // -999999999767169.3564003404797
  s21_decimal decimal_check = {
      {0xF22ACBFD, 0x1DD53402, 0x204FCE5E, 0x800D0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div810) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 999999999767169.3564003404797
  s21_decimal decimal_check = {{0xF22ACBFD, 0x1DD53402, 0x204FCE5E, 0xD0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div811) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // -922337203685477580850000000
  s21_decimal decimal_check = {{0x2FAF080, 0x0, 0x2FAF080, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div812) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // 922337203685477580850000000
  s21_decimal decimal_check = {{0x2FAF080, 0x0, 0x2FAF080, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div813) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // -184467440737095516170000
  s21_decimal decimal_check = {{0x2710, 0x0, 0x2710, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div814) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // 184467440737095516170000
  s21_decimal decimal_check = {{0x2710, 0x0, 0x2710, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div815) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -922337203900225945700000000
  s21_decimal decimal_check = {{0x5F5E100, 0x2FAF080, 0x2FAF080, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div816) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // 922337203900225945700000000
  s21_decimal decimal_check = {{0x5F5E100, 0x2FAF080, 0x2FAF080, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div817) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // -39618043061438312630182477064
  s21_decimal decimal_check = {
      {0x184BFD08, 0xD77F2AFD, 0x800346F1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div818) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // 39618043061438312630182477064
  s21_decimal decimal_check = {{0x184BFD08, 0xD77F2AFD, 0x800346F1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div819) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // -27670116117006778371000000001
  s21_decimal decimal_check = {
      {0xB2D05E01, 0x59682F00, 0x59682F00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div820) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // 27670116117006778371000000001
  s21_decimal decimal_check = {{0xB2D05E01, 0x59682F00, 0x59682F00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div821) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -4682356115670313918263711.45
  s21_decimal decimal_check = {{0x22DA6249, 0x5D63B5E2, 0x18350BF, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div822) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // 4682356115670313918263711.45
  s21_decimal decimal_check = {{0x22DA6249, 0x5D63B5E2, 0x18350BF, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div823) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // -4951760157141521099864932352
  s21_decimal decimal_check = {{0x10000000, 0x0, 0x10000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div824) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // 4951760157141521099864932352
  s21_decimal decimal_check = {{0x10000000, 0x0, 0x10000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div825) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // -39574506750381787011907551265
  s21_decimal decimal_check = {
      {0x7DD38021, 0xB0B822C8, 0x7FDF43C5, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div826) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // 39574506750381787011907551265
  s21_decimal decimal_check = {{0x7DD38021, 0xB0B822C8, 0x7FDF43C5, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div827) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // -39614081257132168798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div828) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 39614081257132168798919458816
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div829) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // -3961408125713216879891945881.6
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div830) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // 3961408125713216879891945881.6
  s21_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div831) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div832) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div833) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div834) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div835) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // 27.72032138750275693363031333
  s21_decimal decimal_check = {{0xFE6B6D25, 0x5A04B66B, 0x8F4F8A3, 0x1A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div836) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // -27.72032138750275693363031333
  s21_decimal decimal_check = {{0xFE6B6D25, 0x5A04B66B, 0x8F4F8A3, 0x801A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div837) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // -10834552318819459802.629269221
  s21_decimal decimal_check = {
      {0xD4A5E6E5, 0x193D94B2, 0x230221B2, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div838) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // 10834552318819459802.629269221
  s21_decimal decimal_check = {{0xD4A5E6E5, 0x193D94B2, 0x230221B2, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div839) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // -63214999029983678345.745456759
  s21_decimal decimal_check = {
      {0xCA1ADE77, 0x194F6961, 0xCC4238BC, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div840) {
  // -39614081257132168798919458816
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 63214999029983678345.745456759
  s21_decimal decimal_check = {{0xCA1ADE77, 0x194F6961, 0xCC4238BC, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div841) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div842) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div843) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 5.0000000000000000000000000001
  s21_decimal decimal_check = {{0x50000001, 0x36B90BE5, 0xA18F07D7, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div844) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -5.0000000000000000000000000001
  s21_decimal decimal_check = {
      {0x50000001, 0x36B90BE5, 0xA18F07D7, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div845) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div846) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div847) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.5
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div848) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -1.5
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div849) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.9999999999999999999457898914
  s21_decimal decimal_check = {{0xEFB031A2, 0x3E250260, 0x204FCE5E, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div850) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.9999999999999999999457898914
  s21_decimal decimal_check = {
      {0xEFB031A2, 0x3E250260, 0x204FCE5E, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div851) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div852) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div853) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 10000000000000000000000000000
  s21_decimal decimal_check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div854) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -10000000000000000000000000000
  s21_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div855) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 9223372034707292160.5
  s21_decimal decimal_check = {{0x5, 0xFFFFFFFB, 0x4, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div856) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // -9223372034707292160.5
  s21_decimal decimal_check = {{0x5, 0xFFFFFFFB, 0x4, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div857) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 0.5000000001164153218269348145
  s21_decimal decimal_check = {{0xA7128131, 0x2F3A685F, 0x1027E72F, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div858) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000001164153218269348145
  s21_decimal decimal_check = {
      {0xA7128131, 0x2F3A685F, 0x1027E72F, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div859) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 9223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div860) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -9223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div861) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div862) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div863) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 4611686018964258816.0625
  s21_decimal decimal_check = {{0x271, 0x4E2, 0x9C4, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div864) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -4611686018964258816.0625
  s21_decimal decimal_check = {{0x271, 0x4E2, 0x9C4, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div865) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div866) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div867) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 19807040628566084398385987584
  s21_decimal decimal_check = {{0x0, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div868) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -19807040628566084398385987584
  s21_decimal decimal_check = {{0x0, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div869) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 19807040628566084398385988574
  s21_decimal decimal_check = {{0x3DE, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div870) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -19807040628566084398385988574
  s21_decimal decimal_check = {{0x3DE, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div871) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 19807040628566084398385987585
  s21_decimal decimal_check = {{0x1, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div872) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -19807040628566084398385987585
  s21_decimal decimal_check = {{0x1, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div873) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 39614081257132168796771975164
  s21_decimal decimal_check = {{0xFFFFFFFC, 0xFFFFFFFF, 0x7FFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div874) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -39614081257132168796771975164
  s21_decimal decimal_check = {
      {0xFFFFFFFC, 0xFFFFFFFF, 0x7FFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div875) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div876) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div877) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div878) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div879) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div880) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div881) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 39614081257132168796771975172
  s21_decimal decimal_check = {{0x4, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div882) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -39614081257132168796771975172
  s21_decimal decimal_check = {{0x4, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div883) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 5000000000000000000000000000.1
  s21_decimal decimal_check = {{0x50000001, 0x36B90BE5, 0xA18F07D7, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div884) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -5000000000000000000000000000.1
  s21_decimal decimal_check = {
      {0x50000001, 0x36B90BE5, 0xA18F07D7, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div885) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 660234687618869479946199586.08
  s21_decimal decimal_check = {{0x55555550, 0x55555555, 0xD5555555, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div886) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // -660234687618869479946199586.08
  s21_decimal decimal_check = {
      {0x55555550, 0x55555555, 0xD5555555, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div887) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div888) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div889) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div890) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div891) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div892) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div893) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 999999999767169.3563461303711
  s21_decimal decimal_check = {{0xD1DAFD9F, 0x1DD53402, 0x204FCE5E, 0xD0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div894) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -999999999767169.3563461303711
  s21_decimal decimal_check = {
      {0xD1DAFD9F, 0x1DD53402, 0x204FCE5E, 0x800D0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div895) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 922337203685477580800000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x2FAF080, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div896) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // -922337203685477580800000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x2FAF080, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div897) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 184467440737095516160000
  s21_decimal decimal_check = {{0x0, 0x0, 0x2710, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div898) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // -184467440737095516160000
  s21_decimal decimal_check = {{0x0, 0x0, 0x2710, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div899) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 922337203900225945650000000
  s21_decimal decimal_check = {{0x2FAF080, 0x2FAF080, 0x2FAF080, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div900) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // -922337203900225945650000000
  s21_decimal decimal_check = {{0x2FAF080, 0x2FAF080, 0x2FAF080, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div901) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // 39618043061438312628034778646
  s21_decimal decimal_check = {{0x9848B616, 0xD77F2AFC, 0x800346F1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div902) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // -39618043061438312628034778646
  s21_decimal decimal_check = {
      {0x9848B616, 0xD77F2AFC, 0x800346F1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div903) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // 27670116117006778369500000000
  s21_decimal decimal_check = {{0x59682F00, 0x59682F00, 0x59682F00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div904) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // -27670116117006778369500000000
  s21_decimal decimal_check = {
      {0x59682F00, 0x59682F00, 0x59682F00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div905) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 4682356115670313918009880.4164
  s21_decimal decimal_check = {{0x602D9C4, 0x7AF30C55, 0x974B8AC0, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div906) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -4682356115670313918009880.4164
  s21_decimal decimal_check = {{0x602D9C4, 0x7AF30C55, 0x974B8AC0, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div907) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // 4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div908) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // -4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div909) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 39574506750381787009762212955
  s21_decimal decimal_check = {{0xFDF43C5B, 0xB0B822C7, 0x7FDF43C5, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div910) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // -39574506750381787009762212955
  s21_decimal decimal_check = {
      {0xFDF43C5B, 0xB0B822C7, 0x7FDF43C5, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div911) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // 39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div912) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div913) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // 3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div914) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // -3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div915) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div916) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div917) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div918) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div919) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // -27.720321387502756932127591696
  s21_decimal decimal_check = {
      {0x96A08D10, 0x842F2037, 0x5991B661, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div920) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // 27.720321387502756932127591696
  s21_decimal decimal_check = {{0x96A08D10, 0x842F2037, 0x5991B661, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div921) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // 10834552318819459802.041926963
  s21_decimal decimal_check = {{0xB1A3C533, 0x193D94B2, 0x230221B2, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div922) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // -10834552318819459802.041926963
  s21_decimal decimal_check = {
      {0xB1A3C533, 0x193D94B2, 0x230221B2, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div923) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // 63214999029983678342.318564795
  s21_decimal decimal_check = {{0xFDD8A5BB, 0x194F6960, 0xCC4238BC, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div924) {
  // 39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -63214999029983678342.318564795
  s21_decimal decimal_check = {
      {0xFDD8A5BB, 0x194F6960, 0xCC4238BC, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div925) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div926) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div927) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -5.0000000000000000000000000001
  s21_decimal decimal_check = {
      {0x50000001, 0x36B90BE5, 0xA18F07D7, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div928) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 5.0000000000000000000000000001
  s21_decimal decimal_check = {{0x50000001, 0x36B90BE5, 0xA18F07D7, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div929) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div930) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div931) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -1.5
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div932) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 1.5
  s21_decimal decimal_check = {{0xF, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div933) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.9999999999999999999457898914
  s21_decimal decimal_check = {
      {0xEFB031A2, 0x3E250260, 0x204FCE5E, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div934) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.9999999999999999999457898914
  s21_decimal decimal_check = {{0xEFB031A2, 0x3E250260, 0x204FCE5E, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div935) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div936) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div937) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -10000000000000000000000000000
  s21_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div938) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 10000000000000000000000000000
  s21_decimal decimal_check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div939) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // -9223372034707292160.5
  s21_decimal decimal_check = {{0x5, 0xFFFFFFFB, 0x4, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div940) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // 9223372034707292160.5
  s21_decimal decimal_check = {{0x5, 0xFFFFFFFB, 0x4, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div941) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // -0.5000000001164153218269348145
  s21_decimal decimal_check = {
      {0xA7128131, 0x2F3A685F, 0x1027E72F, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div942) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 0.5000000001164153218269348145
  s21_decimal decimal_check = {{0xA7128131, 0x2F3A685F, 0x1027E72F, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div943) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // -9223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div944) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // 9223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div945) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // -18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div946) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // 18446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div947) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // -4611686018964258816.0625
  s21_decimal decimal_check = {{0x271, 0x4E2, 0x9C4, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div948) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // 4611686018964258816.0625
  s21_decimal decimal_check = {{0x271, 0x4E2, 0x9C4, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div949) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div950) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div951) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // -19807040628566084398385987584
  s21_decimal decimal_check = {{0x0, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div952) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 19807040628566084398385987584
  s21_decimal decimal_check = {{0x0, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div953) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -19807040628566084398385988574
  s21_decimal decimal_check = {{0x3DE, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div954) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 19807040628566084398385988574
  s21_decimal decimal_check = {{0x3DE, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div955) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -19807040628566084398385987585
  s21_decimal decimal_check = {{0x1, 0x0, 0x40000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div956) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 19807040628566084398385987585
  s21_decimal decimal_check = {{0x1, 0x0, 0x40000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div957) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -39614081257132168796771975164
  s21_decimal decimal_check = {
      {0xFFFFFFFC, 0xFFFFFFFF, 0x7FFFFFFF, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div958) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 39614081257132168796771975164
  s21_decimal decimal_check = {{0xFFFFFFFC, 0xFFFFFFFF, 0x7FFFFFFF, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div959) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div960) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div961) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div962) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div963) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div964) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div965) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -39614081257132168796771975172
  s21_decimal decimal_check = {{0x4, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div966) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 39614081257132168796771975172
  s21_decimal decimal_check = {{0x4, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div967) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -5000000000000000000000000000.1
  s21_decimal decimal_check = {
      {0x50000001, 0x36B90BE5, 0xA18F07D7, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div968) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 5000000000000000000000000000.1
  s21_decimal decimal_check = {{0x50000001, 0x36B90BE5, 0xA18F07D7, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div969) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // -660234687618869479946199586.08
  s21_decimal decimal_check = {
      {0x55555550, 0x55555555, 0xD5555555, 0x80020000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div970) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // 660234687618869479946199586.08
  s21_decimal decimal_check = {{0x55555550, 0x55555555, 0xD5555555, 0x20000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div971) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div972) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div973) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div974) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div975) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // overflow
  int code_check = TEST_ARITHMETIC_SMALL;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div976) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // overflow
  int code_check = TEST_ARITHMETIC_BIG;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div977) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // -999999999767169.3563461303711
  s21_decimal decimal_check = {
      {0xD1DAFD9F, 0x1DD53402, 0x204FCE5E, 0x800D0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div978) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 999999999767169.3563461303711
  s21_decimal decimal_check = {{0xD1DAFD9F, 0x1DD53402, 0x204FCE5E, 0xD0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div979) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // -922337203685477580800000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x2FAF080, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div980) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // 922337203685477580800000000
  s21_decimal decimal_check = {{0x0, 0x0, 0x2FAF080, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div981) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // -184467440737095516160000
  s21_decimal decimal_check = {{0x0, 0x0, 0x2710, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div982) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // 184467440737095516160000
  s21_decimal decimal_check = {{0x0, 0x0, 0x2710, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div983) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -922337203900225945650000000
  s21_decimal decimal_check = {{0x2FAF080, 0x2FAF080, 0x2FAF080, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div984) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // 922337203900225945650000000
  s21_decimal decimal_check = {{0x2FAF080, 0x2FAF080, 0x2FAF080, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div985) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // -39618043061438312628034778646
  s21_decimal decimal_check = {
      {0x9848B616, 0xD77F2AFC, 0x800346F1, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div986) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // 39618043061438312628034778646
  s21_decimal decimal_check = {{0x9848B616, 0xD77F2AFC, 0x800346F1, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div987) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // -27670116117006778369500000000
  s21_decimal decimal_check = {
      {0x59682F00, 0x59682F00, 0x59682F00, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div988) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // 27670116117006778369500000000
  s21_decimal decimal_check = {{0x59682F00, 0x59682F00, 0x59682F00, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div989) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -4682356115670313918009880.4164
  s21_decimal decimal_check = {{0x602D9C4, 0x7AF30C55, 0x974B8AC0, 0x80040000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div990) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // 4682356115670313918009880.4164
  s21_decimal decimal_check = {{0x602D9C4, 0x7AF30C55, 0x974B8AC0, 0x40000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div991) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // -4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div992) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // 4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div993) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // -39574506750381787009762212955
  s21_decimal decimal_check = {
      {0xFDF43C5B, 0xB0B822C7, 0x7FDF43C5, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div994) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // 39574506750381787009762212955
  s21_decimal decimal_check = {{0xFDF43C5B, 0xB0B822C7, 0x7FDF43C5, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div995) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // -39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div996) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div997) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // -3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div998) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // 3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div999) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1000) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1001) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1002) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1003) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // 27.720321387502756932127591696
  s21_decimal decimal_check = {{0x96A08D10, 0x842F2037, 0x5991B661, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1004) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // -27.720321387502756932127591696
  s21_decimal decimal_check = {
      {0x96A08D10, 0x842F2037, 0x5991B661, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1005) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // -10834552318819459802.041926963
  s21_decimal decimal_check = {
      {0xB1A3C533, 0x193D94B2, 0x230221B2, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1006) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // 10834552318819459802.041926963
  s21_decimal decimal_check = {{0xB1A3C533, 0x193D94B2, 0x230221B2, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1007) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // -63214999029983678342.318564795
  s21_decimal decimal_check = {
      {0xFDD8A5BB, 0x194F6960, 0xCC4238BC, 0x80090000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1008) {
  // -39614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 63214999029983678342.318564795
  s21_decimal decimal_check = {{0xFDD8A5BB, 0x194F6960, 0xCC4238BC, 0x90000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1009) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1010) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1011) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.0000000000000000000000000005
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1012) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.0000000000000000000000000005
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1013) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1014) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1015) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000000000000002
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1016) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000000000000000002
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1017) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1018) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1019) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1020) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1021) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1022) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1023) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 0.000000000922337203470729216
  s21_decimal decimal_check = {{0xC0000000, 0xCCCCCCC, 0x0, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1024) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // -0.000000000922337203470729216
  s21_decimal decimal_check = {{0xC0000000, 0xCCCCCCC, 0x0, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1025) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1026) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1027) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 0.0000000009223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1028) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -0.0000000009223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1029) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 0.0000000018446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1030) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -0.0000000018446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1031) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 0.0000000004611686018964258816
  s21_decimal decimal_check = {{0x20000000, 0x40000000, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1032) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -0.0000000004611686018964258816
  s21_decimal decimal_check = {{0x20000000, 0x40000000, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1033) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // 0.7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1034) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -0.7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1035) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // 1.9807040628566084398385987584
  s21_decimal decimal_check = {{0x0, 0x0, 0x40000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1036) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // -1.9807040628566084398385987584
  s21_decimal decimal_check = {{0x0, 0x0, 0x40000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1037) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 1.9807040628566084398385988574
  s21_decimal decimal_check = {{0x3DE, 0x0, 0x40000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1038) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -1.9807040628566084398385988574
  s21_decimal decimal_check = {{0x3DE, 0x0, 0x40000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1039) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 1.9807040628566084398385987585
  s21_decimal decimal_check = {{0x1, 0x0, 0x40000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1040) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -1.9807040628566084398385987585
  s21_decimal decimal_check = {{0x1, 0x0, 0x40000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1041) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 3.9614081257132168796771975164
  s21_decimal decimal_check = {{0xFFFFFFFC, 0xFFFFFFFF, 0x7FFFFFFF, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1042) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -3.9614081257132168796771975164
  s21_decimal decimal_check = {
      {0xFFFFFFFC, 0xFFFFFFFF, 0x7FFFFFFF, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1043) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // 4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1044) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // -4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1045) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1046) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1047) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // 3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1048) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1049) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 3.9614081257132168796771975172
  s21_decimal decimal_check = {{0x4, 0x0, 0x80000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1050) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -3.9614081257132168796771975172
  s21_decimal decimal_check = {{0x4, 0x0, 0x80000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1051) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1052) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1053) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 0.0660234687618869479946199586
  s21_decimal decimal_check = {{0x22222222, 0x22222222, 0x2222222, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1054) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // -0.0660234687618869479946199586
  s21_decimal decimal_check = {{0x22222222, 0x22222222, 0x2222222, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1055) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // 7.922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1056) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -7.922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1057) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // 3961.4081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x190000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1058) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // -3961.4081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80190000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1059) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // 208.49516451122194103564197457
  s21_decimal decimal_check = {{0x79435E51, 0x9435E50D, 0x435E50D7, 0x1A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1060) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // -208.49516451122194103564197457
  s21_decimal decimal_check = {
      {0x79435E51, 0x9435E50D, 0x435E50D7, 0x801A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1061) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 0.0000000000000999999999767169
  s21_decimal decimal_check = {{0xA4C2F281, 0x38D7E, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1062) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // -0.0000000000000999999999767169
  s21_decimal decimal_check = {{0xA4C2F281, 0x38D7E, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1063) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 0.09223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x140000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1064) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // -0.09223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80140000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1065) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 0.000018446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x180000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1066) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // -0.000018446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80180000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1067) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 0.092233720390022594565
  s21_decimal decimal_check = {{0x5, 0x5, 0x5, 0x150000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1068) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // -0.092233720390022594565
  s21_decimal decimal_check = {{0x5, 0x5, 0x5, 0x80150000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1069) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // 3.9618043061438312628034778646
  s21_decimal decimal_check = {{0x9848B616, 0xD77F2AFC, 0x800346F1, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1070) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // -3.9618043061438312628034778646
  s21_decimal decimal_check = {
      {0x9848B616, 0xD77F2AFC, 0x800346F1, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1071) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // 2.76701161170067783695
  s21_decimal decimal_check = {{0xF, 0xF, 0xF, 0x140000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1072) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // -2.76701161170067783695
  s21_decimal decimal_check = {{0xF, 0xF, 0xF, 0x80140000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1073) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 0.000468235611567031391800988
  s21_decimal decimal_check = {{0x33BECE9C, 0x1A761D9F, 0x6327, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1074) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -0.000468235611567031391800988
  s21_decimal decimal_check = {{0x33BECE9C, 0x1A761D9F, 0x6327, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1075) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // 0.4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1076) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // -0.4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1077) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 3.9574506750381787009762212955
  s21_decimal decimal_check = {{0xFDF43C5B, 0xB0B822C7, 0x7FDF43C5, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1078) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // -3.9574506750381787009762212955
  s21_decimal decimal_check = {
      {0xFDF43C5B, 0xB0B822C7, 0x7FDF43C5, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1079) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1080) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1081) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // 0.3961408125713216879677197517
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCCCCCCC, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1082) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // -0.3961408125713216879677197517
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCCCCCCC, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1083) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1084) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1085) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1086) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1087) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // -0.0000000000000000000000000028
  s21_decimal decimal_check = {{0x1C, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1088) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // 0.0000000000000000000000000028
  s21_decimal decimal_check = {{0x1C, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1089) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // 0.0000000010834552318819459802
  s21_decimal decimal_check = {{0x179E62DA, 0x965C0FEE, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1090) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // -0.0000000010834552318819459802
  s21_decimal decimal_check = {{0x179E62DA, 0x965C0FEE, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1091) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // 0.0000000063214999029983678342
  s21_decimal decimal_check = {{0xBAD70F86, 0x6D48CAB0, 0x3, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1092) {
  // 3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -0.0000000063214999029983678342
  s21_decimal decimal_check = {{0xBAD70F86, 0x6D48CAB0, 0x3, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1093) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1094) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1095) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.0000000000000000000000000005
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1096) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 0.0000000000000000000000000005
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1097) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1098) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1099) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // -0.0000000000000000000000000002
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1100) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 0.0000000000000000000000000002
  s21_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1101) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1102) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1103) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1104) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1105) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1106) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1107) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // -0.000000000922337203470729216
  s21_decimal decimal_check = {{0xC0000000, 0xCCCCCCC, 0x0, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1108) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // 0.000000000922337203470729216
  s21_decimal decimal_check = {{0xC0000000, 0xCCCCCCC, 0x0, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1109) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1110) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1111) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // -0.0000000009223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1112) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // 0.0000000009223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1113) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // -0.0000000018446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1114) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // 0.0000000018446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1115) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // -0.0000000004611686018964258816
  s21_decimal decimal_check = {{0x20000000, 0x40000000, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1116) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // 0.0000000004611686018964258816
  s21_decimal decimal_check = {{0x20000000, 0x40000000, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1117) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // -0.7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1118) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 0.7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1119) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // -1.9807040628566084398385987584
  s21_decimal decimal_check = {{0x0, 0x0, 0x40000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1120) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 1.9807040628566084398385987584
  s21_decimal decimal_check = {{0x0, 0x0, 0x40000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1121) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -1.9807040628566084398385988574
  s21_decimal decimal_check = {{0x3DE, 0x0, 0x40000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1122) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 1.9807040628566084398385988574
  s21_decimal decimal_check = {{0x3DE, 0x0, 0x40000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1123) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -1.9807040628566084398385987585
  s21_decimal decimal_check = {{0x1, 0x0, 0x40000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1124) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 1.9807040628566084398385987585
  s21_decimal decimal_check = {{0x1, 0x0, 0x40000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1125) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -3.9614081257132168796771975164
  s21_decimal decimal_check = {
      {0xFFFFFFFC, 0xFFFFFFFF, 0x7FFFFFFF, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1126) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 3.9614081257132168796771975164
  s21_decimal decimal_check = {{0xFFFFFFFC, 0xFFFFFFFF, 0x7FFFFFFF, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1127) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x1C0000}};
  // -4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1128) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -0.0000000000000000000000000008
  s21_decimal decimal2 = {{0x8, 0x0, 0x0, 0x801C0000}};
  // 4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1129) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1130) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 39614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1131) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x1C0000}};
  // -3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1132) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // 3961408125713216879677197516.8
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1133) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -3.9614081257132168796771975172
  s21_decimal decimal_check = {{0x4, 0x0, 0x80000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1134) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 3.9614081257132168796771975172
  s21_decimal decimal_check = {{0x4, 0x0, 0x80000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1135) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1136) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 0.5
  s21_decimal decimal_check = {{0x5, 0x0, 0x0, 0x10000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1137) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // -0.0660234687618869479946199586
  s21_decimal decimal_check = {{0x22222222, 0x22222222, 0x2222222, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1138) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x801B0000}};
  // 0.0660234687618869479946199586
  s21_decimal decimal_check = {{0x22222222, 0x22222222, 0x2222222, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1139) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -7.922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1140) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -0.5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 7.922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1141) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // -3961.4081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80190000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1142) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80030000}};
  // 3961.4081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x190000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1143) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x30000}};
  // -208.49516451122194103564197457
  s21_decimal decimal_check = {
      {0x79435E51, 0x9435E50D, 0x435E50D7, 0x801A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1144) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // 208.49516451122194103564197457
  s21_decimal decimal_check = {{0x79435E51, 0x9435E50D, 0x435E50D7, 0x1A0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1145) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // -0.0000000000000999999999767169
  s21_decimal decimal_check = {{0xA4C2F281, 0x38D7E, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1146) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 0.0000000000000999999999767169
  s21_decimal decimal_check = {{0xA4C2F281, 0x38D7E, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1147) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // -0.09223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80140000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1148) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80080000}};
  // 0.09223372036854775808
  s21_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x140000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1149) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // -0.000018446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80180000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1150) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // 0.000018446744073709551616
  s21_decimal decimal_check = {{0x0, 0x0, 0x1, 0x180000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1151) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -0.092233720390022594565
  s21_decimal decimal_check = {{0x5, 0x5, 0x5, 0x80150000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1152) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // 0.092233720390022594565
  s21_decimal decimal_check = {{0x5, 0x5, 0x5, 0x150000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1153) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // -3.9618043061438312628034778646
  s21_decimal decimal_check = {
      {0x9848B616, 0xD77F2AFC, 0x800346F1, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1154) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // 3.9618043061438312628034778646
  s21_decimal decimal_check = {{0x9848B616, 0xD77F2AFC, 0x800346F1, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1155) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // -2.76701161170067783695
  s21_decimal decimal_check = {{0xF, 0xF, 0xF, 0x80140000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1156) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // 2.76701161170067783695
  s21_decimal decimal_check = {{0xF, 0xF, 0xF, 0x140000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1157) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // -0.000468235611567031391800988
  s21_decimal decimal_check = {{0x33BECE9C, 0x1A761D9F, 0x6327, 0x801B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1158) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // 0.000468235611567031391800988
  s21_decimal decimal_check = {{0x33BECE9C, 0x1A761D9F, 0x6327, 0x1B0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1159) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // -0.4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1160) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // 0.4951760157141521099596496896
  s21_decimal decimal_check = {{0x0, 0x0, 0x10000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1161) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // -3.9574506750381787009762212955
  s21_decimal decimal_check = {
      {0xFDF43C5B, 0xB0B822C7, 0x7FDF43C5, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1162) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // 3.9574506750381787009762212955
  s21_decimal decimal_check = {{0xFDF43C5B, 0xB0B822C7, 0x7FDF43C5, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1163) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  // -3.9614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1164) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1165) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x0}};
  // -0.3961408125713216879677197517
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCCCCCCC, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1166) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // 0.3961408125713216879677197517
  s21_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCCCCCCC, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1167) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1168) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1169) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1170) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // division by zero
  int code_check = TEST_ARITHMETIC_ZERO_DIV;

  test_div_fail1(decimal1, decimal2, code_check);
}

START_TEST(test_div1171) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // 0.0000000000000000000000000028
  s21_decimal decimal_check = {{0x1C, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1172) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // -0.0000000000000000000000000028
  s21_decimal decimal_check = {{0x1C, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1173) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // -0.0000000010834552318819459802
  s21_decimal decimal_check = {{0x179E62DA, 0x965C0FEE, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1174) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // 0.0000000010834552318819459802
  s21_decimal decimal_check = {{0x179E62DA, 0x965C0FEE, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1175) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // -0.0000000063214999029983678342
  s21_decimal decimal_check = {{0xBAD70F86, 0x6D48CAB0, 0x3, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1176) {
  // -3.9614081257132168796771975168
  s21_decimal decimal1 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 0.0000000063214999029983678342
  s21_decimal decimal_check = {{0xBAD70F86, 0x6D48CAB0, 0x3, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1177) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000542101086
  s21_decimal decimal_check = {{0x204FCE5E, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1178) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000542101086
  s21_decimal decimal_check = {{0x204FCE5E, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1179) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 0.0000000000000000005421010864
  s21_decimal decimal_check = {{0x431E0FB0, 0x1, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1180) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.0000000000000000005421010864
  s21_decimal decimal_check = {{0x431E0FB0, 0x1, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1181) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000542101086
  s21_decimal decimal_check = {{0x204FCE5E, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1182) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000542101086
  s21_decimal decimal_check = {{0x204FCE5E, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1183) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 0.0000000000000000001626303259
  s21_decimal decimal_check = {{0x60EF6B1B, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1184) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -0.0000000000000000001626303259
  s21_decimal decimal_check = {{0x60EF6B1B, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1185) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000001084202173
  s21_decimal decimal_check = {{0x409F9CBD, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1186) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -39614081257132168798919458816
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000001084202173
  s21_decimal decimal_check = {{0x409F9CBD, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1187) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0.0000000000000000001084202173
  s21_decimal decimal_check = {{0x409F9CBD, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1188) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000001084202173
  s21_decimal decimal_check = {{0x409F9CBD, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1189) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 1084202172.7379399236781765786
  s21_decimal decimal_check = {{0xBA8A749A, 0x8C4906F8, 0x23084F67, 0x130000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1190) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  // -1084202172.7379399236781765786
  s21_decimal decimal_check = {
      {0xBA8A749A, 0x8C4906F8, 0x23084F67, 0x80130000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1191) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1192) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x80000000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1193) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000542101086
  s21_decimal decimal_check = {{0x204FCE5E, 0x0, 0x0, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1194) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -0.0000000000000000000542101086
  s21_decimal decimal_check = {{0x204FCE5E, 0x0, 0x0, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1195) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.0000000002328306436538696289
  s21_decimal decimal_check = {{0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1196) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -1.0000000002328306436538696289
  s21_decimal decimal_check = {
      {0x4E250261, 0x5E74D0BF, 0x204FCE5E, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1197) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 2.0000000004656612873077392578
  s21_decimal decimal_check = {{0x9C4A04C2, 0xBCE9A17E, 0x409F9CBC, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1198) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -2.0000000004656612873077392578
  s21_decimal decimal_check = {
      {0x9C4A04C2, 0xBCE9A17E, 0x409F9CBC, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1199) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // 8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x0}};
  // 0.5000000001746229827607310124
  s21_decimal decimal_check = {{0x42B9AF2C, 0x374E5BF7, 0x1027E72F, 0x1C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div1200) {
  // 4294967297
  s21_decimal decimal1 = {{0x1, 0x1, 0x0, 0x0}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -0.5000000001746229827607310124
  s21_decimal decimal_check = {
      {0x42B9AF2C, 0x374E5BF7, 0x1027E72F, 0x801C0000}};

  test_div(decimal1, decimal2, decimal_check);
}

Suite *div_suite3(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("div3");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_div801);
  tcase_add_test(tc_core, test_div802);
  tcase_add_test(tc_core, test_div803);
  tcase_add_test(tc_core, test_div804);
  tcase_add_test(tc_core, test_div805);
  tcase_add_test(tc_core, test_div806);
  tcase_add_test(tc_core, test_div807);
  tcase_add_test(tc_core, test_div808);
  tcase_add_test(tc_core, test_div809);
  tcase_add_test(tc_core, test_div810);
  tcase_add_test(tc_core, test_div811);
  tcase_add_test(tc_core, test_div812);
  tcase_add_test(tc_core, test_div813);
  tcase_add_test(tc_core, test_div814);
  tcase_add_test(tc_core, test_div815);
  tcase_add_test(tc_core, test_div816);
  tcase_add_test(tc_core, test_div817);
  tcase_add_test(tc_core, test_div818);
  tcase_add_test(tc_core, test_div819);
  tcase_add_test(tc_core, test_div820);
  tcase_add_test(tc_core, test_div821);
  tcase_add_test(tc_core, test_div822);
  tcase_add_test(tc_core, test_div823);
  tcase_add_test(tc_core, test_div824);
  tcase_add_test(tc_core, test_div825);
  tcase_add_test(tc_core, test_div826);
  tcase_add_test(tc_core, test_div827);
  tcase_add_test(tc_core, test_div828);
  tcase_add_test(tc_core, test_div829);
  tcase_add_test(tc_core, test_div830);
  tcase_add_test(tc_core, test_div831);
  tcase_add_test(tc_core, test_div832);
  tcase_add_test(tc_core, test_div833);
  tcase_add_test(tc_core, test_div834);
  tcase_add_test(tc_core, test_div835);
  tcase_add_test(tc_core, test_div836);
  tcase_add_test(tc_core, test_div837);
  tcase_add_test(tc_core, test_div838);
  tcase_add_test(tc_core, test_div839);
  tcase_add_test(tc_core, test_div840);
  tcase_add_test(tc_core, test_div841);
  tcase_add_test(tc_core, test_div842);
  tcase_add_test(tc_core, test_div843);
  tcase_add_test(tc_core, test_div844);
  tcase_add_test(tc_core, test_div845);
  tcase_add_test(tc_core, test_div846);
  tcase_add_test(tc_core, test_div847);
  tcase_add_test(tc_core, test_div848);
  tcase_add_test(tc_core, test_div849);
  tcase_add_test(tc_core, test_div850);
  tcase_add_test(tc_core, test_div851);
  tcase_add_test(tc_core, test_div852);
  tcase_add_test(tc_core, test_div853);
  tcase_add_test(tc_core, test_div854);
  tcase_add_test(tc_core, test_div855);
  tcase_add_test(tc_core, test_div856);
  tcase_add_test(tc_core, test_div857);
  tcase_add_test(tc_core, test_div858);
  tcase_add_test(tc_core, test_div859);
  tcase_add_test(tc_core, test_div860);
  tcase_add_test(tc_core, test_div861);
  tcase_add_test(tc_core, test_div862);
  tcase_add_test(tc_core, test_div863);
  tcase_add_test(tc_core, test_div864);
  tcase_add_test(tc_core, test_div865);
  tcase_add_test(tc_core, test_div866);
  tcase_add_test(tc_core, test_div867);
  tcase_add_test(tc_core, test_div868);
  tcase_add_test(tc_core, test_div869);
  tcase_add_test(tc_core, test_div870);
  tcase_add_test(tc_core, test_div871);
  tcase_add_test(tc_core, test_div872);
  tcase_add_test(tc_core, test_div873);
  tcase_add_test(tc_core, test_div874);
  tcase_add_test(tc_core, test_div875);
  tcase_add_test(tc_core, test_div876);
  tcase_add_test(tc_core, test_div877);
  tcase_add_test(tc_core, test_div878);
  tcase_add_test(tc_core, test_div879);
  tcase_add_test(tc_core, test_div880);
  tcase_add_test(tc_core, test_div881);
  tcase_add_test(tc_core, test_div882);
  tcase_add_test(tc_core, test_div883);
  tcase_add_test(tc_core, test_div884);
  tcase_add_test(tc_core, test_div885);
  tcase_add_test(tc_core, test_div886);
  tcase_add_test(tc_core, test_div887);
  tcase_add_test(tc_core, test_div888);
  tcase_add_test(tc_core, test_div889);
  tcase_add_test(tc_core, test_div890);
  tcase_add_test(tc_core, test_div891);
  tcase_add_test(tc_core, test_div892);
  tcase_add_test(tc_core, test_div893);
  tcase_add_test(tc_core, test_div894);
  tcase_add_test(tc_core, test_div895);
  tcase_add_test(tc_core, test_div896);
  tcase_add_test(tc_core, test_div897);
  tcase_add_test(tc_core, test_div898);
  tcase_add_test(tc_core, test_div899);
  tcase_add_test(tc_core, test_div900);
  tcase_add_test(tc_core, test_div901);
  tcase_add_test(tc_core, test_div902);
  tcase_add_test(tc_core, test_div903);
  tcase_add_test(tc_core, test_div904);
  tcase_add_test(tc_core, test_div905);
  tcase_add_test(tc_core, test_div906);
  tcase_add_test(tc_core, test_div907);
  tcase_add_test(tc_core, test_div908);
  tcase_add_test(tc_core, test_div909);
  tcase_add_test(tc_core, test_div910);
  tcase_add_test(tc_core, test_div911);
  tcase_add_test(tc_core, test_div912);
  tcase_add_test(tc_core, test_div913);
  tcase_add_test(tc_core, test_div914);
  tcase_add_test(tc_core, test_div915);
  tcase_add_test(tc_core, test_div916);
  tcase_add_test(tc_core, test_div917);
  tcase_add_test(tc_core, test_div918);
  tcase_add_test(tc_core, test_div919);
  tcase_add_test(tc_core, test_div920);
  tcase_add_test(tc_core, test_div921);
  tcase_add_test(tc_core, test_div922);
  tcase_add_test(tc_core, test_div923);
  tcase_add_test(tc_core, test_div924);
  tcase_add_test(tc_core, test_div925);
  tcase_add_test(tc_core, test_div926);
  tcase_add_test(tc_core, test_div927);
  tcase_add_test(tc_core, test_div928);
  tcase_add_test(tc_core, test_div929);
  tcase_add_test(tc_core, test_div930);
  tcase_add_test(tc_core, test_div931);
  tcase_add_test(tc_core, test_div932);
  tcase_add_test(tc_core, test_div933);
  tcase_add_test(tc_core, test_div934);
  tcase_add_test(tc_core, test_div935);
  tcase_add_test(tc_core, test_div936);
  tcase_add_test(tc_core, test_div937);
  tcase_add_test(tc_core, test_div938);
  tcase_add_test(tc_core, test_div939);
  tcase_add_test(tc_core, test_div940);
  tcase_add_test(tc_core, test_div941);
  tcase_add_test(tc_core, test_div942);
  tcase_add_test(tc_core, test_div943);
  tcase_add_test(tc_core, test_div944);
  tcase_add_test(tc_core, test_div945);
  tcase_add_test(tc_core, test_div946);
  tcase_add_test(tc_core, test_div947);
  tcase_add_test(tc_core, test_div948);
  tcase_add_test(tc_core, test_div949);
  tcase_add_test(tc_core, test_div950);
  tcase_add_test(tc_core, test_div951);
  tcase_add_test(tc_core, test_div952);
  tcase_add_test(tc_core, test_div953);
  tcase_add_test(tc_core, test_div954);
  tcase_add_test(tc_core, test_div955);
  tcase_add_test(tc_core, test_div956);
  tcase_add_test(tc_core, test_div957);
  tcase_add_test(tc_core, test_div958);
  tcase_add_test(tc_core, test_div959);
  tcase_add_test(tc_core, test_div960);
  tcase_add_test(tc_core, test_div961);
  tcase_add_test(tc_core, test_div962);
  tcase_add_test(tc_core, test_div963);
  tcase_add_test(tc_core, test_div964);
  tcase_add_test(tc_core, test_div965);
  tcase_add_test(tc_core, test_div966);
  tcase_add_test(tc_core, test_div967);
  tcase_add_test(tc_core, test_div968);
  tcase_add_test(tc_core, test_div969);
  tcase_add_test(tc_core, test_div970);
  tcase_add_test(tc_core, test_div971);
  tcase_add_test(tc_core, test_div972);
  tcase_add_test(tc_core, test_div973);
  tcase_add_test(tc_core, test_div974);
  tcase_add_test(tc_core, test_div975);
  tcase_add_test(tc_core, test_div976);
  tcase_add_test(tc_core, test_div977);
  tcase_add_test(tc_core, test_div978);
  tcase_add_test(tc_core, test_div979);
  tcase_add_test(tc_core, test_div980);
  tcase_add_test(tc_core, test_div981);
  tcase_add_test(tc_core, test_div982);
  tcase_add_test(tc_core, test_div983);
  tcase_add_test(tc_core, test_div984);
  tcase_add_test(tc_core, test_div985);
  tcase_add_test(tc_core, test_div986);
  tcase_add_test(tc_core, test_div987);
  tcase_add_test(tc_core, test_div988);
  tcase_add_test(tc_core, test_div989);
  tcase_add_test(tc_core, test_div990);
  tcase_add_test(tc_core, test_div991);
  tcase_add_test(tc_core, test_div992);
  tcase_add_test(tc_core, test_div993);
  tcase_add_test(tc_core, test_div994);
  tcase_add_test(tc_core, test_div995);
  tcase_add_test(tc_core, test_div996);
  tcase_add_test(tc_core, test_div997);
  tcase_add_test(tc_core, test_div998);
  tcase_add_test(tc_core, test_div999);
  tcase_add_test(tc_core, test_div1000);
  tcase_add_test(tc_core, test_div1001);
  tcase_add_test(tc_core, test_div1002);
  tcase_add_test(tc_core, test_div1003);
  tcase_add_test(tc_core, test_div1004);
  tcase_add_test(tc_core, test_div1005);
  tcase_add_test(tc_core, test_div1006);
  tcase_add_test(tc_core, test_div1007);
  tcase_add_test(tc_core, test_div1008);
  tcase_add_test(tc_core, test_div1009);
  tcase_add_test(tc_core, test_div1010);
  tcase_add_test(tc_core, test_div1011);
  tcase_add_test(tc_core, test_div1012);
  tcase_add_test(tc_core, test_div1013);
  tcase_add_test(tc_core, test_div1014);
  tcase_add_test(tc_core, test_div1015);
  tcase_add_test(tc_core, test_div1016);
  tcase_add_test(tc_core, test_div1017);
  tcase_add_test(tc_core, test_div1018);
  tcase_add_test(tc_core, test_div1019);
  tcase_add_test(tc_core, test_div1020);
  tcase_add_test(tc_core, test_div1021);
  tcase_add_test(tc_core, test_div1022);
  tcase_add_test(tc_core, test_div1023);
  tcase_add_test(tc_core, test_div1024);
  tcase_add_test(tc_core, test_div1025);
  tcase_add_test(tc_core, test_div1026);
  tcase_add_test(tc_core, test_div1027);
  tcase_add_test(tc_core, test_div1028);
  tcase_add_test(tc_core, test_div1029);
  tcase_add_test(tc_core, test_div1030);
  tcase_add_test(tc_core, test_div1031);
  tcase_add_test(tc_core, test_div1032);
  tcase_add_test(tc_core, test_div1033);
  tcase_add_test(tc_core, test_div1034);
  tcase_add_test(tc_core, test_div1035);
  tcase_add_test(tc_core, test_div1036);
  tcase_add_test(tc_core, test_div1037);
  tcase_add_test(tc_core, test_div1038);
  tcase_add_test(tc_core, test_div1039);
  tcase_add_test(tc_core, test_div1040);
  tcase_add_test(tc_core, test_div1041);
  tcase_add_test(tc_core, test_div1042);
  tcase_add_test(tc_core, test_div1043);
  tcase_add_test(tc_core, test_div1044);
  tcase_add_test(tc_core, test_div1045);
  tcase_add_test(tc_core, test_div1046);
  tcase_add_test(tc_core, test_div1047);
  tcase_add_test(tc_core, test_div1048);
  tcase_add_test(tc_core, test_div1049);
  tcase_add_test(tc_core, test_div1050);
  tcase_add_test(tc_core, test_div1051);
  tcase_add_test(tc_core, test_div1052);
  tcase_add_test(tc_core, test_div1053);
  tcase_add_test(tc_core, test_div1054);
  tcase_add_test(tc_core, test_div1055);
  tcase_add_test(tc_core, test_div1056);
  tcase_add_test(tc_core, test_div1057);
  tcase_add_test(tc_core, test_div1058);
  tcase_add_test(tc_core, test_div1059);
  tcase_add_test(tc_core, test_div1060);
  tcase_add_test(tc_core, test_div1061);
  tcase_add_test(tc_core, test_div1062);
  tcase_add_test(tc_core, test_div1063);
  tcase_add_test(tc_core, test_div1064);
  tcase_add_test(tc_core, test_div1065);
  tcase_add_test(tc_core, test_div1066);
  tcase_add_test(tc_core, test_div1067);
  tcase_add_test(tc_core, test_div1068);
  tcase_add_test(tc_core, test_div1069);
  tcase_add_test(tc_core, test_div1070);
  tcase_add_test(tc_core, test_div1071);
  tcase_add_test(tc_core, test_div1072);
  tcase_add_test(tc_core, test_div1073);
  tcase_add_test(tc_core, test_div1074);
  tcase_add_test(tc_core, test_div1075);
  tcase_add_test(tc_core, test_div1076);
  tcase_add_test(tc_core, test_div1077);
  tcase_add_test(tc_core, test_div1078);
  tcase_add_test(tc_core, test_div1079);
  tcase_add_test(tc_core, test_div1080);
  tcase_add_test(tc_core, test_div1081);
  tcase_add_test(tc_core, test_div1082);
  tcase_add_test(tc_core, test_div1083);
  tcase_add_test(tc_core, test_div1084);
  tcase_add_test(tc_core, test_div1085);
  tcase_add_test(tc_core, test_div1086);
  tcase_add_test(tc_core, test_div1087);
  tcase_add_test(tc_core, test_div1088);
  tcase_add_test(tc_core, test_div1089);
  tcase_add_test(tc_core, test_div1090);
  tcase_add_test(tc_core, test_div1091);
  tcase_add_test(tc_core, test_div1092);
  tcase_add_test(tc_core, test_div1093);
  tcase_add_test(tc_core, test_div1094);
  tcase_add_test(tc_core, test_div1095);
  tcase_add_test(tc_core, test_div1096);
  tcase_add_test(tc_core, test_div1097);
  tcase_add_test(tc_core, test_div1098);
  tcase_add_test(tc_core, test_div1099);
  tcase_add_test(tc_core, test_div1100);
  tcase_add_test(tc_core, test_div1101);
  tcase_add_test(tc_core, test_div1102);
  tcase_add_test(tc_core, test_div1103);
  tcase_add_test(tc_core, test_div1104);
  tcase_add_test(tc_core, test_div1105);
  tcase_add_test(tc_core, test_div1106);
  tcase_add_test(tc_core, test_div1107);
  tcase_add_test(tc_core, test_div1108);
  tcase_add_test(tc_core, test_div1109);
  tcase_add_test(tc_core, test_div1110);
  tcase_add_test(tc_core, test_div1111);
  tcase_add_test(tc_core, test_div1112);
  tcase_add_test(tc_core, test_div1113);
  tcase_add_test(tc_core, test_div1114);
  tcase_add_test(tc_core, test_div1115);
  tcase_add_test(tc_core, test_div1116);
  tcase_add_test(tc_core, test_div1117);
  tcase_add_test(tc_core, test_div1118);
  tcase_add_test(tc_core, test_div1119);
  tcase_add_test(tc_core, test_div1120);
  tcase_add_test(tc_core, test_div1121);
  tcase_add_test(tc_core, test_div1122);
  tcase_add_test(tc_core, test_div1123);
  tcase_add_test(tc_core, test_div1124);
  tcase_add_test(tc_core, test_div1125);
  tcase_add_test(tc_core, test_div1126);
  tcase_add_test(tc_core, test_div1127);
  tcase_add_test(tc_core, test_div1128);
  tcase_add_test(tc_core, test_div1129);
  tcase_add_test(tc_core, test_div1130);
  tcase_add_test(tc_core, test_div1131);
  tcase_add_test(tc_core, test_div1132);
  tcase_add_test(tc_core, test_div1133);
  tcase_add_test(tc_core, test_div1134);
  tcase_add_test(tc_core, test_div1135);
  tcase_add_test(tc_core, test_div1136);
  tcase_add_test(tc_core, test_div1137);
  tcase_add_test(tc_core, test_div1138);
  tcase_add_test(tc_core, test_div1139);
  tcase_add_test(tc_core, test_div1140);
  tcase_add_test(tc_core, test_div1141);
  tcase_add_test(tc_core, test_div1142);
  tcase_add_test(tc_core, test_div1143);
  tcase_add_test(tc_core, test_div1144);
  tcase_add_test(tc_core, test_div1145);
  tcase_add_test(tc_core, test_div1146);
  tcase_add_test(tc_core, test_div1147);
  tcase_add_test(tc_core, test_div1148);
  tcase_add_test(tc_core, test_div1149);
  tcase_add_test(tc_core, test_div1150);
  tcase_add_test(tc_core, test_div1151);
  tcase_add_test(tc_core, test_div1152);
  tcase_add_test(tc_core, test_div1153);
  tcase_add_test(tc_core, test_div1154);
  tcase_add_test(tc_core, test_div1155);
  tcase_add_test(tc_core, test_div1156);
  tcase_add_test(tc_core, test_div1157);
  tcase_add_test(tc_core, test_div1158);
  tcase_add_test(tc_core, test_div1159);
  tcase_add_test(tc_core, test_div1160);
  tcase_add_test(tc_core, test_div1161);
  tcase_add_test(tc_core, test_div1162);
  tcase_add_test(tc_core, test_div1163);
  tcase_add_test(tc_core, test_div1164);
  tcase_add_test(tc_core, test_div1165);
  tcase_add_test(tc_core, test_div1166);
  tcase_add_test(tc_core, test_div1167);
  tcase_add_test(tc_core, test_div1168);
  tcase_add_test(tc_core, test_div1169);
  tcase_add_test(tc_core, test_div1170);
  tcase_add_test(tc_core, test_div1171);
  tcase_add_test(tc_core, test_div1172);
  tcase_add_test(tc_core, test_div1173);
  tcase_add_test(tc_core, test_div1174);
  tcase_add_test(tc_core, test_div1175);
  tcase_add_test(tc_core, test_div1176);
  tcase_add_test(tc_core, test_div1177);
  tcase_add_test(tc_core, test_div1178);
  tcase_add_test(tc_core, test_div1179);
  tcase_add_test(tc_core, test_div1180);
  tcase_add_test(tc_core, test_div1181);
  tcase_add_test(tc_core, test_div1182);
  tcase_add_test(tc_core, test_div1183);
  tcase_add_test(tc_core, test_div1184);
  tcase_add_test(tc_core, test_div1185);
  tcase_add_test(tc_core, test_div1186);
  tcase_add_test(tc_core, test_div1187);
  tcase_add_test(tc_core, test_div1188);
  tcase_add_test(tc_core, test_div1189);
  tcase_add_test(tc_core, test_div1190);
  tcase_add_test(tc_core, test_div1191);
  tcase_add_test(tc_core, test_div1192);
  tcase_add_test(tc_core, test_div1193);
  tcase_add_test(tc_core, test_div1194);
  tcase_add_test(tc_core, test_div1195);
  tcase_add_test(tc_core, test_div1196);
  tcase_add_test(tc_core, test_div1197);
  tcase_add_test(tc_core, test_div1198);
  tcase_add_test(tc_core, test_div1199);
  tcase_add_test(tc_core, test_div1200);

  suite_add_tcase(s, tc_core);
  return s;
}
