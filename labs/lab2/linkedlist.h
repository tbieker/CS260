#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList& list);
	~LinkedList();

	void add(char ch);
	bool find(char ch) const;
	bool del(char ch);

	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);

private:
	struct node{
		char item;
		node * next;
	};
	node * head;
	node * trav;
};

#endif // _LINKED_LIST_
