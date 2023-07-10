#if !defined(DOUBLYLINKEDLIST_H)
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <string>

class DoublyLinkedList {
private:
    Node<std::string>* head;
    Node<std::string>* tail;
    int numElements;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    template<typename T>
    Node<T>* getHead() const;

    template<typename T>
    Node<T>* getTail() const;

    template<typename T>
    Node<T>* searchByValue(std::string);

    bool insertAtEnd(std::string);

    bool insertAtBeginning(std::string);

    void print();

    bool isEmpty();

    int getNumElements() const;

    template<typename T>
    bool swap(Node<T>* node1, Node<T>* node2);
};

#endif