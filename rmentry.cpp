#include "main.h"
#include "rmentry.h"
#include "search.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace main_header;

// ------------------------------------------------
// Function remove_one: removes ONE particular inventory entry,
// which is located at list[index].
// @params vector<Commodity> &list: the inventory to modify
//         int index: the location
// @return none
// -----------------------------------------------
void remove_one(std::vector<main_header::Commodity> &list, int index){
	list.erase(list.begin() + index);
}

// -------------------------------------
// Function remove: will be called immediately when the user wants 
// to delete something from the inventory. Lead him to the right functions
// and loop them whenever necessary.
// @params vector<Commodity> &list: the inventory to modify
// @return none
// -------------------------------------
void remove(std::vector<main_header::Commodity> &list){
	bool confirmed = 0;
	string id;
	int index;
	while (not confirmed){
		cout << "The id you want to delete is?\n";
		cin >> id;
		index = idfindcom(list, id);
		if (index == -1){
			cout << id << " not found.\n";
			cout << "Please try again";
		}
		else{
			confirmed = true;
		}
	]
	if (print_warning()){
		remove_one(list, index);
		cout << "The deletion has been successfully completed.\n";
	}
 }

// ------------------------------
// Function print_warning: prints a deletion warning on the screen
// and only proceed with the deletion if the user really wills it.
// @params none
// @return bool: true if user wants to proceed, false otherwise.
// ------------------------------
bool print_warning(){
	cout << "Are you confirmed to remove this item from the inventory? (Y/N)";
	char input;
	cin >> input;
	if (input == 'Y'){
		return true;
	}
	else if (input == 'N'){
		return false;
	}
}

/* Debug only 
int main(){
	return 0;
}*/
