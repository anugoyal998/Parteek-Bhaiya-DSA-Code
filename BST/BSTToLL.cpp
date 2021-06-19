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
class LinkedList{
    public:
    Node* head;
    Node* tail;
};
LinkedList tree2LL(Node* root){
    LinkedList l;
    if(root == NULL){
        l.head  = l.tail = NULL;
        return l;
    }
    if(!root->left and !root->right){
        l.head = l.tail = root;
        return l;
    }
    else if(root->left and !root->right){
        LinkedList leftLL = tree2LL(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
    }else if(root->right and !root->left){
        LinkedList rightLL = tree2LL(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
    }else{
        LinkedList leftLL = tree2LL(root->left);
        LinkedList rightLL = tree2LL(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;
        l.head = leftLL.head;
        l.tail = rightLL.tail;   
    }
    return l;
}
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
int main(){
    Node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};
    for(auto x:arr)root = insert(root,x);
    LinkedList l = tree2LL(root);
    Node* temp = l.head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    return 0;
}