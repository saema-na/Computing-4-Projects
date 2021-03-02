// Copyright 2020 Saema Nazar
#pragma once

#include <iostream>
#include <deque>

class CircularBuffer {
 public:
  explicit CircularBuffer(int capacity);
  int size();   // return number of items currently in the buffer
  bool isEmpty();   // is the buffer empty (size equals zero)?
  bool isFull();   // is the buffer full (size equals capacity)?
  void enqueue(int16_t x);   // add item x to the end
  int16_t dequeue();   // delete and return item from the front
  int16_t peek();   // return (but do not delete) item from the front

 private:
  std::deque<int16_t> buffer;
  unsigned int max;  // capacity of buffer
};
