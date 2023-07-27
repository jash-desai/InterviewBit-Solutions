// Problem Name: Min Sum Path in Matrix
// Problem Link: https://www.interviewbit.com/problems/min-sum-path-in-matrix/

int n,m;
int rec(vector<vector<int>> &v, int i, int j, vector<vector<int>> &dp){
    if(i>=n or j>=m) return 1e9;
    if(i==n-1 and j==m-1) return v[i][j];
    if(dp[i][j] != 1e9) return dp[i][j];
    int ans1 = rec(v,i+1,j,dp), ans2 = rec(v,i,j+1,dp);
    // if(ans1==1e9 and ans2==1e9) return dp[i][j] = 1e9-1;
    return dp[i][j] = v[i][j] + min(ans1, ans2);
}
int Solution::minPathSum(vector<vector<int>> &v){
    n = size(v), m = size(v[0]);
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
    return rec(v,0,0,dp);
}
