CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11
OBJ = nbody.o main.o
DEPS =
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = NBody

NBody: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

nbody.o: nbody.cpp nbody.h
	$(CC) -c $(CFLAGS) nbody.cpp -o nbody.o

main.o: main.cpp nbody.h
	$(CC) -c $(CFLAGS) main.cpp -o main.o

clean:
	\rm *.o *~ NBody

