// Problem Name: Palindrome Partitioning II
// Problem Link: https://www.interviewbit.com/problems/palindrome-partitioning-ii/

bool pal(string&s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j]) return 0;
        else i++, j--;
    }
    return 1;
}
int rec(string&s, int i, vector<int>&dp){
    if(i==s.size() or pal(s,i,s.size()-1)) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    for(int j=i; j<s.size(); j++){
        if(pal(s,i,j)){
            int curr = 1 + rec(s,j+1,dp);
            ans = min(ans, curr);
        }
    }
    return dp[i] = ans;
}
int Solution::minCut(string s){
    int n = s.size(); if(pal(s,0,n-1)) return 0;
    vector<int> dp(n+1, -1); return rec(s,0,dp);
}
