#include "s21_matrix.h"

bool not_empty_matrix(matrix_t *matrix) {
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0)
    return false;
  return true;
}

void print_matrix(matrix_t *mat) {
  for (int i = 0; i < mat->rows; i++) {
    for (int j = 0; j < mat->columns; j++) {
      printf("%lf ", mat->matrix[i][j]);
    }
    printf("\n");
  }
}