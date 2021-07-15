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
void dfs(vi arr[],vi &vis,int src,stack<int> &st){
    vis[src] = 1;
    for(auto i:arr[src]){
        if(!vis[i]){
            dfs(arr,vis,i,st);
        }
    }
    st.push(src);
}
int main(){
    int n,m;
    cin>>n>>m;
    vi arr[n];
    loop(i,0,m){
        int u,v;
        cin>>u>>v;
        arr[u].pb(v);
    }
    vi vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(arr,vis,i,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
     return 0;
}