// Problem Name: Chain of Pairs
// Problem Link: https://www.interviewbit.com/problems/chain-of-pairs/

#define vvi vector<vector<int>>
#define vi vector<int>
int rec(vvi&v, int n, int p, vvi&dp){
    if(n<=0) return 0;
    if(dp[n][p+1] != -1) return dp[n][p+1];
    if(p==-1){
        int ans1 = rec(v,n-1,p,dp);
        int ans2 = 1 + rec(v,n-1,n-1,dp);
        return dp[n][p+1] = max(ans1, ans2);
    }
    int ans1 = rec(v,n-1,p,dp), ans2{0};
    if(v[n-1][1] < v[p][0]) ans2 = 1 + rec(v,n-1,n-1,dp);
    return dp[n][p+1] = max(ans1, ans2);
}
int Solution::solve(vector<vector<int>> &v){
    int n = size(v); vvi dp(n+1, vi(n+1, -1)); return rec(v,n,-1,dp);
    /* not working :(
    int n = size(v); vvi dp(n+1, vi(n+1, 0));
    for(int i{1}; i<=n; i++){
        for(int j{n-1}; j>=-1; j--){
            if(j==-1){
                int ans1 = dp[i-1][j];
                int ans2 = 1 + dp[i-1][i-1];
                dp[i][j+1] = max(ans1, ans2);
            }else{
                int ans1 = dp[i-1][j]; int ans2{0};
                if(v[i-1][1] < v[j][0]) ans2 = 1 + dp[i-1][i-1];
                dp[i][j+1] = max(ans1, ans2);
            }
        }
    }
    return dp[n][0];
    */
}
