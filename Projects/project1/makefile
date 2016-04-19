#Author: Tyler Bieker
#Class: CS 260
#Assignment: Project 1 Makefile
#Date: 
#Sources: 

CC=g++ -std=c++11
CFLAGS= -c -Wall

all: project1driver

project1driver: project1driver.o winery.o list.o
	$(CC) project1driver.o list.o winery.o  -o project1driver
	
project1driver.o: project1driver.cpp
	$(CC) $(CFLAGS) project1driver.cpp

list.o: list.h list.cpp
	$(CC) $(CFLAGS) list.h list.cpp

winery.o: winery.h winery.cpp
	$(CC) $(CFLAGS) winery.h winery.cpp

clean:
	rm *.o *.gch project1driver
