//Author: Tyler Bieker
//Class: CS 260
//Assignment: Project 1
//Date:
//Sources:textbook, C++ Programming(Malik)

#include <iostream>
#include <cstring>
#include "winery.h"

/***************************************
 * Constructors
 ***************************************/

winery::winery(){	//default constructor

	name = new char[strlen("No name") + 1];
	strcpy(name, "No name");
	
	location =  new char[strlen("no location") + 1];
	strcpy(location, "No location");
	
	year = 0;
	rating = 0.0;
	acres = 0.0;
	return;
}

winery::winery(const winery& aWinery){	//copy constructor
	if(name != NULL){
		delete [] name;
		name = NULL;
	}
	if(location != NULL){
		delete [] location;
		location = NULL;
	}
	this->name = new char[strlen(aWinery.name) + 1];
	strcpy(this->name, aWinery.name);
	this->location = new char[strlen(aWinery.location) + 1];
	strcpy(this->location, aWinery.location);
	this->year = aWinery.year;
	this->rating = aWinery.rating;
	this->acres = aWinery.acres;
	return;
}

winery::~winery(){	//destructor
	delete [] name;
	delete [] location;
	name = NULL;
	location = NULL;	
	return;
}



/***************************************
 * Public functions of class list
 ***************************************/
 
void winery::setAcres(float acres){
	this->acres = acres;
	return;
}

void winery::setLocation(char location[MAX_CHAR]){
	if(this->location){
		delete [] this->location;
	}
	this->location = new char[strlen(location + 1)];
	strcpy(this->location, location);
	return;
}

void winery::setName(char name[MAX_CHAR]){
	if(this->name){
		delete [] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	return;
}

void winery::setRating(float rating){
	this->rating = rating;
	return;
}

void winery::setYear(int year){
	this->year = year;
	return;
}

void winery::print(void) const{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Location: " << this->location << std::endl;
	std::cout << "Year: " << this->year << std::endl;
	std::cout << "Acres: " << this->acres << std::endl;
	std::cout << "Rating: " << this->rating << std::endl;
	std::cout << std::endl;
	return;
}

winery& winery::operator=(const winery& aWinery){
	if(this == &aWinery){
		return *this;
	}else{	
		setName(aWinery.name);
		setLocation(aWinery.location);
		setYear(aWinery.year);
		setRating(aWinery.rating);
		setAcres(aWinery.acres);
		return *this;
	}
}



/***************************************
 * Overloaded operators of class list
 ***************************************/
 

bool operator>(const winery& aWinery, const winery& bWinery){
	/*
	If the name of the winery is greater than the name
	of aWinery return true, otherwise return false.
	
	Purpose: Sort the winery names from a to z.
	
	Return true if the name is greater than the name
	compared to.
	*/
	if(strcmp(aWinery.name, bWinery.name) > 0){
		//strcmp is >0 if a > b
		return true;
	}
	return false;
}


bool operator<(const winery& aWinery, const winery& bWinery){
	/*
	If the rating of the winery is equal to the rating of
	aWinery, check if acres of winery is less than acres
	of aWinery.
	
	Purpose: Sort wineries by rating. If the ratings are equal,
	sort by acre size from smallest to larges.
	
	Return true if:
		rating is less
		the rating is equal but acres are greater
	Return false if:
		rating is higher
		ratings are equal and acres are less
	*/
	if(aWinery.rating < bWinery.rating){
		return true;
	}
	else if(aWinery.rating > bWinery.rating){
		return false;
	}else if(aWinery.rating == bWinery.rating){
		if(aWinery.acres < bWinery.acres){
			return false;
		}else{
			return true;
		}
	}
}

bool operator==(const winery& aWinery, const char key[100]){
	/*
	compare winery name to char array key
	
	Return true if:
		name of winery is equal to key
	Return false if:
		name of the winery is not equal
	*/
	if(strcmp(aWinery.name, key) == 0){
		//if strcmp = 0, strings are equal
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const winery& aWinery){
	out << aWinery.name << ","
	    << aWinery.location << ","
	    << aWinery.year << ","
	    << aWinery.acres << ","
	    << aWinery.rating << "\n";
	return out;
}


