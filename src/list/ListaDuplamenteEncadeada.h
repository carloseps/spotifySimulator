#pragma once

#include "./node/Node.h"
#include <string>

class ListaDuplamenteEncadeada {
    private:
        Node<std::string>* cabeca;
        Node<std::string>* cauda;
        int qtdElementos;
        
    public:
        ListaDuplamenteEncadeada(void);
        ~ListaDuplamenteEncadeada(void);

        template<typename T>
        Node<T>* getCabeca(void) const;

        template<typename T>
        Node<T>* getCauda(void) const;

        template<typename T>
        Node<T>* buscarCFreq(std::string);
        
        bool inserirNoFim(std::string);

        bool inserirNoInicio(std::string);

        void print(void);
        
        bool estaVazia(void);

        int getQtdElementos(void) const;

        template<typename T>
        bool swap(Node<T>* no1, Node<T>* no2);
};