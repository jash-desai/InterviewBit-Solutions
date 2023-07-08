// Problem Name: Spiral Order Matrix II
// Problem Link: https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int>> Solution::generateMatrix(int n){
    vector<vector<int>> v(n, vector<int>(n));
    int c=1, t=0, b=n-1, l=0, r=n-1, dir=1;
    while(t<=b and l<=r){
        if(dir==1){
            for(int j=l; j<=r; j++) v[t][j] = c++;
            dir=2; t++;
        }else if(dir==2){
            for(int i=t; i<=b; i++) v[i][r] = c++;
            dir=3; r--;
        }else if(dir==3){
            for(int j=r; j>=l; j--) v[b][j] = c++;
            dir=4; b--;
        }else if(dir==4){
            for(int i=b; i>=t; i--) v[i][l] = c++;
            dir=1; l++;
        }
    }
    assert(--c==(n*n));
    return v;
}
