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
void fill_vector(vi &arr,int n){
    loop(i,0,n){
        cin>>arr[i];
    }
}
//Top Down
int countBST(int n, vi dp){
    if(n==0 || n==1)return 1;
    if(dp[n]!=0)return dp[n];
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x = countBST(i-1, dp);
        int y = countBST(n-i, dp);
        ans+=x*y;
    }
    return  dp[n] = ans;
    unordered_map<pair<int,int>,int> mp;
}

//Bottom Up
int countBST(int n){
    vi dp(n+1, 0);
    dp[0] = dp[1] = 1;
    loop(i,2,n+1){
        loop(j,1,i+1){
            dp[i]+=(dp[j-1]*dp[i-j]);
        }
    }
    return dp[n];
}

int main(){
    int n ;cin>>n;
    vi dp(n+1,0);
    cout<<countBST(n,dp);
    cout<<endl<<endl;
    cout<<countBST(n);
     return 0;
}