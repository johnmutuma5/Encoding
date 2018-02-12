#include <iostream>
#include <fstream>
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


void Encoder::encode (ifstream& file, ofstream& ofs) {
    cout << "[Encoder::encode] (raw message) -> " << endl;

    HuffmanTree* _tree = this->build_tree (file); // returns dynamically allocated memory, clear this with ~Encoder()
    this->tree = _tree;

    map<char, string> encoding_map = tree->get_encoding_map();

    string binary_string = "";
    char chr;

    while(file.get(chr))
        binary_string+=encoding_map[chr];
    binary_string+=encoding_map[EOF]; // creat End of File flag

    stringToBytes (binary_string, ofs);
    cout <<"[Encoder::encode] (encoded message) -> " << endl;
    // cout << this-> oss.str() << endl<< endl;
}



HuffmanTree* Encoder::build_tree (ifstream& file) {
    map<char, long> char_freq_map;
    char_freq_map = get_char_freq(file);
    file.clear(); //clear eofbit flag to be able to seekg the file
    file.seekg(0); // the file will be reused again by Encoder::encode

    // create a priorityQueue of HuffmanNodes
    PriorityQueue<HuffmanNode> pq;
    for (const pair<const char, long>& map_item: char_freq_map) {
        HuffmanNode node(map_item.second, map_item.first); // accepts int priority, char chr
        pq.insert(node, map_item.second);
    }

    // cout << pq << endl;
    // make a HuffmanTreeBuilder with a priority queue of HuffmanNodes
    HuffmanTreeBuilder treeBuilder(&pq);
    return treeBuilder.build_tree();
}


void Encoder::decode (ifstream& ifs, ofstream& ofs) {
    map<string, char> decoding_map = this->tree->get_decoding_map();

    string encoded_string;
    char chr;
    while (ifs.get(chr))
        encoded_string.push_back(chr);

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

            if (decoding_map[decoding_key] == EOF)
                break;
            ofs << decoding_map[decoding_key];

            decoding_key = "";
        }
    }
    cout << endl;
}
