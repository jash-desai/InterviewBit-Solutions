// Problem Name: Distinct Subsequences
// Problem Link: https://www.interviewbit.com/problems/distinct-subsequences/

int Solution::numDistinct(string a, string b){
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); dp[0][0] = 1;
    vector<int> prev(m+1, 0), curr(m+1, 0);
    prev[0] = 1; curr[0] = 1;
    for(int i=1; i<=n; i++){
        curr[0] = 1;
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1]) curr[j] = prev[j] + prev[j-1];
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    return prev[m];
}
