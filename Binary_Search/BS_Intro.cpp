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
int binary_search(vi arr,int n, int key){
    int st = 0;
    int ed = n-1;
    while(st<=ed){
        int mid = (st+ed)/2;
        if(arr[mid]>key){
            ed = mid-1;
        }else if(arr[mid]<key){
            st = mid+1;
        }else{
            return mid;
        }
    }
    return -1;
}     
int main(){
    int n;
    cin>>n;
    vi arr(n);
    loop(i,0,n)cin>>arr[i];
    int x;
    cin>>x;
    cout<<binary_search(arr,n,x);

     return 0;
}