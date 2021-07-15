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
bool dfs(vi arr[],vector<pair<int,int>> &vis,int src){
    vis[src].first = 1;
    vis[src].second = 0 ;
    for(auto i:arr[src]){
        if(vis[i].first==0){
            vis[i].first = 1;
            vis[i].second = !vis[src].second;
            if(!dfs(arr,vis,i))return 0;
        }else if(vis[i].second==vis[src].second)return 0;
    }
    return 1;
}   
int main(){
    int n,m;
    cin>>n>>m;
    vi arr[n+1];
    loop(i,0,m){
        int u,v;cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    vector<pair<int,int>> vis(n+1,{0,-1});
    loop(i,1,n+1){
        if(vis[i].first==0){
            if(!dfs(arr,vis,i)){
                cout<<"No, it's not a bipartite"<<endl;return 0;
            }
        }
    }
    cout<<"Yes, it's a bipartite"<<endl;
     return 0;
}