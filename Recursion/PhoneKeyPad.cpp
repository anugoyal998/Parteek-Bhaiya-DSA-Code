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
string arr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};     
void keypad(string s,string sof){
    if(s==""){
        cout<<sof<<endl;
        return;
    }
    char ch = s[0];
    string x = arr[ch-'0'];
    for(int i=0;i<x.length();i++){
        keypad(s.substr(1),sof+x[i]);
    }
}
int main(){
    string s;
    cin>>s;
    keypad(s,"");

     return 0;
}