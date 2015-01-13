#ifndef STACK_H
#define STACK_H

#include <List.h>

using namespace std;


/**
  *
  * @brief TDA Stack
  * @section Función de abstracción: una instancia de Stack representa una pila,
  *           i.e., una colección de elementos en los que la inserción y el 
  *           borrado de elementos se realiza en el mismo extremo. 
  *
  */

template <class T> class Stack {
    
    private:

        List <T> list;

    public:

        /**
          *
          * @brief Constructor por defecto de la clase
          *
          */

        Stack();

        /**
          *
          * @brief Constructor de la clase
          * @param value el valor que va a almacenar el primer nodo
          *
          */

        Stack(const T &value);

        /**
          *
          * @brief Añade un elemento a la pila
          * @param value valor que vamos a añadir
          *
          */

        void push(const T &value);

        /**
          *
          * @brief Borra el último elemento añadido a la pila
          * @pre La pila no debe estar vacía
          * @return El valor almacenado en ese elemento
          *
          */

        T pop();

        /**
          *
          * @brief Comprueba si la cola está vacía
          * @return true si está vacía, false si no
          *
          */

        bool empty() const;
          

};

#include <Stack.cpp>

#endif