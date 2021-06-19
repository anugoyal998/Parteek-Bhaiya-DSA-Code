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
class  Compare{
    public:
    bool operator()(int a,int b){
        return a<b;
    }
};
int main(){
    int arr[] = {10,15,20,13,6,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    priority_queue<int,vector<int>,Compare> heap;
    for(int x:arr){
        heap.push(x);
    }
    while(!heap.empty()){
        cout<<heap.top()<<" ";
        heap.pop();
    }

     return 0;
}