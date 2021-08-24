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
const int N = 1e5+2;
int a[N], tree[4*N];
void build(int node,int st,int ed){
    if(st==ed){
        tree[node] = a[st];
        return;
    } 
    int mid = (st+ed)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,ed);
    //this line may change acc to question
    tree[node] = tree[2*node] + tree[2*node+1];
}     
int query(int node,int st,int ed,int l,int r){
    if(st>r || ed<l)return 0;
    if(l<=st and ed<=r)return tree[node];
    int mid = (st+ed)/2;
    int q1 = query(2*node,st,mid,l,r);
    int q2 = query(2*node+1,mid+1,ed,l,r);
    return q1+q2;
}
int main(){
    int n;
    cin>>n;
    loop(i,0,n)cin>>a[i];
    build(1,0,n-1);
    // loop(i,1,15)cout<<tree[i]<<" ";
    while(1){
        int type;
        cin>>type;
        if(type==-1) break;
        if(type==1){
            int l,r;cin>>l;cin>>r;
            int ans = query(1,0,n-1,l,r);
            cout<<ans<<endl;
        }
    }
     return 0;
}