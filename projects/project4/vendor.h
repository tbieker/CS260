//Author: Tyler Bieker
//CS 260
//Assignment: Project 4 Vendor Class
//Date:
//Sources:

//vendor.h

#ifndef _VENDOR_
#define _VENDOR_

#include <iostream>
#include <cstring>

class vendor{
private:
    char * name;        //vendor name
    char * phoneNumber; //vendor phone number
    char * product;     //vendor product
    char * events;      //events vendor participates in. Can be more than one

	const static int MAX_CHAR = 100;

public:
    vendor();
    vendor(const vendor& aVendor); //copy constructor
    ~vendor();

    //functions to set private data members
     void setName(char name[100]);
     void setNumber(char number[100]);
     void setProduct(char product[100]);
     void setEvents(char events[100]);

	 //functions to return values
	 void getName(char * name);
	 void getProduct(char * product);

     void print(); //print contents of class

	 const vendor& operator=(const vendor& aVendor); //overload = for deep copy
     friend std::ostream& operator<<(std::ostream& out, const vendor& aVendor);
};

#endif
