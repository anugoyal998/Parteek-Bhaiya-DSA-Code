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

int non_adjacent(vi &arr){
    int n = arr.size();
    //corner cases
    if(n==1){
        return max(arr[0],0);
    }
    if(n==2){
        return max(0,max(arr[1],arr[2]));
    }
    //bottom up dp
    vi dp(n+1,0);
    
    for(int i=0;i<n;i++){
        int ans = 0;
        for(int j=i-2;j>=0;j--){
            ans = max(ans,dp[j]);
        }
        ans+=arr[i];
        dp[i] = ans;
    }
    return *max_element(dp.begin(),dp.end());
}
     
int main(){
    int n;cin>>n;
    vi arr(n);
    fill_vector(arr,n);
    cout<<non_adjacent(arr);

     return 0;
}