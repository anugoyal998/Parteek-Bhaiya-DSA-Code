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
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
int mine  = INT_MAX;
int maxe = INT_MIN;
void xyz(Node* root,int level){
    if(root==NULL)return;
    mine = min(mine,level);
    maxe = max(maxe,level);
    xyz(root->left,level-1);
    xyz(root->right,level+1);
}
int verticalWidth(Node* root)
{
    // Code here
    xyz(root,0);
    return maxe-mine+1;
}     
int main(){
    Node* root  = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout<<verticalWidth(root);
    return 0;
}