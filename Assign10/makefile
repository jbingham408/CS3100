CC = g++
CFLAGS = -std=c++11 -O3

all: assign10

assign10: assign10main.o
	$(CC) $(CFLAGS) -o assign10 assign10main.o

assign10main.o: assign10main.cpp
	$(CC) $(CFLAGS) -c assign10main.cpp

clean:
	$(RM) *.o
	$(RM) assign10
