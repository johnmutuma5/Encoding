#include <iostream>
#include <sstream> // for string
#include <map>

// local includes
#include "priorityQueue.h"
#include "characterFrequency.h"
#include "huffmanTree.h"
#include "stringToBytes.h"

using namespace std;


int main () {
    string msg = "My name is Lazuli. I am one year old. I love my Mummy and Daddy very much!";
    // create a char frequency map
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
    HuffmanTree tree = treeBuilder.build_tree();

    // encode
    // generate encoding  from the tree
    map<char, string> encoding_map = tree.get_encoding_map();

    string binary_string = "";
    float bit_count = 0;
    for (const char& chr: msg){
        binary_string+=encoding_map[chr];
        bit_count++;
    }
    cout << binary_string << endl;

    ostringstream oss;
    stringToBytes (binary_string, oss);
    cout << oss.str() << endl;



    // decode
    // generate decoding map from tree
    map<string, char> decoding_map = tree.get_decoding_map();

    string decoded_binary = "";
    for (char chr: oss.str()){
        for (int bit_indx = 0; bit_indx < 8; ++bit_indx) {
            char bit = (chr & 0b10000000) ? '1' : '0';
            decoded_binary += bit;
            chr <<= 1;
        }
    }
    // view decoded_binary
    cout << decoded_binary << endl;

    string decoding_key;
    for (const char chr: decoded_binary) {
        decoding_key.push_back(chr);
        if (decoding_map.count(decoding_key)) {
            cout << decoding_map[decoding_key];
            decoding_key = "";
        }
    }

    cout << endl;
    return 0;
}

