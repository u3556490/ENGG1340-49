# include "main.h"
# include "update.h"
# include "addentry.h"
# include "rmentry.h"
# include "search.h"
# include "filter.h"
# include "sort.h"
# include "stockalert.h"
# include "imexport.h"
# include <string>
# include <iostream>
# include <vector>
using namespace std;
using namespace main_header;

// Using a vector to hold contents of the table
// Because vectors are dynamic and allow good random access.
vector<Commodity> inventory;

const int INIT_INVENTORY_SIZE = 50;

// -----------------------------------
// Function mainmenu : Prints a list of options 
// for the user to choose from, these options 
// will bring him to corresponding functions
// @params none
// @return none
// -----------------------------------
// Requirements: 
// 1. show a list of options
// 2. let user choose by inputting a number (id) or a character
// 3. Direct him to the corresponding function
//    (using a switch-case, maybe), leave "TODO"s in comments 
//    for functions not yet in place
// 4. Repeat 1-3, until user chooses to Exit
// -----------------------------------
void main_header::mainmenu(){
	// TODO
}

// -----------------------------------
// Function init : Readies the inventory vector.
// @params none
// @return none
// -----------------------------------
void init(){
	inventory.reserve(INIT_INVENTORY_SIZE);
}

// ----------------------
// Main function here
// @params none
// @return int exit code
// ---------------------
int main(){
	init();
	mainmenu();
	return 0;
}
