// Problem Name: Evaluate Expression To True
// Problem Link: https://www.interviewbit.com/problems/evaluate-expression-to-true/

const int mod = 1e3+3;
#define vvvi vector<vector<vector<int>>>
int rec(string&s, int i, int j, bool f, vvvi&dp){
    if(i>j) return 0;
    if(i==j){
        if(f) return (s[i]=='T');
        else return (s[i]=='F');
    }
    if(dp[i][j][f] != -1) return dp[i][j][f];
    long long int ans = 0;
    for(int k=i+1; k<j; k+=2){
        long long int lt = rec(s, i, k-1, 1, dp), lf = rec(s, i, k-1, 0, dp);
        long long int rt = rec(s, k+1, j, 1, dp), rf = rec(s, k+1, j, 0, dp);
        switch(s[k]){
            case '|' : {
                if(f){
                    ans = (ans + (lt*rt))%mod;
                    ans = (ans + (lf*rt))%mod;
                    ans = (ans + (lt*rf))%mod;
                    break;
                }else{
                  ans = (ans + (lf*rf))%mod;
                  break;  
                } 
            }
            case '&' : {
                if(!f){
                    ans = (ans + (lt*rf))%mod;
                    ans = (ans + (lf*rt))%mod;
                    ans = (ans + (lf*rf))%mod;
                    break;
                }else{
                    ans = (ans + (lt*rt))%mod;
                    break;  
                } 
            }
            case '^' : {
                if(f){
                    ans = (ans + (lt*rf))%mod;
                    ans = (ans + (lf*rt))%mod;
                    break;
                }else{
                    ans = (ans + (lf*rf))%mod;
                    ans = (ans + (lt*rt))%mod;
                    break;
                }
            }
        }
    }
    return dp[i][j][f] = ans;
}
int Solution::cnttrue(string s){
    int n = size(s);
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
    return rec(s,0,n-1,1,dp)%mod;
}
