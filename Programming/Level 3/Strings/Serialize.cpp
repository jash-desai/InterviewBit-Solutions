// Problem Name: Serialize
// Problem Link: https://www.interviewbit.com/problems/serialize/

string Solution::serialize(vector<string> &v){
    string ans;
    for(string s : v){
        s += to_string(size(s));
        ans += s + "~";
    }
    return ans.substr(0);
}
