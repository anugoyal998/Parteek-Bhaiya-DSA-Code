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
int roadCut(vector<int> &arr,int n,vector<int> &dp){
    if(n==0)return 0;
    if(dp[n]!=INT_MIN)return dp[n];
    loop(i,1,n+1){
        int x = roadCut(arr,n-i,dp);
        dp[n] = max(dp[n],x + arr[i]);
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vi price(n+1);
    loop(i,1,n+1)cin>>price[i];
    price[0] = 0;
    vector<int> dp(n+1,INT_MIN);
    dp[0] = 0;
    cout<<roadCut(price,n,dp)<<endl;
     return 0;
}