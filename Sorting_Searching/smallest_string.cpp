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

bool compare(string a,string b){
    return a+b<b+a;
}
     
int main(){
    //concatenate strings to get lexicographically smallest one
    vector<string> arr = {"a","ab","aba"};
    int n = 3;
    sort(arr.begin(),arr.end(),compare);
    for(auto i:arr)cout<<i;

     return 0;
}