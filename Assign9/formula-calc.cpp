#include <iostream>
#include <iomanip>
#include <cmath>

/*
 * 	Jason Bingham
 * 	CS3100
 * 	Assignment 9 - Dynamically linked library
 */

//calculates the factorial of n
int factorial(int n){
	if(n == 1)
		return 1;
	else
		return n * factorial(n -1);
}

//calculates e using n
extern "C" void ecalc(int n){
	double e = 1.0;
	for(int i = 1; i <= n; ++i)
		e += (1.0 / factorial(i));

	std::cout << "e equals" << ": " << e << std::endl;
}

//finds pi to n number of decimal places
extern "C" void picalc(int n){
	double pi = 0.0;

	pi += 4.0 * atan(1.0);

	std::cout << "Pi to " << n << " places: ";
	std::cout << std::setprecision(n + 1) << pi << std::endl;
}

//calculates the fibonacci number
extern "C" int fibcalc(int n){
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fibcalc(n - 1) + fibcalc(n - 2);
}
