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
int snake_ladder(int n,vector<pair<int,int>> snake,vector<pair<int,int>> ladder){
     //board to graph
     vector<int> board(n+1,0);
     for(auto sp:snake){
          int s = sp.first;
          int e = sp.second;
          board[s] = e-s;
     }
     for(auto lp:ladder){
          int s = lp.first;
          int e = lp.second;
          board[s] = e-s;
     }
     //graph
     vector<int> arr[n+1];
     for(int u=1;u<n;u++){
          for(int dice=1;dice<=6;dice++){
               int v = u+dice;
               if(v<=n)arr[u].pb(v);
          }
     }
     vi vis(n,0);
     vi dis(n,INT_MAX);
     dis[0] = 0;
     queue<pair<int,int>> q;
     q.push({0,0});
     vis[0] = 1;
     while(!q.empty()){
          pair<int,int> p = q.front();
          q.pop();
          for(auto i:arr[p.first]){
               if(!vis[i]){
                    if(dis[p.first]+1<dis[i]){
                         dis[i] = dis[p.first] + 1;
                         q.push({i,dis[i]});
                    }
               }
          }
     }
     int ans = *min_element(dis.begin(), dis.end());
     return ans;
}     
int main(){
     

     return 0;
}