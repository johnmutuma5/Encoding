#include <iostream>
#include <sstream> // for string
// #include <fstream>
#include "stringToBytes.h"

using namespace std;

int charToInt (string chr) {
    int result;

    stringstream iss (chr);
    iss >> result;
    return result;
}

void stringToByteHelper (string& bitsString, unsigned char& currByte, ostringstream& out, int bitCount=0) {
    if (bitCount == 8) {
        out << currByte;
        currByte = 0;
        bitCount = 0;
    }

    if (bitsString.empty())
        return;

    // choose first character and erase it from bitsString
    string chr;
    chr.push_back(bitsString.at(0));
    bitsString.erase(0, 1);


    int bit =  charToInt(chr);
    currByte <<= 1; //shift bits one step left to create room for the next byte
    currByte |= bit; // set the bit with bitwise OR, bit masking


    stringToByteHelper (bitsString, currByte, out, bitCount + 1);
    bitsString.insert(0, chr);
}



ostringstream& stringToBytes (string& bitsString, ostringstream& oss) {
    // ensure bitString is in multiple of 8bits by appending 0s
    while (bitsString.size() % 8)
        bitsString.push_back('0');

    unsigned char currentByte = 0b00000000;
    stringToByteHelper (bitsString, currentByte, oss);
    return oss;
}