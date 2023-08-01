// Problem Name: Jump Game Array
// Problem Link: https://www.interviewbit.com/problems/jump-game-array/

int Solution::canJump(vector<int> &v){
    int n = v.size(); int curr = v[0];
    if(curr >= n-1) return 1;
    if(curr == 0) return 0;
    for(int i=1; i<n; i++){
        if(i==n-1) return 1;
        if(v[i]==0 and curr<=i) return 0;
        curr = max(curr, i+v[i]);
        if(curr>=n-1) return 1;
    }
    return 0;
}
