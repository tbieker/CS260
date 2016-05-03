//Author: Tyler Bieker
//CS 260
//Assignment: Project 2
//Date: 04/26/2016
//Sources: Textbook, cplusplus.com

#include "linkedqueue.h"
#include "data.h"
#include <iostream>
#include <fstream>
#include <cstring>

queue::queue(){
  front = nullptr;
  end = nullptr;
}

queue::queue(char filename[MAX_CHAR]){
  std::ifstream inFile;
  inFile.open(filename);

  front = nullptr;
  end = nullptr;

  if(!inFile){
    std::cout << "Failed to open" << std::endl;
    exit(1);
  }

  data house;
  char addr[MAX_CHAR];
  int sqFt;
  int bdRm;
  float bthRm;
  char spFeat[MAX_CHAR];

  inFile.get(addr, 100, ',');
  while(!inFile.eof()){
    inFile.ignore(100, ',');
    inFile >> sqFt;
    inFile.ignore(100, ',');
    inFile >> bdRm;
    inFile.ignore(100, ',');
    inFile >> bthRm;
    inFile.ignore(100, ',');
    inFile.get(spFeat, 100, ';');
    inFile.ignore(100, ';');

    house.setAddr(addr);
    house.setSqFt(sqFt);
    house.setBed(bthRm);
    house.setBath(bthRm);
    house.setSpFeat(spFeat);

    enqueue(house);

    inFile.get(addr, 100, ',');
  }

  inFile.close();
  return;

}

queue::~queue(){
  node * curr;
  curr = front;
  while(curr != nullptr){
    front = front->next;
    delete curr;
    curr = nullptr;
    curr = front;
  }
}

bool queue::enqueue(data& house){
  node * newNode;
  newNode = new node;
  newNode->house = house;
  if(front == nullptr){
    front = newNode;
    end = newNode;
  }else{
    end->next = newNode;
    end = newNode;
    end->next = nullptr;
  }
  return true;
}

bool queue::dequeue(data& house){
  if(isEmpty()){
    return false;
  }else{
    node * curr;
    curr = front;
    if(front->next == nullptr){
      front = end = nullptr;
    }else{
      front = front->next;
    }
    house = curr->house;
    delete curr;
    curr = nullptr;
    return true;
  }
}

bool queue::isEmpty() const{
  if(front == nullptr){
    return true;
  }else{
    return false;
  }
}

void queue::display() const{
  node * curr;
  curr = front;
  while(curr){
    std::cout << curr->house << std::endl;
    curr = curr->next;
  }
  return;
}
