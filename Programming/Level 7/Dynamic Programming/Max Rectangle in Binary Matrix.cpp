// Problem Name: Max Rectangle in Binary Matrix
// Problem Link: https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

int fxn(vector<int>&v){
    int n = v.size(); stack<int> st; int ans = 0;
    for(int i=0; i<=n; i++){
        while(!st.empty() and (i==n or v[st.top()] >= v[i])){
            int h = v[st.top()]; st.pop();
            int w = 0;
            if(st.empty()) w = i;
            else w = i-st.top()-1;
            ans = max(ans, h*w);
        }
        st.push(i);
    }
    return ans;
}
int Solution::maximalRectangle(vector<vector<int>> &mat){
    int n = mat.size(), m = mat[0].size();
    vector<int> v(m); int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==1) v[j]++;
            else v[j] = 0;
        }
        ans = max(ans, fxn(v));
    }
    return ans;
}
