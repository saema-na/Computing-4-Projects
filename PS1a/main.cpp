// Copyright 2020 Saema Nazar

#include <iostream>
#include <vector>
#include <string>
#include "FibLFSR.hpp"

using namespace std;


int main(int argc, char* argv[]){
  
  FibLFSR bit("1011011000110110");

  for(int i=0; i<10; i++){
    bit.step();
  }
  
  return 0;

}
