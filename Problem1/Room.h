
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

#include "Reservation.h"
#include "defs.h"




using namespace std;

class Room{
	
	public:
                Room(int roomNumber, string bedType, int capacity, bool hasFridge);


                int getRoomNumber();

                bool isMatch(string bt, int cap, bool f);

                bool lessThan(Room& r);

                bool addReservation(string customerName, Date& d, int duration);

                void printReservations();
                        
                ~Room();

                void updateReservation(Date& currentDate);

                void print();

        

	
	private:
		int roomNumber;
                string bedType;
                int capacity;
                bool hasFridge; 

                int numReservations;

                Reservation* reservations[MAX_RES];

	
};
#endif
