// Problem Name: Increasing Path in Matrix
// Problem Link: https://www.interviewbit.com/problems/increasing-path-in-matrix/

int n, m;
int rec(vector<vector<int>> &v, int i, int j, vector<vector<int>> &dp){
    if(i>=n or j>=m) return -1;
    if(i==n-1 and j==m-1) return 1;
    if(dp[i][j] != -2) return dp[i][j];
    int ans1{-1}, ans2{-1};
    if(i+1 < n and v[i][j] < v[i+1][j]) ans1 = rec(v,i+1,j,dp);
    if(j+1 < m and v[i][j] < v[i][j+1]) ans2 = rec(v,i,j+1,dp);
    if(ans1==-1 and ans2==-1) return dp[i][j] = -1;
    return dp[i][j] = 1 + max(ans1, ans2);
}
int Solution::solve(vector<vector<int>> &v){
    n = size(v); m = size(v[0]);
    vector<vector<int>> dp(n+1, vector<int>(m+1, -2));
    return rec(v,0,0,dp);
}
