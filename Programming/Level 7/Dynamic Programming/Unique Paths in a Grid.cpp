// Problem Name: Unique Paths in a Grid
// Problem Link: https://www.interviewbit.com/problems/unique-paths-in-a-grid/

int n,m;
int rec(vector<vector<int>> &v, int i, int j, vector<vector<int>> &dp){
    if(i>=n or j>=m) return 0;
    if(v[i][j]) return 0;
    if(i==n-1 and j==m-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int ans1 = rec(v,i+1,j,dp), ans2 = rec(v,i,j+1,dp);
    return dp[i][j] = (ans1+ans2);
}
int Solution::uniquePathsWithObstacles(vector<vector<int>> &v){
    n = size(v); m = size(v[0]);
    if(v[0][0] or v[n-1][m-1]) return 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return rec(v,0,0,dp);
}