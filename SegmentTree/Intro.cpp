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
const int N = 1e5+2;
int a[N], tree[4*N];
void build(int node,int st,int ed){
    if(st==ed){
        tree[node] = a[st];
        return;
    } 
    int mid = (st+ed)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,ed);
    //this line may change acc to question
    tree[node] = tree[2*node] + tree[2*node+1];
}     
int main(){
    int n;
    cin>>n;
    loop(i,0,n)cin>>a[i];
    build(1,0,n-1);
    loop(i,1,15)cout<<tree[i]<<" ";
     return 0;
}