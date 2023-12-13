#include "Reservation.h"

Reservation:: Reservation(string customerName, Date& checkin, int duration){
    this->customerName = customerName;
    this->checkin = checkin;
    this->setDuration(duration);
}

void Reservation::setDuration(int duration){
    if(duration < 1){
        this->duration = 1;

    }else{
        this->duration = duration;
        }
    
}

bool Reservation:: overlaps(Reservation& r){

    Date oldcheckin = Date(this->checkin.getYear(), this->checkin.getMonth(), this->checkin.getDay());
    Date t1 = oldcheckin;
    Date newcheckin = Date(r.checkin.getYear(), r.checkin.getMonth(), r.checkin.getDay());
    Date t2 = newcheckin;
    Date oldcheckout = oldcheckin;
    Date newcheckout = newcheckin;
   
    for(int i = 0; i < this->duration; i++){
        oldcheckout.incDate();
        }
   

    for(int  j= 0; j < r.duration; j++){newcheckout.incDate();}
    

    for(int i = 0; i < this->duration; i++){
        if(t1.equals(newcheckin)){
            if(!t1.equals(oldcheckout)){
                return true;
            }
        
        }
        t1.incDate();
    }
    for(int j = 0; j < r.duration; j++){
        t2.print();

        if(t2.equals(oldcheckin)){
            oldcheckin.print();
            if(!t2.equals(newcheckout)){
                return true;  
            }
        }
        t2.incDate();
    }

    return false;
}


bool Reservation::Reservation::lessThan(Reservation& res){
    if(this->overlaps(res)){
        return false;
    }else if(this->checkin.lessThan(res.checkin) || this->checkin.equals(res.checkin)){
        return true;
    }else{
        return false;
    }
}


bool Reservation::lessThan(Date& d){
    if(this->checkin.lessThan(d)){
        return true;
    }
    return false;
}

void Reservation::print(){
    cout << "Reservation for "<<customerName << " on " << this->checkin.getMonthName()<<" "<<this->checkin.getDay()<<", "<<this->checkin.getYear()<< " for " << duration <<" days!"<<endl;
}