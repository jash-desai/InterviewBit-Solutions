// Problem Name: Sort array with squares!
// Problem Link: https://www.interviewbit.com/problems/sort-array-with-squares/

vector<int> Solution::solve(vector<int> &v){
    priority_queue<int, vector<int>, greater<>> pq; vector<int> ans;
    for(int x : v) pq.push(x*x);
    while(!pq.empty()){
        ans.push_back(pq.top()); pq.pop();
    }
    return ans;
}
