#if !defined(QUEUE_H)
#define QUEUE_H

#include "DoublyLinkedList.h"
#include <iostream>
#include <string>

class Queue
{
    private:
        DoublyLinkedList* list = new DoublyLinkedList;
        int numElements;

    public:
        Queue();
        ~Queue(){
            delete[] list;
        }

        bool insert(std::string value){
            Node<std::string>* node = new Node<std::string>(value, this->list->getTail(), this->list->getTail()->getPrevious());

            node->getPrevious()->setNext(node);
            node->getNext()->setPrevious(node);
            
            ++this->numElements;
            return true;
        }

        bool remove(){
            if(this->list->isEmpty()){
                return false;
            }
            Node<std::string>* node = this->list->getHead()->getNext();

            node->getPrevious()->setNext(node->getNext());
            node->getNext()->setPrevious(node->getPrevious());

            delete node;

            --this->numElements;
            return true;
            
        }

};

#endif // QUEUE_H
