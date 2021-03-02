CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11
OBJ = MModel.o test.o TextGenerator.o
DEPS =
LIBS =
EXE = TextGenerator

TextGenerator: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS) -lboost_unit_test_framework

MModel.o: MModel.cpp MModel.h
	$(CC) -c $(CFLAGS) MModel.cpp -o MModel.o

test.o: test.cpp MModel.h
	$(CC) -c $(CFLAGS) test.cpp -o test.o

clean:
	\rm *.o *~ $(EXE)
