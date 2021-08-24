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
bool check(vi arr,int n,int k,int b){
    int cnt = 1;
    int prev = arr[0];
    for(int i=1;i<n;i++){
        int diff = arr[i] - prev;
        if(diff>=k){
            cnt++;
            prev = arr[i];
        }
        if(cnt>=b)break;
    }
    return cnt>=b;
}
int main(){
    //There is a long wire along at straight line, which contains N bird at positions
    //x1,x2,.........,xN
    //There are B (B<=N) birds , which becomes angry towards eacg other once put into a
    //nest. To put the birds from hunting each other you want to assign birds to nests s.t.
    // minimum distance between any two birds is as large as possible. What is the largest
    //minimum distance?
    int n;
    cin>>n;
    int b;
    cin>>b;
    vi arr(n);
    loop(i,0,n){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int st = 0;
    int ed = arr[n-1];
    int ans = 0;
    while(st<=ed){
        int mid = (st+ed)/2;
        bool x = check(arr,n,mid,b);
        if(x){
            ans = mid;
            st = mid+1;
        }else{
            ed = mid-1;
        }
    }
    cout<<ans<<endl;
     return 0;
}