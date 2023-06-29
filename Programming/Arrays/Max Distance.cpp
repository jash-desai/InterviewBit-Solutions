// Problem Name: Max Distance
// Problem Link: https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &v){
    int n = v.size(); vector<pair<int,int>> vp;
    for(int i=0; i<n; i++) vp.push_back({v[i], i});
    sort(vp.begin(), vp.end()); int ans = 0, idx = vp[n-1].second;
    for(int i=n-2; i>=0; i--){
        ans = max(ans, idx - vp[i].second);
        idx = max(idx, vp[i].second);
    }
    return ans;
}
