#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  if (!rows || !columns) status = MATRIX_ERROR;
  if (!status) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++)
      result->matrix[i] = calloc(columns, sizeof(double));
  }
  return status;
}
