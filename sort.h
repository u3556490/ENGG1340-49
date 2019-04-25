#ifndef SORTINV
#define SORTINV
#include "main.h"
#include <vector>
#include <algorithm>

/* Algorithms for sorting
   Use std::sort but with a custom comparator function.
*/

// Implement additional functions whenever necessary
// Note: Comparator functions are local to sort.cpp

// --------------------------------------
// function sort_list: called when the user wills it.
// Take input based on which column should the sort be done.
// @params vector<Commodity> %original: original list of items.
// @return none
// --------------------------------------
void sort_list(std::vector<main_header::Commodity> &original);

// --------------------------------------
// function sort_id: Sorts the list by id, takes no user input.
// Invoked as the user imports an inventory, as an initialization
// measure.
// @params vector<Commodity> %original: original list of items.
// @return none
// --------------------------------------
void sort_id(std::vector<main_header::Commodity> &original);

#endif /* SORINV */
