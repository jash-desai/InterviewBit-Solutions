// Problem Name: Deserialize
// Problem Link: https://www.interviewbit.com/problems/deserialize/

vector<string> Solution::deserialize(string s){
    vector<string> vs; string curr = ""; int i = 0;
    while(i<size(s)){
        if(s[i]=='~'){
            vs.push_back(curr);
            curr = "";
            i++;
        }else if(s[i]>='a' and s[i]<='z'){
            curr.push_back(s[i]);
            i++;
        }else i++;
    }
    return vs;
}
