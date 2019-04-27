#include "main.h"
#include "update.h"
#include "search.h"
#include "inpututil.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace main_header;
using namespace std;

// -------------------------------------
// Function update: will be called immediately when
// the user wants to update the inventory. Lead him to the right functions
// and loop them (e.g. update_one() should be looped when multiple entries are
// to be updated) whenever necessary.
// @params vector<Commodity> &list: the inventory to modify
// @return none
// -------------------------------------
void update(vector<Commodity> &list){
	bool exit = 0;
	string buffer;
	bool input_ok = 0;
	int criterion = 0;
	
	cout << "How would you like to update the commodity?\n";
	cout << "1. one-by-one manually\n";
	cout << "2. go back\n";
	cout << "Please enter a number: ";
	char input;
	cin >> input;
	if (input == '1'){
		Commodity com = getCommodityData();
		add_one(list, com);
	}
	else if (input == '2'){
		return;
	}
	else{
		while (not exit){
			int index;
			while (not input ok){
				cout << "What would you like to do?\n";
				cout << "1.Enter an id\n";
				cout << "2.Type -1 to exit\n";
				cin >> index; 
				
			        if (input == -1){
					exit = true; 
					return;
				}
				index = idfindcom
				if (index == -1){
					cout << "The input id cannot be found\n";
				}
				else{
					input ok = true;
				}
			}
			input ok = false; 
			int choice;
			while (not input ok){		
				cout << "Which criteria are you going to use to edit?" << endl;
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
					} 
					else {
						input_ok = 1;
					}
				}
			}
			switch (criterion){
				case 1: { 
					string value = getString();
					int num = idfindcom(list, value);
					if (num == -1){
						cout << "There is contradiction to the entry ids.\n";
					} 
					else {
						list[index].id = value;
					}
					break;
				}
				case 2: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].name = value; 
					break; 
				}
				case 3: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].manufacturer = value; 
					break; 
				}
				case 4: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].price = value;
					break;
				}
				case 5: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].expiry_date = value; 
					break; 
				}
				case 6: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].stock_amount = value; 
					break; 
				}
				case 7: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].warning_level = value; 
					break; 
				}
				case 8: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].stock_warning = value; 
					break; 
				}
				case 9: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].out_of_stock = value; 
					break; 
				}
				case 10: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].shop_id = value;
					break; 
				}
				case 11: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].shop_stock_amount = value; 
					break; 
				}
				case 12: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].shop_stock_warning = value; 
					break; 
				}
				case 13: {
					string value = getString();
					vector<int> nums = idfindcom(list, value);
					list[index].shop_out_of_stock = value; 
					break; 
				}
			}
		}
	} 
}

// -----------------------------------
// Function getUpdateFile: gets data about an inventory update 
// to be performed according to a file specified by user input.
// By update, it is meant that the contents of the whole inventory
// could be changed, i.e. additions, removals and amendments should be
// supported. For amendments, see the algorithm stated above.
// @params none
// @return none
// -----------------------------------
// TODO: figure out the layout of the file to read
void getUpdateFile(vector<Commodity> &list){
	ifstream ifs;
	string address;
	
	cout << "Regarding the file's format: Attributes are separated by semicolons and one leaves no new line at the end of the file,";
	cout << "which is to be saved as a text file. The attributes come in order of id, name, manufacturer, unit price, expiry date (ddmmyyyy)";
	cout << ", stock amount, stock warning level, shop id, shop stockpile amount. Each line is an entry in the inventory." << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Enter the address of the inventory file with file extension: ";
	cin >> address;
	
	ifs.open(address.c_str());
	if (ifs.fail()){
		cout << "Error occured opening the file." << endl;
	}
	ifs.close();
}

/*debug only
int main(){
	return 0;
}*/
