// Problem Name: Capacity To Ship Packages Within B Days
// Problem Link: https://www.interviewbit.com/problems/capacity-to-ship-packages-within-b-days/

bool fx(vector<int>&v, int&m, int&k){
    int curr = 0, cnt = 1;
    for(int &x : v){
        if(curr+x <= m) curr += x;
        else{curr = x; cnt++;}
    }
    return (cnt<=k);
}
int Solution::solve(vector<int> &v, int k){
    int l = *max_element(begin(v), end(v));
    int r = 0; for(int &x : v) r += x;
    int m, ans;
    while(l<=r){
        m = (l + ((r-l) >> 1 ));
        if(fx(v,m,k)){
            ans = m;
            r = m-1;
        }else l = m+1;
    }
    return ans;
}
