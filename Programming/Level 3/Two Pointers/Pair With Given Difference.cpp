// Problem Name: Pair With Given Difference
// Problem Link: https://www.interviewbit.com/problems/pair-with-given-difference/

int Solution::solve(vector<int> &v, int k){
    int n = v.size(); sort(begin(v), end(v));
    int i=0, j=1;
    while(i<n and j<n){
        if(i!=j and v[j]-v[i]==k) return 1;
        else if(v[j]-v[i] < k) j++;
        else i++;
    }
    return 0;
}
