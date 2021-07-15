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
int parent[maxN];
int Rank[maxN];
void makeSet(){
    loop(i,1,maxN){
        parent[i] = i;
        Rank[i] = 0;
    }
}

int findPar(int node){
    if(node==parent[node])return node;
    return parent[node] = findPar(parent[node]);
}

void Union(int u,int v){
    u = findPar(u);
    v = findPar(v);
    if(Rank[u]<Rank[v]){
        parent[u] = v;
    }else if(Rank[u]>Rank[v]){
        parent[v] = u;
    }else{
        parent[v] = u;
        Rank[u]++;
    }
}

int main(){
    makeSet();
    int m;
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
     return 0;
}