#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
private:
	struct node{
		char data;
		node * next;
		};

	node * head;
	node * trav;

	bool find(node *& first, char ch);
	bool del(node *& first, char ch, node *& prev);
	void add(node *& first, char ch, node *& prev);

public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);

	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);
};

#endif // _LINKED_LIST_
