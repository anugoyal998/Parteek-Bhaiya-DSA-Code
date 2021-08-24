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
//first occurence
int lower_bound(vi arr,int n,int key){
    int st = 0;
    int ed = n-1;
    int ans = -1;
    while(st<=ed){
        int mid = (st+ed)/2;
        if(arr[mid]==key){
            ans = mid;
            ed = mid-1;
        }else if(arr[mid]>key){
            ed = mid-1;
        }else{
            st = mid + 1;
        }
    }
    return ans;
}
//last occurence
int upper_bound(vi arr,int n,int key){
    int st = 0;
    int ed = n-1;
    int ans = -1;
    while(st<=ed){
        int mid = (st+ed)/2;
        if(arr[mid]==key){
            ans = mid;
            st = mid+1;
        }else if(arr[mid]>key){
            ed = mid-1;
        }else{
            st = mid + 1;
        }
    }
    return ans;
}
int main(){
    //count number of occurences of given number in a sorted vector
    int n;
    cin>>n;
    vi arr(n);
    loop(i,0,n){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<lower_bound(arr,n,x)<<" "<<upper_bound(arr,n,x)<<endl;
    cout<<upper_bound(arr,n,x) - lower_bound(arr,n,x) + 1<<endl;
    //STL
    //upper_bound STL function returns an iterator to next greater element than key
    cout<<upper_bound(arr.begin(),arr.end(),x) - lower_bound(arr.begin(),arr.end(),x)<<endl;

     return 0;
}