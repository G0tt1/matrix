#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!not_empty_matrix(A)) return 1;
  if (A->rows != A->columns) return 2;
  int size = A->rows;
  s21_create_matrix(size, size, result);

  if (size == 1) {
    result->matrix[0][0] = 1.0;
    return 0;
  }

  matrix_t minor;
  s21_create_matrix(size - 1, size - 1, &minor);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      for (int row = 0; row < size - 1; row++) {
        for (int col = 0; col < size - 1; col++) {
          int minor_row = row < i ? row : row + 1;
          int minor_col = col < j ? col : col + 1;
          minor.matrix[row][col] = A->matrix[minor_row][minor_col];
        }
      }

      double minor_determinant;
      s21_determinant(&minor, &minor_determinant);
      result->matrix[i][j] = pow(-1, i + j) * minor_determinant;
    }
  }

  s21_remove_matrix(&minor);
  return 0;
}