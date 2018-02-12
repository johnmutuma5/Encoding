#include <iostream>
#include <sstream>
#include <fstream>
// #include "encoder.h"
#include "./characterFrequency/characterFrequency.h"

using namespace std;

int main () {
    // string msg = "My name is Lazuli Muthoni Murimi. I love my Mummy and Daddy very much! We are one family and we pray that God shall keep us well and keep providing for us";

    ifstream infile ("text.txt", ios::in);
    // Encoder encoder;
    // encoder.encode(msg);
    // encoder.decode();
    map<char, int> chrfr = get_char_freq (infile);

    return 0;
}
