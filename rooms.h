#ifndef ROOMS_H
#define ROOMS_H
#include <iostream>
#include <cstring>
#include <vector>
#include "items.h"
using namespace std;

class rooms {
	public:
		rooms(char*,char*);
		~rooms();
		char* getName();
		char* getDescription();
		void setName(char*);
		void setDescription(char*);
		void print();
		void addItems(items*);
		void removeItems(int);
	private:
		char* name;
		char* description;
		vector<items*> roomInventory;
};
#endif
