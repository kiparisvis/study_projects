#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  s21_matrix_error code = S21_MATRIX_OK;
  if (A == NULL || A->matrix == NULL) {
    code = S21_MATRIX_ERROR;
  } else if (A->columns <= 0 || A->rows <= 0) {
    code = S21_MATRIX_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return code;
}