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
     
int main(){
    vi arr = {1,3,4,5,8,10,15,20};
    int idx = lower_bound(arr.begin(),arr.end(),7)-arr.begin();
    arr.insert(arr.begin()+idx,7);
    for(auto i:arr)cout<<i<<" ";

     return 0;
}