#include "../s21_matrix.h"

/**
 * @brief
 * Минор матрицы и матрица алгебраических дополнений.
 * Возможно вычисление определителя ТОЛЬКО для квадратной матрицы
 *
 * @param A матрица
 * @param result матрица-результат
 * @return int код ошибки (если есть)
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  s21_matrix_error code = S21_MATRIX_OK;
  //  Проверяем на корректность матрицы:
  if (checking_matrix(*A) == S21_MATRIX_ERROR) {
    code = S21_MATRIX_ERROR;
  }
  // Проверка на квадратность матрицы:
  if (code == S21_MATRIX_OK) {
    if (A->rows != A->columns) {
      code = S21_MATRIX_ERROR_OF_CALC;
    }
  }
  // Если матрица 1 на 1, то особый случай
  if (code == S21_MATRIX_OK && A->rows == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = A->matrix[0][0];
  } else if (code == S21_MATRIX_OK) {
    matrix_t temp_matrix;
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        // Создаем матрицу n-1
        // Если мы делаем обратную матрицу 1 на 1, то получается, что здесь
        // размерность матрицы будет 0
        s21_create_matrix(A->rows - 1, A->columns - 1, &temp_matrix);
        // Заливаем матрицу и колоночки.
        get_minor_matrix(A, &temp_matrix, i, j);
        double det = 0;
        s21_determinant(&temp_matrix, &det);
        result->matrix[i][j] = det;
        s21_remove_matrix(&temp_matrix);
      }
    }
    algebraic_additions(result);
  }

  return code;
}
