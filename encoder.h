#pragma once

#include <iostream>
#include <fstream>
#include "huffmanTree.h"

class Encoder {
    public:
        Encoder ();
        ~Encoder ();
        void encode (std::ifstream&, std::ofstream&);
        void decode (std::ifstream&, std::ofstream&);
    private:
        HuffmanTree* tree; // this one is assigned to a dynamically allocated pointer; clear this in destructor
        HuffmanTree* build_tree (std::ifstream&);
        // std::ofstream ofs;
    protected:
};