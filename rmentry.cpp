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
	while (not confirmed){
		cin >> id;
		int index = idfindcom(list, id);
		if (index == -1){
			cout << id << " not found.\n";
		}
		else{
			confirmed = true;
		}
		remove_one(list, index);
		cout << "You have successfully deleted the item.\n";
 }

// ------------------------------
// Function print_warning: prints a deletion warning on the screen
// and only proceed with the deletion if the user really wills it.
// @params none
// @return bool: true if user wants to proceed, false otherwise.
// ------------------------------
bool print_warning(){
<<<<<<< HEAD
	cout << "Are you confirmed to remove this item from the inventory? (Y/N)";
=======
	cout << "Are u confirmed to remove this item from the inventory?" << endl;
	cout << "Y/N";
>>>>>>> ff9a8fb6f936564b72f97595c96204b3e3baa5e9
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
