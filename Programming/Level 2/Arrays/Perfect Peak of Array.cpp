// Problem Name: Perfect Peak of Array
// Problem Link: https://www.interviewbit.com/problems/perfect-peak-of-array/

int Solution::perfectPeak(vector<int> &v){
    int n = size(v); vector<int> mn(n, INT_MAX);
    vector<int> mx(n, INT_MIN); mx[0] = v[0]; mn[n-1] = v[n-1];
    for(int i=1; i<n; i++) mx[i] = max(mx[i-1], v[i]);
    for(int i=n-2; i>=0; i--) mn[i] = min(mn[i+1], v[i]);
    for(int i=1; i<n-1; i++){
        if(v[i] > mx[i-1] and v[i] < mn[i+1]) return 1;
    }
    return 0;
}
