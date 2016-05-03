//Author: Tyler Bieker
//CS 260
//Assignment: Project 2 linkedstack
//Date: 04/26/2016
//Sources: Textbook, cplusplus.com

#ifndef _LINKEDSTACK_
#define _LINKEDSTACK_

#include "data.h"

class stack{
private:
  struct node{
    data house;
    node * next;
  };
  node * top;

public:
  stack();
  ~stack();

  bool push(data& house);
  bool pop(data& house);
  bool peak();  //add in future
  bool isEmpty();
  void display();

  stack& operator=(const stack& aStack);
};

#endif
