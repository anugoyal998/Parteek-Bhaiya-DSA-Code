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
bool safe(int i,int j,vvi arr){
    int n = arr.size();
    for(int k=0;k<n;k++){
        if(arr[k][j]==1)return 0;
    }
    int row = i;
    int col = j;
    while(row>=0 and col>=0){
        if(arr[row][col])return 0;
        row--;col--;
    }
    row = i;
    col = j;
    while(row>=0 and col<n){
        if(arr[row][col])return 0;
        row--;col++;
    }
    return 1;
}
bool NQueen(int i,vvi &arr,int n){
    if(i==n){
        return 1;
    }
    for(int j=0;j<n;j++){
        if(safe(i,j,arr)){
            arr[i][j] = 1;
            if(NQueen(i+1,arr,n))return 1;
            arr[i][j] = 0; 
        }
    }
    return 0;
} 
int main(){
    int n;
    cin>>n;
    vvi arr(n,vi(n,0));
    if(NQueen(0,arr,n)){
        for(auto i:arr){
            for(auto j:i)cout<<j<<" ";
            cout<<endl;
        }
    }
     return 0;
}