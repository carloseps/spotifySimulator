#pragma once

#include <iostream>

template <typename T>
class Node {
    private:
        Node<T>* proximo;
        Node<T>* anterior;
        T valor;
        int contadorChamadas;
        
    public:
        Node();
        Node(T);
        Node(T, Node*, Node*);

        T getValor();
        void setValor(T val);
        
        Node* getAnterior();
        void setAnterior(Node*);
        
        Node* getProximo();
        void setProximo(Node*);
        
        int getContadorChamadas();
        void setContadorChamadas(int);
};

template<typename T>
Node<T>::Node(void):
contadorChamadas(0), proximo(NULL), anterior(NULL) {}

template<typename T>
Node<T>::Node(T val):
valor(val), contadorChamadas(0), proximo(NULL), anterior(NULL) {}

template<typename T>
Node<T>::Node(T val, Node* p, Node* a):
valor(val), proximo(p), anterior(a) {}

template<typename T>
T Node<T>::getValor(void) {
    return this->valor;
}

template<typename T>
Node<T>* Node<T>::getProximo(void) {
    return this->proximo;
}

template<typename T>
void Node<T>::setProximo(Node<T>* p) {
    this->proximo = p;
}

template<typename T>
Node<T>* Node<T>::getAnterior(void) {
	return this->anterior;
}

template<typename T>
void Node<T>::setAnterior(Node<T>* a) {
	this->anterior = a;
}

template<typename T>
int Node<T>::getContadorChamadas() {
	return this->contadorChamadas;
}

template<typename T>
void Node<T>::setContadorChamadas(int c) {
	this->contadorChamadas = c;
}