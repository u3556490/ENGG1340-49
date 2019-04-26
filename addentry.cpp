#include "main.h"
#include "addentry.h"
#include "inpututil.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
using namespace main_header;

// -----------------------------------
// Function add+one: adds ONE new commodity to the end of the list.
// @params Commodity item, the entry to add
//		   vector<Commodity> list, the inventory to add into
// @return none
// -----------------------------------
void add_one(vector<Commodity> &list, Commodity item){
	list.push_back(item);
}
// -----------------------------------
// Function add: adds new commodities to the list. Will be called
// immediately when the user wants to add stuff, so direct him to
// the right functions by calling them.
// @params vector<Commodity> list, the inventory to add into
// @return none
// -----------------------------------
void add(vector<Commodity> &list){
	cout << "How would you like to add the commodity?\n1. one-by-one manually\n2. through file\n";
	char input;
	cin >> input;
	if (input == "1"){
		Commodity com = getCommodityData();
		add_one(<Commodity> &list, Commodity com);
	}
	else if (input == "2"){
		Commodity com = getCommodityFile();
		add_one(<Commodity> &list, Commodity com);
	}
}

// -----------------------------------
// Function getCommodityData: gets data about a commodity 
// entry to be added via user input.
// @params none
// @return Commodity, a new commodity instance that holds the data
// -----------------------------------
// Requirements:
// 1. Get input one by one
// 2. Perform check on data if necessary
// 3. Give adequate error messages to user
// 4. Shove the stuff into a new Commodity instance
// -----------------------------------
Commodity getCommodityData(){
	
	Commodity com;
	
	string id, name, manufacturer, shop_id, expiry_date;
	double price; 
	int shop_amount, stock_amount, warning_level;

	cout << "Please enter the id below.\n";
	com.id = getString();
	cout << "Please enter the name below.\n";
	com.name = getString();
	cout << "Please enter the manufacturer below.\n";
	com.manufacturer = getString();
	cout << "Please enter the price below.\n";
	com.price = getDouble();
	cout << "Please enter the expiry date below.\n";
	com.expiry_date = getString();
	cout << "Please enter the stock amount below.\n";
	com.stock_amount = getInt();
	cout << "Please enter the warning level below.\n";
	com.warning_level = getInt();
	cout << "Please enter the shop id below.\n";
	com.shop_id = getString();
	cout << "Please enter the shop amount below.\n";
	com.shop_amount = getInt();
	
	return com;
	
	
}

// -----------------------------------
// Function getCommodityFile: gets data about a commodity 
// entry to be added via a file specified by user input.
// @params none
// @return Commodity, a new commodity instance that holds the data
// -----------------------------------
// TODO: figure out the layout of the file to read
// Requirements:
// 1. Get input file address
// 2. Perform check if file exists (can open)
// 3. Give adequate error messages to user
// 4. Shove the stuff into a new Commodity instance
// -----------------------------------
Commodity getCommodityFile(){
	ifstream ifs;
	ifs.open(address.c_str());
	if (ifs.fail()){
		cout << "Error occured opening the file." << endl;
		return list;
	}
	getline(ifs, line);		   
	stringstream ss (line);
	string token;
	getline(ss, token, ';');
	Commodity com;
	com.id = token;				
	getline(ss,token,';');
	com.name = token;			
	getline(ss,token,';');
	com.manufacturer = token;
	getline(ss,token,';');
	com.price = atof(token.c_str());	
	getline(ss,token,';');
	com.expiry_date = token;	
	getline(ss,token,';');
	com.stock_amount = atoi(token.c_str()); 
	getline(ss,token,';');
	com.warning_level = atoi(token.c_str()); 
	getline(ss,token,';');
	com.shop_id = token;			
	getline(ss,token,';');
	com.shop_amount = atoi(token.c_str()); 
	com.out_of_stock = 0;
	com.shop_out_of_stock = 0;
	com.shop_stock_warning = 0;
	com.stock_warning = 0;
		
	
	ifs.close();
	return com;
}

/*debug only
int main(){
	return 0;
}*/
