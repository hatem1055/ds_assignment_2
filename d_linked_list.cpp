#include "bits/stdc++.h"
using namespace std;
template <class  T>
class Node{
    public:
    T value;
    Node* next ;
    Node* prev ;

    Node(T val){
        value = val;
        next = nullptr;
    }

};
template <class  T>
class DoublyLinkedList{
    private:
        int size = 0;
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;

    public:
    DoublyLinkedList(){
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
            new_element->prev = head;
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
        new_element->prev = tail;

        tail = new_element;
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
        cur->prev = new_element;
        new_element->prev = prev;
        prev->next = new_element;
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
        head->prev = nullptr;
        
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
        cur->next->prev = prev;
        prev->next = cur->next;
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
    }
    bool isExist(T element){
        Node<T>* cur = head;
        while(cur != nullptr){
            if(cur->value == element){
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    bool isItemEqual(T element,int index){
        Node<T>* cur = head;
        int i = 0;
        while(cur != nullptr){
            if(cur->value == element && i == index){
                return true;
            }
            cur = cur->next;
            i++;
        }
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
        Node<T> * prev_second = second->prev;
        Node<T> * second_next = second->next;
        if(has_head && adjecent){
            first->next = second_next;
            if(!has_tail) second_next->prev = first;
            second->next = first;
            first->prev = second;
            head = second;
            second->prev = nullptr;
            return;
        }
        if(has_head){
            first->next = second_next;
            if(!has_tail) second_next->prev = first;
            second->next = first_next;
            first_next->prev = second;
            prev_second->next = first;
            first->prev = prev_second;
            head = second;
            second->prev = nullptr;
            if(has_tail) tail = first;
            return;
        }
        Node<T>* prev_first = first->prev;
        if(adjecent){
            prev_first->next = second;
            second->prev = prev_first;
            first->next = second_next;
            if(!has_tail) second_next->prev = first;
            second->next = first;
            first->prev = second;
            if(has_tail) tail = first;
            return;
        }
        second->next = first_next;
        first_next->prev = second;
        first->next = second_next;
        if(!has_tail) second_next->prev = first;
        prev_first->next = second;
        second->prev = prev_first;
        prev_second->next = first;
        first->prev = prev_second;
        if(has_tail) tail = first;
    }
    void forwardTraversal(){
        Node<T>* cur = head;
        cout << "[";
        while(cur != nullptr){
            cout << cur->value << ",";
            cur = cur->next;
        }
        cout << "]";
    }
    void backwardTraversal(){
        Node<T>* cur = tail;
        cout << "[";
        while(cur != nullptr){
            cout << cur->value << ",";
            cur = cur->prev;
        }
        cout << "]";
    }
    bool isEmpty(){
        return size == 0;
    }
    int DoublyLinkedListSize(){
        return size;
    }
    void clear(){
        size = 0;
        tail = nullptr;
        head = nullptr;
    }
    void reverse(){
        if(size == 0 && size == 1){
            return;
        }
        Node<T>* temp = tail;
        tail = head;
        head = temp;
        Node<T>* cur = head;
        while(cur != nullptr){
            temp = cur->next;
            cur->next = cur->prev;
            cur->prev = temp;
            cur = cur->next;
        }
    }
};
int main(){
    DoublyLinkedList<int> ds;
    ds.insertAtTail(1);
    ds.insertAtTail(2);
    ds.insertAtTail(3);
    ds.insertAtTail(4);
    ds.insertAtTail(5);
    ds.insertAtTail(6);
    ds.insertAtTail(7);
    ds.insertAtTail(8);
    ds.forwardTraversal();
    ds.reverse();
    ds.forwardTraversal();
    ds.backwardTraversal();

}