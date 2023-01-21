// Copyright [2022] <isleanna>
#include "s21_string.h"

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке,
// на которую указывает аргумент str.
char *s21_strrchr(const char *str, int c) {
    char *last_occ = S21_NULL;
    while (*str != '\0') {
        if (*str == c) {
            last_occ = (char *)str;
        }
        ++str;
    }
    return (c == '\0') ? (char *)str : (last_occ);
}
