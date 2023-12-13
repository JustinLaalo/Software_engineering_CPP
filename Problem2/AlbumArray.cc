#include "AlbumArray.h"
//defualt constuctor for AlbumArray
AlbumArray::AlbumArray(){
    this->albumSize =0;
    //dynamically allocate memory of a pointer to Albums with a array size of the MAX_ARRAY
    this->albums = new Album*[MAX_ARRAY];
}
//checks if the AlbumArray is full
bool AlbumArray::isFull()const{
    if(this->albumSize==MAX_ARRAY){
        return true;
    }else{
        return false;
    }
}
//frees the memory of the array
AlbumArray::~AlbumArray(){
    delete[] albums;
}
//adds a new Album to the array 
bool AlbumArray::add(Album* alb){
    //checks if the array is full
    if(isFull()){
       return false; 
    }
    int point = -1;
    //defualt case where the array is empty
    if(this->albumSize==0){
        this->albums[0] = alb;
        this->albumSize++;
        return true;

    }
    //finds the index where the album title is less than the album at the index title. (keep it sorted)
    for(int i= 0; i < this->albumSize; i++){
        if(!((this->albums[i])->lessThan(*alb))){
            point = i;
             break;
        }
    }
    //nothing found adds to the end of the array
    if(point == -1){
        point = this->albumSize;
    }
    //shifts the array to the right opening up space
    for(int i = albumSize; i > point; i--){
        this->albums[i] = this->albums[i-1];
    }
    this->albums[point] = alb;
    this->albumSize++;

    return true;

}
//returns the album at the index position
Album* AlbumArray:: get(int index)const{
    if(index<0 || index>=this->albumSize){
        return NULL;
    }else{
        return this->albums[index];
    }
}
//return the album with the given title
Album* AlbumArray::get(const string& title)const{
    for(int i = 0; i< this->albumSize; i++){
        if(this->albums[i]->equals(title)){
            return this->albums[i];
        }
    }
    return NULL;
}
//removes the album with the given title
Album* AlbumArray::remove(const string& title){
    int index = -1;
    //creates a new album pointer since when removed there will be no pointer to it
    Album* recentAlbum = NULL;
    //finds where the album is
    for(int i = 0; i < this->albumSize; i++){
        if(this->albums[i]->equals(title)){
            index = i;
            recentAlbum = this->albums[i];
            break;
        }
        
    }
    //if not found does one more check to see if it is the last album
    if(index == -1 ){
        if(this->albums[this->albumSize]->equals(title)){
            index = this->albumSize;
            recentAlbum = this->albums[this->albumSize];

        }else{
           return NULL; 
        }
    }
    //shifts the array from the index found to the left
    for(int i = index; i < this->albumSize; i++){
        this->albums[i] = this->albums[i+1];
    }
    this->albumSize--;
    return recentAlbum;
}
//removes the album at the given index
Album* AlbumArray::remove(int index){
    if(index<0 || index>this->albumSize){
        return NULL;
    }
    Album* recentAlbum = this->albums[index];

    for(int i = index; i < this->albumSize; i++){
        this->albums[i] = this->albums[i+1];
    }
    this->albumSize--;
    
    return recentAlbum;
}
//returns the size of the array
int AlbumArray::size()const{
    return this->albumSize;
}