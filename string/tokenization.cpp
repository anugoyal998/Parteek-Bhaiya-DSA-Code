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
    string s;
    getline(cin,s);

    //create a string stream object
    stringstream ss(s);
    string token;
    vector<string> tokens;
    while(getline(ss,token,' ')){
        tokens.push_back(token);
    }
    for(auto i:tokens){
        cout<<i<<"-";
    }

    

     return 0;
}