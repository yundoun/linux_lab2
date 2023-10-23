ofile: 
	gcc -c -fPIC math.c

sofile:
	gcc -shared -o libmath.so math.o

exefile:
	:gcc -o dynamic_math_example main.c -L. -lmath
