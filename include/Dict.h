#ifndef DICT_H
#define DICT_H

#include <algorithm>
#include <iostream>

#include "Tree.h"

using namespace std;

struct NodeData {
    char char;
    bool valid;
    
    NodeData(char char, bool valid){
        this->char = char;
        this->valid = valid;
    }

};

class Dict {

    private:

        Tree <NodeData> tree;

    public:

        Dict();

        Dict(const Tree &tree);

        void addWord(string word);

        bool exists(string word);

        class iterator {

            private:

                Tree <NodeData>::iter_preorder it;

            public:

                iterator(){
                    Tree <NodeData>::iter_preorder it;
                    this->it = it;
                }

                iterator& operator++(){
                    while(not *(++this->it).valid);  // keep advancing till a valid word
                    return *this;
                }

                string operator*() const {
                    Node *last = this->it.getNode(), *curr_letter = last->parent;
                    string word = last->value.char;
                    last = last->parent;
                    
                    while(curr_letter->value.char){
                        word += curr_letter->value.char;
                    }

                    reverse(word.begin(), word.end());

                    return word;

                }

                bool operator==(const iterator &other) const {
                    return this->it == other.it;
                }

                bool operator!=(const iterator &other) const {
                    return not (*this == other);
                }

        };

        iterator& begin();
        iterator& end();

        friend istream& operator>>(istream &is, const Dict &other);
        friend ostream& operator>>(ostream &os, const Dict &other);

};

#endif