#include "s21_string.h"

// Вычисляет длину начального сегмента str1,
// который полностью состоит из символов str2.
s21_size_t s21_strspn(const char *str1, const char *str2) {
    const char *s1;

    for (s1 = str1; (*s1 != '\0' && s21_strchr(str2, *s1)); s1++) {
    }

    // Можно было сделать так
    // while (*s1 != '\0' && s21_strchr(str2, *s1))
    //     s1++;

    return s1 - str1;
}
