
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "PhotoGram.h"
using namespace std;

class Client {
		
	public:
		//constructor
        Client();
        //Deconstructor
        ~Client();
        
        //functions
        bool downloadAlbum(PhotoGram* PhotoGram, string albumTitle);
        bool displayOnlinePhoto(PhotoGram* PhotoGram, const string& albumTitle, const string& photoTitle)const;
        bool displayLocalPhoto(const string& albumTitle, const string& photoTitle)const;
        void printLocalAlbums() const;
        void displayLocalAlbums() const;






        
	
	private:
	

	
		//variables
		AlbumArray* albums;
	
};
#endif
