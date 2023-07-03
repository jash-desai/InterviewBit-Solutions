// Problem Name: Pascal Triangle
// Problem Link: https://www.interviewbit.com/problems/pascal-triangle/

long long int fact(int n){
    if(n==0 or n==1) return 1;
    long long int a = 1, c = 1;
    for(int i=2; i<=n; i++){
        a = c*i;
        c = a;
    }
    return a;
}
long long int ncr(int n, int r){
    long long int nr = n, tr = r-1, tn = n-1;
    while(tr--){
        nr *= tn;
        tn--;
    }
    long long int dr = fact(r);
    return (nr/dr);
}
vector<int> getRow(int n){
    if(n==0) return {1};
    if(n==1) return {1, 1};
    if(n==2) return {1, 2, 1};
    if(n==3) return {1, 3, 3, 1};
    vector<int> ans(n+1, 1); int i;
    for(i=1; i<=((n+1)/2); i++){
        long long int t = ncr(n, i);
        ans[i] = t;
    }
    for(; i<n; i++) ans[i] = ans[n-i];
    return ans;
}

vector<vector<int>> Solution::solve(int n) {
    vector<vector<int>> ans; 
    for(int i=0; i<n; i++) ans.push_back(getRow(i));
    return ans;
}
