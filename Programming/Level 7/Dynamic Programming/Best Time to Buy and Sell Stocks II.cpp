// Problem Name: Best Time to Buy and Sell Stocks II
// Problem Link: https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/

int n;
int rec(const vector<int>&v, int i, bool f, vector<vector<int>>&dp){
    if(i==n) return 0;
    if(dp[i][f] != -1) return dp[i][f];
    int ans1, ans2;
    if(f){
        ans1 = rec(v,i+1,f,dp);
        ans2 = -v[i] + rec(v,i+1, 1-f, dp);
    }else{
        ans1 = rec(v,i+1,f,dp);
        ans2 = v[i] + rec(v,i+1,1-f,dp);
    }
    return dp[i][f] = max(ans1, ans2);
}
int Solution::maxProfit(const vector<int> &v){
    n = size(v); vector<vector<int>> dp(n+1, vector<int>(2, -1));
    return rec(v,0,1,dp);
}
