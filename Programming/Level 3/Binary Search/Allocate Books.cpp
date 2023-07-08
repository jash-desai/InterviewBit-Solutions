// Problem Name: Allocate Books
// Problem Link: https://www.interviewbit.com/problems/allocate-books/

bool fx(vector<int> &v, int&m, int&k){
    int curr = 0, cnt = 1;
    for(int &x : v){
        if(curr + x <= m){
            curr += x;
        }else{
            curr = x;
            cnt++;
        }
    }
    return (cnt<=k);
}
int Solution::books(vector<int> &v, int k){
    if(size(v) < k) return -1;
    int l = *max_element(begin(v), end(v));
    int r = 0; for(int &x : v) r += x;
    int ans, m;
    while(l<=r){
        m = (l + ( (r-l) >> 1) );
        if(fx(v,m,k)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return ans;
}
