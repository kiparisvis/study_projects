// Copyright [2022] <isleanna>
#include "s21_string.h"

// Возвращает копию строки (str), преобразованной в нижний регистр.
// В случае какой-либо ошибки следует вернуть значение S21_NULL
void *s21_to_lower(const char *str) {
    char *res = S21_NULL;
    if (str) {
        res = (char *)malloc(s21_strlen(str) + 1);
        if (res) {
            s21_strcpy(res, str);
            for (char *to_lower = res; *to_lower; ++to_lower) {
                if (*to_lower >= 65 && *to_lower <= 90) {
                    *to_lower = *to_lower + 32;
                }
            }
        }
    }
    return (res);
}
