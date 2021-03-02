CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11
OBJ = main.o
DEPS =
LIBS = -lboost_regex -lboost_date_time
EXE = ps6

ps6: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

main.o: main.cpp
	$(CC) -c $(CFLAGS) main.cpp -o main.o

clean:
	\rm *.o *~ $(EXE)

