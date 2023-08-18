// Problem Name: Path in Directed Graph
// Problem Link: https://www.interviewbit.com/problems/path-in-directed-graph/

int Solution::solve(int n, vector<vector<int>> &mat){
    vector<vector<int>> adj(n+1);
    for(auto &m : mat) adj[m[0]].push_back(m[1]); 
    queue<int> q; q.push(1); vector<bool> vis(n+1, 0); vis[1] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(v==n) return 1;
            if(!vis[v]){
                q.push(v); vis[v]=1;
            }
        }
    }
    return 0;
}