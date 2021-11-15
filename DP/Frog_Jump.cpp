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

int frogJump(vi arr){
    int n = arr.size();
    vi dp(n,0);
    dp[1] = abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        int x = dp[i-1] + abs(arr[i]-arr[i-1]);
        int y = dp[i-2] + abs(arr[i]-arr[i-2]);
        dp[i] = min(x,y);
    }
    return dp[n-1];
}
     
int main(){
    int n;
    cin>>n;
    vi arr(n);
    fill_vector(arr, n);
    cout<<frogJump(arr);
     return 0;
}