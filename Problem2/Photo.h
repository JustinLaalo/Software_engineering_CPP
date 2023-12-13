
#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
using namespace std;

class Photo {
		
	public:
		//constructor
        Photo(const string& title, const Date& date, const string& content);
        void print() const;
        void display() const;
        bool equals(const string& title) const;

        //getter function
        string getTitle() const;

        Date getDate() const;

        string getContent() const;
    
	private:


	
		//variables
		Date date;
        string title;
        string content;
	
};
#endif
