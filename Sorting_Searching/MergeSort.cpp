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

void merge(vi &arr, int s, int e)
{
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;
    vi temp;
    while (i <= m and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.pb(arr[i++]);
        }
        else
        {
            temp.pb(arr[j++]);
        }
    }
    while (i <= m)
        temp.pb(arr[i++]);
    while (j <= e)
        temp.pb(arr[j++]);
    int k = 0;
    loop(idx, s, e + 1)
    {
        arr[idx] = temp[k++];
    }
}

void merge_sort(vi &arr, int s, int e)
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid + 1, e);
    return merge(arr, s, e);
}

int main()
{
    //divide and conquer
    int n;
    cin >> n;
    vi arr(n);
    fill_vector(arr, n);
    merge_sort(arr, 0, n - 1);
    for (auto i : arr)
        cout << i << " ";

    return 0;
}