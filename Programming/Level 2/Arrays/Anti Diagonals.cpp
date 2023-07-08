// Problem Name: Anti Diagonals
// Problem Link: https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int>> Solution::diagonal(vector<vector<int> > &v){
    int n{size(v)}, c{0}; vector<vector<int>> ans((n<<1)-1);
    for(int i{0}; i<n; i++){
        int t = c;
        for(int j{0}; j<n; j++){
            ans[t++].push_back(v[i][j]);
        }
        c++;
    }
    return ans;
}
