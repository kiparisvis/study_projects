// Copyright [2022] <isleanna>
#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип)
// в первых n байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, s21_size_t n) {
    char *p = (char *)str;
    char *res = S21_NULL;
    if (p) {
        if (c) {
            while (n-- && *p) {
                if (*p == c) {
                    res = p;
                    break;
                }
                p++;
            }
        } else if (s21_strlen(p) < n) {
            res = p + s21_strlen(p);
        }
    }
    return res;
}
