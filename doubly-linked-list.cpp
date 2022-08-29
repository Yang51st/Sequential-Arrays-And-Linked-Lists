#include "doubly-linked-list.h"

DoublyLinkedList::Node::Node(DataType data) {
    value=data;
    next= nullptr;
    prev= nullptr;
}


DoublyLinkedList::DoublyLinkedList() {
    size_=0;
    head_= nullptr;
    tail_= nullptr;
}


DoublyLinkedList::~DoublyLinkedList() {
    while(size()>0){
        remove_back();
    }
}


unsigned int DoublyLinkedList::size() const {
    return size_;
}


unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY;
}


bool DoublyLinkedList::empty() const {
    if(size()==0){
        return true;
    }
    else{
        return false;
    }
}


bool DoublyLinkedList::full() const {
    if(size()==capacity()){
        return true;
    }
    else{
        return false;
    }
}


DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    int i=0;
    Node* current;
    current=head_;
    while(i<size()-1){
        if(i==index){
            break;
        }
        i++;
        current=current->next;
    }
    return current->value;
}


unsigned int DoublyLinkedList::search(DataType value) const {
    int index=0;
    Node* current=head_;
    while(index<size()){
        if(current->value==value){
            break;
        }
        index++;
        current=current->next;
    }
    return index;
}


void DoublyLinkedList::print() const {
    if(empty()){
        std::cout<<"{}"<<std::endl;
        return;
    }
    else {
        std::cout << "{ ";
        Node *current = head_;
        while (true) {
            std::cout << current->value;
            if (current == tail_) {
                break;
            }
            std::cout << ", ";
            current = current->next;
        }
        std::cout << " }" << std::endl;
        return;
    }
}


DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    Node* current=head_;
    int i=0;
    while(i<size()){
        if(i==index){
            break;
        }
        i++;
        current=current->next;
    }
    return current;
}


bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    if(index<=size() && size()<capacity()){
        if(empty()){
            Node* temp=new Node(value);
            head_=temp;
            tail_=temp;
            size_++;
            return true;
        }
        else if(index==0){
            return insert_front(value);
        }
        else if(index==size()){
            return insert_back(value);
        }
        else{
            Node* first=getNode(index-1);
            Node* second=first->next;
            Node* inserted=new Node(value);
            first->next=inserted;
            second->prev=inserted;
            inserted->prev=first;
            inserted->next=second;
            size_++;
            return true;
        }
    }
    else{
        return false;
    }
}


bool DoublyLinkedList::insert_front(DataType value) {
    if(empty()){
        Node* temp=new Node(value);
        head_=temp;
        tail_=temp;
        size_++;
        return true;
    }
    else if(size()<capacity()) {
        Node *inserted = new Node(value);
        Node *temp = head_;
        head_ = inserted;
        head_->next = temp;
        temp->prev = head_;
        size_++;
        return true;
    }
    else{
        return false;
    }
}


bool DoublyLinkedList::insert_back(DataType value) {
    if(empty()){
        Node* temp=new Node(value);
        head_=temp;
        tail_=temp;
        size_++;
        return true;
    }
    else if(size()<capacity()){
        Node* inserted=new Node(value);
        Node* temp=tail_;
        tail_=inserted;
        tail_->prev=temp;
        temp->next=tail_;
        size_++;
        return true;
    }
    else{
        return false;
    }
}


bool DoublyLinkedList::remove(unsigned int index) {
    if(index<size() && size()>0){
        if(size()==1){
            delete head_;
            head_= nullptr;
            tail_= nullptr;
            size_--;
            return true;
        }
        else if(index==0){
            return remove_front();
        }
        else if(index==size()-1){
            return remove_back();
        }
        else{
            Node* target=getNode(index);
            Node* first=target->prev;
            Node* second=target->next;
            first->next=second;
            second->prev=first;
            delete target;
            size_--;
            return true;
        }
    }
    else{
        return false;
    }
}


bool DoublyLinkedList::remove_front() {
    if(size()==1){
        delete head_;
        head_= nullptr;
        tail_= nullptr;
        size_--;
        return true;
    }
    else if(size()>1){
        Node* target=head_;
        Node* after=target->next;
        head_=after;
        after->prev= nullptr;
        delete target;
        size_--;
        return true;
    }
    else{
        return false;
    }
}


bool DoublyLinkedList::remove_back() {
    if(size()==1){
        delete tail_;
        head_= nullptr;
        tail_= nullptr;
        size_--;
        return true;
    }
    else if(size()>1){
        Node* target=tail_;
        Node* previous=tail_->prev;
        tail_=previous;
        tail_->next= nullptr;
        delete target;
        size_--;
        return true;
    }
    else{
        return false;
    }
}


bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    if(index<size()){
        Node* temp=getNode(index);
        temp->value=value;
        return true;
    }
    else{
        return false;
    }
}
