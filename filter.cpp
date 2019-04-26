#include "main.h"
#include "filter.h"
#include "search.h"
#include "inpututil.h"
#include <vector>
#include <string>
#include <iostream>
#include <exception>
using namespace std;
using namespace main_header;

/* Algorithms for filtering
   Filtering out a subset of items, all having one specific attribute equal a given value:
   Step 1: ask user which attribute to filter
   Step 2: ask user the value to look for (key)
   Step 3: perform linear search to obtain the subset
   
   Multiple filter criteria?
   Repeat steps 1-3 until user is satisfied. At that point we return to main menu.
   So far there are no ways to unset a filter while keeping another, due to time and technical constraints.
*/

// Implement additional functions whenever necessary

// --------------------------------------
// function filter: called when the user wills it.
// Take input on what to filer and whether the filter is to be unset.
// Must not overwrite the original inventory.
// @params vector<Commodity> original: original list of items.
//         int &count: the number of filters set. this comes in by reference.
// @return vector<Commodity>: vector of entries of the matches to display.
// --------------------------------------
vector<Commodity> filter(vector<Commodity> original, int &count){
	int filter_count = 0;						//no. of filters set
	bool quit = 0;								//whether the user wants to go back to main menu
	vector<Commodity> selected = {};			//selected commodities
	selected.reserve(10);
	vector<Commodity> * current = & original;	//pointer to the list of commodities to filter. initialized to the entire inventory
	
	if (original.size() < 2){					//save some work and return nothing.
		cout << "No meaningful filtering is possible.\n";
		count = 0;
		return selected;
	}
	
	while (!quit){								
		string buffer;		//an input buffer
		bool input_ok = 0;	//used for input checkings
		int criterion = 0;	//which criterion has been chosen to set this filter
		
		//get user input and inform user of current status
		cout << "--------------------------------------------------------\n";
		cout << "Setting up filter #" << filter_count+1 << ". " << filter_count << " filters have been set." << endl;
		cout << "The size of the filtered list is now " << (*current).size() << ".\n";
		cout << "Please select a criterion from the following list: \n";
		cout << "1. id\n2. name\n3. manufacturer\n";
		cout << "4. price\n5. expiry date\n6. stock amount\n";
		cout << "7. warning level\n8. stock warning\n9. out of stock\n";
		cout << "10. shop id\n11. shop stock amount\n12. shop stock warning\n13. shop out of stock\n";
		cout << "14. finish and return\n";
		cout << "--------------------------------------------------------\n";
		while (!input_ok){	//repeat
			cout << "Please enter a number: ";
			cin >> buffer;
			criterion = atoi(buffer.c_str());	//check if the input value is an integer and lies in [1,14].
			if ((criterion < 1) || (criterion > 14)){
				cout << "Please check your input and try again." << endl;
			} else {
				input_ok = 1;
			}
		}
		if (criterion == 14){	//finish and return
			quit = 1;
			break;
		}
		cin.ignore();	//a fix for the getline's
		
		//get value to find and find the entries
		switch(criterion){
			case 1: {	//id
				string value = getString();	//get the value to filter for
				int result = idfindcom(*current, value);	//there exists only one match, just one int is enough
				if (result == -1){	//commodity not found
					cout << "Filtering unsuccessful: id " << value << " not found.\n";
				} else {
					selected.clear();	//reset
					selected.push_back((*current)[result]);	//add item to selected
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 2: {	//name
				string value = getString();
				vector<int> result = name_search(*current, value);	//multiple matches are possible
				if (result.size() == 0){
					cout << "Filtering unsuccessful: name " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);	//god damn this pointer syntax!
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 3: {	//manufacturer
				string value = getString();
				vector<int> result = manu_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: manufacturer " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 4: {	//price
				double value = getDouble();	//double type
				vector<int> result = price_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: expiry date " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);	//god damn this pointer syntax! and the copy-paste!
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 5: {	//expiry date
				string value = getString();
				vector<int> result = date_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: expiry date " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);	//god damn this pointer syntax! and the copy-paste!
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 6: {	//stock amount
				int value = getInt();
				vector<int> result = stockamt_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: expiry date " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);	//god damn this pointer syntax! and the copy-paste!
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 7: {	//warning level
				int value = getInt();
				vector<int> result = level_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: expiry date " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);	//god damn this pointer syntax! and the copy-paste!
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 8: {	//stock warning
				bool value = getBool();
				vector<int> result = stockwarn_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: expiry date " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);	//god damn this pointer syntax! and the copy-paste!
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 9: {	//out of stock
				bool value = getBool();
				vector<int> result = stockout_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: expiry date " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);	//god damn this pointer syntax! and the copy-paste!
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 10: {	//shop id
				string value = getString();
				vector<int> result = shopid_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: expiry date " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);	//god damn this pointer syntax! and the copy-paste!
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 11: {	//shop amount
				int value = getInt();
				vector<int> result = shopamt_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: expiry date " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);	//god damn this pointer syntax! and the copy-paste!
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 12: {	//shop stock warning
				bool value = getBool();
				vector<int> result = shopwarn_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: expiry date " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);	//god damn this pointer syntax! and the copy-paste!
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 13: {	//shop out of stock
				bool value = getBool();
				vector<int> result = shopout_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: expiry date " << value << " not found.\n";
				} else {
					selected.clear();
					for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
						selected.push_back((*current)[(*i)]);	//god damn this pointer syntax! and the copy-paste!
					}
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
		}
	}
	//return
	count = filter_count;
	return selected;
}

/*debug only
int main(){
	return 0;
}*/
