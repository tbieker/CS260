//Author: Tyler Bieker
//Class: CS260
//Assignment: Lab 2
//Date: 04/04/2016
//Sources:

#include <ostream>
#include "linkedlist.h"

LinkedList::LinkedList(){
	head = NULL;
}

//copy constructor
LinkedList::LinkedList(const LinkedList& list){
	if(list.head == NULL){
		head = NULL;
	}
	else{
		//first node
		head = new node;
		head->item = list.head->item;
		
		//create source and destination
		node * srcNode = list.head->next;
		node * destNode = head;
		
		//iterate through list and copy from src to dest
		while(srcNode != NULL){
			destNode->next = new node;
			destNode = destNode->next;
			destNode->item = srcNode->item;
			srcNode = srcNode->next;
		}
		//set tail next node to null
		destNode->next = NULL;
	}
	
}

//destructor
LinkedList::~LinkedList(){
	node * curr;
	curr = head;
	
	while(head != NULL){
		curr = head->next;
		head = NULL;
		delete head;
		head = curr;
	}
}

void LinkedList::add(char ch){
	node * curr = head;
	node * prev = NULL;
	
	//traverse list
	while(curr != NULL && curr->item < ch){
		prev = curr; 
		curr = curr->next;
		prev->next = curr;
	}
	//item exists
	if(curr && curr->item == ch){
		return;
	}
	else{
		node * newNode;
		newNode = new node;
		newNode->item = ch;
		newNode->next = NULL;
		
		//first item on list
		if(prev == NULL){
			head = newNode;
			return;
		}
		
		newNode->next = curr;
		prev->next = newNode;
		return;
	}
}

bool LinkedList::find(char ch) const{
	node * curr;
	curr = head;
	
	while(curr != NULL && curr->item != ch){
		curr = curr->next;
	}
	if(curr == NULL){
		//reached end of list and did not find ch
		return false;
	}else if(curr->item == ch){
		return true;
	}
}

bool LinkedList::del(char ch){
	node * curr = head;
	node * prev = NULL;
	
	while(curr->next != NULL && curr->item != ch){
		prev = curr;
		curr = curr->next;
		prev->next = curr;
	}
	
	if(curr->item == ch){
		//ch = head
		if(prev == NULL){
			head = curr->next;
			curr = NULL;
			delete curr;
			return true;
		}else{
			prev->next = curr->next;
			curr = NULL;
			delete curr;
			return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, LinkedList& list){
	list.trav = list.head;
	while(list.trav != NULL){
		out << list.trav->item;
		list.trav = list.trav->next;
	}
	out << std::endl;
	return out;
	
}












