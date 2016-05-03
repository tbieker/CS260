//Author: Tyler Bieker
//Class: CS 260
//Assignment: Project 1
//Date:
//Sources: textbook, C++ Programming(Malik)

#ifndef _LIST_
#define _LIST_

#include <iostream>
#include "winery.h"

class list{
	private:
		struct node{
			winery item;
			node * nextByName;
			node * nextByRating;
		};
		
		node * headByName;
		node * headByRating;
		
		const static int MAX_CHAR = 100;
		
		void setRating(void); 	//function to set the rating thread = to name thread
		void sortRating(void);	//function to sort the rating thread
		 
	public:
		list();							//default constructor
		list(const list& aList);		//copy constructor
		list(char fileName[MAX_CHAR]); 	//constructor to load from file
		~list();
		
		void insert(winery& aWinery);
		void remove(char key[MAX_CHAR]);
		void displayByRating(void) const;
		void displayByName(void) const;
		void retrieve(char key[MAX_CHAR], winery& aWinery);	//search for winery by key = name
		void writeOut(char fileName[MAX_CHAR]);
		
		const list& operator=(const list& aList); //deep copy
};

#endif
