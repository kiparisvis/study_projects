CC=gcc

SRC=s21_abs.c s21_acos.c s21_asin.c s21_atan.c\
	s21_ceil.c s21_cos.c s21_exp.c s21_fabs.c\
	s21_floor.c s21_fmod.c s21_log.c s21_pow.c\
	s21_sin.c s21_sqrt.c s21_tan.c

OBJ=$(SRC:.c=.o)
TEST_DIR=./tests
TESTS=$(addprefix $(TEST_DIR)/,test_s21_abs.c test_s21_acos_asin_atan.c test_s21_ceil_fmod_log.c\
	test_s21_cos_cin_tan.c test_s21_exp.c test_s21_fabs_floor_sqrt.c test_s21_pow.c)

RM=rm -rf

FLAGS_ER=-Wall -Wextra -Werror
FLAG_STD=-std=c11
FLAG_COV=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS=-lcheck -lm -lpthread

LIB = s21_math.a

all: clean $(LIB) test gcov_report

$(LIB): $(SRC) s21_math.h
	$(CC) $(FLAGS_ER) -c -g $(SRC)
	ar rcs $(LIB) $(OBJ)
	ranlib $(LIB)

test: $(LIB) $(TEST_DIR)/s21_math_tests.h
	$(CC) -c $(FLAG_ER) $(TESTS) main.c
	ar rc test_suite.a $(OBJ) test_s21*.o
	ranlib test_suite.a
	$(CC) $(FLAG_ER) $(FLAG_COV) -o test_check $(LIB) test_suite.a main.o -lcheck
	./test_check

gcov_report: $(TESTS)
	$(CC) -o test_check $(SRC) main.c $(TESTS) $(FLAG_COV) $(CHECK_FLAGS)
	./test_check
	../materials/lcov/bin/lcov -t "gcov_report" -o test.info -c -d .
	../materials/lcov/bin/genhtml -o gcov_report test.info
	rm -rf *.gcno *.gcda *.gcov *.info *.o test

check:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.c
	clang-format -i *.h
	clang-format -i tests/*.c
	rm .clang-format

valg: test
	../materials/valg/bin/valgrind ./test_check

clean:
	$(RM) *.o *.out *.gc* *.a *.info *.css *.html
	$(RM) test_check
	$(RM) test_check.dSYM
	$(RM) gcov_report
	$(RM) report

rebuild: clean all

.PHONY: clean all test gcov_report valg check