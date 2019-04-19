#ifndef ADDENTRY
#define ADDENTRY
#include <vector>
#include "main.h"

// -----------------------------------
// Function add+one: adds ONE new commodity to the end of the list.
// @params Commodity item, the entry to add
//		   vector<Commodity> list, the inventory to add into
// @return none
// -----------------------------------
void add_one(std::vector<main_header::Commodity> &list, main_header::Commodity item);

// -----------------------------------
// Function add: adds new commodities to the list. Will be called
// immediately when the user wants to add stuff, so direct him to
// the right functions by calling them.
// @params vector<Commodity> list, the inventory to add into
// @return none
// -----------------------------------
void add(std::vector<main_header::Commodity> &list);

// -----------------------------------
// Function getCommodityData: gets data about a commodity 
// entry to be added via user input.
// @params none
// @return Commodity, a new commodity instance that holds the data
// -----------------------------------
main_header::Commodity getCommodityData();

// -----------------------------------
// Function getCommodityFile: gets data about a commodity 
// entry to be added via a file specified by user input.
// @params none
// @return Commodity, a new commodity instance that holds the data
// -----------------------------------
// TODO: figure out the layout of the file to read
main_header::Commodity getCommodityFile();

#endif /* ADDENTRY */
