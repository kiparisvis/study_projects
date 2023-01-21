#include <stdio.h>  // Удалить при начале разработки эту заглушку

#include "s21_string.h"

// Разбивает строку str на ряд токенов, разделенных delim.

char *ptr;

char *s21_strtok(char *str, const char *delim) {
    if (str) {
        ptr = str;
    } else {
        str = ptr;
    }
    while (str != S21_NULL && *str != '\0' && s21_strchr(delim, *str)) {
        str++;
    }
    if (str != S21_NULL && s21_strpbrk(str, delim)) {
        char *del = s21_strpbrk(str, delim);
        *del = '\0';
        if (*(del + 1) != '\0') {
            ptr = del + 1;
        } else {
            ptr = S21_NULL;
        }
    } else {
        ptr = S21_NULL;
    }
    return str;
}
