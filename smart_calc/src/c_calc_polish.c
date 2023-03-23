#include "c_calc_polish.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///  @mainpage Calc Polish
///  @section intro_sec Назначение:
///  Вычисление строки с инфиксной записью математического выражения
///  с или без "х".
///  @author romainez
///  @date 12/2022

///  @brief Создание несвязанного обнуленного узла списка
///  @details По умолчанию все поля структуры обнуляются, кроме num. По
///  умолчанию num = NAN.
///  @return Указатель на инициализированный не связанный узел списка.

Node_t* init_struct() {
  Node_t* node = calloc(sizeof(Node_t), 1);
  node->num = NAN;
  return node;
}

/// @brief Удаление всех узлов списка начиная с конечного (перебор по last).
void delete_list_since_last(Node_t* last) {
  Node_t* now = last;
  while (now) {
    last = now->last;
    free(now);
    now = last;
  }
}

/// @brief Удаление всех узлов списка начиная с начального (перебор по next).
void delete_list_since_first(Node_t* first) {
  Node_t* now = first;
  while (now) {
    first = now->next;
    free(now);
    now = first;
  }
}

/// @brief Копирование данных исходного узла (from) в целевой (to), при условии
/// что from и to не NULL.
/// @details Копируются только данные, указатели на предыдущий (last) и
/// следующий (next) узлы не копируются.
/// @param from - указатель на исходный узел (откуда копируем)
/// @param to - указатель на целевой узал (куда копируем)
void copy_node_value(Node_t* from, Node_t* to) {
  if (from && to) {
    to->num = from->num;
    to->operat = from->operat;
    to->priority = from->priority;
    to->x = from->x;
  }
}

/// @brief Добавление в конец списка (после last_node) нового элемента и
/// копирование в него данных из value.
/// @details Если last_node существует (!=NULL), прописываются связи next и last
/// с новым узлом. В противном случае новый элемент считается первым в списке
/// (нет связей next и last) и в него копируются данные value. Если value ==
/// NULL, создается узел со связями без данных.
/// @param last_node - указатель на последний в списке элемент, после которого
/// создается новый
/// @param value - указатель на элемент списка откуда копируются данные в новый
/// элемент
Node_t* push(Node_t* last_node, Node_t* value) {
  Node_t* new = init_struct();
  if (last_node != NULL) {
    new->last = last_node;
    last_node->next = new;
  }
  copy_node_value(value, new);
  return new;
}

/// @brief Копирование данных из последнего узла списка from в узел другого
/// списка to, удаление узла from.
/// @param from - указатель на удаляемый последний элемент списка
/// @param to - указатель на узел, в который копируются данные из from
/// @return Указатель на узел предшествующий from или NULL.
Node_t* pop(Node_t* from, Node_t* to) {
  copy_node_value(from, to);
  if (from->last) {
    Node_t* temp = from;
    from = temp->last;
    from->next = NULL;
    free(temp);
  } else {
    free(from);
    from = NULL;
  }
  return from;
}

/// @brief Сокращение в строке с выражением лексем операторов до одной буквы.
/// @details mod:m, cos:c, sin:s, tan:t, acos:o, asin:i, atan:a, sqrt:q, ln:l,
/// log:g
/// @param infix_string - указатель на строку с инфиксным выражением
/// @return указатель на упрощенную строку
char* simplify_infix_string(char* infix_string) {
  int string_len = strlen(infix_string);
  char* temp = calloc(sizeof(char), 255);
  int temp_i = 0;
  for (int i = 0; i <= string_len; i++) {
    if (strchr("mcts", infix_string[i]) && infix_string[i + 1] != 'q') {
      temp[temp_i++] = infix_string[i];
      i += 2;
    } else if (infix_string[i] == 'a') {
      temp[temp_i++] = infix_string[i + 2];
      i += 3;
    } else if (infix_string[i] == 's' && infix_string[i + 1] == 'q') {
      temp[temp_i++] = 'q';
      i += 3;
    } else if (infix_string[i] == 'l' && infix_string[i + 1] == 'n') {
      temp[temp_i++] = 'l';
      i += 1;
    } else if (infix_string[i] == 'l' && infix_string[i + 1] == 'o') {
      temp[temp_i++] = 'g';
      i += 2;
    } else {
      temp[temp_i++] = infix_string[i];
    }
  }
  return temp;
}

