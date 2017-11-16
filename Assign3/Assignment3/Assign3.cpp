/*
	Jason Bingham
	Assignment 3 CS3100
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Assign3Fib.h"
#include "Assign3e.h"
#include "Assign3pi.h"

int main(int argc, char** argv){

	// stores what operation to perform
	std::string operation;
	// stores the value to use in the operation
	int value;
	// stores if the input was good or bad
	bool badInput = false;

	// checks if enough arguements were entered
	if(argc == 3){
		// gets the operation and the value
		for(int i = 1; i < argc; ++i){
			std::string temp = argv[i];
			if(i == 1)
				operation = temp;
			else
				value = std::stoi(temp);
		}

		// checks which function to perform
		// if any input doesn't fit then the input is bad
		// if input is good then the result is printed out
		// for the fibonacci sequence
		if(operation == "-fib"){
			if(value >= 0 && value <= 14){
				int total = fibonacci(value);
				std::cout << "The fibonacci number for " << value << ": " << total << std::endl;
			}
			else
				badInput = true;
		}
		// for the e calculation
		else if(operation == "-e"){
			if(value >= 1 && value <= 30){
				double e = calcE(value);
				std::cout << "The e value of " << value << ": " << e << std::endl;
			}
			else
				badInput = true;
		}
		// for the pi calculation
		else if(operation == "-pi"){
			if(value >= 1 && value <= 10){
				double pi = calcPi();
				std::cout << "Pi to " << value << " places: ";
				std::cout << std::setprecision(value + 1) << pi << std::endl;
			}
			else
				badInput = true;
		}
		else
			badInput = true;
	}
	else
		badInput = true;

	// If input was determined to be bad
	if(badInput){
		std::cout << "\n------------------Hint--------------------\n";
		std::cout << "-fib n, compute the fibonacci of n, n is between 0 and 14\n";
		std::cout << "-e n, compute the value of e using n iterations, n is between 1 and 30\n";
		std::cout << "-pi n, computer Pi to n digits, n is between 1 and 10\n";
		std::cout << "------------------------------------------\n\n\n";
	}

	return 0;
}




