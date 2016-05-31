#Author: Tyler Bieker
#CS 260
#Assignment: lab 6 makefile
#Date: 05/30/2016

CC = g++
CPPFLAGS = -Wall -g -std=c++11

main:			main.o table.o supplied.o

main.o:			table.h

table.o:		table.h

.PHONY: clean
clean:				# clean the directory
				$(info -- cleaning the directory --)
				rm -f table.o main.o main table.h.gch
