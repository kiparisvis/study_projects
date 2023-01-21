#include "s21_string.h"
#include <stdarg.h>
#include <ctype.h>
#include <math.h>

#ifdef NAN
// NAN is supported
#endif
#ifdef INFINITY
// INFINITY is supported
#endif

#define LONG_MAX 0x7FFFFFFF
#define LONG_MIN 0x80000000
#define LLONG_MAX 0x7FFFFFFFFFFFFFFF
#define LLONG_MIN 0x8000000000000000

struct Spec {
    char type;          // Спецификатор: c, d, i, e, E, f, g, G, o, s, u, x, X, p, n, %
    s21_size_t width;   // Ширина
    char length;        // Длина: h, l, L, ll(x)
    int is_star;        // Указана ли звезда после %: 0 - не указана, 1 - указана
    int is_space;       // Состоит ли этот блок только из пробелов
    char *str;          // Указатель на блок строки, относящейся к этому спецификатору
};

int is_empty(char *string) {
    int result = 1;
    if (string == S21_NULL) {
        result = 1;
    } else {
        char *s = string;
        while (*s != '\0') {
            if (isspace(*s)) {
                s++;
            } else {
                result = 0;
                break;
            }
        }
    }
    return result;
}

int string_to_int(char *string) {
    int result = -1;
    int sign = 1;
    if (string) {
        result = 0;
        if (*string == '+') {
            string++;
        } else if (*string == '-') {
            sign = -1;
            string++;
        }
        while (*string) {
            if (*string < '0' || *string > '9') {
                break;
            } else {
                result = result * 10 + *string - '0';
                string++;
            }
        }
    }
    return sign * result;
}

long string_to_long(const char *nptr, char **endptr, register int base, int width) {
    const char *s = nptr;
    unsigned long acc;
    int c;
    unsigned long cutoff;
    int neg = 0, any, cutlim;

    do {
        c = *s++;
    } while (isspace(c));
    if (c == '+' || c == '-') {
        if (c == '-') {
            neg = 1;
        }
        c = *s++;
    }

    if (base == 16 && c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
    }

    cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
    cutlim = cutoff % (unsigned long)base;
    cutoff /= (unsigned long)base;
    int i = 0;
    for (acc = 0, any = 0; (width == 0 || i < width); c = *s++, i++) {
        if (isdigit(c)) {
            c -= '0';
        } else if (isalpha(c)) {
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        } else {
            break;
        }
        if (c >= base) {
            break;
        }
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim)) {
            any = -1;
        } else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = neg ? LONG_MIN : LONG_MAX;
    } else if (neg) {
        acc = -acc;
    }
    if (endptr != 0) {
        *endptr = (char *) (any ? s - 1 : nptr);
    }
    return (acc);
}

long long string_to_long_long(const char *nptr, char **endptr, register int base, int width) {
    const char *s = nptr;
    long long acc;
    int c;
    long long cutoff;
    int neg = 0, any, cutlim;

    do {
        c = *s++;
    } while (isspace(c));
    if (c == '+' || c == '-') {
        if (c == '-') {
            neg = 1;
        }
        c = *s++;
    }

    if ((base == 0 || base == 16) &&
        c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;

    cutoff = neg ? -(unsigned long long)LLONG_MIN : LLONG_MAX;
    cutlim = cutoff % (unsigned long long)base;
    cutoff /= (unsigned long long)base;
    int i = 0;
    for (acc = 0, any = 0; (width == 0 || i < width); c = *s++, i++) {
        if (isdigit(c))
            c -= '0';
        else if (isalpha(c))
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim)) {
            any = -1;
        } else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = neg ? LLONG_MIN : LLONG_MAX;
    } else if (neg) {
        acc = -acc;
    }
    if (endptr != 0) {
        *endptr = (char *) (any ? s - 1 : nptr);
    }
    return (acc);
}

long double string_to_double(const char *s) {
    long double a = 0.0;
    int e = 0;
    int c;
    int sign = 1;
    c = *s++;
    while (isspace(c)) {
        c = *s++;
    }
    if (c == '+' || c == '-') {
        if (c == '-') {
            sign = -1;
        }
        c = *s++;
    }

    while (c != '\0' && isdigit(c)) {
        a = a * 10.0 + (c - '0');
        c = *s++;
    }
    if (c == '.') {
        while ((c = *s++) != '\0' && isdigit(c)) {
            a = a * 10.0 + (c - '0');
            e = e - 1;
        }
    }
    a = a * sign;
    if (c == 'e' || c == 'E') {
        int esign = 1;
        int ei = 0;
        c = *s++;
        if (c == '+') {
            c = *s++;
        } else if (c == '-') {
            c = *s++;
            esign = -1;
        }
        while (isdigit(c)) {
            ei = ei*10 + (c - '0');
            c = *s++;
        }
        e += ei*esign;
    }
    while (e > 0) {
        a *= 10.0;
        e--;
    }
    while (e < 0) {
        a *= 0.1;
        e++;
    }
    return a;
}

