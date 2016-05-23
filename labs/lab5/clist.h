//clist.h
#include <iostream>
#include <cstring>
#include <cctype>

struct node
{
    int		data;
    node*	next;
};

// These functions are in supplied.o and can be called from your code.
void build(node*& head);
void display(node* head);
void destroy(node* &head);
void duplicate(node*& new_copy);  //Provides a duplicate copy of the list.

// Add the prototypes for your functions below this comment.

int count(node * head); //count number of nodes iteratively
int countR(node * head); //count the number of nodes recursively
int recursiveCount(node * head, node * curr);
int recursiveSum(node * head, node * curr);

int sum(node * head); //sum all the integers in list iteratively
int sumR(node * head); //sum all the integers in list recursively
