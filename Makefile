all: clean format build debug
run:
	g++ -std=c++17 -Wall ./src/* -o hello.out
	./hello.out
debug:
	gdb -ex=r ./hello.out
build:
	g++ -g -std=c++17 -D_GLIBCXX_DEBUG -Wall ./src/* -o hello.out
clean:
	rm -rf ./hello.out
format:
	python3 clang-format-diff.py -i -p1

