

#include <iostream>
#include "table.h"

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
    cout << endl;
    cout << "Number of nodes: " << count(root) << endl;
    cout << "Sum of all nodes: " << sum(root) << endl;
    cout << "Height of the tree: " << height(root) << endl;
    cout << endl;


    display(root);
    destroy(root);
    return 0;
}
