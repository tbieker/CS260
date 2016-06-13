#include <stdlib.h>
//#include <crtdbg.h>


#include "collection.h"
#include "vendor.h"
#include <iostream>

using namespace std;

void displayMenu();
char getCommand();
void executeCmd(char command, collection& vendors);

void getVendor(vendor& aVendor);
void getString(char * prompt, char * input);

const int MAX_LEN = 100;

int main()
{
	//use memory leak detection tool in Visual Studio .Net.
	//comment it out if you are not using Visual Studio .Net
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char command = 'a';
	char fileName[] = "data.dat";
	collection vendors(fileName);

	displayMenu();
	command = getCommand();
	while(command != 'q')
	{
		executeCmd(command, vendors);
		displayMenu();
		command = getCommand();
	}

	vendors.writeOut (fileName);
	cout << "\nThank you for using my nonlinear data structure!" << endl << endl;
	return 0;
}

void displayMenu()
{
	cout << "\nImplemented by: Tyler Bieker" << endl;
	cout << "\nWelcome to CS nonlinear data structure! "<< endl;
	cout << "\ta> add a vendor" << endl
		 << "\tr> remove a vendor" << endl
		 << "\ts> search for a vendor" << endl
		 << "\tn> list all vendors by name" << endl
		 << "\tp> list all vendors by product" << endl
		 << "\tq> quit the application" << endl << endl;
}

char getCommand()
{
	char cmd;
	cout << "Please enter your choice (a, r, s, n, p or q):";
	cin >> cmd;
	cin.ignore(100, '\n');
	return tolower(cmd);
}

void executeCmd(char command, collection& vendors)
{
	vendor aVendor;
	char key[MAX_LEN];

	switch(command)
	{
	case 'a': getVendor(aVendor);
			  vendors.add(aVendor);
			  cout << endl << "the vendor has been saved in the database. " << endl;
		break;

	case 'r': getString("\nPlease enter the name of the vendor you want to remove: ", key);
		      vendors.remove(key);
			  cout << endl << key << " has been removed from the database. " << endl;
		break;

	case 's': getString("\nPlease enter the name of the vendor you want to search: ", key);
			  if(vendors.retrieveByName(key, aVendor)){
			  	cout << endl << "Information about " << key << ": " << endl << '\t' << aVendor << endl;
			}
		break;

	case 'n': vendors.displayByName();
		break;

	case 'p': vendors.displayByType();
		break;

	default: cout << "illegal command!" << endl;
		break;
	}
}

void getVendor(vendor& aVendor)
{
	char name[100];
	char phoneNumber[100];
	char product[100];
	char events[100];

	cout << "\nPlease enter information about the vendor: " << endl;
	getString("\tName: ", name);
	getString("\tPhone Number: ", phoneNumber);
	getString("\tProduct: ", product);
	getString("\tEvents: ", events);

    aVendor.setName(name);
    aVendor.setNumber(phoneNumber);
    aVendor.setProduct(product);
    aVendor.setEvents(events);
}

void getString(char * prompt, char * input)
{
	cout << prompt;
	cin.get(input, MAX_LEN, '\n');
	cin.ignore (100, '\n');
}
