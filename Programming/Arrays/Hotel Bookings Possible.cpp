// Problem Name: Hotel Bookings Possible
// Problem Link: https://www.interviewbit.com/problems/hotel-bookings-possible/

#define pii pair<int,int>
bool Solution::hotel(vector<int> &a, vector<int> &b, int k){
    int n = a.size(); vector<pii> vp;
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i=0; i<n; i++) vp.push_back({a[i], b[i]});
    sort(vp.begin(), vp.end());
    for(auto&[a,d] : vp){
        while(!pq.empty() and pq.top() < a) pq.pop();
        pq.push(d);
        if(pq.size()>k) return 0;
    }
    return 1;
}
