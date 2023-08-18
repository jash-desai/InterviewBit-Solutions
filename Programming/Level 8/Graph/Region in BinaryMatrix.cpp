// Problem Name: Region in BinaryMatrix
// Problem Link: https://www.interviewbit.com/problems/region-in-binarymatrix/

int bfs(vector<vector<int>> &v, int i, int j, vector<vector<bool>> &vis){
    int n = v.size(), m = v[0].size();
    vis[i][j] = 1; int ans {1};
    queue<pair<int,int>> q; q.push({i, j});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second; q.pop();
        for(int i=-1; i<2; i++){
            for(int j=-1; j<2; j++){
                int nr = r+i, nc = c+j;
                if(nr>=0 and nr<n and nc>=0 and nc<m){
                    if(!vis[nr][nc] and v[nr][nc]){
                        ans++; vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
    return ans;
}
int Solution::solve(vector<vector<int>> &v){
    int n = v.size(), m = v[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] and v[i][j]){
                ans = max(ans, bfs(v,i,j,vis));
            }
        }
    }
    return ans;
}
