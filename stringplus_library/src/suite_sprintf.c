#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"
#include "test_s21_string.h"

#define BUFF_SIZE 1024

#define compare_print_func(f1, str_sprintf, f2, str_csprintf, fmt, ...)                      \
    str_sprintf[0] = 0;                                                                      \
    str_csprintf[0] = 0;                                                                     \
    ck_assert_int_eq(f1(str_sprintf, fmt, __VA_ARGS__), f2(str_csprintf, fmt, __VA_ARGS__)); \
    ck_assert_str_eq(str_sprintf, str_csprintf);

START_TEST(test_integer) {
    char str_sprintf[512];
    char str_csprintf[512];
    // INTEGERS
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %d", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%d:%d:%d", 7, 4, 0);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MAX %d", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MIN %d", INT_MIN);
    // %i
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %i", 3534555);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %+d", 3534555);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5d'", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5d'", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5d'", INT_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5d'", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5d'", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5d'", INT_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5d'", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5d'", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5d'", INT_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5d'", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5d'", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5d'", INT_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5d'", 7);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5d'", INT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5d'", INT_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "mix '%% %d %-d %+d % d'", 123, 123,
                       123, 123);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "mix flags '%% %+-d %-d %+d %+-d'",
                       123, 123, 123, 123);

    // Unsigned integers
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %u", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%u:%u:%u", 7u, 4u, 0u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MAX %u", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MIN %u", 0u);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5u'", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5u'", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5u'", 0u);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5u'", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5u'", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5u'", 0u);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5u'", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5u'", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5u'", 0u);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5u'", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5u'", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5u'", 0u);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5u'", 7u);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5u'", UINT_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5u'", 0u);
}
END_TEST

START_TEST(test_long) {
    char str_sprintf[512];
    char str_csprintf[512];
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %ld", 3534535547l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%ld:%ld:%ld", 7l, 34543245324l, 0l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%ld", -5435432542l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MAX %ld", LONG_MAX);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MIN %ld", LONG_MIN);
    // %i
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %li", 3534535547l);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5ld'", 72341l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5ld'", LONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5ld'", LONG_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5ld'", 742343l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5ld'", LONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5ld'", LONG_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5ld'", 754354l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5ld'", LONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5ld'", LONG_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5ld'", 7343l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5ld'", LONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5ld'", LONG_MIN);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5ld'", 754354l);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5ld'", LONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5ld'", LONG_MIN);

    // Unsigned integers
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %lu", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%lu:%lu:%lu", 7ul, 4ul, 0ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MAX %lu", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "MIN %lu", 0ul);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5lu'", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5lu'", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5lu'", 0ul);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5lu'", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5lu'", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5lu'", 0ul);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5lu'", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5lu'", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5lu'", 0ul);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5lu'", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5lu'", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%3.5lu'", 0ul);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5lu'", 7ul);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5lu'", ULONG_MAX);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%-3.5lu'", 0ul);

    // const char * NULL_STR = NULL;
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "%s:%s:%s", "Mi Mundo", "es", "asin");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Nothing '%s'", "");
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "NULL '%s'", NULL_STR);

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5s'", "bar");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%5s'", "barfoobar");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5s'", "bar");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "padding '%-5s'", "barfoobar");

    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5s'", "bar");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "precision '%.5s'", "barfoobar");
}
END_TEST

START_TEST(test_padding) {
    char str_sprintf[512];
    char str_csprintf[512];
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %08d", 34);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %8d", 34);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-8d", 34);
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %018d", 34);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %18d", 34);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-18d", 34);
    // compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %02d", 343432);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-2d", 34423342);
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %9s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-9s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %2s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-2s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %12s", "Mundo");
    compare_print_func(sprintf, str_sprintf, s21_sprintf, str_csprintf, "Hola %-12s", "Mundo");
}
END_TEST

typedef struct {
    const char *fmt;
    int check_vs_sprintf;
    double input_value;
    const char *expected_string;
} double_test_pair;

