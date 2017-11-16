CC = g++
CFLAGS = -std=c++11

assign9main: assign9Main.o formula-calc
	$(CC) $(CFLAGS) -o assign9main assign9Main.o -L`pwd` -Wl,-rpath,`pwd` -ldl

assign9Main.o: assign9Main.cpp
	g++ $(CFLAGS) -c assign9Main.cpp

formula-calc: formula-calc.cpp
	$(CC) -fPIC -g -c -Wall formula-calc.cpp
	$(CC) -shared -Wl,-soname,formula-calc.so -o formula-calc.so formula-calc.o -lc

clean:
	$(RM) *.o
	$(RM) formula-calc.so*
	$(RM) assign9main
