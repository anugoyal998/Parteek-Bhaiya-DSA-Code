#include <bits/stdc++.h>
using namespace std;
int xyz(int turn,vector<int> arr){
    if(arr.empty())return 0;
    if(arr[0]>=arr[arr.end()-arr.begin()-1]){
        int x = arr[0];
        arr.erase(arr.begin());
        if(turn&1)return x + xyz(turn+1,arr);
        else return xyz(turn+1,arr);
    }else{
        int x = arr[arr.end()-arr.begin()-1];
        arr.erase(arr.end());
        if(turn&1)return x + xyz(turn+1,arr);
        else return xyz(turn+1,arr);
    }
}
int MaxValue(int n, vector<int> v){
     return xyz(1,v);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<MaxValue(n,v);
    return 0;
}