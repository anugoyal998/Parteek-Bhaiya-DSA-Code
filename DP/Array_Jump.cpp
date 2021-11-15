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

int min_jump(vi arr){
    int n = arr.size();
    vi dp(n,0);
    for(int i=1;i<n;i++){
        int ans = INT_MAX;
        for(int j=i-1;j>=0;j--){
            if(j+arr[j]>=i)ans = min(ans,dp[j]+1);
        }
        if(ans==INT_MAX)return -1;
        dp[i] = ans;
    }
    return dp[n-1];
}
     
int main(){
    int n;cin >> n;
    vi arr(n);
    fill_vector(arr,n);
    cout<<min_jump(arr);

     return 0;
}