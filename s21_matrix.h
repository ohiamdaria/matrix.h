#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

typedef enum {
    OK,
    MATRIX_ERROR,
    ARITHM_ERROR,
    MALLOC_ERROR
} error;

#define SUCCESS 1
#define FAILURE 0
#define MAX(a, b) (((a) > (b))?(a):(b))

//  main functions
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

//  helpers
void print_matrix(matrix_t *result);
int check_size(matrix_t *A, matrix_t *B);
int is_agreed(matrix_t *A, matrix_t *B);
void submatrix(matrix_t *A, matrix_t *copy, int rows_copy, int columns_copy);
double counter_determinant(matrix_t *A, int n);
int check_norm_value(double result);
void minor(matrix_t *A, matrix_t *minor_matrix);
void scanf_matrix(matrix_t *result);
int check_size_one(matrix_t *A);
int is_empty(matrix_t *A);
int is_square(matrix_t *A);
int copy_matrix(matrix_t *A, matrix_t *B);
void submatrix(matrix_t *A, matrix_t *copy, int rows_copy, int columns_copy);
double counter_determinant(matrix_t *A, int n);
void minor(matrix_t *A, matrix_t *minor_matrix);
int is_agreed(matrix_t *A, matrix_t *B);
int simple_mul(matrix_t *A, matrix_t *B, double *result,
unsigned int current_row, unsigned int current_column);
int check_number(double number);


#endif  // SRC_S21_MATRIX_H_
