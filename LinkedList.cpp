//
// Created by Alexander Allis on 9/1/22.
//

#include <vector>
#include "Node.h"
#include "LinkedList.h"


LinkedList::LinkedList() {
    this -> listPointer = nullptr;
    this -> tail = nullptr;
}

LinkedList::LinkedList(std::vector<int> list) {
    for(int i = 0; i < list.size(); i++) {
        addTail(list.at(i));
    }
}

void LinkedList::add(int data) {
    Node* nodePointer = new Node;
    if (listPointer == nullptr) this -> tail = nodePointer;  // if first node created, set tail
    nodePointer->data = data;
    nodePointer->next = listPointer;
    listPointer = nodePointer;
}

void LinkedList::addTail(int data) {
    if (listPointer == nullptr) {
        add(data);  // if the list is isEmpty, invoke the normal add member function
        return;
    }
    else{
        Node* nodePointer = new Node;
        nodePointer -> data = data;
        this -> tail -> next = nodePointer;
        this -> tail = nodePointer;
        return;
    }
}

int LinkedList::isEmpty() const {
    if (this -> listPointer != nullptr) return 1;
    else return 0;
}

int LinkedList::hasNext() const {
    if (this -> listPointer != nullptr && this->listPointer->next != nullptr) return 1;
    else return 0;
}

int LinkedList::pop() {
    Node* tmp = listPointer;
    listPointer = listPointer -> next;
    return (tmp -> data);
}

void LinkedList::clearList() {
    Node* next;
    while(listPointer != nullptr){
        next = listPointer -> next;
        delete listPointer;
        listPointer = next;
    }
}