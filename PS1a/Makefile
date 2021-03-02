ps1a: test.o FibLFSR.o 
	g++ test.o FibLFSR.o -lboost_unit_test_framework -o ps1a
test.o: test.cpp FibLFSR.hpp
	g++ -c test.cpp -o test.o
FibLFSR.o: FibLFSR.cpp FibLFSR.hpp
	g++ -c FibLFSR.cpp -o FibLFSR.o
clean:
	\rm *.o *~ ps1a






