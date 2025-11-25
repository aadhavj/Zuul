//Header guard
#ifndef ROOMS_H
#define ROOMS_H

//Regular imports
#include <iostream>
#include <cstring>
#include <vector>
#include "items.h"
using namespace std;

//Class instantiation
class rooms {
	//Publicly accessible constructor, destructor, getters, setters, and useful functions
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
	//Privately accessible variables/characteristics and exits, directions, and roomInventory vectors
	private:
		char* name;
		char* description;
		vector<rooms*> exits;
		vector<items*> roomInventory;
		vector<char*> exitDirections;
};
//End of header guard
#endif
