//Neccessary imports
#include <iostream>
#include <cstring>
#include "items.h"
using namespace std;

//Items constructor
items::items(char* inputName, char* inputDescription, char* inputColor){
	name = new char[1000];
	strcpy(name, inputName);
	description = new char[1000];
	strcpy(description, inputDescription);
	color = new char[1000];
	strcpy(color, inputColor);
}

//Items destructor
items::~items(){
	delete[] name;
	delete[] description;
	delete[] color;
}


//Individual getter and setter functions, as well as special print for info.
char* items::getName(){
	return name;
}
char* items::getDescription(){
	return description;
}
void items::setDescription(char* inputDescription){
	strcpy(description, inputDescription);
}
void items::setName(char* inputName){
	strcpy(name, inputName);
}
void items::print(){
	cout << "\nName: " << color << name << "\033[0m" << "\nDescription: " << description << endl;
}
char* items::getColor(){
	return color;
}
void items::setColor(char* inputColor){
	strcpy(color, inputColor);
}

