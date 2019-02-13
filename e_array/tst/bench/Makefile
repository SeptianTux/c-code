build:
		gcc -g bench-data.c ../../e_arr.c with_e_arr.c -o with_e_arr
		gcc -g bench-data.c native.c -o native
		g++ bench-data.c vector.cpp -o vector

clean:
		rm with_e_arr
		rm native
		rm vector
