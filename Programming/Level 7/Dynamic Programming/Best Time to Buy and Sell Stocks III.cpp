// Problem Name: Best Time to Buy and Sell Stocks III
// Problem Link: https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

int n;
int rec(const vector<int>&v, int i, int k, bool f, vector<vector<vector<int>>>&dp){
    if(i==n or k==0) return 0;
    if(dp[i][k][f] != -1) return dp[i][k][f];
    int ans1, ans2;
    if(f){
        ans1 = rec(v,i+1,k,f,dp);
        ans2 = -v[i] + rec(v,i+1,k,1-f,dp);
    }else{
        ans1 = rec(v,i+1,k,f,dp);
        ans2 = v[i] + rec(v,i+1,k-1,1-f,dp);
    }
    return dp[i][k][f] = max(ans1, ans2);
}
int Solution::maxProfit(const vector<int> &v){
    int k = 2; n = size(v);
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
    // return rec(v,0,k,1,dp);
    vector<vector<int>> prev(k+1, vector<int>(2, 0)), curr(k+1, vector<int>(2, 0));
    for(int i{n-1}; i>=0; i--){
        for(int j=1; j<=k; j++){
            for(int f=1; f>=0; f--){
                int ans1, ans2;
                if(f){
                    ans1 = prev[j][f];
                    ans2 = -v[i] + prev[j][1-f];
                }else{
                    ans1 = prev[j][f];
                    ans2 = v[i] + prev[j-1][1-f];
                }
                curr[j][f] = max(ans1, ans2);
            }
        }
        prev = curr;
    }
    return prev[2][1];
}
