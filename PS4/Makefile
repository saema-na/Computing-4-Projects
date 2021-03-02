CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11
OBJ = ED.o
DEPS =
LIBS = 
EXE = ED

all: ED

ED: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

ED.o: ED.cpp
	$(CC) -c $(CFLAGS) ED.cpp -o ED.o

clean:
	\rm *.o *~ $(EXE)
