

#include "Driver.h"
//initalizes static member variables
const char Driver::code = 'D';
int Driver::nextId = 0;
//constructor for Driver class, increase the nextId to insure it is unique and uses member initalization for Entity since it inherits from entity 
Driver::Driver(const string& name, const Location& location):Entity(code, nextId,name, location){
    
    nextId++; 
}
//checks if the driver is free
bool Driver::isFree()const{
    if(this->orders.size()==0){
        return true;
    }
    return false;
}
//prints out the location, order size and the id
void Driver::print()const{
    this->location.print();
    cout<<this->orders.size()<<this->id<<endl;
}