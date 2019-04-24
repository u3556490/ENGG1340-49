#include "main.h"
#include "stockalert.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace main_header;

// ----------------------------
// function setOneLevel: sets warning level of commodity entry
// specified to the value given.
// @params Commodity com: the commodity to manipulate
//         int level: the level to set to
// @return none
// ----------------------------
void setOneLevel(Commodity com, int level){
	com.warning_level = level;
}

// ----------------------------
// function setLevel: gets call upon level change prompt.
// @params vector<Commodity> list: the inventory to manipulate
// @return none
// ----------------------------
void setLevel(vector<Commodity> list){
	//fetch item
	
	//call set Level
	
	//return
}

// ----------------------------
// function check_stock: loops through the whole inventory to find entries whose
// stock amount at shop or at HQ is below the warning level.
// @params vector<Commodity>* list: the list to look through
// @return vector<int>: a list of indices of items that are having issues
// ----------------------------
vector<int> check_stock(vector<Commodity>* list){
	vector<int> result {};
	result.reserve(10);
	//if size < 1, return none
	if (list->size() < 1)
		return result;
	
	int index = 0;
	//for each
	for (vector<Commodity>::iterator i = list->begin(); i != list->end(); i++){
		//check hq stockpile
		if ((*i).stock_amount < (*i).warning_level){
			result.push_back(index);
			(*i).stock_warning = 1;
			if ((*i).stock_amount < 1)
				(*i).out_of_stock = 1;
		}
		//check shop stockpile
		if ((*i).shop_amount < (*i).warning_level){
			result.push_back(index);
			(*i).shop_stock_warning = 1;
			if ((*i).shop_amount < 1)
				(*i).shop_out_of_stock = true;
		}
		index++;
	}
	
	return result;
}

/*
int main(){
return 0;
}
*/
