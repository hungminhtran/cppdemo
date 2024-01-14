all: format build debug

debug:
	gdb -ex=r ./hello.out
build:
	g++ -g -std=c++17 -D_GLIBCXX_DEBUG -Wall ./src/* -o hello.out
format:
	python3 clang-format-diff.py -i -p1

