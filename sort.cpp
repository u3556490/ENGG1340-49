#include "main.h"
#include "sort.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace main_header;

/* Algorithms for sorting
   Use std::sort but with a custom comparator function.
*/

// additional functions necessary
// Comparators
bool id_comp(Commodity c1, Commodity c2){
	return (c1.id) < (c2.id);
}

bool name_comp(Commodity c1, Commodity c2){
	return (c1.name) < (c2.name);
}

bool manu_comp(Commodity c1, Commodity c2){
	return (c1.manufacturer) < (c2.manufacturer);
}

bool price_comp(Commodity c1, Commodity c2){
	return (c1.price) < (c2.price);
}

bool date_comp(Commodity c1, Commodity c2){
	return (c1.expiry_date) < (c2.expiry_date);
}

bool stockamt_comp(Commodity c1, Commodity c2){
	return (c1.stock_amount) < (c2.stock_amount);
}

bool level_comp(Commodity c1, Commodity c2){
	return (c1.warning_level) < (c2.warning_level);
}

bool warning_comp(Commodity c1, Commodity c2){
	return (c1.stock_warning);
}

bool outofstock_comp(Commodity c1, Commodity c2){
	return (c1.out_of_stock);
}

bool shopid_comp(Commodity c1, Commodity c2){
	return (c1.shop_id) < (c2.shop_id);	
}

bool shopamt_comp(Commodity c1, Commodity c2){
	return (c1.shop_amount) < (c2.shop_amount);
}

bool swarning_comp(Commodity c1, Commodity c2){
	return (c1.shop_stock_warning);
}

bool soutofstock_comp(Commodity c1, Commodity c2){
	return (c1.shop_out_of_stock);
}

// --------------------------------------
// function sort_list: called when the user wills it.
// Take input based on which column should the sort be done.
// @params vector<Commodity> %original: original list of items.
// @return none
// --------------------------------------
void sort_list(vector<Commodity> &original){
	if (original.size() < 2){
		cout << "The inventory is too small to sort meaningfully.\n";
		return;
	}
	
	bool sorted = 1;
	//get which column to sort by
	char col;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Based on which attribute should the inventory be sorted?" << endl;
	cout << "(I) for id" << endl;
	cout << "(N) for name" << endl;
	cout << "(M) for manufacturer" << endl;
	cout << "(P) for price" << endl;
	cout << "(X) for expiry date" << endl;
	cout << "(A) for stock amount at warehouse" << endl;
	cout << "(L) for stockpile warning level" << endl;
	cout << "(W) for stockpile warning having ones first" << endl;
	cout << "(O) for out of stock ones first" << endl;
	cout << "(S) for shop id" << endl;
	cout << "(U) for shop stockpile amount" << endl;
	cout << "(R) for shop stockpile warning having ones first" << endl;
	cout << "(T) for shop out of stock ones first" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Enter a letter: ";
	cin >> col;
	col = toupper(col);
	//massive switch-case statement
	switch (col){
		case 'I':{
			stable_sort(original.begin(), original.end(), id_comp);
			break;
		}
		case 'N':{
			stable_sort(original.begin(), original.end(), name_comp);
			break;
		}
		case 'M':{
			stable_sort(original.begin(), original.end(), manu_comp);
			break;
		}
		case 'P':{
			stable_sort(original.begin(), original.end(), price_comp);
			break;
		}
		case 'X':{
			stable_sort(original.begin(), original.end(), date_comp);
			break;
		}
		case 'A':{
			stable_sort(original.begin(), original.end(), stockamt_comp);
			break;
		}
		case 'L':{
			stable_sort(original.begin(), original.end(), level_comp);
			break;
		}
		case 'W':{
			stable_sort(original.begin(), original.end(), warning_comp);
			break;
		}
		case 'O':{
			stable_sort(original.begin(), original.end(), outofstock_comp);
			break;
		}
		case 'S':{
			stable_sort(original.begin(), original.end(), shopid_comp);
			break;
		}
		case 'U':{
			stable_sort(original.begin(), original.end(), shopamt_comp);
			break;
		}
		case 'R':{
			stable_sort(original.begin(), original.end(), swarning_comp);
			break;
		}
		case 'T':{
			stable_sort(original.begin(), original.end(), soutofstock_comp);
			break;
		}
		default: {
			cout << "Please check your input and try again.";
			sorted = 0;
			break;
		}
	}
	if (sorted)
		cout << "Sorting successfully completed." << endl;
	else
		cout << "No sorting has been performed." << endl;
}

// --------------------------------------
// function sort_id: Sorts the list by id, takes no user input.
// Invoked as the user imports an inventory, as an initialization
// measure.
// @params vector<Commodity> %original: original list of items.
// @return none
// --------------------------------------
void sort_id(vector<Commodity> &original){
	stable_sort(original.begin(), original.end(), id_comp);
}

/*/debug only
int main(){
	return 0;
}*/
