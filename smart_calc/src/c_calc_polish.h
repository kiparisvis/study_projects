#ifndef C_CALC_POLISH_H
#define C_CALC_POLISH_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief Элемент двусвязного списка. Хранимые данные: одна лексема
/// выражения.
/// @details Для каждого типа лексем: число, операция, х, используется своё поле
/// структуры. В одном элементе списка не могут быть одновременно заполнены
/// несколько типов.
typedef struct Node_tag {
  double num;              /*!< число*/
  char operat;             /*!< операция*/
  char x;                  /*!< переменная х*/
  unsigned short priority; /*!< приоритет операции (заполняется в случае если
                              лексема - операция)*/
  struct Node_tag* next; /*!< указатель на следующий элемент списка*/
  struct Node_tag* last; /*!< указатель на предыдущий элемент списка*/
} Node_t;

Node_t* init_struct();
void delete_list_since_last(Node_t* last);
void delete_list_since_first(Node_t* first);
void copy_node_value(Node_t* from, Node_t* to);
Node_t* push(Node_t* last_node, Node_t* value);
Node_t* pop(Node_t* from, Node_t* to);
char* simplify_infix_string(char* infix_string);
int parse_simple_infix_to_list(char* infix_string, Node_t* first);
Node_t* infix_list_to_reverse_polish_list(Node_t* in_first);
double do_unary_operator(char operat, double num1);
double do_binary_operator(char operat, double num1, double num2);
void replace_x_by_num(Node_t* polish_first, double num);
double calc_polish_list(Node_t* polish_first);
Node_t* infix_string_to_polish_list(char* infix_string);
double calc_infix_string_without_x(char* infix_string);
double calc_infix_string_with_x(char* infix_string, double x);

#endif  // C_CALC_POLISH_H
