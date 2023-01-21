#include "../s21_matrix.h"

/**
 * @brief
 * Функция очищения памяти матрицы
 *
 * @param A матрица
 */
void s21_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(*((A->matrix) + i));
    }
    free(A->matrix);
  }
}
