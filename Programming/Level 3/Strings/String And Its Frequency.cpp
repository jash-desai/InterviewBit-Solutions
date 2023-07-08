// Problem Name: String And Its Frequency
// Problem Link: https://www.interviewbit.com/problems/string-and-its-frequency/

string Solution::solve(string s){
    vector<int> v(26, 0); string ans = "";
    for(char c : s) v[c-'a']++;
    for(char c : s){
        if(v[c-'a']==0) continue;
        ans.push_back(c);
        ans += to_string(v[c-'a']);
        v[c-'a']=0;
    }
    return ans;
}
