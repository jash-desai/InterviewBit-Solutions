// Problem Name: Coins in a Line
// Problem Link: https://www.interviewbit.com/problems/coins-in-a-line/

int rec(vector<int>&v, int i, int j, vector<vector<int>>&dp){
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans1 = v[i] + min(rec(v,i+2,j,dp), rec(v,i+1,j-1,dp));
    int ans2 = v[j] + min(rec(v,i+1,j-1,dp), rec(v,i,j-2,dp));
    return dp[i][j] = max(ans1, ans2);
}
int Solution::maxcoin(vector<int> &v){
    int n = size(v);
    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // return rec(v,0,n-1,dp);
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            int ans1 = v[i] + min(dp[i+2][j], dp[i+1][j-1]);
            int ans2 = v[j] + min(dp[i+1][j-1], dp[i][j-2]);
            dp[i][j] = max(ans1, ans2);
        }
    }
    return dp[0][n-1];
}
