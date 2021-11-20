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

int partition(vi &arr,int s,int e){
    int pivot = arr[e];
    int i = s-1;
    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

int quick_select(vi arr,int s,int e,int k){
    int p = partition(arr,s,e);
    if(p==k){
        return arr[p];
    }else if(k<p){
        return quick_select(arr,s,p-1,k);
    }else{
        return quick_select(arr,p+1,e,k);
    }
}

int main(){
    //write a function that takes input an array of distinct integers and
    //returns kth smallest int the array
    vi arr = {10,5,2,0,7,6,4};
    int n = arr.size();
    int k;
    cin >> k;
    cout<<quick_select(arr,0,n-1,k);

     return 0;
}