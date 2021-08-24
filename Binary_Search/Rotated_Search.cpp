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
int rotated_search(vi arr,int n,int key){
    int st = 0;
    int ed = n-1;
    while(st<=ed){
        int mid = (st+ed)/2;
        if(arr[mid]==key)return mid;
        if(arr[mid]<=arr[mid]){
            //left
            if(key>=arr[st] and key<=arr[mid]){
                ed = mid-1;
            }else{
                st = mid+1;
            }
        }else{
            //right
            if(key>=arr[mid] and key<=arr[ed]){
                st = mid+1;
            }else{
                ed = mid-1;
            }
        }
    }
    return -1;
}
int main(){
    //Sorted array --> Rotated Clockwise
    int n;
    cin>>n;
    vi arr(n);
    loop(i,0,n)cin>>arr[i];
    int x;
    cin>>x;
    cout<<rotated_search(arr,n,x)<<endl;
     return 0;
}