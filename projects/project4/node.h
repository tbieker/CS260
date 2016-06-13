//Author: Tyler Bieker
//CS 260
//Assignment: Project 4 Node Struct Definition
//Date:
//Sources:

//node.h

#ifndef _NODE_
#define _NODE_

struct node{
    vendor data;
    node * left;    //tree left
    node * right;   //tree right
    node * next;    //hashtable next
};

#endif
