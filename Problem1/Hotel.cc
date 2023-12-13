#include "Hotel.h"

Hotel:: Hotel(){
    this->numRooms = 0;
    
}
bool Hotel:: addRoom(int roomNumber, string bedType, int capacity, bool fr){
    Room* newRoom = new Room(roomNumber, bedType, capacity, fr);
    

    
    
    if(this->numRooms == MAX_ROOMS){
        delete newRoom;
        return false;
    }else{
        

        for(int i = 0; i < this->numRooms; i++){
            if(this->rooms[i]->getRoomNumber() == roomNumber){
                delete newRoom;
                return false;
            }
        }
        
        if(this->numRooms == 0){
            this->rooms[0] = newRoom;
            this->numRooms++;
            return true;
        }
        
        for(int i = 0; i < this->numRooms; i++){
            if(newRoom->lessThan(*this->rooms[i])){
                for(int j = this->numRooms;newRoom->lessThan(*this->rooms[i]) ; j--){
                    this->rooms[j]=this->rooms[j-1];
                }
                newRoom->print();
                this->rooms[i] = newRoom;
                this->numRooms++;
                return true;
                
            }
            if(i == this->numRooms-1){
                this->rooms[i+1]= newRoom;
                this->numRooms++;
                return true;
            }
            
            
            

            
    }
    delete newRoom;
    return false;
    }
}
Hotel:: ~Hotel(){
    for(int i = 0; i < this->numRooms;i++){
        delete this->rooms[i];
    }
}
bool Hotel:: deleteRoom(int roomNumber){
    for(int i = 0; i < this->numRooms; i++){
        if(this->rooms[i]->getRoomNumber() == roomNumber) {
            delete this->rooms[i];
            numRooms--;
            for(int j = i; j < this->numRooms+1; j++){
                this->rooms[j] = this->rooms[j+1];
            }
            return true;
        }
    }
    return false;
    
}
bool Hotel:: getRoom(int roomNumber,Room** room){
    for(int i = 0; i< this->numRooms; i++){
        if(this->rooms[i]->getRoomNumber() == roomNumber){
            *room = this->rooms[i];
            return true;
        }
    }
    return false;
}
bool Hotel:: addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration){
    for(int i = 0; i < this->numRooms; i++){
        if(this->rooms[i]->isMatch(bedType, capacity,fr)){
            //Reservation* res = new Reservation(customer, date,duration);
            if(this->rooms[i]->addReservation(customer, date, duration)){
                return true;
            }else{
                return false;
            }
        }
    }
    return false;
}
void Hotel:: updateReservations(Date& currentDate){
    for(int i = 0; i < this->numRooms; i++){
        this->rooms[i]->updateReservation(currentDate);
    }
}
void Hotel:: print(){
    for(int i = 0; i < this->numRooms; i++){
        this->rooms[i]->print();
    }
}
void Hotel:: printReservations(){
    for(int i = 0; i < this->numRooms; i++){
        this->rooms[i]->printReservations();
    }
}
        

