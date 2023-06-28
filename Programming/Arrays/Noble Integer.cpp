// Problem Name: Noble Integer
// Problem Link: https://www.interviewbit.com/problems/noble-integer/

int Solution::solve(vector<int> &v) {
    int n = v.size(); sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        auto it = upper_bound(v.begin(), v.end(), v[i]);
        if(n - (it-v.begin()) == v[i]) return 1;
    }
    return -1;
}
