#pragma once

#include <iostream>
#include <sstream> // for string

using std::string;
using std::ostringstream;

int charToInt (string);
void stringToByteHelper (string&, unsigned char&, ostringstream&, int);
void stringToBytes (string&, ostringstream&);