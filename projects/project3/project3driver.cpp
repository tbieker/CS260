#include <stdlib.h>
//#include <crtdbg.h>


#include "stock.h"
#include "hashtable.h"
#include <iostream>

using namespace std;

void displayMenu();
char getCommand();
void executeCmd(char command, hashTable& table);

void getStock(stock& aStock);
int getInt(char * prompt);
float getFloat(char * prompt);
void getString(char * prompt, char * input);
void modify(char * input, hashTable& table);
void display(hashTable& table);

const int MAX_LEN = 100;

int main()
{
	//use memory leak detection tool in Visual Studio .Net.
	//comment it out if you are not using Visual Studio .Net
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char command = 'a';
	char fileName[] = "data.dat";
	hashTable table(fileName);

	displayMenu();
	command = getCommand();
	while(command != 'q')
	{
		executeCmd(command, table);
		displayMenu();
		command = getCommand();
	}

	table.writeOut (fileName);
	cout << "\nThank you for using CSMS!" << endl << endl;
	return 0;
}

void displayMenu()
{
	cout << "\nImplemented by: Tyler Bieker" << endl;
	cout << "\nWelcome to CS Stock Management System! "<< endl;
	cout << "\ta> add a stock" << endl
		 << "\tr> remove a stock" << endl
		 << "\tm> modify a stock" << endl
		 << "\ts> search for a stock" << endl
		 << "\tl> list all stocks" << endl
		 << "\tc> check status of hash table" << endl
		 << "\tq> quit the application" << endl << endl;
}

char getCommand()
{
	char cmd;
	cout << "Please enter your choice (a, r, m, s, l or q):";
	cin >> cmd;
	cin.ignore(100, '\n');
	return tolower(cmd);
}

void executeCmd(char command, hashTable& table)
{
	stock stock;
	char key[MAX_LEN];

	switch(command)
	{
	case 'a': getStock(stock);
			  table.add(stock);
			  cout << endl << "the stock has been saved in the database. " << endl;
		break;

	case 'r': getString("\nPlease enter the ticker symbol of the stock you want to remove: ", key);
		      table.remove(key);
			  cout << endl << key << " has been removed from the database. " << endl;
		break;

	case 'm': getString("\nPlease enter the ticker symbole of the stock you want to modify: ", key);
				modify(key, table);
				cout << endl << key << " has been modified. " << endl;
		break;

	case 's': getString("\nPlease enter the name of the stock you want to search: ", key);
			  table.retrieve (key, stock);
			  cout << endl << "Information about " << key << ": " << endl << '\t' << stock << endl;
		break;

	case 'l': display(table);
		break;

	case 'c': table.monitor();
		break;

	default: cout << "illegal command!" << endl;
		break;
	}
}

void display(hashTable& table)
{
	table.display();
}

void modify(char * input, hashTable& table){
	stock stock;
	table.retrieve(input, stock);

	float newNetAssetValue;
	char newDate[MAX_LEN];
	float newDateReturn;

	newNetAssetValue = getFloat("\tNew value: ");
	getString("\tNew date: ", newDate);
	newDateReturn = getFloat("\tNew return: ");

	table.modify(input, newNetAssetValue, newDate, newDateReturn);
}

void getStock(stock& stock)
{
	 char symbol[MAX_LEN];
	 char name[MAX_LEN];
	 float value;
	 char date[MAX_LEN];
	 float assetValue;

	 cout << "\nPlease enter information about the stock: " << endl;
	 getString("\tSymbol: ", symbol);
	 getString("\tName: ", name);
	 value = getFloat("\tValue: ");
	 getString("\tDate: ", date);
	 assetValue = getFloat("\tNet Return: ");

	 stock.setSymbol (symbol);
	 stock.setName (name);
	 stock.setValue (value);
	 stock.setDate (date);
	 stock.setReturn (assetValue);
}


float getFloat(char * prompt)
{
	float temp;
	cout << prompt;
	cin >> temp;
	while(!cin)
	{
		cin.clear ();
		cin.ignore(100, '\n');
		cout << "Illegal input -- try again: ";
		cin >> temp;
	}
	cin.ignore(100, '\n');
	return temp;
}

void getString(char * prompt, char * input)
{
	cout << prompt;
	cin.get(input, MAX_LEN, '\n');
	cin.ignore (100, '\n');
}
