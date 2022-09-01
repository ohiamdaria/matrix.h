Реализация библиотеки matrix.h.

## Матрица

Матрица - это набор чисел, расположенных в фиксированном количестве строк и столбцов.

Матрица A - прямоугольная таблица чисел, расположенных в m строках и n столбцах

```
    1 2 3
A = 4 5 6
    7 8 9
```

```
     1  2  3  4
В =  5  6  7  8
     9 10 11 12
```

Получить нужный элемент можно при помощи индексов, так
A[1,1] = 1, где первый индекс - номер строки, второй - номер столбца.

Матрица А будет иметь элементы с следующими индексами:

```
    (1,1) (1,2) (1,3)
A = (2,1) (2,2) (2,3)
    (3,1) (3,2) (3,3)
```

Порядок матрицы — это число ее строк или столбцов. \
Главная диагональ квадратной матрицы — это диагональ, идущая из левого верхнего в правый нижний угол. \
Прямоугольная матрица (В) — это матрица, у которой число строк не равно числу столбцов. \
Квадратная матрица (А) — это матрица у которой число строк равно числу столбцов.

Матрица-столбец — это матрица, у которой всего один столбец:

```
    (1,1)
A = (2,1)
    (n,1)
```

Матрица-строка — это матрица, у которой всего одна строка:

```
A = (1,1) (1,2) (1,m)
```
Tip: матрицу-столбец и матрицу-строку ещё часто называют векторами.

Диагональная матрица — это квадратная матрица, у которой все элементы, кроме, быть может, стоящих на главной диагонали, равны нулю. \
Единичная матрица — это диагональная матрица, у которой все диагональные элементы равны единице:

```

```


```

```

### Структура матрицы на языке C:

```c
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```

## Операции над матрицами

Все операции (кроме сравнения матриц) должны возвращать результирующий код:  
- 0 - OK
- 1 - Ошибка, некорректная матрица   
- 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя провести вычисления и т.д.)

### Создание матриц (create_matrix)

```c
int s21_create_matrix(int rows, int columns, matrix_t *result);
```

### Очистка матриц (remove_matrix)

```c
void s21_remove_matrix(matrix_t *A);
```

### Сравнение матриц (eq_matrix)

```c
#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B);
```

Две матрицы A, B совпадают |A = B|, если совпадают их размеры и соответствующие элементы равны, то есть при всех i, j A(i,j) = B(i,j).

Сравнение должно происходить вплоть до 7 знака после запятой включительно.

### Сложение (sum_matrix) и вычитание матриц (sub_matrix)

```c
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

Суммой двух матриц A = m × n и B = m × n одинаковых размеров называется матрица C = m × n = A + B тех же размеров, элементы которой определяются равенствами C(i,j) = A(i,j) + B(i,j).

Разностью двух матриц A = m × n и B = m × n одинаковых размеров называется матрица C = m × n = A - B тех же размеров, элементы которой определяются равенствами C(i,j) = A(i,j) - B(i,j).

```
```

### Умножение матрицы на число (mult_number). Умножение двух матриц (mult_matrix)

```c
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

Произведением матрицы A = m × n на число λ называется матрица B = m × n = λ × A, элементы которой определяются равенствами B = λ × A(i,j).

``` 
```

Произведением матрицы A = m × k на матрицу B = k × n называется матрица C = m × n = A × B размера m × n, элементы которой определяются равенством C(i,j) = A(i,1) × B(1,j) + A(i,2) × B(2,j) + … + A(i,k) × B(k,j).

```
```

```
		
```

### Транспонирование матрицы (transpose)

```c
int s21_transpose(matrix_t *A, matrix_t *result);
```

Транспонирование матрицы А заключается в замене строк этой матрицы ее столбцами с сохранением их номеров.

```

```

### Минор матрицы и матрица алгебраических дополнений (calc_complements)

```c
int s21_calc_complements(matrix_t *A, matrix_t *result);
```

Минором M(i,j) называется определитель (n-1)-го порядка, полученный вычёркиванием из матрицы A i-й строки и j-го столбца.

Алгебраическим дополнением элемента матрицы  является значение минора умноженное на -1^(i+j).

Матрица алгебраических дополнений будет иметь вид:


### Определитель матрицы (determinant)

```c
int s21_determinant(matrix_t *A, double *result);
```

Определитель (детерминант) - это число, которое ставят в соответствие каждой квадратной матрице и вычисляют из элементов по специальным формулам. \
Tip: определитель может быть вычислен только для квадратной матрицы.


### Обратная матрица (inverse_matrix)

```c
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
```

Матрицу A в степени -1 называют обратной к квадратной матрице А, если произведение этих матриц равняется единичной матрице.
