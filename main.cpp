#include "LinkedList.hpp"
#include <iostream>

using namespace std;

int main() {
    LinkedList list;

    // Тест push
    list.push(3);
    list.push(2);
    list.push(1);
    cout << "After push: ";
    list.display();

    // Тест append
    list.append(4);
    list.append(5);
    cout << "After append: ";
    list.display();

    // Тест insert
    list.insert(2, 99);
    cout << "After insert at position 2: ";
    list.display();

    // Тест pop
    int popped = list.pop();
    cout << "Popped value: " << popped << endl;
    list.display();

    // Тест del
    list.del(2);
    cout << "After deleting position 2: ";
    list.display();

    // Тест eject
    Node* node = list.eject(1);
    cout << "Ejected value at position 1: " << node->get_value() << endl;
    delete node;
    list.display();

    // Тест get_elem_by_index
    Node* elem = list.get_elem_by_index(1);
    if (elem) cout << "Element at index 1: " << elem->get_value() << endl;

    // Тест search
    cout << "Search 5: " << (list.search(5) ? "Found" : "Not Found") << endl;

    // Тест reverse
    list.reverseLinkedList();
    cout << "After reverse: ";
    list.display();

    // Тест sort
    list.sortLinkedList();
    cout << "After sort: ";
    list.display();

    // Тест shuffle
    list.shuffle();
    cout << "After shuffle: ";
    list.display();

    return 0;
}