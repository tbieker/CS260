# Author: Tyler Bieker
# CS260
# Assignment: Project 2 Makefile
# Date: 04/28/2016
# Sources: None

CC=g++ -std=c++11
FLAGS= -c -Wall

all: project2

project2:	project2driver.o linkedqueue.o linkedstack.o data.o
	${CC} data.o linkedstack.o linkedqueue.o project2driver.o -o project2

project2driver.o: project2driver.cpp
	${CC} ${FLAGS} project2driver.cpp

linkedqueue.o: linkedqueue.h linkedqueue.cpp
	${CC} ${FLAGS} linkedqueue.h linkedqueue.cpp

linkedstack.o: linkedstack.h linkedstack.cpp
	${CC} ${FLAGS} linkedstack.h linkedstack.cpp

data.o:	data.h data.cpp
	${CC} ${FLAGS} data.h data.cpp

clean:
	rm *.o project2 *.gch
