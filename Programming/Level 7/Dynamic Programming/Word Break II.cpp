// Problem Name: Word Break II
// Problem Link: https://www.interviewbit.com/problems/word-break-ii/

vector<string> rec(string&s, int idx, unordered_set<string>&st){
    vector<string> res; string temp = "";
    if(idx==s.size()){res.push_back(temp); return res;}
    for(int i=idx; i<s.size(); i++){
        temp += s[i];
        if(st.count(temp)){
            vector<string> tempAns = rec(s,i+1,st);
            for(string x : tempAns){
                if(x == "") res.push_back(temp);
                else res.push_back(temp + " " + x);
            }
        }
    } return res;
}
vector<string> Solution::wordBreak(string s, vector<string> &v){
    unordered_set<string> st(v.begin(), v.end());
    return rec(s,0,st);
}