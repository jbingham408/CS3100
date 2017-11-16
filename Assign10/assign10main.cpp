/*	Jason Bingham
 * 	CS3100
 * 	HW10
 * 	Belady's Anomaly Simulator
 */

#include <iostream>
#include <ctime>
#include <stdlib.h>

void resetFrames(int[], int);
void generateSequence(int[], int, int);

int main() {
	//stores the maximum size for the reference string
	const int PAGE_SIZE = 1000;
	//stores the maximum number of frames
	const int MAX_FRAMES = 100;
	// stores the number of sequences to test
	const int NUM_OF_SEQ = 100;
	//stores the maximum number for pages
	const int NUM_OF_PAGES = 250;
	//initialize the random seed
	srand(time(NULL));

	//stores the number of pages given by the user
	int numOfPages = 0;
	//stores the number of frames given by the user
	int numOfFrames = 0;
	//stores the size of the reference string given by the user
	int refString = 0;
	//stores a position in the frame array
	int numF = 0;
	//stores the number of page faults
	int pageFaults = 0;
	//stores where the next number should be inserted
	int insertSpot = 0;
	//stores the number of anomalies that occur
	int anomalyAmount = 0;

	//array for storing the frames
	int frames[MAX_FRAMES];
	//array for storing the reference string
	int pages[PAGE_SIZE];
	//2d array that stores the page faults results for the number of frames and the sequence
	int faultsResult[MAX_FRAMES][NUM_OF_SEQ];

	//gets input for the number of pages to use
	while (numOfPages < 1 || numOfPages > NUM_OF_PAGES) {
		std::cout << "Enter number of Pages: ";
		//checks if the input is a number
		if (std::cin >> numOfPages) {
			if (numOfPages < 1 || numOfPages > NUM_OF_PAGES) {
				std::cout << "ERROR: Bad input, must be between 1 and "
						<< NUM_OF_PAGES << std::endl;
			}
		}
		else {
			std::cout << "ERROR: Bad Input, must be an integer\n";
			std::cin.clear();
			std::cin.ignore();
			numOfPages = 0;
		}
	}
	//gets input for how long the reference string will be
	while (refString < 1 || refString > PAGE_SIZE) {
		std::cout << "Enter length of reference string: ";
		//checks if the input is an integer
		if (std::cin >> refString) {
			if (refString < 1 || refString > PAGE_SIZE) {
				std::cout << "ERROR: Bad input, must be between 1 and "
						<< PAGE_SIZE << std::endl;
			}
		}
		else {
			std::cout << "ERROR: Bad Input, must be an integer\n";
			std::cin.clear();
			std::cin.ignore();
			refString = 0;
		}
	}
	//gets input for the max number of frames to use
	while (numOfFrames < 1 || numOfFrames > MAX_FRAMES) {
		std::cout << "Enter number of memory frames: ";
		//checks if the input is an integer
		if (std::cin >> numOfFrames) {
			if (numOfFrames < 1 || numOfFrames > MAX_FRAMES) {
				std::cout << "ERROR: Bad input, must be between 1 and "
						<< MAX_FRAMES << std::endl;
			}
		}
		else {
			std::cout << "ERROR: Bad Input, must be an integer\n";
			std::cin.clear();
			std::cin.ignore();
			numOfFrames = 0;
		}
	}

	//stores if the page has been put in the frames array
	bool inserted = false;

	std::cout << "\n\n\nBelady's Anomly Simulator\n\n";
	std::cout << "Number of sequences: " << NUM_OF_SEQ << std::endl;
	std::cout << "Length of reference string: " << refString << std::endl;
	std::cout << "Frames of physical memory: " << numOfFrames << std::endl
			<< std::endl << std::endl;

	//outer most loop. This loop is for the number of sequences
	for (int seq = 0; seq < NUM_OF_SEQ; ++seq) {
		//generates the reference string
		generateSequence(pages, refString, numOfPages);

		//loops for the maximum number of frames that are being used
		for (int maxFrames = 0; maxFrames < numOfFrames; ++maxFrames) {
			//sets the frames array to be empty
			resetFrames(frames, numOfFrames);
			//resets the page faults to 0
			pageFaults = 0;
			//resets the next insert spot to 0
			insertSpot = 0;

			//loop for looping through the pages array
			for (int pageNum = 0; pageNum < refString; ++pageNum) {
				//sets numF to 0 to make sure it starts looking at the frames array at the beginning
				numF = 0;
				//resets inserted to false
				inserted = false;

				//loops through the frames array
				while (!inserted && numF < maxFrames) {
					//checks if the current spot in the frames array is empty
					if (frames[numF] == -1) {
						//inserts the page and increases the page faults
						frames[numF] = pages[pageNum];
						inserted = true;
						++pageFaults;
					}
					//checks if the current spot in the frame contains the same page number
					else if (frames[numF] == pages[pageNum]) {
						inserted = true;
					}
					//goes to the next frame
					++numF;
				}
				//if the page was not inserted it replaces the page at insertSpot with the current page number, then increases the page faults
				if (!inserted) {
					++pageFaults;
					if (insertSpot >= numOfFrames) {
						insertSpot = 0;
					}
					frames[insertSpot] = pages[pageNum];
					++insertSpot;
				}
			}

			//inserts the final page faults count into the faults result array
			faultsResult[maxFrames][seq] = pageFaults;

			//makes sure that its not the first frame
			if (maxFrames > 0) {
				//checks if the previous total page faults is less than the current total of page faults
				if (faultsResult[maxFrames][seq] > faultsResult[maxFrames - 1][seq]) {
					//increase the total of anomalies detected
					++anomalyAmount;
					std::cout << "Anomaly Discovered\n";
					std::cout << "Sequence: " << seq << std::endl;
					std::cout << "Page Faults: "
							<< faultsResult[maxFrames - 1][seq]
							<< " @ Frame Size: " << maxFrames - 1 << std::endl;
					std::cout << "Page Faults: " << faultsResult[maxFrames][seq]
							<< " @ Frame Size: " << maxFrames << std::endl;
				}
			}
		}
	}

	std::cout << "\n\nAnomaly Detected " << anomalyAmount << " times\n\n";

	return 0;
}

//function to reset the frames array to empty
void resetFrames(int frames[], int max) {

	for (int i = 0; i < max; ++i) {
		frames[i] = -1;
	}
}

//function to generate a new reference string
void generateSequence(int pages[], int size, int numOfPages) {
	for (int i = 0; i < size; ++i) {
		pages[i] = rand() % numOfPages + 1;
	}
}
