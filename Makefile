debug:
	build
	gdb -ex=r ./hello.out
build:
	format
	g++ -g -std=c++17 -Wall ./scr/hello.cpp -o hello.out
format:
    git diff -U0 HEAD^ | clang-format-diff.py -i -p1