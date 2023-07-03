// Problem Name: Max Sum Contiguous Subarray
// Problem Link: https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &v) {
    int n = v.size(), curr = v[0], ans = v[0];
    for(int i=1; i<n; i++){
        curr = max(v[i], curr+v[i]);
        ans = max(ans, curr);
    }
    return ans;
}
