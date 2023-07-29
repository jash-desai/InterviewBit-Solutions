// Problem Name: Best Time to Buy and Sell Stocks I
// Problem Link: https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/

int Solution::maxProfit(const vector<int> &v){
    if(v.empty()) return 0;
    int n = size(v); int mn = v[0], ans{0};
    for(int i=1; i<n; i++){
        ans = max(ans, v[i] - mn);
        mn = min(mn, v[i]);
    }
    return ans;
}
