#include "inpututil.h"
#include <string>
#include <exception>
#include <iostream>
using namespace std;

string getString(){
	string buffer;
	cout << "Please enter a value:";
	std::getline(std::cin, buffer);
	return buffer;
}

int getInt(){
	bool input_ok = 0;
	string * buffer = new string;
	int value;
	while(!input_ok){
		cout << "Please enter the value you want to filter out: ";
		std::getline(std::cin, *buffer);
		try{	//wow c++ exception handling seems interesting
			value = stoi(*buffer);
		} catch (std::invalid_argument){
			cout << "Please check your input and try again.\n";
		}
		input_ok = 1;
	}
	delete buffer;
	return value;
}

bool getBool(){
	bool input_ok = 0;
	bool value;
	string* buffer = new string;
	while (!input_ok){
		cout << "Please enter 1 for true (set) and 0 for false (not set): ";
		cin >> *buffer;
		if (*buffer == "1"){
			value = 1;
			input_ok = 1;
		}
		else if (*buffer == "0"){
			value = 0;
			input_ok = 1;
		}
		else
			cout << "Please check your input and try again.\n";
	}
	delete buffer;
	return value;
}

double getDouble(){
	bool input_ok = 0;
	string * buffer = new string;
	double value;
	while(!input_ok){
		cout << "Please enter a number: ";
		cin >> *buffer;
		try{	//wow c++ exception handling seems interesting
			value = stod(*buffer);
		} catch (std::invalid_argument){
			cout << "Please check your input and try again.\n";
		}
		input_ok = 1;
	}
	delete buffer;
	return value;
}
