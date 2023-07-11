#if !defined(DOUBLYLINKEDLIST_H)
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <string>

class DoublyLinkedList {
private:
    Node<std::string>* head;
    Node<std::string>* tail;

public:
    DoublyLinkedList() {
        this->getHead()->setNext(this->getTail());
    }

    ~DoublyLinkedList(){
        while(!this->isEmpty()){
            delete this->getHead()->getNext();
        }
    }

    Node<std::string>* getHead() const{ return this->head; }

    Node<std::string>* getTail() const{ return this->tail; }

    Node<std::string>* searchByValue(std::string value){
        Node<std::string>* node = this->getHead();
        
        while (node->getNext() != nullptr){
            if(node->getValue() == value){
                return node;
            } else node = node->getNext();
        }
        return nullptr;
    }

    void print(){
        Node<std::string>* node = this->getHead();
        int i = 0;
        while(node->getNext() != nullptr){
            std::cout << "Posição " << i <<  " - " << node->getValue() << std::endl;
        }
    }

    bool isEmpty(){
        if(this->getHead()->getNext() == this->getTail()){
            return true;
        } else return false;
    }

    bool swap(Node<std::string>* node1, Node<std::string>* node2){
        Node<std::string>* nodeAux = node1;
        node1->setPrevious(node2->getPrevious());
        node1->setNext(node2->getNext());
        node1->getNext()->setPrevious(node1);
        node1->getPrevious()->setNext(node1);

        node2->setPrevious(nodeAux->getPrevious());
        node2->setNext(nodeAux->getNext());
        node2->getNext()->setPrevious(node2);
        node2->getPrevious()->setNext(node2);

        delete nodeAux;

        return true;
    }
};

#endif