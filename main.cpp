// this is yet to do anything relevant. Still under construction.
// this is where the encoder will be instantiated and it's methods called


#include <iostream>


using namespace std;

int get_int () {
    int a = 10;

    return a;
}

int main () {
    int* p = new int();
    *p = get_int();
    cout << *p << endl;

    return 0;
}
