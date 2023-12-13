
#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "PhotoArray.h"
using namespace std;

class Album {
		
	public:
		//constructor
        Album(string title, string description);
        Album(const Album&);

        //destructor
        ~Album();

        //functions
        bool equals(const string&)const;
        bool lessThan(const Album&)const;
        bool addPhoto(Photo*);
        bool addPhoto(int, Photo*);
        Photo* removePhoto(int);
        Photo* removePhoto(const string&);
        void print()const;
        void display()const;
        int size()const;
        //getters
        string getTitle() const;
        Photo* getPhoto(int)const;
        Photo* getPhoto(const string&)const;






        
	
	private:
	

	
		//variables
		string title;
        string description;
        PhotoArray* photoArray;
    
};
#endif
