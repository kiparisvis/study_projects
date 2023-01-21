#include "../s21_matrix.h"

/**
 * @brief
 * Проверка на положительные значения количества строк и столбцов
 * И на NULL указатели
 *
 * @param matrix матрица
 * @return int код ошибки (если есть)
 */
int checking_matrix(matrix_t matrix) {
  s21_matrix_error code = S21_MATRIX_OK;

  if (matrix.columns < 1 || matrix.rows < 1) {
    code = S21_MATRIX_ERROR;
  }

  return code;
}

/**
 * @brief
 * Создает матрицу миноров. Для матрицы:
 * 1 2 3
 * 4 5 6
 * 7 8 9
 *
 * Матрицей миноров для М11:
 *
 * 5 6
 * 8 9
 *
 * @param A матрица
 * @param new матрица миноров
 * @param skip_row номер вычеркиваемой сроки
 * @param skip_column номер вычеркиваемого столбца
 */
void get_minor_matrix(matrix_t *A, matrix_t *new, int skip_row,
                      int skip_column) {
  int in = 0, jn = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != skip_row) {
      for (int j = 0; j < A->columns; j++) {
        if (j != skip_column) {
          *(*((new->matrix) + in) + jn) = *(*((A->matrix) + i) + j);
          jn++;
        }
      }
      in++;
      jn = 0;
    }
  }
}

/**
 * @brief
 * Добавляет алгебраические дополнения к матрице
 * Алгебраическим дополнением элемента aij определителя D называется его минор,
 * взятый со знаком (-1)i+j.
 *
 * @param A матрица
 */
void algebraic_additions(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      *(*((A->matrix) + i) + j) = *(*((A->matrix) + i) + j) * pow(-1, (i + j));
    }
  }
}

/**
 * @brief
 * Функция копирования матрицы дя тестов
 *
 * @param matrix
 * @param tmp
 */
void cpy_matrixes(matrix_t *matrix, double tmp[matrix->rows][matrix->columns]) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = tmp[i][j];
    }
  }
}
