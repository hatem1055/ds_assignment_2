#include "bits/stdc++.h"
using namespace std;
template <class  T>
class Node{
    public:
    T value;
    Node* next ;
    Node(T val){
        value = val;
        next = nullptr;
    }

};
template <class  T>
class CircularLinkedList{
    private:
        int size = 0;
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;

    public:
    CircularLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void insertAtHead (T element){
        Node<T>* new_element = new Node<T>(element);
        size++;
        if(head == nullptr){
            head = tail = new_element;
            return;
        }
        if(head == tail){
            tail = head;
            head = new_element;
            new_element->next = tail;
            tail->next = head;
            return;
        }
        Node<T>* temp = head;
        new_element->next = head;
        head = new_element;
    }
    void insertAtTail (T element){
        Node<T>* new_element = new Node<T>(element);
        size++;
        if(head == nullptr){
            head = tail = new_element;
            return;
        }
        tail->next = new_element;
        tail = new_element;
        tail->next = head;
    }
    void insertAt (T element, int index){
        size++;
        if(index == 0){
            insertAtHead(element);
            return;
        }
        if(index == size - 1){
            insertAtTail(element);
            return;
        }

        Node<T>* new_element = new Node<T>(element);
        Node<T>* cur = head;
        Node<T>* prev = nullptr;
        for(int i = 0;i < index;i++){
            prev = cur;
            cur = cur->next;
        }
        new_element->next = cur;
        prev->next = new_element;
        tail->next = head;

    }
    void removeAtHead (){
        size--;
        if(head == nullptr){
            return;
        }
        if(head == tail){
            tail = head = nullptr;
            return;
        }
        head = head->next;
        tail->next = head;
        
    }
    void removeAtTail (){
        size--;
        if(head == nullptr){
            return;
        }
        if(head == tail){
            tail = head = nullptr;
            return;
        }
        Node<T>* cur = head;
        Node<T>* prev = nullptr;
        while(true){
            if(cur == nullptr){
                return;
            }
            if(cur->next == nullptr){
                prev->next = nullptr;
                tail = prev;
                tail->next = head;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        
    }
    void removeAt (int index){
        size--;
        if(index == 0){
            removeAtHead();
            return;
        }
        if(index == size - 1){
            removeAtTail();
            return;
        }

        Node<T>* cur = head;
        Node<T>* prev = nullptr;
        for(int i = 0;i < index;i++){
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        tail->next = head;

    }
    void replaceAt (T element, int index){
        if(index >= size){
            cout << "Out of bound" << endl;
            return;
        }
        Node<T>* cur = head;
        for(int i = 0;i < index;i++){
            cur = cur->next;
        }
        cur->value = element;
        tail->next = head;

    }

    bool isExist(T element){
        Node<T>* cur = head;
        do{
            if(cur->value == element){
                return true;
            }
            cur = cur->next;
        }while(cur != head);
        return false;
    }
    bool isItemEqual(T element,int index){
        Node<T>* cur = head;
        int i = 0;
        do{
            if(cur->value == element && i == index){
                return true;
            }
        }while(cur != head);
        cur = cur->next;
        i++;
        return false;
    }
    Node<T>* getElementPointerAt(int index){
        if(index == 0){
            return head;
        }
        if(index == size - 1){
            return tail;
        }
        Node<T>* cur = head;
        for(int i = 0;i < index;i++){
            cur = cur->next;
        }
        return cur;
    }
    void swap(int first_index,int second_index){
        if(first_index == second_index){
            return;
        }
        if(first_index >= size || second_index >= size ){
            return;
        }
        //make them in order just in case
        if(first_index > second_index){
            int i = first_index;
            first_index = second_index;
            second_index = i;
        }
        bool adjecent = first_index - second_index == -1;
        bool has_head = first_index == 0;
        bool has_tail = second_index == size - 1;
        Node<T>* first = getElementPointerAt(first_index);
        Node<T>* second = getElementPointerAt(second_index);
        Node<T> * first_next = first->next;
        Node<T> * prev_second = getElementPointerAt(second_index - 1);
        Node<T> * second_next = second->next;
        if(has_head && adjecent){
            first->next = second_next;
            second->next = first;
            head = second;
            if(has_tail) tail = first;
            tail->next = head;
            return;
        }
        if(has_head){
            first->next = second_next;
            second->next = first_next;
            prev_second->next = first;
            head = second;
            if(has_tail) tail = first;
            tail->next = head;

            return;
        }
        Node<T>* prev_first = getElementPointerAt(first_index - 1);
        if(adjecent){
            prev_first->next = second;
            first->next = second_next;
            second->next = first;
            if(has_tail) tail = first;
            tail->next = head;

            return;
        }
        second->next = first_next;
        first->next = second_next;
        prev_first->next = second;
        prev_second->next = first;
        if(has_tail) tail = first;
        tail->next = head;

    }
    void print(){
        Node<T>* cur = head;
        cout << "[";
        do{
            cout << cur->value << ",";
            cur = cur->next;
        }while(cur != head);
        cout << "]";
        cout << "tail : " << tail->value << endl;
        if(tail->next != nullptr){
            cout << "tail Next : " << tail->next->value << endl;
        }
    }
    bool isEmpty(){
        return size == 0;
    }
    int CircularLinkedListSize(){
        return size;
    }
    void clear(){
        size = 0;
        tail = nullptr;
        head = nullptr;
    }
};
int main(){
    CircularLinkedList<int> cs;
    cs.insertAtTail(1);
    cs.insertAtTail(2);
    cs.insertAtTail(3);
    cs.insertAtTail(4);
    cs.insertAtTail(5);
    cs.insertAtTail(6);
    cs.insertAtTail(7);
    cs.insertAtTail(8);
    cs.swap(0,7);
    cs.print();
}