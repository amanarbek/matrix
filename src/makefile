CPP =  g++ --std=c++17 -g -Wall -Werror -Wextra
SRC = s21_matrix_oop.cc
GCOV = --coverage
OS = $(shell uname)

ifeq ($(OS), Darwin)
	LIBFLAGS = -lm -lgtest
else
	LIBFLAGS = -lgtest -pthread
endif

all: clean test

clean:
	rm -rf *.o *.a *.so *.cfg *.out *.dSYM test *.txt report *.info *.gcda *.gcno *.gch .clang-format

test: s21_matrix_oop.a 
	@$(CPP) tests.cc s21_matrix_oop.a $(LIBFLAGS)  -o test
	@./test

s21_matrix_oop.a:
	$(CPP) -c $(SRC)
	ar rcs s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a

gcov_report: s21_matrix_oop.a
	$(CPP) $(GCOV) tests.cc $(SRC) s21_matrix_oop.a -L. s21_matrix_oop.a $(LIBFLAGS) -o test
	./test
	lcov -t "test" -c -d  ./ --no-external --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./report/
	open ./report/index.html

check: test
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(SRC) *.h
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n $(SRC) tests.cc s21_matrix_oop.h
	rm -rf .clang-format
ifeq ($(OS), Darwin)
	leaks --atExit -- ./test
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test
endif
