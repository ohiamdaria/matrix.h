#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  init_matrix(result);
  if (!rows || !columns) status = MATRIX_ERROR;
  if (!status) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(result->rows, sizeof(double *));
    if (result->matrix) {
      for (int i = 0, stop = 0; i < rows && !stop; i++) {
        result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          for (int j = i - 1; j >= 0; j--) {
            free(result->matrix[j]);
          }
          free(result->matrix);
          stop = 1;
	status = MALLOC_ERROR;
      }
    }
    } else {
      status = MALLOC_ERROR;
    }
  }

  return status;
}
