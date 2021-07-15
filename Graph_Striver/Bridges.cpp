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
void dfs(int node,int parent, vi &vis,vi &tin,vi &low, int &timer, vi arr[]){
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for(auto i:arr[node]){
        if(i==parent)continue;
        if(!vis[i]){
            dfs(i,node,vis,tin,low,timer,arr);
            low[node] = min(low[node],tin[i]);
            if(low[i]>tin[node]){
                cout<<node<<" "<<i<<endl;
            }
        }else{
            low[node] = min(low[node],tin[i]);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vi arr[n];
    loop(i,0,m){
        int u,v;
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    vi tin(n,-1);
    vi low(n,-1);
    vi vis(n,0);
    int timer = 0;
    loop(i,0,n){
        if(!vis[i]){
            dfs(i,-1,vis,tin,low,timer,arr);
        }
    }

     return 0;
}