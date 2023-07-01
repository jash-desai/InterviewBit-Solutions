// Problem Name: Segregate 0s and 1s in an array
// Problem Link: https://www.interviewbit.com/problems/segregate-0s-and-1s-in-an-array/

vector<int> Solution::solve(vector<int> &v){
    int n = v.size(), l = 0, r = 0;
    while(r<n){
        if(v[r]==0){
            swap(v[l], v[r]);
            l++, r++;
        }else r++;
    }
    return v;
}
