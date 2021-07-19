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
int dfs(vector<vector<int>> arr,vector<vector<int>> &vis,int i,int j,int n,int m){
    vis[i][j] = 1;
    int ans = 1;
    if(i-1>=0 and !vis[i-1][j] and arr[i-1][j]){
        ans+=dfs(arr,vis,i-1,j,n,m);
    }
    if(i+1<n and !vis[i+1][j] and arr[i+1][j]){
        ans+=dfs(arr,vis,i+1,j,n,m);
    }
    if(j-1>=0 and !vis[i][j-1] and arr[i][j-1]){
        ans+=dfs(arr,vis,i,j-1,n,m);
    }
    if(j+1<m and !vis[i][j+1] and arr[i][j+1]){
        ans+=dfs(arr,vis,i,j+1,n,m);
    }
    return ans;
}
int largest_island(vector<vector<int> > grid){
    //return the size of largest island in grid
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] and !vis[i][j]){
                int x = dfs(grid,vis,i,j,n,m);
                ans = max(ans,x);
            }
        }
    }
    return ans;
}     
int main(){
    vector<vector<int>> grid = {
        {1,0,0,1,0},
        {1,0,1,0,0},
        {0,0,1,0,1},
        {1,0,1,1,1},
        {1,0,1,1,0}
    };
    cout<<largest_island(grid);
     return 0;
}