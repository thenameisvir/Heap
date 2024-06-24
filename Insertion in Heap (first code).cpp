#include<iostream>
#include<algorithm>
using namespace std;
class Heap{
  public:
  int* arr;
  int capacity;
  int size;

  Heap(int capacity){
    this->capacity = capacity;
    this->arr = new int[capacity];
    this->size = 0;
  }


  void insert(int val){
    if(size==capacity){
      cout<<"Heap overflow"<<endl;
      return;
    }

    // size will get increased
    size++;
    int index = size;
    arr[index] = val;

   // take the value to it's correct position

   while(index>1){
     int parentindex = index/2;
     if(arr[index]>arr[parentindex]){
      swap(arr[index],arr[parentindex]);
      index = parentindex;
     }
     else{
      break;
     }
   }
  }

  void print(){
    for(int i=1;i<=size;i++){
      cout<<arr[i]<<" ";
    }
  }


};
int main(){
  Heap h(20);
  h.insert(10);
  h.insert(20);
  h.insert(600);
  h.insert(1);
  h.insert(1110);

  h.print();
  return 0;
}