// Problem Name: Maximum Sum Square SubMatrix
// Problem Link: https://www.interviewbit.com/problems/maximum-sum-square-submatrix/

int Solution::solve(vector<vector<int>>&v, int k) {
    int n = v.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 and j==0) continue;
            if(i==0) v[i][j] += v[i][j-1];
            else if(j==0) v[i][j] += v[i-1][j];
            // x + top + side - diag (summed twice)
            else v[i][j] = v[i][j] + v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        }
    }
    int ans = v[k-1][k-1];
    for(int i=k-1; i<n; i++){
        for(int j=k-1; j<n; j++){
            int top = 0, side = 0, diag = 0;
            if(i-k >= 0) top = v[i-k][j];
            if(j-k >= 0) side = v[i][j-k];
            if(i-k >=0 and j-k >= 0) diag = v[i-k][j-k];
            ans = max(ans, v[i][j] - top - side + diag);
        }
    }
    return ans;
}
