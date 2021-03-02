#pragma once
#include <iostream>
#include "CircularBuffer.h"
#include <string>
#include <vector>
#include <SFML/Audio.hpp>


class StringSound {
public:
  StringSound(double frequency);   // create a guitar string sound of the  given frequency using a sampling rate of 44,100

  StringSound(std::vector<sf::Int16> init);	// create a guitar string with
  // size and initial values are given by the vector

  void pluck(); // pluck the guitar string by replacing the buffer with random values, representing white noise

  void tic();	 // advance the simulation one time step

  sf::Int16 sample(); // return the current sample

  int time(); // return num of times tic was called

  ~StringSound();

private:
	CircularBuffer* buffer_ptr;
	int tick = 0;
};
