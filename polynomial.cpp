#include "polynomial.h"

Polynomial::Polynomial(int A[], int size) {
    size_=size;
    for(int i=0;i<size_;i++){
        data_->insert_back(A[i]);
    }
}


Polynomial* Polynomial::add(Polynomial *rhs) {
    unsigned int maxSize=(this->size()>rhs->size())?this->size():rhs->size();
    DoublyLinkedList* thisData= this->getData();
    DoublyLinkedList* rhsData=rhs->getData();
    int coAr[maxSize];
    for(int i=0;i<maxSize;i++){
        if(this->size()<=i){
            coAr[i]=rhsData->select(i);
        }
        else if(rhs->size()<=i){
            coAr[i]=thisData->select(i);
        }
        else{
            coAr[i]=thisData->select(i)+rhsData->select(i);
        }
    }
    Polynomial* newPoly =new Polynomial(coAr,maxSize);
    return newPoly;
}


Polynomial* Polynomial::sub(Polynomial *rhs) {
    unsigned int maxSize=(this->size()>rhs->size())?this->size():rhs->size();
    DoublyLinkedList* thisData= this->getData();
    DoublyLinkedList* rhsData=rhs->getData();
    int coAr[maxSize];
    for(int i=0;i<maxSize;i++){
        if(this->size()<=i){
            coAr[i]=-1*rhsData->select(i);
        }
        else if(rhs->size()<=i){
            coAr[i]=thisData->select(i);
        }
        else{
            coAr[i]=thisData->select(i)-rhsData->select(i);
        }
    }
    Polynomial* newPoly =new Polynomial(coAr,maxSize);
    return newPoly;
}


Polynomial* Polynomial::mul(Polynomial *rhs) {
    unsigned int maxSize=this->size()+rhs->size()-1;
    DoublyLinkedList* thisData= this->getData();
    DoublyLinkedList* rhsData=rhs->getData();
    int coAr[maxSize];
    for(int i=0;i<maxSize;i++){
        coAr[i]=0;
    }
    for(int i=0;i<this->size();i++){
        for(int j=0;j<rhs->size();j++) {
            coAr[i+j] += thisData->select(i) * rhsData->select(j);
        }
    }
    Polynomial* newPoly =new Polynomial(coAr,maxSize);
    return newPoly;
}

unsigned int Polynomial::size() const {
    return size_;
}

DoublyLinkedList* Polynomial::getData() {
    return data_;
}

void Polynomial::print() {
    bool allZero=true;
    for(int i=size()-1;i>=0;i--){
        if(data_->select(i)>0){
            allZero=false;
            std::cout<<data_->select(i)<<"x"<<"^"<<i;
        }
        else if(data_->select(i)<0){
            allZero= false;
            std::cout<<"("<<data_->select(i)<<")"<<"x"<<"^"<<i;
        }
        if(data_->select(i)!=0) {
            for (int j = i - 1; j >= 0; j--) {
                if (data_->select(j)!=0) {
                    std::cout << " + ";
                    break;
                }
            }
        }
    }
    if(allZero){
        std::cout<<"empty";
    }
    std::cout<<std::endl;
}

