all: format build debug

debug:
	gdb -ex=r ./hello.out
build:
	g++ -g -c ./src/hello_b.cpp
	g++ -g -std=c++17 -Wall ./src/* -o hello.out
format:
	python3 clang-format-diff.py -i -p1

