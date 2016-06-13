//Author: Tyler Bieker
//CS 260
//Assignment: Project 4 Collection Class
//Date:
//Sources:

//collection.cpp

#include "collection.h"

/*
Constructors
*/

collection::collection(){
	return;
}

collection::collection(const collection& aCollection){
	*this = aCollection;
	return;
}

collection::collection(char * filename){
  std::ifstream inFile;

  inFile.open(filename);

  if(!inFile){
  std::cout << "Failed to open" << std::endl;
  exit(1);
  }

  std:: cout << "File opened..." << std:: endl;

  vendor aVendor;
  char name[100];
  char phoneNumber[100];
  char product[100];
  char events[100];

  inFile.get(name, 100, ',');
  while(!inFile.eof()){
    inFile.ignore(100, ',');
    inFile.get(phoneNumber, 100, ',');
    inFile.ignore(100, ',');
    inFile.get(product, 100, ',');
    inFile.ignore(100, ',');
    inFile.get(events, 100, '\n');
    inFile.ignore(100, '\n');

    aVendor.setName(name);
    aVendor.setNumber(phoneNumber);
    aVendor.setProduct(product);
    aVendor.setEvents(events);

	//create node to store data
	node * newNode;
	newNode = new node;
	newNode->data = aVendor;

	//add data to tree and hashtable
    tree.add(newNode);
	table.add(newNode);

	inFile.get(name, 100, ',');
  }
  inFile.close();
  return;
}

collection::~collection(){
	return;
}

/*
Public Functions
*/

void collection::add(const vendor& aVendor){
	node * newNode;
	newNode = new node;
	newNode->data = aVendor;
	newNode->left = nullptr;
	newNode->right = nullptr;

	tree.add(newNode);
	table.add(newNode);
	return;
}

bool collection::remove(char * vendorName){
	/*
	link will be removed from tree but not deleted. link will be deleted
	in hashtable
	*/
	if(tree.remove(vendorName)){
		return table.remove(vendorName);
	}else{
		return false;
	}
}

bool collection::retrieveByName(char * vendorName, vendor& aVendor){	//search for vendor by name
	bool result;
	result = tree.retrieve(vendorName, aVendor);
	return result;
}

bool collection::retrieveByProduct(char * productType, vendor& vendors){
	bool result;
	result = table.retrieve(productType, vendors);
	return result;
}

void collection::displayByType(){
	table.display(); //table is sorted by product
	return;
}

void collection::displayByName(){
	tree.display();	//tree is sorted by name
	return;
}

void collection::writeOut(char * filename){
	/*
	Write out file using binary tree so vendors are in
	alphabetical order
	*/
	tree.writeOut(filename);
	return;
}

const collection& collection::operator=(const collection& aCollection){
	//create deep copies of tree and table
	this->tree = aCollection.tree;
	this->table = aCollection.table;
	return *this;
}
