#Author: Tyler Bieker
#Assignment: Project 3

CC=g++ -std=c++11
FLAGS= -c -Wall

all: project3

project3: project3driver.o hashtable.o stock.o
	${CC} stock.o hashtable.o project3driver.o -o project3

project3driver.o: project3driver.cpp
	${CC} ${FLAGS} project3driver.cpp

hashtable.o: hashtable.h hashtable.cpp
	${CC} ${FLAGS} hashtable.h hashtable.cpp

stock.o: stock.h stock.cpp
	${CC} ${FLAGS} stock.h stock.cpp

clean:
	rm *.o *.gch project3
