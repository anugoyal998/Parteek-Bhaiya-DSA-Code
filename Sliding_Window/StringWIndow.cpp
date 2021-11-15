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


bool contain(unordered_map<char,int> temp,unordered_map<char,int> mp){
    for(auto i:temp){
        if(i.second>mp[i.first])return 0;
    }
    return 1;
}
     
int main(){
    string s,t;
    cin>>s>>t;
    int i = 0;
    int j  = 0;
    unordered_map<char,int> temp;
    for(auto i:t)temp[i]++;
    unordered_map<char,int> mp;
    int ans = s.length()+1;
    while(j<s.length()){
        mp[s[j]]++;
        bool x = contain(temp,mp);
        if(x){
            while(i<=j and contain(temp,mp)){
                ans = min(ans,j-i+1);
                mp[s[i]]--;
                i++;
            }
        }
        j++;
    }
    if(contain(temp,mp)){
        while(i<j and contain(temp,mp)){
            ans = min(ans,j-i);
            mp[s[i]]--;
            i++;
        }
    }
    cout<<ans<<endl;

     return 0;
}