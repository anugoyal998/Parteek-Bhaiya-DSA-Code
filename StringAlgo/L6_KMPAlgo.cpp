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
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n,0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
} 
int main(){
    string t,p;
    cin>>t>>p;
    // vi pi = prefix_function(t);
    // for(auto i:pi)cout<<i<<" ";
    string s = "";
    s+=p;s+='#';s+=t;
    vi pi = prefix_function(s);
    int ans = 0;
    for(int i=p.length();i<s.length();i++){
        if(pi[i]==p.length())ans++;
    }
    cout<<ans<<endl;


     return 0;
}