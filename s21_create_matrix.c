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
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
      if (!result->matrix[i]) {
      	while(i >= 0) {
	  free(result->matrix[i]);
	  i--;	  
        }
	status = MALLOC_ERROR;
	break;
      }
    }
    } else {
      status = MALLOC_ERROR;
    }
  }

  return status;
}
