/*
        Jason Bingham
        Assignment 3 CS3100
*/

#include "Assign3e.h"

// estimates e
double calcE(int n){
	double e = 1.0;
	for(int i = 1; i <= n; ++i)
		e += (1.0 / factorial(i));

	return e;
}

// calculates the factorial of n
int factorial(int n){
	if(n == 1)
		return 1;
	else
		return n * factorial(n -1);
}

