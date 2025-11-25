//Header Guards
#ifndef ITEMS_H
#define ITEMS_H
//Regular imports
#include <iostream>
#include <cstring>
using namespace std;

//Class instantiation
class items {
	//Publicly usable functions, constructor, and destructor
	public:
		items(char*, char*, char* = "\033[0m");
		~items();
		char* getName();
		void setName(char*);
		char* getDescription();
		void setDescription(char*);
		void print();
		char* getColor();
		void setColor(char*);
	//Privately accessible variables/characteristics
	private:
		char* name;
		char* description;
		char* color;
};
//End of header guard
#endif
