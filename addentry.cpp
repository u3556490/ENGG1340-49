#include "main.h"
#include "addentry.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace main_header;

// -----------------------------------
// Function add: adds the new commodity to the end of the list.
// @params Commodity commodity, the entry to add
//		   vector<Commodity> list, the inventory to add into
// @return none
// -----------------------------------
// Use functions under the vector header
// Be aware of the capacity of the list and extend if necessary
// (There should be functions that perform this flawlessly)
// Note that pushback may be a bit slow but shouldn't be much of an issue
// -----------------------------------
void add(Commodity commodity, vector<Commodity> list){
	
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
// Function getCommodityData: gets data about a commodity 
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
