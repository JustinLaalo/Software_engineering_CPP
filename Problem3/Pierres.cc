#include "Pierres.h"
//deallocates all the memory from each collection, loops over each colleciton and delete each of its elements
Pierres::~Pierres(){
    for(int i = 0; i<franchises.size();i++){
        delete franchises.at(i);
    }
    for(int i = 0; i<drivers.size();i++){
        delete drivers.at(i);
    }
}
//adds a new driver with the given parameters to the collection of drivers
void Pierres::addDriver(const string& name, const Location& location){
    this->drivers.push_back(new Driver(name, location));
}
//adds a new franchise with the given parameters to the collection of franchises
void Pierres::addFranchise(const string& name, const Location& location){
        this->franchises.push_back(new Franchise(name, location));
}
//finds the franchise that is the closest to the given location and adds a order to it
void Pierres::takeOrder(const string& customerName, int menuItem, const Location& location)const{
    Order* order = new Order(customerName,menuItem,location);
    int closest = -1;
    int index; 
    for(int i = 0; i < franchises.size(); i++){
        if(franchises.at(i)->getLocation().getDistance(location) < closest || closest  == -1){
            closest = franchises.at(i)->getLocation().getDistance(location);
            index = i;
        }
    }
    franchises.at(index)->addOrder(order);

}
//finds a franchise if it exists and the finds the closest driver to the franchise. After it will transfer the orders from the franchise to the driver 
void Pierres::driverPickup(const string& franchiseId, int numOrders)const{
    int closest = -1;
    int index = -1; 
    int found = 0;
    for(int i = 0; i < franchises.size(); i++){
        if(franchises.at(i)->equals(franchiseId)){
            for(int j = 0; j < drivers.size(); j++){
                //base case, since nothing will be smaller than the preset value of -1
                if(closest == -1){
                    closest = drivers.at(j)->getLocation().getDistance(franchises.at(i)->getLocation());
                    index = j;
                }else if(drivers.at(j)->getLocation().getDistance(franchises.at(i)->getLocation()) < closest && drivers.at(j)->isFree()){
                    index = j;
                }
            }
            //sets driver location to franchise location
            drivers.at(index)->setLoctation(franchises.at(i)->getLocation());
            //transfer number orders from franchise to driver
            if(numOrders >= franchises.at(i)->getNumOrders()){
                numOrders = franchises.at(i)->getNumOrders();
            }
            for(int k = 0; k < numOrders; k++){
                drivers.at(index)->addOrder(franchises.at(i)->getNextOrder());
            }
            found = 1;
            break;

        }
    }
    if(found == 0){
        cout<<"There is no franchise with that id"<<endl;
    }
}
//find s delivers the order from driver
void Pierres::driverDeliver(const string& driverId, int numOrders)const{
    int found = 0;
    for(int i = 0; i < drivers.size();i++){
        //finds the driver with the given id
        if(drivers.at(i)->equals(driverId)){
            //checks if numOrders is valid
            if(numOrders >= drivers.at(i)->getNumOrders()){
                numOrders = drivers.at(i)->getNumOrders();
            }
            //loops through all the orders of the driver and delivers them 
            for(int k = 0; k < numOrders; k++){
                Order* order = drivers.at(i)->getNextOrder();
                drivers.at(i)->setLoctation(order->getLocation());
                cout<<"Dilivering"<<endl;
                order->print();
                delete order;
            }
            found = 1;
            break;
            
        }
    }
    if(found == 0){
        cout<<"There is no driver with that id"<<endl;
    }
    
}
//prints out franchises in the collection
void Pierres::printFranchises()const{
    for(int i = 0; i < franchises.size(); i++){
        franchises.at(i)->print();
    }
}
//prints out the driver in the collection
void Pierres::printDrivers()const{
    for(int i = 0; i < drivers.size(); i++){
        drivers.at(i)->print();
    }
}