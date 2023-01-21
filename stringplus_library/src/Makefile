.PHONY: all cpplint gcov_report clean fclean rebuild
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CMD = xdg-open ./coverage_report.html
endif
ifeq ($(UNAME_S),Darwin)
    CMD = open ./coverage_report.html
endif
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -O0 -std=c11
LIBSRC = $(wildcard s21_*.c)
TESTSRC = $(wildcard suite*.c) test_s21_string.c
LIBOBJ = $(LIBSRC:.c=.o)
LIB = s21_string.a

all: test gcov_report s21_string.a

s21_string.a: $(LIBOBJ)
	ar rcs $(LIB) $(LIBOBJ)

s21_%.o: s21_%.c s21_string.h
	gcc $(CFLAGS) -c $<

# Нижеследующая цель просто добавляет зависимости (пререквизиты) для двух объектных файлов
s21_strerror.o s21_sprintf.o: %.o: %.h

test: test_$(LIB) $(TESTSRC:.c=.o)
	gcc $(CFLAGS) $(TESTSRC:.c=.o) $< -fsanitize=address -g -lcheck -lm -lpthread -lgcov -o $@
	./$@

test_$(LIB): $(addprefix test_, $(LIBOBJ))
	ar rcs test_$(LIB) $(addprefix test_, $(LIBOBJ))

test_%.o: %.c s21_string.h
	gcc $(CFLAGS) $(LDFLAGS) -c -g -fprofile-arcs -ftest-coverage $< -o $@

test_s21_strerror.o: s21_strerror.h
test_s21_sprintf.o: s21_sprintf.h

cpplint:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	rm ./CPPLINT.cfg

gcov_report: test
	gcovr -r . --html --html-details -o coverage_report.html
	$(CMD)
	rm -f *.gcda *.gcno

clean:
	rm -f coverage* test *.gcda *.gcno *.o

fclean: clean
	rm -f *.a

rebuild:
	make -B
