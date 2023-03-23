#include "c_validate_input.h"

int validate_pushed_buttons(char* display_string, char* in_button) {
  int val = 0;
  int in_button_len = (int)strlen(in_button);
  int display_string_len = (int)strlen(display_string);
  if (display_string_len > 255) {
    val = 5;
  } else if (in_button_len == 1) {
    if (strchr("0123456789", in_button[0])) {
      if (display_string[display_string_len - 1] == '0') {
        val = check_num_first_zero(display_string, display_string_len);
      } else if (!strchr("x)", display_string[display_string_len - 1])) {
        val = 1;
      }
    } else if (in_button[0] == '.' &&
               strchr("0123456789", display_string[display_string_len - 1])) {
      val = check_dot(display_string, display_string_len);
    } else if (strchr("+-", in_button[0])) {
      if (display_string_len == 1 && display_string[0] == '0') {
        val = 2;
      } else if (strchr("0123456789()x*/+-^d",
                        display_string[display_string_len - 1])) {
        val = 1;
      }
    } else if (strchr("*/^", in_button[0]) &&
               strchr("0123456789)x", display_string[display_string_len - 1])) {
      val = 1;
    } else if (in_button[0] == '(' || in_button[0] == 'x') {
      if (display_string_len == 1 && display_string[0] == '0') {
        val = 2;
      } else if (strchr("+-*/^d(", display_string[display_string_len - 1])) {
        val = 1;
      }
    } else if (in_button[0] == ')' &&
               strchr("0123456789)x", display_string[display_string_len - 1])) {
      val = check_num_of_brackets(display_string, display_string_len);
    }
  } else {
    if (in_button[0] == 'm') {
      if (strchr("0123456789)x", display_string[display_string_len - 1])) {
        val = 1;
      }
    } else {
      if (display_string_len == 1 && display_string[0] == '0') {
        val = 3;
      } else if (strchr("+-*/^d(", display_string[display_string_len - 1])) {
        val = 4;
      }
    }
  }
  return val;
}

int check_dot(char* display_string, int len) {
  int val = 1, len_last_num = 0;
  for (int i = len - 1; strchr("0123456789.", display_string[i]); i--) {
    len_last_num++;
  }
  for (int i = len - len_last_num - 1; i < len; i++) {
    if (display_string[i] == '.') {
      val = 0;
      break;
    }
  }
  return val;
}

int check_num_first_zero(char* display_string, int len) {
  int val = 1;
  if (display_string[len - 1] == '0' &&
      (len == 1 || !strchr("0123456789.", display_string[len - 2]))) {
    val = 2;
  }
  return val;
}

int check_num_of_brackets(char* display_string, int len) {
  int val = 0, left = 0, right = 0;
  for (int i = 0; i < len; i++) {
    if (display_string[i] == '(') left++;
    if (display_string[i] == ')') right++;
  }
  if (left > right) {
    val = 1;
  }
  return val;
}

int delete_last_input(char* display_string) {
  int num_of_char_delete = 0;
  int len = (int)strlen(display_string);
  char last_char = display_string[len - 1];
  if (strchr("0123456789.)x^/*-+", last_char)) {
    num_of_char_delete = 1;
  } else if (last_char == '(') {
    if (strchr("+-*/^(d", display_string[len - 2])) {
      num_of_char_delete = 1;
    } else if (display_string[len - 2] == 'n' &&
               display_string[len - 3] == 'l') {
      num_of_char_delete = 3;
    } else if (display_string[len - 2] == 'n' ||
               display_string[len - 2] == 's') {
      if (display_string[len - 5] == 'a') {
        num_of_char_delete = 5;
      } else {
        num_of_char_delete = 4;
      }
    } else if (display_string[len - 2] == 'g') {
      num_of_char_delete = 4;
    } else if (display_string[len - 2] == 't') {
      num_of_char_delete = 5;
    }
  } else if (last_char == 'd') {
    num_of_char_delete = 3;
  }
  return num_of_char_delete;
}

int error_in_finished_string(char* display_string) {
  int err = 0;
  int len = strlen(display_string);
  if (check_num_of_brackets(display_string, len)) {
    err = 2;
  }
  if (strchr("^/*-+d.(", display_string[len - 1])) {
    err += 1;
  }
  return err;
}

int is_correct_num(char* display_string, int len) {
  int val = 0, dots = 0, start = 0;
  if (display_string[0] == '.' ||
      (display_string[0] == '-' && display_string[1] == '.')) {
    val = 1;
  } else {
    if (display_string[0] == '-') start = 1;
    for (int i = start; i < len; i++) {
      if (display_string[i] == '.') {
        dots++;
        if (dots > 1) {
          val = 1;
          break;
        }
      } else if (!strchr("0123456789.", display_string[i])) {
        val = 1;
        break;
      }
    }
  }
  return val;
}

int check_x_y_min_max(double xMin, double xMax, double yMin, double yMax) {
  int err = 0;
  if (xMin > 1000000 || xMin < -1000000) err += 1;
  if (xMax > 1000000 || xMax < -1000000) err += 10;
  if (yMin > 1000000 || yMin < -1000000) err += 100;
  if (yMax > 1000000 || yMax < -1000000) err += 1000;
  return err;
}
