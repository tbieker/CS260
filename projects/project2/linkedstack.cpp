//Author: Tyler Bieker
//CS 260
//Assignment: Project 2
//Date: 04/26/2016
//Sources: Textbook, cplusplus.com

#include "linkedstack.h"
#include "data.h"
#include <iostream>

stack::stack(){
  top = nullptr;
  return;
}

stack::~stack(){
  node * curr;
  curr = top;
  while(curr){
    top = top->next;
    delete curr;
    curr = nullptr;
    curr = top;
  }
}

bool stack::push(data& house){
  node * newNode;
  newNode = new node;
  newNode->next = nullptr;
  newNode->house = house;
  if(top == nullptr){
    top = newNode;
    return true;
  }else{
    newNode->next = top;
    top = newNode;
    return true;
  }
}

bool stack::pop(data& house){
  if(isEmpty()){
    return false;
  }else{
    node * curr;
    curr = top;
    house = curr->house;
    top = top->next;
    delete curr;
    curr = nullptr;
    return true;
  }
}

bool stack::peak(){
  //add in future
  return true;
}

bool stack::isEmpty(){
  if(top == nullptr){
    return true;
  }
  else{
    return false;
  }
}

void stack::display(){
  node * curr;
  curr = top;
  while(curr){
    std::cout << curr->house << std::endl;
    curr = curr->next;
  }
  return;
}

stack& stack::operator=(const stack& aStack){
  if(&aStack == this){
    return *this;
  }else{
    node * curr;
    curr = top;
    while(curr != nullptr){ //delete previous list
      top = top->next;
      delete curr;
      curr = nullptr;
      curr = top;
    }
    if(aStack.top == nullptr){
      this->top = nullptr;
      return *this;
    }
    else{
      node * src, * dest;
      dest = this->top;
      src = aStack.top;
      while(src){
        dest = new node;
        dest->house = src->house;
        src = src->next;
        dest = dest->next;
      }
      return *this;
    }
  }
}
