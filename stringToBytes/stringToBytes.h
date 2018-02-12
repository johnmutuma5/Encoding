#pragma once

#include <iostream>
#include <sstream>
#include <fstream> // for string

using std::string;
using std::ofstream;

int charToInt (string);
void stringToByteHelper (string&, unsigned char&, ofstream&, int);
void stringToBytes (string&, ofstream&);