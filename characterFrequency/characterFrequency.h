#pragma once

#include <map>
#include <sstream>
#include <fstream>

using std::string;
using std::map;

map<char, long> get_char_freq (std::ifstream&);
