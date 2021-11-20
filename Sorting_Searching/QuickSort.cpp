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

void quicksort(vi &arr,int s,int e){
    if(s>=e)return;
    int p = partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
     
int main(){
    int n;
    cin >> n;
    vi arr(n);
    fill_vector(arr,n);
    quicksort(arr,0,n-1);
    for(auto i:arr){
        cout<<i<<" ";
    }

     return 0;
}