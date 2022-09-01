#include "s21_matrix.h"

void print_matrix(matrix_t *result) {
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
            printf("%.10f ", result->matrix[i][j]);
        }
        printf("\n");
    }
}

int check_size(matrix_t *A, matrix_t *B) {
    int status = SUCCESS;
    if (A->columns != B->columns || A->rows != B->rows)
        status = FAILURE;
    return status;
}

int check_norm_value(double result) {
    int status = SUCCESS;
    if (result == INFINITY || result == -INFINITY || result == NAN)
        status = FAILURE;
    return status;
}

void scanf_matrix(matrix_t *result) {
    for (int i = 0; i < result->rows; i++)
        for (int j = 0; j < result->columns; j++)
            scanf("%lf\n", &result->matrix[i][j]);
}

int check_size_one(matrix_t *A) {
    int status = SUCCESS;
    if (A->columns == 0 || A->rows == 0)
        status = FAILURE;
    return status;
}

int is_empty(matrix_t *A) {
    int status = OK;
    if (!A->columns || !A->rows || A->columns <= 0 || A->rows <= 0)
        status = MATRIX_ERROR;
    return status;
}

int is_square(matrix_t *A) {
    int status = OK;
    if (A->columns != A->rows)
        status = ARITHM_ERROR;
    return status;
}

int copy_matrix(matrix_t *A, matrix_t *B) {
    int status = check_size(A, B);
    if (status) {
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                B->matrix[i][j] = A->matrix[i][j];
    } else
        status = FAILURE;
    return status;
}

void submatrix(matrix_t *A, matrix_t *copy, int rows_copy, int columns_copy) {
    s21_create_matrix(A->rows - 1, A->columns - 1, copy);
    int subi = 0;
    for (int i = 0; i < A->rows; i++) {
        int subj = 0;
        if (i == rows_copy) {
            continue;
        }
        for (int j = 0; j < A->columns; j++) {
            if (j == columns_copy) {
                continue;
            }
            copy->matrix[subi][subj] = A->matrix[i][j];
            if (subj < j - 1) subj++;
        }
        if (subi < i - 1) subi++;
    }
}

double counter_determinant(matrix_t *A, int n) {
    double result = 0.0;
    if (A->rows == 1)
        return A->matrix[0][0];
    else if (A->rows == 2) {
        return result = (A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1]);
    } else {
        for (int x = 0; x < A->columns; x++) {
            matrix_t copy = {0};
            submatrix(A, &copy, 0, x);
            result += ((x % 2 == 0 ? 1 : -1) * A->matrix[0][x] * counter_determinant(&copy, n - 1));
            s21_remove_matrix(&copy);
        }
    }
    return result;
}

void minor(matrix_t *A, matrix_t *minor_matrix) {
    s21_create_matrix(A->rows, A->rows, minor_matrix);
    for (int i = 0; i < A->rows; ++i)
        for (int j = 0; j < A->columns; ++j) {
        matrix_t copy = {0};
        submatrix(A, &copy, i, j);
        minor_matrix->matrix[i][j] = ((((i + j)) % 2 == 0 ? 1 : -1) * counter_determinant(&copy, copy.rows));
        s21_remove_matrix(&copy);
        }
}

int is_agreed(matrix_t *A, matrix_t *B) {
    int status = SUCCESS;
    if (A->columns != B->rows) status = FAILURE;
    return status;
}

int simple_mul(matrix_t *A, matrix_t *B, double *result, unsigned int current_row, unsigned int current_column) {
    int status = OK;
    *result = 0.0;
    for (int j = 0; j < A->columns; j++) {
        *result = A->matrix[current_row][j] * B->matrix[j][current_column] + *result;
        if (*result == INFINITY || *result == -INFINITY || *result == NAN) {
                status = ARITHM_ERROR;
                break;
        }
    }
    return status;
}

int check_number(double number) {
    int status = SUCCESS;
    if (number == INFINITY || number == -INFINITY || number == NAN)
            status = FAILURE;
    return status;
}
