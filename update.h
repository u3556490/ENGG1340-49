#ifndef UPDATE
#define UPDATE
#include "main.h"
#include "rmentry.h"
#include "addentry.h"
#include <vector>

/* Algorithm thought up for the appending/editing of ONE specific commodity entry such that ONE of its attributes is changed */
/* Step 1: find the entry to amend and mark its index in the vector.
   Step 2: make a copy of the entry.
   Step 3: change the attribute of the copy. E.g. if id is to be changed, then copy.id = new_id 
   Step 4: call replacec(list, index, edited_object) to replace the original entry with the copy. 
 */
/* For editing multiple entries, the subroutine replacec() should be called more than once. */

// ------------------------------------------------
// Function update_one: changes content of ONE particular
// inventory entry. This function should implement the above mentioned algorithm,
// but the details are to be input by the user. Perform any necessary
// checks on user input.
// @params vector<Commodity> &list: the inventory to modify
// @return none
// -----------------------------------------------
void update_one(std::vector<main_header::Commodity> &list);

// -------------------------------------
// Function update: will be called immediately when
// the user wants to update the inventory. Lead him to the right functions
// and loop them (e.g. update_one() should be looped when multiple entries are
// to be updated) whenever necessary.
// @params vector<Commodity> &list: the inventory to modify
// @return none
// -------------------------------------
void update(std::vector<main_header::Commodity> &list);

// ----------------------------------------
// Function replacec: replaces the index-th item of the specified list (list[index])
// with the item (target), therefore succeeding in amending contents of an entry.
// Suitable input checks should be performed.
// @params vector<Commodity> &list: the inventory to modify
//		   int index: location of the object
// 		   Commodity target: the object to replace to
// @return none
// ----------------------------------------
void replacec(std::vector<main_header::Commodity> &list, int index, main_header::Commodity target);

// -----------------------------------
// Function getUpdateFile: gets data about an inventory update 
// to be performed according to a file specified by user input.
// By update, it is meant that the contents of the whole inventory
// could be changed, i.e. additions, removals and amendments should be
// supported. For amendments, see the algorithm stated above.
// @params none
// @return none
// -----------------------------------
// TODO: figure out the layout of the file to read
void getUpdateFile();

#endif /*UPDATE*/
