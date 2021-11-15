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
//top down
int NKLadder(int n,int k,int dp[]){
    if(n<0)return 0;
    if(n==0)return 1;
    if(dp[n]!=0)return dp[n];
    for(int i=1;i<=k;i++){
        dp[n]+=NKLadder(n-i,k,dp);
    }
    return dp[n];
}   
//bottom up
int NKLadder(int n, int k){
    vi dp(n+1,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0)dp[i]+=dp[i-j];
        }
    }
    return dp[n];
}  
int main(){
    int n,k;
    cin>>n>>k;
    int dp[1000] = {0};
    cout<<NKLadder(n,k,dp);
    cout<<endl;
    cout<<NKLadder(n,k);
     return 0;
}