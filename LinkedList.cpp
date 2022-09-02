//
// Created by Alexander Allis on 9/1/22.
//

#include <iostream>

#include "Node.h"
#include "LinkedList.h"


LinkedList::LinkedList() {
    this -> listPointer = nullptr;
}

void LinkedList::add(int data) {
    Node* nodePointer = new Node;
    nodePointer->data = data;
    nodePointer->next = listPointer;
    listPointer = nodePointer;
}

int LinkedList::empty() const {
    if (this -> listPointer != nullptr) return 1;
    else return 0;
}

int LinkedList::hasNext() const {
    if (this -> listPointer != nullptr && this->listPointer->next != nullptr) return 1;
    else return 0;
}

int* LinkedList::pop() {
    if (listPointer == nullptr) {
        return nullptr;
    }
    else{
        Node* tmp = listPointer;
        listPointer = listPointer -> next;
        return &(tmp -> data);
    }
}