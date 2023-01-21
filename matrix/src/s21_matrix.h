#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;     // строки
  int columns;  // столбцы
} matrix_t;

#define SUCCESS 1
#define FAILURE 0
#define EPS 1e-7

/**
 * - 0 - OK
 * - 1 - Ошибка, некорректная матрица
 * - 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
 * нельзя провести вычисления и т.д.
 */
typedef enum s21_matrix_error {
  S21_MATRIX_OK = 0,
  S21_MATRIX_ERROR = 1,
  S21_MATRIX_ERROR_OF_CALC = 2
} s21_matrix_error;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int checking_matrix(matrix_t matrix);
void get_minor_matrix(matrix_t *A, matrix_t *new, int skip_row,
                      int skip_column);
void algebraic_additions(matrix_t *A);

// ТЕСТОВЫЕ ФУНКЦИИ
int test_fill_matrix(matrix_t *matrix, double *values);
int test_show_matrix(matrix_t *matrix);
int test_show_matrix_address(matrix_t *matrix);
void pt(char *str);
void cpy_matrixes(matrix_t *matrix, double tmp[matrix->rows][matrix->columns]);

#endif  // SRC_S21_MATRIX_H_