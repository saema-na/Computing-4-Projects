// Copyright 2020 Saema Nazar

#include "CircularBuffer.h"
#include <stdint.h>
#include <iostream>


CircularBuffer::CircularBuffer(int capacity) {
  if (capacity < 1) {
    throw std::invalid_argument
      ("CircularBuffer constructor: capacity must be greater than zero");
  }
  max = capacity+1;
}


int CircularBuffer::size() {   // return number of items currently in the buffer
     return buffer.size();
}


bool CircularBuffer::isEmpty() {   // is the buffer empty (size equals zero)?
      if (buffer.size() == 0) {
          return 1;
         }
        return 0;
}


bool CircularBuffer::isFull() {  // is the buffer full (size equals capacity)?
    if (buffer.size() == max) {
      return 1;
      }
       return 0;
}


void CircularBuffer::CircularBuffer::enqueue(int16_t x) {
  if (max == buffer.size()) {
    throw std::runtime_error("enqueue: can't enqueue to a full ring.");
  }

  buffer.push_back(x);
}


int16_t CircularBuffer::dequeue() {   // delete and return item from the front
  if (isEmpty()) {
    throw std::runtime_error("dequeue: can't dequeue from an empty buffer.");
  }
        int firstItem = buffer.at(0);
        buffer.pop_front();
        return firstItem;
}

int16_t CircularBuffer::peek() {  // return but dont delete element from front
  if (buffer.size() == 0) {
    throw std::runtime_error("peek: can't peek from an empty buffer.");
  }
  return buffer.at(0);
}
