#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include "Location.h"
using namespace std;

class Order {
    public:
        //constuctor 
        Order(const string& cust_name, int menuItem, const Location& location);
        //functions
        const Location& getLocation()const;
        void print() const;
    private:
        string custName;
        int menuItem;
        Location location;
};

#endif