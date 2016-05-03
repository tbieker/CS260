//Author: Tyler Bieker
//CS 260
//Assignment: Project 2
//Date: 04/26/2016
//Sources: Textbook, C++ Programming(Malik)

#ifndef _HOUSE_
#define _HOUSE_

#include <iostream>

class data{
private:
  char * addr;  //address
  int sqFt;  //square footage
  int bdRm; //bedroom
  float bthRm; //2.1 means 2 1/2 baths
  char * spFeat; //special features

  const static int MAX_CHAR = 100; //max characters

public:
  data();
  data(const data& house);
  ~data();

  void setAddr(char addr[MAX_CHAR]); //set address
  void setSqFt(int sqFt); //set square footage
  void setBed(int bdRm);  //set bedrooms
  void setBath(float bthRm); //set bathrooms
  void setSpFeat(char spFeat[MAX_CHAR]); //set special features

  data& operator=(const data& house);
  friend bool operator==(const data& house, const data& aHouse);

  friend std::ostream& operator<<(std::ostream& out, const data& house);
};

#endif
