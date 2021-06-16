//Find the largest sum of a subset of nodes in a binary tree,
//such that if a node is included in the sum then its parent
//and children not be included in the subset sum.
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
pair<int,int> maxSubsetSum(node* root){
    pair<int,int> p;
    if(!root){
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> left = maxSubsetSum(root->left);
    pair<int,int> right = maxSubsetSum(root->right);
    p.first = root->data + left.second + right.second;
    p.second = max(left.first, left.second) + max(right.first, right.second);
    return p;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    loop(i,0,n)cin>>arr[i];
    node* root = buildTree(0,n,arr);
    pair<int,int> p = maxSubsetSum(root);
    cout<<max(p.first,p.second)<<endl;
     return 0;
}