#include "PhotoGram.h"
//defualt constructor for PhotoGram
PhotoGram::PhotoGram(){
    //dynamically allocate memory for a pointer to a AlbumArray object
    this->albumArray = new AlbumArray[MAX_ARRAY];
}
//destructor 
PhotoGram::~PhotoGram(){
    //goes through the array and frees the memory alocated from the album in the array
    for(int i = 0; i < this->albumArray->size(); i++){
        delete this->albumArray->get(i);
    }
    //frees the pointer to the array
    delete[] this->albumArray;
}
//adds a new album to the AlbumArray with the given title and description
bool PhotoGram::addAlbum(const string& title, const string& description){
    //checks to the see the array is full
    if(this->albumArray->size()==MAX_ARRAY){
        return false;
    }
    //call copy constuctor to create a new Album object
    Album* album = new Album(title, description);
    //adds the new album to the array
    albumArray->add(album);
    return true;
}
//removes the album with the given title from the AlbumArray
bool PhotoGram::removeAlbum(const string& title){
    int point = 0;
    //finds the album where the title is equal to the given title
    for(int i= 0; i<albumArray->size(); i++){
        if(albumArray->get(i)->equals(title)){
            //creates a new album pointer so we can save the removes album
            Album* alb2;
            alb2 = this->albumArray->remove(i);
            //checks to see if the pointer is null
            if(alb2!=NULL){
                //if not it will delete the created pointer
                delete alb2;
                return true;
            }
        }
    }
    return false;
    
}
//adds a new photo to the album with the given title
bool PhotoGram::addPhoto(const string& title, Photo photo){
    //checks to see if the array is full
    if(this->albumArray->size()==MAX_ARRAY){
        return false;
    }
    //goes through the array and find the album with the given title
    for(int i = 0; i < this->albumArray->size(); i++){
        if(this->albumArray->get(i)->equals(title)){
            //creates a new photo pointer with the photo parameter
            Photo* photo2= new Photo(photo);
            //adds to the album
            this->albumArray->get(i)->addPhoto(photo2);
            return true;
        }
    }
    return false;
}
//removes the photo with the given title from the album with the given title
bool PhotoGram::removePhoto(const string& title, const string& photoTitle){
    //checks to see if the array is full
    if(this->albumArray->size()==MAX_ARRAY){
        return false;
    }
    //finds the album with the given title
    for(int i = 0; i < this->albumArray->size(); i++){
        
        if(this->albumArray->get(i)->equals(title)){
            //creates a new photo pointer
            Photo* photo2;
            //sets the new photo pointer to the photo pointer returned by the remove function
            photo2 = this->albumArray->get(i)->removePhoto(photoTitle);
            //checks to see if the pointer is null
            if(photo2!= NULL){
                //if not it will delete the created pointer
                delete photo2;
                return true;
            }else{
                return false;
            }
            

        }
    }
    return false;
    
    
    
    
}
//returns the album with the given title
Album* PhotoGram::downloadAlbum(const string& title) const{
    //loops through the array and finds the album with the given title
    for(int i = 0; i < albumArray->size(); i++){
        if(this->albumArray->get(i)->equals(title)){
            return this->albumArray->get(i);
        }
    }
    return NULL;
}
//returns the photo with the gien title in the album with the given title
Photo* PhotoGram::downloadPhoto(const string& title, const string& photoTitle) const{
    //find the album with the given title
    for(int i = 0; i < this->albumArray->size(); i++){
        if(this->albumArray->get(i)->equals(title)){
            //finds the photo with the given title
            return this->albumArray->get(i)->getPhoto(photoTitle);
        }
    }
    return NULL;
}
//prints the albums in the array
void PhotoGram::printAlbums() const{
    for(int i = 0; i < this->albumArray->size(); i++){
        this->albumArray->get(i)->print();
    }
}
//displays the albums in the array
void PhotoGram::displayAlbums() const{
    for(int i = 0; i < this->albumArray->size(); i++){
        this->albumArray->get(i)->display();
    }
}