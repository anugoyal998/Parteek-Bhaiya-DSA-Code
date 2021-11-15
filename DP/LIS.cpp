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

int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j])dp[i] = max(dp[i],1+dp[j]);
        }
    }
    return *max_element(dp.begin(),dp.end());
}
     
int main(){
    int n;
    cin>>n;
    vi arr(n);
    fill_vector(arr,n);
    cout<<lengthOfLIS(arr);
     return 0;
}