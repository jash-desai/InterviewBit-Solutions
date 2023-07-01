// Problem Name: Make equal elements Array
// Problem Link: https://www.interviewbit.com/problems/make-equal-elements-array/

int Solution::solve(vector<int> &v, int k){
    int n = v.size(); unordered_set<int> s;
    int a = v[0]-k, b = v[0], c = v[0]+k;
    s.insert(a); s.insert(b); s.insert(c);
    for(int i=1; i<n; i++){
        unordered_set<int> t;
        a = v[i]-k, b = v[i], c = v[i]+k;
        if(s.find(a) == s.end()){
            if(s.find(b) == s.end()){
                if(s.find(c) == s.end()) return 0;
            }
        }
        if(s.find(a) != s.end()) t.insert(a);
        if(s.find(b) != s.end()) t.insert(b);
        if(s.find(c) != s.end()) t.insert(c);
        s = t;
        
    }
    return 1;
}
