CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11 
OBJ = CircularBuffer.o main.o StringSound.o
DEPS =
LIBS =  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXE = KSGuitarSim

KSGuitarSim: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

StringSound.o: StringSound.cpp StringSound.h
	$(CC) -c $(CFLAGS) StringSound.cpp -o StringSound.o

CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(CC) -c $(CFLAGS) CircularBuffer.cpp -o CircularBuffer.o

main.o: main.cpp CircularBuffer.h
	$(CC) -c $(CFLAGS) main.cpp -o main.o

clean:
	\rm *.o *~ KSGuitarSim


