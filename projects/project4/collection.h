//Author: Tyler Bieker
//CS 260
//Assignment: Project 4 Collection Class
//Date:
//Sources:

//collection.h

#ifndef _COLLECTION_
#define _COLLECTION_

#include "vendor.h"
#include "binarytree.h"
#include "hashtable.h"
#include "node.h"

class collection{
private:
	binarytree tree;			//sorted by name
	hashTable table;	//sorted by product

public:
    collection();
    collection(const collection& aCollection);   //copy constructor
    collection(char * filename); //constructor to load from file
    ~collection();

    void add(const vendor& aVendor); //add vendor to collection
    bool remove(char * vendorName);  //search vendors and remove by name
    bool retrieveByName(char * vendorName, vendor& aVendor); //search for vendor by name
    bool retrieveByProduct(char * productType, vendor& vendors); //search for vendor by product type. May return more than one value
    void displayByType(); //Display all vendors sorted by product type
    void displayByName(); //Display all vendors by name

	void writeOut(char * filename); //write collection to file

	const collection& operator=(const collection& aCollection);
};

#endif
