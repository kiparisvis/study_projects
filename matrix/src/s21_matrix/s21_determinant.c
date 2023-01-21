#include "../s21_matrix.h"

/**
 * @brief
 * Определитель (детерминант) - это число, которое ставят
 * в соответствие каждой квадратной матрице
 * и вычисляют из элементов по специальным формулам.
 *
 * Определитель может быть вычислен только для квадратной матрицы.
 * Определитель матрицы равен сумме произведений элементов строки (столбца)
 * на соответствующие алгебраические дополнения.
 *
 * @param A матрица
 * @param result детерминант
 * @return int код ошибки (если есть)
 */
int s21_determinant(matrix_t *A, double *result) {
  *result = 0;
  s21_matrix_error code = S21_MATRIX_OK;

  //  Проверяем на корректность матрицы:
  if (checking_matrix(*A) == S21_MATRIX_ERROR) {
    code = S21_MATRIX_ERROR;
  }
  // Проверка на квадратность матрицы
  // Также проверка на единичную матрицу
  if (code == S21_MATRIX_OK) {
    if (A->rows != A->columns) {
      code = S21_MATRIX_ERROR_OF_CALC;
    }
  }
  if (code == S21_MATRIX_OK) {
    int size_matrix = A->rows;
    if (size_matrix == 1) {
      *result = A->matrix[0][0];
    } else if (size_matrix == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
    } else if (size_matrix > 2) {
      for (int i = 0; i < A->rows; i++) {
        matrix_t temp_matrix;
        // Создаем новую матрицу размерности n-1
        s21_create_matrix(A->rows - 1, A->columns - 1, &temp_matrix);
        // Заполняем ее минором от текущей строковой итерации главной матрицы
        get_minor_matrix(A, &temp_matrix, i, 0);
        double d = 0;
        s21_determinant(&temp_matrix, &d);
        *result = *result + (A->matrix[i][0] * d) * pow(-1, i + 2);
        s21_remove_matrix(&temp_matrix);
      }
    }
  }

  return code;
}
