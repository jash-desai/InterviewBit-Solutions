// Problem Name: Maximum Sum Triplet
// Problem Link: https://www.interviewbit.com/problems/maximum-sum-triplet/

int Solution::solve(vector<int> &v) {
    int n = v.size(); set<int> s; s.insert(v[0]);
    vector<int> mx(n, v[n-1]); int ans = INT_MIN; 
    for(int i=n-2; i>=0; i--) mx[i] = max(mx[i+1], v[i]);
    for(int i=1; i<n; i++){
        s.insert(v[i]);
        auto it = s.find(v[i]);
        if(it != s.begin() and v[i] != mx[i]){
            it--;
            int temp = *it + v[i] + mx[i];
            ans = max(ans, temp);
        }
    }
    return ans;
}
