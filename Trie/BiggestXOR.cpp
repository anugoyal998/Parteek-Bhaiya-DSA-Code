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
    node* left; //0
    node* right; //1
};  
class trie{
    node* root;
    public:
    trie(){
        root = new node();
    }
    void insert(int n){
        node* temp = root;
        for(int i=31;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit == 0){
                if(!temp->left)temp->left = new node();
                temp = temp->left;
            }else{
                if(!temp->right)temp->right = new node();
                temp = temp->right;
            }
        }
    }
    int max_xor_helper(int value){
        int current_ans = 0;
        node* temp = root;
        for(int j=31;j>=0;j--){
            int bit = (value>>j) & 1;
            if(bit == 0){
                if(temp->right){temp = temp->right;current_ans+=(1<<j);}
                else temp = temp->left;
            }else{
                if(temp->left){temp = temp->left;current_ans+=(1<<j);}
                else temp = temp->right;
            }
        }
        return current_ans;
    }
    int max_xor(int *input,int n){
        int max_xor = 0;
        loop(i,0,n){
            int value = input[i];
            insert(value);
            int current_xor = max_xor_helper(value);
            max_xor = max(max_xor,current_xor);
        }
        return max_xor;
    }
};
int main(){
    int input[] = {3,10,5,25,9,2};
    int n = sizeof(input)/sizeof(input[0]);
    trie t;
    cout<<t.max_xor(input,n);
     return 0;
}