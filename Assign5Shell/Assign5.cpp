/*
 * Jason Bingham
 * CS3100
 * Shell Program
 */


#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <cstring>
#include <chrono>

// function the prints out the time that was spent in the child process
void printTime(std::chrono::duration<double> totalTime);
// function that the child process runs
void childProcess(char** aArgv, std::vector <char*> vArgvHist, std::chrono::duration<double> totalTime);


int main()
{
	int argc = 0; // stores the number of arguments that are given
	std::vector <char*> vArgv; // stores a vector of the arguments given
	std::vector <char*> vArgvHist; // stores the entire list of all the commands given
	std::chrono::time_point<std::chrono::system_clock> start, end; // stores a start and end time
	std::chrono::duration<double> totalTime; // stores the time spent in the child process
	std::string sCommand; // string to get the commands
	char* args; // stores the arguments

	chdir(getcwd(NULL, 8)); // makes sure the shell is in the current directory

	// loops until the user exits the program
	while(true){
		std::cin.clear(); // makes the input is clear
		std::cout << "[cmd]: "; // displays the prompt
		getline(std::cin, sCommand); // gets the commands from the user
		sCommand.push_back('.'); // defines a character that indicates the end of the line
		//std::cout << sCommand << std::endl;
		char* cCommand = new char[sCommand.size()]; // creates a character array
		//transfers the content in sCommand to cCommand
		for(int i = 0; i < sCommand.size(); ++i){
			cCommand[i] = sCommand[i];
		}
		// parses cCommand to get the individual arguments
		args = strtok(cCommand, " .");

		// loops till all arguments are taken care of
		while(args != NULL){
			// checks if the user wants to exit
			if(strcmp(args, "exit") == 0){
				delete[] cCommand;
				return 0;
			}
			// checks if the user wants to see the amount of time spent in the child
			else if(strcmp(args, "ptime") == 0){
				printTime(totalTime);
				args = strtok(NULL, " .");
			}
			// pushes the argument into a vector and erases that argument to move onto the next argument
			else{
				vArgv.push_back(args);
				args = strtok(NULL, " .");
				argc++; // increments how many agruments there are
			}
		}

		// takes the argument vector and stores it in another vector to keep track of all arguments given
		vArgvHist.insert(vArgvHist.end(), vArgv.begin(), vArgv.end());
		// creates an array of character pointers
		char** aArgv = new char*[argc];

		// transfers the contents of the a vector into the new array
		for(int i = 0; i < argc; ++i){
			aArgv[i] = vArgv[i];
			//std::cout << aArgv[i] << std::endl;
		}

		// checks if there were arguments passed in.
		if(argc > 0){
			// creates the child process
			pid_t pid = fork();

			if(pid == -1){ // fails to fork
				std::cout << "fork failed\n";
			}
			else if(pid == 0){ //child process
				//std::cout << "in child\n\n";
				childProcess(aArgv, vArgvHist, totalTime);

				return 0;
			}
			else{ // parent process
				//std::cout << "in parent\n\n";
				//gets the start time
				start = std::chrono::system_clock::now();
				wait(NULL);
				//gets the end time
				end = std::chrono::system_clock::now();
				// stores the time taken
				totalTime = end - start;
			}
		}

		// resets all the input storage
		vArgv.clear();
		argc = 0;
		delete[] aArgv;
	}
}

void printTime(std::chrono::duration<double> totalTime)
{
	//std::cout << totalTime.count() << std::endl;
	std::cout << "Time spent in child: ";
	int seconds = (int) totalTime.count(); // stores the time in seconds without decimals
	int milliseconds = (int) std::chrono::duration_cast<std::chrono::milliseconds>(totalTime).count(); // stores the milliseconds
	int microseconds = (int) (std::chrono::duration_cast<std::chrono::microseconds>(totalTime).count() - (milliseconds * 1000)); // stores the microseconds
	std::cout << seconds << " seconds " << milliseconds << " milliseconds " << microseconds << " microseconds\n"; // prints the results
}

void childProcess(char** aArgv, std::vector <char*> vArgvHist, std::chrono::duration<double> totalTime)
{
	//checks if the user wants the history
	if(strcmp(aArgv[0], "history") == 0){ // prints entire history
		std::cout << "History:\n";
		for(int i = 0; i < vArgvHist.size() - 1; ++i){
			std::cout << vArgvHist[i] << std::endl;
		}
	}
	// prints the history at a certain spot
	else if(strcmp(aArgv[0], "^") == 0){
		int num = atoi(aArgv[1]);
		if(num > 0 && num <= vArgvHist.size()){
			std::cout << vArgvHist[num - 1] << std::endl;
		}
	}
	// executes the commands
	else if(execvp(aArgv[0], aArgv) < 0){
		std::cout << "exec failed: Bad command\n\n";
	}
}
