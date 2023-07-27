// Problem Name: Min Sum Path in Triangle
// Problem Link: https://www.interviewbit.com/problems/min-sum-path-in-triangle/

int n;
int rec(vector<vector<int>> &v, int i, int j, vector<vector<int>> &dp){
    if(i>=n or j>=size(v[i])) return 1e9;
    if(i==n-1) return v[i][j];
    if(dp[i][j] != 1e9) return dp[i][j];
    int ans1 = rec(v,i+1,j,dp), ans2 = rec(v,i+1,j+1,dp);
    return dp[i][j] = v[i][j] + min(ans1, ans2);
}
int Solution::minimumTotal(vector<vector<int>> &v){
    n = size(v); vector<vector<int>> dp(n+1, vector<int>(size(v[n-1])+1, 1e9));
    return rec(v,0,0,dp);
}