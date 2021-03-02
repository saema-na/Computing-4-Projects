#pragma once
#include <vector>

class FibLFSR {
public:
  FibLFSR(std::string seed); // constructor to create LFSR with
                             // the given initial seed and tap


  int step(); // simulate one step and return the
              // new bit as 0 or 1


  int generate(int k); // simulate k steps and return
                       // k-bit integer

  friend std::ostream& operator<<(std::ostream& out, const FibLFSR& fib);
  
  ~FibLFSR();

private:
  std::vector<int> bitString;
};
