.PHONY: test

test:
		gcc -Wall -ggdb src/test.c src/e_arr.c -o test.bin

test-debug:
		gdb ./test.bin

clean:
		rm ./test.bin
