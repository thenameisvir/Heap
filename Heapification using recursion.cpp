#include<iostream>
using namespace std;
class Heap{
  public:
  int *arr;
  int capacity;
  int size;

  Heap(int capacity){
    this->capacity = capacity;
    this->arr = new int[capacity];
    this->size = 0;
  }

  void insertinHeap(int data){
    if(size==capacity){
      cout<<"Heap has been overflowed "<<endl;
      return;
    }
    size++;
    int index = size;
    arr[index] = data;


    while(index>1){
      int parentIndex = index/2;
      if(arr[index]>arr[parentIndex]){
        swap(arr[index],arr[parentIndex]);
        index = parentIndex;
      }
      else{
        break;
      }
      
    }
  }

  void printHeap(){
    for(int i=1;i<=size;i++){
      cout<<arr[i]<<" ";
    }
  }

  int deleteElement(){
    int ans = arr[1];
    arr[1] = arr[size];
    size--;
    int index = 1;

    while(index<=size){
      int leftindex = 2*index;
      int rightindex = 2*index+1;
      int largestIndex = index;
      if(leftindex<=size && arr[leftindex]>arr[largestIndex]){
        largestIndex = leftindex;
      }
      if(rightindex<=size && arr[rightindex]>arr[largestIndex]){
        largestIndex = rightindex;
      }
      if(index==largestIndex){
        break;
      }
      else{
        swap(arr[index],arr[largestIndex]);
        index = largestIndex;
      }

    }
    return ans;

    }
  };
  
  void heapify(int *arr,int n,int index){

    int leftindex = 2*index;
    int rigthindex = 2*index+1;
    int largestIndex = index;

    if(leftindex<=n && arr[leftindex]>arr[largestIndex]){
      largestIndex = leftindex;
    }
     if(rightindex<=n && arr[rightindex]>arr[largestIndex]){
      largestIndex = rghtindex;
    }

    if(index!=largestIndex){
      swap(arr[index],arr[largestIndex]);

      index = largestIndex;
      heapify(arr,n,index);
    }
  }
int main(){
  
}