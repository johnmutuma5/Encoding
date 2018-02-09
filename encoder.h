#pragma once

#include <map>
#include <sstream>
#include "HuffmanTree"

class Encoder {
    public:
        Encoder ();
        ~Encoder ();
        void encode (std::string&);
        void decode ();
    private:
        HuffmanTree* tree;
        void build_tree (std::string msg);
    protected:
};