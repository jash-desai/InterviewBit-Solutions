// Problem Name: Find Permutation
// Problem Link: https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string s, int n) {
    vector<int> ans; int inc = 1, dec = n;
    if(s[0]=='I'){
        ans.push_back(inc++);
    }else{
        ans.push_back(dec--);
    }
    for(int i=1; i<n; i++){
        char c = s[i];
        if(c=='I'){
            ans.push_back(inc++);
        }else{
            ans.push_back(dec--);
        }
    }
    return ans;
}
