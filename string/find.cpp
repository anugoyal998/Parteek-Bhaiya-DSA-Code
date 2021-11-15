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
     
int main(){
    string paragraph = "We are learning about STL strings. STL string class is quite powerful";
    string word;
    getline(cin, word);
    int index = paragraph.find(word);
    if(index == -1){
        cout<<"not found"<<endl;
    }
     return 0;
}