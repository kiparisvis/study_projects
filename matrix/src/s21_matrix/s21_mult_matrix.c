#include "../s21_matrix.h"

/**
 * @brief
 * Произведением матрицы A = m × k на матрицу B = k × n
 * называется матрица C = m × n = A × B размера m × n,
 * элементы которой определяются равенством:
 * C(i,j) = A(i,1) × B(1,j) + A(i,2) × B(2,j) + … + A(i,k) × B(k,j).
 *
 * @param A матрица
 * @param B матрица
 * @param result матрица-результат
 * @return int код ошибки (если есть)
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  s21_matrix_error code = S21_MATRIX_OK;

  // кол-во столбцов матрицы А должно быть равно кол-ву строк матрицы В:
  if (A->columns != B->rows) {
    code = S21_MATRIX_ERROR_OF_CALC;
  }
  //  Проверяем на корректность матрицы:
  if (checking_matrix(*A) == S21_MATRIX_ERROR ||
      checking_matrix(*B) == S21_MATRIX_ERROR) {
    code = S21_MATRIX_ERROR;
  }
  // Создаем матрицу для записи результата:
  if (code == S21_MATRIX_OK) {
    s21_create_matrix(A->rows, B->columns, result);

    // Умножаем матрицы и записываем результат в новую:
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        double test_result = 0;
        for (int k = 0; k < A->columns /*?*/; k++) {
          test_result =
              test_result + *(*((A->matrix) + i) + k) * B->matrix[k][j];
        }
        result->matrix[i][j] = test_result;
      }
    }
  }

  return code;
}
