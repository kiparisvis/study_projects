#include "../s21_matrix.h"

/**
 * @brief
 * Матрицу A в степени -1 называют обратной к квадратной матрице А,
 * если произведение этих матриц равняется единичной матрице.
 *
 * Обратной матрицы не существует, если определитель равен 0.
 *
 * Обратная матрица находится по формуле A−1=1∣A∣×A∗TA^{-1}=\frac{1} {|A|} ×
 * A_*^TA−1=∣A∣1​×A∗T​
 *
 * @param A матрица
 * @param result матрица-результат
 * @return int код ошибки (если есть)
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  s21_matrix_error code = S21_MATRIX_OK;

  double det = 0;
  s21_determinant(A, &det);
  //  Проверяем на корректность матрицы:
  if (checking_matrix(*A) == S21_MATRIX_ERROR) {
    code = S21_MATRIX_ERROR;
  }
  // Проверка на квадратность матрицы
  if (code == S21_MATRIX_OK) {
    if (A->rows != A->columns) {
      code = S21_MATRIX_ERROR_OF_CALC;
    }
  }
  if (code == S21_MATRIX_OK) {  // Условие на проверку определителя. Если 0 -
                                // решений бесконечность
    if (fabs(det) > 1e6) {  //  Значит 0 - ошибка
      code = S21_MATRIX_ERROR_OF_CALC;
    }
  }
  // перед тем как транспонировать матрицу, надо создать матрицу
  // алгебраических дополнений

  // Специальный случай для матрицы 1 на 1
  if (code == S21_MATRIX_OK && A->columns == 1) {
    // Создаем новую матрицу и записываем туда ответ:
    s21_create_matrix(1, 1, result);
    result->matrix[0][0] = 1 / A->matrix[0][0];
  } else if (code == S21_MATRIX_OK) {
    // Объявляем временную матрицу:
    matrix_t temp_matrix;    // для минорной матрицы
    matrix_t temp_matrix_2;  // для транспонирования
    // Транспонируем  матрицу:
    s21_transpose(A, &temp_matrix);

    // Алгебраические дополнение транспонированной минорной матрицы:
    s21_calc_complements(&temp_matrix, &temp_matrix_2);

    // Делим 1/det по формуле:
    det = 1 / det;
    // Создаем матрицу результат:
    // Умножаем траспонированную матрицу на 1/детерминант:
    s21_mult_number(&temp_matrix_2, det, result);
    // Очищаем временные матрицы:
    s21_remove_matrix(&temp_matrix);
    s21_remove_matrix(&temp_matrix_2);
  }

  return code;
}
