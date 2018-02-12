#include <iostream>
#include <sstream>
#include <map>

#include "encoder.h"
#include "characterFrequency.h"
#include "stringToBytes.h"

using namespace std;

Encoder::Encoder () {
    // this->tree = new HuffmanTree;
}

Encoder::~Encoder () {
    delete tree;
}


void Encoder::encode (string& msg) {
    cout << "[Encoder::encode] (raw message) -> " << msg << endl;
    HuffmanTree* _tree = this->build_tree (msg); // returns dynamically allocated memory, clear this with ~Encoder()
    this->tree = _tree;

    map<char, string> encoding_map = tree->get_encoding_map();

    string binary_string = "";
    for (const char& chr: msg)
        binary_string+=encoding_map[chr];

    stringToBytes (binary_string, this->oss);
    cout <<"[Encoder::encode] (encoded message) -> ";
    cout << this->oss.str() << endl<< endl;
}



HuffmanTree* Encoder::build_tree (string& msg) {
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
    return treeBuilder.build_tree();
}


void Encoder::decode () {
    map<string, char> decoding_map = this->tree->get_decoding_map();

    string encoded_string = this->oss.str();

    string decoded_binary = "";
    for (char chr: encoded_string){
        for (int bit_indx = 0; bit_indx < 8; ++bit_indx) {
            //read the first bit with bit masking
            char bit = (chr & 0b10000000) ? '1' : '0';
            decoded_binary += bit;
            //shift bits left, so that the second bit is now first to be read in the next iteration
            chr <<= 1;
        }
    }
    cout << "[Encoder::decode] (decoded message) -> ";
    string decoding_key;
    for (const char chr: decoded_binary) {
        decoding_key.push_back(chr);
        if (decoding_map.count(decoding_key)) {
            cout << decoding_map[decoding_key];
            decoding_key = "";
        }
    }
    cout << endl;
}