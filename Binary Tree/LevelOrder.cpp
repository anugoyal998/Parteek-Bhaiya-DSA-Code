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
node* buildTree(){
    int d;
    cin>>d;
    if(d==-1)return NULL;
    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
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
    node* root = buildTree();
    levelOrderPrint(root);

     return 0;
}