.PHONY: all clean
all: exe lib

exe: main.c heap.h lib
	gcc -std=c99 main.c -fPIC -L. -l-heap -o heap

lib: heap.c heap.h
	gcc -std=c99 -shared heap.c -fPIC -o lib-heap.so

clean: 
	rm -rf heap  lib-heap.so 2>/dev/null
