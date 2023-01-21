#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <stdarg.h>

typedef struct fmt {
    struct fmt* next;
    char* begin;
    const char* end;
    int flag_left;
    int flag_sign;
    int flag_space;
    int width;
    int precision;
    char length;
    char specifier;
} fmt_t;

int _parse(const char* format, fmt_t** fmt);
int _parse_fmt(fmt_t* fmt, const char** from);
fmt_t* _new_fmt();
int _get_flags(fmt_t* fmt, const char** from);
int _do_output(char* str, const char* format, va_list p, fmt_t* fmt);
char* _int_to_str(va_list p, fmt_t* fmt);
char* _uint_to_str(va_list p, fmt_t* fmt);
char* _float_to_str(va_list p, fmt_t* fmt);
char* _char_to_str(va_list p, fmt_t* fmt);
char* _str_to_str(va_list p, fmt_t* fmt);
char* _itoa(long long int i);
void _clear_list(fmt_t* fmt);

#endif  // SRC_S21_SPRINTF_H_
