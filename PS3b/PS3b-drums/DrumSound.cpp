#include <iostream>
#include "DrumSound.h"
#include <math.h>
#include <random>

// create a guitar string sound of the
// given frequency using a sampling rate of 44,100
DrumSound::DrumSound(double frequency) {
	double SAMPLE_RATE = 44100.0;
	
	// cant do less than or equal to 0 frequency
	if (frequency <= 0) {
		throw std::invalid_argument("Invalid Argument: Frequency cannot be less than or equal to zero.\n");
	}

	//lambda expression
	auto getN = [&]() {return ceil(SAMPLE_RATE / frequency); };


	buffer_ptr = new CircularBuffer(getN());
}


// create a guitar string with
// size and initial values given by the vector
DrumSound::DrumSound(std::vector<sf::Int16> init) {

	// empty vector arg throws error
	if (init.empty()) {
		throw std::invalid_argument("Invalid Argument: Vector cannot be empty.\n");
	}

	int size = init.size();
	buffer_ptr = new CircularBuffer(size);	// initalize new buffer with size of init vector

	//enqueue each element in vector onto deque
	for (int i = 0; i < size - 1; i++) {
		buffer_ptr->enqueue(init.at(i));
	}
}

// pluck the guitar string by replacing the buffer with random values,
 // representing white noise
void DrumSound::pluck() {
	std::random_device rd;

	// EMPTY DEQUE: empty dequeue contents while buffer is NOT empty
	while (!buffer_ptr->isEmpty()) {
		buffer_ptr->dequeue();
	}

	// add random values while buffer is NOT full
	while (!(buffer_ptr->isFull())) {
		int16_t randomVal = -32768 + (rd() % (32767 - (-32768) + 1));
		buffer_ptr->enqueue(randomVal);
	}
}


void DrumSound::tic() {
	//delete the sample at the front of the buffer
	//add to the end of the ring buffer the average of the first two samples, multiplied by the energy decay factor
	int16_t firstSample = buffer_ptr->dequeue();	//taking element off from front
	int16_t secondSample = buffer_ptr->peek();		//getting value of second element
	int16_t average = ((firstSample + secondSample) / 2) * 1.00;
	if (rand()%2) {
		average = -(average);
	}
	buffer_ptr->enqueue(average);
}


// return the current sample
sf::Int16 DrumSound::sample() {
	return buffer_ptr->peek();
}

// return num of times tic was called
int DrumSound::time() {
	return tick;
}


DrumSound::~DrumSound() {
	delete buffer_ptr;
	buffer_ptr = nullptr;
}
