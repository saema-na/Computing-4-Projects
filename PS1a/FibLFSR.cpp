// Copyright 2020 Saema Nazar

#include <iostream>
#include <vector>
#include "FibLFSR.hpp"
using namespace std;

FibLFSR::FibLFSR(string seed) {
  int i;
  int temp;
  char tempChar;
  
  while (seed.size() != 16)
        {
	    cout << "Please enter a bit string with length  of 16:" << endl;
            cin >> seed;
        }

  for (i = 0; i < seed.size(); i++) {
	  bitString.push_back(seed[i] -'0');
	  }
}

int FibLFSR::step(void) {
  int result;
  
  result = bitString[0] ^ bitString[2] ^ bitString[3] ^ bitString[5]; 

  for(int i = 0; i < 15; i++) {
    bitString[i] = bitString[i + 1];
  }
  bitString[15] = result;

  return result; 
}

int FibLFSR::generate(int k) {
  int initVar = 0;
  int stepRet;
  
  for(int i = 0; i < k; i++) {
    stepRet = step();
    initVar = (initVar * 2) + stepRet;
    
  }
  return initVar;
  
}

std::ostream& operator<<(std::ostream& out, const FibLFSR& fib) {
  for(int i = 0; i < 16; i ++)
    out << fib.bitString.at(i);
}

FibLFSR::~FibLFSR(){
  bitString.clear();
}
