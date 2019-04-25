#include "main.h"
#include "search.h"
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
// @return vector<int>: the indices of the matches.
// -------------------------------
vector<int> search(vector<Commodity> list){
	
}

/* debug
int main(){
	return 0;
}*/
