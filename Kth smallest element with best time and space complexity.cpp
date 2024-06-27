#include<iostream>
#include<queue>
using namespace std;
int kthsmallest(int arr[],int size,int k){
  priority_queue<int>pq;
  for(int i=0;i<k;i++){
    int e = arr[i];
    pq.push(e);
  }
  for(int i=k;i<size;i++){
    int e = arr[i];
    if(e<pq.top()){
      pq.pop();
      pq.push(e);
    }
  }

  int ans = pq.top();
  return ans;
}
int main(){
  int arr[10] = {3,9,4,6,5,8,7};
  int size = 7;
  int k;
  cin>>k;
  int answer = kthsmallest(arr,size,k);
  cout<<answer;}