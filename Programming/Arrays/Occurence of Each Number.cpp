// Problem Name: Occurence of Each Number
// Problem Link: https://www.interviewbit.com/problems/occurence-of-each-number/
vector<int> Solution::findOccurences(vector<int> &v){
    vector<int> ans = {1}; int n = v.size();
    int c = 0; sort(v.begin(), v.end());
    for(int i=1; i<n; i++){
        if(v[i]==v[i-1]){
            ans[c]++;
        }else if(v[i]!=v[i-1]){
            ans.push_back(1);
            c++;
        }
    }
    return ans;
}
