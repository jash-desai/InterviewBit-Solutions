// Problem Name: Edit Distance
// Problem Link: https://www.interviewbit.com/problems/edit-distance/

int rec(string&a, string&b, int n, int m, vector<vector<int>>&dp){
    if(n==0) return m;
    if(m==0) return n;
    if(dp[n][m] != -1) return dp[n][m];
    if(a[n-1]==b[m-1]) return dp[n][m] = rec(a,b,n-1,m-1,dp);
    int ans1 = rec(a,b,n-1,m,dp), ans2 = rec(a,b,n,m-1,dp), ans3 = rec(a,b,n-1,m-1,dp);
    return dp[n][m] = 1 + min({ans1, ans2, ans3});
}
int Solution::minDistance(string a, string b){
    int n = size(a), m = size(b);
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return rec(a,b,n,m,dp);
}
