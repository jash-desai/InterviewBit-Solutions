// Problem Name: Implement Power Function
// Problem Link: https://www.interviewbit.com/problems/implement-power-function/

#define ll long long int
int Solution::pow(int base, int exp, int mod) {
    if(mod == 1) return 0;
    ll ans = 1, curr = (base % mod);
    while(exp > 0){
        if(exp & 1) ans = (ans*curr) % mod;
        curr = (curr*curr)%mod;
        if(curr < 0) curr += mod;
        exp = (exp >> 1);
    }
    if(ans < 0){
        ans += mod;
        return ans;
    }
    return ans % mod;
}
