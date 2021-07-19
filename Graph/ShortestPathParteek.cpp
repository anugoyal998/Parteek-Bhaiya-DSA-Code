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
class Node{
    public:
    int x,y,dist;
    Node(int x,int y,int dist){
        this->x = x;this->y = y;this->dist = dist;
    }
};
class Compare{
    public:
    bool operator()(const Node &a,const Node &b){
        return a.dist<=b.dist;
    }
};
int shortest_path(vector<vector<int> > grid){
    int m = grid.size();
    int n = grid[0].size();
    int i = 0;
    int j = 0;
    vector<vector<int>> dist(m+1,vector<int>(n+1,INT_MAX));
    dist[i][j] = grid[i][j];
    set<Node,Compare> s;
    s.insert(Node(0,0,dist[i][j]));
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    while(!s.empty()){
        auto it = s.begin();
        int cx = it->x;
        int cy = it->y;
        int cd = it->dist;
        s.erase(it);
        for(int k=0;k<4;k++){
            int nx = cx+dx[k];
            int ny = cy+dy[k];
            if(nx>=0 and nx<m and ny>=0 and ny<n and cd+grid[nx][ny]<dist[nx][ny]){
                Node temp(nx,ny,dist[nx][ny]);
                if(s.find(temp)!=s.end())s.erase(s.find(temp));
                int nd = grid[nx][ny] + cd;
                dist[nx][ny] = nd;
                s.insert(Node(nx,ny,nd));
            }
        }
    }
    return dist[m-1][n-1];
}     
int main(){

     return 0;
}