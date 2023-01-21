#include <string.h>

#include "s21_string.h"
#include "test_s21_string.h"

START_TEST(test_strcmp) {
    int result;
    char *str1 = "school21";
    char *str2 = "school21";
    char *str3 = "school211";

    result = s21_strcmp(str1, str2);
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(result, strcmp(str1, str2));

    result = s21_strcmp(str1, str3);
    ck_assert_int_lt(result, 0);
    ck_assert(result < 0 && strcmp(str1, str3) < 0);
}
END_TEST

START_TEST(test_strncmp) {
    int result;
    char *str1 = "1234567890";
    char *str2 = "1234507890";
    int n1 = 5;
    int n2 = 6;
    int n3 = 0;

    result = s21_strncmp(str1, str2, n1);
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(result, strncmp(str1, str2, n1));

    result = s21_strncmp(str1, str2, n3);
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(result, strncmp(str1, str2, n3));

    result = s21_strncmp(str1, str2, n2);
    ck_assert_int_gt(result, 0);
    ck_assert(result > 0 && strncmp(str1, str2, n2) > 0);
}
END_TEST

START_TEST(test_strcpy) {
    char src[25] = "Hello world!";
    char dest[25] = "";
    char res[25] = {0};
    char expected[25] = "Hello world!";

    s21_strcpy(dest, src);
    ck_assert_str_eq(expected, dest);
    ck_assert_str_eq(dest, strcpy(res, src));
}
END_TEST

START_TEST(test_strncpy) {
    char src[13] = "Hello world!";
    char dest[25] = "aaaaaaaaaaaaaaaaaaaa";
    char res[25] = "aaaaaaaaaaaaaaaaaaaa";
    int n = 25;

    ck_assert_int_eq(s21_strncpy(dest, src, n)[15], strncpy(res, src, n)[15]);
}
END_TEST

START_TEST(test_strlen) {
    char str[25] = "Hello world!";

    ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_strcspn) {
    char str[25] = "Hello world!";
    char rej[6] = "ab cd";
    char empty[] = "";

    ck_assert_int_eq(s21_strcspn(str, rej), strcspn(str, rej));
    ck_assert_int_eq(s21_strcspn(empty, rej), strcspn(empty, rej));
    ck_assert_int_eq(s21_strcspn(str, empty), strcspn(str, empty));
}
END_TEST

START_TEST(test_strspn) {
    char str[25] = "Hello world!";
    char acc[6] = "eollH";
    char empty[] = "";

    ck_assert_int_eq(s21_strspn(str, acc), strspn(str, acc));
    ck_assert_int_eq(s21_strspn(empty, acc), strspn(empty, acc));
    ck_assert_int_eq(s21_strspn(str, empty), strspn(str, empty));
}
END_TEST

START_TEST(test_strpbrk) {
    char string[] = "Functions that will make our lives easier!";
    char chars[] = "";

    ck_assert_pstr_eq(s21_strpbrk(string, chars), strpbrk(string, chars));
    char chars2[] = "t";
    ck_assert_pstr_eq(s21_strpbrk(string, chars2), strpbrk(string, chars2));
    char chars3[2];
    chars3[0] = '\0';
    ck_assert_pstr_eq(s21_strpbrk(string, chars3), strpbrk(string, chars3));
}
END_TEST

START_TEST(test_strrchr) {
    char *string = "Snickersnee";
    char search_for = 'n';
    char string2[20] = "Snickersnee";
    string2[5] = '\0';

    ck_assert_pstr_eq(s21_strrchr(string, search_for), strrchr(string, search_for));
    ck_assert_pstr_eq(s21_strrchr(string2, '\0'), strrchr(string2, '\0'));
}
END_TEST

START_TEST(test_strchr) {
    char *string = "Snickersnee";
    char search_for = 'n';

    ck_assert_str_eq(s21_strchr(string, search_for), strchr(string, search_for));
}
END_TEST

START_TEST(test_strstr) {
    char *haystack = "This is Sparta!";
    char *haystack2 = "";
    char *needle = "is S";
    char *needle2 = "is S ";
    char *needle3 = "";

    ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
    ck_assert_pstr_eq(s21_strstr(haystack, needle2), strstr(haystack, needle2));
    ck_assert_pstr_eq(s21_strstr(haystack, needle3), strstr(haystack, needle3));
    ck_assert_pstr_eq(s21_strstr(haystack2, needle), strstr(haystack2, needle));
}
END_TEST

