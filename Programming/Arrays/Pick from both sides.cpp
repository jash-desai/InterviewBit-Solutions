// Problem Name: Pick from both sides!
// Problem Link: https://www.interviewbit.com/problems/pick-from-both-sides/

int Solution::solve(vector<int> &v, int k){
    int n = v.size(), curr = 0, ans = INT_MIN;
    for(int i=0; i<k; i++) curr += v[i];
    int l = k-1, r = n-1;
    for(int i=0; i<k; i++){
        ans = max(ans, curr);
        curr -= v[l--];
        curr += v[r--];
    }
    ans = max(ans, curr);
    return ans;
}
