#include "Photo.h"
//constructor of the photo class that takes in 3 parameters
Photo::Photo(const string& title, const Date& date, const string& content){
    this->title = title;
    this->date = date;
    this->content = content;
}
//checks to see if the photos title is equal to the current instances of the photos title
bool Photo::equals(const string& title)const{
    if(this->title == title){
        return true;
    }else{
        return false;
    }
}
//////////////////
//returns the photo's title
string Photo::getTitle() const{
    return this->title;
}
//returns the photo's date
Date Photo::getDate()const {
    return this->date;
}

/////////////////////
//prints the photo's data excluding the content
void Photo::print() const{
    cout<<"Title: "<<this->title<<endl;
    this->date.print();
}
//prints out all the data of the photo
void Photo::display() const{
    //calls the print function
    print();
    cout<<"Content: "<<this->content<<endl;
}