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
void printAtLevelK(node* root,int k){
    if(!root)return;
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printAtLevelK(root->left,k-1);
    printAtLevelK(root->right,k-1);
}
int printNodesAtK(node* root,node* target,int k){
    //base case
    if(root == NULL)return -1;
    //react the target node
    if(root==target){
        printAtLevelK(target,k);
        return 0;
    }
    //other case
    int DL = printNodesAtK(root->left,target,k);
    if(DL!=-1){
        //2 cases
        //print the current node
        if(DL+1==k){
            cout<<root->data<<" ";
        }
        //or print somenodes in the rightsubtree
        else{
            printAtLevelK(root->right,k-2-DL);
        }
        return 1+DL;
    }
    int DR = printNodesAtK(root->right,target,k);
    if(DR!=-1){
        //2 cases
        //print current node
        if(DR+1==k){
            cout<<root->data<<" ";
        }
        //or print someondes
        else printAtLevelK(root->left,k-2-DR);
        return 1+DR;
    }
    return -1;
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->left->right->right->left = new node(9);
    root->left->right->right->right = new node(10);
    node* target = root->left->right;
    int k = 2;
    printNodesAtK(root,target,k);
     return 0;
}