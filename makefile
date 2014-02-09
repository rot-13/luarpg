all:
	clang++ *.cpp **/*.cpp -std=c++11 -I/usr/include/i386-linux-gnu/c++/4.8 -lreadline -lm -ldl -llua5.1 -o luarpg
