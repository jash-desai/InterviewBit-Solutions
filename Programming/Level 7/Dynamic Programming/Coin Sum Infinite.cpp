// Problem Name: Coin Sum Infinite
// Problem Link: https://www.interviewbit.com/problems/coin-sum-infinite/

const int mod = 1000007;
int Solution::coinchange2(vector<int> &v, int k){
    int n = v.size();
    // vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    // dp[0][0] = 1;
    vector<int> prev(k+1, 0), curr(k+1, 0);
    prev[0]=1;
    for(int i=1; i<=n; i++){
        curr[0] = 1;
        for(int j=1; j<=k; j++){
            int ans1 = prev[j], ans2 = 0;
            if(v[i-1] <= j) ans2 = curr[j-v[i-1]];
            curr[j] = (ans1 + ans2)%mod;
        }
        prev = curr;
    }
    return curr[k];
}
