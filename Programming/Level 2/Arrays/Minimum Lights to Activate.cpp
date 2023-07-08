// Problem Name: Minimum Lights to Activate
// Problem Link: https://www.interviewbit.com/problems/minimum-lights-to-activate/

int Solution::solve(vector<int> &v, int k) {
    int n = v.size(); int ans = 0; int i = 0;
    while(i<n){
        int j = min(i+k-1, n-1);
        bool f = 0;
        while(j>=i-k+1 and j>=0){
            if(v[j]==1){
                f=1; ans++;
                i = j+k; break;
            }
            j--;
        }
        if(!f) return -1;
    }
    return ans;
}
