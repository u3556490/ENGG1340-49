# include "main.h"
# include "update.h"
# include "addentry.h"
# include "rmentry.h"
# include "search.h"
# include "filter.h"
# include "sort.h"
# include "stockalert.h"
# include "imexport.h"
# include "printinv.h"
# include <string>
# include <iostream>
# include <vector>
using namespace std;
using namespace main_header;

// Using a vector to hold contents of the table
// Because vectors are dynamic and allow good random access.
vector<Commodity> inventory {};

const int INIT_INVENTORY_SIZE = 50;

// -----------------------------------
// Function init : Readies the inventory vector.
// @params none
// @return none
// -----------------------------------
void init(){
	inventory.reserve(INIT_INVENTORY_SIZE);
}


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
	init();
	vector<int> probs;
	
	bool quit = 0;
	char option;
	while (!quit){
		//status
		probs = check_stock(& inventory);
		cout << "=================================================================" << endl;
		cout << "The inventory is now of size: " << inventory.size() << "." << endl;
		if (probs.size() < 1){
			cout << "There are no special warnings. ";
		} else {
			cout << "-------------------------------------------------------------" << endl;
			cout << "There are items with stock issues. Namely: ";
			for (int i = 0; i < probs.size(); i++){
				cout << "\"" << inventory[probs[i]].name << "\", ";
			}
			cout << endl;
			cout << "-------------------------------------------------------------" << endl;
		}
		cout << "Ready\n";
		cout << "What do you want to do?" << endl;
		//print option list
		cout << "(A)dd new entry/entries"<< endl;
		cout << "(R)emove obsolete entry/entries" << endl;
		cout << "(I)mport and load inventory from file" << endl;
		cout << "(E)xport and save current inventory to file" << endl;
		cout << "(S)earch for entries" << endl;
		cout << "(F)ilter entries content" << endl;
		cout << "Show inventory contents (P)" << endl;
		cout << "S(O)rt all entries in order" << endl;
		cout << "Set stockpile (W)arning level" << endl;
		cout << "(C)heck stock status" << endl;
		cout << "E(X)it the application" << endl;
		cout << "================================================================" << endl;
		cout << "Enter a letter: ";
		//get option
		cin >> option;
		option = toupper(option);
		//check option
		switch (option){
			case ('A'): {
				add(inventory);
				break;
			}
			case ('R'):{
				remove(inventory);
				break;
			}
			case ('I'):{
				inventory = import_file();
				break;
			}
			case ('E'):{
				export_file(inventory);
				break;
			}
			case ('S'):{
				search(inventory);
				break;
			}
			case ('F'):{
				filter(inventory);
				break;
			}
			case ('P'):{
				print_inv(inventory);
				break;
			}
			case ('O'):{
				sort_list(inventory);
				break;
			}
			case ('W'):{
				//setLevel(nullptr, nullptr);
				break;
			}
			case ('C'):{
				probs = check_stock(& inventory);
				break;
			}
			case ('X'):{
				quit = 1;
				break;
			}
			default: cout << "Please check your input and try again." << endl;
		}
	}
}

// ----------------------
// Main function here
// @params none
// @return int exit code
// ---------------------
int main(){
	mainmenu();
	return 0;
}
