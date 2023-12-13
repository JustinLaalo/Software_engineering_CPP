#include "PhotoArray.h"
//defalt constructor of the PhotoArray
PhotoArray::PhotoArray(){
    //creates an array of Photo Pointers with a size of MAX_ARRAY, this is also dynamically allocated
    this->photos = new Photo*[MAX_ARRAY];
    this->numPhotos = 0;

}
//checks to see if the PhotoArray is full
bool PhotoArray::isFull()const{
    if(this->numPhotos==MAX_ARRAY){
        return true;
    }else{
        return false;
    }
}
//deallocates the photos and the array itself 
PhotoArray::~PhotoArray(){
    //goes through the array and frees all the pointers to the photos
    for(int i=0;i<this->numPhotos;i++){
        delete this->photos[i];
    }
    //frees the array
    delete [] this->photos;
}
//adds a photo to the array if the array is not full
bool PhotoArray::add(Photo* photo){
    if(isFull()){
        return false;
    }
    this->photos[this->numPhotos] = photo;
    this->numPhotos++;
    return true;
}
//adds a photo to the array at a specific index if the array is not full and the index is valid 
bool PhotoArray::add(int index, Photo* photo){
    if(isFull()){
        return false;
    }
    if(index<0||index>this->numPhotos){
        return false;
    }
    //shifts all the pointers to the right from the back
    for(int i = this->numPhotos-1; i >= index; i--){
        this->photos[i+1] = this->photos[i];
    }
    //adds at the index
    this->photos[index] = photo;
    this->numPhotos++;

    return true;
}
//finds a specific photo in the array with the given title
Photo* PhotoArray::get(const string& title)const{
    for(int i = 0; i < this->numPhotos; i++){ 
        //calls the equal function to compare the titles
        if(this->photos[i]->equals(title)){
            return this->photos[i];
        }
    }
    return NULL;

}
//gets the photo at the given index
Photo* PhotoArray::get(int index) const{
    if(index<0 || index>=this->numPhotos){
        return NULL;
    }
    return this->photos[index];
}

//finds the index where the titles equal and set the index to that point in the array, then it saves the photo values so we can return it
Photo* PhotoArray::remove(const string& title){
    int index = -1;
    //creates a new photo since when we remove it, we wont have a pointer to it anymore
    Photo* recentPhoto = NULL;
    //finds the index where the titles equal
    for(int i = 0; i < this->numPhotos-1; i++){
        if(this->photos[i]->equals(title)){
            index = i;
            recentPhoto = this->photos[i];
        }
    }
    //if the photo was not found checks the last index
    if(index == -1){
        if(this->photos[this->numPhotos]->equals(title)){
            index = this->numPhotos;
            recentPhoto = this->photos[this->numPhotos];
        }
        else{
            return NULL;
        }
    }
    //removes the photo from the array
    for(int i = index; i < this->numPhotos; i++){
        this->photos[i] = this->photos[i+1];
    }
    this->numPhotos--;
    return recentPhoto;
}
//removes the photo at the given index from the array
Photo* PhotoArray::remove(int index){
    if(index<0 || index>=this->numPhotos){
        return NULL;
    }
    //creates a new photo since when we remove it, we wont have a pointer to it anymore
    Photo* recentPhoto = this->photos[index];
    //goes through the array from the index given and shifts all the pointers to the left
    for(int i = index; i < this->numPhotos-1; i++){
        this->photos[i] = this->photos[i+1];
    }
    this->numPhotos--;

    return recentPhoto;
}
//returns the size of the array
int PhotoArray::size()const{
    return this->numPhotos;
}

