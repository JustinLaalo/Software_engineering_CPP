
#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "AlbumArray.h"
using namespace std;

class PhotoGram {
		
	public:
		//constructor
        
        PhotoGram();
        //destructor 
        ~PhotoGram();

        //functions
        bool addAlbum(const string& title, const string& description);
        bool removeAlbum(const string& title);
        bool addPhoto(const string& title, Photo photo);
        bool removePhoto(const string& title, const string& photoTitle);
        Album* downloadAlbum(const string& title)const;
        Photo* downloadPhoto(const string& title, const string& photoTitle)const;
        void printAlbums() const;
        void displayAlbums() const;

        







        
	
	private:
	

	
		//variables
		AlbumArray* albumArray;
	
};
#endif
