#include<iostream>
#include<queue>
using namespace std;
int removeStones(int arr[],int k,int size){
  if(size==0){
    return -1;
  }
  priority_queue<int>pq;
  for(int i=0;i<size;i++){
    int element = arr[i];
    pq.push(element);
  }

  while(k>0){
    int e = pq.top();
    e = e-(e/2);
    pq.pop();
    pq.push(e);
    k--;
  }

  int sum = 0;
  while(!pq.empty()){
    int e = pq.top();
    sum+=e;
    pq.pop();
  }
  return sum;
}

int main(){
  int arr[10] = {4,3,6,7,10};
  int k = 4;
  int size = 5;
  int answer = removeStones(arr,k,size);
  cout<<answer<<endl;
}