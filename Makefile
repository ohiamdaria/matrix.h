CC	=	gcc -g #-fsanitize=address
CFLAGS	=	-c	-Wall	-Werror	-Wextra	-std=c11	-pedantic #-fanalyzer
LIB_NAME	=	s21_matrix.a
TEST = -o test -lcheck
LFLAGS	=	-lcheck	-lm	-lpthread
RFLAGS	=	-fprofile-arcs	-ftest-coverage
HELP = all_helpers.c
ALLFILE = s21_create_matrix.c s21_remove_matrix.c s21_eq_matrix.c s21_sum_matrix.c s21_sub_matrix.c s21_mult_number.c s21_mult_matrix.c s21_transpose.c s21_calc_complements.c s21_determinant.c s21_inverse_matrix.c

all: s21_matrix.a test 

s21_matrix.a:
	$(CC)	$(CFLAGS) $(HELP)
	$(CC)	$(CFLAGS) $(ALLFILE)
	ar	rcs	$(LIB_NAME)	*.o
	ranlib	$(LIB_NAME)
	rm	-r	*.o

clean:
	rm	-rf	*.o	*.out	*.gcno	*.gcna	*.html	*.gcda	*.css	*.exe
	rm	-rf	*.a
	rm -rf tests/runtest
	rm -rf *.txt

rebuild:	clean	s21_matrix.a

test: 
	$(CC)	$(CFLAGS)	-c	tests/*.c
	$(CC) *.o	s21_matrix.a	$(LFLAGS)	-o	tests/runtest
	tests/runtest

gcov_report:
	gcovr	-r	.	--html	--html-details	-o	coverage_report.html
	rm	-rf	*.o	*.out	*.gcno	*.gcna	*gcda

check:
	cppcheck *.h functions/*.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.h functions/*.c
	rm -rf ./CPPLINT*

leaks:
		CK_FORK=no leaks --atExit -- tests/runtest


docker:
	sh ../materials/build/run.sh

valgrind:
		valgrind -q --leak-check=yes tests/runtest




