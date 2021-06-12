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
set<string> ans;
void permut(string s,string sof){
    if(s.length()==0){
        ans.insert(sof);
        return;
    }
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        string x = s.substr(0,i) + s.substr(i+1);
        permut(x,sof+ch);
    }
} 
int main(){
    string s;
    cin>>s;
    permut(s,"");
    for(auto i:ans)cout<<i<<endl;
    // cout<<ans.size();
     return 0;
}