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