START_TEST(test_float) {
    char str_csprintf[512];
    char str_sprintf[512];
    long unsigned int i;
    double_test_pair tests_exp_numbers[] = {
        {"%.5f", 1, 3.5f, NULL},
        {"%.5f", 1, -3.5f, NULL},

        // {"%.5f", 1, 9999999999999999999999999999.99999999999f*9999999999999999.0f, NULL},
        // {"%.5f", 1, -9999999999999999999999999999.99999999999f*9999999999999999.0f, NULL},
        {"%.5f", 1, 0, NULL},
        {"%.5f", 1, 3.5458730589043f, NULL},
        {"%.5f", 1, -3.5458730589043f, NULL},
        // Round
        // {"%10.4f", 0, 3.5458730589043f, "3.5459"},
        // {"%10.4f", 0, -3.5458730589043f, "-3.5459"},
        // {"%07.5f", 1, 334243.5458730589043f, NULL},
        // Overflow go to exp notation
        // {"%010.5f", 0, -438374297892438974433.5458730589043f, "-4.38374e+20"},
        // {"%010.5f", 0, 393824092389048029343234243.5458730589043f,"3.93824e+26"},
    };

    for (i = 0; i < sizeof(tests_exp_numbers) / sizeof(tests_exp_numbers[0]); i++) {
        sprintf(str_sprintf, tests_exp_numbers[i].fmt, tests_exp_numbers[i].input_value);
        s21_sprintf(str_csprintf, tests_exp_numbers[i].fmt, tests_exp_numbers[i].input_value);
        if (tests_exp_numbers[i].check_vs_sprintf) {
            ck_assert_msg(strcmp(str_sprintf, str_csprintf) == 0,
                          "Error String: i=%ld: sprintf: '%s' != result: '%s'", i, str_sprintf, str_csprintf);
        } else {
            ck_assert_msg(strcmp(tests_exp_numbers[i].expected_string, str_csprintf) == 0,
                          "Error String: i=%ld: expected: '%s' != result: '%s' => sprintf:  '%s'", i,
                          tests_exp_numbers[i].expected_string, str_csprintf, str_sprintf);
        }
    }
}
END_TEST

START_TEST(test_sprintf) {
    char orig[100] = {0};
    char res[100] = {0};

    ck_assert_int_eq(s21_sprintf(res, "%% %d %-d %+d % d", 123, 123, 123, 123),
                     sprintf(orig, "%% %d %-d %+d % d", 123, 123, 123, 123));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%5d %-5d %+5d % 5d", 123, 123, 123, 123),
                     sprintf(orig, "%5d %-5d %+5d % 5d", 123, 123, 123, 123));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%5.2d %-5.2d %+5.2d % 5.2d", 123, 123, 123, INT_MAX),
                     sprintf(orig, "%5.2d %-5.2d %+5.2d % 5.2d", 123, 123, 123, INT_MAX));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%5.2d %-5.2d %+5.2d % 5.2d", -123, -123, -123, INT_MIN),
                     sprintf(orig, "%5.2d %-5.2d %+5.2d % 5.2d", -123, -123, -123, INT_MIN));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%5.2ld %-5.2ld %+5.7li % 5.2ld", 123L, 123L, 123L, 123L),
                     sprintf(orig, "%5.2ld %-5.2ld %+5.7li % 5.2ld", 123L, 123L, 123L, 123L));
    ck_assert_str_eq(res, orig);

    short int x = 123;
    ck_assert_int_eq(s21_sprintf(res, "%5.2hd %-5.2hd %+5.2hd % 5.2hd", x, x, x, x),
                     sprintf(orig, "%5.2hd %-5.2hd %+5.2hd % 5.2hd", x, x, x, x));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%% %5.2u %-5.2u %%", 123u, 123U),
                     sprintf(orig, "%% %5.2u %-5.2u %%", 123U, 123U));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%% %5.2lu %-5.5lu %%", 123ul, 123ul),
                     sprintf(orig, "%% %5.2lu %-5.5lu %%", 123ul, 123ul));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%f %-f %+f % f", 1.123f, 1.123f, 1.123f, 1.123f),
                     sprintf(orig, "%f %-f %+f % f", 1.123f, 1.123f, 1.123f, 1.123f));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%10f %-10f %+10f % 10f", 1.123f, 1.123f, 1.123f, 1.123f),
                     sprintf(orig, "%10f %-10f %+10f % 10f", 1.123f, 1.123f, 1.123f, 1.123f));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%10f %-10.f %+10.2f % 10.10f", 1.123f, 2.523f, 1.135f, 1.123f),
                     sprintf(orig, "%10f %-10.f %+10.2f % 10.10f", 1.123f, 2.523f, 1.135f, 1.123f));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%+10.2f", -1.125f), sprintf(orig, "%+10.2f", -1.125f));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%+10.5f", 0.0f), sprintf(orig, "%+10.5f", 0.0f));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%+10.0f", 0.0f), sprintf(orig, "%+10.0f", 0.0f));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%10f %-10.f %+10.2f % 10.10f", -1.123f, -2.123f, -1.125f, -1.123f),
                     sprintf(orig, "%10f %-10.f %+10.2f % 10.10f", -1.123f, -2.123f, -1.125f, -1.123f));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%10f %-10.f %+10.2f % 15.13f", 1.123f, 2.523f, 1.135f, 1.123f),
                     sprintf(orig, "%10f %-10.f %+10.2f % 15.13f", 1.123f, 2.523f, 1.135f, 1.123f));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(
        s21_sprintf(res, "%10s %-10.s %10.2s %10.10s %d", "-1.123f", "-1.123f", "-1.125f", "-1.123f", 5),
        sprintf(orig, "%10s %-10.s %10.2s %10.10s %d", "-1.123f", "-1.123f", "-1.125f", "-1.123f", 5));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%c %-c", 'a', 'b'), sprintf(orig, "%c %-c", 'a', 'b'));
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "%5ls", L"string"), sprintf(orig, "%5ls", L"string"));
    s21_sprintf(res, "%5ls", L"string");
    sprintf(orig, "%5ls", L"string");
    ck_assert_str_eq(res, orig);

    ck_assert_int_eq(s21_sprintf(res, "Test string"), sprintf(orig, "Test string"));
    ck_assert_str_eq(res, orig);
}
END_TEST

