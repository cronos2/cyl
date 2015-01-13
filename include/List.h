#ifndef LIST_H
#define LIST_H

#include <Node.h>

using namespace std;


/**
  *
  * @brief TDA List
  *     Lista enlazada simple.
  * @section Función de abstracción: una lista representa una sucesión
  *     ordenada de objetos encadenados.
  *
  */

template <class T> class List {

    private:

        Node <T> *head;

        void clear(Node <T> *from);

        Node <T>* back();

    public:

        /**
          *
          * @brief Constructor vacío de la clase
          *
          */

        List();

        /**
          *
          * @brief Constructor de la clase
          * @param value el valor que va a almacenar el primer nodo
          * @return Una lista enlazada cuyo primer elemento es un nodo 
          *         de valor value
          *
          */

        List(const T &value);

        /**
          *
          * @brief Constructor de copia de la clase
          * @param other instancia de la clase que queremos copiar
          * @return Una copia profunda de other
          *
          */

        List(const List <T> &other);

        /**
          *
          * @brief Operador de asignación de la clase
          * @param other instancia de la clase a la que queremos asignar this
          * @return *this
          *
          */

        List <T>& operator=(const List <T> &other);

        /**
          *
          * @brief Destructor de la clase
          *
          */

        ~List();

        /**
          *
          * @brief Añade un elemento al final de la lista
          * @param value el valor que almacenará el nodo
          *
          */

        void push(const T &value);

        /**
          *
          * @brief Añade un elemento al principio de la lista
          * @param value el valor que almacenará el nodo
          *
          */

        void unshift(const T &value);

        /**
          *
          * @brief Borra el último elemento de la lista y devuelve su valor
          * @pre La lista no debe estar vacía
          * @return El valor del nodo
          *
          */

        T pop();

        /**
          *
          * @brief Borra el primer elemento de la lista y devuelve su valor
          * @pre La lista no debe estar vacía
          * @return El valor del nodo
          *
          */

        T shift();

        /**
          *
          * @brief Getter del head de la lista
          * @return Puntero al head
          *
          */

        Node <T>* getHead() const {

            return this->head;

        }

        /**
          *
          * @brief Comprueba si la lista está vacía
          * @return true si está vacía, false si no
          *
          */

        bool empty() const {

          return this->head == NULL;

        }

};

#include <List.cpp>

#endif