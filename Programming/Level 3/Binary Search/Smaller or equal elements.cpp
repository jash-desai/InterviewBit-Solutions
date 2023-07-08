// Problem Name: Smaller or equal elements
// Problem Link: https://www.interviewbit.com/problems/smaller-or-equal-elements/

int Solution::solve(vector<int> &v, int k){
    int l = 0, r = size(v) -1, m, ans = -1;
    while(l<=r){
        m = (l + ((r-l) >> 1));
        if(v[m]==k and v[m+1]!=k){
            ans = m;
            break;
        }else if(v[m]==k and v[m+1]==k){
            l = m+1;
        }else if(v[m] < k){
            ans = max(ans, m);
            l = m+1;
        }else if(v[m] > k){
            r = m-1;
        }
    }
    return (ans+1);
}
