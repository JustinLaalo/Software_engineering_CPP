#include "Client.h"
//default constructor for client
Client::Client(){
    //dynamically allocate memory with a pointer to a AlbumArray object with a size of MAX_ARRAY
    this->albums = new AlbumArray[MAX_ARRAY];
}
//Deconstructor
Client::~Client(){
    //loops though the array and frees the memory of each album in the array
    for(int i = 0; i < this->albums->size(); i++){
        delete this->albums->get(i);
    }
    //frees the pointer to the array
    delete[] this->albums;
}

//adds a new album to the array
bool Client::downloadAlbum(PhotoGram* PhotoGram, string albumTitle){
   if(PhotoGram->downloadAlbum(albumTitle)){
    //creates a new album using the copy constructor in ablum
    Album* newAlbum = new Album(*PhotoGram->downloadAlbum(albumTitle));
    //the newly created album to the array
    this->albums->add(newAlbum);
    return true;
   }
   return false;
    
}
//displays a photo with the given title, from album with the given title in the array of PhotoGram albums
bool Client::displayOnlinePhoto(PhotoGram* PhotoGram, const string& albumTitle, const string& photoTitle)const{
   if(PhotoGram->downloadAlbum(albumTitle)){
    for(int i = 0; i < PhotoGram->downloadAlbum(albumTitle)->size(); i++){
        if(PhotoGram->downloadAlbum(albumTitle)->getPhoto(i)->equals(photoTitle)){
            PhotoGram->downloadAlbum(albumTitle)->getPhoto(i)->display();
            return true;
        }
    }
   }
   return false;
}
//displays the photo with the given title, from album with the given title in the array albums
bool Client::displayLocalPhoto(const string& albumTitle, const string& photoTitle)const{
    for(int i = 0; i < this->albums->size(); i++){
        if(this->albums->get(i)->equals(albumTitle)){
            for(int j = 0; j < this->albums->get(i)->size(); j++){
                if(this->albums->get(i)->getPhoto(photoTitle)->equals(photoTitle)){
                    this->albums->get(i)->getPhoto(photoTitle)->display();
                    return true;
                }
            }
        }
    }
    return false;
}
//prints all the albums in the array of albums
void Client::printLocalAlbums() const{
    for(int i = 0; i < this->albums->size(); i++){
        this->albums->get(i)->print();
    }
}
//displays all the albums in the array of albums
void Client::displayLocalAlbums() const{
    for(int i = 0; i < this->albums->size(); i++){
        this->albums->get(i)->display();
    }
}