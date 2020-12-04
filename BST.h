#include <iostream>
using namespace std;
#include "Node.h"

template <class T>
class BST{
    public:
        BST();
        ~BST();
        void add(T data);
        void printIn2();

    private:
        Node<T> *root;
        int cont5=0;
        void destruye(Node<T> *r);
        void inOrden2(Node<T> *r);
};

template <class T>
BST<T>::BST(){
    this->root=nullptr;
}

template <class T>
BST<T>::~BST(){
    destruye(root);
}

template <class T>
void BST<T>::destruye(Node<T> *r){
    if(r!=nullptr){
        destruye(r->getLeft());
        destruye(r->getRight());
        delete r;
    }
}

//Complejidad O(log n)
template <class T>
void BST<T>::add(T data){ //Agrega al arbol, segun el numero de accesos de cada IP, al ser iguales estos accesos la comparacion realizada es por el numero de la IP
    Node<T>* curr=root;
    Node<T>* father=nullptr;
    while(curr!=nullptr){
        if(curr->getData().cont==data.cont){
            father = curr;
            curr=(curr->getData().IP> data.IP) ? curr->getLeft() : curr->getRight();
        }
        else{
            father=curr;
            curr=(curr->getData().cont> data.cont) ? curr->getLeft() : curr->getRight();
        }
    }
    if(father==nullptr){
        root=new Node<T>(data);
    }
    else{
       father->getData().cont > data.cont ? father->setLeft(new Node<T>(data)) : father->setRight(new Node<T>(data));
    }
}

//Complejidad O(n)
template <class T>
void BST<T>::inOrden2(Node<T> *r){ //recorrido en inorden inverso, de mayor a menor
    if(r != nullptr){
        inOrden2(r->getRight());
        if(cont5!=5){
            cout<<cont5+1<<" - "<<r->getData().IPn<<endl;
            cont5++;
        }
        else if(cont5==5){
            return;
        }
        inOrden2(r->getLeft());
    }
}

template <class T>
void BST<T>::printIn2(){
    cont5=0;
    inOrden2(root);
    cout<<endl;
}