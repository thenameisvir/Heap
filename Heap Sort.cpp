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
  
void heapify(int arr[], int n, int index) {
    int largestIndex = index;
    int leftIndex = 2 * index + 1;   // Left child index
    int rightIndex = 2 * index + 2;  // Right child index

    // Compare with left child
    if (leftIndex < n && arr[leftIndex] > arr[largestIndex]) {
        largestIndex = leftIndex;
    }

    // Compare with right child
    if (rightIndex < n && arr[rightIndex] > arr[largestIndex]) {
        largestIndex = rightIndex;
    }

    // If largestIndex is not the current index, swap and heapify recursively
    if (largestIndex != index) {
        swap(arr[index], arr[largestIndex]);
        heapify(arr, n, largestIndex);
    }
}

void buildHeap(int arr[], int n) {
    // Build heap starting from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    buildHeap(arr, n);

    // Perform heap sort
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // Move current root to end
        heapify(arr, i, 0);     // Heapify reduced heap
    }
}

int main() {
    int arr[] = {5, 10, 15, 20, 25, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform heap sort
    heapSort(arr, n);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
