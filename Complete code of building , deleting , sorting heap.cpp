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

  void insertInHeap(int val){
    if(size==capacity){
      cout<<"Heap has been overflowed "<<endl;
      return;
    }

    size++;
    int index = size;
    arr[index] = val;
    while(index>1){
      int parentIndex = index/2;
      if(arr[index]>arr[parentIndex]){
        swap(arr[index],arr[parentIndex]);
        index = parentIndex;
      }
    }
  } 


  void printHeap(){
    for(int i=1;i<=size;i++){
      cout<<arr[i]<<" ";
    }
  }

  int deleteNode(){
    int answer = arr[1];
    arr[1] = arr[size];
    size--;
    int index = 1;
    while(index<size){
      int leftchild = 2*index;
      int rightchild = 2*index+1;
      int largestIndex = index;

      if(leftchild<=size && arr[leftchild]>arr[largestIndex]){
        largestIndex = leftchild;
      }
      if(rightchild<=size && arr[rightchild]>arr[largestIndex]){
        largestIndex = rightchild;
      }
      if(index==largestIndex){
        break;
      }
      else{
        swap(arr[index],arr[largestIndex]);
        index = largestIndex;
      }
    }
    return answer;
  }
};

void heapify(int *arr,int size,int index){
  int leftindex = 2*index;
  int rightindex = 2*index+1;
  int largestIndex = index;

  if(leftindex<=size && arr[leftindex]>arr[largestIndex]){
    largestIndex = leftindex;
  }
  
  if(rightindex<=size && arr[rightindex]>arr[largestIndex]){
    largestIndex = rightindex;
  }

  if(index!=largestIndex){
    swap(arr[index],arr[largestIndex]);
    index = largestIndex;

    heapify(arr,size,index);
  }
}

void buildHeap(int arr[], int size){
   for(int i=size/2;i>0;i--){
    heapify(arr,size,i);
   }
}

void heapsort(int arr[], int size){
  while(size>1){
     swap(arr[1],arr[size]);
     size--;
     heapify(arr,size,1);
  }
}
int main(){
  int arr[] = {-1,5,10,15,20,25,12};
  buildHeap(arr,6);
  cout<<"Printing the Heap "<<endl;
  for(int i=1;i<=6;i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
  cout<<"After heap sort: "<<endl;
  heapsort(arr,6);
  for(int i=1;i<=6;i++){
    cout<<arr[i]<<" ";
  }
  
  

}