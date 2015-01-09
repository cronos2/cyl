#ifndef TREE_H
#define TREE_H

using namespace std;


template <class T> class Tree {

    public:

        struct Node {

            Node *parent, *left_child, *next_sibling;
            T value;

            Node(){
                this->parent = this->left_child = this->next_sibling = NULL;
                T aux;
                this->value = aux;
            }

            Node(const T &value){
                this->parent = this->left_child = this->next_sibling = NULL;
                T aux;
                this->value = aux;
            }

            Node* getPrevSibling() const {
                if(this->parent == NULL){
                    return NULL;
                }

                Node *curr = this->parent->left_child;

                if(curr == this){
                    return NULL;
                }

                for(; curr->next_sibling != this; curr = curr->next_sibling);

                return curr;
            }

            bool operator==(const Node &other) const {
                if(this->value == other.value){
                    Node *here = this->left_child, *there = other.left_child;

                    while(here != NULL and there != NULL and *here == *there);

                    return here == NULL and there == NULL;
                }

                return false;
            }

        };

        /**
          *
          * @brief Constructor por defecto de la clase
          *
          */

        Tree();

        /**
          *
          * @brief Constructor de la clase
          * @param 
          *
          */

        Tree(const Node &root);

        /**
          *
          * @brief Constructor de copia de la clase
          * @param other instancia de la clase que queremos copiar
          * @return Una copia profunda de other
          *
          */

        Tree(const Tree <T> &other);

        /**
          *
          * @brief Operador de asignación de la clase
          * @param other instancia de la clase a la que queremos asignar this
          * @return *this
          *
          */

        Tree <T>& operator=(const Tree <T> &other);
        
        /**
          *
          * @brief Destructor de la clase
          *
          */

        ~Tree();

        Node* addLeftChild(Node &parent, const T &value);
        Node* addLeftChild(Node &parent, Node &child);

        Node* removeLeftChild(Node &parent);

        Node* insertBefore(Node &reference, Node &child);

        void putSubtree(Node &replace, Tree subtree);

        void removeSubtree(Node &root);

        void copy(const Node *src, Node *dest);

        int size() const;

        bool empty() const;

        Node* getRoot(){
            return this->root;
        }

        const Node* getRoot() const {
            return this->root;
        }

        bool operator==(const Tree &other){
            return this->root == other.root;
        }

        bool operator!=(const Tree &other){
            return not (*this == other);
        }

    private:

        Node *root;

        void clear(Node &root);

};

#include "Tree.cpp"

#endif