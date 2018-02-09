#include <iostream>
#include <sstream>

#include "encoder.h"

using namespace std;

Encoder::Encoder () {
    //
}


void Encoder::encode (string& msg) {
    this->build_tree (msg);

    map<char, string> encoding_map = tree.get_encoding_map();

    string binary_string = "";
    for (const char& chr: msg){
        binary_string+=encoding_map[chr];

    cout << binary_string << endl;

    ostringstream oss;
    stringToBytes (binary_string, oss);
    cout << oss.str() << endl;
}



void Encoder::build_tree (string msg) {
    map<char, int> char_freq_map;
    char_freq_map = get_char_freq(msg);

    // create a priorityQueue of HuffmanNodes
    PriorityQueue<HuffmanNode> pq;
    for (const pair<const char, int>& map_item: char_freq_map) {
        HuffmanNode node(map_item.second, map_item.first); // accepts int priority, char chr
        pq.insert(node, map_item.second);
    }


    // make a HuffmanTreeBuilder with a priority queue of HuffmanNodes
    HuffmanTreeBuilder treeBuilder(&pq);
    // HuffmanTree tree = treeBuilder.build_tree();
    *(this->tree) = treeBuilder.build_tree();
}