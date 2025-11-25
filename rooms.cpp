//Neccessary imports
#include <iostream>
#include <cstring>
#include "rooms.h"
#include "items.h"
using namespace std;

//Rooms constructor
rooms::rooms(char* inputName, char* inputDescription){
	name = new char[1000];
	strcpy(name, inputName);
	description = new char[1000];
	strcpy(description, inputDescription);
	vector<items*> roomInventory;
	vector<rooms*> exits;
        vector<char*> exitDirections;	
}

//Rooms destructor
rooms::~rooms(){
	delete[] name;
	delete[] description;
}

//Regular getters and setters
char* rooms::getName(){
	return name;
}
char* rooms::getDescription(){
	return description;
}
void rooms::setName(char* inputName){
	strcpy(name, inputName);
}
void rooms::setDescription(char* inputDescription){
	strcpy(description, inputDescription);
}

//roomInventory and objects in room manipulation functions
void rooms::addItems(items* inputItem){
	roomInventory.push_back(inputItem);
}
items* rooms::removeItems(int removalIndex){
	items* a = roomInventory[removalIndex];
	roomInventory.erase(roomInventory.begin()+removalIndex);
	return a;
}
vector<items*> rooms::seeItems(){
	return roomInventory;
}

//Exits and directions manipulation functions
void rooms::addExit(rooms* inputRoom, char* direction){
	exits.push_back(inputRoom);
	exitDirections.push_back(direction);
}
void rooms::seeExits(){
	cout << "\nExits: " << endl;
	for (int i = 0;i < exits.size();i++){
		cout << exitDirections[i] << "\t" << exits[i]->getName() << endl;
	}
}

//Validity functions, used to check if items at a certain index are valid or directions are valid
bool rooms::validItemIndex(int itemIndex){
	return (!roomInventory.empty() && itemIndex < roomInventory.size());
}
bool rooms::validDirection(char* direction){
	for (int i = 0;i < exitDirections.size();i++){
		if (strcmp(direction, exitDirections[i]) == 0){
			return true;
		}
	}
	return false;
}

//Must be run with valid direction to work, run validDirection prior to this
rooms* rooms::enterRoom(char* direction){
	for (int i = 0; i < exits.size();i++){
		if (strcmp(direction, exitDirections[i]) == 0){
			return exits[i];
		}
	}
	return exits[0];
}

//Special print functions to get info
void rooms::print(){
	cout << "\nName: " << name << "\nDescription: " << description << endl;
	
	cout << "What you see: " << endl;
	if (roomInventory.empty()){
		cout << "Nothing to see here..." << endl;
	}
	else{
		for (int i = 0; i < roomInventory.size();i++){
			cout << i << ". ";
			roomInventory[i]->print();
		}
	}
	
}
