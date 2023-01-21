// Copyright [2022] <romainez>
#include "s21_string.h"

// Сравнивает строку, на которую указывает str1, со строкой,
// на которую указывает str2. Если они идентичны, выводит 0
int s21_strcmp(const char *str1, const char *str2) {
    const char *p = str1;
    const char *q = str2;
    while (*p == *q) {
        if (*p == '\0') {
            return 0;
        }
        p++;
        q++;
    }
    return *(unsigned char *)p - *(unsigned char *)q;
}
