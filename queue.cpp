#include "bits/stdc++.h"
using namespace std;
template <class  T>
class Queue{
    private:
        T* arr ;
        int top;
        int maxsize;
    public:
        Queue(){
            arr = new T[1];
            top = -1;
            maxsize = 1;
        }
        void resize(){
            maxsize *= 2;
            T* temp_t = new T[maxsize];
            for(int i = 0;i <= top;i++){
                temp_t[i] = arr[i];
            }
            arr = temp_t;
        }
        void enqueue(T e){
            if(top == maxsize - 1){
                resize();
            }
            top++;
            arr[top] = e;
        }
        T deque(){
            if(top == -1){
                cout << "Queue is empty" << endl;
                return T();
            }
            T e = arr[0];
            for(int i = 0;i < top;i++){
                arr[i] = arr[i + 1];
            }
            top--;
            return e;
        }
        T first(){
            return arr[top];
        }
        bool isEmpty(){
            return top == -1;
        }
        int size(){
            return top + 1;
        }
        void clear(){
            top = -1;
        }
        void print(){
            cout << "[";
            for(int i = 0;i <= top;i++){
                cout << arr[i] << ",";
            }
            cout << "]" << endl;
        }
};
Queue<int> sort_queue(Queue<int> q){
    vector<int> es;
    while (!q.isEmpty())
    {
        es.push_back(q.deque());
    }
    sort(es.begin(),es.end());
    Queue<int> res;
    for(int n : es){
        res.enqueue(n);
    }
    return res;
    
}
template <class T>
class StackQueue{
    public:
    Queue<T> q1;
    Queue<T> q2;
    void push(T e){
        if(q1.isEmpty()){
            q1.enqueue(e);
        }else{
            q2.clear();
            while(!q1.isEmpty()){
                q2.enqueue(q1.deque());
            }
            q1.clear();
            q1.enqueue(e);
            q2.enqueue(e);
            while(!q2.isEmpty()){
                q1.enqueue(q2.deque());
            }
        }
    }
    T pop(){
        T e = q1.deque();
        return e;
    }
};
string n_to_binary(int n){
    string start = bitset<20>(n).to_string();
    string res;
    bool flag = false;
    for(auto c : start){
        if(c == '1'){
            flag = true;
        }
        if(flag){
            res += c;
        }
    }
    return res;
}
string binary_till_n(int n){
    vector<string> res;
    for(int i = 1;i <= n;i++){
        res.push_back(n_to_binary(i));
    }
    string res_s;
    for(auto s : res){
        res_s += s + " ";
    }
    return res_s;
}
int main(){
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(9);
    q.enqueue(8);
    q.enqueue(6);
    q.enqueue(10);
    StackQueue<int> sq;
    sq.push(1);
    sq.push(2);
    sq.push(3);
    sq.push(4);
    sq.push(5);
    sq.push(6);
    sq.push(7);
    sq.push(8);
    sq.push(9);
    cout << binary_till_n(10000);

}