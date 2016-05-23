//Author: Tyler Bieker
//CS260 Project 3
//Date: 05/13/2016
//Sources:

#include "stock.h"

stock::stock(){
  tickerSymbol = new char[strlen("no symbol") + 1];
  strcpy(tickerSymbol, "no symbol");

  name = new char[strlen("no name") + 1];
  strcpy(name, "no name");

  value = 0;

  date = new char[strlen("0/0/0") + 1];
  strcpy(date, "0/0/0");

  netAssetValue = 0;
  return;
}

stock::stock(const stock& aStock){
  if(this == &aStock){
    return;
  }else{
    setSymbol(aStock.tickerSymbol);
    setName(aStock.name);
    setValue(aStock.value);
    setDate(aStock.date);
    setReturn(aStock.netAssetValue);
    return;
  }
}

stock::~stock(){
    delete [] tickerSymbol;
    tickerSymbol = nullptr;

    delete [] name;
    name = nullptr;

    delete [] date;
    date = nullptr;

    return;
}

void stock::setSymbol(char tickerSymbol[100]){
    if(this->tickerSymbol){
        delete [] this->tickerSymbol;
    }
  this->tickerSymbol = new char[strlen(tickerSymbol) + 1];
  strcpy(this->tickerSymbol, tickerSymbol);
  return;
}

void stock::setName(char name[100]){
    if(this->name){
        delete [] this->name;
    }
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
  return;
}

void stock::setValue(float value){
  this->value = value;
  return;
}

void stock::setDate(char date[100]){
    if(this->date){
        delete [] this->date;
    }
  this->date = new char[strlen(date) + 1];
  strcpy(this->date, date);
  return;
}

void stock::setReturn(float netAssetValue){
  this->netAssetValue = netAssetValue;
  return;
}

void stock::getTicker(char ticker[100]){
  strcpy(ticker, this->tickerSymbol);
  return;
}

stock& stock::operator=(const stock& aStock){
  if(this == &aStock){
    return *this;
  }else{
    setSymbol(aStock.tickerSymbol);
    setName(aStock.name);
    setValue(aStock.value);
    setDate(aStock.date);
    setReturn(aStock.netAssetValue);
    return *this;
  }
}

bool operator<(const stock& s1, const stock& s2){
  if(strcmp(s1.name, s2.name) < 0){
    return true;
  }else{
    return false;
  }
}

void stock::print(){
  std::cout << "Ticker: " << tickerSymbol << std::endl
      << "Name: " << name << std::endl
      << "Value: " << value << std::endl
      << "Last update: " << date << std::endl
      << "Net return: " << netAssetValue << std::endl;
  return;
}

std::ostream& operator<<(std::ostream& out, const stock& aStock){
  out << aStock.tickerSymbol << ","
      << aStock.name << ","
      << aStock.value << ","
      << aStock.date << ","
      << aStock.netAssetValue << "\n";
  return out;
}
