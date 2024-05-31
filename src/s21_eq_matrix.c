#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (A->rows == B->rows && A->columns == B->columns && not_empty_matrix(A) &&
      not_empty_matrix(B)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (round(A->matrix[i][j] * pow(10, 7)) !=
            round(B->matrix[i][j] * pow(10, 7))) {
          return FAILURE;
        }
      }
    }
  } else
    return FAILURE;
  return flag;
}