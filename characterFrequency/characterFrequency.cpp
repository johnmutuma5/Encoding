#include <iostream>
#include <sstream> // for string
#include <set>
#include <map>
#include "characterFrequency.h"

using namespace std;



map<char, int> get_char_freq (string& msg) {
    cout << msg << endl;
    set<char> charSet (msg.begin(), msg.end());
    map<char, int> charFreq;

    for (const char& chr: msg)
        charFreq[chr]++;

    return charFreq;
}