/// @brief Перевод подготовленной упрощенной строки с инфиксной записью в
/// инфиксный список лексем, а также присвоение приоритета операторам.
/// @param infix_string - указатель на строку с инфиксным
/// @param first - указатель на первый элемент инфиксного списка
int parse_simple_infix_to_list(char* infix_string, Node_t* first) {
  int string_len = strlen(infix_string);
  char lexem[255];
  int j;
  Node_t* now = first;
  for (int i = 0; i < string_len; i++) {
    if (strchr("0123456789", infix_string[i])) {
      // парсим, переводим в double и записываем в список числа из строки
      j = 0;
      while (strchr("0123456789.,", infix_string[i]) && i < string_len) {
        lexem[j++] = infix_string[i++];
      }
      lexem[j] = '\0';
      i--;
      now->num = atof(lexem);
    } else if (strchr("+-", infix_string[i])) {
      if (i == 0 || strchr("(*/+-^d", infix_string[i - 1])) {
        // + - унарные
        if (infix_string[i] == '-')
          now->operat = '~';
        else if (infix_string[i] == '+')
          now->operat = '&';
        now->priority = 3;
      } else {
        // + - бинарные
        now->operat = infix_string[i];
        now->priority = 1;
      }
    } else if (strchr("cstoiaqlg", infix_string[i])) {
      // cos, sin, tan, acos, asin, atan, sqrt, ln, log
      now->operat = infix_string[i];
      now->priority = 3;
    } else if (strchr("()", infix_string[i])) {
      now->operat = infix_string[i];
      now->priority = 4;
    } else if (strchr("*/m", infix_string[i])) {
      // * / mod
      now->operat = infix_string[i];
      now->priority = 2;
    } else if (infix_string[i] == '^') {
      now->operat = infix_string[i];
      now->priority = 3;
    } else if (infix_string[i] == 'x') {
      now->x = infix_string[i];
    }
    now = push(now, NULL);
  }
  pop(now, NULL);
  return 0;
}

/// @brief Перевод инфиксного списка в список обратной польской нотации
/// @param in_first - указатель на первый элемент инфиксного списка
/// @return Указатель на первый элемент списка обратной польской нотации
Node_t* infix_list_to_reverse_polish_list(Node_t* in_first) {
  Node_t *out_first, *out_now, *stack = NULL;
  out_now = out_first = init_struct();
  for (Node_t* in_now = in_first; in_now; in_now = in_now->next) {
    if (in_now->num == in_now->num || in_now->x) {
      out_now = push(out_now, in_now);
    } else if (in_now->operat == '(') {
      stack = push(stack, in_now);
    } else if (in_now->operat != ')') {
      while (stack && in_now->priority < stack->priority &&
             stack->operat != '(') {
        out_now = push(out_now, NULL);
        stack = pop(stack, out_now);
      }
      stack = push(stack, in_now);
    } else if (in_now->operat == ')') {
      while (stack->operat != '(') {
        out_now = push(out_now, NULL);
        stack = pop(stack, out_now);
      }
      stack = pop(stack, NULL);
    }
  }
  while (stack) {
    out_now = push(out_now, NULL);
    stack = pop(stack, out_now);
  }
  delete_list_since_first(in_first);
  return out_first;
}

/// @brief Производит унарную операцию с одним числом (num1) согласно
/// переданному оператору (operat).
/// @param operat - char обозначающий унарную операцию
/// @param num1 - число для проведения унарной операции
/// @return Итог вычисления унарной операции, тип данных: double.
double do_unary_operat(char operat, double num1) {
  double answer = NAN;
  switch (operat) {
    case 'c':
      answer = cos(num1);
      break;
    case 's':
      answer = sin(num1);
      break;
    case 't':
      answer = tan(num1);
      break;
    case 'o':
      answer = acos(num1);
      break;
    case 'i':
      answer = asin(num1);
      break;
    case 'a':
      answer = atan(num1);
      break;
    case 'q':
      answer = sqrt(num1);
      break;
    case 'l':
      answer = log(num1);
      break;
    case 'g':
      answer = log10(num1);
      break;
    case '~':
      answer = -num1;
      break;
    case '&':
      answer = num1;
      break;
  }
  return answer;
}

