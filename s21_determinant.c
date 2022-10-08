#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = MAX(is_empty(A), is_square(A));
  if (!status) *result = counter_determinant(A, A->rows);
  return status;
}
