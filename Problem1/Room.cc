#include "Room.h"


Room:: Room(int roomNumber, string bedType, int capacity, bool hasFridge){
    this->roomNumber = roomNumber;
    this->bedType = bedType;
    this->capacity = capacity;
    this->hasFridge = hasFridge;
    this->numReservations = 0;


}

int Room:: getRoomNumber(){return this->roomNumber;}

bool Room:: isMatch(string bt, int cap, bool f){
    if(this->bedType == bt){
        if(this->capacity >= cap){
                    if(f == true){
                        if(this->hasFridge){
                            return true;
                        }else{
                            return false;
                        }
                    }else{
                        return true;
                    }
        }
    }
    return false;
}
Room:: ~Room(){
    for(int i = 0; i < this->numReservations;i++){
        delete this->reservations[i];
    }
}
bool Room:: lessThan(Room& r){
    if(this->roomNumber < r.roomNumber){
        return true;
    }
    return false;
}

bool Room:: addReservation(string customerName, Date& d, int duration){
    Reservation* newReservation = new Reservation(customerName, d, duration);
    if(this->numReservations == MAX_RES){
        delete newReservation;
        return false;
    }else{
        
        for(int i = 0; i < this->numReservations; i++){
            if(this->reservations[i]->overlaps(*newReservation)){
                delete newReservation;
                return false;
            }
        }

        if(this->numReservations == 0){
            this->reservations[0] = newReservation;
            this->numReservations++;
            return true;
        }

        for(int i = 0; i < this->numReservations; i++){
            if(newReservation->lessThan(*this->reservations[i])){
                for(int j = this->numReservations+1; j > i; j--){
                    this->reservations[j]=this->reservations[j-1];
                }
                this->reservations[i] = newReservation;
                this->numReservations++;
                return true;
                
            }
            if(i == this->numReservations-1){
                this->reservations[i+1]= newReservation;
                this->numReservations++;
                return true;
            }
            
    }
    
    }
    delete newReservation;
    return false;
}
void Room::print(){
    cout << "Number of Reservations: " << numReservations << "Capacity: " << capacity << "Room Number: " << roomNumber << "BedType: " << bedType <<"Fridge: " << this->hasFridge <<endl;  
}
void Room:: printReservations(){
    print();
    
    for(int i = 0; i < this->numReservations; i++){
        this->reservations[i]->print();
    }
}
// void Room:: print(){
//     cout<<this->hasFridge<<this->roomNumber<<this->capacity<<this->bedType<<endl;
// }


void Room:: updateReservation(Date& currentDate){
    int counter = 0;
    for(int i = 0; i < this->numReservations; i++){
        if(this->reservations[i]->lessThan(currentDate)){
            counter++;
        }
    }
    int counter2 = 0;
    for(int i = counter; i < this->numReservations; i++){
        delete this->reservations[counter2];
        this->reservations[counter2] = this->reservations[i];
        counter2++;
    }
    this->numReservations = this->numReservations - counter;
}


 
