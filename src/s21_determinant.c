#include "s21_matrix.h"

double s21_mini_determinant(matrix_t *A) {
  return A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
}

int s21_determinant(matrix_t *A, double *result) {
  *result = 0.0;

  if (not_empty_matrix(A)) {
    if (A->rows == A->columns) {
      if (A->rows == 1)
        *result = A->matrix[0][0];
      else if (A->rows == 2)
        *result = s21_mini_determinant(A);
      else {
        matrix_t mini_A;
        double mini_result;
        s21_create_matrix(A->rows - 1, A->columns - 1, &mini_A);

        for (int j = 0; j < A->columns; j++) {
          for (int row = 1; row < A->rows; row++) {
            int colIndex = 0;
            for (int col = 0; col < A->columns; col++) {
              if (col != j) {
                mini_A.matrix[row - 1][colIndex] = A->matrix[row][col];
                colIndex++;
              }
            }
          }
          s21_determinant(&mini_A, &mini_result);
          *result += A->matrix[0][j] * pow(-1, j) * mini_result;
        }
        s21_remove_matrix(&mini_A);
      }
    } else
      return 2;
  } else
    return 1;
  return 0;
}