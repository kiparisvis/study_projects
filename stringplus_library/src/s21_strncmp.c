// Copyright [2022] <romainez>
#include "s21_string.h"

// Сравнивает не более первых n байтов str1 и str2.
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    const unsigned char *p1;
    const unsigned char *p2;
    s21_size_t i;
    int res = 0;

    p1 = (const unsigned char *)str1;
    p2 = (const unsigned char *)str2;
    i = 0;
    while (i < n) {
        if (p1[i] != p2[i]) {
            res = (p1[i] - p2[i]);
            break;
        }
        i++;
    }
    return res;
}
