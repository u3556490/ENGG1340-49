#ifndef MAINMENU
#define MAINMENU
#include <string>

namespace main_header{

// ------------------------------
// Struct Commodity: each instance of 
// this struct corresponds to one entry
// in the inventory table, i.e. a row.
// ------------------------------
struct Commodity{
	std::string id;						//TODO: design id paradigm
	std::string name;
	std::string manufacturer;
	double price;
	std::string expiry_date;			//TODO: design and handle dates
	int stock_amount;
	int warning_level;					//TODO: is warning level global?
	bool stock_warning;
	bool out_of_stock;
	std::string shop_id;
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
void mainmenu();
}
#endif /* MAINMENU */

