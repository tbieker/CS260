//Author: Tyler Bieker
//Class: CS 260
//Assignment: Project 1
//Date:
//Sources: textbook, C++ Programming(Malik)

#include <iostream>
#include <fstream>
#include <cstring>
#include "list.h"

/***************************************
 * Constructors
 ***************************************/

list::list(){		//default constructor
	headByName = NULL;
	headByRating = NULL;
	return;
}

list::list(const list& aList){	//copy constructor

	//if list is empty
	if(!aList.headByName){
		headByName = NULL;
		headByRating = NULL;
	}
	//copy list
	else{
		//first node
		node * head;
		head = new node;
		head->item = aList.headByName->item;
		head->nextByName = NULL;
		head->nextByRating = NULL;
		headByName = head;
		headByRating = head;
		
		node * src;
		node * dest;
		
		dest = headByName;
		src = aList.headByName->nextByName;
		//copy name thread
		while(src != NULL){
			dest->nextByName = new node;
			dest = dest->nextByName;
			dest->item = src->item;
			
			dest->nextByName = NULL;
			dest->nextByRating = NULL;
			
			src = src->nextByName;
		}
		
		//set rating thread to name thread
		setRating();
		//sort rating thread
		sortRating();
	}
	return;
}

list::list(char fileName[MAX_CHAR]){	//load list from file
	std::ifstream inFile;
	
	headByName = NULL;
	headByRating = NULL;
	
	inFile.open(fileName);
	if(!inFile){
		std::cout << "Failed to open" << fileName;
		exit(1);
	}
	
	
	winery aWinery;
	char name[MAX_CHAR];
	char location[MAX_CHAR];
	int year;
	float acres;
	float rating;
	
	inFile.get(name, 100, ',');
	while(!inFile.eof()){
		inFile.ignore(100, ',');
		inFile.get(location, 100, ',');
		inFile.ignore(100, ',');
		inFile >> year;
		inFile.ignore(100, ',');
		inFile >> acres;
		inFile.ignore(100, ',');
		inFile >> rating;
		inFile.ignore(100, '\n');
		
		aWinery.setName(name);
		aWinery.setLocation(location);
		aWinery.setYear(year);
		aWinery.setAcres(acres);
		aWinery.setRating(rating);
		
		insert(aWinery);
		
		inFile.get(name, 100, ',');
	}
	inFile.close();
	return;
}

list::~list(){		//destructor
	node * curr;
	node * next;
	
	//delete list by list head by name
	curr = headByName;
	while(curr != NULL){
		next = curr->nextByName;
		delete curr;
		curr = NULL;
		curr = next;
	}
}



/***************************************
 * Public functions of class list
 ***************************************/

void list::insert(winery& aWinery){
	node * curr;
	curr = headByName;
	
	node * newNode;
	newNode = new node;
	newNode->item = aWinery;
	
	//first entry in list
	if(curr == NULL){
		headByName = newNode;
		headByRating = newNode;
		newNode->nextByName = NULL;
		newNode->nextByRating = NULL;
		return;
	}
	
	//if entered item is less than head by name
	else if(headByName->item > newNode->item){
		newNode->nextByName = headByName;
		headByName = newNode;
		
		//sort rating thread
		setRating();
		sortRating();
		return;
	}
	
	//search through list
	else{
		/*
		 * Insert node in list sorted by name. When node
		 * has been inserted, sort the rating thread to set
		 * proper order for rating
		 */
		 
		node * prev;
		prev = curr; 
		 
		//search and insert by name(a to z)
		while(curr != NULL){
			if(newNode->item > curr->item){
				prev = curr;
				curr = curr->nextByName;
			}else{
				prev->nextByName = newNode;
				newNode->nextByName = curr;
				break;
			}
			//end of list reached
			if(curr == NULL){
				prev->nextByName = newNode;
				newNode->nextByName = NULL;
			}
		}
	}
	//sort rating thread
	setRating();
	sortRating();
	
	return;
	
}

