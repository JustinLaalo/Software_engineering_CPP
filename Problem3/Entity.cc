#include "Entity.h"
//sets the loction of the entity
void Entity::setLoctation(const Location& location){
    this->location = location;
}
//constuctor for the entity
Entity::Entity(char id, int order, const string& name, const Location& location){
    this->id = id + to_string(order);
    this->location = location;
    this->name = name;
}
//returns the size of the entity
int Entity::getNumOrders()const{
    return orders.size();
}
//pops the first thing out of the queue and returns it
Order* Entity::getNextOrder(){
    Order* check = orders.popFirst();
    if(check == nullptr){
        return nullptr;
    }
    return check;
}
//adds to the end of the queue
void Entity::addOrder(Order* order){
    orders.addLast(order);
}
//prints out the loction and the order size 
void Entity::print()const{
    this->location.print();
    cout<<this->orders.size()<<endl;
}
//checks if the entity's id equals the id
bool Entity::equals(const string& id)const{
    if(this->id== id){
        return true;
    }else{
        return false;
    }
}
//returns the location of the entity
Location Entity::getLocation()const{
    return this->location;
}


