#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i, st, n) for (int i = st; i < n; i++)
#define mod 1000000007
#define maxN 1000001
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
void fill_vector(vi &arr, int n)
{
    loop(i, 0, n)
    {
        cin >> arr[i];
    }
}

int main()
{
    // Along one side of a road there is sequence of vaccant plots of land. Each plot has a different area (non zero).
    // So, the areas form a sequence A[1],A[2],......,A[N]
    // You want to buy `K` acres of land to build a house. You want to find all segments of contiguous plots
    // whose sum is exactly `K`
    int n;
    cin >> n;
    vi arr(n);
    fill_vector(arr, n);
    int k;
    cin >> k;
    vvi ans;
    int st = 0;
    int ed = 0;
    int sum = 0;
    while(ed<n){
        sum+=arr[ed];
        ed++;
        while(sum>k and st<ed){
            sum-=arr[st];
            st++;
        }
        if(sum==k){
            ans.pb({st,ed-1});
        }
    }
    for(auto i:ans){
        for(auto j:i)cout << j << "";
        cout<<endl;
    }
    return 0;
}