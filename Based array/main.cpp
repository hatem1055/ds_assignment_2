#include <iostream>
using namespace std;

class arrayList{
    int*arr;
    int maxSize;
    int length;
public:
    arrayList(int s){
        if(s<0){
            maxSize=10;
        }
        else{
            maxSize=s;
            length=0;
            arr=new int[maxSize];
        }
    }
void insertAt(int element ,int index){
    if (index >=0 && index <=length ){
        if (length<maxSize){
            for (int i = length; i > index ; --i) {
                arr[i]=arr[i-1];
            }
            arr[index]=element;
            length++;
        } else{
            cout<< "list is full"<< endl;
        }
    } else{
        cout << "invalid index "<<endl;
    }
    }
int retrieveAt( int index){
        if (index >= 0 && index < length){
            return arr[index];
        }
        else{
            cout << "Invalid index "<<endl;
            return -1;
        }
    }
void removeAt(int index ){
    if (index >=0 && index <length){
        for(int i=index; i<length -1;i++){
            arr[i]=arr[i+1];
        }
        length--;
    }
    else{
        cout << "Invalid index" << endl;
    }
    }
void replaceAt(int newele,int index){
    if (index >=0 && index < length){
        arr[index]=newele;
    }
    else{
        cout<< "Invalid index" << endl;
    }
    }
bool isItemEq(int element ,int index){
        if(index >=0 && index < length){
            return arr[index] == element;
        } else {
            cout << "Invalid index " <<endl;
            return false;
        }
    }
bool isEmpty(){
    return length == 0;
    }
bool isFull(){
        return length ==maxSize;
    }

int  listSize ()
{
return length;
    }
int maxListSize (){
    return maxSize;
    }
void clear() {
    length = 0;
    }
void print(){
    for (int i = 0; i < length ; ++i) {
        cout <<arr[i] <<" ";
    }
    cout <<endl;
    }
};















int main() {

}
