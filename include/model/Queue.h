#if !defined(QUEUE_H)
#define QUEUE_H

#include "DoublyLinkedList.h"

template <typename T>
class Queue
{
private:
    Node<T>* head;
    Node<T>* tail;

    DoublyLinkedList<T> list;

public:
    Queue();
    ~Queue();
    void add(const T& item);
    void remove();
    void update(const T& oldItem, const T& newItem);
    bool isEmpty() const;
    void print() const;
};

template <typename T>
Queue<T>::Queue() {
    head = new Node<T>();
    tail = new Node<T>();

    head->setNext(tail);
    tail->setPrevious(head);
}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty())
        remove();

    delete head;
    delete tail;
}

template <typename T>
void Queue<T>::add(const T& item) {
    list.insertAtEnd(item);
}

template <typename T>
void Queue<T>::remove() {
    if (isEmpty()) {
        return;
    }

    Node<T>* temp = head->getNext();
    list.remove(temp);
    delete temp;
}

template <typename T>
void Queue<T>::update(const T& oldItem, const T& newItem) {
    Node<T>* current = head->getNext();
    while (current != tail) {
        if (current->getData() == oldItem) {
            current->setData(newItem);
            break;
        }
        current = current->getNext();
    }
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return head->getNext() == tail;
}

template <typename T>
void Queue<T>::print() const {
    list.print();
}

#endif // QUEUE_H
