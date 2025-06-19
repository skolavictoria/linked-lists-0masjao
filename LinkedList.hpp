#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <vector>

// Класс узла (Node)
class Node {

private:
    int value;
    Node* next_member;

public:
    Node(int val);
    void add_next_member(Node* ptr);
    int get_value();
    Node* get_next_member();

    friend class LinkedList; 
};

// Класс связного списка (LinkedList)
class LinkedList {

public:
    Node* head;

    LinkedList(Node* first = nullptr);
    void push(int value);
    void append(int value);
    void insert(int position, int value);
    int pop();
    void del(int position);
    Node* eject(int position);
    int get_len();
    void reverseLinkedList();
    void sortLinkedList();
    Node* get_elem_by_index(int index);
    bool search(int value);
    void shuffle();
    void display();
    
};

#endif
