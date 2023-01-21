#include <string.h>

#include "s21_string.h"
#include "test_s21_string.h"

START_TEST(test_insert) {
    char string[41] = "Error. Press F1 to continue";
    char to_insert[20] = "No keyboard. ";
    char expected[100] = "Error. No keyboard. Press F1 to continue";

    char *res = s21_insert(string, to_insert, 7);
    ck_assert_str_eq(expected, res);
    if (res) free(res);

    res = s21_insert(S21_NULL, to_insert, 7);
    ck_assert_pstr_eq(S21_NULL, res);
    if (res) free(res);

    res = s21_insert(string, S21_NULL, 7);
    ck_assert_pstr_eq(S21_NULL, res);
    if (res) free(res);

    res = s21_insert(string, to_insert, 100);
    ck_assert_pstr_eq(S21_NULL, res);
    if (res) free(res);
}
END_TEST

START_TEST(test_to_upper) {
    char str[] = "this IS 5parta|";
    char *expected = "THIS IS 5PARTA|";
    char str2[] = "";

    char *res1 = s21_to_upper(str);
    char *res2 = s21_to_upper(str2);
    char *res3 = s21_to_upper(S21_NULL);
    ck_assert_pstr_eq(res1, expected);
    ck_assert_pstr_eq(res2, "");
    ck_assert_pstr_eq(res3, S21_NULL);
    if (res1) free(res1);
    if (res2) free(res2);
}
END_TEST

START_TEST(test_to_lower) {
    char str[] = "THIS is SPARTA!";
    char *expected = "this is sparta!";
    char str2[] = "";

    char *res1 = s21_to_lower(str);
    char *res2 = s21_to_lower(str2);
    char *res3 = s21_to_lower(S21_NULL);
    ck_assert_pstr_eq(res1, expected);
    ck_assert_pstr_eq(res2, "");
    ck_assert_pstr_eq(res3, S21_NULL);
    if (res1) free(res1);
    if (res2) free(res2);
}
END_TEST

START_TEST(test_trim) {
    char string[] = "./Nincompooper";
    char trim_chars[] = "re/.";

    char *res = s21_trim(string, trim_chars);
    ck_assert_str_eq(res, "Nincompoop");
    if (res) free(res);

    res = s21_trim(S21_NULL, trim_chars);
    ck_assert_pstr_eq(res, S21_NULL);
    if (res) free(res);

    res = s21_trim(string, S21_NULL);
    ck_assert_pstr_eq(res, S21_NULL);
    if (res) free(res);

    char string2[] = "./er";
    res = s21_trim(string2, trim_chars);
    ck_assert_str_eq(res, "");
    if (res) free(res);
}
END_TEST

Suite *make_sharp_suite(void) {
    Suite *s = suite_create("Sharp functions tests");
    TCase *tc_insert;
    TCase *tc_to_upper;
    TCase *tc_to_lower;
    TCase *tc_trim;

    tc_insert = tcase_create("insert");
    tcase_add_test(tc_insert, test_insert);
    suite_add_tcase(s, tc_insert);

    tc_to_upper = tcase_create("to_upper");
    tcase_add_test(tc_to_upper, test_to_upper);
    suite_add_tcase(s, tc_to_upper);

    tc_to_lower = tcase_create("to_lower");
    tcase_add_test(tc_to_lower, test_to_lower);
    suite_add_tcase(s, tc_to_lower);

    tc_trim = tcase_create("trim");
    tcase_add_test(tc_trim, test_trim);
    suite_add_tcase(s, tc_trim);

    return s;
}
