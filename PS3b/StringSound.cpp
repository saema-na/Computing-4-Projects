#include <iostream>
#include "StringSound.h"
#include <math.h>
#include <random>

// create a guitar string sound of the
// given frequency using a sampling rate of 44,100
StringSound::StringSound(double frequency) {
	double SAMPLE_RATE = 44100.0;
	//	double DECAY_FACTOR = .994;

	// cant do less than or equal to 0 frequency
	if (frequency <= 0) {
		throw std::invalid_argument("Frequency cannot be less than or equal to zero.");	
	}

	//lambda expression
	auto getN= [&]() {return ceil(SAMPLE_RATE/frequency); };


	buffer_ptr = new CircularBuffer(getN());
}


// create a guitar string with
// size and initial values given by the vector
StringSound::StringSound(std::vector<sf::Int16> init){

	// empty vector throw error
	if (init.empty()) {
			throw std::invalid_argument("Vector cannot be empty.");
	}


	int size = init.size();
	buffer_ptr = new CircularBuffer(size);	// initalize new buffer with size of init vector

	//enqueue each thing in vector stating at back
	for(int i = 0; i > size-1; i++) {
		buffer_ptr->enqueue(init.at(i));
	}
}

// pluck the guitar string by replacing the buffer with random values,
 // representing white noise
void StringSound::pluck() {
	std::random_device rd;

	// EMPTY DEQUE: dequeue contents while buffer is NOT empty
	while (!buffer_ptr->isEmpty()) {
		buffer_ptr->dequeue();
	}

	// add random values while buffer is NOT full
	while (!(buffer_ptr->isFull())) {
		int16_t randomVal = -32768 + (rd() % (32767 - (-32768) + 1));
		buffer_ptr->enqueue(randomVal);
	}
}


// advance the simulation one time step
void StringSound::tic(){
	//delete the sample at the front of the ring buffer
	//add to the end of the ring buffer the average of the first two samples, multiplied by the energy decay factor (look above). 
	double DECAY_FACTOR = .994;
	int16_t firstSample = buffer_ptr->dequeue();	//taking element off from front
	int16_t secondSample = buffer_ptr->peek();		//getting value of second element
	int16_t average = ((firstSample + secondSample) / 2) * DECAY_FACTOR;
	buffer_ptr->enqueue(average);
}


// return the current sample
sf::Int16 StringSound::sample() {
	return buffer_ptr->peek();
}

// return num of times tic was called
int StringSound::time() {
	return tick;
}


StringSound::~StringSound(){
	delete buffer_ptr;
	buffer_ptr = nullptr;
}
