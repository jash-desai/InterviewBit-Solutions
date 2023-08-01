// Problem Name: Longest valid Parentheses
// Problem Link: https://www.interviewbit.com/problems/longest-valid-parentheses/

int Solution::longestValidParentheses(string s){
    int n = size(s), op = 0, cl = 0, ans = 0;
    int i = 0;
    while(i<n){
        if(s[i]=='(') op++;
        else cl++;
        if(op==cl) ans = max(ans, op+cl);
        if(cl>op) op=0, cl=0;
        i++;
    }
    i = n-1; op=0; cl=0;
    while(i>=0){
        if(s[i]=='(') op++;
        else cl++;
        if(op==cl) ans = max(ans, op+cl);
        if(op>cl) op=0, cl=0;
        i--;
    }
    return ans;
}
