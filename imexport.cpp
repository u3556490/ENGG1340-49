#include "main.h"
#include "imexport.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
using namespace main_header;

const int INIT_INVENTORY_SIZE = 50;

// -----------------------------
// function import_file: reads an address from the user and imports a
// whole inventory from that address.
// @params none
// @return vector<Commodity>: the inventory obtained
// -----------------------------
vector<Commodity> import_file(){
	vector<Commodity> list = {};				//a temporary list of commodities to save things into
	list.reserve(INIT_INVENTORY_SIZE);
	string address;		//address of input file
	string line;		//buffer
	
	//user warning and get address
	cout << "Regarding the file's format: Attributes are separated by semicolons and one leaves no new line at the end of the file,";
	cout << "which is to be saved as a text file. The attributes come in order of id, name, manufacturer, unit price, expiry date (ddmmyyyy)";
	cout << ", stock amount, stock warning level, shop id, shop stockpile amount. Each line is an entry in the inventory." << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Enter the address of the inventory file with file extension: ";
	cin >> address;
	
	//open file
	ifstream ifs;
	ifs.open(address.c_str());
	if (ifs.fail()){	//error
		cout << "Error occured opening the file." << endl;
		return list;	//return nothing
	}
	
	//take inputs from file
	while(ifs.good()){
		getline(ifs, line);		   //get one line (one entry)
		//split by special chars
		stringstream ss (line);
		string token;
		getline(ss, token, ';');	//attributes should be ; separated
		Commodity com;
		com.id = token;				//id
		getline(ss,token,';');
		com.name = token;			//second attribute: name
		getline(ss,token,';');
		com.manufacturer = token;	//manufacturer
		getline(ss,token,';');
		com.price = atof(token.c_str());	//price
		getline(ss,token,';');
		com.expiry_date = token;	//expiry date
		getline(ss,token,';');
		com.stock_amount = atoi(token.c_str()); //stock amt
		getline(ss,token,';');
		com.warning_level = atoi(token.c_str()); //level
		getline(ss,token,';');
		com.shop_id = token;			//shop id
		getline(ss,token,';');
		com.shop_amount = atoi(token.c_str()); //shop amt
		com.out_of_stock = 0;	//set to false. will be updated upon stock checks which are automatically run
		com.shop_out_of_stock = 0;
		com.shop_stock_warning = 0;
		com.stock_warning = 0;
		
		list.push_back(com);	//add to list
		
	}
	
	ifs.close();	//close file
	
	/*/debug use
	for (vector<Commodity>::iterator i = list.begin(); i != list.end(); i++){
		cout << (*i).id << ";" << (*i).name << ";" << (*i).manufacturer << ";" << (*i).price << ";" << (*i).expiry_date << ";";
		cout << (*i).stock_amount << ";" << (*i).warning_level << ";" << (*i).shop_id << ";" << (*i).shop_amount << ";\n";
	}*/
	
	cout << "Import successful. " << list.size() << " entries retrieved from file." << endl;
	return list;	//return list.
}

// -----------------------------
// function export_file: reads an address from the user and exports the
// current inventory to that address.
// @params vector<Commodity>* list: the inventory to export
// @return bool: whether the action is successful.
// -----------------------------
bool export_file(vector<Commodity>* list){
	bool success = 0;		//action successful?
	string address = "";	//address
	
	//warning and get address
	cout << "Regarding the file's format: Each attribute are separated by semicolons";
	cout << " and there will be no new line at the end of the file,";
	cout << "which will be saved as a text file. The attributes come in order of id, ";
	cout << "name, manufacturer, unit price, expiry date (ddmmyyyy)";
	cout << ", stock amount, stock warning level, shop id, shop stockpile amount. ";
	cout << "Each line is an entry in the inventory." << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Enter the name of the output file with file extension: ";
	cin >> address;
	
	//open file
	ofstream ofs;
	ofs.open(address.c_str());
	if (ofs.fail()){	//handle error
		success = 0;
		cout << "Error occured writing to file." << endl;
		return success;
	}
	success = 1;	//will work ga la
	
	//for each item
	for (vector<Commodity>::iterator i = list->begin(); i != list->end(); i++){
		//unpack contents and write
		Commodity com = *i;
		ofs << com.id << ";" << com.name << ";" << com.manufacturer << ";" << com.price << ";" << com.expiry_date << ";" << com.stock_amount << ";";
		ofs << com.warning_level << ";" << com.shop_id << ";" << com.shop_amount;
		if ((i+1) != list->end())	//no end of line characters for the last entry
			ofs << endl;
	}
	
	ofs.close();	//close file
	cout << "Export successful. " << list->size() << " entries written to file." << endl;
	return success;	//return
}

/*
int main(){
	import_file();
	return 0;
}*/

