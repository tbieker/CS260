#include <iostream>
#include "clist.h"

using namespace std;

#pragma GCC diagnostic ignored "-Wunused-variable"

int main()
{
    node* head{nullptr};

    /* Builds a circular linked list with a random number of nodes
    *containing randomly-chosen numbers.
    */
    build(head);

    display(head);

    // PUT YOUR CODE HERE to call the functions assigned,
	// and print out the results. For example,
	//
	//    cout << "iterative sum: " << sum(head) << endl;
	//
	// The code for your functions should be in clist.cpp.

    cout << "Iterative count: " << count(head) << endl;
    cout << "Recursive count: " << countR(head) << endl;

    cout << "Iterative sum: " << sum(head) << endl;
    cout << "Recursive sum: " << sumR(head) << endl;

    // When called the 2nd time, this also prints the total
	// of the numbers in the nodes.
    display(head);


	int		nNodesFreed{0};
	node*	n{head};
	node* 	temp;

	while( n != head || ! nNodesFreed) {
		temp = n->next;
		delete n;
		n = temp;
		nNodesFreed++;

		}
	cout << "# nodes freed: " << nNodesFreed << endl;


	//destroy(head);

    return 0;
}
