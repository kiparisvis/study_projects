// Copyright [2022] <isleanna>
#include "s21_string.h"

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
    char *res = S21_NULL;
    while (*str1 != '\0') {
        if (s21_strchr(str2, *str1)) {
            res = (char *)str1;
            break;
        } else {
            ++str1;
        }
    }
    return (res);
}
