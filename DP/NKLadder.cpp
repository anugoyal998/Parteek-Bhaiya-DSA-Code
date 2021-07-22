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
int NKLadder(int n,int k,int *dp){
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=0)return dp[n];
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans+=NKLadder(n-i,k,dp);
    }
    return dp[n] = ans;
}     
int main(){
    int n,k;
    cin>>n>>k;
    int dp[1000] = {0};
    cout<<NKLadder(n,k,dp);
     return 0;
}