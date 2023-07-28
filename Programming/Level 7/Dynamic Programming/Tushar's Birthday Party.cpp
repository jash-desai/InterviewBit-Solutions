// Problem Name: Tushar's Birthday Party
// Problem Link: https://www.interviewbit.com/problems/tushars-birthday-party/

int rec(const vector<int> &b, const vector<int> &c, int n, int k, vector<vector<int>> &dp){
    if(n==0 or k<0) return INT_MAX;
    if(k==0) return 0;
    if(n==1 and b[n-1]>k) return dp[n][k] = INT_MAX;
    if(dp[n][k] != -1) return dp[n][k];
    if(b[n-1]>k) return dp[n][k] = rec(b,c,n-1,k,dp);
    int ans1 = rec(b,c,n-1,k,dp);
    int ans2 = rec(b,c,n,k-b[n-1],dp);
    if(ans1==INT_MAX and ans2==INT_MAX) return dp[n][k] = INT_MAX;
    if(ans2 != INT_MAX) ans2 +=  c[n-1];
    return dp[n][k] = min(ans1, ans2);
}
int Solution::solve(const vector<int> &a, const vector<int> &b, const vector<int> &c){
    int n = size(a); int m = size(b);  int ans = 0;
    vector<vector<int>> dp(m+1, vector<int>(1e3+1, -1));
    for(int i=0; i<n; i++){
        int temp = rec(b,c,m,a[i],dp);
        ans += temp;
    }
    return ans;
}
