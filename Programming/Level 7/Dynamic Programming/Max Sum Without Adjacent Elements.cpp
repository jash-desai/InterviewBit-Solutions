// Problem Name: Max Sum Without Adjacent Elements
// Problem Link: https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

int rec(vector<int>&v, int n, vector<int>&dp){
    if(n<=0) return 0;
    if(n==1) return v[n-1];
    if(dp[n] != -1) return dp[n];
    int ans1 = rec(v,n-1,dp);
    int ans2 = v[n-1] + rec(v,n-2,dp);
    return dp[n] = max(ans1, ans2);
}
int Solution::adjacent(vector<vector<int>> &arr){
    int n = size(arr[0]); vector<int> v(n);
    for(int i=0; i<n; i++){
        v[i] = max(arr[0][i], arr[1][i]);
    }
    vector<int> dp(n+1, -1);
    return rec(v,n,dp);
}
