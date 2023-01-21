#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке,
// на которую указывает аргумент str.
char *s21_strchr(const char *str, int c) {
    while (*str != '\0' && *str != (char)c) str++;
    return (*str == '\0' && (char)c != '\0') ? S21_NULL : (char *)str;
}
