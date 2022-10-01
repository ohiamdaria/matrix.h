CC	=	gcc
CFLAGS	= -Wall -Werror -Wextra -std=c11 -pedantic
LIB_NAME = s21_matrix.a
PLIB_NAME = s21_matrix_peer.a
LFLAGS = -lcheck -lm -lpthread
RFLAGS = -fprofile-arcs	-ftest-coverage
HELP = s21_all_helpers.c
TST=tests/
TFILE=runtest

INC:=$(shell find . -maxdepth 1 -name "*.h")
SRC:=$(shell find . -maxdepth 1 -name "s21*.c")
OBJS:=$(SRC:%.c=%.o)

all: $(LIB_NAME)

TEST=ON

$(OBJS): %.o:%.c $(SRC) $(INC)
	$(CC) $(CFLAGS) $(RFLAGS) -o $@ -c $< -g

$(LIB_NAME): 	$(OBJS)
	ar	-vrcs	$(LIB_NAME)	$(OBJS)
	ranlib	$(LIB_NAME)

test: $(LIB_NAME)
	$(CC)	$(CFLAGS)	-c	$(TST)*.c
	$(CC)   $(RFLAGS) *.o	$(LIB_NAME)	$(LFLAGS)	-o	$(TST)$(TFILE)
	$(TST)$(TFILE)

gcov_report: clean test
	gcovr	-r	.	--html	--html-details	-o	coverage_report.html
	rm	-rf	*.o	*.out	*.gcno	*.gcna	*gcda
	open	./coverage_report.html

clean:
	rm	-rf	*.o	*.out *.gcno *.gcna	*.html *.gcda *.css	*.exe
	rm	-rf	*.a $(TST)$(TFILE) *.txt

rebuild:	clean	$(LIB_NAME)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.h *.c
	rm -rf ./CPPLINT*

docker: clean
	sh ../materials/build/run.sh

valgrind: compile_test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose tests/runtest)
