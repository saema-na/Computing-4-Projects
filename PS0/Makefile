sfml-app: main.o
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c -Wall -Werror -ansi -pedantic main.cpp

clean:
	\rm *.o *~ sfml-app



