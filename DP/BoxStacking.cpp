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

class Box{
    public:
    int width,depth,height;
    Box(int w,int d,int h){
        width = w;
        depth = d;
        height = h;
    }
};
     
int main(){
    //width depth height
    int n;
    cin>>n;
    vector<Box> arr;
    loop(i,0,n){
        int w,d,h;
        cin>>w>>d>>h;
        arr.push_back(Box(w,d,h));
    }
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i].width>arr[j].width && arr[i].height>arr[j].height){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
     return 0;
}