#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int status = OK;
    if (!(!rows || !columns)) {
        result->rows = rows;
        result->columns = columns;
        result->matrix = calloc(rows, sizeof(double *));
        if (result->matrix) {
            for (int i = 0; i < rows; i++) {
                result->matrix[i] = calloc(columns, sizeof(double));
                // if (!result->matrix[i]) {
                //     status = MALLOC_ERROR;
                //     for (int j = 0; j < i; j++)
                //         free(result->matrix[j]);
                //     free(result->matrix);
                //     break;
                // }
            }
        }
    } else {
        status = MATRIX_ERROR;
    }
    return status;
}
