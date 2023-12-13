#include "Franchise.h"
//initalizes the static member variables
const string Franchise::menu[MENU_ITEMS]={"1. Large Poutine", "2. Medium Poutine", "3. Small Poutine"};
int Franchise::nextId = 0;
const char Franchise::code = 'F';

//constructor for franchise and increase id to make sure it is unique and uses member intalization since it inherits from entity
Franchise::Franchise(const string& name, const Location& location):Entity(code, nextId,name, location){
    nextId++;
}
//returns the menu item at a given index if it is valid
string Franchise::getMenu(int index){
    if(index < 3 || index < 0){
        return "Invalid menu option";
    }
    else{
        return menu[index];
    }
}
//prints out the location, order size and id of the franchise
void Franchise::print()const{
    this->location.print();
    cout<<this->orders.size()<<this->id<<endl;
}
//prints out all the menu items
void Franchise::printMenu(){
    for(int i = 0; i < 3; i++){
        cout<<menu[i]<<endl;
    }
}