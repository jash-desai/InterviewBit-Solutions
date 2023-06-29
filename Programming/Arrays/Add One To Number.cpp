// Problem Name: Add One To Number
// Problem Link: https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &v) {
    int n = v.size(), c = 1; vector<int> ans; stack<int> st;
    for(int i=n-1; i>=0; i--){
        int d = v[i]+c;
        if(d>=10){
            st.push(d%10);
            c = d/10;
        }else{
            st.push(d);
            c = 0;
        }
    }
    if(c!=0) st.push(c);
    while(!st.empty()){
        while(ans.empty() and st.top()==0 and !st.empty()) st.pop();
        int t = st.top(); st.pop();
        ans.push_back(t);
    }
    return ans;
}
