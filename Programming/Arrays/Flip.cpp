// Problem Name: Flip
// Problem Link: https://www.interviewbit.com/problems/flip/

vector<int> Solution::flip(string s){
    vector<int> ans; vector<int> v(size(s));
    int n = size(v); int tl = 0, tr = 0;
    for(int i=0; i<size(s); i++){
        if(s[i]=='0') v[i]=1;
        if(s[i]=='1') v[i]=-1;
    }
    int l = 0, r = 0; int t = v[0], c = v[0];
    for(int i=1; i<n; i++){
        if(v[i] > t+v[i]){
            tl = i;
            t = v[i];
        }else t += v[i];
        if(t > c){
            c = t;
            l = tl;
            r = i;
        }
    }
    if(c<0) return {};
    return {l+1, r+1};
}
