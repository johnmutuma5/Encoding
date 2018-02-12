#include <iostream>
#include <sstream>

#include "huffmanTree.h"

using namespace std;

// int HuffmanNode::total = 0;

HuffmanNode::HuffmanNode () {

}

HuffmanNode::HuffmanNode (long priority):
priority(priority)
{

}

HuffmanNode::HuffmanNode (long priority, char chr):
priority(priority), chr(chr)
{

}

HuffmanNode::~HuffmanNode () {

}

HuffmanTreeBuilder::HuffmanTreeBuilder () {
}

HuffmanTreeBuilder::HuffmanTreeBuilder (PriorityQueue<HuffmanNode>* pq) {
    this -> pq = pq;
}

HuffmanTreeBuilder::~HuffmanTreeBuilder () {
    //
}



void build_helper (PriorityQueue<HuffmanNode>*& pq) {
    if (pq->get_size() == 1)
        return;

    //pq.pop() delinks pq.root and returns the first element in pq
    HuffmanNode* first_node = new HuffmanNode ();
    *first_node = pq->pop ();
    HuffmanNode* second_node = new HuffmanNode ();
    *second_node = pq->pop ();

    //build a new node with priority equal to the sum of the first two nodes and having left child as the first node and right child
    //as the right node and reinsert it intor the priority queue
    long joint_priority = first_node->priority + second_node->priority;
    HuffmanNode tree (joint_priority);
    tree.left = first_node;
    tree.right = second_node;


    pq->insert(tree, joint_priority);
    // repeat this process until we only have one node in the queue, this is the halfman tree root node
    build_helper (pq);
}

HuffmanTree* HuffmanTreeBuilder::build_tree () {
    build_helper (this->pq);

    // let us remember to dynamically allocate memory to the last node just like how the children nodes have beeb allocated
    HuffmanNode* root = new HuffmanNode ();
    *root = this->pq->pop();
    HuffmanTree* tree = new HuffmanTree (root);
    return tree;
}


HuffmanTree::HuffmanTree (HuffmanNode*& root):
p_tree(root)
{
    //
}

HuffmanTree::HuffmanTree () {
    // non-param constructor
}

HuffmanTree::~HuffmanTree () {
    this->clear();
}

void HuffmanTree::toString () {
    cout << *(this->p_tree->left) << endl;
}




bool get_map_helper (HuffmanNode*& current,
                    map<char, string>& encoding_map,
                    map<string, char>& decoding_map,
                    string pathSoFar = "", char gotten_char = 0) {
    if (current == NULL) {
        //undo path leading to null
        pathSoFar.pop_back();
        encoding_map[gotten_char] = pathSoFar;
        decoding_map[pathSoFar] = gotten_char;
        return true;
    }

    bool got_leaf = get_map_helper (current->left, encoding_map, decoding_map, pathSoFar + "0", current->chr);
    if (!got_leaf)
        get_map_helper (current->right, encoding_map, decoding_map, pathSoFar + "1", current->chr);

}

map<char, string>& HuffmanTree::get_encoding_map () {
    // this will build the encoding and decoding maps all together
    get_map_helper (this->p_tree, this->encoding_map, this->decoding_map);
    return this->encoding_map;
}

map<string, char>& HuffmanTree::get_decoding_map () {
    return this->decoding_map;
}

void clear_helper (HuffmanNode*& current) {
    if (current == NULL)
        return;

    clear_helper (current->left);
    clear_helper (current->right);
    delete current;
}
void HuffmanTree::clear () {
    clear_helper (this->p_tree);
}
