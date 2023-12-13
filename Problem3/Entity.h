#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

class Entity {
    public:

        
        //constuctor 
        Entity(char id, int orders, const string &name, const Location& location);
        //functions
        Location getLocation()const;
        void setLoctation(const Location& location);
        Order* getNextOrder();
        void addOrder(Order *o);
        int getNumOrders()const;
        void print()const;
        bool equals(const string& id)const;
    protected:
        string id;
        string name;
        Location location;
        Queue orders;
};

#endif