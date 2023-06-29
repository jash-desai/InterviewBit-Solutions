// Problem Name: Maximum Absolute Difference
// Problem Link: https://www.interviewbit.com/problems/maximum-absolute-difference/

int Solution::maxArr(vector<int> &v){
    int n = v.size(), mx1 = INT_MIN, mx2 = INT_MIN;
    int mn1 = INT_MAX; int mn2 = INT_MAX, ans = 0;
    for(int i=0; i<n; i++){
        mx1 = max(mx1, v[i]+i); mn1 = min(mn1, v[i]+i);
        mx2 = max(mx2, v[i]-i); mn2 = min(mn2, v[i]-i);
    }
    ans = max(mx1-mn1, ans); ans = max(mx2-mn2, ans);
    return ans;
}
