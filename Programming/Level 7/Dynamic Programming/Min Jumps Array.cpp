// Problem Name: Min Jumps Array
// Problem Link: https://www.interviewbit.com/problems/min-jumps-array/

int Solution::jump(vector<int> &v){
    if(v.size()<2) return 0;
    int n = v.size(), ans=0, curr=0, lim=0;
    for(int i=0; i<n-1; i++){
        curr = max(curr, i+v[i]);
        if(i==lim){
            if(i!=n-1 and curr<=i) return -1;
            lim = curr, ans++;
            if(lim==n-1) return ans;
        }
    }
    return ans;
}
