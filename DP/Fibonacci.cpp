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
//memo
vi dp(maxN,-1);
int fib(int n){
    if(n==0 || n==1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}     
//bottom up
int fib_bottom_up(int n){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    cout<<endl;
    cout<<fib_bottom_up(n)<<endl;
     return 0;
}