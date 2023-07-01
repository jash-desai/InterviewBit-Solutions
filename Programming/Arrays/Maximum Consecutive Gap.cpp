// Problem Name: Maximum Consecutive Gap
// Problem Link: https://www.interviewbit.com/problems/maximum-consecutive-gap/

#define all(v) begin(v),end(v)
int Solution::maximumGap(const vector<int> &v){
    if(size(v)<2) return 0;
    int n = size(v), mn = *min_element(all(v));
    int mx = *max_element(all(v));
    float avgi = (float)(mx-mn)/(float)(n-1);
    vector<int> mnb(n-1, INT_MAX), mxb(n-1, INT_MIN);
    for(int i=0; i<n; i++){
        if(v[i]==mn or v[i]==mx) continue;
        int idx = (v[i]-mn)/avgi;
        mnb[idx] = min(mnb[idx], v[i]);
        mxb[idx] = max(mxb[idx], v[i]);
    }
    int prev = mn, ans = INT_MIN;
    for(int i=0; i<n-1; i++){
        if(mnb[i]==INT_MAX) continue;
        ans = max(ans, mnb[i]-prev);
        prev = mxb[i];
    }
    ans = max(ans, mx-prev);
    return ans;
}
