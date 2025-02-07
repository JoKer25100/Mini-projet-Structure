CFLAGS = -g -Wno-unused-parameter -Wall -O2
PROGRAMS = main test
OBJS = biblioLC.o entreeSortieLC.o main.o

.PHONY: all clean

all: $(PROGRAMS)

main: $(OBJS)
	gcc -o $@ $(CFLAGS) $^

test: biblioLC.o entreeSortieLC.o test.o
	gcc -o $@ $(CFLAGS) $^

biblioLC.o: biblioLC.c biblioLC.h
	gcc $(CFLAGS) -c biblioLC.c

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h biblioLC.h
	gcc $(CFLAGS) -c entreeSortieLC.c

main.o: main.c biblioLC.h entreeSortieLC.h 
	gcc $(CFLAGS) -c main.c

test.o: test.c biblioLC.h entreeSortieLC.h
	gcc $(CFLAGS) -c test.c
	
clean:
	rm -f *.o *~ $(PROGRAMS)