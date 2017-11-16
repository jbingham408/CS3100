#include <iostream>
#include <thread>

void producer(int);
void consumer(int);

int main(int argc, char** argv)
{

	if(argc != 4){
		std::cout << "Wrong number of arguments\n";
		return 1;
	}

	for(int i = 1; i < argc; ++i){
		std::cout << argv[i] << std::endl;
		if(atoi(argv[i]) <= 0){
			std::cout << "Argument " << i << " doesn't work\n";
			return 1;
		}
	}

	int numOfProducers = atoi(argv[1]);
	int numOfConsumers = atoi(argv[2]);
	int sharedQueueSize = atoi(argv[3]);

	std::thread c[numOfConsumers];
	std::thread p[numOfProducers];

	for(int i = 0; i < numOfConsumers; ++i){
		c[i] = std::thread(consumer, i);
	}

	for(int i = 0; i < numOfProducers; ++i){
		p[i] = std::thread(producer, i);
	}


	std::cout << "Main\n";

	for(int i = 0; i < numOfConsumers; ++i){
		c[i].join();
	}
	for(int i = 0; i < numOfProducers; ++i){
		p[i].join();
	}

	return 0;
}

void producer(int id){
	std::cout << "Producer " << id << std::endl;
}

void consumer(int id){
	std::cout << "Consumer " << id << std::endl;
}
