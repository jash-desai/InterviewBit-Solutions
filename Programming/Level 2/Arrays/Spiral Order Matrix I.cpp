// Problem Name: Spiral Order Matrix I
// Problem Link: https://www.interviewbit.com/problems/spiral-order-matrix-i/

vector<int> Solution::spiralOrder(const vector<vector<int>>&v) {
    int n = v.size(), m = v[0].size();
    vector<int> ans; int dir=1;
    int l=0, r=m-1; int t=0, b=n-1;
    while(l<=r and t<=b){
        if(dir==1){
            for(int j=l; j<=r; j++) ans.push_back(v[t][j]);
            t++; dir=2;
        }else if(dir==2){
            for(int i=t; i<=b; i++) ans.push_back(v[i][r]);
            r--; dir=3;
        }else if(dir==3){
            for(int j=r; j>=l; j--) ans.push_back(v[b][j]);
            b--; dir=4;
        }else if(dir==4){
            for(int i=b; i>=t; i--) ans.push_back(v[i][l]);
            l++; dir=1;
        }
    }
    return ans;
}

