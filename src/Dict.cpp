#ifndef DICT_CPP
#define DICT_CPP

#include "Dict.h"
#include "Tree.h"

using namespace std;


Dict::Dict(){
    Tree <NodeData> tree;
    this->tree = tree;
}


Dict::Dict(const Tree &tree){
    this->tree = tree;
}


void Dict::addWord(string word){
    
    Node *curr = this->tree.getRoot()->left_child, *sibling = curr, *new_node;
    int len = word.size();

    for(int i = 0; i < len; ++i){

        while(curr != NULL and word[i] != curr->value.char){
            curr = curr->next_sibling;
        }

        if(curr == NULL){  // there doesn't exist that point
            new_node = new Node(curr->value.char);
            this->tree.addRightChild(*(sibling->parent), *new_node);
        } else {
            sibling = curr = curr->left_child;
        }

    }

    curr->value.valid = true;

}


bool Dict::exists(string word){

    Node *curr = this->tree.getRoot()->left_child, *sibling = curr, *new_node;
    int len = word.size(), i = 0;

    for(; i < len; ++i){

        while(curr != NULL and word[i] != curr->value.char){
            curr = curr->next_sibling;
        }

        if(curr != NULL){
            sibling = curr = curr->left_child;
        }

    }    
    
    return i == len and curr->value.valid;
}


&iterator Dict::begin(){
    iterator it;
    it.it = ++(this->tree.begin());  // skip the root for it's emtpy    
}


&iterator Dict::end(){
    iterator it;
    it.it = this->tree.end();    
}


istream& operator>>(istream &is, const Dict &dict){
    Tree <NodeData> tree;
    dict.tree = tree;

    string word;

    do {
        getline(is, word);
        dict.addWord(word);
    } while(word);

    return is;
}


ostream& operator>>(ostream &os, const Dict &dict){
    Dict::iterator it = dict.begin(), end = dict.end();

    for(; it != end; ++it){
        os << *it;
    }

    return os;
}

#endif