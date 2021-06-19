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
class Node{
    public:
    int data;
    Node* left,*right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
Node* MinBSTBuild(int arr[],int st,int ed){
    if(st>ed)return NULL;
    int mid = (st+ed)/2;
    Node* root = new Node(arr[mid]);
    root->left = MinBSTBuild(arr,st,mid-1);
    root->right = MinBSTBuild(arr,mid+1,ed);
    return root;
}   
void inOrder(Node* root){
    if(root == NULL){return;}
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder(Node* root){
    if(root == NULL){return;}
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}  
int main(){
    int arr[] = {1,2,3,4,5,6,7};
    Node* root = MinBSTBuild(arr,0,6);
    inOrder(root);
    cout<<endl;
    preOrder(root);
     return 0;
}