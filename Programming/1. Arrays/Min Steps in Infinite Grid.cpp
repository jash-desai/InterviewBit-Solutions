// Problem Name: Min Steps in Infinite Grid
// Problem Link: https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

int Solution::coverPoints(vector<int> &a, vector<int> &b) {
    int n = a.size(); assert(n==b.size());
    int ans = 0;
    for(int i=1; i<n; i++){
        int xd = abs(a[i]-a[i-1]);
        int yd = abs(b[i]-b[i-1]);
        ans += max(xd, yd);
    }
    return ans;
}
