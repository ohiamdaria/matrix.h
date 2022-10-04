#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double det = 0.0;
  int status = s21_determinant(A, &det);
  init_matrix(result);
  if (fabs(det) < 1e-7 || (A->columns != A->rows)) status = ARITHM_ERROR;

  if (!status) {
    if (A->rows == 1 && A->columns == 1) {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = (double)1 / A->matrix[0][0];
    } else {
      matrix_t mat2;
      init_matrix(&mat2);
      minor(A, &mat2);
      matrix_t mat3;
      init_matrix(&mat3);
      if (!s21_transpose(&mat2, &mat3)) {
        if (!s21_mult_number(&mat3, (double)1 / det, result)) {
          status = OK;
        } else {
          s21_remove_matrix(result);
          status = ARITHM_ERROR;
        }
      } else {
        status = MATRIX_ERROR;
      }
      s21_remove_matrix(&mat3);
      s21_remove_matrix(&mat2);
    }
  }
  if (!check_size_one(A)) {
    status = MATRIX_ERROR;
  }

  return status;
}
