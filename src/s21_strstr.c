#include "s21_string.h"

// Находит первое вхождение всей строки needle
// (не включая завершающий нулевой символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle) {
    char *res = S21_NULL;
    while (*haystack != '\0' && s21_strlen(haystack) >= s21_strlen(needle) &&
           s21_strncmp(haystack, needle, s21_strlen(needle))) {
        haystack++;
    }
    if (s21_strlen(haystack) >= s21_strlen(needle)) res = (char *)haystack;
    return res;
}
