// Problem Name: Subset Sum Problem!
// Problem Link: https://www.interviewbit.com/problems/subset-sum-problem/

int rec(vector<int> &v, int n, int k, vector<vector<int>>&dp){
    if(n<=0 or k<0) return 0;
    if(k==0) return 1;
    if(n==1 and v[n-1]!=k) return 0;
    if(n==1 and v[n-1]==k) return 1;
    if(dp[n][k] != -1) return dp[n][k];
    int ans1 = rec(v,n-1,k,dp), ans2 = rec(v,n-1,k-v[n-1],dp);
    return dp[n][k] = (ans1 or ans2);
}
int Solution::solve(vector<int> &v, int k){
    int n = size(v); vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return rec(v,n,k,dp);
}
