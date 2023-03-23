CC = gcc
CFLAG = -Wall -Wextra -Werror -std=c11
CHECKFLAGS = -lcheck -coverage -pthread
APP = build/s21_3dviewer.app

all: build open

clean:
	rm -rf *.o *.a *.css *.out coverage_report.html *.gcno *.gcda *.gcov build ~/Desktop/3d_viewer_v1.0 3d_viewer_v1.0/3dviewer_private.pro.user Archive_3d_viewer_v1.0 test 


build:
	mkdir build
	cd ./build/ && qmake ../3d_viewer_v1.0 && make && mv 3dviewer_private.app s21_3dviewer.app

install: build
	@mkdir ~/Desktop/3d_viewer_v1.0/
	@cp -rf $(APP) ~/Desktop/3d_viewer_v1.0/
	

uninstall:
	@rm -rf build
	@rm -rf ~/Desktop/3d_viewer_v1.0/

open:
	./build/s21_3dviewer.app/Contents/MacOS/3dviewer_private

dist:
	cd ../ && tar -cf ~/Desktop/Archive_3d_viewer_v1.0.tar src
 
dvi:
	open dvi.html

test: clean
	$(CC) $(CFLAG) $(CHECKFLAGS) 3d_viewer_v1.0/parser/parser.c tests/test.c -o test.o
	./test.o

gcov_report: test
	$(CC) $(CFLAG) -c -fprofile-arcs -ftest-coverage tests/test.c 3d_viewer_v1.0/parser/parser.c
	$(CC) $(CFLAG) -fprofile-arcs *.o -o tests.o -lcheck -lm -pthread
	./tests.o
	# rm -rf *.gcda *.gcno
	gcovr -r . --html --html-details -s -o coverage_report.html
	# rm *.o
	open coverage_report.html
	
lint:
	clang-format -i 3d_viewer_v1.0/parser/*.c 3d_viewer_v1.0/parser/*.h 3d_viewer_v1.0/*.cpp 3d_viewer_v1.0/*.hpp tests/test.c

valgrind: test
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all -v ./test.o
