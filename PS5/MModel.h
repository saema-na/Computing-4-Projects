// Copyright 2020 Saema Nazar
#pragma once
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>

class MModel {
 public:
    MModel(std::string text, int k);
    int freq(std::string kgram) const;
    int freq(std::string kgram, char c) const;
    int kOrder() const;
    char kRand(std::string kgram);
    std::string generate(std::string kgram, int L);

    friend std::ostream& operator<<(std::ostream& out, const MModel& obj);

 private:
    int textLength;
    int orderK;     // order of markov model, length of kgrams
    std::string textString;

    // kgram string, the string youre looking for in the input
    std::string kgramString;

    // kgram, every character following the kgram
    std::map<std::string, std::multiset<char>> symTab;
};
