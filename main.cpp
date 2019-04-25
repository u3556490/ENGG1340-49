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

const int INIT_INVENTORY_SIZE = 50;	//the capacity to initialize to.

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
	vector<int> probs;		//indices of commodities with issues
	vector<Commodity> * current = &inventory;	//the current list to be shown. Depends on the filters
	vector<Commodity> filtered;					//the filtered list here. Must not remove or current will dangle.
	int filter_count = 0;
	
	bool quit = 0;
	int option; 
	string buffer;
	while (!quit){
		//status
		probs = check_stock(&inventory);
		int filtered_size = (filter_count > 0) ? (*current).size() : 0;
		cout << "=================================================================" << endl;
		cout << "The inventory is now of size: " << inventory.size() << "." << endl;
		cout << "There are " << filter_count << " filters set, with " << (*current).size() << " items in the filtered list." << endl;
		if (probs.size() < 1){																	//have problems?
			cout << "There are no special warnings. ";
		} else {																				//print names and ids of items
			cout << "---------------------------------------------------------------" << endl;
			cout << "There are items with stock issues. Namely: ";
			for (int i = 0; i < probs.size(); i++){
				cout << "\"" << inventory[probs[i]].name << "\"(" << inventory[probs[i]].id;
				if (inventory[probs[i]].out_of_stock){
					cout << ", warehouse out of stock ";
				}
				if (inventory[probs[i]].shop_out_of_stock){
					cout << ", out of stock at shop " << inventory[probs[i]].shop_id;
				}
				cout << ")";
				if ((i+1) == probs.size()){
					cout << endl;
				} else {
					cout << ", ";
				}
			}
			cout << "---------------------------------------------------------------" << endl;
		}
		cout << "Ready\n";
		cout << "What do you want to do?" << endl;
		//print option list
		cout << "1. Add new entry/entries"<< endl;
		cout << "2. Remove obsolete entry/entries" << endl;
		cout << "3. Import and load inventory from file" << endl;
		cout << "4. Export and save current (with filters) inventory to file" << endl;
		cout << "5. Search for entries" << endl;
		cout << "6. Filter entries content" << endl;
		cout << "7. Unset all filters' effect" << endl;
		cout << "8. Print current inventory (with filters) contents on screen" << endl;
		cout << "9. Sort current inventory (with filters) in order" << endl;
		cout << "10. Set stockpile warning level" << endl;
		cout << "11. Check stock status once more" << endl;
		cout << "12. Exit the application" << endl;
		cout << "================================================================" << endl;
		bool input_ok = 0;
		while (!input_ok){ //input check
			cout << "Enter a number: ";
			//get option
			cin >> buffer;
			option = atoi(buffer.c_str());
			if ((option < 1) || (option > 12)){	//better option is to catch stoi exceptions but nvm
				cout << "Please check your input and try again.\n";
			} else {
				input_ok = 1;
			}
		}
		//check option
		switch (option){
			case (1): {
				add(inventory);	
				break;
			}
			case (2):{
				remove(inventory);
				break;
			}
			case (3):{
				inventory = import_file();	//import: done
				sort_id(inventory);
				current = & inventory;
				break;
			}
			case (4):{
				export_file(current);	//export: done
				break;
			}
			case (5):{
				search(inventory);	
				break;
			}
			case (6):{
				filtered = filter(*current, filter_count);	//must not be local!
				current = &filtered;
				//cout << (*current)[0].name << "\n";
				break;
			}
			case (7):{
				current = &inventory;	//reset filter
				filter_count = 0;
				break;
			}
			case (8):{
				print_inv(*current);
				break;
			}
			case (9):{
				sort_list(*current);	//sort: done
				break;
			}
			case (10):{
				setLevel(inventory);	//set level: done
				break;
			}
			case (11):{
				probs = check_stock(& inventory);	//check stock: done
				break;
			}
			case (12):{	//quit
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
