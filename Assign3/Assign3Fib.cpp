/*
        Jason Bingham
        Assignment 3 CS3100
*/

#include "Assign3Fib.h"

// calculates the fibonacci number for n
int fibonacci(int n){
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}
