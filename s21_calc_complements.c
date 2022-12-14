#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = MAX(is_empty(A), is_square(A));
  init_matrix(result);
  if (!status) {
    minor(A, result);
  }
  return status;
}
