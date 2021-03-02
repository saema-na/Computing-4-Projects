#pragma once
#include <iostream>
#include "CircularBuffer.h"
#include <string>
#include <vector>
#include <SFML/Audio.hpp>


class DrumSound {
public:
	DrumSound(double frequency);		

	DrumSound(std::vector<sf::Int16> init);
	      

	void pluck();		 

	void tic();			// advance the simulation one time step

	sf::Int16 sample(); // return the current sample

	int time();			// return num of times tic was called

	~DrumSound();

private:
	CircularBuffer* buffer_ptr;
	int tick = 0;
};
