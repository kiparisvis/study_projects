// Copyright [2022] <isleanna>
#include "s21_string.h"

// Сравнивает первые n байтов str1 и str2.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    unsigned char *p1 = (unsigned char *)str1;
    unsigned char *p2 = (unsigned char *)str2;
    int res = 0;
    for (s21_size_t i = 0; i < n; i++) {
        res = *p1 - *p2;
        if (*p1 != *p2) {
            break;
        }
        p1++;
        p2++;
    }
    return (res);
}
