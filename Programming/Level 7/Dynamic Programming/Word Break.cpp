// Problem Name: Word Break
// Problem Link: https://www.interviewbit.com/problems/word-break/

int Solution::wordBreak(string s, vector<string> &v){
    unordered_set<string> st(v.begin(), v.end());
    if(st.count(s)) return 1;
    int n = s.size();  vector<int> dp(n+1, 0); dp[0] = 1;
    int mx = INT_MIN; for(string &x : v) mx = max(mx, (int)x.size());
    for(int i=1; i<=n; i++){
        for(int j=i-1; j>=max(i-mx-1, 0); j--){
            string t = s.substr(j, i-j);
            if(dp[j] and st.count(t)){ dp[i] = 1; break; }
        }
    } return dp[n];
}
