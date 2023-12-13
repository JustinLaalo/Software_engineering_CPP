
#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Album.h"
using namespace std;

class AlbumArray {
		
	public:
		//constructor
        
        AlbumArray();
        
        //deconstructor
        ~AlbumArray();
        
        //functions
        bool add(Album* alb);
        Album* remove(const string& title);
        Album* remove(int index);
        int size()const;
        bool isFull()const;
        //getters
        Album* get(int index)const;
        Album* get(const string& title)const;
        
        






        
	
	private:
		//functions
	

	
		//variables
        //check to see if set
		int albumSize;
        Album** albums;
	
};
#endif
