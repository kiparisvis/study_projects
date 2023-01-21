#include "s21_strerror.h"
#include "s21_string.h"

char message[MAX_MESSAGE];
const char *errors[ERRMAX] = ERRORS;

char *s21_strerror(int errnum) {
    if ((errnum >= 0) && (errnum < ERRMAX - 1)) {
        s21_strcpy(message, errors[errnum]);
    } else {
        s21_sprintf(message, "%s %d", errors[ERRMAX - 1], errnum);
    }
    return message;
}
