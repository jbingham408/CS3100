#include <iostream>
#include <string>
#include <dlfcn.h>

/*
 * 	Jason Bingham
 * 	CS3100
 * 	Assignment 9 - Dynamically linked library
 */

int main(){

	//stores the full command given by the user
	std::string fullCommand;
	//stores the function the user wants to run
	std::string command;
	//stores the value to go with the command
	int value = -2;

	//opens the library
	void* handle = dlopen("./formula-calc.so", RTLD_LAZY);
	if(!handle)
	{
		std::cout << "Library could not be opened: " << dlerror() << std::endl;
		return 1;
	}

	//adds the three functions from the library
	void (*ecalc)(int) = (void(*)(int))dlsym(handle, "ecalc");
	if (dlerror() != NULL)
	{
		std::cout << "Couldn't find 'ecalc', error: " << dlerror() << std::endl;
		return 1;
	}
	void (*picalc)(int) = (void(*)(int))dlsym(handle, "picalc");
	if (dlerror() != NULL)
	{
		std::cout << "Couldn't find 'picalc', error: " << dlerror() << std::endl;
		return 1;
	}
	int (*fibcalc)(int) = (int(*)(int))dlsym(handle, "fibcalc");
	if (dlerror() != NULL)
	{
		std::cout << "Couldn't find 'fibcalc', error: " << dlerror() << std::endl;
		return 1;
	}

	//loops until the user enters quit
	while(true){
		//makes sure that cin is clean
		std::cin.clear();
		//initializes value
		value = -2;
		//prompts input from the user
		std::cout << "[cmd:] ";
		getline(std::cin, fullCommand);
		std::cout << std::endl;
		//checks if there is whitespace in the command given by the user
		int spot = fullCommand.find(' ');
		//if there is whitspace, fullCommand is split to get the command and the value that goes with it.
		if(spot > 0){
			command = fullCommand.substr(0, spot);
			//tries to convert the string containing the number into an int
			try{
				value = std::stoi(fullCommand.substr(spot + 1));
			}
			catch(...){
				std::cout << "Exception Caught: " << fullCommand.substr(spot + 1) << " is not a valid argument\n";
			}
		}
		else
			command = fullCommand;

		//checks what command was entered
		if(command == "quit")
			//exit program
			return 0;
		else if(command == "fib" && (value > -1 && value < 15)){
			//calculates the fibonacci number
			int total = fibcalc(value);
			std::cout << "The fibonacci number is: " << total << std::endl;
		}
		else if(command == "e" && (value > 0 && value < 31))
			//calculates e
			ecalc(value);
		else if(command == "pi" && (value > 0 && value < 11))
			//finds pi to some number of decimal places
			picalc(value);
		else
			std::cout << "Bad Command: " << fullCommand << " is not a recognized command\n";

		std::cout << std::endl;
	}

	return 0;
}
