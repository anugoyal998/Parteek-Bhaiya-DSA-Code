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
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};
node* buildTree(int i,int n,int arr[]){
    if(arr[i]==-1 || i>=n)return NULL;
    node* x = new node(arr[i]);
    x->left = buildTree(2*i+1,n,arr);
    x->right = buildTree(2*i+2,n,arr);
    return x;
}     
void levelOrderPrint(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<"\n";
            if(!q.empty())q.push(NULL);
        }else{
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}  
int main(){
    int n;
    cin>>n;
    int arr[n];
    loop(i,0,n)cin>>arr[i];
    node* root = buildTree(0,n,arr);
    levelOrderPrint(root);
     return 0;
}