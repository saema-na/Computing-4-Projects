// Copyright 2020 Saema Nazar
#pragma once
#include <iostream>
#include <vector>
#include <string>

class ED {
 public:
  ED(std::string a, std::string b);
  static int penalty(char a, char b);
  static int min(int a, int b, int c);  // NOLINT
  int OptDistance(void);
  std::string Alignment(void);

 private:
  int M;  // length string one
  int N;  // length string two
  std::string vertical;  // NOLINT
  std::string horizontal;  // horizontal string, two
  int gapPenalty = 2;
  int mismatchPenalty = 1;
  std::vector<std::vector<int>> matrix;
};
