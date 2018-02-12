#include <iostream>
#include <sstream>
#include <fstream>
#include "encoder.h"

using namespace std;

int main () {

    Encoder encoder;

    ifstream infile ("alice.txt", ios::in);
    ofstream output ("encoded.txt", ios::out);

    // demostrate encoding
    encoder.encode(infile, output);
    infile.close();
    output.close();


    // demonstrate decoding v
    ifstream to_decode ("encoded.txt", ios::in);
    ofstream decoded ("decoded.txt", ios::out);
    encoder.decode(to_decode, decoded);
    to_decode.close();
    decoded.close();

    return 0;
}
