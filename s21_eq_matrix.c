#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int status = MAX(is_empty(A), is_empty(B));
    status = MAX(status, !check_size(A, B));
    if (!status) {
        status = SUCCESS;
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                if (!(fabs(A->matrix[i][j] - B->matrix[i][j]) <= 1e-7)) {
                    status = FAILURE;
                    break;
                }
    }
    return status;
}
