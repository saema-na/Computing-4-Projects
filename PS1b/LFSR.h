// Copyright Saema Nazar 2020
#pragma once
#include <vector>
#include <string>

class FibLFSR {
 public:
  FibLFSR(std::string seed);  // NOLINT
  int step();  // simulate one step and return the
  int generate(int k);  // NOLINT
  friend std::ostream& operator<<(std::ostream& out, const FibLFSR& fib);

  ~FibLFSR();

 private:
  std::vector<int> bitString;
};
