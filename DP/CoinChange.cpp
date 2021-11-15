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
//without dp --> TLE
int coinChange(vi &arr,int v){
    if(v==0)return 0;
    int ans = INT_MAX;
    for(auto i:arr){
        if(v>=i){
            int x = 1 + coinChange(arr,v-i);
            if(x==0){
                x = INT_MAX;
            }
            ans = min(ans,x);
        }
    }
    return ans==INT_MAX?-1:ans;
}
//with dp --> Top down --> TLE
vector<int> dp(100000,INT_MAX);
int coin(vector<int> &arr,int v){
    if(v==0)return 0;
    if(dp[v]!=INT_MAX)return dp[v];
    for(auto i:arr){
        if(v>=i){
            int x = 1 + coin(arr,v-i);
            if(x==0)x = INT_MAX;
            dp[v] = min(dp[v],x);
        }
    }
    return dp[v]==INT_MAX?-1:dp[v];
}
//with dp --> bottom up --> accepted
int coinC(vector<int> &arr,int v){
    vector<int> dp(v+1,0);
    for(int i=1;i<=v;i++){
        dp[i] = INT_MAX;
        for(int c:arr){
            if(i-c>=0 and dp[i-c]!=INT_MAX){
                dp[i] = min(dp[i],dp[i-c] + 1);
            }
        }
    }
    return dp[v] == INT_MAX?-1:dp[v];
}
int main(){
    int n;
    cin>>n;
    vi arr(n);
    loop(i,0,n)cin>>arr[i];
    int v;
    cin>>v;
    cout<<coinChange(arr,v)<<endl;
    cout<<coin(arr,v)<<endl;
    cout<<coinC(arr,v)<<endl;

     return 0;
}