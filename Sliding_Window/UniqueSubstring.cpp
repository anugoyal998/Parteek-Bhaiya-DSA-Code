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

bool check(vi f){
    for(auto i:f){
        if(i>1)return 0;
    }
    return 1;
}
     
int main(){
    //Given a string, write a function to find the largest substring with
    //unique characters
    string s;
    cin >> s;
    unordered_map<char,int> mp;
    int i = 0;
    int j = 0;
    int len = 0;
    int maxe = 0;
    int start = -1;
    while(j<s.length()){
        char ch = s[j];
        if(mp.count(ch) and mp[ch]>=i){
            i = mp[ch]+1;
            len = j-i;
        }
        mp[ch] = j;
        len++;
        j++;
        if(len>maxe){
            maxe = len;
            start = i;
        }
    }
    cout<<s.substr(start,len)<<endl;
    return 0;
}