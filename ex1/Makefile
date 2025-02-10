CFLAGS = -g -Wno-unused-parameter -Wall -O2
PROGRAMS = main main2
OBJS = biblioLC.o entreeSortieLC.o main.o
OBJS2 = biblioH.o main.o

.PHONY: all clean

all: $(PROGRAMS)

main: $(OBJS)
	gcc -o $@ $(CFLAGS) $^

biblioLC.o: biblioLC.c biblioLC.h
	gcc $(CFLAGS) -c biblioLC.c

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h biblioLC.h
	gcc $(CFLAGS) -c entreeSortieLC.c

main.o: main.c biblioLC.h entreeSortieLC.h 
	gcc $(CFLAGS) -c main.c

main2: $(OBJS)
	gcc -o $@ $(CFLAGS) $^

biblioH.o: biblioH.c biblioH.h
	gcc $(CFLAGS) -c biblioH.c

main2.o: main.c biblioH.h 
	gcc $(CFLAGS) -c main.c
    
clean:
	rm -f *.o *~ $(PROGRAMS)