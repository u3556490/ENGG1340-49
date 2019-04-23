#include "main.h"
#include "sort.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace main_header;

/* Algorithms for sorting
   Use std::sort but with a custom comparator function.
*/

// Implement additional functions whenever necessary

// --------------------------------------
// function sort: called when the user wills it.
// Take input based on which column should the sort be done.
// @params vector<Commodity> original: original list of items.
// @return vector<Commodity>: sorted list of items.
// --------------------------------------
vector<Commodity> sort_list(vector<Commodity> original){
	vector<Commodity> sorted;
	//get which column to sort by
	char col;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Based on which attribute should the inventory be sorted?" << endl;
	cout << "(I) for id" << endl;
	cout << "(N) for name" << endl;
	cout << "(M) for manufacturer" << endl;
	cout << "(P) for price" << endl;
	cout << "(X) for expiry date" << endl;
	cout << "(A) for stock amount at warehouse" << endl;
	cout << "(L) for stockpile warning level" << endl;
	cout << "(W) for stockpile warning low ones first" << endl;
	cout << "(O) for out of stock ones first" << endl;
	cout << "(S) for shop id" << endl;
	cout << "(U) for shop stockpile amount" << endl;
	cout << "(R) for shop stockpile warning low ones first" << endl;
	cout << "(T) for shop out of stock ones first" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Enter a letter: " << endl;
	cin >> col;
	//massive switch-case statement
	switch (col){
		
	}
	
}

/*debug only
int main(){
	return 0;
}*/
