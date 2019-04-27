#include "main.h"
#include "printinv.h"
#include <iostream>
using namespace std;
using namespace main_header;

// ---------------------------------
// function print_inv: prints out the contents of
// the inventory specified.
// TODO: think how to present the information
// @params vector<Commodity> list: the list to print
// @return none
// ---------------------------------
void print_inv(vector<Commodity> list){
	bool exit = 0;
	string buffer;
	bool input_ok = 0;
	int criterion = 0;
	int index;
	vector<Commodity>::iterator position = list.begin();
	while (not exit){
		cout << "------------------------------------------------------\n";
		cout << "Commodity id: " << (*position).id << endl;
		cout << "Commodity name: " << (*position).name << endl;
		cout << "Commodity manufacturer: " << (*position).manufacturer << endl;
		cout << "Commodity price: " << (*position).price << endl;
		cout << "Commodity expiry date: " << (*position).expiry_date << endl;
		cout << "Commodity stock amount: " << (*position).stock_amount << endl;
		cout << "Commodity warning level: " << (*position).warning_level << endl;
		cout << "Commodity stock warning: " << (*position).stock_warning << endl;
		cout << "Commodity out of stock;: " << (*position).out_of_stock << endl;
		cout << "Commodity shop id: " << (*position).shop_id << endl;
		cout << "Commodity shop amount: " << (*position).shop_amount << endl;
		cout << "Commodity shop stock warning: " << (*position).shop_stock_warning << endl;
		cout << "Commodity shop out of stock: " << (*position).shop_out_of_stock << endl;
		cout << "------------------------------------------------------\n";
		cout << "What action would you like to take?\n";
		cout << "1. go to next item\n";
		cout << "2. jump to an item\n";
		cout << "3. return to the menu\n";
	
		while (!input_ok){
			cout << "Please enter a number: ";
			cin >> buffer;
			criterion = atoi(buffer.c_str());
			if ((criterion < 1) || (criterion > 3)){
				cout << "Please check your input and try again." << endl;
			} 
			else {
				input_ok = 1;
			}
		}
		input_ok = 0;
	
		switch(criterion){
			case 1: {
				position++;
				if (position == list.end()) 
					exit = true; 
				break;
			}
			case 2: {
				cout << "Please enter an integer x, such that we skip to the x-th item: ";
				cin >> index;
				index--;	//indicies begin at zero
				if ((index > 0 ) && (index <= list.size()))
					position = list.begin() + index;
				else 
					cout << "Please check your input.\n";
				break;
			}
			case 3: {
				exit = true; 
				break; 
			}
			default: cout << "There is an error in your input" << endl;
		}
	}
}

/*
int main(){
return 0;
}
*/
