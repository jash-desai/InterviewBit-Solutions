// Problem Name: Largest Number
// Problem Link: https://www.interviewbit.com/problems/largest-number/

string Solution::largestNumber(const vector<int> &v){
    string ans; int n = size(v); vector<string> vs;
    for(int x : v) vs.push_back(to_string(x));
    sort(begin(vs), end(vs), [](auto&a, auto&b){
        return (a+b > b+a);
    });
    for(string s : vs) ans += s;
    int idx = 0;
    while(ans[idx]=='0') idx++;
    ans = ans.substr(idx);
    return (ans.empty()) ? "0" : ans;
}
