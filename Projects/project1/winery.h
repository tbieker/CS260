//Author: Tyler Bieker
//Class: CS 260
//Assignment: Project 1
//Date:
//Sources:textbook, C++ Programming(Malik)

#ifndef _WINERY_
#define _WINERY_

#include <ostream>

//Class to store winery data

class winery{
	private:
		const static int MAX_CHAR = 100;
		char * name;
		char * location;
		int year;
		float acres;
		float rating;
	
	public:
		winery();
		winery(const winery& aWinery);
		~winery();
		
		void setName(char name[MAX_CHAR]);
		void setLocation(char location[MAX_CHAR]);
		void setYear(int year);		
		void setAcres(float acres);
		void setRating(float rating);

		void print(void) const;	//print formatted data
		
		winery& operator=(const winery& aWinery);	//copy 
		friend std::ostream& operator<<(std::ostream& out, const winery& aWinery);
		
		friend bool operator>(const winery& aWinery, const winery& bWinery);
		friend bool operator<(const winery& aWinery, const winery& bWinery);
		friend bool operator==(const winery& aWinery, const char key[MAX_CHAR]);
};



#endif
