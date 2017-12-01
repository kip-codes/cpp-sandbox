containers.out : container.o main.o sortedvector.o vector.o 
	g++ -ansi -Wall -g -o containers.out container.o main.o sortedvector.o vector.o

container.o : container.cpp container.h
	g++ -ansi -Wall -g -c container.cpp

main.o : main.cpp container.h sortedvector.h vector.h
	g++ -ansi -Wall -g -c main.cpp

sortedvector.o : sortedvector.cpp sortedvector.h container.h
	g++ -ansi -Wall -g -c sortedvector.cpp

vector.o : vector.cpp vector.h sortedvector.h container.h
	g++ -ansi -Wall -g -c vector.cpp
clean : 
	rm -f containers.out container.o main.o sortedvector.o vector.o
