#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
//lab 4 changed character to integer

private:
	struct node{
		int data;
		node * next;
		};

	node * head;
	node * trav;

	//lab 3 private functions
	bool find(node *& first, int ch);
	bool del(node *& first, int ch, node *& prev);
	void add(node *& first, int ch, node *& prev);

	//lab 4 private functions
	int sumRec(node * curr, int& x);

public:
	LinkedList();
	~LinkedList();

	//lab 3 functions
	void add(int ch);
	bool find(int ch);
	bool del(int ch);

	//lab 4 functions
	int sum(void);	//iteratively add list
	int sumR(void);	//recursively add list

	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);
};

#endif // _LINKED_LIST_
