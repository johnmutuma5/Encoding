#pragma once

#include <iostream>
#include <sstream>
#include "huffmanTree.h"

class Encoder {
    public:
        Encoder ();
        ~Encoder ();
        void encode (std::string&);
        void decode ();
    private:
        HuffmanTree* tree; // this one is assigned to a dynamically allocated pointer; clear this in destructor
        HuffmanTree* build_tree (std::string& msg);
        std::ostringstream oss;
    protected:
};