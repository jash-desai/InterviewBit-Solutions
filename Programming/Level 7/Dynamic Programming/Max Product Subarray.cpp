// Problem Name: Max Product Subarray
// Problem Link: https://www.interviewbit.com/problems/max-product-subarray/

int Solution::maxProduct(const vector<int> &v) {
    int n = size(v), pre = 1, suff = 1; int ans = INT_MIN;
    for(int i=0; i<n; i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        pre = pre*v[i];
        suff = suff*v[n-i-1];
        ans = max({ans, pre, suff});
    }
    return ans;
}
