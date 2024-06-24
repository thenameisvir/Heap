
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
    this->size = 0;
    this->arr = new int[capacity];
  }

  void insert(int val){
    if(size==capacity){
      cout<<"Heap has been overflowed: "<<endl;
      return;
    }
    // insertion at the end
    size++;
    int index = size;
    arr[index] = val;

    // taking the element to the right place

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
  void printheap(){
      for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
      }
    }

    int deleteheapnode(){
      int answer = arr[1];
      //replacement
      arr[1] = arr[size];
      size--;
      int index = 1;
      while(index<size){
         int leftchild = 2*index;
         int rightchild = 2*index+1;

         int largestindex = index;
         if(leftchild <= size&& arr[largestindex]<arr[leftchild]){
          largestindex = leftchild;
         }
         if(rightchild <=size&& arr[largestindex]<arr[rightchild]){
          largestindex = rightchild;
         }

         if(index==largestindex){
          break;
         }
         else{
          swap(arr[index],arr[largestindex]);
          index = largestindex;
         }
      }

      return answer;

    }
};
int main(){
  Heap h(10);
  h.insert(20);
  h.insert(30);
  h.insert(40);
  h.insert(50);
  h.insert(60);
  h.insert(70);
  h.insert(80);
  h.insert(90);
  h.printheap();

  cout<<endl;
 int ans =  h.deleteheapnode();
 cout<<endl;
 cout<<ans;
 cout<<endl;
   h.printheap();

  // If i want to convert an array into a heap then it will eat O(n) time complexity
}