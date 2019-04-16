# include "main.h"
# include <iostream>
using namespace std;
using namespace main_header;

// ------------------------------
// Struct Commodity: each instance of 
// this struct corresponds to one entry
// in the inventory table, i.e. a row.
// ------------------------------
struct main_header::Commodity{
	string id;					//TODO: design id
	string name;
	string manufacturer;
	double price;
	string expiry_date;			//TODO: design and handle dates
	int stock_amount;
	int warning_level;			//TODO: is warning level global?
	bool stock_warning;
	bool out_of_stock;
	string shop_id;
	int shop_amount;
	bool shop_stock_warning;
	bool shop_out_of_stock;
};


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

// ----------------------
// Main function here
// @params none
// @return int exit code
// ---------------------
int main(){
	mainmenu();
	return 0;
}
