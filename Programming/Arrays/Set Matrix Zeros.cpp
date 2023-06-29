// Problem Name: Set Matrix Zeros
// Problem Link: https://www.interviewbit.com/problems/set-matrix-zeros/

void Solution::setZeroes(vector<vector<int> > &v) {
    int n = v.size(), m = v[0].size();
    bool r = 0, c = 0;
    auto it = find(v[0].begin(), v[0].end(), 0);
    if(it != v[0].end()) r = 1;
    for(int i=0; i<n; i++){
        if(v[i][0]==0){
            c = 1; break;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(v[i][j] == 0){
                v[i][0] = 0;
                v[0][j] = 0;
            }
        }
    }
    for(int i=1; i<n; i++){
        if(v[i][0]==0) v[i] = vector<int>(m, 0);
    }
    for(int j=1; j<m; j++){
        if(v[0][j]==0){
            for(int i=0; i<n; i++) v[i][j] = 0;
        }
    }
    if(r) v[0] = vector<int>(m, 0);
    if(c){
        for(int i=0; i<n; i++) v[i][0] = 0;
    }
    /*
    vector<bool> row(n, 0), col(m, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(row[i]) v[i] = vector<int>(m, 0);
    }
    for(int j=0; j<m; j++){
        if(col[j]){
            for(int i=0; i<n; i++){
                v[i][j] = 0;
            }
        }
    }
    */
    return;
}
