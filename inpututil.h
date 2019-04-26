#ifndef INPUTUTIL
#define INPUTUTIL
#include <string>
#include <iostream>

// The following are functions that take user inputs of a certain type and return them
// and perform any input checks.
// Singled out to avoid code repetition.

std::string getString();

int getInt();

double getDouble();

bool getBool();

#endif /* INPUTUTIL */
