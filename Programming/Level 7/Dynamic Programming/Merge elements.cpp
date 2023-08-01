// Problem Name: Merge elements
// Problem Link: https://www.interviewbit.com/problems/merge-elements/

int sum(vector<int>&v, int i, int j){
    int ans = 0;
    for(int k=i; k<=j; k++) ans += v[k];
    return ans;
}
int rec(vector<int>&v, int i, int j, vector<vector<int>>&dp){
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k=i+1; k<=j; k++){
        int curr = (sum(v,i,k-1) + sum(v,k,j));
        curr += rec(v,i,k-1,dp) + rec(v,k,j,dp);
        ans = min(ans, curr);
    }
    return dp[i][j] = ans;
}
int Solution::solve(vector<int> &v){
    int n = v.size(); vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return rec(v,0,n-1,dp);
}
