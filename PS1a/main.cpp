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
  
  
  //  cout<<"Generate function output: "<<bit.generate(5)<<endl;
  // cout<<"Gen Func output 2: "<<bit.generate(5)<<endl;
  
  
  return 0;


}
