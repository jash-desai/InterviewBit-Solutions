// Problem Name: Matrix Search
// Problem Link: https://www.interviewbit.com/problems/matrix-search/

int Solution::searchMatrix(vector<vector<int>> &v, int k){
    int n = size(v), m = size(v[0]);
    int row = 0, col = m-1, ele = 0;
    while(row<n and col<m){
        ele = v[row][col];
        if(ele == k) return 1;
        if(ele < k) row++;
        else col--;
    }
    return 0;
}
