CFLAGS = -g -Wno-unused-parameter -Wall -O2
PROGRAMS = main main2 main3
OBJS = biblioLC.o entreeSortieLC.o main.o
OBJS2 = biblioH.o entreeSortieH.o main2.o

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

main2: $(OBJS2)
	gcc -o $@ $(CFLAGS) $^

biblioH.o: biblioH.c biblioH.h
	gcc $(CFLAGS) -c biblioH.c

entreeSortieH.o: entreeSortieH.c entreeSortieH.h biblioH.h
	gcc $(CFLAGS) -c entreeSortieH.c

main2.o: main2.c biblioH.h entreeSortieH.h 
	gcc $(CFLAGS) -c main2.c


main3: biblioLC.o entreeSortieLC.o biblioH.o entreeSortieH.o main3.o
	gcc -o $@ $(CFLAGS) $^


main3.o: main3.c biblioH.h entreeSortieH.h biblioLC.h entreeSortieLC.h 
	gcc $(CFLAGS) -c main3.c
    
clean:
	rm -f *.o *~ $(PROGRAMS)