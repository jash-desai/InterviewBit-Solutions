// Problem Name: 0-1 Knapsack
// Problem Link: https://www.interviewbit.com/problems/0-1-knapsack/

int rec(vector<int> &a, vector<int> &b, int n, int k, vector<vector<int>>&dp){
    if(n<=0 or k<=0) return 0;
    if(n==1 and b[n-1]<=k) return a[n-1];
    if(dp[n][k] != -1) return dp[n][k];
    int ans1 = rec(a,b,n-1,k,dp), ans2 = 0;
    if(b[n-1] <= k) ans2 = a[n-1] + rec(a,b,n-1,k-b[n-1],dp);
    return dp[n][k] = max(ans1, ans2);
}
int Solution::solve(vector<int> &a, vector<int> &b, int k){
    int n = size(a); vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return rec(a,b,n,k,dp);
}
