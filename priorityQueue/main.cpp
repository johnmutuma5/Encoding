#include <iostream>
#include <string>
#include "priorityQueue.h"

using namespace std;


int main () {
    PriorityQueue<char> pq;
    pq.insert ('b', 3);
    pq.insert ('c', 3);
    pq.insert ('d', 4);
    pq.insert ('e', 5);
    pq.insert ('f', 6);

    cout << pq << endl;
    pq.updatePriority('f', 1);
    cout << pq << endl;
    pq.erase(pq.get_size() - 1);
    cout << pq << endl;

    return 0;
}

