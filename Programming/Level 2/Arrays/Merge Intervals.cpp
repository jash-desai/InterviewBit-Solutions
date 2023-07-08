// Problem Name: Merge Intervals
// Problem Link: https://www.interviewbit.com/problems/merge-intervals/

vector<Interval> Solution::insert(vector<Interval> &v, Interval newInterval) {
    if(newInterval.start > newInterval.end) swap(newInterval.start, newInterval.end);
    vector<Interval> ans; stack<Interval> st; v.push_back(newInterval); int n = v.size();
    sort(v.begin(), v.end(), [](auto&a, auto&b){
        return a.start < b.start;
    });
    for(int i=n-1; i>=0; i--){
        st.push(v[i]);
    }
    ans.push_back(st.top()); st.pop(); int i = 0;
    while(!st.empty()){
        auto t = st.top(); st.pop();
        if(t.start >= ans[i].start and t.end <= ans[i].end) continue;
        if(t.start <= ans[i].end and t.end > ans[i].end) ans[i].end = t.end;
        if(t.start > ans[i].end){
            ans.push_back(t); i++;
        }
    }
    return ans;
}
