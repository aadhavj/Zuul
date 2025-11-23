//Useful modules
#include <iostream>
#include <cstring>
#include <vector>

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

//Namespace
using namespace std;

int main(){

	rooms* r = new rooms("Living Room", "A lightly wooded region.");
	items* i = new items("Key1", "A light bronze key!");
	items* g = new items("Key2", "A shining silver key!", YELLOW);
	
	r->addItems(i);
	r->addItems(g);

	r->print();

	

return 0;
}
