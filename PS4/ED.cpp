// Copyright 2020 Saema Nazar

#include "ED.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;  // NOLINT

ED::ED(string a, string b) {
     vertical = a;
     horizontal = b;
     M = vertical.length()-1;
     N = horizontal.length()-1;

      // pushback temp vectors into matrix
       for (int i = 0; i <= M; i++) {
       vector<int> temp;
       temp.push_back(0);
       // fill vectors with 0's to make a table
       for (int j = 0; j <= N; j++) {
          matrix.push_back(temp);
      }
      }
}
int ED::penalty(char a, char b) {
        auto isMatch = [&]() {
        if (a == b)
        return 1;
	}; };  // NOLINT

    if (isMatch()) {
    return 0;
      }
   else {  // NOLINT
         return 1;
        }
}
int ED::min(int a, int b, int c) {  // NOLINT
      int minim = 0;
      // if a is less than or equal to b, a is the minimum
      if (a <= b) {
      minim = a;
       }
      else {  // NOLINT
        minim = b;
     }

      // if c is less than or equal to the current minimum, the new minimum is c
        if (c <= minim) {
        minim = c;
     }
       return minim;
}

int ED::OptDistance(void) {
        // filling bottom row with gap penalties
        matrix[M][0] = N * gapPenalty;
        for (int i = 1; i <= N; i++) {
        matrix[M][i] = matrix[M][0] - (i*gapPenalty);
  }

      // filling rightmost column with gap penalties
      matrix[0][N] = M * gapPenalty;
      for (int i = 0; i <= M; i++) {
         matrix[i][N] = matrix[0][N] - (i * gapPenalty);
      }

       int k = 0;
       for (int i = (vertical.length() - 1); i >= 0; i--) {
           for (k = (horizontal.length() - 1); k >= 0; k--) {
                matrix[i][k] = penalty(M, N);
     }
  }
       return matrix[0][0];
}

string ED::Alignment(void) {
    int maxLength = M + N;
}
