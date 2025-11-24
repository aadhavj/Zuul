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
		vector<items*> seeItems();
		items* removeItems(int);
		void addExit(rooms*, char*);
		void seeExits();
		rooms* enterRoom(char*);
		bool validDirection(char*);
		bool validItemIndex(int);
	private:
		char* name;
		char* description;
		vector<rooms*> exits;
		vector<items*> roomInventory;
		vector<char*> exitDirections;
};
#endif
