
#ifndef PHOTOARRAY_H
#define PHOTOARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Photo.h"
#include "defs.h"
using namespace std;

class PhotoArray {
		
	public:
		//constructors
        PhotoArray();
        //destructor
        ~PhotoArray();

        //functions
        bool isFull() const;
        bool add(Photo* photo);
        bool add(int index, Photo* photo);
        Photo* remove(const string& title);

        Photo* remove(int index);

        int size() const;
        //getters
        Photo* get(const string& title) const;

        Photo* get(int index) const;

        
	
	private:
	

	
		//variables
		Photo** photos;
        int numPhotos;
	
};
#endif
