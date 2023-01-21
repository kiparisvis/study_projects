#include "../s21_matrix.h"

/**
 * @brief
 * Две матрицы A, B совпадают |A = B|, если совпадают их размеры
 * и соответствующие элементы равны, то есть при всех i, j A(i,j) = B(i,j).
 *
 * Сравнение должно происходить вплоть до 7 знака после запятой включительно.
 *
 * @param A матрица
 * @param B матрица
 * @return int результат сравнения
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code_eq = SUCCESS;

  if (checking_matrix(*A) == S21_MATRIX_ERROR ||
      checking_matrix(*B) == S21_MATRIX_ERROR) {
    code_eq = FAILURE;
  }
  if (code_eq == SUCCESS) {
    if (!(A->columns == B->columns &&
          A->rows == B->rows)) {  // Проверяем соответствие размерности
      code_eq = FAILURE;
    }
  }
  if (code_eq == SUCCESS) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >
            EPS) {  // Если больше, то не равны
          code_eq = FAILURE;
        }
        if (code_eq == FAILURE) {
          break;
        }
      }
      if (code_eq == FAILURE) {
        break;
      }
    }
  }

  return code_eq;
}
