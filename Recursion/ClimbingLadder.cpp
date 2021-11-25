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
ll ways(int n){
    if(n==0)return 1;
    if(n<0)return 0;
    return ways(n-1) + ways(n-2) + ways(n-3);
}
int main(){
    //given a ladder containing N steps, you can take a jump of
    // 1,2 or 3 at each step. Find the number of ways to climb the ladder.
    int n ;
    cin>>n;
    cout<<ways(n);
     return 0;
}