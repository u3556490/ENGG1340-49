#include "main.h"
#include "filter.h"
#include "search.h"
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

// The following are functions that take user inputs of a certain type and return them
// and perform any input checks.
// Singled out to avoid code repetition.
string getString(){
	string buffer;
	cout << "Please enter the value you want to filter out:";
	std::getline(std::cin, buffer);
	return buffer;
}

int getInt(){
	bool input_ok = 0;
	string buffer;
	int value;
	while(!input_ok){
		cout << "Please enter the value you want to filter out: ";
		std::getline(std::cin, buffer);
		try{	//wow c++ exception handling seems interesting
			value = stoi(buffer);
		} catch (std::invalid_argument){
			cout << "Please check your input and try again.\n";
		}
		input_ok = 1;
	}
	return value;
}

bool getBool(){
	bool input_ok = 0;
	bool value;
	string buffer;
	while (!input_ok){
		cout << "Please enter 1 for true (set) and 0 for false (not set): ";
		cin >> buffer;
		if (buffer == "1"){
			value = 1;
			input_ok = 1;
		}
		else if (buffer == "0"){
			value = 0;
			input_ok = 1;
		}
		else
			cout << "Please check your input and try again.\n";
	}
	return value;
}

double getDouble(){
	bool input_ok = 0;
	string buffer;
	double value;
	while(!input_ok){
		cout << "Please enter the value you want to filter out: ";
		cin >> buffer;
		try{	//wow c++ exception handling seems interesting
			value = stod(buffer);
		} catch (std::invalid_argument){
			cout << "Please check your input and try again.\n";
		}
		input_ok = 1;
	}
	return value;
}

// --------------------------------------
// function filter: called when the user wills it.
// Take input on what to filer and whether the filter is to be unset.
// Must not overwrite the original inventory.
// @params vector<Commodity> original: original list of items.
// @return vector<Commodity>: vector of entries of the matches to display.
// --------------------------------------
vector<Commodity> filter(vector<Commodity> original, int &count){
	int filter_count = 0;
	bool quit = 0;
	vector<Commodity> selected = {};
	selected.reserve(10);
	vector<Commodity> * current = & original;
	
	if (original.size() < 2){
		cout << "No meaningful filtering is possible.\n";
		return selected;
	}
	
	while (!quit){
		string buffer;
		bool input_ok = 0;
		int criterion = 0;
		//get user input
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
		while (!input_ok){
			cout << "Please enter a number: ";
			cin >> buffer;
			criterion = atoi(buffer.c_str());
			if ((criterion < 1) || (criterion > 14)){
				cout << "Please check your input and try again." << endl;
			} else {
				input_ok = 1;
			}
		}
		if (criterion == 14){
			quit = 1;
			break;
		}
		cin.ignore();	//a fix for the getline's
		//get value to find and find the entries
		switch(criterion){
			case 1: {
				string value = getString();
				int result = idfindcom(*current, value);	//there exists only one match
				if (result == -1){
					cout << "Filtering unsuccessful: id " << value << " not found.\n";
				} else {
					selected.clear();
					selected.push_back((*current)[result]);
					cout << "Filter successfully set. The first item in the selected list is: \n";
					cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items filtered out.\n";
					filter_count++;
					current = & selected;
				}
				break;
			}
			case 2: {
				string value = getString();
				vector<int> result = name_search(*current, value);	
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
			case 3: {
				string value = getString();
				vector<int> result = manu_search(*current, value);	
				if (result.size() == 0){
					cout << "Filtering unsuccessful: manufacturer " << value << " not found.\n";
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
			case 4: {
				double value = getDouble();
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
			case 5: {
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
			case 6: {
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
			case 7: {
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
			case 8: {
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
			case 9: {
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
			case 10: {
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
			case 11: {
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
			case 12: {
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
			case 13: {
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
