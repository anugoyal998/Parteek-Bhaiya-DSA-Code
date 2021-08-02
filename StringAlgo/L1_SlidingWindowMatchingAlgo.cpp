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
     
int main(){
    //Guven text T and pattern P, find whether P exists in T or not.
    //In case it exist, print all the occurrences of P in T.
    string t,p;
    getline(cin,t);
    cin>>p;
    int n = t.size();
    int m = p.size();
    string s = "";
    int i = 0;
    while(i<n){
        if(s.length()<m){
            s+=t[i++];
        }
        if (s.length()==m){
            if(s==p)cout<<i-m<<" ";
            s.erase(s.begin());
        }
    }
     return 0;
}