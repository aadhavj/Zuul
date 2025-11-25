//Useful modules
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib> 
#include <ctime>

//Imported self-created classes
#include "items.h"
#include "rooms.h"

//ANSI Color escape strings
#define BLACK "\033[30m"
#define RED   "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW   "\033[33m"
#define BLUE   "\033[34m"
#define MAGENTA   "\033[35m"
#define CYAN   "\033[36m"
#define RESET   "\033[0m"

//Namespace
using namespace std;

int main(){
	
	//Basic predefinition of variables
	bool runProgram = true;
	bool winCondition = false;
	bool hasAllKeys = false;
	bool keyHere = false;
	rooms* currentRoom;
	vector<rooms*> university;
	char command[1000];
	char direction[1000];
	int itemIndex;
	vector<items*> inventory;
	bool hasMap;

	//Randomizer neccessities
	srand(static_cast<unsigned int>(std::time(nullptr)));
	int random_num;
	int minRandom = 0;
	
	//Possible commands
	char seeMap[] = "MAP";
	char pickUp[] = "PICKUP";
	char drop[] = "DROP";
	char seeInventory[] = "INVENTORY";
	char move[] = "MOVE";
	char help[] = "HELP";
	char quit[] = "QUIT";

	//Set Rooms w/ items
	rooms* mainEntrance = new rooms("Main Entrance", "A huge gate to the university.");
	university.push_back(mainEntrance);
	items* map = new items("MAP", "A quintessential item for navigation.");
	mainEntrance->addItems(map);

	rooms* ComputingLab = new rooms("1-20 Computing Lab", "An array of computers side-by-side.");
	university.push_back(ComputingLab);
       	items* computer = new items("Computer", "A regular computer. Seems to be detached tho...", GREEN);
	ComputingLab->addItems(computer);	

	rooms* coffeeHouse = new rooms("Campus Coffee House", "The smell of birthday cake frappuccino is pungent in the air.");
	university.push_back(coffeeHouse);
	items* coffee = new items("Black Coffee", "MMm! Delicious.", MAGENTA);
	coffeeHouse->addItems(coffee);

	rooms* lectureTheater = new rooms("Lecture Theater", "A place where professors give lectures.");
	university.push_back(lectureTheater);

	rooms* Classroom1 = new rooms("Classroom #1", "A regular classroom to teach students.");
	university.push_back(Classroom1);

	rooms* Classroom3 = new rooms("Classroom #3", "A regular classroom to teach students.");
	university.push_back(Classroom3);

	rooms* Classroom2 = new rooms("Classroom #2", "A regular classroom to teach students.");
	university.push_back(Classroom2);

	rooms* Classroom4 = new rooms("Classroom #4", "A regular classroom to teach students.");
	university.push_back(Classroom4);

	rooms* library = new rooms("Library", "A place with a bunch of books. How boring...");
	university.push_back(library);

	rooms* adminOffice = new rooms("Admin Office", "A place where the admins meet up to work.");
	university.push_back(adminOffice);

	rooms* exitGateway = new rooms("Exit from the University", "A big castle door with 4 keyholes. I wonder?");
	university.push_back(exitGateway);

	rooms* HouseDistrict1 = new rooms("Housing gateway 1", "A room that leads to the dormitories");
	university.push_back(HouseDistrict1);

	rooms* HouseDistrict2 = new rooms("Housing gateway 2", "A room that leads to the dormitories");
	university.push_back(HouseDistrict2);

	rooms* Dormitory1 = new rooms("Dormitory 1", "A regular student's housing.");
	university.push_back(Dormitory1);

	rooms* Dormitory2 = new rooms("Dormitory 2", "A regular student's housing.");
	university.push_back(Dormitory2);

	rooms* Dormitory3 = new rooms("Dormitory 3", "A regular student's housing.");
	university.push_back(Dormitory3);

	rooms* Dormitory4 = new rooms("Dormitory 4", "A regular student's housing.");
	university.push_back(Dormitory4);

	rooms* BoysBathroom = new rooms("Boy's Bathroom", "A few sinks, a few stalls, nothin much.");
	university.push_back(BoysBathroom);

	rooms* GirlsBathroom =  new rooms("Girl's Bathroom", "A few sinks, a few stalls, nothin much.");
	university.push_back(GirlsBathroom);
	
	//Randomizer max set based on room numbers
	int maxRandom = university.size()-1;

	//Adding exits
	exitGateway->addExit(mainEntrance, "South");
	
	mainEntrance->addExit(exitGateway, "North");
	mainEntrance->addExit(lectureTheater, "East");
	mainEntrance->addExit(coffeeHouse, "West");
	mainEntrance->addExit(ComputingLab,"South");

	lectureTheater->addExit(HouseDistrict2,"North");
	lectureTheater->addExit(Classroom3, "East");
	lectureTheater->addExit(adminOffice, "South");
	lectureTheater->addExit(mainEntrance, "West");

	coffeeHouse->addExit(HouseDistrict1, "North");
	coffeeHouse->addExit(mainEntrance, "East");
	coffeeHouse->addExit(library, "South");
	coffeeHouse->addExit(Classroom1, "West");

	Classroom1->addExit(coffeeHouse, "North");
	Classroom1->addExit(Classroom2, "South");

 	Classroom2->addExit(Classroom1, "North");
	Classroom2->addExit(library, "East");

	library->addExit(coffeeHouse, "North");
	library->addExit(ComputingLab, "East");
	library->addExit(Classroom2, "West");

	ComputingLab->addExit(mainEntrance, "North");
	ComputingLab->addExit(adminOffice, "East");
	ComputingLab->addExit(library, "West");

	adminOffice->addExit(lectureTheater, "North");
	adminOffice->addExit(Classroom4, "East");
	adminOffice->addExit(ComputingLab, "West");

	Classroom4->addExit(Classroom3, "North");
	Classroom4->addExit(adminOffice, "West");

	Classroom3->addExit(Classroom4, "South");
	Classroom3->addExit(lectureTheater, "West");

	HouseDistrict1->addExit(Dormitory2, "North");
	HouseDistrict1->addExit(coffeeHouse,"South");
	HouseDistrict1->addExit(Dormitory1, "West");

	Dormitory1->addExit(BoysBathroom, "North");
	Dormitory1->addExit(HouseDistrict1, "East");

	BoysBathroom->addExit(Dormitory2, "East");
	BoysBathroom->addExit(Dormitory1, "South");

	Dormitory2->addExit(HouseDistrict1, "South");
	Dormitory2->addExit(BoysBathroom, "West");

	HouseDistrict2->addExit(Dormitory3,"North");
	HouseDistrict2->addExit(Dormitory4, "East");
	HouseDistrict2->addExit(lectureTheater, "South");

	Dormitory3->addExit(GirlsBathroom, "East");
	Dormitory3->addExit(HouseDistrict2, "South");

	GirlsBathroom->addExit(Dormitory4, "South");
	GirlsBathroom->addExit(Dormitory3, "West");

	Dormitory4->addExit(GirlsBathroom, "North");
	Dormitory4->addExit(HouseDistrict2, "West");

	//ADDING KEYS in random locations, using previous randomizer stuff
	vector<items*> keys;
	items* key1 = new items("Key1", "A light bronze key!", RED);
	keys.push_back(key1);
	items* key2 = new items("Key2", "A shining silver key!", CYAN);
	keys.push_back(key2);
	items* key3 = new items("Key3", "A heavy glinting golden key!", GREEN);
	keys.push_back(key3);
	items* key4 = new items("Key4", "A dark-black obsideon key!", YELLOW);
	keys.push_back(key4);
	for (items* key : keys){
		random_num = (rand() % (maxRandom - minRandom + 1)) + minRandom;
		university[random_num]->addItems(key);		
	}
	



	//BEGIN USER-INTERFACE
	currentRoom = mainEntrance; //sets current room/starter room
	cout << "Hello! Welcome to " << RED << "escape the unversity" << RESET << "\nYour goal is to escape, but you gotta figure out how!\nStart exploring!" << endl;
	while (runProgram){
		
		//Gives room information, name and details of room, as well as items and avaliable exits
		currentRoom->print();
		currentRoom->seeExits();
		
		//Tip on how to get info on commands
		cout << "\nNeed a detailed command description? type " << GREEN << "HELP" << RESET << "." << "\nCOMMAND: ";
		
		//Command getter
		cin >> command;
		
		//Command parser
		if (strcmp(command, seeMap) == 0){ //Checks to see if player has map object, if so, displays rudimentary map
			hasMap = false;
			for (int i = 0; i < inventory.size();i++){
				if (strcmp(inventory[i]->getName(),map->getName()) == 0){
					hasMap = true;
				}
			}
			if (hasMap){
			cout << MAGENTA << "Map Of University\n[ ] [ ]     [ ] [ ]\n[ ] [ ] [E] [ ] [ ]\n[ ] [ ] [S] [ ] [ ]\n[ ] [ ] [ ] [ ] [ ]\nE - Entrance\nS - Spawn"<< RESET << endl;
			}
			else{
			cout << MAGENTA << "You do not currently have access to the map. You must pick one up." << RESET << endl;
			}
		}
		else if (strcmp(command,help) == 0){ //Lists all possible user commands and brief description on each
			cout << CYAN << "\nPossible Commands: MAP, PICKUP, DROP, INVENTORY, MOVE, HELP, QUIT." << endl;
			cout << CYAN << "MAP - shows you a detailed map design of the university."  << endl;
			cout << CYAN << "PICKUP - allows you to pickup items within a room, if possible." << endl;
			cout << CYAN << "DROP - allows you to drop items into your current room, if possible" << endl;
			cout << CYAN << "INVENTORY - shows you a detailed layout of your inventory." << endl;
			cout << CYAN << "MOVE -  allows you to move from one room to another, if exit exists." << endl;
			cout << CYAN << "HELP - gives you a detailed list of commands and their purpose." << endl;
			cout << CYAN << "QUIT - terminated program processes" << RESET << endl;
		}
		else if (strcmp(command, quit) == 0){ //Terminates program early
			runProgram = false;
			cout << RED << "TERMINATING PROGRAM." << RESET << endl;
		}
		else if (strcmp(command,seeInventory) == 0){ //Displays player inventory, simple as that
			cout << "_____INVENTORY_____" << endl;
			if (inventory.size() == 0){
				cout << "Your pockets are empty" << endl;
			}
			else{
				for (int i = 0; i < inventory.size();i++){
					cout << i << ". " << inventory[i]->getName() << endl;
				}
			}
			cout << "_____INVENTORY_____" << endl;
		}
		else if (strcmp(command, pickUp) == 0){ //Adds items to user inventory
			if (currentRoom->seeItems().empty()){
				cout << "No items are present in this room." << endl;
			}
			else{
				cout << "Enter Pickup Item Index: ";
				cin >> itemIndex;
				if (currentRoom->validItemIndex(itemIndex)){
					inventory.push_back(currentRoom->removeItems(itemIndex));
					cout << YELLOW << inventory[inventory.size()-1]->getName() << RESET << " added to inventory." << endl;

					//Check if all keys picked up, updates hasAllKeys variable, neccessary for win condition
					hasAllKeys = true;
					for (int i = 0; i < keys.size();i++){
						keyHere = false;
						for (items* a : inventory){
							if (strcmp(a->getName(),keys[i]->getName()) == 0){
								keyHere = true;
							}
						}
						if (!keyHere){
							hasAllKeys = false;
						}
					}

				}
				else{
					cout << "Invalid item index. Returning you to command line." << endl;
				}
			}
		}
		else if (strcmp(command, drop) == 0){ //Allows player to drop items in rooms
			if (inventory.empty()){
				cout << "You have nothing to drop.." << endl;
			}
			else{
				for (int i = 0; i < inventory.size();i++){
                                        cout << i << ". " << inventory[i]->getName() << endl;
				}
				cout << "\nEnter Drop Item Index: ";
				cin >> itemIndex;
				if (itemIndex < inventory.size()){
					cout << GREEN << inventory[itemIndex]->getName() << RESET << " dropped in " << currentRoom->getName() << endl;
					currentRoom->addItems(inventory[itemIndex]);
					inventory.erase(inventory.begin()+itemIndex);
					
					//Confirms whether player has all keys, updates hasAllKeys variabl, neccessary for win condition
					hasAllKeys = true;
                                        for (int i = 0; i < keys.size();i++){
                                                keyHere = false;
                                                for (items* a : inventory){
                                                        if (strcmp(a->getName(),keys[i]->getName()) == 0){
                                                                keyHere = true;
                                                        }
                                                }
                                                if (!keyHere){
                                                        hasAllKeys = false;
                                                }
                                        }
				}
				else{
					cout << "Invalid item index. Returning you to command line." << endl;
				}
			}
		}
		else if (strcmp(command, move) == 0){ //Prompts player for valid diretion and changes their room
			cout << "Enter Chosen Direction: ";
			cin >> direction;
			if (currentRoom->validDirection(direction)){
				currentRoom = currentRoom->enterRoom(direction);
			}
			else{
				cout << "Invalid direction, returning you to command prompt." << endl;
			}
		}
		else{
			cout << RED << "Invalid command, not recognized. Please try again!" << RESET << endl;
		}
		
		//Checks if win conditions e.g. in right room and have keys, to win
		if ((strcmp(currentRoom->getName(),exitGateway->getName()) == 0) && hasAllKeys){
			winCondition = true;
			runProgram = false;
		}

	}
	//If player satisfies win conditions, display success text
	if (winCondition){
		cout << CYAN << "As you enter the exit gateway, you find the urge\n to slide the four keys you have gathered over\nthe course of this entire journey. After sliding\nthem in, a bright light engulfs you. When you open\nyou eyes, you see you have escaped the university.\n" << RESET << endl;
		cout << YELLOW << "CONGRATULATIONS!!! YOU HAVE WON!!!!" << RESET << endl;
	}
	//ASK GALBRAITH HOW TO PREVENT MEMORY LEAK FROM BEFORE
	

return 0;
}
