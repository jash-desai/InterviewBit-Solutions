// Problem Name: Maximum Size Square Sub-matrix
// Problem Link: https://www.interviewbit.com/problems/maximum-size-square-sub-matrix/

int Solution::solve(vector<vector<int>> &v){
    int n = v.size(), m = v[0].size(), ans = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 or j==0) dp[i][j] = v[i][j];
            else{
                if(v[i][j] == 1) dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return (ans*ans);
}
