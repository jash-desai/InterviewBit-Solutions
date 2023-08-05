// Problem Name: Unique Binary Search Trees II
// Problem Link: https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

int n;
int rec(int i, int j, vector<vector<int>> &dp){
    if(i>=j) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 0;
    for(int k=i; k<=j; k++){
        int lt = rec(i, k-1, dp), rt = rec(k+1, j, dp);
        ans += (lt*rt);
    }
    return dp[i][j] = ans;
}
int Solution::numTrees(int N){
    n = N; if(n==1 or n==2) return n;
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return rec(1,n,dp);
}