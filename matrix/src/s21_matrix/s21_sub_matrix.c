#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  s21_matrix_error code = S21_MATRIX_OK;

  if ((A == NULL || A->matrix == NULL) || (B == NULL || B->matrix == NULL)) {
    code = S21_MATRIX_ERROR;
  } else if ((A->columns <= 0 || A->rows <= 0) ||
             (B->columns <= 0 || B->rows <= 0)) {
    code = S21_MATRIX_ERROR;
  } else if (!(A->rows == B->rows && A->columns == B->columns)) {
    code = S21_MATRIX_ERROR_OF_CALC;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return code;
}
