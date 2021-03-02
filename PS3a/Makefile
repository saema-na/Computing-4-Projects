CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11 
OBJ = CircularBuffer.o test.o
DEPS =
LIBS =
EXE = ps3a

ps3a: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS) -lboost_unit_test_framework

CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(CC) -c $(CFLAGS) CircularBuffer.cpp -o CircularBuffer.o

test.o: test.cpp CircularBuffer.h
	$(CC) -c $(CFLAGS) test.cpp -o test.o

clean:
	rm ps3a


