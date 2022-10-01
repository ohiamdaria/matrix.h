#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = is_agreed(A, B);
  if (status) {
    status = OK;
    status = s21_create_matrix(A->rows, A->rows, result);
    if (!status) {
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->rows; j++) {
          status = simple_mul(A, B, &result->matrix[i][j], i, j);
        }
    }
  } else {
    status = ARITHM_ERROR;
  }
  return status;
}
