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
    vector<pair<int,int>> arr[n+1];
    loop(i,0,m){
        int u,v,wt;
        cin>>u>>v>>wt;
        arr[u].pb({v,wt});
        arr[v].pb({u,wt});
    }
    vi dis(n+1,INT_MAX);
    queue<pair<int,int>> q;
    q.push({1,0});
    dis[1] = 0;
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        for(auto i:arr[node.first]){
            if(dis[node.first]+i.second<dis[i.first]){
                dis[i.first] = dis[node.first]+i.second;
                q.push({i.first,dis[i.first]});
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
     return 0;
}