START_TEST(simple_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    compare_print_func(sprintf, str1, s21_sprintf, str2, "This is a simple value %d", 69);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%.5i", 69);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%5d", 69);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%-5i", 69);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%+12d", 69);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%+5.31li", 698518581899L);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%.0d", 0);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "% d", 0);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%u", 14140u);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%15u", 14140u);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%-16u", 14140u);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%.51u", 14140u);
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%lu", 949149114140lu);
}
END_TEST

START_TEST(flags_short_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    short int val = 6958;

    compare_print_func(sprintf, str1, s21_sprintf, str2, "%-16.9hi", val);
}
END_TEST

START_TEST(unsigned_val_short) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    unsigned short int val = 14140;

    compare_print_func(sprintf, str1, s21_sprintf, str2, "%hu", val);
}
END_TEST

START_TEST(unsigned_val_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    unsigned short int vals = 14140;
    compare_print_func(sprintf, str1, s21_sprintf, str2, "%lu, %u, %hu, %.5u, %5.u", 949149114140lu, 14u,
                       vals, 14414u, 9681u);
}
END_TEST

START_TEST(unsigned_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%u";
    s21_sprintf(str1, format, 0);
    sprintf(str2, format, (unsigned)0);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%c";
    char val = 'X';
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.5c";
    char val = 'c';
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% -5c";
    char val = 'c';
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15c";
    char val = 'c';
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
    char val = 'c';
    s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b');
    sprintf(str2, format, val, 'c', 'a', 'b', 'b');

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.3c";
    char val = 'c';
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.15s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15s";
    char *val = "69 IS MY FAVORITE NUMBER";
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-15.9s";
    char *val = "69 IS MY FAVORITE NUMBER";
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s";
    char *val = "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s%s%s%s";
    char *val = "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    char *s1 = "";
    char *s2 = "87418347813748913749871389480913";
    char *s3 = "HAHAABOBASUCKER";
    s21_sprintf(str1, format, val, s1, s2, s3);
    sprintf(str2, format, val, s1, s2, s3);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width_huge) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *val = "kjafdiuhfjahfjdahf";
    char *format = "%120s";
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "% f";
    float val = 0;
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(all_empty) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    s21_sprintf(str1, "abc");
    sprintf(str2, "abc");

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "abc");
    sprintf(str2, "abc");

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%c", '\t');
    sprintf(str2, "%c", '\t');

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's');
    sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's');

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%s", "Drop Sega PLS");
    sprintf(str2, "%s", "Drop Sega PLS");

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS");
    sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS");

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%d", 666);
    sprintf(str2, "%d", 666);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100);
    sprintf(str2, "%d%d%d%d", -999, 0, 666, -100);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%i", -0);
    sprintf(str2, "%i", -0);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100);
    sprintf(str2, "%i%i%i%i", -999, 0, 666, -100);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%f", 0.0001);
    sprintf(str2, "%f", 0.0001);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001);
    sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%u", 100);
    sprintf(str2, "%u", (unsigned)100);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100);
    sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0, (unsigned)666, (unsigned)100);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%8c", '\t');
    sprintf(str2, "%8c", '\t');

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_right) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%-8c", '\t');
    sprintf(str2, "%-8c", '\t');

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char_with_alignment) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's');
    sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's');

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf1) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%10ld";

    s21_sprintf(str1, format, 1);
    sprintf(str2, format, 1);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf2) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%1.1f";

    s21_sprintf(str1, format, 1.1);
    sprintf(str2, format, 1.1);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf3) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%8.3c";

    s21_sprintf(str1, format, 'a');
    sprintf(str2, format, 'a');

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf4) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+5.5d aboba";

    int val = 10000;
    s21_sprintf(str1, format, val);
    sprintf(str2, format, val);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf6) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%7.7f";

    s21_sprintf(str1, format, 11.123456);
    sprintf(str2, format, 11.123456);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf7) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%7.4s";

    s21_sprintf(str1, format, "aboba floppa");
    sprintf(str2, format, "aboba floppa");

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf8) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%6.6u";

    s21_sprintf(str1, format, 12341151);
    sprintf(str2, format, 12341151);

    ck_assert_str_eq(str1, str2);
}
END_TEST

