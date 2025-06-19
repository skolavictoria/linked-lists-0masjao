#include "LinkedList.hpp"
#include <iostream>

using namespace std;

int main() {
    LinkedList list;
    list.push(3);
    list.push(2);
    list.push(1);

    list.display();
    
    list.reverseLinkedLists();
    list.display();

    list.sortLinkedList();
    list.display();

    return 0;
}