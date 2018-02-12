#include <iostream>
#include <sstream> // for string
#include <set>
#include <map>
#include "characterFrequency.h"

using namespace std;


map<char, long> get_char_freq (ifstream& file) {
    char chr;
    map<char, long> charFreq;
    while (file.get(chr))
        charFreq[chr]++;
    charFreq[EOF] = 1; // char to rep End of File

    return charFreq;
}
