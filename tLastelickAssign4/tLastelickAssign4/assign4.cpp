#include <iostream>
#include "LinkedList.h"

using namespace std;



int main()
{
    // create a list
    LinkedList<int> list;
    list.appendNode(5);
    list.appendNode(55);
    list.appendNode(525);
    list.appendNode(5000);
    list.appendNode(99);
    list.appendNode(955);
    
    cout << "List in reverse order" << endl;
    list.printListReverse();     
    cout << "List in ascending order" << endl;
    list.printList();
    cout << "Total number of nodes: " << list.totalNodes() << endl;
    cout << "List in ascending order skipping every other node : " << endl;
    list.skipPrint();
    cout << "Searching if value 525 exists in list : " << list.searchNodes(525) << endl;
    cout << "Searching if value 599 exists in list : " << list.searchNodes(599) << endl;

    return 0;
}
