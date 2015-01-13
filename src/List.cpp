#ifndef LIST_CPP
#define LIST_CPP

#include <stddef.h>

#include <List.h>
#include <Node.h>

using namespace std;


/* PRIVATE */


template <class T> void List <T>::clear(Node <T> *from = NULL){
    
    Node <T> *curr = from ? from : this->head, *next;

    while(curr != NULL){

        next = curr->getNext();

        delete curr;

        curr = next;

    }

}


template <class T> Node <T>* List <T>::back(){

    if(this->empty()){

        return NULL;

    }
    
    Node <T> *curr = this->head;

    while(curr->getNext() != NULL){  // list is NOT empty

        curr = curr->getNext();

    }

    return curr;

}


/* PUBLIC */


template <class T> List <T>::List(){
    
    this->head = NULL;

}


template <class T> List <T>::List(const T &value){
    
    Node <T> *node = new Node <T>(value);

    this->head = node;

}


template <class T> List <T>::List(const List <T> &other){
    
    Node <T> *curr_other = other.getHead(), *prev_here, *curr_here;

    prev_here = new Node <T>(curr_other->getValue());

    this->head = prev_here;

    curr_other = curr_other->getNext();

    while(curr_other != NULL){

        curr_here = new Node <T>(curr_other->getValue());

        prev_here->setNext(curr_here);

        prev_here = curr_here;

        curr_other = curr_other->getNext();

    }

    curr_here->setNext(NULL);

}


template <class T> List <T>& List <T>::operator=(const List <T> &other){
    
    if(this != &other){

        Node <T> *curr_here = this->head, *curr_other = other.getHead(), 
                *prev_here = NULL;

        while(curr_here != NULL and curr_other != NULL){

            curr_here->setValue(curr_other->getValue());

            prev_here = curr_here;
            curr_here = curr_here->getNext();
            curr_other = curr_other->getNext();

        }

        if(curr_here == NULL and curr_other != NULL){  // not enough space

            Node <T> *new_node;

            if(this->empty()){

                this->unshift(curr_other->getValue());

                curr_other = curr_other->getNext();
                curr_here = this->head;

            } else {

                curr_here = prev_here;
                
            }

            while(curr_other != NULL){

                new_node = new Node <T>(curr_other->getValue());
                
                curr_here->setNext(new_node);

                curr_here = new_node;

                curr_other = curr_other->getNext();

            }

        } else if(curr_here != NULL and curr_other == NULL){

            prev_here ? prev_here->setNext(NULL) : void();

            this->clear(curr_here);  // remove remaining elements

        }

    }

    return *this;
    
}


template <class T> List <T>::~List(){
    
    this->clear();

}


template <class T> void List <T>::push(const T &value){
    
    Node <T> *curr = this->head, new_node = new Node <T>(value);

    if(curr == NULL){

        this->head = new_node;

    } else {

        curr = this->back();

        curr->setNext(new_node);

    }

}


template <class T> void List <T>::unshift(const T &value){
    
    Node <T> *new_node = new Node <T>(value, this->head);

    this->head = new_node;

}


template <class T> T List <T>::pop(){
    
    Node <T> *last = this->back(), *curr = this->head;

    while(curr->getNext() != last){  // list is NOT empty

        curr = curr->getNext();

    }

    curr->setNext(NULL);

    T value = last->getValue();

    delete last;

    return value;

}


template <class T> T List <T>::shift(){

    Node <T> *head = this->head, *next;
    
    T value = head->getValue();

    next = head->getNext();

    delete this->head;

    this->head = next;

    return value;

}

#endif