CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11
OBJ = PhotoMagic.o LFSR.o
DEPS =
LIBS =
EXE = PhotoMagic

all: PhotoMagic

PhotoMagic: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS) -lsfml-graphics -lsfml-window -lsfml-system

PhotoMagic.o: PhotoMagic.cpp
	$(CC) -c $(CFLAGS) PhotoMagic.cpp -o PhotoMagic.o

FibLFSR.o: LFSR.cpp LFSR.h
	$(CC) -c $(CFLAGS) LFSR.cpp -o LFSR.o

clean:
	\rm *.o *~ $(EXE)