START_TEST(test_strcat) {
    char dst[100] = "Hello";
    char dst2[100] = "Hello";
    char *src = " World!";

    ck_assert_str_eq(s21_strcat(dst, src), strcat(dst2, src));
}
END_TEST

START_TEST(test_strncat) {
    char dst[100] = "Hello";
    char dst2[100] = "Hello";
    char *src = " World!";

    ck_assert_str_eq(s21_strncat(dst, src, 3), strncat(dst2, src, 3));
    char dst3[100] = "Hello";
    char dst4[100] = "Hello";
    ck_assert_str_eq(s21_strncat(dst3, src, 10), strncat(dst4, src, 10));
}
END_TEST

START_TEST(test_strtok) {
    char p[15] = "VK is Bad Guy";
    char exp[15] = "VK is Bad Guy";
    char *delim = "Visay";

    ck_assert_pstr_eq(s21_strtok(p, delim), strtok(exp, delim));
    ck_assert_pstr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
    ck_assert_pstr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
    ck_assert_pstr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(test_strerror) {
    int errno = -1;
    int ERRMAX = 150;
    while (errno < ERRMAX) {
        ck_assert_str_eq(strerror(errno), s21_strerror(errno));
        errno++;
    }
}
END_TEST

Suite *make_str_suite(void) {
    Suite *s = suite_create("Str functions tests");
    TCase *tc_strcmp;
    TCase *tc_strncmp;
    TCase *tc_strcpy;
    TCase *tc_strncpy;
    TCase *tc_strlen;
    TCase *tc_strcspn;
    TCase *tc_strspn;
    TCase *tc_strpbrk;
    TCase *tc_strrchr;
    TCase *tc_strchr;
    TCase *tc_strstr;
    TCase *tc_strcat;
    TCase *tc_strncat;
    TCase *tc_strtok;
    TCase *tc_strerror;

    tc_strcmp = tcase_create("strcmp");
    tcase_add_test(tc_strcmp, test_strcmp);
    suite_add_tcase(s, tc_strcmp);

    tc_strncmp = tcase_create("strncmp");
    tcase_add_test(tc_strncmp, test_strncmp);
    suite_add_tcase(s, tc_strncmp);

    tc_strcpy = tcase_create("strcpy");
    tcase_add_test(tc_strcpy, test_strcpy);
    suite_add_tcase(s, tc_strcpy);

    tc_strncpy = tcase_create("strncpy");
    tcase_add_test(tc_strncpy, test_strncpy);
    suite_add_tcase(s, tc_strncpy);

    tc_strlen = tcase_create("strlen");
    tcase_add_test(tc_strlen, test_strlen);
    suite_add_tcase(s, tc_strlen);

    tc_strcspn = tcase_create("strcspn");
    tcase_add_test(tc_strcspn, test_strcspn);
    suite_add_tcase(s, tc_strcspn);

    tc_strspn = tcase_create("strspn");
    tcase_add_test(tc_strspn, test_strspn);
    suite_add_tcase(s, tc_strspn);

    tc_strpbrk = tcase_create("strpbrk");
    tcase_add_test(tc_strpbrk, test_strpbrk);
    suite_add_tcase(s, tc_strpbrk);

    tc_strrchr = tcase_create("strrchr");
    tcase_add_test(tc_strrchr, test_strrchr);
    suite_add_tcase(s, tc_strrchr);

    tc_strchr = tcase_create("strchr");
    tcase_add_test(tc_strchr, test_strchr);
    suite_add_tcase(s, tc_strchr);

    tc_strstr = tcase_create("strstr");
    tcase_add_test(tc_strstr, test_strstr);
    suite_add_tcase(s, tc_strstr);

    tc_strcat = tcase_create("strcat");
    tcase_add_test(tc_strcat, test_strcat);
    suite_add_tcase(s, tc_strcat);

    tc_strncat = tcase_create("strncat");
    tcase_add_test(tc_strncat, test_strncat);
    suite_add_tcase(s, tc_strncat);

    tc_strtok = tcase_create("strtok");
    tcase_add_test(tc_strtok, test_strtok);
    suite_add_tcase(s, tc_strtok);

    tc_strerror = tcase_create("strerror");
    tcase_add_test(tc_strerror, test_strerror);
    suite_add_tcase(s, tc_strerror);

    return s;
}
