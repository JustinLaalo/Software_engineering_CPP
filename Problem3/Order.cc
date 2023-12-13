#include "Order.h"
//constuctor for Order class
Order::Order(const string& name, int menuInt, const Location& location){
    this->custName = name;
    this->menuItem = menuInt;
    this->location = location;
}
//returns the location
const Location& Order::getLocation()const{
    return this->location;
}
//prints out the customer name and menuitem
void Order::print()const{
    cout<<this->custName<<this->menuItem<<endl;
}

