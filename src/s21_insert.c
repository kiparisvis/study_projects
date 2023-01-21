// Copyright [2022] <isleanna>
#include "s21_string.h"

// Возвращает новую строку, в которой указанная строка (str)
// вставлена в указанную позицию (start_index) в данной строке (src).
// В случае какой-либо ошибки следует вернуть значение S21_NULL
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *res = S21_NULL;
    if (src && str && start_index <= s21_strlen(src)) {
        res = (char *)malloc((s21_strlen(src) + s21_strlen(str) + 1));
        if (res) {
            s21_strncpy(res, src, start_index);
            res[start_index] = '\0';
            s21_strcat(res, str);
            s21_strcat(res, src + start_index);
        }
    }
    return (res);
}
