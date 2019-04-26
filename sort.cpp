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
bool id_comp(Commodity c1, Commodity c2){	//id
	return (c1.id) < (c2.id);
}

bool name_comp(Commodity c1, Commodity c2){	//name
	return (c1.name) < (c2.name);
}

bool manu_comp(Commodity c1, Commodity c2){	//manufacturer
	return (c1.manufacturer) < (c2.manufacturer);
}

bool price_comp(Commodity c1, Commodity c2){	//price
	return (c1.price) < (c2.price);
}

bool date_comp(Commodity c1, Commodity c2){	//expiry date
	return (c1.expiry_date) < (c2.expiry_date);
}

bool stockamt_comp(Commodity c1, Commodity c2){		//stock amount
	return (c1.stock_amount) < (c2.stock_amount);
}

bool level_comp(Commodity c1, Commodity c2){	//warning level
	return (c1.warning_level) < (c2.warning_level);
}

bool warning_comp(Commodity c1, Commodity c2){	//if there are warnings
	return (c1.stock_warning);
}

bool outofstock_comp(Commodity c1, Commodity c2){	//out of stock
	return (c1.out_of_stock);
}

bool shopid_comp(Commodity c1, Commodity c2){	//shop id
	return (c1.shop_id) < (c2.shop_id);	
}

bool shopamt_comp(Commodity c1, Commodity c2){	//shop amomunt
	return (c1.shop_amount) < (c2.shop_amount);
}

bool swarning_comp(Commodity c1, Commodity c2){	//shop stock warning
	return (c1.shop_stock_warning);
}

bool soutofstock_comp(Commodity c1, Commodity c2){	//shop out of stock
	return (c1.shop_out_of_stock);
}

// --------------------------------------
// function sort_list: called when the user wills it.
// Take input based on which column should the sort be done.
// @params vector<Commodity> %original: original list of items.
// @return none
// --------------------------------------
void sort_list(vector<Commodity> &original){
	if (original.size() < 2){	//save some work
		cout << "The inventory is too small to sort meaningfully.\n";
		return;
	}
	
	bool sorted = 1;
	//get which column to sort by
	int col;	//sorting criterion = the column in the table.
	string buffer;	//input buffer
	bool input_ok = 0;	//for input checks
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Based on which attribute should the inventory be sorted?" << endl;
	cout << "1 for id" << endl;
	cout << "2 for name" << endl;
	cout << "3 for manufacturer" << endl;
	cout << "4 for price" << endl;
	cout << "5 for expiry date" << endl;
	cout << "6 for stock amount at warehouse" << endl;
	cout << "7 for stockpile warning level" << endl;
	cout << "8 for stockpile warning having ones first" << endl;
	cout << "9 for out of stock ones first" << endl;
	cout << "10 for shop id" << endl;
	cout << "11 for shop stockpile amount" << endl;
	cout << "12 for shop stockpile warning having ones first" << endl;
	cout << "13 for shop out of stock ones first" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	while (!input_ok){	//user input checking
		cout << "Please enter a number: ";
		cin >> buffer;
		col = atoi(buffer.c_str());	//check in range [1,13]
		if ((col < 1) || (col > 13)){
			cout << "Please check your input and try again.\n";
			sorted = 0;
		} else {
			input_ok = 1;
		}
	}
	//massive switch-case statement
	switch (col){
		case 1:{
			stable_sort(original.begin(), original.end(), id_comp);
			break;
		}
		case 2:{
			stable_sort(original.begin(), original.end(), name_comp);
			break;
		}
		case 3:{
			stable_sort(original.begin(), original.end(), manu_comp);
			break;
		}
		case 4:{
			stable_sort(original.begin(), original.end(), price_comp);
			break;
		}
		case 5:{
			stable_sort(original.begin(), original.end(), date_comp);
			break;
		}
		case 6:{
			stable_sort(original.begin(), original.end(), stockamt_comp);
			break;
		}
		case 7:{
			stable_sort(original.begin(), original.end(), level_comp);
			break;
		}
		case 8:{
			stable_sort(original.begin(), original.end(), warning_comp);
			break;
		}
		case 9:{
			stable_sort(original.begin(), original.end(), outofstock_comp);
			break;
		}
		case 10:{
			stable_sort(original.begin(), original.end(), shopid_comp);
			break;
		}
		case 11:{
			stable_sort(original.begin(), original.end(), shopamt_comp);
			break;
		}
		case 12:{
			stable_sort(original.begin(), original.end(), swarning_comp);
			break;
		}
		case 13:{
			stable_sort(original.begin(), original.end(), soutofstock_comp);
			break;
		}
	}
	if (sorted)	//message
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
