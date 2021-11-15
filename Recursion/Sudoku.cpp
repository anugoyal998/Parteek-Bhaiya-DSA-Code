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
bool help(int i,int j,vvi arr,int no){
    //check for row and column
    loop(k,1,10){
        if(arr[k][j]==no || arr[i][k]==no)return false;
    }
    //check for sub grid
    int sx = ((i-1)/3)*3 + 1; 
    int sy = ((j-1)/3)*3 + 1;
    for(int x=sx;x<sx+3;x++){
        for(int y=sy;y<sy+3;y++){
            if(arr[x][y]==no)return false;
        }
    }
    return true;
}
bool Sudoku(vvi &arr,int i,int j){
    if(i==10){
        for(int u=1;u<10;u++){
            loop(v,1,10)cout<<arr[u][v]<<" ";
            cout<<endl;
        }
    }
    if(j==10){
        return Sudoku(arr,i+1,1);
    }
    if(arr[i][j]!=0)return Sudoku(arr,i,j+1);
        for(int x=1;x<=9;x++){
        if(help(i,j,arr,x)){
            arr[i][j] = x;
            if(Sudoku(arr,i,j+1))return 1;
        }
    }
    //backtracking
    arr[i][j] = 0;
    return 0;
} 
int main(){
    vvi arr(10,vi(10,0));
    loop(i,1,10){
        loop(j,1,10){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    if(Sudoku(arr,1,1));
    else cout<<"NO SOLUTION";
     return 0;
}