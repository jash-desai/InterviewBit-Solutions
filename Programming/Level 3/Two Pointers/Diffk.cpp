// Problem Name: Diffk
// Problem Link: https://www.interviewbit.com/problems/diffk/

int Solution::diffPossible(vector<int> &v, int k){
    int n = v.size(), i{0}, j{1};
    while(i<n and j<n){
        if(i!=j and v[j]-v[i]==k) return 1;
        if(v[j]-v[i] < k) j++;
        else i++;
    }
    return 0;
}
