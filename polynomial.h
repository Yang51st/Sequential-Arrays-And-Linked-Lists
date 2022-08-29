#ifndef LAB1_POLYNOMIAL_H
#define LAB1_POLYNOMIAL_H

#include "doubly-linked-list.h"

class Polynomial {

private :
    friend class PolynomialTest ;
    unsigned int size_;
    DoublyLinkedList* data_=new DoublyLinkedList();
    DoublyLinkedList* getData();

public :
    Polynomial(int A[],int size);
    Polynomial* add(Polynomial* rhs);
    Polynomial* sub(Polynomial* rhs);
    Polynomial* mul(Polynomial* rhs);
    unsigned int size() const;
    void print();

};
#endif
