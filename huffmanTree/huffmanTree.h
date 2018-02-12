#pragma once

#include <map>
#include <sstream> // for string
#include "priorityQueue.h"

using std::map;
using std::string;

struct HuffmanNode {
    static int total;
    long priority;
    char chr;

    HuffmanNode* left = NULL;
    HuffmanNode* right = NULL;

    HuffmanNode ();
    HuffmanNode (long); // for non-leaf nodes
    HuffmanNode (long, char); // for leaf nodes
    // HuffmanNode (const HuffmanNode& obj); // copy constructor
    ~HuffmanNode ();

    friend std::ostream& operator<< (std::ostream& out, HuffmanNode& node) {
        out << node.chr << ": " << node.priority << std::endl;
    }
};

class HuffmanTree {
    public:
        HuffmanTree (HuffmanNode*&);
        HuffmanTree ();
        ~HuffmanTree ();
        void toString();
        map<char, string>& get_encoding_map (); //simultaneously creates the decoding_map too
        map<string, char>& get_decoding_map ();
    private:
        HuffmanNode* p_tree;
        map<char, string> encoding_map;
        map<string, char> decoding_map;
        void clear ();
    protected:
};





class HuffmanTreeBuilder {
    public:
        HuffmanTreeBuilder ();
        HuffmanTreeBuilder (PriorityQueue<HuffmanNode>*);
        ~HuffmanTreeBuilder ();
        HuffmanTree* build_tree ();
    private:
        PriorityQueue<HuffmanNode>* pq = NULL;
    protected:
};
