#include <iostream>
#include <sstream> // for string
#include <fstream>
#include "stringToBytes.h"

using namespace std;

int charToInt (char chr) {
    int result;

    string _chr;
    _chr.push_back(chr);
    stringstream iss (_chr);
    iss >> result;
    return result;
}

void stringToByteHelper (string& bitsString, unsigned char& currByte, ofstream& out, int bitCount=0) {
    for (char bit_char: bitsString) {
      if (bitCount == 8) {
          out << currByte;
          currByte = 0;
          bitCount = 0;
      }

      int bit = charToInt(bit_char);
      currByte <<= 1; //shift bits one step left to create room for the next byte
      currByte |= bit; // set the bit with bitwise OR, bit masking
      bitCount++;
    }
}



void stringToBytes (string& bitsString, ofstream& ofs) {
    // ensure bitString is in multiple of 8bits by appending 0s
    while (bitsString.size() % 8)
        bitsString.push_back('0');

    unsigned char currentByte = 0b00000000;
    stringToByteHelper (bitsString, currentByte, ofs);
}
