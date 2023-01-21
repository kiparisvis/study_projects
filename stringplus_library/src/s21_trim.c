// Copyright [2022] <isleanna>
#include "s21_string.h"

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src).
// В случае какой-либо ошибки следует вернуть значение S21_NULL
void *s21_trim(const char *src, const char *trim_chars) {
    char *res = S21_NULL;
    if (src && trim_chars) {
        size_t lead = 0;
        size_t trail = s21_strlen(src);
        while (src[lead] != '\0' && s21_strchr(trim_chars, src[lead])) lead++;
        while (trail > lead && s21_strchr(trim_chars, src[trail - 1])) trail--;
        res = (char *)malloc(sizeof(char) * (trail - lead + 1));
        if (res) {
            size_t i = 0;
            while (lead < trail) res[i++] = src[lead++];
            res[i] = '\0';
        }
    }
    return (res);
}
