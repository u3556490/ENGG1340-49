#include "main.h"
#include "filter.h"
#include <vector>
using namespace std;
using namespace main_header;

/* Algorithms for filtering
   Filtering out a subset of items, all having one specific attribute equal a given value:
   Step 1: ask user which attribute to filter
   Step 2: ask user the value to look for (key)
   Step 3: perform linear search to obtain the subset
*/

// Implement additional functions whenever necessary

// --------------------------------------
// function filter: called when the user wills it.
// Take input on what to filer and whether the filter is to be unset.
// Must not overwrite the original inventory.
// @params vector<Commodity> original: original list of items.
// @return vector<int>: vector of indices of the matches to display.
// --------------------------------------
vector<int> filter(vector<Commodity> original){
	
}

/*debug only
int main(){
	return 0;
}*/
