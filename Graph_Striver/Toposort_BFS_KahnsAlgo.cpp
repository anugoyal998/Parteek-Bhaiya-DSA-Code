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
    }
    queue<int> q;
    vi indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto j:arr[i])indegree[j]++;
    }
    for(int i=0;i<n;i++){
        if(indegree[i]==0)q.push(i);
    }
    vi topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.pb(node);
        for(auto i:arr[node]){
            indegree[i]--;
            if(indegree[i]==0)q.push(i);
        }
    }
    for(auto i:topo)cout<<i<<" ";
     return 0;
}