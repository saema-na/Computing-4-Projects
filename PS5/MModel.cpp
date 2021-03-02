// Copyright 2020 Saema Nazar
#include <iostream>
#include <cstdio>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "MModel.h"

using namespace std; // NOLINT

    // create a Markov model of order k from given text
MModel::MModel(std::string text, int k) {
    textLength = text.length();
    textString = text;

    // LAMBDA IMPLEMENTATION EXTRA CREDIT 
    auto isLengthLessThanK = [&]() {return (textLength < k); };

    if (isLengthLessThanK()) {
        throw std::invalid_argument
        ("Constructor Error: text must be > length of k.\n");
    }

    orderK = k;
    std::string temp;
    int indexModded;

    for (int i = 0; i <= textLength-1; i++) {
        indexModded = i % text.length();
        int j = indexModded;

        while (j < k+indexModded) {
            temp += text[j%text.length()];
            j++;
        }

        if (symTab.find(temp) != symTab.end()) {
            int tmpJ = j % text.length();
            symTab[temp].insert(text[tmpJ]);
        }
        else { 
            int tmpJ = j % text.length();
            symTab[temp];
            symTab[temp].insert(text[tmpJ]);
        }
        temp = "";
    }
}

int MModel::kOrder() const {    // order k of Markov model
    return orderK;
  }


// number of occurrences of kgram in text
int MModel::freq(std::string kgram) const {
  if (kgram.length() != (unsigned)orderK) {
        throw std::invalid_argument
        ("freq(string) Error: kgram is not of length k.\n");
    }
    if (symTab.find(kgram) == symTab.end()) {
        cout << "Error: given kgram was not found.\n" << endl;
        return 0;
    }
    auto p = symTab.find(kgram);
    // return size of kgram's associated multiset
    return p->second.size();
}

int MModel::freq(std::string kgram, char c) const {
  if (kgram.length() != (unsigned)orderK) {
        throw std::invalid_argument
        ("freq(string) Error: kgram is not of length k.\n");
    }

    if (symTab.find(kgram) == symTab.end()) {
        cout << "Error: given kgram was not found.\n" << endl;
        return 0;
    }
  auto p = symTab.find(kgram);
  return p->second.count(c);
}

char MModel::kRand(std::string kgram) {
    if (kgram.length() < (unsigned)orderK) {
        throw std::invalid_argument
        ("Error: kgram length must be >= length k or kgram not found.\n");
    }
    if (symTab.find(kgram) == symTab.end()) {
        throw std::invalid_argument
        ("kRand() Error: kgram was not found.\n");
    }

    int i = 0;
    int ranIndex = (unsigned)(rand() % freq(kgram)); // NOLINT
    auto p1 = symTab.find(kgram);

    auto p2 = p1->second.begin();

while (i < ranIndex) {
       p2++;
       i++;
      }
return *p2;
}

string MModel::generate(std::string kgram, int L) {
  if (kgram.length() < (unsigned)orderK) {
         throw std::invalid_argument
        ("generate() Error: kgram length must be at least length k.\n");
        }

     // chain starts with kgram then generates following letters
     string chain = kgram;
     string currKgram = kgram;

     while (chain.length() < (unsigned)L) {
         chain = chain + kRand(currKgram);
         currKgram = chain[chain.length() - 2];
         currKgram = currKgram + chain[chain.length() - 1];
     }
     return chain;
}

ostream& operator <<(ostream& out, const MModel& obj) {
     cout << "Order: " << obj.orderK << endl;
     for (auto p = obj.symTab.begin(); p != obj.symTab.end(); p++) {
         string tmp = p->first;
         cout << "\n\nKgram: " << p->first;
         cout << "\nFrequency kgram: " << obj.freq(tmp) << endl;

        for (int i = 0; i < 127; i++) {
            int tmpFreq = obj.freq(tmp, i);
            if (tmpFreq != 0) {
              char tmpCh = static_cast<char> (i);
              cout << " Frequency k+1 (" << tmpCh << "): " << tmpFreq << "";
            } else   // NOLINT
                continue;
        }
     }

     return out;
}
