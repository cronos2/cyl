#ifndef STACK_CPP
#define STACK_CPP

#include <Stack.h>
#include <List.h>

using namespace std;


template <class T> Stack <T>::Stack(){
    
    List <T> list;

    this->list = list;

}


template <class T> Stack <T>::Stack(const T &value){
    
    List <T> list(value);

    this->list = list;

}


template <class T> void Stack <T>::push(const T &value){
    
    this->list.unshift(value);

}


template <class T> T Stack <T>::pop(){
    
    return this->list.shift();

}


template <class T> bool Stack <T>::empty() const {
    
    return this->list.empty();

}

#endif