// Problem Name: Balance Array
// Problem Link: https://www.interviewbit.com/problems/balance-array/

int Solution::solve(vector<int> &v){
    if(size(v)==1 or size(v)==2) return (size(v)%2);
    int n{size(v)}; vector<int> ps(n), ss(n);
    ps[0]=v[0], ps[1]=v[1]; ss[n-1]=v[n-1], ss[n-2]=v[n-2];
    for(int i=2; i<n; i++){
        ps[i] = v[i] + ps[i-2];
    }
    for(int i=n-3; i>=0; i--){
        ss[i] = v[i] + ss[i+2];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        int ls = 0, rs = 0;
        if(i-2>=0) ls += ps[i-2];
        if(i+1<n) ls += ss[i+1];
        if(i-1>=0) rs += ps[i-1];
        if(i+2<n) rs += ss[i+2];
        if(ls==rs) ans++;
    }
    return ans;
}
