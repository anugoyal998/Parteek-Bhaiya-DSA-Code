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

int lcs(string s1,string s2,int i,int j, vvi dp){
    if(i==s1.length() or j==s2.length()){return 0;}
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j])return dp[i][j] = 1+lcs(s1,s2,i+1,j+1, dp);
    int op1 = lcs(s1,s2,i+1,j, dp);
    int op2 = lcs(s1,s2,i,j+1, dp);
    return dp[i][j] =  max(op1,op2);
}

int lcs(string s1,string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    vvi dp(n1+1,vi(n2+1,0));
    loop(i,1,n1+1){
        loop(j,1,n2+1){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                int op1 = dp[i-1][j];
                int op2 = dp[i][j-1];
                dp[i][j] = max(op1,op2);
            }
        }
    }
    return dp[n1][n2];
}
     
int main(){
    string s1,s2;cin>>s1>>s2;
    int n1 = s1.length();
    int n2 = s2.length();
    vvi dp(n1,vi(n2,-1));
    cout<<lcs(s1,s2,0,0,dp);
    cout<<endl;
    cout<<endl;
    cout<<lcs(s1,s2);
     return 0;
}