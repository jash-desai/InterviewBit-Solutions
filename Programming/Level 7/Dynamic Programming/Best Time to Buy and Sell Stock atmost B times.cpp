// Problem Name: Best Time to Buy and Sell Stock atmost B times
// Problem Link: https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stock-atmost-b-times/

int Solution::solve(vector<int> &v, int k){
    int n = size(v); k = min((n/2)+1, k);
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
    return prev[k][1];
}
