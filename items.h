#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <cstring>
using namespace std;

class items {
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
	private:
		char* name;
		char* description;
		char* color;
};
#endif
