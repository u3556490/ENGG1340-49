#ifndef SEARCH
#define SEARCH
#include "main.h"
#include <vector>
#include <string>

/*
  Search algorithm
  A linear search through the list. The entire list is iterated through, 
  if all matches are to be found. A vector should be returned in this case.
*/

// Implement additional functions whenever needed.

// ------------------------------
// function comexist: a bruteforce linear search through the list,
// to find an entry with the id specified. If found, returns true,
// false otherwise. Thereby checks if the commodity with the associated
// id exists in the list.
// Assumptions: list is not sorted by id; id's are unique.
// @params vector<Commodity> list: the inventory to look through
// 		   string tag: the id to look for
// @return bool: whether the desired entry is found.
// ------------------------------
bool comexist(std::vector<main_header::Commodity> list, std::string tag);

// ------------------------------
// function idfindcom: a bruteforce linear search through the list,
// to find an entry with the id specified. If found, returns its position,
// -1 otherwise.
// Assumptions: list is not sorted by id; id's are unique.
// @params vector<Commodity> list: the inventory to look through
// 		   string tag: the id to look for
// @return int: position of the commodity entry.
// ------------------------------
int idfindcom(std::vector<main_header::Commodity> list, std::string tag);

// -------------------------------
// function name_search: searches through the ENTIRE given list in a linear
// way, returns the index of the entry element when its name matches the given
// tag. Assumes the list is not sorted in order of name.
// @params vector<Commodity> list: the list to plough through
//         string tag: the name to look for
// @return vector<int> a list of indices at which the required items are found.
// Check return vector size > 0 to prevent tragedies.
// -------------------------------
std::vector<int> name_search(std::vector<main_header::Commodity> list, std::string tag);
// The following are spinoffs of this same subroutine, searching other things instead.
// A slightly more lengthy explanation is in search.cpp, but I believe these are self-explanatory.
std::vector<int> manu_search(std::vector<main_header::Commodity> list, std::string tag);
std::vector<int> date_search(std::vector<main_header::Commodity> list, std::string tag);
std::vector<int> shopid_search(std::vector<main_header::Commodity> list, std::string tag);
std::vector<int> price_search(std::vector<main_header::Commodity> list, double tag);
std::vector<int> stockamt_search(std::vector<main_header::Commodity> list, int tag);
std::vector<int> level_search(std::vector<main_header::Commodity> list, int tag);
std::vector<int> shopamt_search(std::vector<main_header::Commodity> list, int tag);
std::vector<int> stockwarn_search(std::vector<main_header::Commodity> list, bool tag);
std::vector<int> stockout_search(std::vector<main_header::Commodity> list, bool tag);
std::vector<int> shopwarn_search(std::vector<main_header::Commodity> list, bool tag);
std::vector<int> shopout_search(std::vector<main_header::Commodity> list, bool tag);

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
