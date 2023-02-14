CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GCOV = -fprofile-arcs -ftest-coverage
# TST_LIBS = -lcheck -pthread -lrt -lm -lsubunit -lgcov
TEST = -lcheck

all: s21_math.a test

s21_math.a: clean
# $(CC) $(CFLAGS) $(TST_LIBS) -std=c11 -c s21_*.c
	$(CC) $(CFLAGS) -c s21_*.c
	ar rc s21_math.a *.o
	mkdir binary_files
	mv *.o binary_files
	ranlib s21_math.a

gcov_report: s21_math.a
	$(CC) $(CFLAGS) $(GCOV) math_test.c $(TEST) s21_*.c -o gcovreport
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	open ./report/index.html

test: s21_math.a
# $(CC) $(CFLAGS) $(TEST) $(TST_LIBS) math_test.c s21_math.a -o math_test
	$(CC) $(CFLAGS) $(TEST) $(TST_LIBS) math_test.c s21_math.a -o math_test
	./math_test

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info binary_files test math_test report gcovreport