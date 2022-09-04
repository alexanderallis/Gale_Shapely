//
// Created by Alexander Allis on 9/1/22.
//

#ifndef GALE_SHAPELY_LINKEDLIST_H
#define GALE_SHAPELY_LINKEDLIST_H

#include <vector>
#include "Node.h"

class LinkedList {
    public:
        LinkedList();
        explicit LinkedList(std::vector<int>);
//        ~LinkedList();
        void add(int);
        void addTail(int);
        int pop();
        int isEmpty() const;

    private:
        Node* listPointer{};
        Node* tail{};
        int hasNext() const;
};



#endif //GALE_SHAPELY_LINKEDLIST_H