//    START_TEST(test_sprintf9) {
//        char str1[BUFF_SIZE];
//        char str2[BUFF_SIZE];
//        char format[] = "%li%ld%lu";
//
//        s21_sprintf(str1, format, 666666666666, 777, 111);
//        sprintf(str2, format, 666666666666, 777, 111);
//
//        ck_assert_str_eq(str1, str2);
//    }
//    END_TEST

START_TEST(test_sprintf10) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%hi%hd%hu";

    s21_sprintf(str1, format, 666, -777, 111);
    sprintf(str2, format, 666, -777, 111);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf11) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+li%+lu%+d%+lf";

    s21_sprintf(str1, format, -123, 321, -5555, -1213.123);
    sprintf(str2, format, -123, 321, -5555, -1213.123);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf14) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

    s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232);
    sprintf(str2, format, 1, 222, 33333333333, -166513.1232);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf15) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

    s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232);
    sprintf(str2, format, 1, 222, 33333333333, -166513.1232);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf16) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% c";

    s21_sprintf(str1, format, 'a');
    sprintf(str2, format, 'a');

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf17) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% s";

    s21_sprintf(str1, format, "aboba likes floppa");
    sprintf(str2, format, "aboba likes floppa");

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf18) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% s% c";

    s21_sprintf(str1, format, "", 'f');
    sprintf(str2, format, "", 'f');

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf19) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%210s";

    s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH");
    sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH");

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf20) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-115s";

    s21_sprintf(str1, format, "Nick her");
    sprintf(str2, format, "Nick her");

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf24) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

    s21_sprintf(str1, format, 'f', 21, 42, 666.666, "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11);
    sprintf(str2, format, 'f', 21, 42, 666.666, "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf25) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%.f";

    s21_sprintf(str1, format, 121.123);
    sprintf(str2, format, 121.123);

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_sprintf26) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%%";

//     ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf27) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%%%%%%%%";

//     ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_sprintf29) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-.f";

    s21_sprintf(str1, format, 111.111);
    sprintf(str2, format, 111.111);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf30) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-.1d";

    s21_sprintf(str1, format, 111);
    sprintf(str2, format, 111);

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(wide_char) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %lc";
//     unsigned long w = L'汉';
//     s21_sprintf(str1, format, w);
//     sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
// }

START_TEST(width_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %5c";
    char w = 'c';
    s21_sprintf(str1, format, w);
    sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
}
// START_TEST(minus_wide_char) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %-5lc";
//     unsigned long w = L'森';
//     s21_sprintf(str1, format, w);
//     sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(wide_string) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %ls";
//     wchar_t w[] = L"森我爱菠萝";
//     s21_sprintf(str1, format, w);
//     sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(wide_string1) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %5.12ls";
//     wchar_t w[] = L"森我爱菠萝";
//     s21_sprintf(str1, format, w);
//     sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(wide_string2) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %120ls ABOBA";
//     wchar_t w[] = L"森我爱菠萝";
//     s21_sprintf(str1, format, w);
//     sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(wide_string3) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];

