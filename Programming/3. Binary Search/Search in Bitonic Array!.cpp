// Problem Name: Search in Bitonic Array!
// Problem Link: https://www.interviewbit.com/problems/search-in-bitonic-array/

int Solution::solve(vector<int> &v, int k){
    int l = 0, r = size(v)-1, m;
    while(l<=r){
        m = ((l+r) >> 1);
        if(v[m]==k) return m;
        if(v[l]<=v[m]){
            if(v[l] <= k and k < v[m]) r = m-1;
            else l = m+1;
        }else if(v[m]>=v[r]){
            if(v[r] <= k and k < v[m]) l = m+1;
            else r = m-1;
        }
    }
    return -1;
}
