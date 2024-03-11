FLAGS = -Wall -Werror -Wextra -std=c11 -g

GCOV_FLAGS=-fprofile-arcs -ftest-coverage

all: s21_decimal.a

OS = $(shell uname)

ifeq ($(OS), Darwin)
	CHECK = -lcheck
endif

ifeq ($(OS), Linux)
	CHECK = -lcheck -lsubunit -lm -lrt -lpthread
endif

test: s21_decimal.a
	$(CC) $(CFLAGS) test/*.c -L. s21_decimal.a $(CHECK) -o testing

	make run_tests

s21_decimal.a:
	$(CC) $(CFLAGS) -c *.c  *on/*.c

	ar rc s21_decimal.a *.o
	rm -rf *.o

gcov_report: s21_decimal.a
	$(CC) $(CFLAGS) $(GCOV_FLAGS) *.c  */*.c s21_decimal.a -o testing $(CHECK)
	make run_tests
	lcov -t "stest" -o s21_test.info --ignore-errors mismatch --no-external -c -d .
	genhtml -o report testing.info


format:
	clang-format -style=google -i *.c */*.c *.h */*.h

style:
	clang-format -style=google -n *.c */*.c *.h */*.h
	
clean:
	rm -rf *.o *.a s21_decimal *.info  *.gcda *.gcno testing report

run_tests:
	./testing