//     char *format = "This is a simple wide char %-43ls";
//     wchar_t w[] = L"森我爱菠萝";
//     s21_sprintf(str1, format, w);
//     sprintf(str2, format, w);
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(sprintf_simple_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple value %d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precise_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%5d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_minus_width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%+12d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_long_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%+5.31li";
    long int val = 698518581899;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_short_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-16.9hi";
    short int val = 6958;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.0d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-16u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% 5.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%hu";
    unsigned short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lu";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lu, %u, %hu, %.5u, %5.u";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(
        s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
        sprintf(str2, format, val, (unsigned)14, (unsigned short)1441, (unsigned)14414, (unsigned)9681));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%u";
    ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, (unsigned)0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%c";
    char val = 'X';
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_one_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.5c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% -5c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                     sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.3c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.15s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15s";
    char *val = "69 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-15.9s";
    char *val = "69 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_long) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s";
    char *val = "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s%s%s%s";
    char *val = "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    char *s1 = "";
    char *s2 = "87418347813748913749871389480913";
    char *s3 = "HAHAABOBASUCKER";
    ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3), sprintf(str2, format, val, s1, s2, s3));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width_huge) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *val = "kjafdiuhfjahfjdahf";
    char *format = "%120s";
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *format = "% f";
    float val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_all_empty) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_empty_format_and_parameters) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                     sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"), sprintf(str2, "%s", "Drop Sega PLS"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
                     sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                     sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                     sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_float) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001), sprintf(str2, "%f", 0.0001));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_float) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    ck_assert_int_eq(s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
                     sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_unsigned_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    ck_assert_int_eq(s21_sprintf(str1, "%u", 100), sprintf(str2, "%u", (unsigned)100));
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_unsigned_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                     sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0, (unsigned)666, (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_left) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_right) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'), sprintf(str2, "%-8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char_with_alignment) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
                     sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf1) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%10ld";

    ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf2) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%1.1f";

    ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf3) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%8.3c";

    ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf4) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+5.5d aboba";

    int val = 10000;
    int a = s21_sprintf(str1, format, val);
    int b = sprintf(str2, format, val);
    ck_assert_int_eq(a, b);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf6) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%7.7f";

    ck_assert_int_eq(s21_sprintf(str1, format, 11.123456), sprintf(str2, format, 11.123456));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf7) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%7.4s";

    ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"), sprintf(str2, format, "aboba floppa"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf8) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%6.6u";

    ck_assert_int_eq(s21_sprintf(str1, format, 12341151), sprintf(str2, format, 12341151));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf9) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%li%ld%lu";

    ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777l, 111ul),
                     sprintf(str2, format, 666666666666, 777l, 111ul));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf10) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%hi%hd%hu";

    ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111), sprintf(str2, format, 666, -777, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf11) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+li%+lu%+d%+lf";

    ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                     sprintf(str2, format, -123, 321, -5555, -1213.123));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf14) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

    ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                     sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf15) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

    ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                     sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf16) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% c";

    ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf17) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% s";

    ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                     sprintf(str2, format, "aboba likes floppa"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf18) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% s% c";

    ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'), sprintf(str2, format, "", 'f'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf19) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%210s";

    ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                     sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf20) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-115s";

    ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"), sprintf(str2, format, "Nick her"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf24) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 'f', 21, 42, 666.666, "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
        sprintf(str2, format, 'f', 21, 42, 666.666, "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf25) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%.f";

    ck_assert_int_eq(s21_sprintf(str1, format, 121.123), sprintf(str2, format, 121.123));

    ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_test_sprintf26) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%%";

//     ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(sprintf_test_sprintf27) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char format[] = "%%%%%%%%";

//     ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(sprintf_test_sprintf29) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-.f";

    ck_assert_int_eq(s21_sprintf(str1, format, 111.111), sprintf(str2, format, 111.111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf30) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-.1d";

    ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple wide char %5c";
    char w = 'c';
    int a = s21_sprintf(str1, format, w);
    int b = sprintf(str2, format, w);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(a, b);
}

