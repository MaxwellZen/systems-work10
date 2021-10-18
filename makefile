all: main.o manga.o
	gcc -o main main.o manga.o

main.o: main.c manga.h
	gcc -c main.c

manga.o: manga.c manga.h
	gcc -c manga.c

run:
	./main

clean:
	rm *.o
