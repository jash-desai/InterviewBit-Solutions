// Problem Name: Scramble String
// Problem Link: https://www.interviewbit.com/problems/scramble-string/

map<pair<string, string>, bool> mp;
bool rec(string a, string b){
    if(a==b) return 1;
    if(a.size()!=b.size()) return 0;
    if(mp.find({a,b}) != mp.end()) return mp[{a,b}];
    int n = a.size();
    for(int i=1; i<a.size(); i++){
        bool case1 = rec(a.substr(0,i), b.substr(0,i)) and rec(a.substr(i, n-i), b.substr(i, n-i));
        bool case2 = rec(a.substr(0,i), b.substr(n-i, i)) and rec(a.substr(i,n-i), b.substr(0,n-i));
        if(case1 or case2) return mp[{a,b}] = 1;
    }
    return mp[{a,b}] = 0;
}
int Solution::isScramble(const string a, const string b) {
    if(a==b) return 1;
    if(a.size()!=b.size()) return 0;
    mp.clear(); return rec(a,b);
}
