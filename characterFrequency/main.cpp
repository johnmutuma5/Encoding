#include <iostream>
#include <sstream> // for string
#include <map>
#include "characterFrequency.h"

using namespace std;

int main () {
    string msg = "My name is Lazuli. I am one year old. I love my Mummy aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaand Daddy very much!***";

    map<char, int> char_freqs;
    char_freqs = get_char_freq(msg);

    for (const pair<const char, int>& x: char_freqs)
        cout << x.first << " : " << x.second << endl;


    return 0;
}