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
bool bfs(vi arr[],vi &vis,int src){
    vis[src]  = 1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto i:arr[node]){
            if(!vis[i]){
                vis[i] = 1;
                q.push({i,node});
            }else{
                if(i!=parent)return 1;
            }
        }
    }
    return 0;
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
    vi vis(n+1,0);
    loop(i,1,n+1){
        if(vis[i]==0){
            if(bfs(arr,vis,i)){
                cout<<"YES, There is a cycle"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO, There is no cycle"<<endl;
     return 0;
}