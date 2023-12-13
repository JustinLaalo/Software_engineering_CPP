
#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Date.h"




using namespace std;

class Reservation{
	
	public:
    
		Reservation(string customerName, Date& checkin, int duration);

        void setDuration(int duration);

        bool overlaps(Reservation& r);

        bool lessThan(Reservation& res);

        bool lessThan(Date& d);

        void print();

        

	
	private:
		string customerName;
        Date checkin;
        int duration;

		
		
	
};
#endif