void list::remove(char key[MAX_CHAR]){
	//key is the name of the winery to be removed
	node * saved;
	node * curr;
	node * prev;

	
	//if head by name is the selected item
	if(headByName->item == key){
		saved = headByName;
		headByName = headByName->nextByName;
	}
	//if head by rating is the selected item
	if(headByRating->item == key){
		saved = headByRating;
		headByRating = headByRating->nextByRating;
	}
	
	//search name list
	curr = headByName;
	prev = curr;
	while(curr != NULL){
		if(curr->item == key){
			saved = curr;
			prev->nextByName = curr->nextByName;
			break;
		}
		prev = curr;
		curr = curr->nextByName;
	}
	
	//search rating list
	curr = headByRating;
	prev = curr;
	while(curr != NULL){
		if(curr->item == key){
			prev->nextByRating = curr->nextByRating;
			break;
		}
		prev = curr;
		curr = curr->nextByRating;
	}
	
	//delete saved node after all list pointers have been rearranged
	delete saved;
	saved = NULL;
	return;
}

void list::displayByRating(void) const{
	node * curr;
	curr = headByRating;
	while(curr != NULL){
		curr->item.print();
		curr = curr->nextByRating;
	}
	return;
}

void list::displayByName(void) const{
	node * curr;
	curr = headByName;
	
	while(curr != NULL){
		curr->item.print();
		curr = curr->nextByName;
	}
	return;
}

void list::retrieve(char key[MAX_CHAR], winery& aWinery){
	/*
	Search through list and find winery by name. If winery is found
	output winery information to aWinery by reference.
	*/
	node * curr;
	curr = headByName;
	while(curr != NULL){
		if(curr->item == key){
			//copy winery in current node to aWinery
			aWinery = curr->item;
			return;
		}
	}
	/*
	If no winery matches key, create new winery object which has default
	constructor of no name, no location and 0 int/float
	*/
	winery noWinery;
	aWinery = noWinery;
	return;
}

void list::writeOut(char fileName[MAX_CHAR]){
	std::ofstream outFile;
	
	outFile.open(fileName);
	node * curr;
	curr = headByName;
	
	while(curr != NULL){
		outFile << curr->item;
		curr = curr->nextByName;
	}
	
	outFile.close();
	return;
}

const list& list::operator=(const list& aList){	//copy list by iterating through src list head by name
	if(this == &aList){
		return *this;
	}else{
		//deallocate previous memory
		node * curr;
		node * next;
		
		curr = headByName;
		while(curr != NULL){
			next = curr->nextByName;
			delete curr;
			curr = NULL;
			curr = next;
		}
		
		//if list is empty, set heads to null
		if(!aList.headByName){
			headByName = NULL;
			headByRating = NULL;
		}else{
			//first node
			node * head;
			head = new node;
			head->item = aList.headByName->item;
			headByName = head;
			headByRating = head;
			head->nextByName = NULL;
			head->nextByRating = NULL;
			
			node * src;
			node * dest;
			
			dest = headByName;
			src = aList.headByName->nextByName;
			//copy name thread
			while(src != NULL){
				dest->nextByName = new node;
				dest = dest->nextByName;
				dest->item = src->item;
				dest->nextByName = NULL;
				dest->nextByRating = NULL;
				src = src->nextByName;
			}
			
			//set rating thread = to name thread
			setRating();
			//sort rating thread
			sortRating();
		}
	}	
	return *this;
}



/****************************************
 * Private functions of class list
 ****************************************/

void list::setRating(void){	//set the rating thread = to name thread
	//set rating thread the same as name thread
	node * curr;
	node * currRating;
	
	headByRating = headByName;
	
	curr = headByName;
	currRating = headByRating;
	
	while(curr != NULL){
		currRating->nextByRating = curr->nextByName;
		curr = curr->nextByName;
		currRating = currRating->nextByRating;	
	}
	return;
}

void list::sortRating(void){	//function to sort the rating thread of list
	node * prev;	
	node * curr;
	node * next;
	
	prev = NULL;	
	curr = headByRating;
	next = curr->nextByRating;
	
	//only one node in list
	if(curr->nextByRating == NULL){
		return;
	}else{
		while(next != NULL){
			// if current is NOT less than next
			if(!(curr->item < next->item)){
				prev = curr;
				curr = next;
				next = next->nextByRating;
			}
			/*
			 * current is less than next. Swap values. If the first two 
			 * values must be swapped, prev==NULL.
			 */
			else if(prev == NULL){
				curr->nextByRating = next->nextByRating;
				next->nextByRating = curr;
				headByRating = next;
				
				prev = headByRating;
				curr = prev->nextByRating;
				next = curr->nextByRating;
				
			}else{
				prev->nextByRating = next;
				curr->nextByRating = next->nextByRating;
				next->nextByRating = curr;
				
				//reset nodes to beginning
				prev = NULL;
				curr = headByRating;
				next = curr->nextByRating;
			}
		}
	}
	return;
}




