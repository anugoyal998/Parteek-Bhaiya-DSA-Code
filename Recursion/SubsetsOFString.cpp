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
void subset(string s,string sof){
    if(s.length()==0){
        cout<<sof<<endl;
        return;
    }
    subset(s.substr(1),sof);
    subset(s.substr(1),sof+s[0]);
}
int subsetSum(int sum,int x,vi arr){
    if(arr.empty()){
        if(sum==x)return 1;
        else return 0;
    }
    int y = arr[0];
    arr.erase(arr.begin());
    return subsetSum(sum,x,arr) + subsetSum(sum+y,x,arr);
}
int main(){
    //print subsequences
    string s;
    cin>>s;
    subset(s,"");


    //subset sum problem
    // int n,x;
    // cin>>n>>x;
    // vi arr(n);
    // loop(i,0,n)cin>>arr[i];
    // cout<<subsetSum(0,x,arr);
    return 0;
}