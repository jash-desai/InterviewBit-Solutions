// Problem Name: Rotated Sorted Array Search
// Problem Link: https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &v, int k){
    int l = 0, r = size(v)-1, m;
    while(l<=r){
        m = ((l+r) >> 1);
        if(v[m]==k) return m;
        if(v[l]<=v[m]){
            if(v[l] <= k and k < v[m]) r = m-1;
            else l = m+1;
        }else if(v[m] <= v[r]){
            if(v[m] < k and k <= v[r]) l = m+1;
            else r = m-1;
        }
    }
    return -1;
}
