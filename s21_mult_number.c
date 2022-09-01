#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int status = MAX(is_empty(A), !check_number(number));
    if (!status) {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] * number;
                // if (!check_number(result->matrix[i][j])) {
                //     status = MATRIX_ERROR;
                //     break;
                // }
            }
    }
    return status;
}
