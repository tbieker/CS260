//Author: Tyler Bieker
//CS 260
//Assignment: Project 4 Vendor Class
//Date:
//Sources:

//vendor.cpp

#include "vendor.h"

vendor::vendor(){
	name = nullptr;
	phoneNumber = nullptr;
	product = nullptr;
	events = nullptr;
	/*
	setName("No name");
	setNumber("No number");
	setProduct("No product");
	setEvents("No events)");
	*/
	return;
}

vendor::vendor(const vendor& aVendor){
	setName(aVendor.name);
	setNumber(aVendor.phoneNumber);
	setProduct(aVendor.product);
	setEvents(aVendor.events);
	return;
}

vendor::~vendor(){
	//delete name
	if(this->name != nullptr){
		delete [] this->name;
		this->name = nullptr;
	}

	//delete phone number
	if(this->phoneNumber != nullptr){
		delete [] this->phoneNumber;
		this->phoneNumber = nullptr;
	}

	//delete product
	if(this->product != nullptr){
		delete [] this->product;
		this->product = nullptr;
	}

	//delete events
	if(this->events != nullptr){
		delete [] this->events;
		this->events = nullptr;
	}
}

void vendor::setName(char name[MAX_CHAR]){

	if(this->name){
		delete [] this->name;
		//this->name = nullptr;
	}

	this->name = new char[strlen(name) - 1];
	strcpy(this->name, name);
	return;
}

void vendor::setNumber(char number[MAX_CHAR]){

	if(this->phoneNumber){
		delete [] this->phoneNumber;
		//this->phoneNumber = nullptr;
	}

	this->phoneNumber = new char[strlen(number) - 1];
	strcpy(this->phoneNumber, number);
	return;
}

void vendor::setProduct(char product[MAX_CHAR]){

	if(this->product){
		delete [] this->product;
		//this->product = nullptr;
	}

	this->product = new char[strlen(product) - 1];
	strcpy(this->product, product);
	return;
}

void vendor::setEvents(char events[MAX_CHAR]){

	if(this->events){
		delete [] this->events;
		//this->events = nullptr;
	}

	this->events = new char[strlen(events) - 1];
	strcpy(this->events, events);
	return;
}

void vendor::print(){
	std::cout << "Name: " << this->name << std::endl
		<< "Phone Number: " << this->phoneNumber << std::endl
		<< "Product: " << this->product << std::endl
		<< "Events: " << this->events << std::endl;
	return;
}

void vendor::getName(char * name){
	strcpy(name, this->name);
	return;
}

void vendor::getProduct(char * product){
	strcpy(product, this->product);
	return;
}

const vendor& vendor::operator=(const vendor& aVendor){
	this->setName(aVendor.name);
	this->setNumber(aVendor.phoneNumber);
	this->setProduct(aVendor.product);
	this->setEvents(aVendor.events);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const vendor& aVendor){
    out << aVendor.name << ','
        << aVendor.phoneNumber << ','
        << aVendor.product << ','
        << aVendor.events << '\n';
    return out;
}
