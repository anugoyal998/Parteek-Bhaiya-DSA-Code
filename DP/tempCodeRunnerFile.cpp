int coin(vector<int> &arr,int v){
    if(v==0)return 0;
    if(dp[v]!=INT_MAX)return dp[v];
    for(auto i:arr){
        if(v>=i){
            int x = 1 + coin(arr,v-i);
            if(x==0)x = INT_MAX;
            dp[v] = min(dp[v],x);
        }
    }
    return dp[v]==INT_MAX?-1:dp[v];
}