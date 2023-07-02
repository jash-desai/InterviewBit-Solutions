// Problem Name: Square Root of Integer
// Problem Link: https://www.interviewbit.com/problems/square-root-of-integer/

int Solution::sqrt(int n){
    if(n==0 or n==1) return n;
    long long int l = 1, r = n, m = 1, ans;
    while(l<=r){
        m = ( l + ( (r-l) >> 1 ) );
        long long int sq = (m*m);
        if(sq == n) return m;
        if(sq<n){
            ans = m;
            l = m+1;
        }else if(sq>n){
            r = m-1;
        }
    }
    return ans;
}
