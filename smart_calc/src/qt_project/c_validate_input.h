#ifndef C_VALIDATE_INPUT_H
#define C_VALIDATE_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_pushed_buttons(char* display_string, char* in_button);
int check_dot(char* display_string, int len);
int check_num_first_zero(char* display_string, int len);
int check_num_of_brackets(char* display_string, int len);
int delete_last_input(char* display_string);
int error_in_finished_string(char* display_string);
int is_correct_num(char* display_string, int len);
int check_x_y_min_max(double xMin, double xMax, double yMin, double yMax);

#endif  // C_VALIDATE_INPUT_H