long double string_to_long_double(char *str, char **ptr) {
    char *p;
    if (ptr == (char **)0) {
        return string_to_double(str);
    }
    p = str;
    while (isspace(*p)) {
        p++;
    }
    if (*p == '+' || *p == '-') {
        p++;
    }
    // INF or INFINITY
    if ((p[0] == 'i' || p[0] == 'I')
    && (p[1] == 'n' || p[1] == 'N')
    && (p[2] == 'f' || p[2] == 'F')) {
        if ((p[3] == 'i' || p[3] == 'I')
        && (p[4] == 'n' || p[4] == 'N')
        && (p[5] == 'i' || p[5] == 'I')
        && (p[6] == 't' || p[6] == 'T')
        && (p[7] == 'y' || p[7] == 'Y')) {
            *ptr = p + 8;
            return INFINITY;
        } else {
            *ptr = p + 3;
            return INFINITY;
        }
    }
    // NAN
    if ((p[0] == 'n' || p[0] == 'N')
    && (p[1] == 'a' || p[1] == 'A')
    && (p[2] == 'n' || p[2] == 'N')) {
        p += 3;
        if (*p == '(') {
            ++p;
            while (*p != '\0' && *p != ')') {
              ++p;
            }
            if (*p == ')') {
              ++p;
            }
        }
        *ptr = p;
        return NAN;
    }
    if (isdigit(*p) || *p == '.') {
        int got_dot = 0;
        while (isdigit(*p) || (!got_dot && *p == '.')) {
            if (*p == '.') {
                got_dot = 1;
            }
            ++p;
        }
        if (*p == 'e' || *p == 'E') {
            int i;
            i = 1;
            if (p[i] == '+' || p[i] == '-') {
                ++i;
            }
            if (isdigit(p[i])) {
                while (isdigit(p[i])) {
                    ++i;
                }
                *ptr = p + i;
                return string_to_double(str);
            }
        }
        while (isspace(*p)) {
            p++;
        }
        *ptr = p;
        return string_to_double(str);
    }
    *ptr = str;
    return 0.0;
}

s21_size_t save_spaces(char *from, struct Spec *s) {
    s21_size_t space_count = s21_strspn(from, " ");
    if (space_count) {
        char *str = (char *) malloc((space_count + 1) * sizeof(char));
        s21_strncpy(str, from, space_count);
        str[space_count] = '\0';
        s->str = str;
        s->is_space = 1;
        *from += space_count;
    }
    return space_count;
}

void match_string(const char* *p_here, char* str, int spaces, int *p_error) {
    if (spaces) {
        s21_size_t space_count = s21_strspn(*p_here, " ");
        *p_here += space_count;
    } else {
        s21_size_t str_len = s21_strlen(str);
        if (s21_strncmp(*p_here, str, str_len)) {
            *p_error = 5;
        } else {
            *p_here += str_len;
        }
    }
}

void parse_spec(char *from, int size, struct Spec *s, int *error) {
    s->str = (char *) malloc ((size + 1) * sizeof(char));
    s21_strncpy(s->str, from, size);
    s->str[size] = '\0';
    s->type = ' ';
    s->width = 0;
    s->length = ' ';
    s->is_star = 0;
    s->is_space = 0;

    char *this = s->str;
    this++;
    if (*this == '%') {
        s->is_star = 0;
        s->type = '%';
    } else {
        if (*this == '*') {
            s->is_star = 1;
            this++;
        } else {
            s->is_star = 0;
            if (isdigit(*this)) {
                s->width = string_to_int(this);
                while (isdigit(*this)) {
                    this++;
                }
            }
            if (*this == 'h' || *this == 'l' || *this == 'L') {
                s->length = *this;
                this++;
                if (*this == 'l') {
                    s->length = 'x';
                    this++;
                }
            }
        }
        if (s21_strchr("cdieEfgGosuxXpn%\0", *this) != S21_NULL) {
            s->type = *this;
        } else {
            *error = 6;
        }
    }
    return;
}

int format_to_array(const char *format, struct Spec **specs, int *error) {
    int result = 0;
    char *from = malloc((s21_strlen(format) + 1) * sizeof(char));
    char *next = S21_NULL;
    from = s21_strcpy(from, format);
    while (*from) {
        int spaces = save_spaces(from, *specs + result);
        if (spaces) {
            from += spaces;
        } else {
            from = s21_strchr(from, '%');
            if (from == S21_NULL) {
                break;
            }
            next = s21_strchr(from + 1, '%');
            if (next == S21_NULL) {
                next = from + s21_strlen(from);
            }
            parse_spec(from, next - from, *specs + result, error);
            result++;
            from++;
        }
    }
    if (!specs) {
        result = 0;
    }
    free(from);
    return result;
}

