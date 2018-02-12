#include <iostream>
#include <sstream>
#include "encoder.h"

using namespace std;

int main () {
    string msg = "My name is Lazuli Muthoni Murimi. I love my Mummy and Daddy very much! We are one family and we pray that God shall keep us well and keep providing for us";
    Encoder encoder;
    encoder.encode(msg);
    encoder.decode();

    return 0;
}
