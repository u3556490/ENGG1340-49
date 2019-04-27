#include "main.h"
#include "search.h"
#include "stockalert.h"
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
using namespace main_header;

// ----------------------------
// function setOneLevel: sets warning level of commodity entry
// specified to the value given.
// @params Commodity &com: the commodity to manipulate
//         int level: the level to set to
// @return none
// ----------------------------
void setOneLevel(Commodity &com, int level){
	com.warning_level = level;
}

// ----------------------------
// function setLevel: gets call upon level change prompt.
// @params vector<Commodity> &list: the inventory to manipulate
// @return none
// ----------------------------
void setLevel(vector<Commodity> &list){
	string target_id;
	bool ok = 0;
	int level = 0;
	string buffer;
	//user input
	cout << "-------------------------------------------------------" << endl;
	while (!ok){	//input check
		cout << "Please enter the id of the item to work on: ";
		cin >> buffer;	//assuming no one is "smart" enough to use spaces in his id
		if (!comexist(list, buffer)){
			cout << "Your input it faulty. Please try again.\n";
		} 
		else {
			ok = 1;
		}
	}
	target_id = buffer;
	ok = 0;
	while (!ok){
		cout << "Please enter the desired new warning level (whole number): ";
		cin >> buffer;
		if (atoi(buffer.c_str()) >= 0){
			ok = 1;
		}
		else{
			cout << "Your input it faulty. Please try again.\n";
		}
	}
	level = atoi(buffer.c_str());
	//fetch item
	int pos = idfindcom(list, target_id);
	//call set Level
	setOneLevel(list[pos], level);
	//return
	cout << "Action successfully performed." << endl;
}

// ----------------------------
// function check_stock: loops through the whole inventory to find entries whose
// stock amount at shop or at HQ is below the warning level.
// @params vector<Commodity>* list: the list to look through
// @return vector<int>: a list of indices of items that are having issues
// ----------------------------
vector<int> check_stock(vector<Commodity>* list){
	unordered_set<int> temp_set;				//unique item indices. Not handling further information yet
	//if size < 1, return none
	if (list->size() < 1){
		return vector<int>{};
	}
	
	int index = 0;
	//for each
	for (vector<Commodity>::iterator i = list->begin(); i != list->end(); i++){
		//check hq stockpile
		if ((*i).stock_amount <= (*i).warning_level){
			temp_set.insert(index);
			(*i).stock_warning = 1;
			if ((*i).stock_amount < 1){
				(*i).out_of_stock = 1;
			}
		}
		//check shop stockpile
		if ((*i).shop_amount <= (*i).warning_level){
			temp_set.insert(index);
			(*i).shop_stock_warning = 1;
			if ((*i).shop_amount < 1){
				(*i).shop_out_of_stock = true;
			}
		}
		index++;
	}
	vector<int> result(temp_set.begin(), temp_set.end());	//return vector
	return result;
}

/*
int main(){
return 0;
}
*/
