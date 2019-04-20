#ifndef SEARCH
#define SEARCH
#include "main.h"
#include <vector>

/*
  Search algorithm
  A linear search through the list. The entire list is iterated through, 
  if all matches are to be found. A vector should be returned in this case.
*/

// Implement additional functions whenever needed.

// ------------------------------
// function search: called first. Accepts user input
// on what to search for and performs the search.
// The results should be returned as a vector containing
// the indices of the matched items.
// @params vector<Commodity> list: the list to search in.
// @return vector<int>: the indices of the matches.
// -------------------------------
std::vector<int> search(std::vector<main_header::Commodity> list);

#endif /* SEARCH */
