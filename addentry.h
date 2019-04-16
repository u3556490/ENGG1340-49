#ifndef ADDENTRY
#define ADDENTRY
#include <vector>
#include "main.h"

// -----------------------------------
// Function add: adds the new commodity to the end of the list.
// @params Commodity commodity, the entry to add
//		   vector<Commodity> list, the inventory to add into
// @return none
// -----------------------------------
void add(main_header::Commodity commodity, std::vector<main_header::Commodity> list);

// -----------------------------------
// Function getCommodityData: gets data about a commodity 
// entry to be added via user input.
// @params none
// @return Commodity, a new commodity instance that holds the data
// -----------------------------------
main_header::Commodity getCommodityData();

// -----------------------------------
// Function getCommodityData: gets data about a commodity 
// entry to be added via a file specified by user input.
// @params none
// @return Commodity, a new commodity instance that holds the data
// -----------------------------------
// TODO: figure out the layout of the file to read
main_header::Commodity getCommodityFile();

#endif /* ADDENTRY */
