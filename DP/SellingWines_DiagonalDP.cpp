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

//Diagonal Table Filling
int selling_wines(vi arr,int n){
    vvi dp(n+1,vi(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i==j){
                dp[i][j] = n*arr[i];
            }
            else if(i<=j){
                int year = n-j+i;
                int left = arr[i]*year + dp[i+1][j];
                int right = arr[i]*year + dp[i][j-1];
                dp[i][j] = max(left,right);
            }
        }
    }
    return dp[0][n-1];
}
     
int main(){
    int n;
    cin>>n;
    vi arr(n);
    fill_vector(arr,n);
    cout<<selling_wines(arr,n);

     return 0;
}