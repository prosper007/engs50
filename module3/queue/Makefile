CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:		test_1

%.o:		%.c %.h
				gcc $(CFLAGS) -c $<


test_1:		test1.o queue.o
					gcc ${CFLAGS} test1.o queue.o -o $@

clean:
					rm -f *.o test_1

