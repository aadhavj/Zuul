#include <iostream>
#include <cstring>
#include "rooms.h"
#include "items.h"

using namespace std;

rooms::rooms(char* inputName, char* inputDescription){
	name = new char[1000];
	strcpy(name, inputName);
	description = new char[1000];
	strcpy(description, inputDescription);
	vector<items*> roomInventory;
}

rooms::~rooms(){
	delete[] name;
	delete[] description;
}

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
void rooms::addItems(items* inputItem){
	roomInventory.push_back(inputItem);
}
void rooms::removeItems(int removalIndex){
	delete[] roomInventory[removalIndex];
	roomInventory.erase(roomInventory.begin()+removalIndex);
}
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
