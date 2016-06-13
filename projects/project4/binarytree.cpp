//Author: Tyler Bieker
//CS 260
//Assignment: Project 4 Binary Search Tree Class
//Date:
//Sources:

#include "binarytree.h"

binarytree::binarytree(){
	root = nullptr;
	count = 0;
}

binarytree::binarytree(const binarytree& data){
	*this = data;
}

binarytree::~binarytree(){
	//check if tree is empty and delete if data
	if(root != nullptr){
		destroy(root);
	}
	return;
}

const binarytree& binarytree::operator=(const binarytree& aTable){

	if(this == &aTable){
		return *this;
	}else{
		//remove previous data
		destroy(root);
		//copy the tree starting at roots
		copyTree(root, aTable.root);
		return *this;
	}
}



/***********************************************************************
Public Functions
***********************************************************************/

void binarytree::add(node * newNode){
	if(root == nullptr){
		root = newNode;
		count++;
		return;
	}else{
		//new node to tree
		add(root, newNode);
		return;
	}
}

bool binarytree::remove(char * vendorName){
	bool output = false;

	//check if tree contains data
	if(root != nullptr){
		output = remove(vendorName, root);
	}
	return output;
}

bool binarytree::retrieve(char * vendorName, vendor& aVendor){	//not finished
	bool output;
	output = retrieve(vendorName, aVendor, root);
	return output;
}

void binarytree::display(){ //display vendors by name
	if(root != nullptr){
		display(root);
	}
	return;
}

void binarytree::writeOut(char * filename){
	std::ofstream out;

	out.open(filename);
	if(!out){
	  std::cout << "Failed to write to " << filename << std::endl;
	  exit(1);
	}

	if(root != nullptr){
		writeOut(out, root);
	}

	out.close();
	return;
}

void binarytree::writeOut(std::ofstream& out, node * dest){
	if(dest != nullptr){
		writeOut(out, dest->left);
		out << dest->data;
		writeOut(out, dest->right);
	}
	return;
}

/***********************************************************************
Private functions
***********************************************************************/

void binarytree::add(node * dest, node * newNode){

	//create two strings and set to vendor names
	char rootName[100];
	char newName[100];

	dest->data.getName(rootName);
	newNode->data.getName(newName);

	 if(newName < rootName){	//if newNode is less that root, add to left branch
		if(dest->left != nullptr){
			add(dest->left, newNode);
			return;
		}else{
			dest->left = newNode;
			count++;
			return;
		}
		return;
	}else{	//if newNode is greater than root, add to right branch
		if(dest->right != nullptr){
			add(dest->right, newNode);
			return;
		}else{
			dest->right = newNode;
			count++;
			return;
		}
		return;
	}
}

void binarytree::display(node * dest){
	//return if no data
	if(dest == nullptr){
		return;
	}else{
		//display left, root, right
		display(dest->left);
		dest->data.print();
		std::cout << std::endl;
		display(dest->right);
	}
	return;
}

void binarytree::destroy(node * root){
	/*
	Delete left branch
	Delete right branch
	Delete Root
	*/
	if(root->left != nullptr){
		destroy(root->left);
	}
	if(root->right != nullptr){
		destroy(root->right);
	}
	delete root;
	root = nullptr;
	return;
}

bool binarytree::remove(char * vendorName, node * root){
	//check if root contains data. Return false if no data in tree
	if(root == nullptr){
		return false;
	}

	char name[100];
	root->data.getName(name);

	//check if strings are not equal
	if(strcmp(vendorName, name) != 0){
		//check left side. return true if node was found
		if(remove(vendorName, root->left)){
			return true;
		}
		else{
			//check right side if left did not find node
			return (remove(vendorName, root->right));
		}
	}
	//return true if node was found and remove node
	else if(strcmp(vendorName, name) == 0){
		removeNode(root);
		return true;
	}
}

void binarytree::removeNode(node * root){

	//if node is leaf
	if(root->left == nullptr || root->right == nullptr){
		count--;
		//node will be deleted in hashtable
		//delete root;
		//root = nullptr;
	}
	//no left branch
	else if(root->left == nullptr){
		node * temp;
		temp = root;
		root = root->right;
		temp->right = nullptr;
		count--;

		//node will be deleted in hashtable
		//delete temp;
		//temp = nullptr;
	}
	//no right branch
	else if(root->right == nullptr){
		node * temp;
		temp = root;
		root = root->left;
		temp->left = nullptr;
		count--;

		//node will be deleted in hashtable
		//delete temp;
		//temp = nullptr;
	}
	//both branches exist
	else{
		node * prev, * curr, * temp;
		temp = root;
		prev = nullptr;
		curr = root->right;
		//find the right most branch
		while(curr->right != nullptr){
			prev = curr;
			curr = curr->right;
		}
		//set the previous node right branch to current node left
		prev->right = curr->left;
		curr->left = root->left;
		curr->right = root->right;
		root = curr;
		count--;

		//node will be deleted in hashtable
		//delete temp;
		//temp = nullptr;
	}
	return;
}

bool binarytree::retrieve(char * searchName, vendor& aVendor, node * root){
	char name[100];
	root->data.getName(name);

	if(strcmp(searchName, name) == 0){
		aVendor = root->data;
		return true;
	}else{
		if(retrieve(searchName, aVendor, root->left)){
			return true;
		}else{
			return retrieve(searchName, aVendor, root->right);
		}
	}
}

void binarytree::copyTree(node * newRoot, node * root){
	if(root != nullptr){
		newRoot = new node;
		newRoot->data = root->data;
		copyTree(newRoot->left, root->left);
		copyTree(newRoot->right, root->right);
	}else{
		//root is equal to nullptr, set new root to nullptr
		newRoot = nullptr;
	}
}