Suite *make_sprintf_suite(void) {
    Suite *s = suite_create("Sprintf function tests");
    TCase *tc_sprintf;

    tc_sprintf = tcase_create("sprintf");
    tcase_add_test(tc_sprintf, test_sprintf);
    tcase_add_test(tc_sprintf, test_integer);
    tcase_add_test(tc_sprintf, test_long);
    tcase_add_test(tc_sprintf, test_float);
    tcase_add_test(tc_sprintf, test_padding);
    suite_add_tcase(s, tc_sprintf);

    TCase *tc = tcase_create("sprintf_tc");
    tcase_add_test(tc, simple_int);
    tcase_add_test(tc, flags_short_int);
    tcase_add_test(tc, unsigned_val_short);
    tcase_add_test(tc, unsigned_val_many);
    tcase_add_test(tc, unsigned_zero);
    tcase_add_test(tc, one_char);
    tcase_add_test(tc, one_precision);
    tcase_add_test(tc, one_flags);
    tcase_add_test(tc, one_width);
    tcase_add_test(tc, one_many);
    tcase_add_test(tc, one_many_flags);
    tcase_add_test(tc, string);
    tcase_add_test(tc, string_precision);
    tcase_add_test(tc, string_width);
    tcase_add_test(tc, string_flags);
    tcase_add_test(tc, string_long);
    tcase_add_test(tc, string_many);
    tcase_add_test(tc, string_width_huge);
    tcase_add_test(tc, float_flags);
    tcase_add_test(tc, all_empty);
    tcase_add_test(tc, empty_format_and_parameters);
    tcase_add_test(tc, test_one_char);
    tcase_add_test(tc, test_many_char);
    tcase_add_test(tc, test_one_string);
    tcase_add_test(tc, test_many_string);
    tcase_add_test(tc, test_one_dec);
    tcase_add_test(tc, test_many_dec);
    tcase_add_test(tc, test_one_int);
    tcase_add_test(tc, test_many_int);
    tcase_add_test(tc, test_one_float);
    tcase_add_test(tc, test_many_float);
    tcase_add_test(tc, test_one_unsigned_dec);
    tcase_add_test(tc, test_many_unsigned_dec);
    tcase_add_test(tc, test_one_char_with_alignment_left);
    tcase_add_test(tc, test_one_char_with_alignment_right);
    tcase_add_test(tc, test_many_char_with_alignment);
    tcase_add_test(tc, test_sprintf1);
    tcase_add_test(tc, test_sprintf2);
    tcase_add_test(tc, test_sprintf3);
    tcase_add_test(tc, test_sprintf4);
    tcase_add_test(tc, test_sprintf6);
    tcase_add_test(tc, test_sprintf7);
    tcase_add_test(tc, test_sprintf8);
    //    tcase_add_test(tc, test_sprintf9);
    tcase_add_test(tc, test_sprintf10);
    tcase_add_test(tc, test_sprintf11);
    tcase_add_test(tc, test_sprintf14);
    tcase_add_test(tc, test_sprintf15);
    tcase_add_test(tc, test_sprintf16);
    tcase_add_test(tc, test_sprintf17);
    tcase_add_test(tc, test_sprintf18);
    tcase_add_test(tc, test_sprintf19);
    tcase_add_test(tc, test_sprintf20);
    tcase_add_test(tc, test_sprintf24);
    tcase_add_test(tc, test_sprintf25);
    tcase_add_test(tc, test_sprintf29);
    tcase_add_test(tc, test_sprintf30);
    // tcase_add_test(tc, wide_char);
    tcase_add_test(tc, width_char);
    // tcase_add_test(tc, minus_wide_char);
    // tcase_add_test(tc, wide_string);
    // tcase_add_test(tc, wide_string1);
    // tcase_add_test(tc, wide_string2);
    // tcase_add_test(tc, wide_string3);
    tcase_add_test(tc, sprintf_simple_int);
    tcase_add_test(tc, sprintf_precise_int);
    tcase_add_test(tc, sprintf_width_int);
    tcase_add_test(tc, sprintf_minus_width_int);
    tcase_add_test(tc, sprintf_plus_width_int);
    tcase_add_test(tc, sprintf_flags_long_int);
    tcase_add_test(tc, sprintf_flags_short_int);
    tcase_add_test(tc, sprintf_zero_precision_zero_int);
    tcase_add_test(tc, sprintf_space_flag_int);
    tcase_add_test(tc, sprintf_unsigned_val);
    tcase_add_test(tc, sprintf_unsigned_val_width);
    tcase_add_test(tc, sprintf_unsigned_val_flags);
    tcase_add_test(tc, sprintf_unsigned_val_precision);
    tcase_add_test(tc, sprintf_unsigned_val_many_flags);
    tcase_add_test(tc, sprintf_unsigned_val_short);
    tcase_add_test(tc, sprintf_unsigned_val_long);
    tcase_add_test(tc, sprintf_unsigned_val_many);
    tcase_add_test(tc, sprintf_unsigned_zero);
    tcase_add_test(tc, sprintf_one_char);
    tcase_add_test(tc, sprintf_one_precision);
    tcase_add_test(tc, sprintf_one_flags);
    tcase_add_test(tc, sprintf_one_width);
    tcase_add_test(tc, sprintf_one_many);
    tcase_add_test(tc, sprintf_one_many_flags);
    tcase_add_test(tc, sprintf_string);
    tcase_add_test(tc, sprintf_string_precision);
    tcase_add_test(tc, sprintf_string_width);
    tcase_add_test(tc, sprintf_string_flags);
    tcase_add_test(tc, sprintf_string_long);
    tcase_add_test(tc, sprintf_string_many);
    tcase_add_test(tc, sprintf_string_width_huge);
    tcase_add_test(tc, sprintf_float_flags);
    tcase_add_test(tc, sprintf_all_empty);
    tcase_add_test(tc, sprintf_empty_format_and_parameters);
    tcase_add_test(tc, sprintf_test_one_char);
    tcase_add_test(tc, sprintf_test_many_char);
    tcase_add_test(tc, sprintf_test_one_string);
    tcase_add_test(tc, sprintf_test_many_string);
    tcase_add_test(tc, sprintf_test_one_dec);
    tcase_add_test(tc, sprintf_test_many_dec);
    tcase_add_test(tc, sprintf_test_one_int);
    tcase_add_test(tc, sprintf_test_many_int);
    tcase_add_test(tc, sprintf_test_one_float);
    tcase_add_test(tc, sprintf_test_many_float);
    tcase_add_test(tc, sprintf_test_one_unsigned_dec);
    tcase_add_test(tc, sprintf_test_many_unsigned_dec);
    tcase_add_test(tc, sprintf_test_one_char_with_alignment_left);
    tcase_add_test(tc, sprintf_test_one_char_with_alignment_right);
    tcase_add_test(tc, sprintf_test_many_char_with_alignment);
    tcase_add_test(tc, sprintf_test_sprintf1);
    tcase_add_test(tc, sprintf_test_sprintf2);
    tcase_add_test(tc, sprintf_test_sprintf3);
    tcase_add_test(tc, sprintf_test_sprintf4);
    tcase_add_test(tc, sprintf_test_sprintf6);
    tcase_add_test(tc, sprintf_test_sprintf7);
    tcase_add_test(tc, sprintf_test_sprintf8);
    tcase_add_test(tc, sprintf_test_sprintf9);
    tcase_add_test(tc, sprintf_test_sprintf10);
    tcase_add_test(tc, sprintf_test_sprintf11);
    tcase_add_test(tc, sprintf_test_sprintf14);
    tcase_add_test(tc, sprintf_test_sprintf15);
    tcase_add_test(tc, sprintf_test_sprintf16);
    tcase_add_test(tc, sprintf_test_sprintf17);
    tcase_add_test(tc, sprintf_test_sprintf18);
    tcase_add_test(tc, sprintf_test_sprintf19);
    tcase_add_test(tc, sprintf_test_sprintf20);
    tcase_add_test(tc, sprintf_test_sprintf24);
    tcase_add_test(tc, sprintf_test_sprintf25);
    tcase_add_test(tc, sprintf_test_sprintf29);
    tcase_add_test(tc, sprintf_test_sprintf30);
    // tcase_add_test(tc, sprintf_test_sprintf26);
    // tcase_add_test(tc, sprintf_test_sprintf27);
    tcase_add_test(tc, sprintf_width_char);

    suite_add_tcase(s, tc);

    return s;
}
