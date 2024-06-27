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

  int a = pq.top();
  return a;
}
int kthlargest(int arr[],int size,int k){
priority_queue<int, vector<int>, greater<int>> pq;
for(int i=0;i<k;i++){
    int e = arr[i];
  pq.push(e);
  }

  for(int i=k;i<size;i++){
    int e = arr[i];
    if(e>pq.top()){
      pq.pop();
      pq.push(e);
    }
  }

  int a = pq.top();
  return a;
}
int main()
{
  int arr[10] = {3,4,5,7,6,8,9};
  int size = 7;
  int k;
  cin>>k;
  int answer = kthlargest(arr,size,k);
  int answer2 = kthsmallest(arr,size,k);
  cout<<answer<<endl<<answer2<<endl;
}
