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
Node* insert(Node* root,int key){
    if(root == NULL){
        return new Node(key);
    }
    if(key<root->data){
        root->left = insert(root->left,key);
    }else{
        root->right = insert(root->right,key);
    }
    return root;
}
void inOrder(Node* root){
    if(root == NULL){return;}
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main(){
    Node* root = NULL;
    int arr[] = {0,3,10,1,6,14,4,7,13};
    for(int x:arr){
        root = insert(root,x);
    }
    inOrder(root);
    return 0;
}