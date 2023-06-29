// Problem Name: First Missing Integer
// Problem Link: https://www.interviewbit.com/problems/first-missing-integer/

int Solution::firstMissingPositive(vector<int> &v){
    int n = v.size();
    for(int i=0; i<n; i++){
        if(v[i] == i+1) continue;
        if(v[i]>=1 and v[i]<=n){
            int idx = v[i]-1;
            if(v[idx] != v[i]){
                swap(v[i], v[idx]);
                i--;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(v[i] != i+1) return i+1;
    }
    return n+1;
}
