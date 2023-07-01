// Problem Name: Rotate Matrix
// Problem Link: https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate(vector<vector<int> > &v) {
    int n = size(v);
    if(n==1) return;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++) swap(v[i][j],v[j][i]);
    }
    for(int i=0; i<n; i++){
        reverse(begin(v[i]), end(v[i]));
    }
}
