// Problem Name: Longest Palindromic Subsequence
// Problem Link: https://www.interviewbit.com/problems/longest-palindromic-subsequence/

int rec(string&a, string&b, int n, int m, vector<vector<int>>&dp){
    if(n==0 or m==0) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    if(a[n-1]==b[m-1]) return dp[n][m] = 1 + rec(a,b,n-1,m-1,dp);
    int ans1 = rec(a,b,n-1,m,dp);
    int ans2 = rec(a,b,n,m-1,dp);
    return dp[n][m] = max(ans1,ans2);
}
int Solution::solve(string a){
    int n = size(a); string b = string(rbegin(a), rend(a));
     vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return rec(a,b,n,n,dp);
}