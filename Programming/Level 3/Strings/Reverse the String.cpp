// Problem Name: Reverse the String
// Problem Link: https://www.interviewbit.com/problems/reverse-the-string/

string Solution::solve(string s){
    stack<string> st; int l = 0, r = size(s)-1;
    while(l<size(s)){
        if(s[l]==' ') l++;
        else break;
    }
    while(r>=0){
        if(s[r]==' ') r--;
        else break;
    }
    s = s.substr(l, r-l+1); string t, curr;
    int i = 0;
    while(i<size(s)){
        if(s[i]==' '){
            t += curr + " ";
            curr = "";
            while(s[i]==' ') i++;
        }else{
            curr.push_back(s[i]);
            i++;
        }
    }
    if(curr.size()) t+= curr;
    curr = ""; i = 0;
    while(i<size(t)){
        if(t[i]!=' '){
            curr.push_back(t[i]); 
            i++;
        }else{
            st.push(curr);
            curr = "";
            i++;
        }
    }
    string ans; st.push(curr);
    while(!st.empty()){
        string temp = st.top(); st.pop();
        ans += temp + " ";
    }
    return ans.substr(0, size(ans)-1);
}
