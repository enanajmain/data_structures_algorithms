#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>

template <class T>
class Node
{
public:
    Node (T value) {
        this->value = value;
        next = NULL;
    }
    virtual ~Node () {
    }
    void setNext(Node<T> * next) {
        this->next = next;
    }
    void setValue(T value) {
        this-> value = value;
    }
    Node<T> * getNext() {
        return next;
    }
    T getValue() {
        return value;
    }

private:
    T value;
    Node<T> * next;
};

template <class T>
class LinkedList
{
public:
    LinkedList ();           // create a singly linked list
    LinkedList (T);          // create a singly linked list and add item
    virtual ~LinkedList ();  // delete list and release memory
    void add(T);             // add item at the last
    void insertFirst(T);     // add item at the beginning
    void remove(T);          // remove first occurrence of item
    void removeAllOf(T);     // remove all occurrence of item
    void printList();        // print the items of the list

private:
    Node<T> * root;
};

template <class T>
LinkedList<T>::LinkedList() {
    root = NULL;
}

template <class T>
LinkedList<T>::LinkedList(T value) {
    root = new Node<T>(value);
}

template <class T>
LinkedList<T>::~LinkedList() {
}

template <class T>
void LinkedList<T>::add(T value) {
    Node<T> * tmpNode = new Node<T>(value);
    if (root==NULL) {
        root = tmpNode;
        return ;
    }

    Node<T> * currentNode = root;
    while (currentNode->getNext() != NULL)
        currentNode = currentNode->getNext();
    currentNode->setNext(tmpNode);
}

template <class T>
void LinkedList<T>::insertFirst(T value) {
    Node<T> * tmpNode = new Node<T>(value);
    tmpNode->setNext(root);
    root = tmpNode;
}

template <class T>
void LinkedList<T>::remove(T value) {
    if (root==NULL) return ;
    if (root->getValue() == value) {
        root = root->getNext();
        return ;
    }
    Node<T> * currentNode = root;
    Node<T> * previousNode = NULL;
    while (currentNode->getValue() != value
            && currentNode->getNext() != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->getNext();
    }

    if (currentNode->getValue() == value) {
        currentNode = currentNode->getNext();
        previousNode->setNext(currentNode);
    }
}

template <class T>
void LinkedList<T>::removeAllOf(T value) {
    if (root==NULL) return ;
    if (root->getNext()==NULL) {
        remove(value);
        return ;
    }
    // Remove all the nodes with matching value from the beginning
    while (root->getValue() == value) {
        root = root->getNext();
    }

    Node<T> * currentNode = root;
    Node<T> * previousNode = NULL;

    // traverse list and remove matching nodes until hit end
    while (currentNode->getNext()!=NULL) {
        previousNode = currentNode;
        currentNode = currentNode->getNext();

        if (currentNode->getValue()==value) {
            previousNode->setNext(currentNode->getNext());
            currentNode = previousNode;
        }
    }
}

template <class T>
void LinkedList<T>::printList() {
    if (root==NULL) {
        std::cout << "List is empty" << std::endl;
        return ;
    }
    Node<T> * currentNode = root;
    std::cout << currentNode->getValue() << " ";
    while (currentNode->getNext() != NULL) {
        currentNode = currentNode->getNext();
        std::cout << currentNode->getValue() << " ";
    }
    std::cout << std::endl;
}

#endif          // LINKEDLIST_H