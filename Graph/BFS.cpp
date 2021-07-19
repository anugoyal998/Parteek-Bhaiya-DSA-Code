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
void bfs(vi arr[],vi &vis,int src){
    queue<int> q;q.push(src);
        vis[src] = 1;
    while(q.size()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto i:arr[src]){
            if(!vis[i]){q.push(i);vis[i]=1;}
        }
    }
} 
int main(){
    int n,m;cin>>n>>m;
    vi arr[n];
    loop(i,0,m){
        int u,v;
        cin>>u>>v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    vi vis(n,0);
    loop(i,0,n){
        if(!vis[i]){bfs(arr,vis,i);}
    }
     return 0;
}