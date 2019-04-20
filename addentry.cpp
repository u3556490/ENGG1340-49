#include "main.h"
#include "addentry.h"
#include <iostream>
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
	
}

// -----------------------------------
// Function add: adds new commodities to the list. Will be called
// immediately when the user wants to add stuff, so direct him to
// the right functions by calling them.
// @params vector<Commodity> list, the inventory to add into
// @return none
// -----------------------------------
void add(vector<Commodity> &list){
	
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
	
}

/*debug only
int main(){
	return 0;
}*/
