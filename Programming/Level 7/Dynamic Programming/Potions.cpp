// Problem Name: Potions
// Problem Link: https://www.interviewbit.com/problems/potions/

int sum(vector<int>&v, int i, int j){
    int s = 0; 
    for(int k=i; k<=j; k++) s = (s+v[k])%100;
    return s%100;
}
int rec(vector<int>&v, int i, int j, vector<vector<int>> &dp){
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k=i+1; k<=j; k++){
        int lf = rec(v,i,k-1,dp), rt = rec(v,k,j,dp);
        int curr = (sum(v,i,k-1)*sum(v,k,j)) + lf + rt;
        ans = min(ans, curr);
    }
    return dp[i][j] = ans;
}
int Solution::minSmoke(vector<int> &v){
    int n = v.size(); vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return rec(v,0,n-1,dp);
}
