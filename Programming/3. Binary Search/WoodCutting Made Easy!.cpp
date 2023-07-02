// Problem Name: WoodCutting Made Easy!
// Problem Link: https://www.interviewbit.com/problems/woodcutting-made-easy/

bool fx(vector<int> &v, long long int&m, int &k){
    long long int curr = 0;
    for(int &x : v){
        if(x > m) curr += (x-m);
    }
    return (curr>=k);
}
int Solution::solve(vector<int> &v, int k){
    if(k==0) return *max_element(begin(v), end(v));
    long long int l = 0, m, ans = INT_MIN;
    long long int r = *max_element(begin(v), end(v));
    while(l<=r){
        m = (l + ((r-l) >> 1));
        if(fx(v,m,k)){
            ans = max(ans, m);
            l = m+1;
        }else r = m-1;
    }
    return ans;
}
