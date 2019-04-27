#include "main.h"
#include "search.h"
#include "inpututil.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace main_header;

/*
  Search algorithm
  A linear search through the list. The entire list is iterated through, 
  if all matches are to be found. A vector should be returned in this case.
*/

// <!!!!!> The main search function is at the bottom of this file.
// When it gets too unwieldy and lengthy, consider creating a new cpp to accomodate
// the main search function instead. </!!!!!>
// Implement additional functions whenever needed.

// ------------------------------
// function comexist: a bruteforce linear search through the list,
// to find an entry with the id specified. If found, returns true,
// false otherwise. Thereby checks if the commodity with the associated
// id exists in the list.
// Assumptions: list is not sorted by id; id's are unique.
// !!!!! Likely redundant but do not remove yet. !!!!!
// @params vector<Commodity> list: the inventory to look through
// 		   string tag: the id to look for
// @return bool: whether the desired entry is found.
// ------------------------------
bool comexist(vector<Commodity> list, string tag){
	bool found = 0;
	for (vector<Commodity>::iterator i = list.begin(); i!=list.end(); i++){
		if ((*i).id == tag){
			found = 1;
			break;
		}
	}
	return found;
}

// ------------------------------
// function idfindcom: a bruteforce linear search through the list,
// to find an entry with the id specified. If found, returns its position,
// -1 otherwise.
// Assumptions: list is not sorted by id; id's are unique.
// @params vector<Commodity> list: the inventory to look through
// 		   string tag: the id to look for
// @return int: position of the commodity entry.
// ------------------------------
int idfindcom(vector<Commodity> list, string tag){
	int pos = -1;
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i!=list.end(); i++){
		if ((*i).id == tag){
			pos = index;
			break;
		}
		index++;
	}
	return pos;
}

// -------------------------------
// function name_search: searches through the ENTIRE given list in a linear
// way, returns the index of the entry element when its name matches the given
// tag. Assumes the list is not sorted in order of name.
// @params vector<Commodity> list: the list to plough through
//         string tag: the name to look for
// @return vector<int> a list of indices at which the required items are found.
// Check return vector size > 0 to prevent tragedies.
// -------------------------------
vector<int> name_search(vector<Commodity> list, string tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).name == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// -------------------------------
// function manu_search: Please see name_search for more details. Looks for manufacturer (String) instead.
// -------------------------------
vector<int> manu_search(vector<Commodity> list, string tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).manufacturer == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// -------------------------------
// function date_search: Please see name_search for more details. Looks for expiry dates (String) instead.
// -------------------------------
vector<int> date_search(vector<Commodity> list, string tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).expiry_date == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// -------------------------------
// function shopid_search: Please see name_search for more details. Looks for shop id (String) instead.
// -------------------------------
vector<int> shopid_search(vector<Commodity> list, string tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).shop_id == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// -------------------------------
// function price_search: Please see name_search for more details. Looks for price (Double) instead.
// -------------------------------
vector<int> price_search(vector<Commodity> list, double tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).price == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// -------------------------------
// function stockamt_search: Please see name_search for more details. Looks for stock amount (int) instead.
// -------------------------------
vector<int> stockamt_search(vector<Commodity> list, int tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).stock_amount == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// -------------------------------
// function level_search: Please see name_search for more details. Looks for warning level (int) instead.
// -------------------------------
vector<int> level_search(vector<Commodity> list, int tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).warning_level == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// -------------------------------
// function shopamt_search: Please see name_search for more details. Looks for shop stock amount (int) instead.
// -------------------------------
vector<int> shopamt_search(vector<Commodity> list, int tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).shop_amount == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// -------------------------------
// function stockwarn_search: Please see name_search for more details. Looks for stock low warning (bool) instead.
// -------------------------------
vector<int> stockwarn_search(vector<Commodity> list, bool tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).stock_warning == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// -------------------------------
// function shopwarn_search: Please see name_search for more details. Looks for shop stock low warning (bool) instead.
// -------------------------------
vector<int> shopwarn_search(vector<Commodity> list, bool tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).shop_stock_warning == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// -------------------------------
// function stockout_search: Please see name_search for more details. Looks for out of stock status flag (bool) instead.
// -------------------------------
vector<int> stockout_search(vector<Commodity> list, bool tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).out_of_stock == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// -------------------------------
// function shopout_search: Please see name_search for more details. Looks for shop out of stock status flag (bool) instead.
// -------------------------------
vector<int> shopout_search(vector<Commodity> list, bool tag){
	vector<int> result;
	result.reserve(10);
	int index = 0;
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		if ((*i).shop_out_of_stock == tag){
			result.push_back(index);
		}
		index++;
	}
	return result;
}

