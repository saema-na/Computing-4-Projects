// Copyright 2020 Saema Nazar

#include <cstdio>
#include <fstream>
#include <string>
#include <iostream>
#include <boost/regex.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"

using namespace std;  // NOLINT
using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_period;
using boost::gregorian::date_duration;

using boost::posix_time::ptime;
using boost::posix_time::time_duration;

int main(int argc, char* argv[]) {
  int lineCount = 1;
  string fileName = argv[1];
  ifstream fileLog(argv[1]);
  boost::smatch sm;

  // LAMBDA IMPLEMENTATION
  auto fileOpen = [&]() {
    if (fileLog.is_open())
      return 1;
    else
      return 0;
  };

  if (fileOpen() == 0) {
    cout << "Error opening file." << endl;
    exit(1);
  }

  int nameLength = fileName.size();
  string outFile = fileName;
  outFile[nameLength-1] = 't';
  outFile[nameLength-2] = 'p';
  outFile[nameLength-3] = 'r';
  outFile[nameLength-4] = '.';
  ofstream output(outFile);

  bool matchSt = 0;
  bool matchEnd = 0;
  string testStr;
  int pairCount = 0;
  boost::posix_time:: ptime t1, t2;
  boost::regex searchExp("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) " "([0-9]++):([0-9]{2}):([0-9]{2})" "(.*log.c.166.*)");  // NOLINT
  boost::regex endExpr("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) " "([0-9]++):([0-9]{2}):([0-9]{2})" "(.*oejs.AbstractConnector:Started SelectChannelConnector.*)");  // NOLINT


  while (getline(fileLog, testStr)) {
    matchSt = boost::regex_match(testStr, sm, searchExp);

      // if start is found after another start
      if (matchSt) {
        if (pairCount == 1) {
	  cout<< lineCount << "(" << argv[1] << "): " << sm[1] << "-" << sm[2] << "-" << sm[3] << " " << sm[4] << ":" << sm[5] << ":" << sm[6] << " Boot FAILED" << endl;
         output << lineCount << "(" << argv[1] << "): " << sm[1] << "-" << sm[2] << "-" << sm[3] << " " << sm[4] << ":" << sm[5] << ":" << sm[6] << " Boot FAILED" << endl;   // NOLINT
         date tempD2(from_simple_string(sm[0]));
         boost::posix_time::ptime tempT2(tempD2,boost::posix_time::time_duration(stoi(sm[4]), stoi(sm[5]), stoi(sm[6])));   // NOLINT
         t2 = tempT2;
         boost::posix_time::time_duration td = t2 - t1;
	 cout<< "\tElapsed Time: "<< td.total_milliseconds() << " ms" << endl << endl;
         output << "\tElapsed Time: "<< td.total_milliseconds() << " ms" << endl << endl;  // NOLINT
        }

        pairCount = 1;   // = 1 if start has been found
	cout<< "==Device Boot==" << endl << lineCount << "(" << argv[1] << "):" << sm[1] << "-" << sm[2] << "-" << sm[3] << " " << sm[4] << ":" << sm[5] << ":" << sm[6] << " Boot Start" << endl;
        output << "==Device Boot==" << endl << lineCount << "(" << argv[1] << "):" << sm[1] << "-" << sm[2] << "-" << sm[3] << " " << sm[4] << ":" << sm[5] << ":" << sm[6] << " Boot Start" << endl;   // NOLINT

        date tempD(from_simple_string(sm[0]));
        boost::posix_time::ptime tempT(tempD, boost::posix_time::time_duration(stoi(sm[4]), stoi(sm[5]), stoi(sm[6])));   // NOLINT
        t1 = tempT;  // starting time
      }

      matchEnd = boost::regex_match(testStr, sm, endExpr);
    if (matchEnd) {
      cout<<lineCount<<"("<<argv[1]<<"): "<<sm[1]<<"-"<<sm[2]<<"-"<<sm[3]<<" "<<sm[4]<<":"<<sm[5]<<":"<<sm[6]<<" Boot SUCCESS"<<endl;
      output<<lineCount<<"("<<argv[1]<<"): "<<sm[1]<<"-"<<sm[2]<<"-"<<sm[3]<<" "<<sm[4]<<":"<<sm[5]<<":"<<sm[6]<<" Boot SUCCESS"<<endl; // NOLINT

      date tempD3(from_simple_string(sm[0]));
      boost::posix_time::ptime tempT3(tempD3,boost::posix_time::time_duration(stoi(sm[4]), stoi(sm[5]), stoi(sm[6]))); // NOLINT
      t2 = tempT3;
      boost::posix_time::time_duration td = t2 - t1;
      cout<<"\tElapsed Time: " << td.total_milliseconds() << " ms" << endl << endl;
      output << "\tElapsed Time: " << td.total_milliseconds() << " ms" << endl << endl; // NOLINT
      pairCount = 0;
    }
    lineCount++;
  }

  fileLog.close();
  output.close();

  return 0;
}
