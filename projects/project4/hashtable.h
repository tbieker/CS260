//Author: Tyler Bieker
//CS260 Project 3
//Date:
//Sources:

#ifndef _HASHTABLE_
#define _HASHTABLE_

#include "vendor.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "node.h"

class hashTable{
private:
  node ** table;
  int capacity;
  int size; //size of table
  const static int DEFAULT_CAPACITY = 50;
  //char filename[100] = "data.dat";

  void destroyTable();
  void initializeTable();
  int keyGen(char * product);

public:
  hashTable();
  hashTable(const hashTable& aTable);
  hashTable(char fileName[100]);
  ~hashTable();

  void add(node * newNode);
  bool remove(char * vendorName);
  bool retrieve(char * product, vendor& aVendor);	//retrieve vendor by product type
  void display(); //display all vendors by product type
  void monitor();	//monitor distribution of hashTable
  void writeOut(char * filename);

  const hashTable& operator=(const hashTable& aTable);
};

#endif
