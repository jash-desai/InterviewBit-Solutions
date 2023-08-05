// Problem Name: Queen Attack
// Problem Link: https://www.interviewbit.com/problems/queen-attack/

const vector<pair<int,int>> dirs = { {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1} };
int n, m; bool check(int x, int y){ return (x>=0 and x<n and y>=0 and y<m); }
int rec(vector<string>&v, int i, int j, int k, vector<vector<vector<int>>>&dp){
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int ni = i + dirs[k].first, nj = j + dirs[k].second;
    dp[i][j][k] = 0;
    if(check(ni,nj)){
        if(v[ni][nj] == '1') dp[i][j][k]++;
        else dp[i][j][k] = rec(v,ni,nj,k,dp);
    }
    return dp[i][j][k];
}
vector<vector<int>> Solution::queenAttack(vector<string> &v){
    n = v.size(); m = v[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(8, -1)));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<8; k++) ans[i][j] += rec(v,i,j,k,dp);
        }
    }
    return ans;
}
