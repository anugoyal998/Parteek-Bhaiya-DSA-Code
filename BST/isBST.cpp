#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,st,n) for(int i=st;i<n;i++)
#define mod 1000000007
#define maxN 1000001
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};
bool isBST(Node* root,Node* max,Node* min){
    if(!root)return 1;
    if(min!=NULL and root->key<=min->key)return 0;
    if(max!=NULL and root->key>=max->key)return 0;
    bool leftValid = isBST(root->left,root,min);
    bool rightValid = isBST(root->left,max,root);
    return leftValid and rightValid;
}     
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout<<isBST(root,NULL,NULL)<<endl;
     return 0;
}