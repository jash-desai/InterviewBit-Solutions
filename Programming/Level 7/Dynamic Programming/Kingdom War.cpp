// Problem Name: Kingdom War
// Problem Link: https://www.interviewbit.com/problems/kingdom-war/

int Solution::solve(vector<vector<int>> &v){
    int n = v.size(), m = v[0].size(), ans = INT_MIN;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            dp[i][j] = v[i][j];
            if(i+1<n) dp[i][j] += dp[i+1][j];
            if(j+1<m) dp[i][j] += dp[i][j+1];
            if(i+1<n and j+1<m) dp[i][j] -= dp[i+1][j+1];
            ans = max(ans, dp[i][j]);
        }
    } return ans;
}
