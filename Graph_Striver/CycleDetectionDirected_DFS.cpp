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
bool dfs(vi arr[],vi &vis,vi dfsVis,int src){
    vis[src] = dfsVis[src] = 1;
    for(auto i:arr[src]){
        if(!vis[i]){
            if(dfs(arr,vis,dfsVis,i))return 1;
        }else if(dfsVis[i]==1)return 1;
    }
    dfsVis[src] = 0;
    return 0;
} 
int main(){
    int n,m;
    cin>>n>>m;
    vi arr[n+1];
    loop(i,0,m){
        int u,v;
        cin>>u>>v;
        arr[u].pb(v);
    }
    vi vis(n+1,0);
    vi dfsVis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(dfs(arr,vis,dfsVis,i)){
                cout<<"YES, cycle is present"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO, cycle is not present"<<endl;
     return 0;
}