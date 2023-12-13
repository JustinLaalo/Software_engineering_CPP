#include "Album.h"
//Album acts as a wrapper class of PhotoArray
//album constuctor that takes in 2 parameters
Album::Album(string title, string description){
    this->title = title;
    this->description = description;
    //dynamically allocates memory that points to a PhotoArray object
    this->photoArray = new PhotoArray[MAX_ARRAY];
    
    
}
//destructor
Album::~Album(){
    //frees the memory allocated to the PhotoArray
    delete [] this->photoArray;
    
}
//copy constructor
Album::Album(const Album& alb){
    this->title = alb.title;
    this->description = alb.description;
    //since it is dynamically allocating memory we need to use new and create a new PhotoArray and then new photos into it
    this->photoArray = new PhotoArray[MAX_ARRAY];
    for(int i = 0; i < alb.photoArray->size(); i++){
        Photo* newPhoto = new Photo(*alb.getPhoto(i));
        photoArray->add(newPhoto);
    } 
}
//gets the title of the album
string Album::getTitle() const{
    return this->title;
}
//returns true if the album titles are equal
bool Album::equals(const string& title)const{
    if(this->title == title){
        return true;

    }else{
        return false;
    }
}
//compares the albums titles to see if one is less than the other
bool Album::lessThan(const Album& alb)const{
    if(this->title.compare(alb.title) < 0){
        return true;
    }else{
        return false;
    }
}
//adds a new photo to the album
bool Album::addPhoto(Photo* photo){
    return this->photoArray->add(photo);
}
//adds a new Photo to the album at a given index
bool Album::addPhoto(int index, Photo* photo){
    return this->photoArray->add(index, photo);
}
//gets the photo at a given index
Photo* Album::getPhoto(int index)const {
    return this->photoArray->get(index);
}
//gets the photo with the given title
Photo* Album::getPhoto(const string& title)const{
    return this->photoArray->get(title);
}
//removes a photo from the album at a given index
Photo* Album::removePhoto(int index){
    return this->photoArray->remove(index);
}
//removes a photo from the album with the given title
Photo* Album::removePhoto(const string& title){
    return this->photoArray->remove(title);
}
//prints the album
void Album::print()const{
    cout << "Title: " << this->title << " Description: "<<this->description<<endl;
}
//prints the album and its contents
void Album::display()const{
    print();
    for(int i = 0; i < (this->photoArray)->size(); i++){
        (this->photoArray)->get(i)->display();
    }
}
//returns the size of the album
int Album::size()const{
    return this->photoArray->size();
}