// Считывает форматированный ввод из строки.
int s21_sscanf(const char *str, const char *format, ...) {
    int result = 0;
    if ((str == S21_NULL) || (format == S21_NULL)) {
        result = -1;
    } else {
        int error = 0;
        struct Spec *specs = malloc(s21_strlen(format) / 2 * sizeof(struct Spec));
        int spec_count = format_to_array(format, &specs, &error);
        va_list args;
        va_start(args, format);

        char* here = malloc((s21_strlen(str) + 1) * sizeof(char));
        here[s21_strlen(str)] = '\0';
        const char* const_here = here;
        s21_strcpy(here, str);
        int base = 10;
        for (int i = 0; i < spec_count; i++) {
            char *there = S21_NULL;
            switch (specs[i].type) {
                case 'o': case 'x': case 'X': case 'd': case 'i': case 'u': {
                    if (specs[i].type == 'o') {
                        base = 8;
                    } else if (specs[i].type == 'x' || specs[i].type == 'X') {
                        base = 16;
                    }
                    long _var0 = string_to_long(here, &there, base, specs[i].width);
                    if (is_empty(here)) {
                        if (result == 0) {
                            error = 1;
                        }
                        break;
                    }
                    if (*here == '\0' && *there == '\0') {
                        if (specs[i].is_star == 0) {
                            if (specs[i].length == 'x') {
                                *(va_arg(args, long long *)) = (long long) 0;
                            } else {
                                if (specs[i].length == 'l') {
                                    *(va_arg(args, long *)) = (long) 0;
                                } else if (specs[i].length == 'h') {
                                    *(va_arg(args, short *)) = (short) 0;
                                } else {
                                    *(va_arg(args, int *)) = (int) 0;
                                }
                            }
                        }
                    } else if (here != there) {
                        if (specs[i].is_star == 0) {
                            result++;
                            if (specs[i].length == 'x') {
                                long long _var1 = string_to_long_long(here, &there, base, specs[i].width);
                                *(va_arg(args, long long *)) = (long long) _var1;
                            } else if (specs[i].length == 'l') {
                                *(va_arg(args, long *)) = (long) _var0;
                            } else if (specs[i].length == 'h') {
                                *(va_arg(args, short *)) = (short) _var0;
                            } else {
                                *(va_arg(args, int *)) = (int) _var0;
                            }
                        }
                        if (specs[i].width > s21_strlen(here)) {
                            here += s21_strlen(here);
                        } else {
                            here = there;
                        }
                    }
                    break;
                }
                case 'p': {
                    long long _var2 = string_to_long_long(here, &there, 16, specs[i].width);
                    if (here != there) {
                        if (specs[i].is_star == 0) {
                            result++;
                            *(va_arg(args, long long *)) = _var2;
                        }
                        here = there;
                    } else {
                        if (specs[i].is_star == 0) {
                            error = 2;
                        }
                    }
                    break;
                }
                case 'f': case 'F': case 'g': case 'G': case 'e': case 'E': {
                    long double _var3 = string_to_long_double(here, &there);
                    if (here != there) {
                        if (specs[i].length == 'L') {
                            if (specs[i].is_star == 0) {
                                result++;
                                *(va_arg(args, long double *)) = _var3;
                            }
                        } else if (specs[i].length == 'l') {
                            if (specs[i].is_star == 0) {
                                result++;
                                *(va_arg(args, double *)) = _var3;
                            }
                        } else {
                            if (specs[i].is_star == 0) {
                                result++;
                                *(va_arg(args, float *)) = _var3;
                            }
                        }
                        here = there;
                    } else {
                        if (specs[i].is_star == 0) {
                            error = 3;
                        }
                    }
                    break;
                }
                case 'c': {
                    s21_size_t count = specs[i].width ? specs[i].width : 1;
                    if (s21_strlen(here) >= count) {
                        if (specs[i].is_star == 0) {
                            there = va_arg(args, char *);
                            s21_strncpy(there, here, count);
                            result++;
                            there[count] = '\0';
                        }
                        here += count;
                    } else {
                        if (specs[i].is_star == 0) {
                            error = 4;
                        }
                    }
                    while (*here == ' ') {
                        here++;
                    }
                    break;
                }
                case 's': {
                    while (isspace(*here) || *here == '\t') {
                        here++;
                    }
                    s21_size_t non_space_count = s21_strcspn(here, " \t");
                    s21_size_t count = 0;
                    if (specs[i].width == 0) {
                        count = non_space_count;
                    } else if (non_space_count < specs[i].width) {
                        count = non_space_count;
                    } else {
                        count = specs[i].width;
                    }
                    if (specs[i].is_star == 0) {
                        there = va_arg(args, char *);
                        s21_strncpy(there, here, count);
                        there[count] = '\0';
                        result++;
                    }
                    here += count;
                    break;
                }
                case '\0': {
                    match_string(&const_here, specs[i].str, specs[i].is_space, &error);
                    break;
                }
                case '%': {
                    match_string(&const_here, "%", specs[i].is_space, &error);
                    break;
                }
                case 'n': {
                    int len = (s21_strlen(str) - s21_strlen(here));
                    if (len > 0) {
                        *(va_arg(args, int *)) = (s21_strlen(str) - s21_strlen(here)) + 1;
                    } else {
                        *(va_arg(args, int *)) = 0;
                    }
                    break;
                }
                default: {}
            }
            if (error != 0) {
                break;
            }
        }
        va_end(args);
        if (error > 0) {
            result = -1;
        }

        for (int i = 0; i < spec_count; i++) {
            free(specs[i].str);
        }
        free(specs);
    }
    return result;
}
