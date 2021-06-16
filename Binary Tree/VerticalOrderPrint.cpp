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
map<int,vi> mp;
void vertivalPrint(node* root,int level){
    if(root==NULL)return;
    mp[level].push_back(root->data);
    vertivalPrint(root->left,level-1);
    vertivalPrint(root->right,level+1);
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);
    vertivalPrint(root,0);
    for(auto i:mp){
        for(auto j:i.second)cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}