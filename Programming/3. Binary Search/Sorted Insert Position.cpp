// Problem Name: Sorted Insert Position
// Problem Link: https://www.interviewbit.com/problems/sorted-insert-position/

int Solution::searchInsert(vector<int> &v, int k){
    int l = 0, r = size(v) - 1, m, ans = -1;
    while(l<=r){
        m = (l + ((r-l) >> 1));
        if(v[m]==k) return m;
        if(v[m]<k){
            ans = m;
            l = m+1;
        }else r = m-1;
    }
    return ans+1;
}
