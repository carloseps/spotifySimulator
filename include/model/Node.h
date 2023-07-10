#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    Node<T>* next;
    Node<T>* previous;
    T value;
    int callCount;

public:
    Node();
    Node(T);
    Node(T, Node*, Node*);

    T getValue();
    void setValue(T val);

    Node* getPrevious();
    void setPrevious(Node*);

    Node* getNext();
    void setNext(Node*);

    int getCallCount();
    void setCallCount(int);
};

template<typename T>
Node<T>::Node() : callCount(0), next(nullptr), previous(nullptr) {}

template<typename T>
Node<T>::Node(T val) : value(val), callCount(0), next(nullptr), previous(nullptr) {}

template<typename T>
Node<T>::Node(T val, Node* n, Node* p) : value(val), next(n), previous(p) {}

template<typename T>
T Node<T>::getValue() {
    return value;
}

template<typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

template<typename T>
void Node<T>::setNext(Node<T>* n) {
    next = n;
}

template<typename T>
Node<T>* Node<T>::getPrevious() {
    return previous;
}

template<typename T>
void Node<T>::setPrevious(Node<T>* p) {
    previous = p;
}

template<typename T>
int Node<T>::getCallCount() {
    return callCount;
}

template<typename T>
void Node<T>::setCallCount(int c) {
    callCount = c;
}

#endif  // NODE_H
