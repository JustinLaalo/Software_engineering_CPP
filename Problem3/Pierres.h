#ifndef PIERRES_H
#define PIERRES_H

#include <iostream>
#include <string>
#include <vector>
#include "Driver.h"
#include "Franchise.h"
using namespace std;

class Pierres{
    public:
        //destructor
        ~Pierres();
        //functions
        void addDriver(const string& name, const Location& location);
        void addFranchise(const string& name, const Location& location);
        void takeOrder(const string& customerName, int menuItem, const Location& location)const;
        void driverPickup(const string& franchiseId, int numOrders)const;
        void driverDeliver(const string& driverId, int numOrders)const;
        void printFranchises()const;
        void printDrivers()const;


    

    private:
        //collection of drivers
        vector<Driver*> drivers;
        vector<Franchise*> franchises;
        
};

#endif