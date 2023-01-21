#include "../s21_matrix.h"

/**
 * @brief
 * Функция выделения памяти под матрицы
 *
 * @param rows строки
 * @param columns столбцы
 * @param result матрица-результат
 * @return int код ошибки (если есть)
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  s21_matrix_error code = S21_MATRIX_OK;

  if (rows > 0 && columns > 0) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = calloc(rows, sizeof(double *));

    if (result->matrix != NULL) {
      for (int i = 0; i < result->rows; i++) {
        result->matrix[i] = calloc(result->columns, sizeof(double *));
        code = S21_MATRIX_OK;
      }
    } else {
      code = S21_MATRIX_ERROR;
    }
  } else {
    code = S21_MATRIX_ERROR;
  }

  return code;
}
