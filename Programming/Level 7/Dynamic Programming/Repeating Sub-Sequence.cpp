// Problem Name: Repeating Sub-Sequence
// Problem Link: https://www.interviewbit.com/problems/repeating-subsequence/

int Solution::anytwo(string s){
    int n = s.size(); vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1]==s[j-1] and i!=j) dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return (dp[n][n]>=2);
}
