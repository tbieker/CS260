//Author: Tyler Bieker
//CS 260
//Assignment: Project 2 linkedqueue
//Date: 04/26/2016
//Sources: Textbook, cplusplus.com

#ifndef _LINKEDQUEUE_
#define _LINKEDQUEUE_

#include "data.h"

class queue{
private:
  struct node{
    data house;
    node * next;
  };
  node * front;
  node * end;

  const static int MAX_CHAR = 100;

public:
  queue();
  queue(char filename[MAX_CHAR]);
  ~queue();

  bool enqueue(data& house);
  bool dequeue(data& house);
  bool isEmpty() const;
  void display() const;

  queue& operator=(const queue& aQueue);
};

#endif
