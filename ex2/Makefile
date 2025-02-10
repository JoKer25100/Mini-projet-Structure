CFLAGS = -g -Wno-unused-parameter -Wall -O2
PROGRAMS = main
OBJS = biblioH.o main.o

.PHONY: all clean

all: $(PROGRAMS)

main: $(OBJS)
	gcc -o $@ $(CFLAGS) $^

biblioH.o: biblioH.c biblioH.h
	gcc $(CFLAGS) -c biblioH.c

main.o: main.c biblioH.h 
	gcc $(CFLAGS) -c main.c
    
clean:
	rm -f *.o *~ $(PROGRAMS)