/// @brief Производит бинарную операцию согласно переданному оператору (operat).
/// @param operat - char обозначающий унарную операцию
/// @param num1 - первое число из стека для проведения бинарной операции
/// @param num2 - второе число из стека для проведения бинарной операции
/// @return Итог вычисления бинарной операции, тип данных: double.
double do_binary_operat(char operat, double num1, double num2) {
  double answer = NAN;
  switch (operat) {
    case '+':
      answer = num2 + num1;
      break;
    case '-':
      answer = num2 - num1;
      break;
    case '*':
      answer = num2 * num1;
      break;
    case '/':
      answer = num2 / num1;
      break;
    case '^':
      answer = pow(num2, num1);
      break;
    case 'm':
      answer = fmod(num2, num1);
      break;
  }
  return answer;
}

/// @brief Замена х на число в списке обратной польской нотации
/// @param polish_first - указатель на первый элемент списка обратной польской
/// нотации
/// @param num - число заменяемое х
void replace_x_by_num(Node_t* polish_first, double num) {
  for (Node_t* polish_now = polish_first; polish_now;
       polish_now = polish_now->next) {
    if (polish_now->x) {
      polish_now->x = 0;
      polish_now->num = num;
    }
  }
}

/// @brief Вычисление обратной польской записи
/// @param polish_first - указатель на превый элемент списка обратной польской
/// записи
/// @return Результат вычисления обратной польской записи в типе данных double.
double calc_polish_list(Node_t* polish_first) {
  Node_t* polish_now = polish_first->next;
  Node_t* stack = NULL;
  for (; polish_now; polish_now = polish_now->next) {
    if (polish_now->num == polish_now->num) {
      stack = push(stack, polish_now);
    } else if (polish_now->operat) {
      if (strchr("cstoiaqlg~&", polish_now->operat)) {
        // если унарный оператор
        stack->num = do_unary_operat(polish_now->operat, stack->num);
      } else if (strchr("+-*/^m", polish_now->operat)) {
        // если бинарный оператор
        stack->last->num =
            do_binary_operat(polish_now->operat, stack->num, stack->last->num);
        stack = pop(stack, NULL);
      }
    }
  }
  double answer = stack->num;
  delete_list_since_last(stack);
  return answer;
}

/// @brief Преобразование входящей инфиксной строки в список обратной польской
/// записи.
/// @details Создана для предотвращения дублирования кода в функциях
/// calc_infix_string_without_x и calc_infix_string_whith_x. Последовательно
/// выполняет упрощение входной строки, перевод её в инфиксный список, далее
/// перевод в список обратной польской нотации.
/// @param infix_string - указатель на корректную инфиксную строку
/// @return Указатель на первый элемент списка обратной польской записи.
Node_t* infix_string_to_polish_list(char* infix_string) {
  char* simple_infix_string = simplify_infix_string(infix_string);
  Node_t* infix_list_first = init_struct();
  parse_simple_infix_to_list(simple_infix_string, infix_list_first);
  free(simple_infix_string);
  Node_t* polish_list_first =
      infix_list_to_reverse_polish_list(infix_list_first);
  return polish_list_first;
}

/// @brief Основная функция вычисления инфиксной строки не содержащей х.
/// @param infix_string - указатель на корректную инфиксную строку
/// @return Результат вычислений в типе данных double.
double calc_infix_string_without_x(char* infix_string) {
  Node_t* polish_list_first = infix_string_to_polish_list(infix_string);
  double answer = calc_polish_list(polish_list_first);
  delete_list_since_first(polish_list_first);
  return answer;
}

/// @brief Основная функция вычисления инфиксной строки содержащей х.
/// @details Функцианал почти аналогичен calc_infix_string_without_x, разница в
/// добавлении функции замены х на значение.
/// @param infix_string - указатель на корректную инфиксную строку
/// @param x - значение для замены х
/// @return Результат вычислений в типе данных double.

double calc_infix_string_with_x(char* infix_string, double x) {
  Node_t* polish_list_first = infix_string_to_polish_list(infix_string);
  replace_x_by_num(polish_list_first, x);
  double y = calc_polish_list(polish_list_first);
  delete_list_since_first(polish_list_first);
  return y;
}
