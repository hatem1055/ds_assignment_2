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
class LinkedList{
    public:
    int size = 0;

    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    LinkedList(){
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
        Node<T> * prev_second = getElementPointerAt(second_index - 1);
        Node<T> * second_next = second->next;
        if(has_head && adjecent){
            first->next = second_next;
            second->next = first;
            head = second;
            if(has_tail) tail = first;

            return;
        }
        if(has_head){
            first->next = second_next;
            second->next = first_next;
            prev_second->next = first;
            head = second;
            if(has_tail) tail = first;
            return;
        }
        Node<T>* prev_first = getElementPointerAt(first_index - 1);
        if(adjecent){
            prev_first->next = second;
            first->next = second_next;
            second->next = first;
            if(has_tail) tail = first;
            return;
        }
        second->next = first_next;
        first->next = second_next;
        prev_first->next = second;
        prev_second->next = first;
        if(has_tail) tail = first;
    }
    void print(){
        Node<T>* cur = head;
        cout << "[";
        while(cur != nullptr){
            cout << cur->value << ",";
            cur = cur->next;
        }
        cout << "]";
    }
    bool isEmpty(){
        return size == 0;
    }
    int linkedListSize(){
        return size;
    }
    void clear(){
        size = 0;
        tail = nullptr;
        head = nullptr;

    }
};
LinkedList<int> combine_zeros(Node<int>* head){
    LinkedList<int> res;
    Node<int>* cur = head;
    int current_sum = 0;
    while(cur != nullptr){
        int cur_value = cur->value;
        if(cur_value == 0){
            if(current_sum != 0) res.insertAtTail(current_sum);
            current_sum = 0;
        }
        current_sum += cur_value;
        cur = cur->next;
    }
    return res;
}
LinkedList<int> merge_sorted(vector<LinkedList<int>> lists){
    LinkedList<int> res;
    while (true)
    {
        int selected_index = 0;
        int smallest = INT_MAX;
        for(int i = 0;i < lists.size();i++){
            if(lists[i].isEmpty()){
                continue;
            }
            if(lists[i].head->value < smallest){
                smallest = lists[i].head->value;
                selected_index = i;
            }
        }
        if(smallest == INT_MAX){
            break;
        }
        res.insertAtTail(smallest);
        lists[selected_index].removeAtHead();
    }
    return res;
}
int main(){
    LinkedList<int> ls1;
    ls1.insertAtTail(1);
    ls1.insertAtTail(4);
    ls1.insertAtTail(5);
    LinkedList<int> ls2;
    ls2.insertAtTail(1);
    ls2.insertAtTail(3);
    ls2.insertAtTail(4);
    LinkedList<int> ls3;
    ls3.insertAtTail(2);
    ls3.insertAtTail(6);
    merge_sorted({ls1,ls2,ls3}).print();
}