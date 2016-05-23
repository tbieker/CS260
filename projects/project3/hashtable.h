//Author: Tyler Bieker
//CS260 Project 3
//Date:
//Sources:

#ifndef _HASHTABLE_
#define _HASHTABLE_

#include "stock.h"
#include <iostream>
#include <fstream>
#include <cstring>

class hashTable{
private:
  struct node{
    stock data;
    node * next;
  };

  node ** table;
  int capacity;
  int size; //size of table
  const static int DEFAULT_CAPACITY = 27;
  //char filename[100] = "data.dat";

  void destroyTable();
  void initializeTable();
  int keyGen(char * ticker);

public:
  hashTable();
  hashTable(const hashTable& aTable);
  hashTable(char fileName[100]);
  ~hashTable();

  void add(stock& aStock);
  bool remove(char tickerSymbol[100]);
  bool modify(char tickerSymbol[100], float newNetAssetValue, char newDate[100], float newDateReturn);
  bool retrieve(char tickerSymbol[100], stock& aStock);
  void display(); //display all stocks
  void monitor();
  void writeOut(char fileName[100]);

};

#endif
