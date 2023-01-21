// Copyright [2022] <romainez>
#include "s21_string.h"

// Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    // Если n больше длины src, то добить нуль-символами
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
