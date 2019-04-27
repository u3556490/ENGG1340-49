#ifndef UPDATE
#define UPDATE
#include "main.h"
#include <vector>

// -------------------------------------
// Function update: will be called immediately when
// the user wants to update the inventory. Lead him to the right functions.
// @params vector<Commodity> &list: the inventory to modify
// @return none
// -------------------------------------
void update(std::vector<main_header::Commodity> &list);

// -----------------------------------
// Function getUpdateFile: gets data about an inventory update 
// to be performed according to a file specified by user input.
// By update, it is meant that the contents of the whole inventory
// could be changed.
// @params none
// @return none
// -----------------------------------
// TODO: figure out the layout of the file to read
void getUpdateFile(std::vector<main_header::Commodity> &list);

#endif /*UPDATE*/
