CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11 
OBJ = CircularBuffer.o main.o DrumSound.o
DEPS =
LIBS =  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXE = KSDrumSim

KSDrumSim: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

DrumSound.o: DrumSound.cpp DrumSound.h
	$(CC) -c $(CFLAGS) DrumSound.cpp -o DrumSound.o

CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(CC) -c $(CFLAGS) CircularBuffer.cpp -o CircularBuffer.o

main.o: main.cpp CircularBuffer.h
	$(CC) -c $(CFLAGS) main.cpp -o main.o

clean:
	\rm *.o *~ KSDrumSim


