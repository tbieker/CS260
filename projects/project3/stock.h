//Author: Tyler Bieker
//CS260 Project 3
//Date: 05/13/2016
//Sources:

#ifndef _STOCK_
#define _STOCK_

#include <cstring>
#include <iostream>

class stock{
private:
  char * tickerSymbol;
  char * name;
  float value;
  char * date;
  float netAssetValue;

public:
  stock();
  stock(const stock& aStock);
  ~stock();

  void setSymbol(char tickerSymbol[100]);
  void setName(char name[100]);
  void setValue(float value);
  void setDate(char date[100]);
  void setReturn(float netAssetValue);
  void print();
  void getTicker(char ticker[100]);

  stock& operator=(const stock& aStock);
  friend bool operator<(const stock& s1, const stock& s2);
  friend std::ostream& operator<<(std::ostream& out, const stock& aStock);
};

#endif
