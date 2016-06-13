#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << endl;
    cout << "Number of nodes that contains even number in doubly linked list: " << countEven(head) << endl;
    cout << "After removing the nodes that contain even numbers: " << removeEven(head) << endl;

    display(head);
    destroy(head);
    return 0;
}
