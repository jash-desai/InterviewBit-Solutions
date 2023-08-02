// Problem Name: Minimum Difference Subsets!
// Problem Link: https://www.interviewbit.com/problems/minimum-difference-subsets/

#include<bits/stdc++.h>
vector<int> fx(vector<int> &v, int k){
    int n = size(v); vector<int> prev(k+1, 0)
    vector<int> curr(k+1, 0); prev[0] = curr[0] = 1; curr[v[0]] = 1;
    for(int i=1; i<=n; i++){
        curr[0] = 1;
        for(int j=1; j<=k; j++){
            int ans1 = prev[j], ans2 = 0;
            if(j>=v[i-1]) ans2 = prev[j-v[i-1]];
           curr[j] = (ans1 or ans2);
        }
        prev = curr;
    }
    return prev;
}
int Solution::solve(vector<int> &v){
    if(v.size() == 2) return abs(v[0]-v[1]);
    int n = size(v), s = accumulate(begin(v), end(v), 0);
    vector<int> check = fx(v, s); int diff = INT_MAX;
    for(int i=0; i<=s; i++){
        if(check[i]==1){
            diff = min(diff, abs((2*i)-s));
        }
    }
    return diff;
}