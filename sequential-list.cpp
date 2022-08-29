#include "sequential-list.h"

SequentialList::SequentialList(unsigned int cap) {
    capacity_=cap;
    size_=0;
    data_=new DataType [cap];
}


SequentialList::~SequentialList() {
    for(int i=0;i<capacity();i++){
        *(data_+i)=0;
    }
    delete[] data_;
    data_=nullptr;
}


unsigned int SequentialList::size() const {
    return SequentialList::size_;
}


unsigned int SequentialList::capacity() const {
    return SequentialList::capacity_;
}


bool SequentialList::empty() const {
    if(size()==0){
        return true;
    }
    else{
        return false;
    }
}


bool SequentialList::full() const {
    if(capacity()==size()){
        return true;
    }
    else{
        return false;
    }
}


SequentialList::DataType SequentialList::select(unsigned int index) const {
    DataType returnValue=0;
    int i=0;
    while(true){
        if(i<size()){
            returnValue=*(data_+i);
        }
        else{
            return returnValue;
        }
        if(i==index){
            return returnValue;
        }
        i++;
    }
}


unsigned int SequentialList::search(DataType val) const {
    int index=0;
    while(true){
        if(*(data_+index)==val){
            return index;
        }
        index++;
        if(index>=size()){
            return size();
        }
    }
}


void SequentialList::print() const {
    int index=0;
    while(true){
        if(index>=size()){
            break;
        }
        std::cout<<"Index "<<index<<": "<<*(data_+index)<<std::endl;
        index++;
    }
}


bool SequentialList::insert(DataType val, unsigned int index) {
    if(index<=size() && size()<capacity()) {
        DataType previous = *(data_ + index);
        DataType temp = 0;
        *(data_ + index) = val;
        for (unsigned int k = index + 1; k < capacity(); k++) {
            temp = *(data_ + k);
            *(data_ + k) = previous;
            previous = temp;
        }
        SequentialList::size_++;
        return true;
    }
    else{
        return false;
    }
}


bool SequentialList::insert_front(DataType val) {
    return insert(val, 0);
}


bool SequentialList::insert_back(DataType val) {
    return insert(val, size());
}


bool SequentialList::remove(unsigned int index) {
    int next=0;
    if(size()==0 || index>=size()){
        return false;
    }
    SequentialList::size_--;
    while(true) {
        if(index>=size()){
            break;
        }
        next=*(data_+index+1);
        *(data_ + index) =next;
        index++;
    }
    *(data_+index)=0;
    return true;
}


bool SequentialList::remove_front() {
    return remove(0);
}


bool SequentialList::remove_back() {
    return remove(size()-1);
}


bool SequentialList::replace(unsigned int index, DataType val) {
    if(index<size()){
        *(data_+index)=val;
        return true;
    }
    else{
        return false;
    }
}
