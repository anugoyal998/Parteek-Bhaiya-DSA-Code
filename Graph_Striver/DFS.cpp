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
void dfs(vi arr[],vi &vis,int src){
    vis[src] = 1;
    cout<<src<<" ";
    for(auto i:arr[src]){
        if(!vis[i]){
            dfs(arr,vis,i);
        }
    }
}    
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arr[n+1];
    loop(i,0,m){
        int u,v;
        cin >> u >> v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    vi vis(n+1,0);
    loop(i,1,n+1){
        if(vis[i]==0){
            dfs(arr,vis,i);
        }
    }

     return 0;
}