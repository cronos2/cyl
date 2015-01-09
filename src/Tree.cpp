#ifndef TREE_CPP
#define TREE_CPP

#include <stddef.h>

#include "Tree.h"

using namespace std;


template <class T> void Tree <T>::clear(Node &root){

    Node *curr_child = root.left_child, *prev = root.getPrevSibling();

    while(curr_child != NULL){
        this->clear(curr_child);
        curr_child = curr_child->next_sibling;
    }

    if(prev != NULL){
        prev->next_sibling = root.next_sibling;
    } else {  // it's its parent's left child
        root.parent->left_child = root.next_sibling;
    }

    delete &root;
}


template <class T> Tree <T>::Tree(){
    this->root = NULL;
}


template <class T> Tree <T>::Tree(Node &root){
    this->root = &root;
}


template <class T> Tree <T>::Tree(const Tree &other){
    Node *root = new Node;
    this->root = root;
    this->copy(other.getRoot(), this->root);
}


template <class T> Tree <T>& Tree <T>::operator=(const Tree &other){
    if(this != &other){
        this->clear(this->getRoot());
        Node *root = new Node;
        this->root = root;
        this->copy(other.getRoot(), this->root);
    }

    return *this;
}


template <class T> void Tree <T>::copy(const Node *src, Node *dest){  // TODO: static?
    
    if(src == NULL){}  // foo

    dest->value = src->value;

    if(src->left_child != NULL){  // if it's a leaf return a dull node pointer
        Node *curr = src->left_child, *curr_clone, *prev_clone;

        while(curr != NULL){  // walk the tree by level
            this->copy(curr, curr_clone);
            curr_clone->parent = dest;

            if(dest->left_child == NULL){
                dest->left_child = curr_clone;
            }
            // TODO: if-else
            if(prev_clone != NULL){
                prev_clone->next_sibling = curr_clone;
            }
 
            curr = curr->next_sibling;
            prev_clone = curr_clone;        
        }
    }
}


template <class T> typename Tree<T>::Node* Tree <T>::addLeftChild(Node &parent, const T &value){
    Node *new_child = new Node(value);
    this->addLeftChild(parent, *new_child);
}


template <class T> typename Tree<T>::Node* Tree <T>::addLeftChild(Node &parent, Node &child){
    child.next_sibling = this->left_child;
    child.parent = this;
    this->left_child = &child;
}


template <class T> typename Tree<T>::Node* Tree <T>::removeLeftChild(Node &parent){
    Node *left = parent.left_child, *next = NULL;

    if(left){
        next = left->next_sibling;
        this->clear(*left);
    }

    parent.left_child = next;
    return next;
}


template <class T> typename Tree<T>::Node* Tree <T>::insertBefore(Node &reference, Node &child){
    reference.getPrevSibling()->next_sibling = &child;
    child.parent = reference.parent;
    child.next_sibling = &reference;
    return &child;
}


template <class T> void Tree <T>::putSubtree(Node &reference, Node &child){  // WTF does this do
    Node *prev = reference.getPrevSibling();
    
    prev->next_sibling = &child;
    child.parent = reference.parent;
    child.next_sibling = &reference;
    return &child;
}


template <class T> void Tree <T>::removeSubtree(Node &root){
    this->clear(&root);
}


template <class T> int Tree <T>::size() const {
    int size = 1;
    Node *curr = this->root->left_child;

    while(curr != NULL){
        size += Tree(*curr).size();
        curr = curr->next_sibling;
    }

    return size;
}


template <class T> bool Tree <T>::empty() const {
    return this->root == NULL;
}


template <class T> bool Tree <T>::operator==(const Tree &other) const {
    return *(this->root) == *(other.root);
}


#endif