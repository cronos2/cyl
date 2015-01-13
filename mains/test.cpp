#include <iostream>
#include "Tree.h"

using namespace std;


int main(){

    Node *root = new Node(1);
    Tree tree(*root);

    tree.addLeftChild(*root, 2);  // TODO: static
    tree.addRightChild(*root, 3);

    Tree::iter_preorder it = tree.begin(), end = tree.end();

    for(; it != end; ++it){
        cout << *it;
    }

    cout << tree;
    
}