// ------------------------------
// function search: called first. Accepts user input
// on what to search for and performs the search.
// The results should be returned as a vector containing
// the indices of the matched items.
// @params vector<Commodity> list: the list to search in.
// @return vector<Commodity>: the matches.
// -------------------------------
vector<Commodity> search(vector<Commodity> list){
	string buffer;
	bool input_ok = 0;
	int criterion = 0;
	vector<Commodity> selected;
	
	cout << "Which criteria are you going to use to search?" << endl;        //using a clear table to show the criterias
	cout << "1. id\n";
	cout << "2. name\n";
	cout << "3. manufacturer\n";
	cout << "4. price\n";
	cout << "5. expiry date\n";
	cout << "6. stock amount\n";
	cout << "7. warning level\n";
	cout << "8. stock warning\n";
	cout << "9. out of stock\n";
	cout << "10. shop id\n";
	cout << "11. shop stock amount\n";
	cout << "12. shop stock warning\n";
	cout << "13. shop out of stock\n";
	cout << "--------------------------------------------------------\n";
	while (!input_ok){
		cout << "Please enter a number: ";
		cin >> buffer;
		criterion = atoi(buffer.c_str());
		if ((criterion < 1) || (criterion > 13)){
			cout << "Please check your input and try again." << endl;
		} else {
			input_ok = 1;
		}
	}
	
	switch(criterion){					//using switch to seperate different cases
		case 1: {
			string value = getString();
			int result = idfindcom(list, value);	
			if (result == -1){
				cout << "Searching unsuccessful: id " << value << " not found.\n";
			} 
			else {
				selected.clear();
				selected.push_back((list)[result]);
				cout << "Search successfully set. \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". \n";
			}
			break;
		}
		case 2: {
			string value = getString();
			vector<int> result = name_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: name " << value << " not found.\n";
			} 
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
					selected.push_back((list)[(*i)]);	
				}
				cout << "Search successfully set. The first item in the selected list is: \n";		
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}
		case 3: {
			string value = getString();
			vector<int> result = manu_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: manufacturer " << value << " not found.\n";
			} 
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
				selected.push_back((list)[(*i)]);	
				}
				cout << "Search successfully set. The first item in the selected list is: \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}
		case 4: {
			double value = getDouble();
			vector<int> result = price_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: expiry date " << value << " not found.\n";
			} 
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
					selected.push_back((list)[(*i)]);	
				}
				cout << "Search successfully set. The first item in the selected list is: \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}
		case 5: {
			string value = getString();
			vector<int> result = date_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: expiry date " << value << " not found.\n";
			}
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
					selected.push_back((list)[(*i)]);	
				}
				cout << "Search successfully set. The first item in the selected list is: \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}
		case 6: {
			int value = getInt();
			vector<int> result = stockamt_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: expiry date " << value << " not found.\n";
			} 
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
					selected.push_back((list)[(*i)]);	
				}
				cout << "Search successfully set. The first item in the selected list is: \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}
		case 7: {
			int value = getInt();
			vector<int> result = level_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: expiry date " << value << " not found.\n";
			} 
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
					selected.push_back((list)[(*i)]);	
				}
				cout << "Search successfully set. The first item in the selected list is: \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}	
		case 8: {
			bool value = getBool();
			vector<int> result = stockwarn_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: expiry date " << value << " not found.\n";
			} 
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
					selected.push_back((list)[(*i)]);	
				}
				cout << "Search successfully set. The first item in the selected list is: \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}
		case 9: {
			bool value = getBool();
			vector<int> result = stockout_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: expiry date " << value << " not found.\n";
			}
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
					selected.push_back((list)[(*i)]);	
				}
				cout << "Search successfully set. The first item in the selected list is: \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}
		case 10: {
			string value = getString();
			vector<int> result = shopid_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: expiry date " << value << " not found.\n";
			}
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
					selected.push_back((list)[(*i)]);	
				}
				cout << "Search successfully set. The first item in the selected list is: \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}
		case 11: {
			int value = getInt();
			vector<int> result = shopamt_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: expiry date " << value << " not found.\n";
			}
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
					selected.push_back((list)[(*i)]);	
					}
				cout << "Search successfully set. The first item in the selected list is: \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}
		case 12: {
			bool value = getBool();
			vector<int> result = shopwarn_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: expiry date " << value << " not found.\n";
			} 
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
					selected.push_back((list)[(*i)]);	
				}
				cout << "Search successfully set. The first item in the selected list is: \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}
		case 13: {
			bool value = getBool();
			vector<int> result = shopout_search(list, value);	
			if (result.size() == 0){
				cout << "Searching unsuccessful: expiry date " << value << " not found.\n";
			} 
			else {
				selected.clear();
				for (vector<int>::iterator i = result.begin(); i != result.end(); i++){
					selected.push_back((list)[(*i)]);	
				}
				cout << "Search successfully set. The first item in the selected list is: \n";
				cout << (selected[0]).id << " \"" << (selected[0]).name << "\". Totally " << selected.size() << " items searched out.\n";
			}
			break;
		}
	}
	return selected;
}
	

/* debug
int main(){
	return 0;
}*/
