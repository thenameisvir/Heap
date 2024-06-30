#include<iostream>
#include<climits>
using namespace std;
class Info{
  public:
  int maxVal;
  bool isHeap;

  Info(int a,bool b){
    this->maxVal = a;
    this->isHeap = b;
  }
};

Info checkMaxHeap(Node* root){
  if(root==NULL){
    Info temp;
    temp.maxVal = INT_MIN;
    temp.isHeap = true;
    return temp;
  }

  if(root->left==NULL && root->right == NULL){
     Info temp;
     temp.maxVal = root->data;
     temp.isHeap = true;
  }

  Info leftAns = checkMaxHeap(root->left);
  Info rightAns = checkMaxHeap(root->right);
  
  if(root->data>leftAns.maxVal && root->data>rightAns.maxVal && leftAns.isHeap && rightAns.isHeap){
    Info ans;
    ans.maxVal = root->data;
    ans.isHeap = true;
    return ans;
  }
  else{
    Info ans;
    ans.maxVal = max(root->data,max(leftAns.maxVal,rightAns.maxVal));
    ans.isHeap = false;
    return ans;  
  }

}
int main()
{

}