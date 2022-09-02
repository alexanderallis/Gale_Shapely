//
// Created by Alexander Allis on 9/1/22.
//

#ifndef GALE_SHAPELY_LINKEDLIST_H
#define GALE_SHAPELY_LINKEDLIST_H


class LinkedList {
    public:
        LinkedList();
        void add(int);
        int* pop();
        int empty() const;

        Node* listPointer{};

    private:
        int hasNext() const;
};



#endif //GALE_SHAPELY_LINKEDLIST_H
