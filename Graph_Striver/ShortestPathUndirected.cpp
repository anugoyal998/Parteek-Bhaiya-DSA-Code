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
    vi vis(n,0);
    vi dis(n,INT_MAX);
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto i:arr[node]){
            if(dis[node]+1<dis[i]){
                dis[i] = dis[node]+1;
                q.push(i);
            }
        }
    }
    for(auto i:dis){
        cout<<i<<" ";
    }
     return 0;
}