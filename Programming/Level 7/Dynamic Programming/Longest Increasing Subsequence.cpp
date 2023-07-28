// Problem Name: Longest Increasing Subsequence
// Problem Link: https://www.interviewbit.com/problems/longest-increasing-subsequence/

int Solution::lis(const vector<int> &v){
    int n = size(v); vector<int> dp(n, 1); int ans = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[j] < v[i]) dp[i] = max(dp[i], 1 + dp[j]);
            ans = max(ans, dp[i]);
        }
    }
    return ans;
}
