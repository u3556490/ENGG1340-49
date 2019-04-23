#ifndef STOCKALERT
#define STOCKALERT
#include "main.h"
#include <vector>

// ----------------------------
// function setOneLevel: sets warning level of commodity entry
// specified to the value given.
// @params Commodity com: the commodity to manipulate
//         int level: the level to set to
// @return none
// ----------------------------
void setOneLevel(main_header::Commodity com, int level);

// ----------------------------
// function setLevel: gets call upon level change prompt.
// @params vector<Commodity> list: the inventory to manipulate
// @return none
// ----------------------------
void setLevel(std::vector<main_header::Commodity> list);

// ----------------------------
// function check_stock: loops through the whole inventory to find entries whose
// stock amount at shop or at HQ is below the warning level.
// @params vector<Commodity> list: the list to look through
// @return vector<int>: a list of indices of items that are having issues
// ----------------------------
std::vector<int> check_stock(std::vector<main_header::Commodity> list);

#endif /* STOCKALERT */
