#include "../s21_matrix.h"

/**
 * @brief
 * Транспонирование матрицы А заключается в замене строк этой матрицы ее
 * столбцами с сохранением их номеров.
 *
 * Пример для матрицы:
 * 1 2 3
 * 4 5 6
 * 7 8 9
 *
 * Транспонированная матрица будет иметь вид:
 * 1 4 7
 * 2 5 8
 * 3 6 9
 *
 * @param A матрица
 * @param result матрица-результат
 * @return int код ошибки (если есть)
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  s21_matrix_error code = S21_MATRIX_OK;

  //  Проверяем на корректность матрицу:
  if (checking_matrix(*A) == S21_MATRIX_ERROR) {
    code = S21_MATRIX_ERROR;
  }

  if (code == S21_MATRIX_OK) {
    // Создаем матрицу для записи результата:
    s21_create_matrix(A->columns, A->rows, result);
    // Транспонируем матрицу и записываем результат в новую:
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        *(*((result->matrix) + j) + i) = A->matrix[i][j];
      }
    }
  }
  return code;
}
