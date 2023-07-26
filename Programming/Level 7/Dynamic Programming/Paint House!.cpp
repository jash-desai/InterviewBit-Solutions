// Problem Name: Paint House!
// Problem Link: https://www.interviewbit.com/problems/paint-house/

int n;
int rec(vector<vector<int>>&v, int i, int j, vector<vector<int>>&dp){
    if(i>=n or j<0 or j>=4 ) return 1e9;
    if(i==n-1){
        int mn = 1e9;
        for(int k=0; k<3; k++){
            if(k==j-1) continue;
            mn = min(mn, v[i][k]);
        }
        return mn;
    }
    if(dp[i][j] != 1e9) return dp[i][j];
    if(j==0){
        int ans1 = v[0][0] + rec(v,i+1,1,dp);
        int ans2 = v[0][1] + rec(v,i+1,2,dp);
        int ans3 = v[0][2] + rec(v,i+1,3,dp);
        return dp[i][j] = min({ans1, ans2, ans3});
    }else if(j==1){
        int ans1 = v[i][1] + rec(v,i+1,2,dp);
        int ans2 = v[i][2] + rec(v,i+1,3,dp);
        return dp[i][j] = min(ans1, ans2);
    }else if(j==2){
        int ans1 = v[i][0] + rec(v,i+1,1,dp);
        int ans2 = v[i][2] + rec(v,i+1,3,dp);
        return dp[i][j] = min(ans1, ans2);
    }else if(j==3){
        int ans1 = v[i][0] + rec(v,i+1,1,dp);
        int ans2 = v[i][1] + rec(v,i+1,2,dp);
        return dp[i][j] = min(ans1, ans2);
    }
}
int Solution::solve(vector<vector<int>> &v) {
    n = size(v); vector<vector<int>> dp(n+1, vector<int>(4, 1e9));
    return rec(v,0,0,dp);
}