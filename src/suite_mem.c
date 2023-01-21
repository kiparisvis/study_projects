#include <string.h>

#include "s21_string.h"
#include "test_s21_string.h"

START_TEST(test_memcmp) {
    int result;
    char *str1 = "21school";
    char *str2 = "21school ";
    char *str3 = "42school";

    ck_assert_int_eq(s21_memcmp(str1, str2, strlen(str1)), memcmp(str1, str2, 8));
    ck_assert(s21_memcmp(str1, str2, 9) < 0 && memcmp(str1, str2, 9) < 0);
    ck_assert_int_eq(s21_memcmp("", str2, 9), memcmp("", str2, 1));
    result = s21_memcmp(str1, str2, 10);
    ck_assert_int_ne(result, 0);
    // ck_assert_int_eq(result, memcmp(str1, str2, 10));
    ck_assert(s21_memcmp(str1, str3, strlen(str1)) < 0 && memcmp(str1, str3, 8) < 0);
    ck_assert(s21_memcmp(str3, str1, strlen(str1)) > 0 && memcmp(str3, str1, 8) > 0);
    ck_assert_int_eq(s21_memcmp(str1, str3, 0), memcmp(str1, str3, 0));
}
END_TEST

START_TEST(test_memchr) {
    char *str = "21school";
    char *to_find = "sSx h70";

    while (*to_find) {
        ck_assert_pstr_eq(s21_memchr(str, *to_find, s21_strlen(str) + 1),
                          memchr(str, *to_find, s21_strlen(str) + 1));
        to_find++;
    }
    ck_assert_pstr_eq(s21_memchr(str, *to_find, s21_strlen(str) + 1),
                      memchr(str, *to_find, s21_strlen(str) + 1));

    ck_assert_pstr_eq(s21_memchr(str, 'o', 3), memchr(str, 'o', 3));

    char *str2 = " ";
    char *to_find2 = "";
    ck_assert_pstr_eq(s21_memchr(str2, *to_find2, 1), memchr(str2, *to_find2, 1));

    // Наша функция защищена от n большего, чем длина строки
    ck_assert_pstr_eq(s21_memchr(str2, *to_find2, 3), memchr(str2, *to_find2, 2));
    // Наша функция защищена от нулевого указателя вместо строки
    ck_assert_ptr_null(s21_memchr(S21_NULL, 'x', 10));
}
END_TEST

START_TEST(test_memcpy) {
    char *s = "Deadline is approaching!";
    char d[25] = {0};
    char e[25] = {0};
    extern void *s21_memcpy(void *dest, const void *src, s21_size_t n);

    ck_assert_str_eq(s21_memcpy(d, s, 8), memcpy(e, s, 8));
}
END_TEST

START_TEST(test_memmove) {
    char src[15] = "Hello world!";
    char dst1[15] = "";
    char dst2[15] = "";
    int n = 5;
    extern void *s21_memmove(void *dest, const void *src, s21_size_t n);

    ck_assert_str_eq(s21_memmove(dst1, src, n), memmove(dst2, src, n));

    memset(dst1, 0, sizeof(dst1));
    memset(dst2, 0, sizeof(dst2));
    n = 0;
    ck_assert_str_eq(s21_memmove(dst1, src, n), memmove(dst2, src, n));

    memset(dst1, 0, sizeof(dst1));
    memset(dst2, 0, sizeof(dst2));
    n = 0;
    ck_assert_str_eq(s21_memmove(dst1, src, n), memmove(dst2, src, n));
}
END_TEST

START_TEST(test_memset) {
    char array[5] = "ABCD";
    char array2[5] = "ABCD";
    char expected[5] = "000D";
    int n = 3;
    double d[2] = {0.5, 0.6};
    double d2[2] = {0.5, 0.6};
    int d3[5] = {1, 1, 1, 1, 1};
    int d4[5] = {1, 1, 1, 1, 1};

    s21_memset(array, '0', n);
    ck_assert_str_eq(expected, array);
    ck_assert_str_eq(array, memset(array2, '0', n));
    ck_assert_str_eq(s21_memset(d, '0', n), memset(d2, '0', n));
    ck_assert_str_eq(s21_memset(d3, '0', n), memset(d4, '0', n));
}
END_TEST

Suite *make_mem_suite(void) {
    Suite *s = suite_create("Mem functions tests");
    TCase *tc_memchr;
    TCase *tc_memcmp;
    TCase *tc_memcpy;
    TCase *tc_memmove;
    TCase *tc_memset;

    tc_memchr = tcase_create("memchr");
    tcase_add_test(tc_memchr, test_memchr);
    suite_add_tcase(s, tc_memchr);

    tc_memcmp = tcase_create("memcmp");
    tcase_add_test(tc_memcmp, test_memcmp);
    suite_add_tcase(s, tc_memcmp);

    tc_memcpy = tcase_create("memcpy");
    tcase_add_test(tc_memcpy, test_memcpy);
    suite_add_tcase(s, tc_memcpy);

    tc_memmove = tcase_create("memmove");
    tcase_add_test(tc_memmove, test_memmove);
    suite_add_tcase(s, tc_memmove);

    tc_memset = tcase_create("memset");
    tcase_add_test(tc_memset, test_memset);
    suite_add_tcase(s, tc_memset);

    return s;
}
