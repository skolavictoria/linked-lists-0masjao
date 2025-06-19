#include "LinkedList.hpp"
#include <iostream>
using namespace std;

//Node
Node::Node(int val) : value(val), next_member(nullptr) {}

void Node::add_next_member(Node* ptr) {
    next_member = ptr;

}

int Node::get_value() {
    return value;

}

Node* Node::get_next_member() {
    return next_member;

}

LinkedList::LinkedList(Node* first) : head(first) {}

void LinkedList::push(int value) {
    Node* new_node = new Node(value);
    new_node->add_next_member(head);
    head = new_node;

}

//LinkedList
void LinkedList::append(int value) {
    Node* new_node = new Node(value);
    if (!head) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->get_next_member())
        temp = temp->get_next_member();
    temp->add_next_member(new_node);
}

void LinkedList::insert(int position, int value) {
    if (position < 0) return;
    if (position == 0) return push(value);

    Node* temp = head;
    for (int i = 0; i < position - 1 && temp; ++i)
        temp = temp->get_next_member();

    if (!temp) return;

    Node* new_node = new Node(value);
    new_node->add_next_member(temp->get_next_member());
    temp->add_next_member(new_node);
}

int LinkedList::pop() {
    if (!head) return -1;
    int val = head->get_value();
    Node* temp = head;
    head = head->get_next_member();
    delete temp;
    return val;
}

void LinkedList::del(int position) {
    if (position < 0 || !head) return;
    if (position == 0) {
        Node* temp = head;
        head = head->get_next_member();
        delete temp;
        return;
    }

    Node* prev = head;
    for (int i = 0; i < position - 1 && prev; ++i)
        prev = prev->get_next_member();

    if (!prev || !prev->get_next_member()) return;

    Node* temp = prev->get_next_member();
    prev->add_next_member(temp->get_next_member());
    delete temp;
}

Node* LinkedList::eject(int position) {
    if (position < 0 || !head) return nullptr;
    if (position == 0) {
        Node* temp = head;
        head = head->get_next_member();
        temp->add_next_member(nullptr);
        return temp;
    }

    Node* prev = head;
    for (int i = 0; i < position - 1 && prev; ++i)
        prev = prev->get_next_member();

    if (!prev || !prev->get_next_member()) return nullptr;

    Node* target = prev->get_next_member();
    prev->add_next_member(target->get_next_member());
    target->add_next_member(nullptr);
    return target;
}

int LinkedList::get_len() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->get_next_member();
    }
    return count;
}

void LinkedList::reverseLinkedList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) {
        next = current->get_next_member();
        current->add_next_member(prev);
        prev = current;
        current = next;
    }

    head = prev;
}

void LinkedList::sortLinkedList() {
    if (!head || !head->get_next_member()) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->get_next_member()) {
            Node* next = current->get_next_member();
            if (current->get_value() > next->get_value()) {
                swap(current->value, next->value);
                swapped = true;
            }
            current = next;
        }
    } while (swapped);
}

void LinkedList::display() {
    Node* temp = head;
    while (temp) {
        cout << temp->get_value() << " ";
        temp = temp->get_next_member();
    }
    cout << endl;
}