#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!not_empty_matrix(A)) return 1;
  if (A->rows != A->columns) return 2;

  double det;
  s21_determinant(A, &det);

  if (fabs(det) < 1e-7) {
    return 2;
  }

  matrix_t complements;
  s21_calc_complements(A, &complements);

  matrix_t transposed;
  s21_transpose(&complements, &transposed);

  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = transposed.matrix[i][j] / det;
    }
  }

  s21_remove_matrix(&complements);
  s21_remove_matrix(&transposed);

  return 0;
}