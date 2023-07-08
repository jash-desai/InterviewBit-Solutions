// Problem Name: Painter's Partition Problem
// Problem Link: https://www.interviewbit.com/problems/painters-partition-problem/

int mod = 10000003;
#define ll long long int
bool check(vector<int> &v, ll&m, int&n){
    ll curr = 0, cnt = 1;
    for(int x : v){
        if(curr+x <= m) curr += x;
        else{
            curr = x;
            cnt++;
        }
    }
    return (cnt<=n);
}
int Solution::paint(int n, int k, vector<int> &v){
    long long int l = (*max_element(begin(v), end(v)));
    long long int r = 0; for(int x : v) r += x;
    long long int m, ans = 0;
    while(l<=r){
        m = ((l + ((r-l) >> 1)) % mod);
        if(check(v,m,n)){
            ans = m;
            r = m-1;
        }else l = m+1;
    }
    return (ans*k)%mod;
}
