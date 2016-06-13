#Author: Tyler Bieker
#Assignment: Project 4

CC=g++ -std=c++11
FLAGS= -c -Wall

all: project4

project4: project4driver.o collection.o binarytree.o hashtable.o vendor.o
	${CC} vendor.o hashtable.o binarytree.o collection.o project4driver.o -o project4

project4driver.o: project4driver.cpp
	${CC} ${FLAGS} project4driver.cpp

collection.o: collection.h collection.cpp
	${CC} ${FLAGS} collection.h collection.cpp

binarytree.o: binarytree.h binarytree.cpp
	${CC} ${FLAGS} binarytree.h binarytree.cpp

hashtable.o: hashtable.h hashtable.cpp
	${CC} ${FLAGS} hashtable.h hashtable.cpp

vendor.o: vendor.h vendor.cpp
	${CC} ${FLAGS} vendor.h vendor.cpp

clean:
	rm *.o *.gch project4
