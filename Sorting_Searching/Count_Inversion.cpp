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

int merge(vi &arr, int s, int e)
{
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;
    vi temp;
    int cnt = 0;
    while (i <= m and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.pb(arr[i++]);
        }
        else
        {
            cnt += m - i + 1;
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
    return cnt;
}
int inversion_count(vi &arr, int s, int e)
{
    if (s >= e)
        return 0;
    int mid = (s + e) / 2;
    int c1 = inversion_count(arr, s, mid);
    int c2 = inversion_count(arr, mid + 1, e);
    int ci = merge(arr, s, e);
    return c1 + c2 + ci;
}

int main()
{
    int n;
    cin >> n;
    vi arr(n);
    fill_vector(arr, n);
    cout << inversion_count(arr, 0, n - 1);
    return 0;
}