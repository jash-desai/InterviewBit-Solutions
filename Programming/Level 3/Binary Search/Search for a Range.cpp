// Problem Name: Search for a Range
// Problem Link: https://www.interviewbit.com/problems/search-for-a-range/

int fidx(const vector<int> &v, int k){
    int l = 0, r = size(v)-1, m; int ans = -1;
    while(l<=r){
        m = l + ((r-l)>>1);
        if(v[m]==k and v[m-1]!=k) return m;
        if(v[m]==k and v[m-1]==k){
            ans = m;
            r = m-1;
        }else if(v[m]<k) l = m+1;   
        else if(v[m]>k) r = m-1;
    }
    return ans;
}
int lidx(const vector<int> &v, int k){
    int l = 0, r = size(v)-1, m; int ans = -1;
    while(l<=r){
        m = l + ((r-l)>>1);
        if(v[m]==k and v[m+1]!=k) return m;
        if(v[m]==k and v[m+1]==k){
            ans = m;
            l = m+1;
        }else if(v[m]<k) l = m+1;   
        else if(v[m]>k) r = m-1;
    }
    return ans;
}
vector<int> Solution::searchRange(const vector<int> &v, int k){
    int l = fidx(v,k); if(l==-1) return {-1, -1};
    int r = lidx(v,k); if(r!=-1) return {l, r};
}
