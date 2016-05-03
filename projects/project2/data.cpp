//Author: Tyler Bieker
//CS 260
//Assignment: Project 2
//Date: 04/26/2016
//Sources: Textbook, C++ Programming(Malik)

#include "data.h"
#include <cstring>
#include <iostream>

/************************************************
* Constructors
************************************************/

data::data(){
  addr = new char[strlen("No address") + 1];
  strcpy(addr, "No address");
  sqFt = 0;
  bdRm = 0;
  bthRm = 0.0;
  spFeat = new char[strlen("No special features") + 1];
  strcpy(spFeat, "No special features");
  return;
}

data::data(const data& house){ //copy constructor
  if(house == *this){
    return;
  }else{
    setAddr(house.addr);
    setSqFt(house.sqFt);
    setBed(house.bdRm);
    setBath(house.bthRm);
    setSpFeat(house.spFeat);
    return;
  }
}

data::~data(){
  if(addr != nullptr){
    delete [] addr;
    addr = nullptr;
  }
  if(spFeat != nullptr){
    delete [] spFeat;
    spFeat = nullptr;
  }
  return;
}

/************************************************
* Public Functions
************************************************/

void data::setAddr(char addr[MAX_CHAR]){
  if(this->addr != nullptr){
    delete [] this->addr;
    this->addr = nullptr;
  }
  this->addr = new char[strlen(addr) + 1];
  strcpy(this->addr, addr);
  return;
}

void data::setSqFt(int sqFt){
  this->sqFt = sqFt;
  return;
}

void data::setBed(int bdRm){
  this->bdRm = bdRm;
  return;
}

void data::setBath(float bthRm){
  this->bthRm = bthRm;
  return;
}

void data::setSpFeat(char spFeat[MAX_CHAR]){
  if(this->spFeat != nullptr){
    delete [] this->spFeat;
    this->spFeat = nullptr;
  }
  this->spFeat = new char[strlen(spFeat) + 1];
  strcpy(this->spFeat, spFeat);
  return;
}

/************************************************
* Private Functions
************************************************/

/************************************************
* Overloaded Operators
************************************************/

data& data::operator=(const data& house){ //deep copy
  if(this == &house){
    return *this;
  }
  else{
    setAddr(house.addr);
    setSqFt(house.sqFt);
    setBed(house.bdRm);
    setBath(house.bthRm);
    setSpFeat(house.spFeat);
    return *this;
  }
}

bool operator==(const data& h1, const data& h2){
  if(strcmp(h1.addr, h2.addr) == 0){
    if(h1.sqFt == h2.sqFt){
      if(h1.bdRm == h2.bdRm){
        if(h1.bthRm == h2.bthRm){
          if(strcmp(h1.spFeat, h2.spFeat) == 0){
            return true;
          }
        }
      }
    }
  }else{
    return false;
  }
}

std::ostream& operator<<(std::ostream& out, const data& house){
  out << "Address: " << house.addr << "\n"
      << "Square Footage: " << house.sqFt << "\n"
      << "Bedrooms: " << house.bdRm << "\n"
      << "Bathrooms: " << house.bthRm << "\n"
      << "Special Features: " << house.spFeat << "\n";
    return out;
}
