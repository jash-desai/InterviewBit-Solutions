// Problem Name: Maximum Path in Triangle
// Problem Link: https://www.interviewbit.com/problems/maximum-path-in-triangle/

int n;
int rec(vector<vector<int>> &v, int i, int j, vector<vector<int>> &dp){
    if(i>=n or j>=n) return 0;
    if(i==n-1) return v[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int ans1 = rec(v,i+1,j,dp), ans2 = rec(v,i+1,j+1,dp);
    return dp[i][j] = v[i][j] + max(ans1, ans2);   
}
int Solution::solve(vector<vector<int>> &v){
    n = size(v); vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return rec(v,0,0,dp);
}
