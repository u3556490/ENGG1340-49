#ifndef SORTINV
#define SORTINV
#include "main.h"
#include <vector>
#include <algorithm>

/* Algorithms for sorting
   Use std::sort but with a custom comparator function.
*/

// Implement additional functions whenever necessary

// --------------------------------------
// function sort_list: called when the user wills it.
// Take input based on which column should the sort be done.
// @params vector<Commodity> original: original list of items.
// @return vector<Commodity>: sorted list of items.
// --------------------------------------
std::vector<main_header::Commodity> sort_list(std::vector<main_header::Commodity> original);

#endif /* SORINV */
