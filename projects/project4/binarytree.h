//Author: Tyler Bieker
//CS 260
//Assignment: Project 4 Binary Search Tree Class
//Date:
//Sources:

#ifndef _binarytree_
#define _binarytree_

#include "vendor.h"
#include "node.h"
#include <iostream>
#include <fstream>

class binarytree{
private:

	node * root; //root of binary search tree
	int count; //number of items in tree

	//private functions
	void add(node * dest, node * newNode);
	void destroy(node * root);	//destroy the tree
	void display(node * dest); //display by vendor name
	bool remove(char * vendorName, node * root); //remove data from tree
	void removeNode(node * root); //remove node from tree
	bool retrieve(char * searchName, vendor& aVendor, node * root);
	void copyTree(node * newRoot, node * root);
	void writeOut(std::ofstream& out, node * dest);

public:
	binarytree();
	binarytree(const binarytree& data); //copy constructor
	~binarytree();

	void add(node * newNode);	//add item to tree
	bool remove(char * vendorName);	//remove item by name from tree
	bool retrieve(char * vendorName, vendor& aVendor);	//search for vendor by name in tree and return pointer
	void display();	//display contents of tree in alphabetical order
	void writeOut(char * filename);	//write contents to file

	const binarytree& operator=(const binarytree& aTable);	//overload = operator for deep copy
};

#endif
