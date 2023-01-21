#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки,
// на которую указывает dest, длиной до n символов.
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *start = dest;
    dest += s21_strlen(dest);
    for (s21_size_t i = 1; (*src != '\0' && i <= n); i++, dest++, src++) {
        *dest = *src;
    }
    *dest = '\0';
    return start;
}
