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
ll ways(int i,int n){
    if(i>n)return 0;
    if(i==n)return 1;
    return ways(i+1,n) + ways(i+2,n) + ways(i+3,n);  
}
int main(){
    //given a ladder containing N steps, you can take a jump of
    // 1,2 or 3 at each step. Find the number of ways to climb the ladder.
    int n ;
    cin>>n;
    cout<<ways(0,n);
     return 0;
}