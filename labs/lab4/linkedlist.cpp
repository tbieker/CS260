//Author: Tyler Bieker
//CS 260
//Assignment: Lab 4
//Date: 05/09/2016
//Sources: Textbook

#include "linkedlist.h"
#include <iostream>

//Public functions
LinkedList::LinkedList(){
	head = NULL;
	return;
}

LinkedList::~LinkedList(){
	trav = head;
	while(trav != NULL){
		head = trav->next;
		delete trav;
		trav = NULL;
		trav = head;
	}
	return;
}

void LinkedList::add(int ch){
	trav = NULL;
	add(head, ch, trav);
	return;
}

bool LinkedList::find(int ch){
	return find(head, ch);
}

bool LinkedList::del(int ch){
	trav = NULL;
	return del(head, ch, trav);
}


//Private functions
bool LinkedList::find(node *& first, int ch){
	if(!first){	//end of list
		return false;
	}else{
		if(first->data == ch){	//return true if data is equal to searched term
			return true;
		}else{
			return find(first->next, ch);
		}
	}
}

bool LinkedList::del(node*& first, int ch, node*& prev){
	if(!first)	//end of list and not found
	{
		return false;
	}
	else{
		if(first->data == ch)
		{
			if(!prev)	//delete head
			{
				std::cout << "head" << std::endl;
				head = first->next;
				delete first;
				first = NULL;
				return true;
			}
			prev = first;
			first = first->next;
			return true;
		}
		else
		{
			return del(first->next, ch, first);
		}
	}
}

void LinkedList::add(node *& first, int ch, node *& prev){
	if(!first){	//add to end of list
		first = new node;
		first->data = ch;
		if(prev){
			prev->next = first;
		}
	}else{
		if(ch < first->data){
			node * newNode = new node;
			newNode->data = ch;
			if(prev == NULL){	//first in list
				newNode->next = first;
				head = newNode;
			}else{
				newNode->next = first;
				prev->next = newNode;
			}
		}else{
			add(first->next, ch, first);
		}
	}
}

int LinkedList::sum(void){	//iteratively add list
	trav = head;
	int total = 0;
	while(trav != NULL){
		total = total + trav->data;
	}
	return total;
}

int LinkedList::sumR(void){	//recursively add list
	trav = head;
	int total = 0;
	return sumRec(trav, total);
}

int LinkedList::sumRec(node * curr, int& x){
	if(curr != nullptr){
		x = x + sumRec(curr->next, x);
	}
	return x;
}

//Overloaded functions
std::ostream& operator<<(std::ostream& out, LinkedList& list){
	if(list.head == NULL){
		out << "Empty" << std::endl;
		return out;
	}else{
		list.trav = list.head;
		while(list.trav != NULL){
			out << list.trav->data;
			list.trav = list.trav->next;
		}
	}
	out << std::endl;
	return out;
}
