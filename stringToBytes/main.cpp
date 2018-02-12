#include <iostream>
#include <sstream> // for string
#include <fstream>
#include "stringToBytes.h"

using namespace std;


int main () {
    string bitsString = "111111111";
    ofstream ofs ("text.txt", ios::out);
    stringToBytes (bitsString, ofs);

    ofs.close();

    return 0;
}