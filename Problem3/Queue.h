#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include "Order.h"
using namespace std;


class Queue{
    //class for Node (specifiys what a node is)
    class Node{
        public:
            //a node will have data and a pointer to the next node (single way not double-linked list)
            Order* data;
            Node* next;
    };

    public:
        //constuctor
        Queue();
        //destructor
        ~Queue();
        //functions
        bool empty() const;
        int size() const;
        Order* peekFirst()const;
        Order* popFirst();
        void addLast(Order* order);
    private:
        Node* head;
        Node* tail;
        int totalSize;

};


#endif