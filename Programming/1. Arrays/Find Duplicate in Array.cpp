// Problem Name: Find Duplicate in Array
// Problem Link: https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &v){
    int n{size(v)}; vector<int> occ(n+1, 0);
    for(int x : v){
        occ[x-1]++;
        if(occ[x-1]==2) return x;
    }
    return -1;
}
