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
int z[maxN] = {0};
//naive 
void z_function(string s){
    int n = s.length();
    loop(i,1,n){
        loop(j,i,n){
            if(s[j-i]==s[j])z[i]++;
            else break;
        }
    }
} 
//optimized
vi z_function_optimized(string s){
    int n = s.length();
    vi z(n,0);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r)
        z[i] = min(r-i+1,z[i-l]);
        while(i+z[i]<n and s[z[i]]==s[i+z[i]])++z[i];
        if(i+z[i]-1>r){
            l = i;r = i+z[i]-1;
        }
    }
    return z;
}
int main(){
    //Z function for a string S is defined as an array of length n (assuming string length
    // is n ), where the ith element is equal to the greatest number of elements statrting
    //from index i that coincide with first character of S. 
    string s;
    cin >> s;
    vi z = z_function_optimized(s);
    for(auto i:z)cout<<i<<" ";
     return 0;
}