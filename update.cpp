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
	
	cout << "How would you like to update the commodity?\n";               //ask the user the method to perform the update
	cout << "1. one-by-one manually\n";
	cout << "2. by importing from a file\n";
	cout << "3. go back\n";
	cout << "--------------------------------------------------------\n";
	cout << "Please enter a number: ";
	char input;
	cin >> input;
	if (input == '2'){
		getUpdateFile(list);      
	}
	else if (input == '3'){
		return;
	}
	else if (input == '1'){
		while (not exit){
			string id;
			int index;
			input_ok = 0;
			while (not input_ok){
				cout << "Enter the id of the item to edit.\n";
				cout << "Enter '-1' (without quotes) to finish and quit.\n";	
				id = getString();
			        	if (id == "-1"){
						exit = true; 
						return;
					}
				index = idfindcom(list, id);
				if (index == -1){
					cout << "The input id cannot be found. Please try again.\n";
				}
				else{
					input_ok = true;
				}
			}
			bool choice_ok = false; 
			int choice;
			while (not choice_ok){		
				cout << "Which criteria are you going to use to edit?" << endl;   //show the list of criteria to the user
				cout << "1. id\n";
				cout << "2. name\n";
				cout << "3. manufacturer\n";
				cout << "4. price\n";
				cout << "5. expiry date\n";
				cout << "6. stock amount\n";
				cout << "7. warning level\n";
				cout << "8. shop id\n";
				cout << "9. shop stock amount\n";
				cout << "--------------------------------------------------------\n";
				while (!choice_ok){
					cout << "Please enter a number: ";
					cin >> buffer;
					choice = atoi(buffer.c_str());
					if ((criterion < 1) || (criterion > 9)){
						cout << "Please check your input and try again." << endl;
					} 
					else {
						choice_ok = 1;
					}
				}
			}
			switch (choice){                 //using switch to perform different update.
				case 1: { 
					cout << "Modifying id of item " << list[index].id << " : " << list[index].name << ".\n";
					string value = getString();
					int num = idfindcom(list, value);
					if (num == -1){
						cout << "There is contradiction to the entry ids. No changes has been made.\n";
					} 
					else {
						list[index].id = value;
						cout << "Action successfully performed.\n";
					}
					break;
				}
				case 2: {
					cout << "Modifying name of item " << list[index].id << " : " << list[index].name << ".\n";
					string value = getString();
					list[index].name = value; 
					cout << "Action successfully performed.\n";
					break; 
				}
				case 3: {
					cout << "Modifying manufacturer of item " << list[index].id << " : " << list[index].name << ".\n";
					string value = getString();
					list[index].manufacturer = value; 
					cout << "Action successfully performed.\n";
					break; 
				}
				case 4: {
					cout << "Modifying unit price of item " << list[index].id << " : " << list[index].name << ".\n";
					double value = getDouble();
					list[index].price = value;
					cout << "Action successfully performed.\n";
					break;
				}
				case 5: {
					cout << "Modifying expiry date of item " << list[index].id << " : " << list[index].name << ".\n";
					string value = getString();
					list[index].expiry_date = value; 
					cout << "Action successfully performed.\n";
					break; 
				}
				case 6: {
					cout << "Modifying stock amount of item " << list[index].id << " : " << list[index].name << ".\n";
					int value = getInt();
					list[index].stock_amount = value; 
					cout << "Action successfully performed.\n";
					break; 
				}
				case 7: {
					cout << "Modifying warning level of item " << list[index].id << " : " << list[index].name << ".\n";
					int value = getInt();
					list[index].warning_level = value; 
					cout << "Action successfully performed.\n";
					break; 
				}
				case 8: {
					cout << "Modifying shop id of item " << list[index].id << " : " << list[index].name << ".\n";
					string value = getString();
					list[index].shop_id = value;
					cout << "Action successfully performed.\n";
					break; 
				}
				case 9: {
					cout << "Modifying shop stock amount of item " << list[index].id << " : " << list[index].name << ".\n";
					int value = getInt();
					list[index].shop_stock_amount = value;
					cout << "Action successfully performed.\n";
					break; 
				}                  //there is reminders telling the users error has been occured in each case :)
			}
		}
	} 
	else{
		cout << "Incorrect option. No updating has been performed.\n";
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
	
	cout << "Regarding the file's format: The first line is an integer n, indicating n amendments to be made.";
	cout << "The following n lines are the n amendments. Each line contains 3 fields: 1st one is the id of";
	cout << "the item to work on, 2nd one is a mnemonic (abbreviation) of the attribute to change and ";
	cout << "the 3rd one is the value to change to. The fields are semicolon (;) separated." << endl; 
	cout << "There should not be any empty lines at the end of the file. The last field should end with a semicolon." << endl;
	cout << "Attribute full name (left) and mnemonic (right) correspondence list for reference: " << endl;
	cout << "ID: id" << endl;
	cout << "Name: name" << endl;
	cout << "Manufacturer: manu" << endl;
	cout << "Unit price: price" << endl;
	cout << "Expiry date: date" << endl;                              //clear instruction to the users how this function runs
	cout << "Amount at HQ/Warehouse: amt" << endl;
	cout << "Warning level: level" << endl;                                
	cout << "Shop ID: shop" << endl;
	cout << "Amount at shop: samt" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Enter the address of the update file with file extension: ";
	cin >> address;
	
	ifs.open(address.c_str());
	if (ifs.fail()){
		cout << "Error occured opening the file." << endl;
		return;	//!
	}
	
	string buffer;
	std::getline(ifs, buffer);
	int n = atoi(buffer.c_str());
	if (n < 1){
		cout << "The number of updates is incorrect! No changes have been made.\n";
	}
	else{
		for (int i = 0; i < n; i++){
			std::getline(ifs, buffer);
			stringstream ss (buffer);
			string token;
			getline(ss,token,';');
			cout << "Processing update " << i+1 << " of " << n << ": Editing item " << token << "......\n"; 	
			int index = idfindcom(list, token);
			if (index == -1){
				cout << "The item cannot be found! Skipping to next update.\n";
			}
			else{
				getline(ss,token,';');
				string column = token;
				getline(ss,token,';');
				string value = token;      //using criteria to seperate different case
				
				if (column == "id"){
					if (idfindcom(list, value) != -1){
						cout << "The new id specified is in conflict with a preexisting one.\n";
					} 
					else {
						list[index].id = value;
						cout << "New id (" << value << ") given to item.\n";
					}
				}
				else if (column == "name"){
					list[index].name = value;
					cout << "New name (" << value << ") given to item.\n";
				}
				else if (column == "manu"){
					list[index].manufacturer = value;
					cout << "New manufacturer name (" << value << ") given to item.\n";
				}
				else if (column == "price"){
					double preis = atof(value.c_str());
					if (preis < 0){
						cout << "The new price specified is invalid.\n";
					} 
					else {
						list[index].price = preis;
						cout << "New name (" << value << ") given to item.\n";
					}
				}
				else if (column == "date"){
					list[index].expiry_date = value;
					cout << "New expiry date (" << value << ") given to item.\n";
				}
				else if (column == "amt"){
					int amt = atoi(value.c_str());
					if (amt < 0){
						cout << "The new amount specified is invalid.\n";
					} 
					else {
						list[index].stock_amount = amt;
						cout << "New stock amount (" << value << ") given to item.\n";
					}
				}
				else if (column == "level"){
					int level = atoi(value.c_str());
					if (level < 0){
						cout << "The new amount specified is invalid.\n";
					} 
					else {
						list[index].warning_level = level;
						cout << "New stock amount (" << value << ") given to item.\n";
					}
				}
				else if (column == "shop"){
					list[index].shop_id = value;
					cout << "New shop id (" << value << ") given to item.\n";
				}
				else if (column == "samt"){
					int amt = atoi(value.c_str());
					if (amt < 0){
						cout << "The new amount specified is invalid.\n";
					} 
					else {
						list[index].shop_amount = amt;
						cout << "New shop stock amount (" << value << ") given to item.\n";
					}
				}
				else{
					cout << "Incorrect mnemonic. Skipping to next update.\n";
				}
			}
		}
		cout << "Action successfully performed.\n"; 
	}
	ifs.close();
}

/*debug only
int main(){
	return 0;
}*/
