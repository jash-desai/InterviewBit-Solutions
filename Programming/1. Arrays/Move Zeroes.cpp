// Problem Name: Move Zeroes
// Problem Link: https://www.interviewbit.com/problems/move-zeroes/

vector<int> Solution::solve(vector<int> &v){
    int n = v.size(), cnt = 0, idx = 0;
    for(int i=0; i<n; i++){
        if(v[i]==0) cnt++;
        else v[idx++] = v[i];
    }
    for(int i=n-cnt; i<n; i++) v[i]=0;
    return v;
}
