// Problem Name: Wave Array
// Problem Link: https://www.interviewbit.com/problems/wave-array/

vector<int> Solution::wave(vector<int> &v) {
    int n = v.size(), i = 0; sort(v.begin(), v.end());
    while(i<n-1){
        swap(v[i], v[i+1]);
        i += 2;
    }
    return v;
}
