app.out : main.o math.o
	gcc -o app.out main.o math.o 

main.o : math.h main.c
	gcc -c -o main.o main.c

math.o : math.h math.c
	gcc -c -o math.o math.c

