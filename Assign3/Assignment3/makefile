CC = g++
CFLAGS = -std=c++11

all: Assign3

Assign3: Assign3.o Assign3Fib.o Assign3e.o Assign3pi.o
	$(CC) $(CFLAGS) -o Assign3 Assign3.o Assign3Fib.o Assign3e.o Assign3pi.o

Assign3.o: Assign3.cpp
	$(CC) $(CFLAGS) -c Assign3.cpp

Assign3Fib.o: Assign3Fib.cpp Assign3Fib.h
	$(CC) $(CFLAGS) -c Assign3Fib.cpp Assign3Fib.h

Assign3e.o: Assign3e.cpp Assign3e.h
	$(CC) $(CFLAGS) -c Assign3e.cpp Assign3e.h

Assign3pi.o: Assign3pi.cpp Assign3pi.h
	$(CC) $(CFLAGS) -c Assign3pi.cpp Assign3pi.h

clean:
	$(RM) Assign3 *.o *~
