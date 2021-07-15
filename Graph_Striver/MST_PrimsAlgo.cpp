#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i, st, n) for (int i = st; i < n; i++)
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
    vector<pair<int,int>> arr[n];
    loop(i,0,m){
        int u,v,wt;
        cin>>u>>v>>wt;
        arr[u].pb({v,wt});
        arr[v].pb({u,wt});
    }
    vi parent(n,-1);
    vi key(n,INT_MAX);
    vi mst(n,0);
    key[0] = 0;parent[0] = -1;
    loop(i,0,n-1){
        int mini = INT_MAX,u;
        loop(v,0,n){
            if(mst[v]==0 and key[v]<mini){
                mini = key[v],u  = v;
            }
        }
        mst[u] = 1;
        for(auto it:arr[u]){
            int v = it.first;
            int wt = it.second;
            if(mst[v]==0 and wt<key[v]){
                parent[v] = u;key[v] = wt;
            }
        }
    }
    loop(i,1,n){
        cout<<parent[i]<<"->"<<i<<endl;
    }
    return 0;
}